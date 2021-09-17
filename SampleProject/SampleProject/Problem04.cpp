#include <iostream>
#include <vector>

using namespace std;

// N (2 <= N <= 100)명의 나이가 입력됩니다. 이 N명의 사람 중 가장 나이차이가 많이 나는 경우는 몇 살 ?
// 최대 나이 차이를 출력하는 프로그램 작성.

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