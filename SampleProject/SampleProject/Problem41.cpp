#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
	41. ���ӵ� �ڿ����� ��
	 �Է����� ���� ���� N�� �ԷµǸ� 2�� �̻��� ���ӵ� �ڿ����� ������ ���� N�� ǥ���ϴ� ����� �������� ����ϴ� ���α׷��� �ۼ��ϼ���.
	���� N=15�̸�
	7+8=15
	4+5+6=15
	1+2+3+4+5=15
	�� ���� �� 3������ ��찡 �����Ѵ�.

	�� �Է¼���
	 ù ��° �ٿ� ���� ���� N(7<=N<1000)�� �־�����.

	�� ��¼���
	 ù�ٺ��� ������ ����� ���� ����Ѵ�.
	�� ������ �ٿ� �� ������ ����Ѵ�.
*/

int answer = 0;
int num = 0;

void fuc(int input)
{
	if (input <= 0)
		return;

	vector<int> v;
	int sum = 0;
	int src = input;

	while (true)
	{
		sum += src;
		v.emplace_back(src);

		if (sum > num)
			break;
		else if (sum == num)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				if (i != v.size() - 1)
					cout << v[i] << " + ";
				else
					cout << v[i] << " = " << sum << endl;
			}

			++answer;
			break;
		}

		++src;
	}

	fuc(input - 1);
}

void fuc2(int num)
{
	vector<int> v;
	int sum = 0;
	int origin = 0;

	for (int i = num / 2 + 1; i > 0; --i)
	{
		v.clear();
		sum = 0;
		origin = i;

		while (true)
		{
			sum += origin;
			v.emplace_back(origin);

			if (sum > num)
				break;
			else if (sum == num)
			{
				for (int i = 0; i < v.size(); ++i)
				{
					if (i != v.size() - 1)
						cout << v[i] << " + ";
					else
						cout << v[i] << " = " << sum << endl;
				}

				++answer;
				break;
			}

			++origin;
		}
	}
}

void fuc3(int num)
{
	vector<int> v;

	int sum = 0;
	int result = 0;

	for (int i = 2; i < num / 2 + 1; ++i)
	{
		sum = 0;
		v.clear();

		for (int j = 1; j <= i; ++j)
		{
			sum += j;
			v.emplace_back(j);
		}
		
		if (sum > num)
			continue;

		result = (num - sum) % i;

		if (result != 0)
			continue;
		else
		{
			for (int k = 0; k < v.size(); ++k)
			{
				v[k] += (num - sum) / i;

				if (k != v.size() - 1)
					cout << v[k] << " + ";
				else
					cout << v[k] << " = " << num << endl;
			}

			++answer;
		}
	}
}

int main()
{
	cin >> num;

	//fuc(num / 2 + 1);
	//fuc2(num);


	fuc3(num);
	cout << answer << endl;

	return 0;
}