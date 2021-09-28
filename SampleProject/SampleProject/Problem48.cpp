#include <iostream>
#include <vector>

using namespace std;

/*
	48. �� ���� ��հ� ���� ����� ��

	<�׸� 1>�� ���� 9 �� 9 �����ǿ� ������ 81���� �ڿ����� �־��� ��, �� ���� ����� ���ϰ�,
	�� ��հ� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. 
	����� �Ҽ��� ù ° �ڸ����� �ݿø��մϴ�. ��հ� ����� ���� �� ���̸� �� �� ū ���� ����ϼ���.

	�� �Է¼���
	ù ° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� ��ȩ ���� �ڿ����� �־�����. �־����� �ڿ����� 100���� �۴�.

	�� ��¼���
	ù° �ٿ� ù ��° �ٺ��� �� �ٿ� ������ ��հ� �� �࿡�� ��հ� ���� ����� ���� ����Ѵ�.

	�� �Է¿���
	3 23 85 34 17 74 25 52 65
	10 7 39 42 88 52 14 72 63
	87 42 18 78 53 45 18 84 53
	34 28 64 85 12 16 75 36 55
	21 77 45 35 28 75 90 76 1
	25 87 65 15 28 11 37 28 74
	65 27 75 41 7 89 78 64 39
	47 47 70 45 23 65 3 41 44
	87 13 82 38 50 12 48 29 80

	�� ��¿���
	42 34
	43 42
	53 53
	45 36
	50 45
	41 37
	54 64
	43 44
	49 50
*/

int main()
{
	vector<vector<int>> v;

	v.resize(9);
	for (auto& vec : v)
		vec.resize(9);

	for (auto& vec : v)
	{
		for (auto& num : vec)
			cin >> num;
	}

	vector<int> vecAvg;
	vecAvg.resize(9);

	// Calc Avg
	for (int i = 0; i < v.size(); ++i)
	{
		int sum = 0;

		for (auto& num : v[i])
			sum += num;

		vecAvg[i] =(int)(floor((double)sum / (double)v[i].size() + 0.5));
	}

	int min = INT_MAX;
	int out = INT_MIN;

	for (int i = 0; i < v.size(); ++i)
	{
		min = INT_MAX;
		out = INT_MIN;

		for (auto& num : v[i])
		{
			int result = abs(vecAvg[i] - num);

			if (result < min)
			{
				min = result;
				out = num;
			}
			if (result == min)
			{
				if (out < num)
					out = num;
			}
		}

		cout << vecAvg[i] << " " << out << endl;
	}
}