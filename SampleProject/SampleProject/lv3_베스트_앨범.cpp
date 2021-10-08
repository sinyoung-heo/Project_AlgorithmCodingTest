#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;

    // �帣�� PlayCnt�� �켱���� ť�� ����.
    map<string, priority_queue<pair<int, int>>> mappqGenresPlays;

    // �帣�� ��� Ƚ�� ����.
    map<string, int> mapGenresPlayCnt;

    // 1. ���� ����� �帣 ���� ã��.
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


    // 2. �帣�� ��� Ƚ�� �ε��� ã��.
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