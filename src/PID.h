#ifndef PID_H
#define PID_H
#include <random>

class PID {

public:
  /*
  * Errors
  */
  double p_cte;
  double i_cte;
  double d_cte;
  
  int cte_length;
  
  std::vector<double> cte_lst ;

  
  
  /*
  * Coefficients
  */ 
  double tau_p;
  double tau_i;
  double tau_d;

  
  double steering; 

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);
  

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);
  
  
  /*
   * Calculate the steering value. 
   */
  double GetErrorSquare();
  

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
};

#endif /* PID_H */