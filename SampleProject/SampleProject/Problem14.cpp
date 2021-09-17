#include <iostream>
#include <vector>

using namespace std;

/*
	14. 뒤집은 소수

	 N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는 프로그램을 작성하세요. 
	예를 들어 32를 뒤집으면 23이고, 23은 소수이다. 그러면 23을 출력한다. 
	단 910를 뒤집으면 19로 숫자화 해야 한다. 첫 자리부터의 연속된 0은 무시한다.
	뒤집는 함수인 int reverse(int x) 와 소수인지를 확인하는 함수 bool isPrime(int x)를 반드시 작성하여 프로그래밍 한다.

	▣ 입력설명
	 첫 줄에 자연수의 개수 N(3<=N<=100)이 주어지고, 그 다음 줄에 N개의 자연수가 주어진다.
	각 자연수의 크기는 100,000를 넘지 않는다.

	▣ 출력설명
	 첫 줄에 뒤집은 소수를 출력합니다. 출력순서는 입력된 순서대로 출력합니다.
*/

int reverse(int x)
{
	vector<int> vecNumber;

	while (true)
	{
		vecNumber.emplace_back(x % 10);
		x /= 10;

		if (x == 0)
			break;
	}

	int sum = 0;
	int j = 0;
	for (int i = vecNumber.size() - 1; i >= 0; --i, ++j)
		sum += vecNumber[i] * pow(10, j);

	return sum;
}

bool isPrime(int x)
{
	int cnt = 0;

	for (int i = 1; i <= x; ++i)
	{
		if (x % i == 0)
			++cnt;

		if (cnt > 2)
			return false;
	}

	if (cnt == 1)
		return false;

	return true;
}

int main()
{
	int input = 0;
	cin >> input;

	vector<int> vecNumber;
	vecNumber.resize(input);

	for (int i = 0; i < input; ++i)
		cin >> vecNumber[i];
	
	for (auto& number : vecNumber)
	{
		int revValue = reverse(number);

		if (isPrime(revValue))
			cout << revValue << " ";
	}



	return 0;
}