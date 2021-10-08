#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;

    pair<int, int> width_height;

    int sum = brown + yellow;

    // 인수를 통해 width와 height를 구한다.
    for (int width = sum - 1; width >= 1; --width)
    {
        if (sum % width == 0)
        {
            int height = sum / width;

            if ((width - 2) * (height - 2) == yellow)
            {
                answer.emplace_back(width);
                answer.emplace_back(height);
                break;
            }
        }
    }

    return answer;
}

int main()
{

}