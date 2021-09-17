#include <iostream>
#include <vector>

using namespace std;

/*
	10. 자릿수의 합
	 N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력 하는 프로그램을 작성하세요. 
	각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를 꼭 작성해서 프로그래밍 하세요.

	▣ 입력설명
	 첫 줄에 자연수의 개수 N(3<=N<=100)이 주어지고, 그 다음 줄에 N개의 자연수가 주어진다.
	각 자연수의 크기는 10,000,000를 넘지 않는다.

	▣ 출력설명
	 자릿수의 합이 최대인 자연수를 출력한다. 자리수의 합이 최대인 자연수가 여러개인 경우 그
	중 값이 가장 큰 값을 출력합니다.
*/

int digit_sum(int x)
{
	int sum = 0;

	while (true)
	{
		sum += x % 10;
		x /= 10;

		if (x == 0)
		{
			sum += x % 10;
			break;
		}
	}

	return sum;
}

int main()
{
	int num = 0;
	cin >> num;

	vector<int> vecInput;
	vecInput.resize(num);

	for (int i = 0; i < num; ++i)
		cin >> vecInput[i];

	int result = 0;
	int sum = 0;
	for (int i = 0; i < vecInput.size(); ++i)
	{
		if (sum <= digit_sum(vecInput[i]))
		{
			if (sum == digit_sum(vecInput[i]))
			{
				if (result < vecInput[i])
				{
					sum = digit_sum(vecInput[i]);
					result = vecInput[i];
					continue;
				}
				else
				{
					sum = digit_sum(vecInput[i]);
					continue;
				}
			}

			sum = digit_sum(vecInput[i]);
			result = vecInput[i];
		}
	}

	cout << result << endl;

	return 0;
}