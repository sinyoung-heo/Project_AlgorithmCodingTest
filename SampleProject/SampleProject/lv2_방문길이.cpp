#include <string>
using namespace std;


int solution(string dirs) {
    int answer = 0;

    struct NEIGHBOR
    {
        bool uVisit = false;
        bool dVisit = false;
        bool rVisit = false;
        bool lVisit = false;
    };

    const int SIZE_X = 11;
    const int SIZE_Y = 11;

    NEIGHBOR point[SIZE_Y][SIZE_X];
    for (int i = 0; i < SIZE_Y; ++i)
    {
        for (int j = 0; j < SIZE_X; ++j)
        {
            // U
            if (i - 1 >= 0)
            {
                point[i][j].uVisit = false;
            }

            // D
            if (i + 1 < SIZE_Y)
            {
                point[i][j].dVisit = false;
            }

            // R
            if (j + 1 < SIZE_X)
            {
                point[i][j].rVisit = false;
            }

            // L
            if (j - 1 >= 0)
            {
                point[i][j].lVisit = false;
            }
        }
    }

    int curX = 5, curY = 5;
    int preX = 5, preY = 5;

    for (int i = 0; i < dirs.size(); ++i)
    {
        if ('U' == dirs[i])
        {
            if (curY - 1 >= 0)
            {
                --curY;

                if (!point[curY][curX].dVisit && !point[preY][preX].uVisit)
                {
                    point[curY][curX].dVisit = true;
                    point[preY][preX].uVisit = true;

                    ++answer;
                }
                preX = curX;
                preY = curY;
            }
        }
        else if ('D' == dirs[i])
        {
            if (curY + 1 < SIZE_Y)
            {
                ++curY;

                if (!point[curY][curX].uVisit && !point[preY][preX].dVisit)
                {
                    point[curY][curX].uVisit = true;
                    point[preY][preX].dVisit = true;

                    ++answer;
                }
                preX = curX;
                preY = curY;
            }
        }
        else if ('R' == dirs[i])
        {
            if (curX + 1 < SIZE_X)
            {
                ++curX;

                if (!point[curY][curX].lVisit && !point[preY][preX].rVisit)
                {
                    point[curY][curX].lVisit = true;
                    point[preY][preX].rVisit = true;

                    ++answer;
                }
                preX = curX;
                preY = curY;
            }
        }
        else if ('L' == dirs[i])
        {
            if (curX - 1 >= 0)
            {
                --curX;

                if (!point[curY][curX].rVisit && !point[preY][preX].lVisit)
                {
                    point[curY][curX].rVisit = true;
                    point[preY][preX].lVisit = true;

                    ++answer;
                }
                preX = curX;
                preY = curY;
            }
        }
    }

    return answer;
}

int main()
{

    return 0;
}