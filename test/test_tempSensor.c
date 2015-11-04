#include "unity.h"
#include "tempSensor.h"

#include "mock_i2c.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_whenTempRegisterReadsMaxValue_thenTheTemperatureIsTheMaxValue(void)
{
	uint8_t tempRegisterAddress = 0x03; //This is the temperature register address.
	float expectedTemperature = 104.6f; //The temperature that we expect.
	float tolerance = 0.1f;							//How close we need to be.

	//When
	i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x3ff);

	//Then
	float actualTemperature = tempSensor_getTemperature();
	TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature, actualTemperature);
}

void test_whenTempRegisterReadsMinValue_thenTheTemperatureIsTheMinValue(void)
{
	uint8_t tempRegisterAddress = 0x03; //This is the temperature register address.
	float expectedTemperature = -100.0f; //The temperature that we expect.
	float tolerance = 0.1f;							//How close we need to be.

	//When
	i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x0);

	//Then
	float actualTemperature = tempSensor_getTemperature();
	TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature, actualTemperature);
}
