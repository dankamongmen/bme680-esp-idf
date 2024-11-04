#ifndef DANKAMONGMEN_BME680
#define DANKAMONGMEN_BME680

// ESP-IDF component for working with Bosch BME680 environmental sensors.

#include <driver/i2c_master.h>

// Probe the I2C bus specified by i2c for a BME680. If it is found, the device
// handle i2cbme will be prepared for use, and 0 will be returned.
int bme680_detect(i2c_master_bus_handle_t i2c, i2c_master_dev_handle_t* i2cbme);

#endif