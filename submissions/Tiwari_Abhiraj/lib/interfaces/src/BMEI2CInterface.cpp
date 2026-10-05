#include "BMEI2CInterface.h"

bool BMEI2CInterface::init(uint8_t address)
{
    _connected = _bme.begin(address, &Wire);
    return _connected;
}

void BMEI2CInterface::read()
{
    _temperature_c = _connected ? _bme.readTemperature() : NAN;
}
