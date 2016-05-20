#include "Monster.h"

Monster::Monster(int num)
{
	this->monsterNum = num;
	if (monsterNum == BEAST)
	{
		nowEnergy = 15;
		power = 2;
	}
	else if (monsterNum == BIRD)
	{
		nowEnergy = 8;
	}
	else if (monsterNum == DOG)
	{
		nowEnergy = 13;
		power = 2;
	}
	else if (monsterNum == BAT)
	{
		nowEnergy = 8;
	}
	else if (monsterNum == SNAKE)
	{
		nowEnergy = 10;
		power = 2;
	}
	else if (monsterNum == SOUL)
	{
		nowEnergy = 5;
		power = 3;
	}
	else if (monsterNum == SWORND)
	{
		nowEnergy = 5;
		power = 3;
	}
	else if (monsterNum == WORM)
	{
		nowEnergy = 10;
		power = 2;
	}
	else if (monsterNum == FIREGIRL)
	{
		nowEnergy = 1000;
		power = 0;
	}
	else if (monsterNum == FIRE)
	{
		nowEnergy = 1000;
		power = 0;
	}


	this->init2();
}

void Monster::init2()
{
	
	switch (monsterNum)
	{
	case BEAST:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/beast.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;

	case BIRD:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/bird.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;
	case DOG:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/dog.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;
	case BAT:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/bat.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;
	case SNAKE:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/snake.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;
	case SOUL:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/soul.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;
	case SWORND:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/swornd.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;
	case WORM:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/stage1-monster/worm.png");
		this->initWithTexture(monster, Rect(0, 0, 120, 120));
		break;
	case FIREGIRL:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/npc/firegirl.png");
		this->initWithTexture(monster, Rect(0, 0, 75, 200));
		break;
	case FIRE:
		monster = Director::getInstance()->getTextureCache()->addImage("monster/npc/Bonfire_v1.png");
		this->initWithTexture(monster, Rect(0, 0, 71, 100));
		break;

	}
	this->setTag(2);

}
void Monster::IdleAction()
{
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1);
	switch (monsterNum)
	{
	case BEAST:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 0, 120, 120));
		break;

	case BIRD:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(840, 0, 120, 120));
		break;
	case DOG:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(840, 0, 120, 120));
		break;
	case BAT:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		break;
	case SNAKE:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 0, 120, 120));
		break;
	case SOUL:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 0, 120, 120));
		break;
	case SWORND:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		break;
	case WORM:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		break;
	case FIREGIRL:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 75, 200));
		animation->addSpriteFrameWithTexture(monster, Rect(75, 0, 75, 200));
		animation->addSpriteFrameWithTexture(monster, Rect(150, 0, 75, 200));
		animation->addSpriteFrameWithTexture(monster, Rect(225, 0, 75, 200));
		break;
	case FIRE:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 60, 101));
		animation->addSpriteFrameWithTexture(monster, Rect(60, 0, 60, 101));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 60, 101));
		animation->addSpriteFrameWithTexture(monster, Rect(180, 0, 60, 101));
		break;
		

	}
	auto animate = Animate::create(animation);
	auto seqFor = RepeatForever::create(animate);
	this->stopAllActions();
	this->runAction(seqFor);

}
void Monster::AttackAction()
{
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1);
	switch (monsterNum)
	{
	case BEAST:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 240, 120, 120));
		
		break;

	case BIRD:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 240, 120, 120));
		
		break;
	case DOG:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 240, 120, 120));
		
		break;
	case BAT:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		
	case SNAKE:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 240, 120, 120));
		
		break;
	case SOUL:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 120, 120, 120));
		break;
	case SWORND:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 120, 120, 120));
		break;
	case WORM:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 240, 120, 120));
		
		break;
	}
	auto animate = Animate::create(animation);
	auto seq = Sequence::create(animate,CallFunc::create(CC_CALLBACK_0(Monster::IdleAction,this)), nullptr);
	this->stopAllActions();
	this->runAction(seq);
}
void Monster::MoveAction()
{
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1);
	switch (monsterNum)
	{
	case BEAST:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 120, 120, 120));
		
		break;

	case BIRD:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 120, 120, 120));
		
		
		break;
	case DOG:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 120, 120, 120));
		
		break;
	case BAT:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		break;
	case SNAKE:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 120, 120, 120));
		
		break;
	case SOUL:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 0, 120, 120));
		break;
	case SWORND:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 0, 120, 120));
		break;
	case WORM:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 120, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 120, 120, 120));
		break;
	}
	auto animate = Animate::create(animation);
	auto seq = Sequence::create(animate, nullptr);
	this->stopAllActions();
	this->runAction(seq);
}

void Monster::DeadAction()
{
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1);
	switch (monsterNum)
	{
	case BEAST:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 480, 120, 120));
		break;

	case BIRD:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(840, 480, 120, 120));
		break;
	case DOG:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(840, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(960, 480, 120, 120));
		break;
	case BAT:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 360, 120, 120));
		break;
	case SNAKE:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 480, 120, 120));
		
		break;
	case SOUL:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(840, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(960, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(1080, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(1200, 360, 120, 120));

		break;
	case SWORND:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(720, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(840, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(960, 360, 120, 120));
		
		break;
	case WORM:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 480, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(600, 480, 120, 120));
		break;
	}
	auto animate = Animate::create(animation);
	auto seq = Sequence::create(animate,RemoveSelf::create(), nullptr);
	this->stopAllActions();
	this->runAction(seq);
}
void Monster::HittedAction()
{
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1);
	switch (monsterNum)
	{
	case BEAST:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		
		break;

	case BIRD:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 360, 120, 120));
		
		break;
	case DOG:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 360, 120, 120));
		
		break;
	case BAT:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 240, 120, 120));
		break;
	case SNAKE:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 360, 120, 120));
		
		break;
	case SOUL:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		
		break;
	case SWORND:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 240, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 240, 120, 120));
		
		break;
	case WORM:
		animation->addSpriteFrameWithTexture(monster, Rect(0, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(120, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(240, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(360, 360, 120, 120));
		animation->addSpriteFrameWithTexture(monster, Rect(480, 360, 120, 120));
		break;
	}
	auto animate = Animate::create(animation);
	auto seq = Sequence::create(animate, CallFunc::create(CC_CALLBACK_0(Monster::IdleAction, this)), nullptr);
	this->stopAllActions();
	this->runAction(seq);
}
#define BEAST 1
#define BIRD 2
#define DOG 3
#define BAT 4
#define SNAKE 5
#define SOUL 6
#define SWORND 7
#define WORM 8