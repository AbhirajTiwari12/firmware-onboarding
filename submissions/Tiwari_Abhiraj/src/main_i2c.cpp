#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

namespace
{
    LEDController led_controller;
    uint32_t last_read_ms = 0;
}

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);

    BMEI2CInterfaceInstance::create();
    if (BMEI2CInterfaceInstance::instance().init())
    {
        Serial.println(F("BME280 found over I2C"));
    }
    else
    {
        Serial.println(F("ERROR: BME280 not found over I2C, check wiring"));
    }
}

void loop()
{
    const uint32_t now_ms = millis();
    BMEI2CInterface &bme = BMEI2CInterfaceInstance::instance();

    if (now_ms - last_read_ms >= BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        last_read_ms = now_ms;
        bme.read();

        Serial.print(F("Temp: "));
        Serial.print(bme.get_temperature_c());
        Serial.print(F(" C | blink interval: "));
        Serial.print(LEDController::compute_blink_interval_ms(bme.get_temperature_c()));
        Serial.println(F(" ms"));
    }

    led_controller.update(bme.get_temperature_c(), now_ms);
    digitalWrite(BMEConstants::LED_PIN, led_controller.is_led_on() ? HIGH : LOW);
}
