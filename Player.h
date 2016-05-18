#pragma once
#include "cocos2d.h"
#include "SwordMissile.h"
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

	Layer *nowStage;
	int maxEnergy;
	int nowEnergy;
	int power;
	float attackSpeed;
	SwordMissile *missile;
	Texture2D *playerMoveTexture;
	Texture2D *playerAttackTexture;
	Texture2D *playerIdleTexture;
	Texture2D *playerDeadTexture;



};