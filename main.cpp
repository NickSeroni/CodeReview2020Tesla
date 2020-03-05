#include <iostream>

using namespace std;

// Conversion functions
bool characteristic(char numString[], int& c);
bool mantissa(char numString[], int& numerator, int& denominator);
// conversion helper functions
bool isDigit(char ch);
bool isNumValid(char numString[]);
bool hasCharacteristic(char numString[]); // checks if any characteristic entered ex: -.123
bool isNegative(char numString[]); // negative nums with no characteristic must be handled by mantissa
bool findIn(char numString[], char c);

int findFirstIndexOf(char numString[], char c);
int pow(int base, int power);
int getCStringSize(char* string);

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
	if (characteristic(number, c))// && mantissa(number, n, d))
	{
		//calculate c, n, d	
	}
	else
	{
		// handle error on input
	}

    return 0;
}

// Stores the characteristic from param numString[] in param c
bool characteristic(char numString[], int& c)
{
	bool isValid = isNumValid(numString);

	if (isValid == true) 
	{
		// if the number doesnt have a characteristic set c to 0
		if (hasCharacteristic(numString) == false) 
		{
			c = 0;
		}

		int strSize = getCStringSize(numString);
		int startingIndex = 0; // Starting index for the string loop

		if (isDigit(numString[0]) == false) // if character is '-' or '+'
		{
			startingIndex = 1;
		}

		int decimalIndex = strSize; // if there is no decimal, then default to the end of the string
		if (findIn(numString, '.') == true)
		{
			decimalIndex = findFirstIndexOf(numString, '.');
		}
		
		// Add digits together multiplied by powers of 10
		// ex: 1, 2, 3 -> 1x100 + 2x10 + 3 -> 123.
		int sum = 0;
		for (int i = startingIndex; i < decimalIndex; i++)
		{
			// subtracting 48 to convert from ASCII to int (ASCII 0 starts at 48)
			sum += (numString[i] - 48) * pow(10, decimalIndex - i - 1);
		}

		// set c to negative
		if (isNegative(numString) == true)
		{
			c = sum * -1;
		}
		else
		{
			c = sum;
		}
	}

	return isValid;
}

bool isDigit(char ch)
{
	bool isDigit = false;

	// Determine if the character is a digit by ASCII codes for 0-9
	if (ch >= 48 && ch <= 57)
	{
		isDigit = true;
	}

	return isDigit;
}

// String is valid if:
// all characters are digits
// only first character can be either '+' or '-'
// only one instance of '.'
bool isNumValid(char numString[])
{
	bool isValid = true;
	int strSize = getCStringSize(numString);

	int decimalCount = 0; // Keep track of the decimal encounters 
	for (int i = 0; i < strSize; i++)// Iterate through every character
	{
		if (isDigit(numString[i]) == false) // If the character isnt a digit
		{
			// it could be a decimal, in which case we continue and let the later condition handle it
			if (numString[i] == '.')
			{
				continue;
			}
			// otherwise, we must check for first index unary sign
			else if (i == 0 && numString[i] == '+' || isNegative(numString))
			{
				continue;
			}
			// otherwise the character must be invalid
			else
			{
				isValid = false;
			}
		}

		if (numString[i] == '.')
		{
			decimalCount++;
		}
	}

	if (decimalCount > 1 || decimalCount < 0)
	{
		isValid = false;
	}

	return isValid;
}

bool hasCharacteristic(char numString[])
{
	bool exists = false;
	int size = getCStringSize(numString);

	// if there is a digit between the beginning or a unary sign and the decimal or end
	// then the characteristic must exist
	for (int i = 0; numString[0] != '.' || i < size; i++)
	{
		if (isDigit(numString[i]))
		{
			exists = true;
			break;
		}
	}

	return exists;
}

bool isNegative(char numString[])
{
	bool isNeg = false;

	if (numString[0] == '-')
	{
		isNeg = true;
	}

	return isNeg;
}

bool findIn(char numString[], char c)
{
	bool exists = false;
	int size = getCStringSize(numString);

	for (int i = 0; i < size; i++)
	{
		if (numString[i] == c)
		{
			exists = true;
			break;
		}
	}

	return exists;
}

int findFirstIndexOf(char numString[], char c)
{
	int result = -1;
	int size = getCStringSize(numString);

	for (int i = 0; i < size; i++)
	{
		if (numString[i] == c)
		{
			result = i;
			break;
		}
	}

	return result;
}

int pow(int base, int power)
{
	int result = base;

	if (power <= 0)
	{
		result = 1;
	}
	else
	{
		for (int i = 1; i < power; i++)
		{
			result *= base;
		}
	}

	return result;
}

int getCStringSize(char numString[])
{
	char* copy = nullptr; // copy of the original string

	for (copy = numString; *copy != '\0'; copy++)// continue the pointer until we reach the null terminator
	{
		continue;
	}

	// our return value of the size, the difference between the start and final pointer
	return int(copy - numString); 
}