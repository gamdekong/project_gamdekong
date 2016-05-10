#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class SwordMissile : public cocos2d::Sprite
{
public:
	SwordMissile(int);
	void init2(int);
	void endAction(int);
	void startAction(int);

	int missileNum;

	Texture2D *missile;
	Sprite *missile1;
	Sprite *missile2;
	Sprite *missile3;
	Sprite *missile4;
	Sprite *missile5;


};