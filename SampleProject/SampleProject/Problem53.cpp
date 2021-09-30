#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
	10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 
	스택 자료구조를 사용하시기 바랍니다.

	▣ 입력설명
	첫 번째 줄에 10진수 N(10<=N<=1,000)과 K(2, 5, 8, 16)가 주어진다.

	▣ 출력설명
	K진수를 출력한다.

	▣ 입력예제 1
	11 2
	▣ 출력예제 1
	1011

	▣ 입력예제 2
	31 16
	▣ 출력예제 2
	1F
*/


int n, k;
stack<int> s;

int main()
{
	cin >> n >> k;

	int num = n;
	int result = 0;
	while (num != 0)
	{
		result = num % k;

		if (k != 16)
			s.push(result);
		else
		{
			switch (result)
			{
			case 10:
				result = 'A';
				break;
			case 11:
				result = 'B';
				break;
			case 12:
				result = 'C';
				break;
			case 13:
				result = 'D';
				break;
			case 14:
				result = 'E';
				break;
			case 15:
				result = 'F';
				break;
			default:
				break;
			}

			s.push(result);
		}

		num /= k;
	}

	while (!s.empty())
	{
		int n = s.top();
		if (n >= 10)
			cout << (char)n;
		else
			cout << n;

		s.pop();
	}
	cout << endl;
}