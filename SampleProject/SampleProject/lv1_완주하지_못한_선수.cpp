#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";


    map<string, int> mapParticipant;
    for (auto& name : participant)
        ++mapParticipant[name];

    map<string, int> mapCompletion;
    for (auto& name : completion)
        ++mapCompletion[name];

    for (auto& pair : mapParticipant)
    {
        auto iter_find = mapCompletion.find(pair.first);
        if (iter_find == mapCompletion.end())
        {
            answer = pair.first;
            return answer;
        }
        else
        {
            if (iter_find->second != pair.second)
            {
                answer = iter_find->first;
                return answer;
            }
        }
    }

    return answer;
}

int main()
{
    return 0;
}