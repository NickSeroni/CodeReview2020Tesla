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

	char number[] = "123.456";
	int c, n, d;

	// If the conversion from C string to integers can take place
	if (characteristic(number, c) && mantissa(number, n, d))
	{
		// do math with c, n, d
	}
	else
	{
		// handle error on input
	}

    return 0;
}

bool characteristic(char numString[], int& c)
{

}
