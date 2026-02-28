# Display LCD TFT SPI de 2.4 polegadas (ILI9341) + Touch

**Referências:**

- [Mischianti: Guia Completo ILI9341 com TFT_eSPI](https://mischianti.org/complete-guide-using-an-ili9341-display-with-the-tft_espi-library/)
- [Mischianti: Diagrama de Fiação (ESP32)](https://mischianti.org/wp-content/uploads/2024/11/TFT-ili9341-esp32-wiring-677x1024.jpg.webp)
- [Fórum Arduino: Discussão sobre Touchscreen no ESP32](https://forum.arduino.cc/t/esp32-touchscreen-tft_espi-ili9341/607951/16)

## Especificações

- **Controlador**: ILI9341 (Display) / XPT2046 (Touch).
- **Resolução**: 320x240 pixels (2.4").
- **Interface**: SPI (4-fios).
- **Profundidade de Cor**: RGB 65k Cores.
- **Tensão Lógica**: 3.3V (O VCC pode ser 5V se houver regulador LDO no módulo, mas os sinais SPI/Lógica **devem** ser 3.3V).

## Mapeamento de Pinos - Willy ESP32-S3

| Pino do Display | Pino ESP32-S3 | Descrição |
| :--- | :--- | :--- |
| `VCC` | `5V / VIN` | Alimentação Principal (Recomendado se usar regulador onboard). |
| `GND` | `GND` | Terra comum. |
| `CS` | `10` | Seleção de Chip (Display). |
| `RESET / RST` | `14` | Reset de Hardware. |
| `DC / RS` | `9`| Data/Command (Seleção de Registro). |
| `MOSI` | `11` | SPI MOSI. |
| `SCK` | `12` | SPI Clock. |
| `LED / BL` | `3.3V` | Backlight (Sempre ligado ou via PWM no pino 3V3). |
| `MISO` | `13` | SPI MISO. |

**Pinos do Touch (SPI Compartilhado XPT2046)**

| Pino do Touch | Pino ESP32-S3 | Descrição |
| :--- | :--- | :--- |
| `T_CLK` | `12` | SPI Clock (Compartilhado). |
| `T_CS` | `15` | Seleção de Chip do Touch. |
| `T_DIN` | `11` | SPI MOSI (Compartilhado). |
| `T_DO` | `13` | SPI MISO (Compartilhado). |

## Configuração da Biblioteca (`TFT_eSPI`)

Para a ESP32-S3 no firmware Willy, edite o arquivo `User_Setup.h` ou as flags do PlatformIO:

- `DRIVER_IC`: `ILI9341_DRIVER`
- `TFT_WIDTH`: `240`, `TFT_HEIGHT`: `320`
- `TFT_CS`: `10`, `TFT_DC`: `9`, `TFT_RST`: `14`
- `TOUCH_CS`: `15`
- `SPI_FREQUENCY`: `40000000` (40MHz para máximo desempenho)
