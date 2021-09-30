#include "vld.h"
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

class CPlayer
{
public:
	CPlayer() { cout << "Player 기본생성자 호출" << endl; };
	CPlayer(const int& n) : level(n) { cout << "Player 인자 있는 생성자 호출" << endl; };
	~CPlayer() { cout << "Player 소멸자 호출" << endl; cout << camera.use_count() << endl; };
public:
	const int& getLevel() { return level; }
	weak_ptr<CCamera>& getCamera() { return camera; }
	void setCamera(const shared_ptr<CCamera>& spCamera) { camera = spCamera; cout << camera.use_count() << endl; }

private:
	int level{ 0 };
	weak_ptr<CCamera> camera;
};


class CCamera
{
public:
	CCamera() { cout << "Camera 기본생성자 호출" << endl; };
	CCamera(const int& n) : value(n) { cout << "Camera 인자 있는 생성자 호출" << endl; };
	~CCamera() { cout << "Camera 소멸자 호출" << endl; cout << player.use_count() << endl; };
public:
	const int& getValue() { return value; }
	weak_ptr<CPlayer>& getPlayer() { return player; }

	void setPlayer(const shared_ptr<CPlayer>& spPlayer) { player = spPlayer; cout << player.use_count() << endl; }

private:
	int value{ 0 };
	weak_ptr<CPlayer> player;
};

int main()
{
	shared_ptr<CPlayer> spPlayer = make_shared<CPlayer>(99);
	shared_ptr<CCamera> spCamera = make_shared<CCamera>(1);

	cout << spPlayer.use_count() << endl;
	cout << spCamera.use_count() << endl;
	cout << "------" << endl;

	// weak_ptr은 shared_ptr의 순환 참조 고리를 끊기 위해 도입되었다.
	// weak_ptr은 참조 횟수를 증가시키지 않는다.
	spPlayer->setCamera(spCamera);
	spCamera->setPlayer(spPlayer);

	return 0;
}