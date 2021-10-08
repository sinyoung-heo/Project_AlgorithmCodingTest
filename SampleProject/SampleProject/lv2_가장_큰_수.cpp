#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// **************************

string solution(vector<int> numbers) 
{
    string answer = "";

    vector<string> str_numbers;

    for (auto& num : numbers)
    {
        char p[256] = "";
        sprintf(p, "%d", num);

        str_numbers.emplace_back(p);
    }

    sort(str_numbers.begin(), str_numbers.end(), [](const string& a, const string& b)
        {
            return a + b > b + a;
        });

    for (auto& str : str_numbers)
    {
        if (answer == "" && str == "0") continue;

        answer += str;
    }

    if (answer.length() == 0)
        answer += "0";

    return answer;
}

int main()
{

    return 0;
}