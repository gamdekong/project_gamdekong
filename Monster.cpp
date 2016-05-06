#include "Monster.h"

Monster::Monster()
{
	this->init2();
}

void Monster::init2()
{
	this->initWithFile("monster/grossini.png");
	this->setPosition(Vec2(500, 200));


}
