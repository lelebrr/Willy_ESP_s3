# Guia de Solução de Problemas (Troubleshooting)

Este guia ajuda a resolver os problemas mais comuns encontrados ao montar ou operar o dispositivo Willy.

## 🛠️ Problemas de Hardware

### 1. Tela Branca (White Screen)

- **Causa**: Falha na comunicação com o controlador do display ou fiação incorreta.
- **Solução**: Verifique se o pino `TFT_CS` está bem conectado. No CYD, certifique-se de que está usando o ambiente correto no PlatformIO (`CYD-2USB`).

### 2. Touch Screen Não Responde

- **Causa**: Cabo flat do touch mal conectado ou calibração corrompida.
- **Solução**: Tente recalibrar no menu **Configurações -> Tela -> Calibrar Touch**. Se o problema persistir, verifique a continuidade dos pinos `T_CS`, `T_CLK` e `T_DIN`.

### 3. Cartão SD Não Monta ("SD Card Fail")

- **Causa**: Cartão mal inserido, formatado incorretamente ou alta velocidade de clock.
- **Solução**: Formate o cartão em **FAT32** (limite de 32GB para melhor compatibilidade). Verifique se o pino 5 (CS) está livre para uso do SD.

---

## 📡 Problemas de Módulos

### 4. GPS Sem Sinal (No Fix)

- **Causa**: Falta de visão do céu ou interferência de componentes eletrônicos.
- **Solução**: Vá para um local aberto. O primeiro "lock" pode levar até 5 minutos. Verifique se a chave de energia do GPS está ligada.

### 5. RF (CC1101) Não Transmite/Recebe

- **Causa**: Módulo mal energizado (requer 3.3V estável) ou pino GDO0 incorreto.
- **Solução**: Verifique se o interruptor do CC1101 está ligado e o do NFC desligado. Confira se o pino `GDO0` está mapeado para o GPIO 27.

---

## 💻 Problemas de Software/Compilação

### 6. Erro de Compilação no PlatformIO

- **Causa**: Falta de bibliotecas ou versão do framework incompatível.
- **Solução**: Execute `pio lib install` e certifique-se de que o hardware selecionado no arquivo `platformio.ini` corresponde ao seu dispositivo.

### 7. Interface Web Inacessível

- **Causa**: Willy não está no modo Access Point ou IP incorreto.
- **Solução**: Verifique se a rede WiFi "Willy-AP" aparece no seu celular. Acesse `http://192.168.4.1` no navegador.

---

## 🆘 Suporte Adicional

Se o seu problema não estiver listado aqui:

1. Verifique os logs no Serial Monitor (Baudrate 115200).
2. Consulte os arquivos de log no SD na pasta `/WILLY_LOGS/`.
3. Abra uma issue no repositório oficial do GitHub.
