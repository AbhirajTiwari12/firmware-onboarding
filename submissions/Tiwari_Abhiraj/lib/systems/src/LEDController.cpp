#include "LEDController.h"

uint32_t LEDController::compute_blink_interval_ms(float temperature_c)
{
    using namespace BMEConstants;

    if (!(temperature_c > MIN_TEMP_C))
    {
        return SLOW_BLINK_INTERVAL_MS;
    }
    if (temperature_c >= MAX_TEMP_C)
    {
        return FAST_BLINK_INTERVAL_MS;
    }

    const float fraction = (temperature_c - MIN_TEMP_C) / (MAX_TEMP_C - MIN_TEMP_C);
    const float span = static_cast<float>(SLOW_BLINK_INTERVAL_MS - FAST_BLINK_INTERVAL_MS);
    return SLOW_BLINK_INTERVAL_MS - static_cast<uint32_t>(fraction * span + 0.5f);
}

void LEDController::update(float temperature_c, uint32_t now_ms)
{
    if (temperature_c != temperature_c)
    {
        _led_on = false;
        _last_toggle_ms = now_ms;
        return;
    }

    const uint32_t interval_ms = compute_blink_interval_ms(temperature_c);

    if (now_ms - _last_toggle_ms >= interval_ms)
    {
        _led_on = !_led_on;
        _last_toggle_ms = now_ms;
    }
}
