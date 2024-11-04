#include "bme680.h"
#include <esp_log.h>
#include <freertos/FreeRTOS.h>

static const char* TAG = "bme";

static const unsigned TIMEOUT_MS = 1000u; // FIXME why 1s?

int bme680_detect(i2c_master_bus_handle_t i2c, i2c_master_dev_handle_t* i2cbme){
  const unsigned addr = 0x77;
  esp_err_t e = i2c_master_probe(i2c, addr, TIMEOUT_MS);
  if(e != ESP_OK){
    ESP_LOGE(TAG, "error (%s) detecting BME680 at 0x%02x", esp_err_to_name(e), addr);
    return -1;
  }
  i2c_device_config_t devcfg = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = addr,
    .scl_speed_hz = 100000,
  };
  ESP_LOGI(TAG, "successfully detected BME680 at 0x%02x", addr);
  if((e = i2c_master_bus_add_device(i2c, &devcfg, i2cbme)) != ESP_OK){
    ESP_LOGE(TAG, "error (%s) adding bme680 i2c device", esp_err_to_name(e));
    return -1;
  }
  return 0;
}
