#include <iostream> // 8 variant SHOOTING
#include <iomanip>
#include <cmath>

int main()
{
    double y[100] = {0.5}; // starting y0
    double z[100] = {0.3615}; // starting z0  = 0.5,0,0.2354,0.3615;
    int i = 0;
    double x[10] = {0}; // starting x0
    double h = 0.1; // step
    while (i <= 10)
    {
        std::cout << "i=" << i << std::endl;
        std::cout << "x["<< i << "]=" << x[i] << " | ";
        y[i+1] = y[i] + h * z[i];
        std::cout << "y[" << i << "]=" << y[i] << " | ";
        z[i+1] = z[i] + h * (2 * 0.18 / pow(0.2 * x[i] + 1, 3 / 2) + (0.08 / (pow(0.2 * x[i] + 1, 2)) * y[i]));
        std::cout << "z[" << i << "]=" << z[i] << " | \n";
        x[i+1] = x[i] + h;
        i++;
    }

    return 0;
}

/*
#include <iostream> // PROGONKA 7 variant

using namespace std;

int main()
{
    double a[10][10] = { {10.4502, -9.95025, 0, 0, 0, 0, 0, 0, 0},
                       {100.55, -200.2, 99.45, 0, 0, 0, 0, 0, 0},
                       {0, 100.7, -200.4, 99.3, 0, 0, 0, 0, 0},
                       {0, 0, 100.95, -200.6, 99.5, 0, 0, 0, 0},
                       {0, 0, 0, 101.3, -200.8, 98.7, 0, 0, 0},
                       {0, 0, 0, 0, 101.75, -200.1, 98.25, 0, 0},
                       {0, 0, 0, 0, 0, 102.3, -201.2, 97.7, 0},
                       {0, 0, 0, 0, 0, 0, 102.95, -201.4, 97.05},
                       {0, 0, 0, 0, 0, 0, 0, 103.7, -201.6, 96.3},
                       {0, 0, 0, 0, 0, 0, 0, 0, -104.55, 201.8} };
    double f[10] = { 14.9562,
                    -105.184,
                    14.577,
                    49.570,
                    43.2408,
                    30.3207,
                    20.1364,
                    13.3412,
                    8.98269,
                    89.26611
                    };
    int dim = 10;

    double alfa[10] = {};
    double beta[10] = {};
    double z[10] = {};
    double x[11] = {};

    //double roots[3] = { 1,2,3 };

    cout << "Matrix:\n";
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            cout << a[i][j] << " ";
        };
        cout << "|" << f[i] << endl;
    };

    //cout << "Root x1: " << roots[0] << endl;
    //cout << "Root x2: " << roots[1] << endl;
    //cout << "Root x3: " << roots[2] << endl << endl;

    cout << "Let's start calculating the coefficients alpha and beta, zet will also be displayed\n";
    alfa[0] = a[0][1] / -a[0][0]; // 2 / (-1) = -2;
    beta[0] = -f[0] / -a[0][0];// -5 / -1 = 5;

    cout << "Iteration: 1" << endl;
    cout << "alfa0" <<": " << alfa[0] << endl;
    cout << "beta0" <<": " << beta[0] << endl;

    for (int i = 1; i <= dim-1; i++) {
        z[i] = -a[i][i] - a[i][i - 1] * alfa[i - 1];
        alfa[i] = a[i][i + 1] / z[i]; // 1.5, 0
        beta[i] = (-f[i] + a[i][i - 1] * beta[i - 1]) / z[i];// -2.5, 3
        if (i == dim - 1) {
            alfa[i] = 0;
        }
        cout << "Iteration: " << i+1 << endl;
        cout << "alfa" <<    i << ": " << alfa[i] << endl;
        cout << "beta" << i << ": " << beta[i] << endl;
        cout << "z" << i << ": " << z[i] << endl;
    };

    cout << endl;
    x[dim - 1] = beta[dim - 1];
    for (int i = dim - 1; i >= 0; i--) {
        x[i] = alfa[i] * x[i + 1] + beta[i];
    };

    cout << "Calculated roots:\n";
    for (int i = 0; i < dim; i++) {
        cout.precision(15);
        cout << "x" << i + 1 << ": " << x[i] << endl;
    }
}
*/
