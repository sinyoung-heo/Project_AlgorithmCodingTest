#include <iostream>
#include <vector>

using namespace std;

/*
	18. 층간소음 (*)

	  T편한 세상 아파트는 층간소음 발생 시 윗집의 발뺌을 방지하기 위해 애초 아파트를 지을 때 바닥에 진동센서를 설치했습니다. 
	 이 센서는 각 세대의 층간 진동소음 측정치를 초단위로 아파트 관리실에 실시간으로 전송합니다. 
	 그리고 한 세대의 측정치가 M값을 넘으면 세대호수와 작은 경보음이 관리실 모니터에서 울립니다. 
	 한 세대의 N초 동안의 실시간 측정치가 주어지면 최대 연속으로 경보음이 울린 시간을 구하세요. 
	 경보음이 없으면 -1를 출력합니다.

	▣ 입력설명
	 첫 줄에 자연수 N(10<=N<=100)과 M이 주어집니다.
	두 번째 줄에 N개의 측정값(1000이하 자연수)이 초 순서대로 입력된다.

	▣ 출력설명
	 최대 연속 경보음이 울린 시간(초)를 출력하세요.
*/

int main()
{
	int N, M = 0;
	cin >> N >> M;

	vector<int> vecPower;
	vecPower.resize(N);

	int length = 0;
	int max = INT_MIN;

	for (int i = 0; i < N; ++i)
	{
		cin >> vecPower[i];

		if (vecPower[i] > M)
		{
			++length;

			if (max < length)
				max = length;
		}
		else
			length = 0;
	}

	if (max == 0)
		cout << -1 << endl;
	else
		cout << max << endl;




	//for (int i = 0; i < vecPower.size(); ++i)
	//{
	//	if (vecPower[i] > M)
	//	{
	//		++length;

	//		if (max < length)
	//			max = length;
	//	}
	//	else
	//		length = 0;
	//}

	//cout << max << endl;





	//for (int i = 0; i < vecPower.size(); ++i)
	//{
	//	if (vecPower[i] > M)
	//	{
	//		++length;
	//		if (max < length)
	//			max = length;

	//		if (i + 1 < vecPower.size())
	//		{
	//			if (vecPower[i + 1] > M)
	//			{
	//				++length;
	//				++i;
	//				if (max < length)
	//					max = length;

	//				continue;
	//			}
	//			else
	//			{
	//				length = 0;
	//				continue;
	//			}
	//		}
	//	}
	//	else
	//		length = 0;

	//}

	// cout << max << endl;

	return 0;
}