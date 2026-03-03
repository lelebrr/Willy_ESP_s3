#include "web_server.h"
#include <Hash.h>
#include <time.h>

WebServer::WebServer(const String& ssid, const String& password)
    : server(80), ssid(ssid), password(password), isAuthenticated(false) {

    // Initialize device state
    deviceState.uptime = millis();

    // Initialize logs
    addLog("System initialized");
}

void WebServer::begin() {
    // Initialize SPIFFS
    if(!SPIFFS.begin(true)){
        Serial.println("Erro ao montar SPIFFS");
        return;
    }

    // Connect to WiFi
    WiFi.begin(ssid.c_str(), password.c_str());
    Serial.println("Conectando ao WiFi...");

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi conectado!");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        addLog("WiFi conectado: " + WiFi.localIP().toString());
    } else {
        Serial.println("\nFalha ao conectar ao WiFi");
        addLog("Falha ao conectar ao WiFi");
        return;
    }

    // Set up server routes
    server.on("/", HTTP_GET, std::bind(&WebServer::handleRoot, this));
    server.on("/login", HTTP_GET, std::bind(&WebServer::handleLogin, this));
    server.on("/logout", HTTP_GET, std::bind(&WebServer::handleLogout, this));
    server.on("/dashboard", HTTP_GET, std::bind(&WebServer::handleDashboard, this));
    server.on("/settings", HTTP_GET, std::bind(&WebServer::handleSettings, this));
    server.on("/logs", HTTP_GET, std::bind(&WebServer::handleLogs, this));
    server.on("/system", HTTP_GET, std::bind(&WebServer::handleSystem, this));

    // API routes
    server.on("/api/state", HTTP_GET, std::bind(&WebServer::handleApiState, this));
    server.on("/api/relay", HTTP_POST, std::bind(&WebServer::handleApiRelay, this));
    server.on("/api/settings", HTTP_POST, std::bind(&WebServer::handleApiSettings, this));
    server.on("/api/logs", HTTP_GET, std::bind(&WebServer::handleApiLogs, this));
    server.on("/api/system", HTTP_GET, std::bind(&WebServer::handleApiSystem, this));

    // Static files
    server.on("/css/style.css", HTTP_GET, std::bind(&WebServer::handleCss, this));
    server.on("/js/script.js", HTTP_GET, std::bind(&WebServer::handleJs, this));
    server.on("/images/", HTTP_GET, std::bind(&WebServer::handleImages, this));

    server.onNotFound(std::bind(&WebServer::handleNotFound, this));

    // Start server
    server.begin();
    Serial.println("Servidor HTTP iniciado");
    addLog("Servidor HTTP iniciado");
}

void WebServer::handleClient() {
    server.handleClient();
}

bool WebServer::checkAuthentication() {
    if (isAuthenticated) return true;

    // Check for session cookie
    if (server.hasHeader("Cookie")) {
        String cookie = server.header("Cookie");
        if (cookie.indexOf("session_token=") != -1) {
            isAuthenticated = true;
            return true;
        }
    }

    return false;
}

void WebServer::generateToken() {
    // Simple token generation (in production, use proper crypto)
    unsigned long seed = millis() + random(1000);
    String token = String(seed, HEX);
    server.sendHeader("Set-Cookie", "session_token=" + token + "; Path=/; Max-Age=3600");
    isAuthenticated = true;
}

void WebServer::handleRoot() {
    if (!checkAuthentication()) {
        server.sendHeader("Location", "/login");
        server.send(302, "text/plain", "Redirecting to login...");
        return;
    }

    server.sendHeader("Location", "/dashboard");
    server.send(302, "text/plain", "Redirecting to dashboard...");
}

void WebServer::handleLogin() {
    if (server.hasArg("username") && server.hasArg("password")) {
        String username = server.arg("username");
        String password = server.arg("password");

        // Simple authentication (in production, use proper hashing)
        if (username == "admin" && password == "admin") {
            generateToken();
            server.sendHeader("Location", "/dashboard");
            server.send(302, "text/plain", "Login successful!");
            addLog("User logged in: " + username);
            return;
        } else {
            addLog("Failed login attempt: " + username);
        }
    }

    serveFile("/login.html", "text/html");
}

void WebServer::handleLogout() {
    isAuthenticated = false;
    server.sendHeader("Set-Cookie", "session_token=; Path=/; Max-Age=0");
    server.sendHeader("Location", "/login");
    server.send(302, "text/plain", "Logged out successfully");
    addLog("User logged out");
}

void WebServer::handleDashboard() {
    if (!checkAuthentication()) {
        server.sendHeader("Location", "/login");
        server.send(302, "text/plain", "Redirecting to login...");
        return;
    }

    serveFile("/dashboard.html", "text/html");
}

void WebServer::handleSettings() {
    if (!checkAuthentication()) {
        server.sendHeader("Location", "/login");
        server.send(302, "text/plain", "Redirecting to login...");
        return;
    }

    serveFile("/settings.html", "text/html");
}

void WebServer::handleLogs() {
    if (!checkAuthentication()) {
        server.sendHeader("Location", "/login");
        server.send(302, "text/plain", "Redirecting to login...");
        return;
    }

    serveFile("/logs.html", "text/html");
}

void WebServer::handleSystem() {
    if (!checkAuthentication()) {
        server.sendHeader("Location", "/login");
        server.send(302, "text/plain", "Redirecting to login...");
        return;
    }

    serveFile("/system.html", "text/html");
}

void WebServer::handleNotFound() {
    serveFile("/404.html", "text/html");
}

void WebServer::serveFile(const String& path, const String& contentType) {
    File file = SPIFFS.open(path, "r");
    if (!file) {
        Serial.println("Arquivo não encontrado: " + path);
        server.send(404, "text/plain", "File not found");
        return;
    }

    String content = file.readString();
    file.close();

    // Replace placeholders with actual values
    content.replace("{{RELAY1_STATE}}", deviceState.relay1 ? "checked" : "");
    content.replace("{{RELAY2_STATE}}", deviceState.relay2 ? "checked" : "");
    content.replace("{{RELAY3_STATE}}", deviceState.relay3 ? "checked" : "");
    content.replace("{{RELAY4_STATE}}", deviceState.relay4 ? "checked" : "");
    content.replace("{{TEMPERATURE}}", String(deviceState.temperature, 1));
    content.replace("{{HUMIDITY}}", String(deviceState.humidity, 1));
    content.replace("{{WIFI_SIGNAL}}", String(deviceState.wifiSignal));
    content.replace("{{BATTERY_LEVEL}}", String(deviceState.batteryLevel));
    content.replace("{{UPTIME}}", formatUptime(deviceState.uptime));

    server.send(200, contentType, content);
}

String WebServer::formatUptime(unsigned long uptime) {
    unsigned long seconds = uptime / 1000;
    unsigned long minutes = seconds / 60;
    unsigned long hours = minutes / 60;
    unsigned long days = hours / 24;

    seconds %= 60;
    minutes %= 60;
    hours %= 24;

    String result = "";
    if (days > 0) result += String(days) + "d ";
    if (hours > 0) result += String(hours) + "h ";
    if (minutes > 0) result += String(minutes) + "m ";
    if (seconds > 0) result += String(seconds) + "s ";

    return result;
}

void WebServer::handleApiState() {
    if (!checkAuthentication()) {
        server.send(401, "application/json", "{\"error\":\"Unauthorized\"}");
        return;
    }

    DynamicJsonDocument doc(512);
    doc["relay1"] = deviceState.relay1;
    doc["relay2"] = deviceState.relay2;
    doc["relay3"] = deviceState.relay3;
    doc["relay4"] = deviceState.relay4;
    doc["temperature"] = deviceState.temperature;
    doc["humidity"] = deviceState.humidity;
    doc["wifiSignal"] = deviceState.wifiSignal;
    doc["batteryLevel"] = deviceState.batteryLevel;
    doc["uptime"] = deviceState.uptime;

    String response;
    serializeJson(doc, response);
    server.send(200, "application/json", response);
}

void WebServer::handleApiRelay() {
    if (!checkAuthentication()) {
        server.send(401, "application/json", "{\"error\":\"Unauthorized\"}");
        return;
    }

    if (server.hasArg("relay") && server.hasArg("state")) {
        int relay = server.arg("relay").toInt();
        bool state = server.arg("state") == "1";

        if (relay >= 1 && relay <= 4) {
            setRelay(relay, state);
            server.send(200, "application/json", "{\"success\":true}");
            addLog("Relay " + String(relay) + " set to " + String(state ? "ON" : "OFF"));
        } else {
            server.send(400, "application/json", "{\"error\":\"Invalid relay number\"}");
        }
    } else {
        server.send(400, "application/json", "{\"error\":\"Missing parameters\"}");
    }
}

void WebServer::handleApiSettings() {
    if (!checkAuthentication()) {
        server.send(401, "application/json", "{\"error\":\"Unauthorized\"}");
        return;
    }

    DynamicJsonDocument doc(256);
    if (server.hasArg("ssid")) doc["ssid"] = server.arg("ssid");
    if (server.hasArg("password")) doc["password"] = server.arg("password");
    if (server.hasArg("hostname")) doc["hostname"] = server.arg("hostname");

    String response;
    serializeJson(doc, response);
    server.send(200, "application/json", "{\"success\":true}");
    addLog("Settings updated");
}

void WebServer::handleApiLogs() {
    if (!checkAuthentication()) {
        server.send(401, "application/json", "{\"error\":\"Unauthorized\"}");
        return;
    }

    DynamicJsonDocument doc(1024);
    JsonArray logs = doc.createNestedArray("logs");

    for (int i = 0; i < deviceState.logs.size() && i < 50; i++) {
        logs.add(deviceState.logs[deviceState.logs.size() - 1 - i]);
    }

    String response;
    serializeJson(doc, response);
    server.send(200, "application/json", response);
}

void WebServer::handleApiSystem() {
    if (!checkAuthentication()) {
        server.send(401, "application/json", "{\"error\":\"Unauthorized\"}");
        return;
    }

    DynamicJsonDocument doc(512);
    doc["ip"] = WiFi.localIP().toString();
    doc["ssid"] = WiFi.SSID();
    doc["rssi"] = WiFi.RSSI();
    doc["heap"] = ESP.getFreeHeap();
    doc["chipId"] = ESP.getChipId();
    doc["flashSize"] = ESP.getFlashChipSize();
    doc["sdkVersion"] = ESP.getSdkVersion();

    String response;
    serializeJson(doc, response);
    server.send(200, "application/json", response);
}

void WebServer::handleCss() {
    File file = SPIFFS.open("/css/style.css", "r");
    if (!file) {
        server.send(404, "text/plain", "CSS file not found");
        return;
    }

    String content = file.readString();
    file.close();
    server.send(200, "text/css", content);
}

void WebServer::handleJs() {
    File file = SPIFFS.open("/js/script.js", "r");
    if (!file) {
        server.send(404, "text/plain", "JS file not found");
        return;
    }

    String content = file.readString();
    file.close();
    server.send(200, "application/javascript", content);
}

void WebServer::handleImages() {
    String path = server.uri();
    File file = SPIFFS.open(path, "r");
    if (!file) {
        server.send(404, "text/plain", "Image not found");
        return;
    }

    String contentType = "image/jpeg";
    if (path.endsWith(".png")) contentType = "image/png";
    else if (path.endsWith(".gif")) contentType = "image/gif";
    else if (path.endsWith(".svg")) contentType = "image/svg+xml";

    String content = file.readString();
    file.close();
    server.send(200, contentType, content);
}

// Device control methods
void WebServer::setRelay(int relay, bool state) {
    switch (relay) {
        case 1: deviceState.relay1 = state; break;
        case 2: deviceState.relay2 = state; break;
        case 3: deviceState.relay3 = state; break;
        case 4: deviceState.relay4 = state; break;
    }
}

void WebServer::setTemperature(float temp) {
    deviceState.temperature = temp;
}

void WebServer::setHumidity(float hum) {
    deviceState.humidity = hum;
}

void WebServer::setWifiSignal(int signal) {
    deviceState.wifiSignal = signal;
}

void WebServer::setBatteryLevel(int level) {
    deviceState.batteryLevel = constrain(level, 0, 100);
}

void WebServer::updateDeviceState() {
    deviceState.uptime = millis();
    deviceState.wifiSignal = WiFi.RSSI();
    deviceState.batteryLevel = 85; // Placeholder - implement actual battery reading
}

void WebServer::addLog(const String& message) {
    String timestamp = String(millis() / 1000) + "s";
    deviceState.logs.push_back(timestamp + " - " + message);

    // Keep only last 100 logs
    if (deviceState.logs.size() > 100) {
        deviceState.logs.erase(deviceState.logs.begin());
    }
}

// Getters
bool WebServer::getRelayState(int relay) {
    switch (relay) {
        case 1: return deviceState.relay1;
        case 2: return deviceState.relay2;
        case 3: return deviceState.relay3;
        case 4: return deviceState.relay4;
        default: return false;
    }
}

float WebServer::getTemperature() {
    return deviceState.temperature;
}

float WebServer::getHumidity() {
    return deviceState.humidity;
}

int WebServer::getWifiSignal() {
    return deviceState.wifiSignal;
}

int WebServer::getBatteryLevel() {
    return deviceState.batteryLevel;
}

unsigned long WebServer::getUptime() {
    return deviceState.uptime;
}

std::vector<String> WebServer::getLogs() {
    return deviceState.logs;
}
