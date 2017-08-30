# CarND-Controls-PID
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)
--
The goal of this project is to properly control a simulated vehicles steering angles using PID control. PID represents the three parameters we must tune in order to achieve minimum Cross-Track Error (CTE):  

* tau_p - <em>Proportianal control to handle the CTE difference between the required steering angle and the predicted steering angle.</em>

* tau_d - <em>Diffrential control to handle the CTE differential. </em>

* tau_i - <em>Integral control to handle the CTE integral.</em>


## Controller steps

### Parameter Update  
* This PID controller utilizes the following rules:
    * tau_p is increased by 0.001 if 30th MSE value is greater than 3
    * tau_d is increased by 0.01 if 30th MSE value is between 0.3 and 1
    * tau_i is increased by 0.000001 if 30th MSE value is between 0.01 and 0.1

### Parameter selection
* Parameters must be selected due to our inability to control steering angles at initialization and the danger of highly increasing parameters.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
