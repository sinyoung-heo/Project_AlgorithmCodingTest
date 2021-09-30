#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <memory>

using namespace std;

template<typename T, typename... Args>
T* CreateT(Args&&... args)
{
	return new T(forward<Args>(args)...);
}

class CPlayer
{
public:
	CPlayer(const int& level, const int& hp, const int& att)
		: level(level), hp(hp), att(att)
	{
		cout << "Player 생성자 호출" << endl;
	}
	~CPlayer() = default;
private:
	int level = 0;
	int hp = 0;
	int att = 0;
};

int main()
{
	CPlayer* player = nullptr;
	player = CreateT<CPlayer>(99, 1000, 256);

	if (nullptr != player)
		delete player;
}