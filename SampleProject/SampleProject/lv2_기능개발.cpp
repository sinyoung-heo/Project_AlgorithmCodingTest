#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    deque<int> dq_progresses{ progresses.begin(), progresses.end() };
    deque<int> dq_speeds{ speeds.begin(), speeds.end() };

    while (!dq_progresses.empty() && !speeds.empty())
    {
        int size = dq_progresses.size();

        for (int i = 0; i < size; ++i)
            dq_progresses[i] += dq_speeds[i];

        int progress_cnt = 0;
        while (true)
        {
            if (dq_progresses.front() >= 100)
            {
                ++progress_cnt;
                dq_progresses.pop_front();
                dq_speeds.pop_front();
            }

            if (dq_progresses.empty() || dq_progresses.front() < 100)
            {
                if (progress_cnt != 0)
                    answer.emplace_back(progress_cnt);

                break;
            }

        }
    }

    return answer;
}

int main()
{

    return 0;
}