#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    set<string> setWord;

    vector<int> vecCycle;
    vecCycle.resize(n);

    // 0 1 2 3 4 - 0 1 2 3 4
    int order = 1;
    for (int i = 0; i < words.size(); ++i)
    {
        ++vecCycle[i % n];

        auto iter_find = setWord.find(words[i]);
        if (iter_find != setWord.end())
        {
            answer.emplace_back((i % n) + 1);
            answer.emplace_back(vecCycle[i % n]);
            break;
        }
        if (i != 0)
        {
            if (words[i - 1].back() != words[i].front())
            {
                answer.emplace_back((i % n) + 1);
                answer.emplace_back(vecCycle[i % n]);
                break;
            }
        }

        setWord.emplace(words[i]);
    }

    if (answer.empty())
    {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }

    return answer;
}

int main()
{

    return 0;
}