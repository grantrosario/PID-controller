#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    tau_p = Kp;
    tau_i = Ki;
    tau_d = Kd;

    tau_p = 0.22;
    tau_i = 0.000195;
    tau_d = 2.55;
    
    p_cte = 0;
    i_cte = 0;
    d_cte = 0;
    cte_length = 0 ;
}



void PID::UpdateError(double cte) {
    //Update Error
    d_cte = cte - p_cte;
    p_cte = cte;
    i_cte += cte;
    
    //Add Update Weight Steps
    cte_lst.push_back(cte);
    cte_length += 1;
    
    // STEP FOR CALCULATING FIRST INITIAL PARAMETERS (~TWIDDLE)
    /*
    if(cte_length > 30 ){
        vector<double> y(cte_lst.end()-30,cte_lst.end());
        cte_lst = y;
        double total_error = PID::GetErrorSquare();
       
        if(total_error >= 0.3){
            Kp_ += 0.001;
        }
        if(total_error >= 0.1 && total_error < 0.3 ){
            Kd_ += 0.01;
        }
        
        if(total_error >= 0.01 && total_error< 0.1){
            Ki_ += 0.000001;
        }
        
        
        if(cte_length % 100 ==0 ){
            cout<<"CTE LENGTH "<<cte_length <<endl;;
            cout<<"It's total error:"<<total_error<<endl;
            cout<<"It's p error    :"<<p_error<<endl;
            cout<<"It's d error    :"<<d_error<<endl;
            cout<<"It's i error    :"<<i_error<<endl;
            cout<<"Im Kp_          :"<<Kp_<<endl;
            cout<<"Im Kd_          :"<<Kd_<<endl;
            cout<<"Im Ki_          :"<<Ki_<<endl;
            cout<<"\n"<<endl;
        }
     
      }
     **/

    }


// Get the mean CTE Squared. 
double PID::GetErrorSquare() {
    double err = 0;
    for(int i = 0; i < cte_lst.size(); i++){
        err += pow(cte_lst[i],2.0);
    }
    err = err / cte_lst.size();
    return err;
}

double PID::TotalError(){
    double steer = (-1) * tau_p * p_cte - tau_d * d_cte - tau_i * i_cte;
    return steer;
}