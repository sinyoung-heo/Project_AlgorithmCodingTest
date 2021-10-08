#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// **************************

int solution(vector<int> priorities, int location) 
{
    int answer = 0;

    int max_value = *max_element(priorities.begin(), priorities.end());

    while (true)
    {
        for (int i = 0; i < priorities.size(); ++i)
        {
            // 찾고자 하는 작업이 나왔다면 return.
            if (max_value == priorities[i] && i == location)
                return ++answer;

            // 우선순위가 가장 높은 작업을 찾았다면? 
            if (priorities[i] == max_value)
            {
                ++answer;
                priorities[i] = 0;

                max_value = *max_element(priorities.begin(), priorities.end());
            }
        }
    }

    return answer;
}

int main()
{
    solution(vector<int>{2, 3, 3, 2, 9, 3, 3}, 3);
}