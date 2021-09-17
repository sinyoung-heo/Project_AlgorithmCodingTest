#include <iostream>
#include <vector>

using namespace std;

// 선택정렬

int main()
{
	vector<int> input;

	int n;
	cin >> n;

	input.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> input[i];

	int idx = -1;
	int start = 0;
	while (start != input.size() - 1)
	{
		++idx;
		++start;

		int min = INT_MAX;
		int minIdx = start;
		for (int i = start; i < input.size(); ++i)
		{
			if (min > input[i])
			{
				min = input[i];
				minIdx = i;
			}
		}

		if (input[idx] > input[minIdx])
			swap(input[idx], input[minIdx]);
	}


	for (auto& n : input)
		cout << n << " ";

	return 0;
}