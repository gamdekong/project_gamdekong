#include "Player.h"

void Player::IdleAction()
{
	playerIdleTexture = Director::getInstance()->getTextureCache()->addImage("player/idle/idle.png");
	//--------ÈÞ½Ä
	auto animation2 = Animation::create();
	animation2->setDelayPerUnit(0.2);
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;

		animation2->addSpriteFrameWithTexture(playerIdleTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate2 = Animate::create(animation2);

	auto seq2 = Sequence::create(animate2, nullptr);
	auto playerIdleSeq = RepeatForever::create(seq2);
	this->runAction(playerIdleSeq);
}

void Player::AttackAction()
{
	playerIdleTexture = Director::getInstance()->getTextureCache()->addImage("player/idle/idle.png");
	//--------ÈÞ½Ä
	auto animation2 = Animation::create();
	animation2->setDelayPerUnit(0.2);
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;

		animation2->addSpriteFrameWithTexture(playerIdleTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate2 = Animate::create(animation2);

	auto seq2 = Sequence::create(animate2, nullptr);
	auto playerIdleSeq = RepeatForever::create(seq2);


	/////////////////////////////////////////

	playerAttackTexture = Director::getInstance()->getTextureCache()->addImage("player/attack/attack.png");
	auto animation3 = Animation::create();
	animation3->setDelayPerUnit(0.1);
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;

		animation3->addSpriteFrameWithTexture(playerAttackTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate3 = Animate::create(animation3);

	auto seq3 = Sequence::create(animate3, animate2, animate2, animate2, animate2, animate2, animate2,
		animate2, animate2, animate2, animate2, animate2, animate2,nullptr);
	//auto playerAttackSeq = RepeatForever::create(seq3);
	this->runAction(seq3);
}

void Player::DeadAction()
{
	playerDeadTexture = Director::getInstance()->getTextureCache()->addImage("player/dead/dead.png");
	auto animation4 = Animation::create();
	animation4->setDelayPerUnit(0.1);
	for (int i = 0; i < 6; i++)
	{
		int column = i % 6;

		animation4->addSpriteFrameWithTexture(playerDeadTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate4 = Animate::create(animation4);

	auto seq4 = Sequence::create(animate4, nullptr);
	auto playerDeadSeq = RepeatForever::create(seq4);
	this->runAction(playerDeadSeq);
}

void Player::MoveAction()
{
	playerMoveTexture = Director::getInstance()->getTextureCache()->addImage("player/move/move.png");
	auto animation1 = Animation::create();
	animation1->setDelayPerUnit(0.1);
	for (int i = 0; i < 6; i++)
	{
		int column = i % 6;

		animation1->addSpriteFrameWithTexture(playerMoveTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate1 = Animate::create(animation1);

	auto seq1 = Sequence::create(animate1, nullptr);
	auto playerMoveSeq = RepeatForever::create(seq1);

	this->runAction(playerMoveSeq);
}
