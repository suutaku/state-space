#include <state_space.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    StateSpace sp;
    std::cout << "hello\n";
    std::ifstream infile("/Users/john/Desktop/cntel/仿生机器人2期/PlanA/source/state-space/output.txt");
    std::ofstream outfile("./cpp_output.txt");
    std::string line;
    int count = 0;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        double a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11;
        if (!(iss >> a0 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10 >> a11)) {
            break;
        }  // error
           // printf("read: %f %f %f %f %f %f %f %f %f %f %f %f \n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
        Eigen::MatrixXd tmp;
        tmp.resize(12, 1);
        tmp.col(0) << a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11;
        // std::cout << tmp << std::endl;
        Eigen::MatrixXd res = sp.Calculate(tmp);
        outfile << res.col(0)[0] << " " << res.col(0)[1] << " " << res.col(0)[2] << std::endl;
    }
    return 0;
}