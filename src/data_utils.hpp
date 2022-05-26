void read_data(string fname, vector<double>& vec);
void vec_print(vector<double>& vec);
double barymetric_lambda_gen(double a, double b, double x);
double barymetric_value_from_lambda(double a, double b, double lambda);
double index_find_from_x(vector<double>& vec, double x);
void aero_interpolation(vector<double>& Alpha, vector<double>& Cl, vector<double>& Cd, vector<double>& Cm, double* alpha, double* cl, double* cd, double* cm);
void vector1D_to_file(vector<double>& v, string fname);