#include <iostream>
#include <vector>

using namespace std;

/*
	9. 모두의 약수(*)
	1초안에!!

	 자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램을 작성하세요. 
	만약 N이 8이 입력된다면 1(1개), 2(2개), 3(2개), 4(3개), 5(2개), 6(4개), 7(2개), 8(4개) 와 같이 
	각 숫자의 약수의 개수가 구해집니다.
	출력은 다음과 같이 1부터 차례대로 약수의 개수만 출력하면 됩니다.
	1 2 2 3 2 4 2 4 와 같이 출력한다.

	▣ 입력설명
	 첫 번째 줄에 자연수 N(5<=N<=50,000)가 주어진다.

	▣ 출력설명
	 첫 번째 줄에 1부터 N까지 약수의 개수를 순서대로 출력한다.
*/

int main()
{
	int input = 0;
	cin >> input;

	vector<int> vecCnt;
	vecCnt.resize(input);
	for (auto& cnt : vecCnt)
		cnt = 0;

	for (int i = 1; i <= input; ++i)
	{
		// "배수는 약수이다."를 활용하여 시간복잡도를 줄이자!
		for (int j = i; j <= input; j += i)
		{
			++vecCnt[j - 1];
		}
	}

	for (auto& cnt : vecCnt)
		cout << cnt << " ";

	return 0;
}