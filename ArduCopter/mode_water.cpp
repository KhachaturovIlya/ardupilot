#include "Copter.h"

bool ModeWater::init(bool ignore_checks)
{
    if (motors->armed()) {
        return false;
    }
    return true;
    uint16_t pwm_wat = 1400;

    motors->init(AP_Motors::MOTOR_FRAME_HEXA, AP_Motors::MOTOR_FRAME_TYPE_X);
    motors->is_motor_enabled(5);
    motors->is_motor_enabled(6);
    motors->armed(true);
    motors->set_dt(1.0/400.0);
    motors->set_update_rate(490);
    motors->output_min();

    for(int i = 5; i <= 6; ++i)
    {
    motors->rc_write(i, pwm_wat);}
}

void ModeWater::run()
{

}