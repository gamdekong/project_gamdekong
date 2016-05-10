#include "SwordMissile.h"

SwordMissile::SwordMissile(int num)
{
	this->init2(num);
}

void SwordMissile::init2(int num)
{
	missile = Director::getInstance()->getTextureCache()->addImage("missile/missile.png");
	switch (num)
	{
	case 1:
		this->initWithTexture(missile, Rect(120, 360, 120, 120));
		break;

	case 2:
		this->initWithTexture(missile, Rect(120, 120, 120, 120));
		break;
	case 3:

		this->initWithTexture(missile, Rect(120, 240, 120, 120));
		break;
	case 4:
		this->initWithTexture(missile, Rect(120, 0, 120, 120));
		break;
	case 5:
		this->initWithTexture(missile, Rect(120, 480, 120, 120));
		break;

		
	}
	this->missileNum = num;
	this->setTag(3);
}

void SwordMissile::endAction(int num)
{
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1);

	switch (num)
	{
	case 1:
		animation->addSpriteFrameWithTexture(missile, Rect(240, 360, 120, 120));
		animation->addSpriteFrameWithTexture(missile, Rect(360, 360, 120, 120));
		break;

	case 2:
		animation->addSpriteFrameWithTexture(missile, Rect(240, 120, 120, 120));
		animation->addSpriteFrameWithTexture(missile, Rect(360, 120, 120, 120));
		break;
	case 3:
		animation->addSpriteFrameWithTexture(missile, Rect(240, 240, 120, 120));
		animation->addSpriteFrameWithTexture(missile, Rect(360, 240, 120, 120));
		break;
	case 4:
		animation->addSpriteFrameWithTexture(missile, Rect(240, 0, 120, 120));
		animation->addSpriteFrameWithTexture(missile, Rect(360, 0, 120, 120));
		break;
	case 5:
		animation->addSpriteFrameWithTexture(missile, Rect(240, 480, 120, 120));
		animation->addSpriteFrameWithTexture(missile, Rect(360, 480, 120, 120));
		break;
	}
	auto animate = Animate::create(animation);
	auto seq = Sequence::create(animate,RemoveSelf::create(), nullptr);
	this->runAction(seq);


}

void SwordMissile::startAction(int num)
{
	
		auto animation = Animation::create();
		animation->setDelayPerUnit(0.1);

		switch (num)
		{
		case 1:
			animation->addSpriteFrameWithTexture(missile, Rect(0, 360, 120, 120));
			animation->addSpriteFrameWithTexture(missile, Rect(120, 360, 120, 120));
			break;

		case 2:
			animation->addSpriteFrameWithTexture(missile, Rect(0, 120, 120, 120));
			animation->addSpriteFrameWithTexture(missile, Rect(120, 120, 120, 120));
			break;
		case 3:
			animation->addSpriteFrameWithTexture(missile, Rect(0, 240, 120, 120));
			animation->addSpriteFrameWithTexture(missile, Rect(120, 240, 120, 120));
			break;
		case 4:
			animation->addSpriteFrameWithTexture(missile, Rect(0, 0, 120, 120));
			animation->addSpriteFrameWithTexture(missile, Rect(120, 0, 120, 120));
			break;
		case 5:
			animation->addSpriteFrameWithTexture(missile, Rect(0, 480, 120, 120));
			animation->addSpriteFrameWithTexture(missile, Rect(120, 480, 120, 120));
			break;
		}
		auto animate = Animate::create(animation);
		auto seq = Sequence::create(animate, nullptr);
		this->runAction(seq);


	
}