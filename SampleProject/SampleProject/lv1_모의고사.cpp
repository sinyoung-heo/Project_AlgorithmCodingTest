#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;

    vector<int> vecScore{ 0, 0, 0 };

    vector<int> p1{ 1, 2, 3, 4, 5 };
    vector<int> p2{ 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> p3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    auto iter_begin_p1 = p1.begin();
    auto iter_begin_p2 = p2.begin();
    auto iter_begin_p3 = p3.begin();

    for (int i = 0; i < answers.size(); ++i, ++iter_begin_p1, ++iter_begin_p2, ++iter_begin_p3)
    {
        if (iter_begin_p1 == p1.end()) iter_begin_p1 = p1.begin();
        if (iter_begin_p2 == p2.end()) iter_begin_p2 = p2.begin();
        if (iter_begin_p3 == p3.end()) iter_begin_p3 = p3.begin();

        if (*iter_begin_p1 == answers[i]) ++vecScore[0];
        if (*iter_begin_p2 == answers[i]) ++vecScore[1];
        if (*iter_begin_p3 == answers[i]) ++vecScore[2];
    }

    int max_score = *max_element(vecScore.begin(), vecScore.end());

    for (int i = 0; i < vecScore.size(); ++i)
    {
        if (vecScore[i] == max_score)
            answer.emplace_back(i + 1);
    }

    return answer;
}

int main()
{

    return 0;
}