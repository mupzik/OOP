#include <iostream>
#include <math.h>



int main()
{
    setlocale(LC_ALL, "rus");
    int xo = 2, M1 = 1, M2 = 4;
    double h1, h2, diff1, diff2, eps = 0.001;

    std::cout << "Задание №1:\n\nПо первой формуле верхний порог для h = ";
    std::cout << pow((6 * eps / M1),0.5) << "\nh = ";
    std::cin >> h1;
    diff1 = (log(xo + h1) - log(xo - h1)) / (2 * h1);
    std::cout << "Производная по первой формуле: " << diff1 <<"\n\n";

    std::cout << "По второй формуле верхний порог для h = ";
    std::cout << pow((30 * eps / M2), 0.25) << "\nh = ";
    std::cin >> h2;
    diff2 = (log(xo - 2 * h2) - 8 * log(xo - h2) + 8 * log(xo + h2) - log(xo + 2 * h2)) / (12 * h2);
    std::cout << "Производная по второй формуле: " << diff2;

    const int N = 7;
    double x[N]{ 3.2, 3.9, 4.6, 5.3, 6.0, 6.7, 7.4 };
    double y[N][N]{ {1.85107,0,0,0,0,0,0},
                    {1.03027,0,0,0,0,0,0},
                    {0.11931,0,0,0,0,0,0},
                    {-0.87462,0,0,0,0,0,0},
                    {1.94582,0,0,0,0,0,0},
                    {-3.08963,0,0,0,0,0,0},
                    {-4.302140,0,0,0,0,0} };
    
   /* double x[N]{ 4, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6 };
    double y[N][N]{ {4.123106,0,0,0,0,0,0,0},
                    {4.22019,0,0,0,0,0,0,0},
                    {4.317407,0,0,0,0,0,0,0},
                    {4.414748,0,0,0,0,0,0,0},
                    {4.512206,0,0,0,0,0,0,0},
                    {4.609772,0,0,0,0,0,0,0},
                    {4.707441,0,0,0,0,0,0,0},
                    {4.805206,0,0,0,0,0,0,0} };*/
    double s, d, delta,  h = 0.1;

    std::cout << "\n\nЗадание №2\nk:\tx:\ty(x):\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << i << "\t" << x[i] << "\t" << y[i][0] << "\n";
    }

    std::cout << "\nD:\n";
    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < N - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N-i; j++)
            std::cout << y[i][j] << "\t\t";
        std::cout << "\n";
    }
        
    std::cout << "\ny’(xo):\t\tпогр.\n";
    
    s = 0;
    d = -1;
    delta = 0;
    for (int j = 1; j < N - 1; j++)
    {
        d = (-1) * d;
        s = s + d * y[0][j] / (j * h);
        delta = abs(y[0][j + 1] / ((j + 1) * h));
        std::cout << s << "\t\t" << delta << '\n';
    }
}

