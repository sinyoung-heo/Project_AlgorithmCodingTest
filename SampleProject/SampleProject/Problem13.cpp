#include <iostream>
#include <map>

using namespace std;

/*
	13. 가장 많이 사용된 자릿수

	 N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프로그램을 작성하세요.
	예를 들어 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니다. 
	답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요.

	▣ 입력설명
	 첫 줄에 자연수가 입력됩니다. 자연수의 길이는 100을 넘지 않습니다.

	▣ 출력설명
	 자릿수의 곱을 출력합니다.
*/


int main()
{
	string input;
	cin >> input;

	map<char, int> mapNumberCnt;
	for (int i = 0; i < 10; ++i)
		mapNumberCnt.emplace((char)(i + 48), 0);

	for (int i = 0; i < input.size(); ++i)
		++mapNumberCnt[input[i]];


	int max = -1;
	char answer = -1;
	for (auto& pair : mapNumberCnt)
	{
		if (max <= pair.second)
		{
			if (max == pair.second)
			{
				if (answer <= pair.first)
					answer = pair.first;

				continue;
			}

			answer = pair.first;
			max = pair.second;
		}
	}

	cout << answer << endl;

	return 0;
}