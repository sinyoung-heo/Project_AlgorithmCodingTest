#include <iostream>
#include <vector>

using namespace std;

/*
	 문자와 숫자가 섞여있는 문자열이 주어지면 그 중 숫자만 추출하여 그 순서대로 자연수를 만듭니다. 
	만들어진 자연수와 그 자연수의 약수 개수를 출력합니다.
	만약 “t0e0a1c2her”에서 숫자만 추출하면 0, 0, 1, 2이고 이것을 자연수를 만들면 12가 됩니다. 
	즉 첫 자리 0은 자연수화 할 때 무시합니다. 출력은 12를 출력하고, 다음 줄에 12의 약수의 개수를 출력하면 됩니다.
	추출하여 만들어지는 자연수는 100,000,000을 넘지 않습니다.

	▣ 입력설명
	 첫 줄에 숫자가 썩인 문자열이 주어집니다. 문자열의 길이는 50을 넘지 않습니다.

	▣ 출력설명
	 첫 줄에 자연수를 출력하고, 두 번째 줄에 약수의 개수를 출력합니다.
*/

int main()
{
	char input[64];
	cin >> input;

	vector<char> vecNumber;

	for (int i = 0; i < strlen(input); ++i)
	{
		if (!isalpha(input[i]))
			vecNumber.emplace_back(input[i]);
	}

	int sum = 0;
	int j = 0;
	for (int i = vecNumber.size() - 1; i >= 0; --i, ++j)
	{
		int num = vecNumber[i] - 48;
		sum += num * (int)pow(10.0, (double)j);
	}

	int cnt = 0;
	for (int i = 1; i <= sum; ++i)
	{
		if (sum % i == 0)
			++cnt;
	}

	cout << sum << endl;
	cout << cnt << endl;

	return 0;
}