#pragma once
#include "cocos2d.h"

using namespace cocos2d;

#define BEAST 1
#define BIRD 2
#define DOG 3
#define BAT 4
#define SNAKE 5
#define SOUL 6
#define SWORND 7
#define WORM 8

class Monster : public cocos2d::Sprite
{
public:


	Monster(int);
	void init2();


	//int maxEnergy;
	int power;
	int nowEnergy;
	int monsterNum;
	Texture2D *monster;
	Texture2D *beast;
	Texture2D *bird;
	Texture2D *dog;
	Texture2D *bat;
	Texture2D *snake;
	Texture2D *soul;
	Texture2D *swornd;
	Texture2D *worm;

	void IdleAction();
	void AttackAction();
	void MoveAction();
	void DeadAction();
	void HittedAction();



};