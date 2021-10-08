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
        // ����ִٸ� ó�� ���ڸ� �ִ´�.
        if (vecChar.empty())
        {
            vecChar.emplace_back(ch);
        }
        else
        {
            // ���� ���� ���ڸ� ����Ʈ���� �����Ѵ�.
            if (vecChar.back() == ch)
                vecChar.pop_back();

            // �ٸ� ���ڸ� ����Ʈ�� �ִ´�.
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