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

	
	
	
	
	
	

}
