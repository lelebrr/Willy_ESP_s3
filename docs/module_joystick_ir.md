# Shield de Joystick (Funduino / KY-023) e Infravermelho (IR)

Este capítulo detalha os componentes de entrada analógica e a infraestrutura de comunicação infravermelha (IR).

## 1. Shield de Joystick

O "Joystick Shield para Arduino" (frequentemente baseado no módulo KY-023) fornece controle analógico de dois eixos (X/Y) e um botão de clique (Z/SW).

**Referências:**

- [CB Electronics: Shield KY-023](https://cb-electronics.com/products/ky-023-shield/)
- [Embarcados: Review do Joystick Shield Funduino](https://embarcados.com.br/review-hardware-joystick-shield-funduino/)
- [GitHub: Lógica de Joystick para ESP32-S2](https://github.com/schnoog/Joystick_ESP32S2)
- [ProtoSupplies: Conexões Funduino](https://protosupplies.com/wp-content/uploads/2018/07/Funduino-Joystick-Shield-Connections.jpg)

| Pino do Joystick | Pino ESP32-S3 | Tipo | Pinagem no Shield |
| :--- | :--- | :--- | :--- |
| `VCC` | `3.3V` | Ref Analógica | VCC / 5V (compatível com 3.3V) |
| `GND` | `GND` | Terra (Ground)| GND |
| `VRx` | `4` | `ADC1_CH3` | Analog 0 (Sugerido) |
| `VRy` | `5` | `ADC1_CH4` | Analog 1 (Sugerido) |
| `SW` | `6` | Entrada Digital| Botão K (Digital) |

**Notas Importantes:**

- Utilize `pinMode(6, INPUT_PULLUP)` no firmware para o botão SW.
- Na ESP32-S3, os ADCs possuem resolução de 12 bits (0-4095). O ponto central (repouso) costuma ser aproximadamente ~2048.

---

## 2. Infravermelho (IR) — Serial YS-IRTM v3.08

Para detalhes técnicos sobre o módulo IR serial, consulte o documento dedicado: **[docs/ys_irtm_ir_serial.md](ys_irtm_ir_serial.md)**

| Componente | Pino ESP32-S3 | Protocolo |
| :--- | :--- | :--- |
| **TX** | `1` | Serial UART |
| **RX** | `47` | Serial UART |
