#include <iostream>
#include <vector>

using namespace std;

/*
	36. 삽입정렬
	N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
	정렬하는 방법은 삽입정렬입니다.
	
	▣ 입력설명
	 첫 번째 줄에 자연수 N(1 <= N <= 100)이 주어집니다.
	두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다.각 자연수는 정수형 범위 안에 있습니다.
	
	▣ 출력설명
	 오름차순으로 정렬된 수열을 출력합니다.
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