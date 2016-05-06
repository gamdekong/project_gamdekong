#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class Player : public cocos2d::Sprite
{
public:
	void IdleAction();
	void AttackAction();
	void DeadAction();
	void MoveAction();


	Player();
	void init2();


	int maxEnergy;
	int nowEnergy;
	Texture2D *playerMoveTexture;
	Texture2D *playerAttackTexture;
	Texture2D *playerIdleTexture;
	Texture2D *playerDeadTexture;



};