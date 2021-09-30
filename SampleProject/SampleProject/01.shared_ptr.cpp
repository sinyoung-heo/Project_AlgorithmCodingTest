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
	CPlayer() { cout << "Player �⺻������ ȣ��" << endl; };
	CPlayer(const int& n) : level(n) { cout << "Player ���� �ִ� ������ ȣ��" << endl; };
	~CPlayer() { cout << "Player �Ҹ��� ȣ��" << endl; cout << camera.use_count() << endl; };
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
	CCamera() { cout << "Camera �⺻������ ȣ��" << endl; };
	CCamera(const int& n) : value(n) { cout << "Camera ���� �ִ� ������ ȣ��" << endl; };
	~CCamera() { cout << "Camera �Ҹ��� ȣ��" << endl; cout << player.use_count() << endl; };
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

	// weak_ptr�� shared_ptr�� ��ȯ ���� ���� ���� ���� ���ԵǾ���.
	// weak_ptr�� ���� Ƚ���� ������Ű�� �ʴ´�.
	spPlayer->setCamera(spCamera);
	spCamera->setPlayer(spPlayer);

	return 0;
}