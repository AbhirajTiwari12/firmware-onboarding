#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    explicit BMESPIInterface(int8_t cs_pin = BMEConstants::SPI_CS_PIN) : _bme(cs_pin, &SPI) {}

    bool init();

    void read();

    float get_temperature_c() const { return _temperature_c; }

private:
    Adafruit_BME280 _bme;
    float _temperature_c = NAN;
    bool _connected = false;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
