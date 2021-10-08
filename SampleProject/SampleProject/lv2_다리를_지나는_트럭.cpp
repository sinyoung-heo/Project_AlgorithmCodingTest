#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    queue<int> waitting_trucks;

    deque<int> trucks_on_bridge_length;
    deque<int> trucks_on_bridge_move;

    for (auto& w : truck_weights)
        waitting_trucks.push(w);

    while (true)
    {
        // 다리를 지나는 트럭 계산.
        for (auto& move_len : trucks_on_bridge_move)
            ++move_len;

        if (!trucks_on_bridge_move.empty() &&
            trucks_on_bridge_move.front() > bridge_length)
        {
            trucks_on_bridge_move.pop_front();
            trucks_on_bridge_length.pop_front();
        }

        ++answer;

        int sum_weight = 0;

        // 다리 위의 트럭 무게 합산.
        for (auto& weights : trucks_on_bridge_length)
            sum_weight += weights;

        // 다리 위의 트럭 무게가 넘지 않았거나, 다리 위에 있는 트럭 개수가 다리 길이보다 적다면 트럭 추가.
        int front = 0;
        if (!waitting_trucks.empty())
            front = waitting_trucks.front();

        if (sum_weight + front <= weight &&
            trucks_on_bridge_length.size() + 1 <= bridge_length)
        {
            if (!waitting_trucks.empty())
            {
                trucks_on_bridge_length.emplace_back(waitting_trucks.front());
                trucks_on_bridge_move.emplace_back(1);

                waitting_trucks.pop();
            }
        }

        if (trucks_on_bridge_move.empty()) break;
    }

    return answer;
}

int main()
{
    solution(2, 10, vector<int>{ 7, 4, 5, 6 });

	return 0;
}