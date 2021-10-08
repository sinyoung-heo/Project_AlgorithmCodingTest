#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;

    for (auto& cmd_arr : commands)
    {
        vector<int> temp{ array.begin() + (cmd_arr[0] - 1), array.begin() + (cmd_arr[1]) };
        sort(temp.begin(), temp.end());

        answer.emplace_back(temp[cmd_arr[2] - 1]); // k th Num.
    }

    return answer;
}

int main()
{

    return 0;
}