#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;

    unordered_map<string, int> subString;

    for (auto& ph_num : phone_book)
    {
        string comp_str = "";

        for (int i = 0; i < ph_num.length(); ++i)
        {
            comp_str += ph_num[i];
            ++subString[comp_str];
        }
    }

    for (auto& ph_num : phone_book)
    {
        if (subString[ph_num] > 1)
            return false;
    }


    answer = true;
    return answer;
}

int main()
{

    return 0;
}