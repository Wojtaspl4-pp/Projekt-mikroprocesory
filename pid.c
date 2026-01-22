#include "pid.h"

float PID_Compute(PID_Controller *pid, float setpoint, float measured)
{
    float error = setpoint - measured;
    pid->integral += error;
    float derivative = error - pid->prev_error;

    float output = pid->Kp * error
                 + pid->Ki * pid->integral
                 + pid->Kd * derivative;

    pid->prev_error = error;
    return output;
}
