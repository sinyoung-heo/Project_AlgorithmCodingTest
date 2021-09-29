#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

/*
	52. Ugly Numbers (투 포인트 알고리즘 응용)

	어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly Number라고 부릅니다. 
	Ugly Number를 차례대로 적어보면 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다. 
	숫자 1은 Ugly Number의 첫 번째 수로 합니다. 
	자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는 프로그램을 작성하세요.

	▣ 입력설명
	첫 줄에 자연수 N(3<=N<=1500)이 주어집니다.

	▣ 출력설명
	첫 줄에 N번째 Ugly Number를 출력하세요.

	▣ 입력예제 1
	10
	▣ 출력예제 1
	12

	▣ 입력예제 2
	1500
	▣ 출력예제 2
	859963392
*/

vector<int> v{ 1 };
int n;
int answer;

int idxP2;
int idxP3;
int idxP5;

int findMin(const int& a, const int& b, const int& c)
{
	int min = 0;
	
	if (a < b) min = a;
	else min = b;

	if (min > c)
		min = c;

	return min;
}

int main()
{
	cin >> n;

	int r2 = 0, r3 = 0, r5 = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		r2 = v[idxP2] * 2;
		r3 = v[idxP3] * 3;
		r5 = v[idxP5] * 5;

		int ug = findMin(r2, r3, r5);
		v.emplace_back(ug);

		// index 증가.
		if (ug == r2)
			++idxP2;
		if (ug == r3)
			++idxP3;
		if (ug == r5)
			++idxP5;
	}

	cout << v.back() << endl;
}