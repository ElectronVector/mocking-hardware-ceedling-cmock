#include "tempSensor.h"
#include "i2c.h"
#include <stdint.h>

float tempSensor_getTemperature(void)
{
  uint16_t rawValue = i2c_readRegister(0x03);

  return -100.0f + (0.2f * (float)rawValue);
}
