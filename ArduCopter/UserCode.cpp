#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    motors->init(AP_Motors::MOTOR_FRAME_QUAD, AP_Motors::MOTOR_FRAME_TYPE_X);
    motors->set_dt(1.0/400.0);
    motors->set_update_rate(490);
    motors->output_min();
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
    chel += 1;

    if(chel == 100)
    {
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
    // put your aux switch #1 handler here (CHx_OPT = 47)
}

void Copter::userhook_auxSwitch2(const RC_Channel::AuxSwitchPos ch_flag)
{
    // put your aux switch #2 handler here (CHx_OPT = 48)
}

void Copter::userhook_auxSwitch3(const RC_Channel::AuxSwitchPos ch_flag)
{
    // put your aux switch #3 handler here (CHx_OPT = 49)
}
#endif
