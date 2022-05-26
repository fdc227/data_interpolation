#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "data_utils.hpp"

#define start -18.5
#define end 18.5
#define interval 0.1

int main(void)
{
    vector<double> Alpha;
    vector<double> Cl;
    vector<double> Cd;
    vector<double> Cm;
    string fname_Alpha = "../data/Alpha.dat";
    string fname_Cl = "../data/Cl.dat";
    string fname_Cd = "../data/Cd.dat";
    string fname_Cm = "../data/Cm.dat";
    read_data(fname_Alpha, Alpha);
    read_data(fname_Cl, Cl);
    read_data(fname_Cd, Cd);
    read_data(fname_Cm, Cm);
    // vec_print(Alpha);

    vector<double> Alpha_interpolated;
    vector<double> Cl_interpolated;
    vector<double> Cd_interpolated;
    vector<double> Cm_interpolated;

    for (int i = 0; start+i*interval<end; i++)
    {
        Alpha_interpolated.push_back(start+i*interval);
        Cl_interpolated.push_back(0.0);
        Cd_interpolated.push_back(0.0);
        Cm_interpolated.push_back(0.0);
    }

    for (int i = 0; i < Alpha_interpolated.size(); i++)
    {
        aero_interpolation(Alpha, Cl, Cd, Cm, &*Alpha_interpolated.begin()+i, &*Cl_interpolated.begin()+i, &*Cd_interpolated.begin()+i, &*Cm_interpolated.begin()+i);
    }
    
    vector1D_to_file(Alpha_interpolated, "../interpolated_data/Alpha_interpolated.dat");
    vector1D_to_file(Cl_interpolated, "../interpolated_data/Cl_interpolated.dat");
    vector1D_to_file(Cd_interpolated, "../interpolated_data/Cd_interpolated.dat");
    vector1D_to_file(Cm_interpolated, "../interpolated_data/Cm_interpolated.dat");

}