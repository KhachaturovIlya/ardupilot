#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    copter.set_auto_armed(true);
    
    AP_HAL::RCOutput::BLHeliDshotCommand direction = true ? AP_HAL::RCOutput::DSHOT_REVERSE : AP_HAL::RCOutput::DSHOT_NORMAL;
    AP_HAL::RCOutput::BLHeliDshotCommand inverse_direction = true ? AP_HAL::RCOutput::DSHOT_NORMAL : AP_HAL::RCOutput::DSHOT_REVERSE;

    if (!hal.rcout->get_reversed_mask()) {
        hal.rcout->send_dshot_command(direction, AP_HAL::RCOutput::ALL_CHANNELS, 0, 10, true);
    } else {
        for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; ++i) {
            if (!motors->is_motor_enabled(i)) {
                continue;
            }

            if ((hal.rcout->get_reversed_mask() & (1U << i)) == 0) {
                hal.rcout->send_dshot_command(direction, i, 0, 10, true);
            } else {
                hal.rcout->send_dshot_command(inverse_direction, i, 0, 10, true);
            }
        }
    }

    motors->armed(true);
    for(int i=0; i<4; ++i){motors->rc_write(1, 1200);}
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{

}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
}
#endif

#ifdef USERHOOK_AUXSWITCH
void Copter::userhook_auxSwitch1(const RC_Channel::AuxSwitchPos ch_flag)
{
    motors->armed(true);
        motors->set_dt(1.0/400.0);
        motors->set_update_rate(490);
        motors->output_min();

        for(int i = 1; i < 6; ++i)
        {
        motors->rc_write(i, pwm_ex);}
}

void Copter::userhook_auxSwitch2(const RC_Channel::AuxSwitchPos ch_flag)
{
    motors->armed(true);
        motors->set_dt(1.0/400.0);
        motors->set_update_rate(490);
        motors->output_min();

        for(int i = 1; i < 6; ++i)
        {
        motors->rc_write(i, pwm_ex);}    // put your aux switch #2 handler here (CHx_OPT = 48)
}

void Copter::userhook_auxSwitch3(const RC_Channel::AuxSwitchPos ch_flag)
{
    motors->armed(true);
        motors->set_dt(1.0/400.0);
        motors->set_update_rate(490);
        motors->output_min();

        for(int i = 1; i < 6; ++i)
        {
        motors->rc_write(i, pwm_ex);}    // put your aux switch #3 handler here (CHx_OPT = 49)
}
#endif
