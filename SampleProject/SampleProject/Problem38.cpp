#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
	38. Inversion Sequence

	 1���� n������ ���� �� ������ ����Ͽ� �̷���� ������ ���� ��, 
	 1���� n���� ������ �� �տ� ���� �ִ� �ڽź��� ū ������ ������ ������ ǥ���� ���� Inversion Sequence�� �Ѵ�.
	���� ��� ������ ���� ������ ���
	4 8 6 2 5 1 3 7
	1�տ� ���� 1���� ū ���� 4, 8, 6, 2, 5. �̷��� 5���̰�,
	2�տ� ���� 2���� ū ���� 4, 8, 6. �̷��� 3��,
	3�տ� ���� 3���� ū ���� 4, 8, 6, 5 �̷��� 4��......
	���� 4 8 6 2 5 1 3 7�� inversion sequence�� 5 3 4 0 2 1 1 0 �� �ȴ�.
	n�� 1���� n������ ���� ����Ͽ� �̷���� ������ inversion sequence�� �־����� ��, ������ ������ ����ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	 ù ��° �ٿ� �ڿ��� N(3<=N<100)�� �־�����, �� ��° �ٿ��� inversion sequence�� ����
	���̿� �� ĭ�� ������ �ΰ� �־�����.

	�� ��¼���
	 ������������ ���ĵ� ������ ����մϴ�.
*/

void findPlace(list<int>& lst, const int& num ,const int& input)
{
	if (lst.empty())
		lst.emplace_back(num);
	else
	{
		int cnt = 0;
		auto iter_begin = lst.begin();
		auto iter_end = lst.end();

		if (input == 0)
			lst.emplace_front(num);
		else
		{
			for (; iter_begin != iter_end; ++iter_begin)
			{
				if (*iter_begin > num)
					++cnt;

				if (cnt == input)
				{
					++iter_begin;
					lst.insert(iter_begin, num);
					break;
				}
			}
		}

	}
}

int main()
{
	int size = 0;
	cin >> size;
	
	list<int> lst;

	vector<int> v;
	v.resize(size);

	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];


	for (int i = size - 1; i >= 0; --i)
		findPlace(lst, i + 1, v[i]);

	for (auto& n : lst)
		cout << n << " ";

	return 0;
}