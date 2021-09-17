#include <iostream>
#include <vector>

using namespace std;


char gameRSP(int a, int b)
{
	switch (a)
	{
		// ����
		case 1:
		{
			switch (b)
			{
				// ����
				case 1:
				{
					return 'D';
				} break;

					// ����
				case 2:
				{
					return 'B';
				} break;

					// ��
				case 3:
				{
					return 'A';
				} break;
			}
		} break;

			// ����
		case 2:
		{
			switch (b)
			{
				// ����
				case 1:
				{
					return 'A';
				} break;

				// ����
				case 2:
				{
					return 'D';
				} break;

				// ��
				case 3:
				{
					return 'B';
				} break;
			}
		} break;

			// ��
		case 3:
		{
			switch (b)
			{
				// ����
				case 1:
				{
					return 'B';
				} break;

				// ����
				case 2:
				{
					return 'A';
				} break;

				// ��
				case 3:
				{
					return 'D';
				} break;
			}
		} break;
	}

	return 0;
}

int main()
{
	int N = 0;
	cin >> N;

	vector<int> vecA;
	vector<int> vecB;
	vecA.resize(N);
	vecB.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> vecA[i];
	for (int i = 0; i < N; ++i)
		cin >> vecB[i];

	for (int i = 0; i < N; ++i)
		cout << gameRSP(vecA[i], vecB[i]) << endl;

	return 0;
}