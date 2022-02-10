#ifndef STATE_SPACE
#define STATE_SPACE
#include <Eigen/Dense>
#include <iostream>

class StateSpace {
   private:
    /* data */
    Eigen::MatrixXd A_, B_, C_;    // A,B,C matrices
    Eigen::MatrixXd x0;            // initial state
    Eigen::MatrixXd m_last_input;  // input sequnce, dimensions: m\times  timeSamples
    Eigen::MatrixXd m_last_state;
    Eigen::MatrixXd m_state_sequence;   // simulated state sequence, dimensions: n\times  timeSamples
    Eigen::MatrixXd m_output_sequence;  // simulated output sequence, dimensions: r\times  timeSamples
    Eigen::MatrixXd timeRowVector;      // time row vector [0,1,2,3,\ldots, timeSamples-1]
    int m_time_samples;
    int m, n, r, timeSamples;  // m - input dimension, n- state dimension, r-output dimension, timeSamples- number of time samples
    double h;

   public:
    StateSpace(/* args */);
    ~StateSpace();
    Eigen::MatrixXd Calculate(Eigen::MatrixXd input);
};

#endif
