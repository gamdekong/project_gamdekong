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
#define FIREGIRL 9
#define BALCKSMITH 10
#define FIRE 11

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
	

	void IdleAction();
	void AttackAction();
	void MoveAction();
	void DeadAction();
	void HittedAction();



};