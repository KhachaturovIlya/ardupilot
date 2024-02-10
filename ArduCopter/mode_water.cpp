#include "Copter.h"

bool ModeWater::init(bool ignore_checks)
{
    return true;
}

void ModeWater::run()
{
    if (motors->armed()) {
        motors->armed(false);
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::SHUT_DOWN);
    }
    hal.console->begin(115200);
    hal.console->printf("\n\nWater Mode working\n\n");
    static uint16_t pwm_wat = 1400;

    motors->init(AP_Motors::MOTOR_FRAME_HEXA, AP_Motors::MOTOR_FRAME_TYPE_X);

    motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::THROTTLE_UNLIMITED);
    ///motors->output_min();
    motors->armed(true);

    for (uint8_t i = 1; i <= 6; ++i) {
        ///SRV_Channel::Aux_servo_function_t function = SRV_Channels::get_motor_function(i);
        ///SRV_Channels::set_aux_channel_default(function, i);
        
        motors->is_motor_enabled(i);
        motors->rc_write(i, pwm_wat);
    }

}

void ModeWater::exit()
{
    motors->armed(false);
    ///motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::SHUT_DOWN);
    motors->init(AP_Motors::MOTOR_FRAME_QUAD, AP_Motors::MOTOR_FRAME_TYPE_X);
    for(int i = 5; i <= 6; ++i){motors->is_motor_enabled(i);}
}