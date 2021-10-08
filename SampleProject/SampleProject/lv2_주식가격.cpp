#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;

    for (int i = 0; i < prices.size(); ++i)
    {
        int sec = 0;

        for (int j = i + 1; j < prices.size(); ++j)
        {
            ++sec;

            if (prices[i] > prices[j]) break;
        }

        answer.emplace_back(sec);
    }


    return answer;
}

int main()
{

    return 0;
}