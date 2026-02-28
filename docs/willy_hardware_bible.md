# 📖 BÍBLIA DO HARDWARE — Willy ESP32-S3-WROOM-1-N8R2

> **O guia definitivo para conectar TODOS os 13 módulos ao ESP32-S3.**
> Se você seguir este documento letra por letra, **tudo vai funcionar**. Se pular uma linha, vai queimar algo.

---

## 📑 Índice

1. [Lista de Compras (BOM)](#-lista-de-compras-bom)
2. [Mapa Geral de GPIO](#️-mapa-geral-de-gpio)
3. [Esquema de Alimentação (Energia)](#-esquema-de-alimentação-energia)
4. [Barramento SPI — 6 Dispositivos](#-barramento-spi--6-dispositivos)
5. [Barramento I2C — 3 Dispositivos](#-barramento-i2c--3-dispositivos)
6. [UART — GPS e IR Serial](#-uart--gps-e-ir-serial)
7. [I2S — Microfone INMP441](#-i2s--microfone-inmp441)
8. [Analógico — Joystick KY-023](#️-analógico--joystick-ky-023)
9. [Módulo 1: Display TFT ILI9341 2.4"](#-módulo-1-display-tft-ili9341-24)
10. [Módulo 2: Touch XPT2046](#-módulo-2-touch-xpt2046)
11. [Módulo 3: Cartão Micro SD](#-módulo-3-cartão-micro-sd)
12. [Módulo 4: NRF24L01+PA+LNA #1](#-módulo-4-nrf24l01palna-1)
13. [Módulo 5: NRF24L01+PA+LNA #2](#-módulo-5-nrf24l01palna-2)
14. [Módulo 6: CC1101 Sub-GHz](#-módulo-6-cc1101-sub-ghz)
15. [Módulo 7: PN532 NFC/RFID](#-módulo-7-pn532-nfcrfid)
16. [Módulo 8: DS3231 RTC](#-módulo-8-ds3231-rtc)
17. [Módulo 9: PAJ7620 Sensor de Gestos](#️-módulo-9-paj7620-sensor-de-gestos)
18. [Módulo 10: GPS NEO-6M](#️-módulo-10-gps-neo-6m)
19. [Módulo 11: YS-IRTM IR Serial](#-módulo-11-ys-irtm-ir-serial)
20. [Módulo 12: INMP441 Microfone](#-módulo-12-inmp441-microfone)
21. [Módulo 13: Joystick KY-023](#️-módulo-13-joystick-ky-023)
22. [Tabela de Bibliotecas e Drivers](#-tabela-de-bibliotecas-e-drivers)
23. [Checklist de Montagem](#-checklist-de-montagem)
24. [Troubleshooting](#-troubleshooting)

---

## 🛒 Lista de Compras (BOM)

| # | Componente | Qtd | Preço Aprox. | Onde Comprar |
| --- | --- | --- | --- | --- |
| 1 | ESP32-S3-WROOM-1-N8R2 (DevKit) | 1 | R$45 | AliExpress |
| 2 | Display TFT ILI9341 2.4" SPI (com Touch XPT2046) | 1 | R$25 | AliExpress |
| 3 | Módulo Micro SD Card SPI | 1 | R$5 | AliExpress |
| 4 | NRF24L01+PA+LNA (com antena SMA) | **2** | R$16 cada | AliExpress |
| 5 | CC1101 433MHz (com antena SMA) | 1 | R$12 | AliExpress |
| 6 | PN532 NFC V3 (Elechouse) | 1 | R$18 | AliExpress |
| 7 | DS3231 RTC (com bateria CR2032) | 1 | R$8 | AliExpress |
| 8 | PAJ7620 Sensor de Gestos (GY-PAJ7620U2) | 1 | R$15 | AliExpress |
| 9 | GPS NEO-6M (com antena cerâmica) | 1 | R$20 | AliExpress |
| 10 | YS-IRTM v3.08 IR Serial | 1 | R$10 | AliExpress |
| 11 | INMP441 Microfone I2S | 1 | R$8 | AliExpress |
| 12 | Joystick KY-023 (ou Funduino Shield) | 1 | R$5 | AliExpress |
| 13 | BMS 2S 5A (Proteção de Bateria) | 1 | R$5 | AliExpress |
| 14 | Conversor Buck Mini-360 (8V→5V) | 1 | R$4 | AliExpress |
| 15 | LDO AMS1117-3.3V | 1 | R$2 | AliExpress |
| 16 | 2x Bateria 18650 Li-Ion 3.7V | 2 | R$15 cada | Local |
| 17 | Capacitores 10μF e 100μF (eletrolítico) | 4+ | R$2 | Local |
| 18 | Capacitores 100nF (cerâmico) | 6+ | R$2 | Local |
| 19 | Fios Dupont (M-F, F-F) | 40+ | R$8 | AliExpress |

### Custo Total Estimado: ~R$280

---

## 🗺️ Mapa Geral de GPIO

> **Esta é a tabela mais importante deste documento.** Imprima ela e cole na sua bancada.

| GPIO | Função | Módulo | Barramento | Cor do Fio |
| :---: | --- | --- | :---: | :---: |
| `1` | TX (IR Serial) | YS-IRTM | UART2 | 🟡 Amarelo |
| `2` | I2S SD/DIN | INMP441 Mic | I2S | 🟢 Verde |
| `4` | ADC JOY_X | Joystick | Analog | 🟠 Laranja |
| `5` | ADC JOY_Y | Joystick | Analog | 🟡 Amarelo |
| `6` | JOY BTN (SW) | Joystick | Digital | 🔵 Azul |
| `8` | **I2C SDA** | PN532 + DS3231 + PAJ7620 | **I2C** | 🟢 Verde |
| `9` | TFT DC | Display ILI9341 | SPI | 🟠 Laranja |
| `10` | TFT CS | Display ILI9341 | SPI | 🟡 Amarelo |
| `11` | **SPI MOSI** | TFT+Touch+SD+NRFx2+CC1101 | **SPI** | 🔵 Azul |
| `12` | **SPI SCK** | TFT+Touch+SD+NRFx2+CC1101 | **SPI** | 🟠 Laranja |
| `13` | **SPI MISO** | TFT+Touch+SD+NRFx2+CC1101 | **SPI** | 🟢 Verde |
| `14` | TFT RST | Display ILI9341 | SPI | ⚪ Branco |
| `15` | TOUCH CS | XPT2046 Touch | SPI | 🟤 Marrom |
| `16` | NRF1 CSN | NRF24L01 #1 | SPI | 🟡 Amarelo |
| `17` | **I2C SCL** | PN532 + DS3231 + PAJ7620 | **I2C** | 🟡 Amarelo |
| `18` | CC1101 CS | CC1101 | SPI | 🔵 Azul |
| `21` | NRF1 CE | NRF24L01 #1 | GPIO | ⚪ Branco |
| `33` | CC1101 GDO0 | CC1101 | GPIO | 🟢 Verde |
| `34` | CC1101 GDO2 | CC1101 | GPIO | 🟤 Marrom |
| `35` | NRF2 CSN | NRF24L01 #2 | SPI | 🟠 Laranja |
| `36` | NRF2 CE | NRF24L01 #2 | GPIO | 🟤 Marrom |
| `38` | SD CS | Micro SD Card | SPI | 🟣 Roxo |
| `39` | GPS RX (recebe do GPS TX) | GPS NEO-6M | UART1 | 🟢 Verde |
| `40` | GPS TX (envia para GPS RX) | GPS NEO-6M | UART1 | 🟡 Amarelo |
| `41` | I2S SCK/BCLK | INMP441 Mic | I2S | 🟠 Laranja |
| `42` | I2S WS/LRCK | INMP441 Mic | I2S | 🟡 Amarelo |
| `47` | RX (IR Serial) | YS-IRTM | UART2 | 🟢 Verde |
| `48` | WS2812 RGB LED | Built-in | Internal | — |

**GPIOs Livres (para expansão futura):** `0, 3, 7, 19, 20, 37, 43, 44, 45, 46`

> [!CAUTION]
> **NUNCA** use GPIO 0 durante o boot (strap pin). GPIOs 43 e 44 são TX/RX do USB Serial nativo — evite usá-los para periféricos.

---

## ⚡ Esquema de Alimentação (Energia)

Este é o esquema de como alimentar TODOS os módulos sem queimar nada.

```text
 ┌─────────────────────────────────────────────────────────────────────┐
 │                     ESQUEMA DE ALIMENTAÇÃO                         │
 │                                                                     │
 │   ┌─────────┐    ┌─────────┐    ┌───────────────┐                  │
 │   │ Bateria │    │ Bateria │    │   BMS 2S 5A   │                  │
 │   │ 18650   │    │ 18650   │    │               │                  │
 │   │ 3.7V    │──┐ │ 3.7V    │──┐ │ B+ ← Bat1(+) │                  │
 │   └─────────┘  │ └─────────┘  │ │ BM ← Junção  │                  │
 │                │              │ │ B- ← Bat2(-) │                  │
 │                └──────────────┘ │               │                  │
 │                                 │ P+ ── 8.4V ──┐│                  │
 │                                 │ P- ── GND ──┐││                  │
 │                                 └──────────────┘││                  │
 │                                                 ││                  │
 │              ┌──────────────────────────────────┘│                  │
 │              │                                   │                  │
 │              ▼                                   ▼                  │
 │   ┌───────────────────┐                  ┌─────────────┐           │
 │   │  Conversor Buck   │                  │   GND       │           │
 │   │  (Mini-360)       │                  │  Comum      │           │
 │   │  IN: 8.4V         │                  └─────────────┘           │
 │   │  OUT: 5.0V ───────┤                        │                   │
 │   └───────────────────┘                        │                   │
 │              │                                  │                   │
 │              ▼                                  │                   │
 │   ┌───────────────────────────────────────┐    │                   │
 │   │        ESP32-S3 DevKit                │    │                   │
 │   │                                       │    │                   │
 │   │  VIN/5V ← Recebe 5V do Buck          │    │                   │
 │   │  3V3    → Saída regulada 3.3V        │    │                   │
 │   │  GND    → Terra Comum ───────────────┼────┘                   │
 │   └────────┬──────────────┬───────────────┘                        │
 │            │              │                                         │
 │            ▼              ▼                                         │
 │     ┌──────────┐  ┌──────────────┐                                 │
 │     │ LDO      │  │ Linha 3.3V   │                                 │
 │     │AMS1117   │  │ DO ESP32     │                                 │
 │     │3.3V      │  │              │                                 │
 │     │Dedicado  │  │ → I2C (3)    │                                 │
 │     │para      │  │ → INMP441    │                                 │
 │     │Rádios    │  │ → Joystick   │                                 │
 │     │          │  │ → IR Serial  │                                 │
 │     │ → NRF #1 │  └──────────────┘                                 │
 │     │ → NRF #2 │                                                   │
 │     │ → CC1101 │  ┌──────────────┐                                 │
 │     └──────────┘  │ Linha 5V     │                                 │
 │                   │ DO ESP32     │                                 │
 │                   │              │                                 │
 │                   │ → TFT VCC   │                                 │
 │                   │ → SD VCC    │                                 │
 │                   │ → GPS VCC   │                                 │
 │                   └──────────────┘                                 │
 └─────────────────────────────────────────────────────────────────────┘
```

> [!WARNING]
> **REGRA DE OURO**: O LDO dedicado (AMS1117-3.3V) alimenta **SOMENTE** os rádios (2x NRF24 + CC1101). Eles consomem picos de >300mA juntos e **vão derrubar** o regulador interno do ESP32 se estiverem na mesma linha.

### Tabela de Consumo de Corrente

| Módulo | Tensão | Pico (mA) | Média (mA) | Fonte |
| --- | :---: | :---: | :---: | --- |
| ESP32-S3 | 3.3V | 500 | 150 | Regulador interno |
| TFT ILI9341 (backlight) | 5V | 80 | 60 | Linha 5V |
| Touch XPT2046 | 3.3V | 2 | 1 | Linha 3.3V ESP |
| Micro SD Card | 3.3V/5V | 100 | 30 | Linha 5V (via LDO onboard) |
| NRF24L01 #1 (PA+LNA) | 3.3V | 115 | 26 | **LDO Dedicado** |
| NRF24L01 #2 (PA+LNA) | 3.3V | 115 | 26 | **LDO Dedicado** |
| CC1101 | 3.3V | 30 | 17 | **LDO Dedicado** |
| PN532 NFC | 3.3V | 150 | 60 | Linha 3.3V ESP |
| DS3231 RTC | 3.3V | 1 | 0.3 | Linha 3.3V ESP |
| PAJ7620 Gesture | 3.3V | 3 | 2 | Linha 3.3V ESP |
| GPS NEO-6M | 5V | 67 | 45 | Linha 5V |
| YS-IRTM IR | 5V | 40 | 20 | Linha 5V |
| INMP441 Mic | 3.3V | 1.4 | 1 | Linha 3.3V ESP |
| Joystick KY-023 | 3.3V | 1 | 0.5 | Linha 3.3V ESP |

**Total Pico Máximo (Tudo Ligado):**

- Linha 3.3V ESP: ~215 mA ✅ (dentro do limite de 500mA)
- LDO Dedicado 3.3V: ~260 mA ✅ (AMS1117 suporta até 800mA)
- Linha 5V: ~287 mA ✅ (Buck suporta ~2A)

---

## 🔌 Barramento SPI — 6 Dispositivos

**6 dispositivos compartilham 3 fios de dados** (MOSI, MISO, SCK). Cada um tem seu próprio fio de **CS (Chip Select)** para ser selecionado individualmente.

```text
                           BARRAMENTO SPI COMPARTILHADO
                    ┌────────────────────────────────────────┐
                    │                                        │
   ESP32-S3         │   MOSI (GPIO 11) ──── Fio Azul ──────┤──→ TFT (SDI/MOSI)
                    │                                        ├──→ Touch (T_DIN)
                    │   MISO (GPIO 13) ──── Fio Verde ──────┤──→ SD (MISO/DO)
                    │                                        ├──→ Touch (T_DO)
                    │   SCK  (GPIO 12) ──── Fio Laranja ────┤──→ NRF1 (SCK)
                    │                                        ├──→ NRF2 (SCK)
                    │                                        ├──→ CC1101 (SCK)
                    └────────────────────────────────────────┘

   CHIP SELECTS (Um fio exclusivo para cada módulo):

   GPIO 10 ─── Fio Amarelo ──→ TFT CS        (Seleciona o Display)
   GPIO 15 ─── Fio Marrom  ──→ Touch CS      (Seleciona o Touch)
   GPIO 38 ─── Fio Roxo   ──→ SD CS          (Seleciona o Cartão SD)
   GPIO 16 ─── Fio Amarelo ──→ NRF1 CSN      (Seleciona o Rádio 1)
   GPIO 35 ─── Fio Laranja ──→ NRF2 CSN      (Seleciona o Rádio 2)
   GPIO 18 ─── Fio Azul   ──→ CC1101 CS      (Seleciona o Sub-GHz)
```

> [!IMPORTANT]
> **Como funciona o SPI compartilhado?** Imagine 6 pessoas numa sala com um telefone (os 3 fios de dados). Só uma pessoa pode falar por vez. O **CS** (Chip Select) é como "apontar" para qual pessoa deve falar. Quando o CS de um módulo vai para `LOW` (0V), ele "acorda" e usa o barramento. Os outros ficam em modo "dormindo" (Hi-Z, alta impedância) e ignoram o barramento.

### Regra Crítica: O Problema do MISO

> [!CAUTION]
> Módulos Micro SD **baratos** possuem um defeito de fábrica: eles **NÃO soltam o pino MISO** quando não são selecionados. Resultado: o SD trava TODOS os outros módulos SPI.
>
> **Solução:** Compre módulos SD que tenham o chip **74LVC125A** (buffer tri-state). Ou solde um resistor de 1KΩ em série na linha MISO do SD.

---

## 🔗 Barramento I2C — 3 Dispositivos

**3 dispositivos compartilham 2 fios** (SDA e SCL). Não há conflito porque cada um tem um **endereço** diferente (como CEPs de casas na mesma rua).

```text
                         BARRAMENTO I2C
                    ┌──────────────────────────┐
                    │                          │
   ESP32-S3         │  SDA (GPIO 8) ── Verde ──┤──→ PN532 (SDA)    [Addr: 0x24]
                    │                          ├──→ DS3231 (SDA)    [Addr: 0x68]
                    │                          ├──→ PAJ7620 (SDA)   [Addr: 0x73]
                    │                          │
                    │  SCL (GPIO 17) ── Amarelo┤──→ PN532 (SCL)
                    │                          ├──→ DS3231 (SCL)
                    │                          ├──→ PAJ7620 (SCL)
                    └──────────────────────────┘

   ALIMENTAÇÃO (em paralelo):
   3.3V ──→ VCC de todos os 3 módulos
   GND  ──→ GND de todos os 3 módulos
```

> [!TIP]
> **Resistores de Pull-Up**: A maioria dos módulos breakout já tem resistores de pull-up de 4.7KΩ embutidos. Se os 3 módulos juntos tiverem pull-up (cada um com 4.7K), o pull-up efetivo será ~1.57K, o que ainda é aceitável. Se tiver problemas de comunicação, **remova** os pull-ups de 2 dos 3 módulos (desolde os resistores SMD da placa).

### Inicialização no Código

```cpp
#include <Wire.h>

void setup() {
    Wire.begin(8, 17);  // SDA=8, SCL=17
    Wire.setClock(100000); // 100kHz (padrão, seguro para todos)

    // Agora todos os 3 dispositivos estão acessíveis:
    // PN532 em 0x24
    // DS3231 em 0x68
    // PAJ7620 em 0x73
}
```

---

## 📡 UART — GPS e IR Serial

Dois módulos seriais usam **UARTs diferentes** do ESP32-S3 (ele tem 3 UARTs disponíveis).

```text
   UART1 (GPS):
   GPIO 40 (TX ESP) ── Amarelo ──→ GPS RX
   GPIO 39 (RX ESP) ── Verde   ──→ GPS TX

   UART2 (IR Serial):
   GPIO 1  (TX ESP) ── Amarelo ──→ YS-IRTM RX (Azul)
   GPIO 47 (RX ESP) ── Verde   ──→ YS-IRTM TX (Amarelo)
```

> [!NOTE]
> **TX e RX sempre se cruzam!** O TX de um lado vai no RX do outro. Se não funcionar, **inverta** os fios — é o erro mais comum na montagem.

### Inicialização Serial no Código

```cpp
HardwareSerial gpsSerial(1);   // UART1
HardwareSerial irSerial(2);    // UART2

void setup() {
    gpsSerial.begin(9600, SERIAL_8N1, 39, 40);  // RX=39, TX=40
    irSerial.begin(9600, SERIAL_8N1, 47, 1);    // RX=47, TX=1
}
```

---

## 🎤 I2S — Microfone INMP441

```text
   ESP32-S3                    INMP441
   ─────────                   ────────
   GPIO 41 (I2S SCK)  ──→  SCK (Clock)
   GPIO 42 (I2S WS)   ──→  WS  (Word Select)
   GPIO 2  (I2S SD)   ←──  SD  (Data Out do Mic)
   3.3V               ──→  VDD
   GND                ──→  GND
   GND                ──→  L/R (Canal Esquerdo)
```

---

## 🕹️ Analógico — Joystick KY-023

```text
   ESP32-S3                    KY-023
   ─────────                   ──────
   GPIO 4 (ADC)  ←───  VRx (Eixo X)
   GPIO 5 (ADC)  ←───  VRy (Eixo Y)
   GPIO 6         ←───  SW  (Botão)
   3.3V           ──→  +5V / VCC
   GND            ──→  GND
```

> [!NOTE]
> Use `pinMode(6, INPUT_PULLUP)` para o botão. O ADC da ESP32-S3 é de 12 bits (0-4095). O valor central em repouso é ~2048.

---

## 📺 Módulo 1: Display TFT ILI9341 2.4"

### Especificações

| Parâmetro | Valor |
| --- | --- |
| Controlador | ILI9341 |
| Resolução | **320 × 240 pixels** |
| Tamanho | 2.4 polegadas |
| Cores | 65.536 (RGB565) |
| Interface | SPI (4 fios) |
| Backlight | LED (requer VCC para ligar) |
| Driver/Biblioteca | **TFT_eSPI** (Bodmer) |

### Fiação Completa

| Pino do Display | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `5V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| CS | Chip Select Display | `10` | 🟡 Amarelo |
| RESET | Reset Hardware | `14` | ⚪ Branco |
| DC/RS | Data/Command | `9` | 🟠 Laranja |
| SDI/MOSI | SPI Data In | `11` | 🔵 Azul |
| SCK | SPI Clock | `12` | 🟠 Laranja |
| LED/BL | Backlight | `3.3V` | 🔴 Vermelho |
| SDO/MISO | SPI Data Out | `13` | 🟢 Verde |

### Configuração (User_Setup.h / PlatformIO flags)

```cpp
#define ILI9341_DRIVER
#define TFT_WIDTH  240
#define TFT_HEIGHT 320
#define TFT_MOSI   11
#define TFT_SCLK   12
#define TFT_CS     10
#define TFT_DC      9
#define TFT_RST    14
#define SPI_FREQUENCY  40000000  // 40MHz
```

---

## 👆 Módulo 2: Touch XPT2046

O controlador de touch vem **embutido** na mesma placa do display ILI9341. Compartilha o barramento SPI mas usa seu próprio CS.

| Pino Touch | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| T_CLK | SPI Clock (compartilhado) | `12` | 🟠 Laranja |
| T_CS | Touch Chip Select | `15` | 🟤 Marrom |
| T_DIN | SPI MOSI (compartilhado) | `11` | 🔵 Azul |
| T_DO | SPI MISO (compartilhado) | `13` | 🟢 Verde |
| T_IRQ | Interrupção (opcional) | Não conectado | — |

```cpp
#define TOUCH_CS 15
#define SPI_TOUCH_FREQUENCY 2500000 // 2.5MHz (touch é mais lento)
```

---

## 💾 Módulo 3: Cartão Micro SD

| Pino SD | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `5V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| CS | Chip Select SD | `38` | 🟣 Roxo |
| MOSI | SPI Data In | `11` | 🔵 Azul |
| MISO | SPI Data Out | `13` | 🟢 Verde |
| SCK | SPI Clock | `12` | 🟠 Laranja |

```cpp
#include <SD.h>
#include <SPI.h>

SPIClass spi(HSPI);
spi.begin(12, 13, 11, 38); // SCK, MISO, MOSI, CS
SD.begin(38, spi);
```

> [!CAUTION]
> Formate o cartão em **FAT32**. Cartões acima de 32GB precisam ser formatados com ferramenta externa (o Windows não formata em FAT32 acima de 32GB nativamente).

---

## 📻 Módulo 4: NRF24L01+PA+LNA #1

| Pino NRF | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `3.3V` (**LDO**) | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| CE | Chip Enable | `21` | ⚪ Branco |
| CSN | Chip Select | `16` | 🟡 Amarelo |
| SCK | SPI Clock | `12` | 🟠 Laranja |
| MOSI | SPI Data In | `11` | 🔵 Azul |
| MISO | SPI Data Out | `13` | 🟢 Verde |
| IRQ | Interrupção (opcional) | Não conectado | — |

> [!CAUTION]
> **Solde um capacitor de 10μF + 100nF** entre VCC e GND do módulo NRF, o mais perto possível dos pinos. Sem esse capacitor, o módulo vai resetar o ESP32 inteiro ao transmitir.

---

## 📻 Módulo 5: NRF24L01+PA+LNA #2

| Pino NRF | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `3.3V` (**LDO**) | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| CE | Chip Enable | `36` | 🟤 Marrom |
| CSN | Chip Select | `35` | 🟠 Laranja |
| SCK | SPI Clock | `12` | 🟠 Laranja |
| MOSI | SPI Data In | `11` | 🔵 Azul |
| MISO | SPI Data Out | `13` | 🟢 Verde |
| IRQ | Interrupção (opcional) | Não conectado | — |

> [!WARNING]
> **NUNCA** energize um módulo NRF PA+LNA sem a antena SMA conectada. A potência refletida destrói o estágio amplificador instantaneamente.

---

## 📡 Módulo 6: CC1101 Sub-GHz

| Pino CC1101 | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `3.3V` (**LDO**) | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| CSN | Chip Select | `18` | 🔵 Azul |
| SCK | SPI Clock | `12` | 🟠 Laranja |
| MOSI | SPI Data In | `11` | 🔵 Azul |
| MISO (GDO1) | SPI Data Out | `13` | 🟢 Verde |
| GDO0 | Interrupção / Data | `33` | 🟢 Verde |
| GDO2 | Status / Clock | `34` | 🟤 Marrom |

```cpp
#include <ELECHOUSE_CC1101_SRC_DRV.h>

ELECHOUSE_cc1101.setGDO(33, 34); // GDO0=33, GDO2=34
ELECHOUSE_cc1101.setSpiPin(12, 13, 11, 18); // SCK, MISO, MOSI, CS
ELECHOUSE_cc1101.Init();
ELECHOUSE_cc1101.setMHZ(433.92);
```

---

## 🔖 Módulo 7: PN532 NFC/RFID

### Configuração dos DIP Switches

Para usar no barramento I2C compartilhado, configure as chaves:

| Chave 1 | Chave 2 | Modo |
| :---: | :---: | :---: |
| **ON** (Cima) | **OFF** (Baixo) | **I2C** ✅ |

### Fiação

| Pino PN532 | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `3.3V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| SDA | I2C Data | `8` | 🟢 Verde |
| SCL | I2C Clock | `17` | 🟡 Amarelo |

### Endereço I2C: `0x24`

```cpp
#include <Wire.h>
#include <Adafruit_PN532.h>

Adafruit_PN532 nfc(-1, -1, &Wire); // I2C mode, no reset pin

void setup() {
    Wire.begin(8, 17);
    nfc.begin();
    nfc.SAMConfig();
}
```

> [!NOTE]
> Convive em paralelo com DS3231 e PAJ7620 sem conflito (endereços I2C diferentes).

---

## ⏰ Módulo 8: DS3231 RTC

| Pino DS3231 | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `3.3V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| SDA | I2C Data | `8` | 🟢 Verde |
| SCL | I2C Clock | `17` | 🟡 Amarelo |

### Endereço I2C: `0x68`

```cpp
#include <RTClib.h>
RTC_DS3231 rtc;

void setup() {
    Wire.begin(8, 17);
    rtc.begin();
}
```

---

## 🖐️ Módulo 9: PAJ7620 Sensor de Gestos

| Pino PAJ7620 | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `3.3V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| SDA | I2C Data | `8` | 🟢 Verde |
| SCL | I2C Clock | `17` | 🟡 Amarelo |

### Endereço I2C: `0x73`

```cpp
#include <RevEng_PAJ7620.h>
RevEng_PAJ7620 gestureSensor;

void setup() {
    Wire.begin(8, 17);
    gestureSensor.begin();
}
```

---

## 🛰️ Módulo 10: GPS NEO-6M

| Pino GPS | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `5V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| TX | GPS envia dados | `39` (ESP RX) | 🟢 Verde |
| RX | GPS recebe comandos | `40` (ESP TX) | 🟡 Amarelo |

```cpp
#include <TinyGPS++.h>
TinyGPSPlus gps;
HardwareSerial gpsSerial(1);

void setup() {
    gpsSerial.begin(9600, SERIAL_8N1, 39, 40);
}

void loop() {
    while (gpsSerial.available()) {
        gps.encode(gpsSerial.read());
    }
}
```

> [!TIP]
> O primeiro "fix" (Cold Start) pode levar **até 5 minutos** em ambiente aberto. Com bateria de backup, o "Hot Start" demora ~1 segundo.

---

## 📡 Módulo 11: YS-IRTM IR Serial

| Pino YS-IRTM | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC | Alimentação | `5V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| TXD | IR envia dados | `47` (ESP RX) | 🟢 Verde |
| RXD | IR recebe comandos | `1` (ESP TX) | 🟡 Amarelo |

```cpp
HardwareSerial irSerial(2);

void setup() {
    irSerial.begin(9600, SERIAL_8N1, 47, 1);
}

// Enviar comando IR NEC:
void sendIR(uint8_t addr, uint8_t cmd) {
    uint8_t data[] = {0xA1, 0xF1, addr, cmd};
    irSerial.write(data, 4);
}
```

---

## 🎤 Módulo 12: INMP441 Microfone

| Pino INMP441 | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VDD | Alimentação | `3.3V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| SCK | I2S Clock | `41` | 🟠 Laranja |
| WS | Word Select | `42` | 🟡 Amarelo |
| SD | Data Out | `2` | 🟢 Verde |
| L/R | Canal (L=GND) | `GND` | ⚫ Preto |

```cpp
#include <driver/i2s.h>

i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
};

i2s_pin_config_t pin_config = {
    .bck_io_num = 41,
    .ws_io_num = 42,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = 2,
};

i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
i2s_set_pin(I2S_NUM_0, &pin_config);
```

---

## 🕹️ Módulo 13: Joystick KY-023

| Pino Joystick | Função | GPIO ESP32-S3 | Cor do Fio |
| :---: | --- | :---: | :---: |
| VCC / +5V | Alimentação | `3.3V` | 🔴 Vermelho |
| GND | Terra | `GND` | ⚫ Preto |
| VRx | Eixo X (Analógico) | `4` | 🟠 Laranja |
| VRy | Eixo Y (Analógico) | `5` | 🟡 Amarelo |
| SW | Botão Click | `6` | 🔵 Azul |

```cpp
void setup() {
    pinMode(6, INPUT_PULLUP);
    analogReadResolution(12); // 0-4095
}

void loop() {
    int x = analogRead(4);  // 0-4095, centro ~2048
    int y = analogRead(5);  // 0-4095, centro ~2048
    bool btn = !digitalRead(6); // LOW = pressionado
}
```

> [!IMPORTANT]
> Alimente o joystick com **3.3V** (não 5V), ou os valores do ADC vão estourar e ler sempre 4095.

---

## 📚 Tabela de Bibliotecas e Drivers

| Módulo | Biblioteca | Versão | Link |
| --- | --- | :---: | --- |
| TFT ILI9341 | TFT_eSPI | 2.5.x | [GitHub](https://github.com/Bodmer/TFT_eSPI) |
| Touch XPT2046 | (inclusa no TFT_eSPI) | — | — |
| Micro SD | SD (built-in) | — | Arduino Core |
| NRF24L01 | RF24 | 1.4.x | [GitHub](https://github.com/nRF24/RF24) |
| CC1101 | SmartRC-CC1101-Driver-Lib | 2.5.x | [GitHub](https://github.com/LSatan/SmartRC-CC1101-Driver-Lib) |
| PN532 NFC | Adafruit-PN532 | 1.3.x | [GitHub](https://github.com/adafruit/Adafruit-PN532) |
| DS3231 RTC | RTClib | 2.1.x | [GitHub](https://github.com/adafruit/RTClib) |
| PAJ7620 Gesture | RevEng_PAJ7620 | 1.5.x | [GitHub](https://github.com/acrandal/RevEng_PAJ7620) |
| GPS NEO | TinyGPS++ | 1.0.x | [GitHub](https://github.com/mikalhart/TinyGPSPlus) |
| IR Serial (YS-IRTM) | HardwareSerial (built-in) | — | Arduino Core |
| Microfone INMP441 | driver/i2s.h (ESP-IDF) | — | ESP-IDF |
| Joystick | analogRead (built-in) | — | Arduino Core |

---

## ✅ Checklist de Montagem

Siga esta ordem **exatamente** para evitar danos:

- [ ] **1.** Monte o circuito de alimentação (BMS + Buck + LDO) **SEM** o ESP32 conectado
- [ ] **2.** Meça a saída do Buck com multímetro: deve marcar **5.0V** (±0.1V)
- [ ] **3.** Meça a saída do LDO: deve marcar **3.3V** (±0.05V)
- [ ] **4.** Conecte o ESP32-S3 ao Buck (VIN/5V e GND)
- [ ] **5.** Verifique que o ESP32 liga (LED built-in) e faça upload de um sketch "Blink"
- [ ] **6.** Conecte o Display TFT (pinos SPI + CS + DC + RST + Backlight)
- [ ] **7.** Upload do sketch de teste do TFT_eSPI → deve aparecer cores na tela
- [ ] **8.** Adicione o Touch (ele já compartilha SPI, só adicione o CS no GPIO 15)
- [ ] **9.** Adicione o Cartão SD (CS no GPIO 38)
- [ ] **10.** Teste leitura de arquivo do SD → se falhar, verifique o chip buffer MISO
- [ ] **11.** Conecte NRF24 #1 (CS=16, CE=21) no LDO dedicado, com capacitores
- [ ] **12.** Conecte NRF24 #2 (CS=35, CE=36) no LDO dedicado, com capacitores
- [ ] **13.** Conecte CC1101 (CS=18, GDO0=33, GDO2=34) no LDO dedicado
- [ ] **14.** Conecte os 3 módulos I2C em paralelo (SDA=8, SCL=17): PN532, DS3231, PAJ7620
- [ ] **15.** Conecte o GPS (TX→39, RX→40) na linha 5V
- [ ] **16.** Conecte o IR Serial (TX→47, RX→1) na linha 5V
- [ ] **17.** Conecte o Microfone INMP441 (SCK=41, WS=42, SD=2) na 3.3V
- [ ] **18.** Conecte o Joystick (X=4, Y=5, BTN=6) na 3.3V
- [ ] **19.** Flash do firmware Willy completo
- [ ] **20.** Teste cada módulo individualmente no menu do Willy

---

## 🔧 Troubleshooting

### "O display fica branco"

- Verifique se TFT_CS (GPIO 10), TFT_DC (GPIO 9) e TFT_RST (GPIO 14) estão corretos.
- Confirme que as flags `ILI9341_DRIVER` e os pinos estão definidos no `User_Setup.h`.

### "O Touch não responde"

- Verifique GPIO 15 (TOUCH_CS).
- O touch usa SPI a 2.5MHz, não 40MHz. Verifique `SPI_TOUCH_FREQUENCY`.

### "O cartão SD não monta"

- Formate em **FAT32**.
- Verifique se o módulo SD tem o buffer 74LVC125A (problema de MISO Hi-Z).

### "NRF24 não inicializa / ESP32 reseta"

- Capacitor! Solde `10μF + 100nF` entre VCC e GND de **cada** módulo NRF.
- Use o LDO dedicado, não a 3.3V do ESP32.

### "CC1101 não recebe sinais"

- Verifique GDO0 (GPIO 33). Sem ele, interrupções não funcionam.
- Confirme a frequência: Brasil = 433.92MHz (não 868MHz).

### "PN532 não encontrado"

- Verifique DIP switches: Chave 1 = ON, Chave 2 = OFF (modo I2C).
- Execute um scan I2C — deve mostrar endereço `0x24`.
- Se tiver pull-ups duplicados, remova os dos outros módulos I2C.

### "GPS sem fix"

- Vá para um local com **céu aberto**. O GPS precisa ver satélites.
- Primeiro fix demora até 5 minutos.

### "Joystick lê sempre 4095"

- Está alimentando com 5V? Mude para **3.3V**.

### "Vários módulos SPI falham ao mesmo tempo"

- Apenas **um CS** deve estar LOW por vez. Verifique se o firmware está gerenciando os CS corretamente.
- Módulo SD pode estar travando o MISO (veja "Regra do MISO" acima).
