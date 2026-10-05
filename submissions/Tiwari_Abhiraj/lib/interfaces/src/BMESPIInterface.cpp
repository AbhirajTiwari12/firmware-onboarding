#include "BMESPIInterface.h"

bool BMESPIInterface::init()
{
    _connected = _bme.begin();
    return _connected;
}

void BMESPIInterface::read()
{
    _temperature_c = _connected ? _bme.readTemperature() : NAN;
}
