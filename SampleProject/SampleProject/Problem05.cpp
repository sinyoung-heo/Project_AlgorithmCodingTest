#include <iostream>

using namespace std;

constexpr int THIS_YEAR = 2019;
constexpr int GENDER_IDX = 7;

int main()
{
	int age = 0;
	char gender = ' ';

	char number[32] = "";
	cin >> number;

	int v1 = 0, v2 = 0, v3 = 0;
	v1 = ((int)number[0] - 48) * 10;
	v2 = (int)number[1] - 48;

	switch (number[GENDER_IDX])
	{
		case '1':
		{
			gender = 'M';
			age = THIS_YEAR - (1900 + v1 + v2) + 1;
		}
		break;
		
		case '2':
		{
			gender = 'W';
			age = THIS_YEAR - (1900 + v1 + v2) + 1;
		}
		break;

		case '3':
		{
			gender = 'M';
			age = THIS_YEAR - (2000 + v1 + v2) + 1;
		}
		break;

		case '4':
		{
			gender = 'W';
			age = THIS_YEAR - (2000 + v1 + v2) + 1;
		}
		break;
	}

	cout << age << " " << gender << endl;

	return 0;
}