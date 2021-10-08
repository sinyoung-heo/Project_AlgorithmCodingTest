#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace chrono;

const int MAX_SIZE = 100'000;
const int FIND_SIZE = 1'000;

int main()
{
	// 정규분포를 갖는 정수 생성.
	// 이론적으로는 -infinite ~ +infinite의 범위.
	// 데이터는 -5 ~ +5에 몰려있다.
	normal_distribution<> nd{ 0.0, 1.0 };
	default_random_engine dre{ random_device()() };


	vector<int> v;
	v.reserve(MAX_SIZE);
	for (int i = 1; i <= MAX_SIZE; ++i)
		v.emplace_back(i);


	// 10'000'000개의 벡터에서 원하는 값을 찾는데 걸리는 시간을 재본다.
	// 찾으려는 값을 arrFind[FIND_SIZE]에 저장한다.
	uniform_int_distribution<> uid{ 0, MAX_SIZE - 1 };

	int arrFind[FIND_SIZE];
	for (int i = 0; i < FIND_SIZE; ++i)
	{
		arrFind[i] = v[uid(dre)];
	}


	// vector
	for (int i = 0; i < 5; ++i)
	{
		auto start = steady_clock::now();

		for (auto& n : arrFind)
			auto p = find(v.begin(), v.end(), n);	// 탐색.

		cout << i << "회차 vector에서 경과시간 : " << duration_cast<milliseconds>(steady_clock::now() - start).count() << "ms" << endl;
	}

	cout << "-----------" << endl;

	list<int> l;
	for (int i = 1; i <= MAX_SIZE; ++i)
		l.emplace_back(i);

	for (int i = 0; i < 5; ++i)
	{
		auto start = steady_clock::now();

		for (auto& n : arrFind)
			auto p = find(l.begin(), l.end(), n);	// 탐색.

		cout << i << "회차 list에서 경과시간 : " << duration_cast<milliseconds>(steady_clock::now() - start).count() << "ms" << endl;

	}
	cout << "-----------" << endl;
	l.clear();

	set<int> s;
	for (int i = 1; i <= MAX_SIZE; ++i)
		s.emplace(i);

	for (int i = 0; i < 5; ++i)
	{
		auto start = steady_clock::now();

		for (auto& n : arrFind)
			auto iter_find = s.find(n);

		// auto p = find(s.begin(), s.end(), findNum);	// 탐색.

		cout << i << "회차 set에서 경과시간 : " << duration_cast<milliseconds>(steady_clock::now() - start).count() << "ms" << endl;

	}
}


int main()
{


	return 0;
}