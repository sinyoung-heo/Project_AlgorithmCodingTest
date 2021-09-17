#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

//long countMoves(vector<int> numbers) {
//	long count = 0;
//
//	map<int, int> m;
//	for (auto& n : numbers)
//		++m[n];
//
//	while (true)
//	{
//		if (m.size() == 1)
//			break;
//
//		auto iterB = --(m.end());
//		auto iterBB = (iterB - 1);
//
//		count += (iterB->first - iterBB->first) * iterB->second;
//		iterBB->second += iterB->second;
//
//		m.erase(iterB);
//	}
//
//	return count;
//}

//int cnt = 0;

//int getMinimumMoves(vector<int> arr) {
//    while (true)
//    {
//        if (arr.begin() == max_element(arr.begin(), arr.end()))
//            break;
//
//        auto iter_max = max_element(arr.begin(), arr.end());
//        if (iter_max != (--arr.end()))
//            ++cnt;
//
//        for (auto iter_begin = iter_max; iter_begin != arr.end(); ++iter_begin)
//            arr.erase(iter_max);
//    }
//
//    return cnt;
//}

int main()
{
	// cout << countMoves(vector<int>{5, 6, 8,8,5}) << endl;

	list<int> v{ 1, 3, 5 };

	auto iter_begin = v.begin();
	++iter_begin;

	v.insert(iter_begin, 2);

	for (auto& n : v)
		cout << n << " ";



	return 0;
}