#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

//vector<long long> solution(vector<long long> numbers) {
//    vector<long long> answer;
//
//    for (auto& src : numbers)
//    {
//        long long dst = src + 1;
//
//        while (true)
//        {
//            bitset<64> bitResult = dst ^ src;
//            int diff_cnt = bitResult.count();
//
//            if (diff_cnt == 2 || diff_cnt == 1)
//            {
//                answer.emplace_back(dst);
//                break;
//            }
//
//            ++dst;
//        }
//    }
//
//    return answer;
//}
//
//
//
//int solution2(vector<int> citations) 
//{
//    int answer = 0;
//
//    sort(citations.begin(), citations.end());
//
//    for (int i = 0; i < citations.size(); ++i)
//    {
//        int cnt_high = count_if(citations.begin(), citations.end(), [&i, &citations](const int& src)
//            {
//                citations[i];
//            });
//    }
//
//    for (auto& n : citations)
//    {
//        int cnt_high = count_if(citations.begin(), citations.end(), [&n](const int& src)
//            {
//                return src >= n;
//            });
//        if (cnt_high >= n)
//        {
//
//        }
//    }
//
//    return answer;
//}



//int solution(string s)
//{
//    int answer = -1;
//
//    auto iter_find = s.begin();
//    auto tier_find = s.end();
//    while (true)
//    {
//        if (s.empty()) return 1;
//
//        auto iter_start = adjacent_find(s.begin(), s.end());
//        if (*iter_start == '\0') return 0;
//
//        auto iter_end = adjacent_find(iter_start, s.end(), [](const char& a, const char& b)
//            {
//                return a != b;
//            });
//
//        s.erase(iter_start, iter_end + 1);
//    }
//
//    return answer;
//}



//
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//
//
//    map<string, int> mapParticipant;
//    for (auto& name : participant)
//        ++mapParticipant[name];
//
//    map<string, int> mapCompletion;
//    for (auto& name : completion)
//        ++mapCompletion[name];
//
//    for (auto& pair : mapParticipant)
//    {
//        auto iter_find = mapCompletion.find(pair.first);
//        if (iter_find == mapCompletion.end())
//        {
//            answer = pair.first;
//            return answer;
//        }
//        else
//        {
//            if (iter_find->second != pair.second)
//            {
//                answer = iter_find->first;
//                return answer;
//            }
//        }
//    }
//
//    return answer;
//}


//vector<int> solution(vector<string> genres, vector<int> plays) {
//    vector<int> answer;
//
//    // 장르별 PlayCnt를 우선순위 큐에 저장.
//    map<string, priority_queue<pair<int, int>>> mappqGenresPlays;
//
//    // 장르별 재생 횟수 누적.
//    map<string, int> mapGenresPlayCnt;
//
//    // 1. 많이 재생된 장르 순서 찾기.
//    for (int i = 0; i < plays.size(); ++i)
//    {
//        mapGenresPlayCnt[genres[i]] += plays[i];
//        mappqGenresPlays[genres[i]].emplace(plays[i], i);
//    }
//
//    vector<pair<string, int>> vecGenresPlayCnt{ mapGenresPlayCnt.begin(), mapGenresPlayCnt.end() };
//    sort(vecGenresPlayCnt.begin(), vecGenresPlayCnt.end(), [](const pair<string, int>& a, const pair<string, int>& b)
//        {
//            return a.second > b.second;
//        });
//
//    // 2. 장르별 재생 횟수 인덱스 찾기.
//    for (int i = 0; i < vecGenresPlayCnt.size(); ++i)
//    {
//        string genres_tag = vecGenresPlayCnt[i].first;
//
//        int pop_cnt = 0;
//        while (true)
//        {
//            if (mappqGenresPlays[genres_tag].empty()) break;
//            if (pop_cnt == 2) break;
//
//            int idx = mappqGenresPlays[genres_tag].top().second;
//            answer.emplace_back(idx);
//
//            mappqGenresPlays[genres_tag].pop();
//            ++pop_cnt;
//        }
//    }
//
//    return answer;
//}

//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//    vector<int> answer;
//
//    for (auto& cmd_arr : commands)
//    {
//        vector<int> temp{ array.begin() + (cmd_arr[0] - 1), array.begin() + (cmd_arr[1] - 1) };
//        sort(temp.begin(), temp.end());
//
//        answer.emplace_back(temp[cmd_arr[2] - 1]); // k th Num.
//    }
//
//    return answer;
//}

//
//string solution(vector<int> numbers) {
//    string answer = "";
//
//    vector<string> str_numbers;
//
//    for (auto& num : numbers)
//    {
//        char p[256] = "";
//        sprintf(p, "%d", num);
//
//        str_numbers.emplace_back(p);
//    }
//
//    sort(str_numbers.begin(), str_numbers.end(), [](const string& a, const string& b)
//        {
//            return a + b > b + a;
//        });
//
//    for (auto& str : str_numbers)
//    {
//        if (answer == "" && str == "0") continue;
//
//        answer += str;
//    }
//
//    if (answer.length() == 0)
//        answer += "0";
//
//    return answer;
//}


class com 
{
public:	
    bool operator() (const pair<int, int> a, const pair<int, int> b) 
    {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};


int solution(vector<int> priorities, int location) {
    int answer = 0;

    // key : priorities, value : idx
    priority_queue<pair<int, int>, vector<pair<int, int>>, com> pq;

    for (int i = 0; i < priorities.size(); ++i)
        pq.emplace(priorities[i], i);


    while (true)
    {

    }

    return answer;
}

int main() 
{

    solution(vector<int>{ 1, 1, 9, 1, 1, 1 }, 0);

    return 0;
}