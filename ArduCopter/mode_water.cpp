#include "Copter.h"

bool ModeWater::init(bool ignore_checks)
{
    return true;

}

void ModeWater::run()
{
    ///    static uint16_t pwm_wat = 1600;

    motors->init(AP_Motors::MOTOR_FRAME_HEXA, AP_Motors::MOTOR_FRAME_TYPE_X);

    for (uint8_t i = 5; i <= 6; ++i) {
        if (!motors->is_motor_enabled(i)) {
            continue;
        }

        int16_t pwm = motors->get_pwm_output_min() + (motors->get_pwm_output_max() - motors->get_pwm_output_min()) * 0.5f;

        motors->rc_write(i, pwm);
    }

}