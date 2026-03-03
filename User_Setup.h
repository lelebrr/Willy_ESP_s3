// User_Setup.h - WILLY ESP S3 + ILI9341 + XPT2046 (versão corrigida 03/03/2026)
#define USER_SETUP_LOADED

#define ILI9341_DRIVER

#define TFT_WIDTH  240
#define TFT_HEIGHT 320

#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST  14
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_MISO 13

#define TFT_BL   -1               // backlight fixo 3.3V

#define USE_HSPI_PORT             // ← OBRIGATÓRIO (mesmo no S3 para esses pinos)
#define SPI_FREQUENCY      20000000
#define SPI_READ_FREQUENCY 10000000
#define SPI_TOUCH_FREQUENCY 2500000

#define TOUCH_CS   15
#define TOUCH_IRQ  36

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define SMOOTH_FONT
#define TFT_RGB_ORDER TFT_BGR
