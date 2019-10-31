class Kalman
{

public:
  Kalman(float mea_e, float est_e, float q);
  float updateEstimate(float mea);
  bool setMeasurementError(float mea_e);
  bool setEstimateError(float est_e);
  bool setProcessNoise(float q);
  float getKalmanGain();
  float getEstimateError();

private:
  float _measure;
  float _estimate;
  float _q;
  float _current_e;
  float _last_e;
  float _gain;

protected: 
  float kalmanGain(); 
};