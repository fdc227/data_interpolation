#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void read_data(string fname, vector<double>& vec)
{
	fstream file;
	file.open(fname, ios::in);
	while (!file.eof())
	{
		double tmp;
        while(file >> tmp)
        {
            vec.push_back(tmp);
        }
	}
    file.close();
}

void vec_print(vector<double>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

double barymetric_lambda_gen(double a, double b, double x) // get lambda from x that is between a and b, a is assumed to be smaller than b
{
     return (b-x) / (b-a);
}

double barymetric_value_from_lambda(double a, double b, double lambda)
{
    return a * lambda + (1 - lambda) * b;
}

double index_find_from_x(vector<double>& vec, double x) // vec is sorted, idx is for b
{
    double idx = 0;
    while(idx < vec.size() && x > vec[idx])
    {
        idx++;
    }
    return idx;
}


void aero_interpolation(vector<double>& Alpha, vector<double>& Cl, vector<double>& Cd, vector<double>& Cm, double* alpha, double* cl, double* cd, double* cm)
{
    int idx = index_find_from_x(Alpha, *alpha);
    if (idx ==0 || idx == Alpha.size())
    {
        *alpha = 0.0;
        *cl = 0.0;
        *cd = 0.0;
        *cm = 0.0;
    }
    else
    {
        double lambda = barymetric_lambda_gen(Alpha[idx-1], Alpha[idx], *alpha);
        *cl = barymetric_value_from_lambda(Cl[idx-1], Cl[idx], lambda);
        *cd = barymetric_value_from_lambda(Cd[idx-1], Cd[idx], lambda);
        *cm = barymetric_value_from_lambda(Cm[idx-1], Cm[idx], lambda);
    }
}

void vector1D_to_file(vector<double>& v, string fname)
{
	fstream file;
	file.open(fname, ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		file << v[i] << '\n';
	}
	file.close();
}