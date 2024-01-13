#include "Copter.h"

bool ModeWater::init(bool ignore_checks)
{
    return true;

}

void ModeWater::run()
{
    ///    static uint16_t pwm_wat = 1600;


    motors->init(AP_Motors::MOTOR_FRAME_HEXA, AP_Motors::MOTOR_FRAME_TYPE_X);
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; ++i) {
        if (!motors->is_motor_enabled(i)) {
            continue;
        }

        const Vector2f output{motors->get_roll_factor(i), motors->get_pitch_factor(i)};

        int16_t pwm = motors->get_pwm_output_min() + (motors->get_pwm_output_max() - motors->get_pwm_output_min()) * 0.5;

        motors->rc_write(i, pwm);
    }

}