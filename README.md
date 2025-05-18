# LED Controller
A simple monochromatic LED controller for Home Assistant, powered by ESPHome on a XIAO ESP32-C3.

## Features
- Brightness control via Home Assistant UI  
- Over-the-air (OTA) updates  

## Hardware Requirements
- ESP32-C3 board (e.g. XIAO ESP32-C3)  
- Monochromatic LED strip or LED bar  
- Logic-level MOSFET/transistor (for driving higher currents)  
- Suitable power supply (e.g. 5 V or 12 V matching LED strip voltage)  
- Connecting wires  

## Configuration

All firmware configuration lives in [code.yaml](code.yaml):

```yaml
esphome:
  name: led-controller
  friendly_name: LED-Controller

esp32:
  board: esp32-c3-devkitm-1
  framework:
    type: arduino

logger:

api:
  encryption:
    key: "YOUR_API_ENCRYPTION_KEY"

ota:
  - platform: esphome
    password: "YOUR_OTA_PASSWORD"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password
  ap:
    ssid: "Led-Controller"
    password: "FALLBACK_AP_PASSWORD"

light:
  - platform: monochromatic
    name: "Light Bar"
    output: gpio_light
    id: light_bar1
    icon: "mdi:ceiling-light"

output:
  - platform: ledc
    pin: GPIO10
    id: gpio_light
    inverted: true

captive_portal:
```