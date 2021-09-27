#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	46. ��Ƽ�½�ŷ(īī�� �Թ� ���� ����)
	������ ��ǻ�ʹ� ��Ƽ�½�ŷ�� �����ϴ�. 
	ó���ؾ� �� �۾��� N�� ������ ������ ��ǻ�ʹ� �۾��� 1���� N������ ��ȣ�� �ο��ϰ� ó���� ������ ���� �Ѵ�.

	1) ��ǻ�ʹ� 1�� �۾����� ������� 1�ʾ� �۾��� �Ѵ�. �� �� �۾��� 1�ʸ� �۾��ϰ� ���� �۾��� �ϴ� ���̴�.
	2) ������ ��ȣ�� �۾��� 1�� ������ �ٽ� 1�� �۾����� ���� �ٽ� 1�ʾ� �ļ� ó���� �Ѵ�.
	3) ó���� ���� �۾��� �۾� �����쿡�� ������� ���ο� �۾��� ������ �ʴ´�.

	�׷��� ������ ��ǻ�Ͱ� ���� ������ �� K�� �Ŀ� ������ �Ǿ� ��ǻ�Ͱ� �Ͻ������� ���߾���. 
	���Ⱑ ������ ���� ������ ��ǻ�Ͱ� �� �� �۾����� �ٽ� �����ؾ� �ϴ��� �˾Ƴ��� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù ��° �ٿ� �۾��� ���� N(1<=N<=2,000)�� �־����� �� ���� N�ٿ� ���� �� �۾��� ó���ϴµ� �ɸ��� �ð��� �ʴ����� �־�����. 
	�� �۾��� ó���ϴµ� �ʿ��� �ð��� 1,000�� ���� �ʴ´�.
	������ �ٿ� ������ �߻��� �ð� K(1<=K<=2,000,000)�� �־�����.

	�� ��¼���
	 ù ��° �ٿ� �� �� �۾����� �ٽ� �����ؾ� �ϴ��� �۾� ��ȣ�� ����Ѵ�.
	���� �� �̻� ó���� �۾��� ���ٸ� -1�� ����Ѵ�.

	3
	1
	2
	3
	5
	------
	3
	<����� ����>
	- 0~1�� ���� 1�� �۾��� ó���Ѵ�.	���� �ð��� [0, 2, 3] �̴�.
	- 1~2�� ���� 2�� �۾��� ó���Ѵ�.	���� �ð��� [0, 1, 3] �̴�.
	- 2~3�� ���� 3�� �۾��� ó���Ѵ�.	���� �ð��� [0, 1, 2] �̴�.
*/

int n, k;

int main()
{
	cin >> n;

	vector<pair<int, int>> vecWork;
	vecWork.reserve(n);
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		int time = 0;
		cin >> time;

		vecWork.emplace_back(i + 1, time);
		sum += time;
	}

	cin >> k;


	if (sum <= k)
	{
		cout << -1 << endl;
		return 0;
	}

	sort(vecWork.begin(), vecWork.end(), [](const pair<int, int>& v1, const pair<int, int>& v2)
		{
			return v1.second < v2.second;
		});

	int workTime = 0;
	while (workTime + vecWork.front().second * vecWork.size() < k)
	{
		workTime += vecWork.front().second * vecWork.size();

		for (auto iter = vecWork.begin() + 1; iter != vecWork.end();)
		{
			iter->second -= vecWork.front().second;

			if (iter->second == 0)
				iter = vecWork.erase(iter);
			else
				++iter;
		}

		vecWork.erase(vecWork.begin());

		if (vecWork.size() == 1)
		{
			cout << vecWork[0].second << endl;
			return 0;
		}
	}


	sort(vecWork.begin(), vecWork.end(), [](const pair<int, int>& v1, const pair<int, int>& v2)
		{
			return v1.first < v2.first;
		});

	int answer = 0;
	while (workTime != k)
	{
		for (auto iter_begin = vecWork.begin(); iter_begin != vecWork.end();)
		{
			--(iter_begin->second);

			if (iter_begin->second == 0)
				iter_begin = vecWork.erase(iter_begin);
			else
				++iter_begin;

			if (iter_begin != vecWork.end())
				answer = iter_begin->first;

			++workTime;
			if (workTime == k)
			{
				cout << answer << endl;
				return 0;
			}
		}
	}

	return 0;
}
