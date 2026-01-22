#ifndef PID_H
#define PID_H

typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float prev_error;
    float integral;
} PID_Controller;

float PID_Compute(PID_Controller *pid, float setpoint, float measured);

#endif
