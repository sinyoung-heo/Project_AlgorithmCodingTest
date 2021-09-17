#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//int temp = 0;

	//set<int> s1;
	//set<int> answer;

	//int size_s1 = 0, size_s2 = 0;
	//
	//cin >> size_s1;
	//for (int i = 0; i < size_s1; ++i)
	//{
	//	cin >> temp;
	//	s1.emplace(temp);
	//}

	//cin >> size_s2;
	//for (int i = 0; i < size_s2; ++i)
	//{
	//	cin >> temp;
	//	auto iter_find = s1.find(temp);
	//	if (iter_find == s1.end())
	//		s1.emplace(temp);
	//	else
	//		answer.emplace(temp);
	//}

	//for (auto& n : answer)
	//	cout << n << " ";




	vector<int> v1;
	vector<int> v2;
	vector<int> answer;

	int size_v1 = 0, size_v2 = 0;

	cin >> size_v1;
	v1.resize(size_v1);
	for (int i = 0; i < size_v1; ++i)
		cin >> v1[i];

	cin >> size_v2;
	v2.resize(size_v2);
	for (int i = 0; i < size_v2; ++i)
		cin >> v2[i];

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	auto iter_begin_v1 = v1.begin();
	auto iter_begin_v2 = v2.begin();
	while (true)
	{
		if (iter_begin_v1 == v1.end() || iter_begin_v2 == v2.end())
			break;

		if (*iter_begin_v1 == *iter_begin_v2)
		{
			answer.emplace_back(*iter_begin_v1);
			++iter_begin_v1;
			++iter_begin_v2;
			continue;
		}

		else if (*iter_begin_v1 < *iter_begin_v2)
		{
			++iter_begin_v1;
			continue;
		}
		else if (*iter_begin_v1 > *iter_begin_v2)
		{
			++iter_begin_v2;
			continue;
		}
	}

	for (auto& n : answer)
		cout << n << " ";

	return 0;
}