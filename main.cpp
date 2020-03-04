#include <iostream>

using namespace std;

// Conversion functions
bool characteristic(char numString[], int& c);
bool mantissa(char numString[], int& numerator, int& denominator);

// Math functions
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

int main()
{
    cout<<"In-class Code Review"<<endl;

    return 0;
}
