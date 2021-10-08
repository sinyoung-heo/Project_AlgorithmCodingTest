#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;

    // 장르별 PlayCnt를 우선순위 큐에 저장.
    map<string, priority_queue<pair<int, int>>> mappqGenresPlays;

    // 장르별 재생 횟수 누적.
    map<string, int> mapGenresPlayCnt;

    // 1. 많이 재생된 장르 순서 찾기.
    for (int i = 0; i < plays.size(); ++i)
    {
        mapGenresPlayCnt[genres[i]] += plays[i];
        mappqGenresPlays[genres[i]].emplace(plays[i], i);
    }

    vector<pair<string, int>> vecGenresPlayCnt{ mapGenresPlayCnt.begin(), mapGenresPlayCnt.end() };
    sort(vecGenresPlayCnt.begin(), vecGenresPlayCnt.end(), [](const pair<string, int>& a, const pair<string, int>& b)
        {
            return a.second > b.second;
        });


    // 2. 장르별 재생 횟수 인덱스 찾기.
    for (int i = 0; i < vecGenresPlayCnt.size(); ++i)
    {
        string genres_tag = vecGenresPlayCnt[i].first;

        if (mappqGenresPlays[genres_tag].empty()) continue;
        if (mappqGenresPlays[genres_tag].size() > 1)
        {
            auto p1 = mappqGenresPlays[genres_tag].top();
            mappqGenresPlays[genres_tag].pop();

            auto p2 = mappqGenresPlays[genres_tag].top();
            mappqGenresPlays[genres_tag].pop();

            if (p1.first == p2.first)
            {
                answer.emplace_back(p2.second);
                answer.emplace_back(p1.second);
            }
            else
            {
                answer.emplace_back(p1.second);
                answer.emplace_back(p2.second);
            }
        }
        else if (mappqGenresPlays[genres_tag].size() == 1)
        {
            auto p1 = mappqGenresPlays[genres_tag].top();
            mappqGenresPlays[genres_tag].pop();

            answer.emplace_back(p1.second);
        }
    }

    return answer;
}

int main()
{

    return 0;
}