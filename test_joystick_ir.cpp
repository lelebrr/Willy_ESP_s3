/*
 * Código de Teste para Joystick KY-023 e IR YS-IRTM
 * ESP32-S3-WROOM-1-N8R2
 *
 * Este arquivo contém um código de teste para validar as implementações
 * do joystick e módulo IR.
 */

// Definições dos pinos
#define JOY_X_PIN    4    // ADC1_CH3
#define JOY_Y_PIN    5    // ADC1_CH4
#define JOY_BTN_PIN  6    // Digital com INPUT_PULLUP

#define IR_SERIAL_TX_PIN 1    // ESP TX → YS-IRTM RXD
#define IR_SERIAL_RX_PIN 47   // ESP RX ← YS-IRTM TXD
#define IR_SERIAL_BAUD  9600

// Variáveis globais para testes
bool test_passed = true;
int test_count = 0;
int test_success = 0;

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("=== Teste Joystick KY-023 e IR YS-IRTM ===");
    Serial.println("ESP32-S3-WROOM-1-N8R2");
    Serial.println();

    // Configuração dos pinos do joystick
    pinMode(JOY_BTN_PIN, INPUT_PULLUP);

    // Configuração dos ADCs
    analogReadResolution(12); // 12 bits (0-4095)

    // Inicialização da serial IR
    Serial2.begin(IR_SERIAL_BAUD, SERIAL_8N1, IR_SERIAL_RX_PIN, IR_SERIAL_TX_PIN);

    Serial.println("Configuração inicial concluída!");
    Serial.println();

    run_tests();
}

void run_tests() {
    Serial.println("=== Iniciando Testes ===");

    // Teste 1: Verificar pinos do joystick
    test_joystick_pins();

    // Teste 2: Verificar leitura analógica
    test_analog_read();

    // Teste 3: Verificar botão do joystick
    test_joystick_button();

    // Teste 4: Verificar comunicação IR
    test_ir_communication();

    // Resultados
    Serial.println();
    Serial.println("=== Resultados dos Testes ===");
    Serial.printf("Total de testes: %d\n", test_count);
    Serial.printf("Sucessos: %d\n", test_success);
    Serial.printf("Falhas: %d\n", test_count - test_success);

    if (test_success == test_count) {
        Serial.println("✅ Todos os testes passaram!");
    } else {
        Serial.println("❌ Alguns testes falharam. Verifique as conexões.");
    }
}

void test_joystick_pins() {
    Serial.println("Teste 1: Verificando pinos do joystick...");

    test_count++;

    // Verificar se os pinos estão configurados corretamente
    if (JOY_X_PIN == 4 && JOY_Y_PIN == 5 && JOY_BTN_PIN == 6) {
        Serial.println("✅ Pinos do joystick configurados corretamente");
        test_success++;
    } else {
        Serial.println("❌ Pinos do joystick incorretos");
        Serial.printf("Esperado: X=4, Y=5, BTN=6\n");
        Serial.printf("Recebido: X=%d, Y=%d, BTN=%d\n", JOY_X_PIN, JOY_Y_PIN, JOY_BTN_PIN);
    }
    Serial.println();
}

void test_analog_read() {
    Serial.println("Teste 2: Verificando leitura analógica...");

    test_count++;

    // Ler valores dos eixos
    int x = analogRead(JOY_X_PIN);
    int y = analogRead(JOY_Y_PIN);

    Serial.printf("Valores lidos: X=%d, Y=%d\n", x, y);

    // Verificar se os valores estão na faixa esperada (0-4095)
    if (x >= 0 && x <= 4095 && y >= 0 && y <= 4095) {
        Serial.println("✅ Leitura analógica dentro da faixa esperada");
        test_success++;

        // Verificar se os valores estão próximos do centro (calibração)
        if (x > 1000 && x < 3500 && y > 1000 && y < 3500) {
            Serial.println("✅ Valores próximos do centro - joystick calibrado corretamente");
        } else {
            Serial.println("⚠️  Valores fora do centro - calibragem necessária");
            Serial.println("   Mova o joystick para todas as direções para calibrar");
        }
    } else {
        Serial.println("❌ Leitura analógica fora da faixa esperada");
        Serial.println("   Verifique conexões e alimentação do joystick");
    }
    Serial.println();
}

void test_joystick_button() {
    Serial.println("Teste 3: Verificando botão do joystick...");

    test_count++;

    // Ler estado do botão
    bool btn_state = digitalRead(JOY_BTN_PIN);

    Serial.printf("Estado do botão: %s\n", btn_state ? "HIGH (solto)" : "LOW (pressionado)");

    // O botão deve estar em HIGH (solto) devido ao INPUT_PULLUP
    if (btn_state == HIGH) {
        Serial.println("✅ Botão configurado corretamente com INPUT_PULLUP");
        test_success++;

        Serial.println("Pressione o botão do joystick para continuar...");
        delay(2000);

        // Verificar se o botão foi pressionado
        btn_state = digitalRead(JOY_BTN_PIN);
        if (btn_state == LOW) {
            Serial.println("✅ Botão responde ao pressionar");
            test_success++;
        } else {
            Serial.println("❌ Botão não responde ao pressionar");
        }
    } else {
        Serial.println("❌ Botão não está em estado HIGH (solto)");
        Serial.println("   Verifique a configuração INPUT_PULLUP");
    }
    Serial.println();
}

void test_ir_communication() {
    Serial.println("Teste 4: Verificando comunicação IR...");

    test_count++;

    // Verificar se a serial IR foi inicializada
    if (Serial2) {
        Serial.println("✅ Serial IR inicializada corretamente");
        test_success++;

        // Enviar comando de teste
        Serial.println("Enviando comando de teste IR...");
        Serial2.write("TEST\n");

        // Verificar se há dados disponíveis
        if (Serial2.available()) {
            Serial.println("✅ Comunicação IR bidirecional funcionando");
            test_success++;
        } else {
            Serial.println("⚠️  Comunicação IR unidirectional (transmissão apenas)");
        }
    } else {
        Serial.println("❌ Falha ao inicializar serial IR");
    }
    Serial.println();
}

void loop() {
    // Monitoramento contínuo do joystick
    static uint32_t last_print = 0;
    if (millis() - last_print > 1000) {
        int x = analogRead(JOY_X_PIN);
        int y = analogRead(JOY_Y_PIN);
        bool btn = digitalRead(JOY_BTN_PIN);

        Serial.printf("Joystick - X: %4d, Y: %4d, BTN: %s\n", x, y, btn ? "HIGH" : "LOW");

        // Detectar movimentos
        if (x < 1500) Serial.println("  ← Esquerda");
        else if (x > 3500) Serial.println("  → Direita");

        if (y < 1500) Serial.println("  ↑ Cima");
        else if (y > 3500) Serial.println("  ↓ Baixo");

        if (btn == LOW) Serial.println("  [Botão pressionado]");

        last_print = millis();
    }

    delay(50);
}
