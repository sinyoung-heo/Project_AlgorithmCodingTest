#include <iostream>
#include <vector>

using namespace std;

/*
	61. 특정 수 만들기(DFS : MS 인터뷰)

	N개의 원소로 구성된 자연수 집합이 주어지면, 집합의 원소와 ‘+’, ‘-’ 연산을 사용하여 특정
	수인 M을 만드는 경우가 몇 가지 있는지 출력하는 프로그램을 작성하세요. 
	각 원소는 연산에 한 번만 사용합니다.
	예를 들어 {2, 4, 6, 8}이 입력되고, M=12이면
	2+4+6=12
	4+8=12
	6+8-2=12
	2-4+6+8=12
	로 총 4가지의 경우가 있습니다. 만들어지는 경우가 존재하지 않으면 -1를 출력한다.

	▣ 입력설명
	첫 번째 줄에 자연수 N(1<=N<=10)와 M(1<=M<=100) 주어집니다.
	두 번째 줄에 집합의 원소 N개가 주어진다. 각 원소는 중복되지 않는다.

	▣ 출력설명
	첫 번째 줄에 “YES" 또는 ”NO"를 출력한다.

	▣ 입력예제 1
	4 12
	2 4 6 8

	▣ 출력예제 1
	4
*/

int answer;

int N;
int M;
vector<int> v;

void findAnswer(const int& idx, const int& num)
{
	if (idx > v.size() - 1)
		return;

	// +
	int localSum1 = num;
	localSum1 += v[idx];
	if (localSum1 == M)
		++answer;

	findAnswer(idx + 1, localSum1);

	// -
	int localSum2 = num;
	localSum2 += (v[idx] * -1);
	if (localSum2 == M)
		++answer;

	findAnswer(idx + 1, localSum2);

	// 0
	 int localSum3 = num;
	//if (localSum3 == M)
	//	++answer;
	findAnswer(idx + 1, localSum3);
}

int main()
{
	cin >> N >> M;
	
	v.resize(N);
	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	findAnswer(0, 0);

	if (answer != 0)
		cout << answer << endl;
	else
		cout << -1 << endl;
}