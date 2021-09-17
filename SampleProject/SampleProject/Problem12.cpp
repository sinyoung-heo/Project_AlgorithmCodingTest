#include <iostream>

using namespace std;

/*
	11. 숫자의 총 개수(large)

	 자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
	예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
	총 21개가 쓰였음을 알 수 있습니다.
	자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작성하세요.

	▣ 입력설명
	 첫 번째 줄에는 자연수 N(3<=N<100,000,000)이 주어진다.

	▣ 출력설명
	 첫 번째 줄에 숫자의 총개수를 출력한다.
*/


int countDigit(int input)
{
	int cnt = 0;

	while (true)
	{
		input /= 10;
		++cnt;

		if (input == 0)
			break;
	}

	return cnt;
}

int main()
{
	// 1 ~ 9
	// 10 ~ 99
	// 100 ~ 999
	// 1 * 9
	// 2 * 90
	// 3 * 900

	int input = 0;
	cin >> input;

	int cnt = 0;
	int input_cnt = countDigit(input);

	for (int i = 1; i < input_cnt; ++i)
	{
		cnt += i * (pow(10, i) - pow(10, i - 1));
	}

	cnt += input_cnt * (input - pow(10, input_cnt - 1) + 1);

	cout << cnt;

	return 0;
}