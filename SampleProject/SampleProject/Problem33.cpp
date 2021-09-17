#include <iostream>
#include <vector>

using namespace std;

/*
	33. 3���� ������?
	 N���� ���м����� �־����� �� �� 3���� �� ���м����� ����ϴ� ���α׷��� �ۼ��ϼ���.
	���� �л��� ������ 100���� 3��, 99���� 2��, 98���� 5��, 97���� 3�� �̷������� 
	������ �����Ǹ� 1���� 3���̸�, 2���� 2���̸� 3���� 5���� �Ǿ� 98���� 3���� �� ������ �˴ϴ�.

	�� �Է¼���
	 ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
	�� ��° �ٿ� N���� ���м��� ������ ������ ���̿� �ΰ� �Էµ˴ϴ�. ���м��� ������ 100��
	���� �������� �Էµ˴ϴ�.

	�� ��¼���
	3���� �� ������ ����մϴ�.
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