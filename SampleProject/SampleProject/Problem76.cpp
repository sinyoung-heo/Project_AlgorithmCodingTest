#include <iostream>
#include <vector>

using namespace std;

/*
	76. 이항계수(메모이제이션)
	이항계수는 N개의 원소를 가지는 집합에서 R개의 원소를 뽑아 부분집합을 만드는 경우의 수 를 의미한다. 
	공식은 nCr 로 표현된다.
	N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.

	▣ 입력설명
	첫 번째 줄에 자연수 N(1<=N<=20)과 R(0<=R<=20)이 주어진다. 단 (N>=R)

	▣ 출력설명
	첫 번째 줄에 이항계수 값을 출력한다.

	▣ 입력예제 1
	5 3

	▣ 출력예제 1
	10

	nPr = n! / (n-r)!
	nCr = nPr / r!
*/

int n, r;

vector<int> v;

void fac(int n)
{
	if (n == 1)
		return;

	fac(n - 1);
	v[n - 1] = n * v[n - 2];
}


int main()
{
	cin >> n >> r;

	v.resize(n);
	v[0] = 1;

	fac(n);

	int nPr = v[n - 1] / v[n - r - 1];
	int nCr = nPr / v[r - 1];

	cout << nCr << endl;
}