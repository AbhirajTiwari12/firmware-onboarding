#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool init(uint8_t address = BMEConstants::I2C_ADDRESS);

    void read();

    float get_temperature_c() const { return _temperature_c; }

private:
    Adafruit_BME280 _bme;
    float _temperature_c = NAN;
    bool _connected = false;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
