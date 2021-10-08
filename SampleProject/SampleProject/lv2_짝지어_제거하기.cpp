#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = -1;

    vector<char> vecChar;
    vecChar.reserve(s.size());

    for (auto& ch : s)
    {
        // 비어있다면 처음 문자를 넣는다.
        if (vecChar.empty())
        {
            vecChar.emplace_back(ch);
        }
        else
        {
            // 만약 같은 문자면 리스트에서 제거한다.
            if (vecChar.back() == ch)
                vecChar.pop_back();

            // 다른 문자면 리스트에 넣는다.
            else
                vecChar.push_back(ch);
        }
    }

    if (vecChar.empty())
        return 1;
    else
        return 0;

    return answer;
}

int main()
{
    return 0;
}