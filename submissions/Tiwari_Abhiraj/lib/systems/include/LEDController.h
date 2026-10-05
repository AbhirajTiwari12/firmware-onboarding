#pragma once
#include <stdint.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void update(float temperature_c, uint32_t now_ms);

    bool is_led_on() const { return _led_on; }

    static uint32_t compute_blink_interval_ms(float temperature_c);

private:
    uint32_t _last_toggle_ms = 0;
    bool _led_on = false;
};
