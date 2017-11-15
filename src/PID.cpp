#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->p[0] = Kp;
  this->p[1] = Ki;
  this->p[2] = Kd;
  this->prev_p_perror = 0.0;
  this->int_error = 0.0;
}

void PID::UpdateError(double cte) {
  this->p_error = cte;

  this->d_error = cte - prev_p_perror;
  prev_p_perror = cte;

  this->i_error += cte;
}

double PID::TotalError() {
  return -p[0] * p_error - p[2] * d_error  - p[1] * i_error;
}