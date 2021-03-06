# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Reflection

The PID implementation itself was simple, the tuning is the hard part. There are 3 steps in the PID.

1. Init (w/ tuned parameters)
2. Update error in every cycle
3. Feedback for next cycle

In the update error stage, p_error is cte. d_error is differentiation of cte, since the delta_t is constant we use "cte - last_cte". i_error is the integration of cte so we use the accumulated cte. The code is in the UpdateError() in PID.cpp.

The feedback is using the formula, -Kp * p_error - Kd * d_error  - Ki * i_error. Surprisingly feeding it as the steering value, it works.

### P

"Proportional", this component directly effects the steering direction and the scale. If the car is right to the lane center(the distance is defined as CTE), it steers to left. If the car is far right to the lane center, it steers harder.

### D

"Differentiation", although P did the job already, the passenger might not feel good in the P-controlled car. Because it may oscillate constantly. So adding D can avoid the oscillation.

### I

"Integration", even D eliminated the oscillation. It may still suffer from the system bias so the CTE might keep large. Adding an accumulated system-wise cte, I, can reduce this bias.


## Tuning the parameter

Before tuning the parameter, we need to define what a good combination is. I used first 100 iterations as a warmup. And the next 2000 iterations' cte^2 as the error. I used the average of those 2000 cte^2 as the error. The less the better.

I wanted to use twiddle to tune the parameter, however, I can't tune the values with simulator automatically. So, in the end, I simulate the rule of twiddle and find a good combination.

![Parameter table](/parameter_table.png)