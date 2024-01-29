#include "Copter.h"

bool ModeWater::init(bool ignore_checks)
{
    if (motors->armed()) {return false;}
    return true;
}

void ModeWater::run()
{
    hal.console->begin(115200);
    hal.console->printf("\n\nMotors expo inverse test\n\n");
    static uint16_t pwm_wat = 1600;

    motors->init(AP_Motors::MOTOR_FRAME_HEXA, AP_Motors::MOTOR_FRAME_TYPE_X);

    ///motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::THROTTLE_UNLIMITED);
    motors->set_dt(1.0/400.0);
    motors->set_update_rate(490);
    motors->output_min();
    motors->armed(true);
    
    motors->is_motor_enabled(5);
    motors->is_motor_enabled(6);

    for (uint8_t i = 1; i <= 6; ++i) {
        ///SRV_Channel::Aux_servo_function_t function = SRV_Channels::get_motor_function(i);
        ///SRV_Channels::set_aux_channel_default(function, i);
        

        motors->rc_write(i, pwm_wat);
    }

}