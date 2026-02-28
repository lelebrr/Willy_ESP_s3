#include "core/powerSave.h"
#include <interface.h>
#include <globals.h>
#include "core/settings.h"

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    // Initial basic pin setup for S3 boards
#ifdef RGB_LED
    if (RGB_LED >= 0) {
        pinMode(RGB_LED, OUTPUT);
        digitalWrite(RGB_LED, LOW);
    }
#endif
#ifdef LED
    if (LED >= 0) {
        pinMode(LED, OUTPUT);
        digitalWrite(LED, LOW);
    }
#endif

    // Setup Joystick Button
#ifdef JOY_BTN_PIN
    if (JOY_BTN_PIN >= 0) {
        pinMode(JOY_BTN_PIN, INPUT_PULLUP);
    }
#endif

    // CC1101 GDO Pins
#ifdef CC1101_GDO0
    if (CC1101_GDO0 >= 0) pinMode(CC1101_GDO0, INPUT);
#endif
#ifdef CC1101_GDO2
    if (CC1101_GDO2 >= 0) pinMode(CC1101_GDO2, INPUT);
#endif

    // NRF24 CE Pin
#ifdef NRF24_CE_PIN
    if (NRF24_CE_PIN >= 0) pinMode(NRF24_CE_PIN, OUTPUT);
#endif

    bruceConfig.startupApp = "WebUI";
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; } // S3 board has no battery monitoring by default

/***************************************************************************************
** Function name: isCharging()
** Description:   Default implementation that returns false
***************************************************************************************/
bool isCharging() { return false; }

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {
#ifdef TFT_BL
    if (TFT_BL >= 0) {
        analogWrite(TFT_BL, brightval);
    }
#endif
}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static uint32_t last_check = 0;
    if (millis() - last_check < 20) return;
    last_check = millis();

    // Reset flags
    static bool btn_last_state = HIGH;

#ifdef JOY_BTN_PIN
    if (JOY_BTN_PIN >= 0) {
        bool btn_state = digitalRead(JOY_BTN_PIN);
        if (btn_state == LOW && btn_last_state == HIGH) {
            SelPress = true;
            AnyKeyPress = true;
        }
        btn_last_state = btn_state;
    }
#endif

    // Joystick Navigation - KY-023 Funduino Shield Configuration
    // Valores calibrados para KY-023: ponto central ~2048, faixa de ativação ~1500-3500
#ifdef JOY_X_PIN
    if (JOY_X_PIN >= 0) {
        int x = analogRead(JOY_X_PIN);
        // Centro: ~2048, Limite inferior: < 1500 (esquerda), Limite superior: > 3500 (direita)
        if (x < 1500) { PrevPress = true; AnyKeyPress = true; }
        else if (x > 3500) { NextPress = true; AnyKeyPress = true; }
    }
#endif

#ifdef JOY_Y_PIN
    if (JOY_Y_PIN >= 0) {
        int y = analogRead(JOY_Y_PIN);
        // Centro: ~2048, Limite inferior: < 1500 (cima), Limite superior: > 3500 (baixo)
        if (y < 1500) { UpPress = true; AnyKeyPress = true; }
        else if (y > 3500) { DownPress = true; AnyKeyPress = true; }
    }
#endif
}
