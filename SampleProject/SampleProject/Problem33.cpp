#include <iostream>
#include <vector>

using namespace std;

/*
	33. 3등의 성적은?
	 N명의 수학성적이 주어지면 그 중 3등을 한 수학성적을 출력하는 프로그램을 작성하세요.
	만약 학생의 점수가 100점이 3명, 99점이 2명, 98점이 5명, 97점이 3명 이런식으로 
	점수가 분포되면 1등은 3명이며, 2등은 2명이며 3등은 5명이 되어 98점이 3등을 한 점수가 됩니다.

	▣ 입력설명
	 첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
	두 번째 줄에 N개의 수학성적 점수가 공백을 사이에 두고 입력됩니다. 수학성적 점수는 100점
	만점 기준으로 입력됩니다.

	▣ 출력설명
	3등을 한 점수를 출력합니다.
*/

int main()
{
	int input = 0;
	cin >> input;
	
	vector<int> v;
	v.resize(input);
	for (int i = 0; i < input; ++i)
		cin >> v[i];

	int idx = 0;
	int startIdx = 1;

	int min = INT_MAX;
	int min_idx = 0;

	while (true)
	{
		min = INT_MAX;
		min_idx = 0;

		for (int i = startIdx; i < v.size(); ++i)
		{
			if (min >= v[i])
			{
				min = v[i];
				min_idx = i;
			}
		}

		if (v[idx] > v[min_idx])
			swap(v[idx], v[min_idx]);

		++idx;
		++startIdx;
		if (idx == v.size() - 1)
			break;

	}

	int cnt = 0;
	int result = INT_MAX;
	for (auto iter_rbegin = v.rbegin(); iter_rbegin != v.rend(); ++iter_rbegin)
	{
		if (result > *iter_rbegin)
		{
			result = *iter_rbegin;
			++cnt;
		}
		
		if (cnt == 3)
		{
			cout << *iter_rbegin;
			return 0;
		}
	}

	return 0;
}