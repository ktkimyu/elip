#include "elip/stats/random_engine.h"
#include "elip/stats/random_sample.h"

#include <map>
#include <iomanip>
#include <iostream>



int main(int argc, char *argv[])
{
//    std::mt19937 gen = elip::RandomEngine{}.GetMT19937();
//
//    std::map<int, int> hist{};
//    for(int n=0; n<10000; ++n) {
//        ++hist[std::round( elip::SampleNormal() )];
//    }
//
//   for(auto p : hist) {
//        std::cout << std::setw(2)
//                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
//    }

    const int nrolls = 10000; // number of experiments
    const int nstars = 95;    // maximum number of stars to distribute

    std::default_random_engine generator;

    int p[10]={};

    for (int i=0; i<nrolls; ++i) {
        int number = elip::SampleUniform(0, 9);
        ++p[number];
    }

    std::cout << "uniform_int_distribution (0,9):" << std::endl;
    for (int i=0; i<10; ++i)
        std::cout << i << ": " << std::string(p[i]*nstars/nrolls,'*') << std::endl;

//    const int nrolls=10000;  // number of experiments
//    const int nstars=95;     // maximum number of stars to distribute
//    const int nintervals=10; // number of intervals
//
//    std::default_random_engine generator;
//
//    int p[nintervals]={};
//
//    for (int i=0; i<nrolls; ++i) {
//        double number = elip::SampleUniform();
//        ++p[int(nintervals*number)];
//    }
//
//    std::cout << "uniform_real_distribution (0.0,1.0):" << std::endl;
//    std::cout << std::fixed; std::cout.precision(1);
//
//    for (int i=0; i<nintervals; ++i) {
//        std::cout << float(i)/nintervals << "-" << float(i+1)/nintervals << ": ";
//        std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
//    }
}
