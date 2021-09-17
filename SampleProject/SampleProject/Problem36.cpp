#include <iostream>
#include <vector>

using namespace std;

/*
	36. ��������
	N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
	�����ϴ� ����� ���������Դϴ�.
	
	�� �Է¼���
	 ù ��° �ٿ� �ڿ��� N(1 <= N <= 100)�� �־����ϴ�.
	�� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�.�� �ڿ����� ������ ���� �ȿ� �ֽ��ϴ�.
	
	�� ��¼���
	 ������������ ���ĵ� ������ ����մϴ�.
*/

//void InsertSort(vector<int>& v, const int& num)
//{
//	if (v.empty())
//		v.emplace_back(num);
//	else if (v.size() == 1)
//	{
//		if (v[0] < num)
//			v.emplace_back(num);
//		else
//			v.insert(v.begin(), num);
//	}
//	else
//	{
//		for (auto iter_begin = v.begin(); iter_begin != --(v.end()); ++iter_begin)
//		{
//			int src = (*iter_begin);
//			int dst = *(iter_begin + 1);
//
//			if (src >= num)
//			{
//				v.insert(iter_begin, num);
//				break;
//			}
//			else if (src <= num && dst >= num)
//			{
//				v.insert(iter_begin + 1, num);
//				break;
//			}
//			else if (iter_begin + 1 == --(v.end()))
//			{
//				v.emplace_back(num);
//				break;
//			}
//		}
//	}
//}

void InsertSort(vector<int>& v)
{
	for (int i = 1; i < v.size(); ++i)
	{
		int temp = v[i];
		int j = i - 1;

		for (; j >= 0; --j)
		{
			if (v[j] > temp)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = temp;
	}
}

int main()
{
	int size = 0;
	cin >> size;

	vector<int> v;
	v.reserve(size);

	for (int i = 0; i < size; ++i)
	{
		int num;
		cin >> num;
		// InsertSort(v, num);
		v.emplace_back(num);
	}

	InsertSort(v);

	for (auto& n : v)
		cout << n << " ";

	return 0;
}