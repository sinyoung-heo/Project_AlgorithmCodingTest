#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector<char> vecTemp;
    vecTemp.reserve(s.size());

    int cntSmall = 0;
    int cntMid = 0;
    int cntLarge = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        // ÇÑ Ä­¾¿ ¿ÞÂÊÀ¸·Î ÀÌµ¿.
        if (i != 0)
        {
            char first = s[0];

            for (int k = 1; k < s.size(); ++k)
                s[k - 1] = s[k];

            s[s.size() - 1] = first;
        }

        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] == ')')
            {
                --cntSmall;
                if (vecTemp.back() == '(')
                    vecTemp.pop_back();
            }
            else if (s[j] == '(')
            {
                ++cntSmall;
                vecTemp.emplace_back(s[j]);
            }

            else if (s[j] == '}')
            {
                --cntMid;
                if (vecTemp.back() == '{')
                    vecTemp.pop_back();
            }
            else if (s[j] == '{')
            {
                ++cntMid;
                vecTemp.emplace_back(s[j]);
            }

            else if (s[j] == ']')
            {
                --cntLarge;
                if (vecTemp.back() == '[')
                    vecTemp.pop_back();
            }
            else if (s[j] == '[')
            {
                ++cntLarge;
                vecTemp.emplace_back(s[j]);
            }

            if (cntSmall < 0 || cntMid < 0 || cntLarge < 0)
                break;
        }

        if (cntSmall == 0 && cntMid == 0 && cntLarge == 0 && vecTemp.empty())
            ++answer;

        vecTemp.clear();
        cntSmall = 0;
        cntMid = 0;
        cntLarge = 0;
    }

    return answer;
}

int main()
{

    return 0;
}