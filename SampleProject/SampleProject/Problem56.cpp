#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

/*
	56. 재귀함수 분석

	 자연수 N이 주어지면 아래와 같이 출력하는 프로그램을 작성하세요. 재귀함수를 이용해서 출력해야 합니다.

	▣ 입력설명
	 첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.

	▣ 출력설명
	 첫 번째 줄에 재귀함수를 이용해서 출력하세요.
*/

void fuc(int n)
{
	if (n <= 0)
		return;

	cout << n << " ";
	fuc(--n);
}

int main()
{
	int input = 0;
	cin >> input;

	fuc(input);

	return 0;
}