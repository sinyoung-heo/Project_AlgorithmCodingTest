#include <iostream>
#include <vector>

using namespace std;

/*
	19. 분노 유발자 (*)

	 오늘은 수능이 끝난 다음날로 교장선생님은 1, 2학년 재학생들에게 강당에 모여 
	어벤져스 영화를 보여준다고 하여 학생들이 강당에 모였습니다.
	강당의 좌석은 영화관처럼 계단형이 아니라 평평한 바닥에 의자만 배치하고 학생들이 앉습니다. 
	그런데 만약 앞자리에 앉은 키가 큰 학생이 앉으면 그 학생보다 앉은키가 작은 뒷자리 학생은 스크린이 보이지 않습니다. 
	한 줄에 앉은키 정보가 주어지면 뒷사람 모두의 시야를 가려 
	영화 시청이 불가능하게 하는 분노유발자가 그 줄에 몇 명이 있는지 구하는 프로그램을 작성하세요.

	▣ 입력설명
	 첫 줄에 한 줄에 앉은 학생수 N(3<=N<=100)이 주어집니다.
	두 번째 줄에 N명의 앉은 키 정보(45이상 100이하)가 앞 자리 학생부터 차례대로 주어집니다.

	▣ 출력설명
	 자신의 뒷 사람 모두를 시청방해하는 학생수를 출력합니다.
*/

int main()
{
	int N = 0;
	cin >> N;

	vector<int> vecHeight;
	vecHeight.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> vecHeight[i];

	int cnt = -1;
	int max = INT_MIN;

	for (auto iter_rbegin = vecHeight.rbegin(); iter_rbegin != vecHeight.rend(); ++iter_rbegin)
	{
		if (max < (*iter_rbegin))
		{
			++cnt;
			max = *iter_rbegin;
		}
	}

	cout << cnt << endl;



	//bool isBigger = false;
	//for (int i = 0; i < N - 1; ++i)
	//{
	//	for (int j = i + 1; j < N; ++j)
	//	{
	//		if (vecHeight[i] <= vecHeight[j])
	//		{
	//			isBigger = true;
	//			break;
	//		}
	//	}

	//	if (!isBigger)
	//		++cnt;

	//	isBigger = false;
	//}

	//cout << cnt << endl;

	return 0;
}