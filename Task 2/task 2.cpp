#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream ellipse_file(argv[1]);
    double x0, y0, a, b;
    ellipse_file >> x0 >> y0 >> a >> b;
    ellipse_file.close();

    ifstream points_file(argv[2]);
    double x, y;

    while (points_file >> x >> y)
{
        double value = ((x - x0) * (x - x0)) / (a * a) + ((y - y0) * (y - y0)) / (b * b);

        if (value == 1.0) 
            cout << 0 << endl;
        else if (value < 1.0) 
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    points_file.close();
    return 0;
}

