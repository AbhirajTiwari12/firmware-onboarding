#pragma once
#include <stdint.h>

namespace BMEConstants
{
    constexpr uint32_t SERIAL_BAUD = 115200;

    constexpr uint8_t I2C_ADDRESS = 0x76;

    constexpr int8_t SPI_CS_PIN = 10;

    constexpr uint8_t LED_PIN = 7;

    constexpr uint32_t SENSOR_READ_INTERVAL_MS = 500;

    constexpr float MIN_TEMP_C = 20.0f;
    constexpr float MAX_TEMP_C = 35.0f;
    constexpr uint32_t SLOW_BLINK_INTERVAL_MS = 1000;
    constexpr uint32_t FAST_BLINK_INTERVAL_MS = 100;
}
