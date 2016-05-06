#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class Monster : public cocos2d::Sprite
{
public:


	Monster();
	void init2();


	int maxEnergy;
	int nowEnergy;
	Texture2D *moster;


};