#include <string>
#include <vector>
#include <cmath>

using namespace std;

// ********************


vector<int> solution(int n) 
{
    vector<int> answer;

    vector<vector<int>> vecTriangle;
    vecTriangle.resize(n);
    for (int i = 0; i < n; ++i)
        vecTriangle[i].resize(n);

    int cnt = n;
    int startValue = 1;
    int y = -1, x = 0;

    int dir = 1;
    int down = 1, left = 2, up = 0;

    while (cnt > 0)
    {
        for (int i = 0; i < cnt; ++i)
        {
            // down
            if (dir % 3 == 1)
                ++y;
            // left
            else if (dir % 3 == 2)
                ++x;
            // up
            else if (dir % 3 == 0)
            {
                --x;
                --y;
            }

            vecTriangle[y][x] = startValue;
            ++startValue;
        }

        --cnt;
        ++dir;
    }

    for (auto& a : vecTriangle)
    {
        for (auto& b : a)
        {
            if (b != 0)
                answer.emplace_back(b);
        }
    }

    return answer;
}

int main()
{

    return 0;
}