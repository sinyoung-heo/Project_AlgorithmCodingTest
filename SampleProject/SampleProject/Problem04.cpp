#include <iostream>
#include <vector>

using namespace std;

// N (2 <= N <= 100)���� ���̰� �Էµ˴ϴ�. �� N���� ��� �� ���� �������̰� ���� ���� ���� �� �� ?
// �ִ� ���� ���̸� ����ϴ� ���α׷� �ۼ�.

int main()
{
	int n = 0;
	vector<int> vecAge;

	int min = INT_MAX, max = 0;

	cin >> n;
	vecAge.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vecAge[i];

		if (vecAge[i] < min)
			min = vecAge[i];

		if (vecAge[i] > max)
			max = vecAge[i];
	}

	cout << max - min << endl;

	return 0;
}