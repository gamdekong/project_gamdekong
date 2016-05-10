#include "Monster.h"

Monster::Monster()
{
	this->init2();
}

void Monster::init2()
{
	this->initWithFile("monster/grossini.png");
	nowEnergy = 10;
	this->setPosition(Vec2(500, 200));
	this->setTag(2);

}
