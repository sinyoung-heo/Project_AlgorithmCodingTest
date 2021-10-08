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
            // ã���� �ϴ� �۾��� ���Դٸ� return.
            if (max_value == priorities[i] && i == location)
                return ++answer;

            // �켱������ ���� ���� �۾��� ã�Ҵٸ�? 
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