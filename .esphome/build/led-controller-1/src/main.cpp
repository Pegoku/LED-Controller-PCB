// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace light;
logger::Logger *logger_logger_id;
web_server_base::WebServerBase *web_server_base_webserverbase_id;
captive_portal::CaptivePortal *captive_portal_captiveportal_id;
wifi::WiFiComponent *wifi_wificomponent_id;
mdns::MDNSComponent *mdns_mdnscomponent_id;
web_server::WebServerOTAComponent *web_server_webserverotacomponent_id;
esphome::ESPHomeOTAComponent *esphome_esphomeotacomponent_id;
safe_mode::SafeModeComponent *safe_mode_safemodecomponent_id;
api::APIServer *api_apiserver_id;
using namespace api;
preferences::IntervalSyncer *preferences_intervalsyncer_id;
monochromatic::MonochromaticLightOutput *monochromatic_monochromaticlightoutput_id;
light::LightState *light_bar1;
using namespace output;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id;
ledc::LEDCOutput *gpio_light;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  App.reserve_light(1);
  // network:
  //   enable_ipv6: false
  //   min_ipv6_addr_count: 0
  // async_tcp:
  //   {}
  // esphome:
  //   name: led-controller-1
  //   friendly_name: LED-Controller-1
  //   min_version: 2025.7.4
  //   build_path: build/led-controller-1
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   debug_scheduler: false
  //   areas: []
  //   devices: []
  App.pre_setup("led-controller-1", "LED-Controller-1", "", __DATE__ ", " __TIME__, false);
  App.reserve_components(12);
  // light:
  // logger:
  //   id: logger_logger_id
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   task_log_buffer_size: 768
  //   hardware_uart: USB_CDC
  //   level: DEBUG
  //   logs: {}
  logger_logger_id = new logger::Logger(115200, 512);
  logger_logger_id->create_pthread_key();
  logger_logger_id->init_log_buffer(768);
  logger_logger_id->set_log_level(ESPHOME_LOG_LEVEL_DEBUG);
  logger_logger_id->set_uart_selection(logger::UART_SELECTION_USB_CDC);
  logger_logger_id->pre_setup();
  logger_logger_id->set_component_source("logger");
  App.register_component(logger_logger_id);
  // web_server_base:
  //   id: web_server_base_webserverbase_id
  web_server_base_webserverbase_id = new web_server_base::WebServerBase();
  web_server_base_webserverbase_id->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase_id);
  web_server_base::global_web_server_base = web_server_base_webserverbase_id;
  // captive_portal:
  //   id: captive_portal_captiveportal_id
  //   web_server_base_id: web_server_base_webserverbase_id
  captive_portal_captiveportal_id = new captive_portal::CaptivePortal(web_server_base_webserverbase_id);
  captive_portal_captiveportal_id->set_component_source("captive_portal");
  App.register_component(captive_portal_captiveportal_id);
  // wifi:
  //   ap:
  //     ssid: Led-Controller-1
  //     password: c7TExWdd6VRP
  //     id: wifi_wifiap_id
  //     ap_timeout: 1min
  //   id: wifi_wificomponent_id
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   passive_scan: false
  //   enable_on_boot: true
  //   networks:
  //     - ssid: !secret 'wifi_ssid_m'
  //       password: !secret 'wifi_password_m'
  //       id: wifi_wifiap_id_2
  //       priority: 0.0
  //   use_address: led-controller-1.local
  wifi_wificomponent_id = new wifi::WiFiComponent();
  wifi_wificomponent_id->set_use_address("led-controller-1.local");
  {
  wifi::WiFiAP wifi_wifiap_id_2 = wifi::WiFiAP();
  wifi_wifiap_id_2.set_ssid("DIGIFIBRA-hA7G");
  wifi_wifiap_id_2.set_password("R5kU9AZFR2");
  wifi_wifiap_id_2.set_priority(0.0f);
  wifi_wificomponent_id->add_sta(wifi_wifiap_id_2);
  }
  {
  wifi::WiFiAP wifi_wifiap_id = wifi::WiFiAP();
  wifi_wifiap_id.set_ssid("Led-Controller-1");
  wifi_wifiap_id.set_password("c7TExWdd6VRP");
  wifi_wificomponent_id->set_ap(wifi_wifiap_id);
  }
  wifi_wificomponent_id->set_ap_timeout(60000);
  wifi_wificomponent_id->set_reboot_timeout(900000);
  wifi_wificomponent_id->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent_id->set_fast_connect(false);
  wifi_wificomponent_id->set_passive_scan(false);
  wifi_wificomponent_id->set_enable_on_boot(true);
  wifi_wificomponent_id->set_component_source("wifi");
  App.register_component(wifi_wificomponent_id);
  // mdns:
  //   id: mdns_mdnscomponent_id
  //   disabled: false
  //   services: []
  mdns_mdnscomponent_id = new mdns::MDNSComponent();
  mdns_mdnscomponent_id->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent_id);
  // ota:
  // ota.web_server:
  //   platform: web_server
  //   id: web_server_webserverotacomponent_id
  web_server_webserverotacomponent_id = new web_server::WebServerOTAComponent();
  // ota.esphome:
  //   platform: esphome
  //   password: 8606e0b37cf4fdab65869aad6e50621a
  //   id: esphome_esphomeotacomponent_id
  //   version: 2
  //   port: 3232
  esphome_esphomeotacomponent_id = new esphome::ESPHomeOTAComponent();
  esphome_esphomeotacomponent_id->set_port(3232);
  esphome_esphomeotacomponent_id->set_auth_password("8606e0b37cf4fdab65869aad6e50621a");
  esphome_esphomeotacomponent_id->set_component_source("esphome.ota");
  App.register_component(esphome_esphomeotacomponent_id);
  // safe_mode:
  //   id: safe_mode_safemodecomponent_id
  //   boot_is_good_after: 1min
  //   disabled: false
  //   num_attempts: 10
  //   reboot_timeout: 5min
  safe_mode_safemodecomponent_id = new safe_mode::SafeModeComponent();
  safe_mode_safemodecomponent_id->set_component_source("safe_mode");
  App.register_component(safe_mode_safemodecomponent_id);
  if (safe_mode_safemodecomponent_id->should_enter_safe_mode(10, 300000, 60000)) return;
  web_server_webserverotacomponent_id->set_component_source("web_server.ota");
  App.register_component(web_server_webserverotacomponent_id);
  // api:
  //   encryption:
  //     key: A7/yPVQlZ8iXmnI/Zw1jFkoAKNDb9RMuOr4dR6iZ16s=
  //   id: api_apiserver_id
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  //   batch_delay: 100ms
  //   custom_services: false
  api_apiserver_id = new api::APIServer();
  api_apiserver_id->set_component_source("api");
  App.register_component(api_apiserver_id);
  api_apiserver_id->set_port(6053);
  api_apiserver_id->set_reboot_timeout(900000);
  api_apiserver_id->set_batch_delay(100);
  api_apiserver_id->set_noise_psk({3, 191, 242, 61, 84, 37, 103, 200, 151, 154, 114, 63, 103, 13, 99, 22, 74, 0, 40, 208, 219, 245, 19, 46, 58, 190, 29, 71, 168, 153, 215, 171});
  // esp32:
  //   board: esp32-c3-devkitm-1
  //   framework:
  //     version: 3.1.3
  //     advanced:
  //       ignore_efuse_custom_mac: false
  //     source: pioarduino/framework-arduinoespressif32@https:github.com/espressif/arduino-esp32/releases/download/3.1.3/esp32-3.1.3.zip
  //     platform_version: https:github.com/pioarduino/platform-espressif32/releases/download/53.03.13/platform-espressif32.zip
  //     type: arduino
  //   flash_size: 4MB
  //   variant: ESP32C3
  //   cpu_frequency: 160MHZ
  setCpuFrequencyMhz(160);
  // preferences:
  //   id: preferences_intervalsyncer_id
  //   flash_write_interval: 60s
  preferences_intervalsyncer_id = new preferences::IntervalSyncer();
  preferences_intervalsyncer_id->set_write_interval(60000);
  preferences_intervalsyncer_id->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer_id);
  // light.monochromatic:
  //   platform: monochromatic
  //   name: Light Bar
  //   output: gpio_light
  //   id: light_bar1
  //   icon: mdi:ceiling-light
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   gamma_correct: 2.8
  //   default_transition_length: 1s
  //   flash_transition_length: 0s
  //   output_id: monochromatic_monochromaticlightoutput_id
  monochromatic_monochromaticlightoutput_id = new monochromatic::MonochromaticLightOutput();
  light_bar1 = new light::LightState(monochromatic_monochromaticlightoutput_id);
  App.register_light(light_bar1);
  light_bar1->set_component_source("light");
  App.register_component(light_bar1);
  light_bar1->set_name("Light Bar");
  light_bar1->set_object_id("light_bar");
  light_bar1->set_disabled_by_default(false);
  light_bar1->set_icon("mdi:ceiling-light");
  light_bar1->set_restore_mode(light::LIGHT_ALWAYS_OFF);
  light_bar1->set_default_transition_length(1000);
  light_bar1->set_flash_transition_length(0);
  light_bar1->set_gamma_correct(2.8f);
  light_bar1->add_effects({});
  // output:
  // output.ledc:
  //   platform: ledc
  //   pin:
  //     number: 10
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   id: gpio_light
  //   inverted: true
  //   zero_means_zero: false
  //   frequency: 1000.0
  esp32_esp32internalgpiopin_id = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id->set_pin(::GPIO_NUM_10);
  esp32_esp32internalgpiopin_id->set_inverted(false);
  esp32_esp32internalgpiopin_id->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id->set_flags(gpio::Flags::FLAG_OUTPUT);
  gpio_light = new ledc::LEDCOutput(esp32_esp32internalgpiopin_id);
  gpio_light->set_component_source("ledc.output");
  App.register_component(gpio_light);
  gpio_light->set_inverted(true);
  gpio_light->set_zero_means_zero(false);
  gpio_light->set_frequency(1000.0f);
  // socket:
  //   implementation: bsd_sockets
  // md5:
  monochromatic_monochromaticlightoutput_id->set_output(gpio_light);
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
