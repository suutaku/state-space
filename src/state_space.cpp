#include <state_space.h>

StateSpace::StateSpace(/* args */) {
    m = 12;     // input
    n = 3;      // state
    r = 3;      // output
    h = 0.002;  // step
    m_time_samples = 0;
    Eigen::MatrixXd A, B, C;
    A.resize(n, r);
    A.row(0)
        << -0.005246268918146 * 100,
        0.011333843785063 * 100,
        0.006758482295630 * 100;
    A.row(1) << 0.267880873817216 * 100, -0.697519065453146 * 100,
        -0.461514614862574 * 100;
    A.row(2) << 0.682062218450676 * 100, -1.739227172689009 * 100,
        -1.165397955456245 * 100;
    B.resize(r, m);
    B.row(0) << 0.025883060897373 * 10000, 0.035625435099437 * 10000,
        0.002104594352945 * 10000, 0.022471669117039 * 10000,
        -0.028724800578713 * 10000, 0.024726727143919 * 10000,
        -0.024414415056216 * 10000, 0.013824898796611 * 10000,
        -0.021751113748072 * 10000, -0.026853355066210 * 10000,
        -0.040747247631815 * 10000, -0.001071297753917 * 10000;
    B.row(1) << -1.584537756887962 * 10000, -2.393716762453076 * 10000,
        -0.100666763156882 * 10000, -1.785071769126092 * 10000,
        2.047946670838852 * 10000, -1.832745491185441 * 10000,
        1.795381743727541 * 10000, -0.869147562615822 * 10000,
        1.596382982264640 * 10000, 1.515528015708205 * 10000,
        2.575744544243867 * 10000, -0.000479890623214 * 10000;
    B.row(2) << -3.957022358700365 * 10000, -6.035229521208053 * 10000,
        -0.248420843889808 * 10000, -4.564557287341860 * 10000,
        5.194592753442518 * 10000, -4.663893115587425 * 10000,
        4.561374219345226 * 10000, -2.175774516679374 * 10000,
        4.059269370936629 * 10000, 3.750883629768099 * 10000,
        6.449847545205523 * 10000, -0.014149250625615 * 10000;
    C.resize(n, n);
    C.row(0) << -14.116623969691849, -2.569822656546348, 0.936684731009241;
    C.row(1) << -1.317401945689283, -0.334510022827894, 0.125987550453426;
    C.row(2) << -0.780239406885334, -0.153785323098714, 0.052204569918656;
    x0.resize(n, 1);
    x0.setZero();
    Eigen::Matrix3d I;
    I << 1, 0, 0,
        0, 1, 0,
        0, 0, 1;
    Eigen::MatrixXd tmp = (I - h * A);
    A_ = tmp.inverse();
    B_ = A_ * h * B;
    C_ = C;
}

StateSpace::~StateSpace() {
}

Eigen::MatrixXd StateSpace::Calculate(Eigen::MatrixXd input) {
    Eigen::MatrixXd ret(r, 1);
    ret.setZero();
    if (m_time_samples == 0) {
        m_state_sequence = x0;
    } else {
        m_state_sequence = A_ * m_last_state + B_ * m_last_input;
    }
    ret = C_ * m_state_sequence;
    m_last_input = input;
    m_last_state = m_state_sequence;
    m_time_samples++;
    return ret;
}