#include "Arduino.h"
#include "Kalman.h"
#include <math.h>
Kalman::Kalman(float mea_e, float est_e, float q)
{ 
  // mea_e : measure_error
  // est_e : estimate_error
  _measure=mea_e;
  _estimate=est_e;
  _q = q;
}

bool Kalman::setMeasurementError(float mea_e)
{
  _measure=mea_e;
  return true;
}

bool Kalman::setEstimateError(float est_e)
{
  _estimate=est_e;
  return true;
}

bool Kalman::setProcessNoise(float q)
{
  _q=q;
  return true;
}

float Kalman::getKalmanGain() {
  return _gain;
}

float Kalman::getEstimateError() {
  return _estimate;
}
float Kalman::kalmanGain(){
  return _estimate/(_estimate+_measure);
}
float Kalman::update(float mea)
{
  _current_e = _last_e + kalmanGain * (mea - _last_e);
  _estimate =  (1.0 - kalmanGain)*_estimate + fabs( _last_e - _current_e) * _q;
  _last_e = _current_e; // update state of estimate
  return _current_e;
}
