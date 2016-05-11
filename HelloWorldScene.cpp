#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
   
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
	scene->addChild(layer);


    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto winsize = Director::getInstance()->getWinSize();
	//player = new Player();
	//this->addChild(player,1);
	//this->runAction(Follow::create(player,Rect(0, 0,1500, 720)));

	

	//bgLayer = new BackgroundLayer();
	//bgLayer->init();
	//bgLayer->player = player;
	//
	////플레이어 생성
	//
	//
	//bgLayer->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));

	//
	////----조이스틱 생성


	// 조이스틱 1
	kCenter1 = Vec2(JOYSTICK_RADIUS + JOYSTICK_OFFSET_X,
		JOYSTICK_RADIUS + JOYSTICK_OFFSET_Y);
	
	velocity1 = Vec2::ZERO;

	Sprite* bg1 = Sprite::create("joystick_background.png");
	bg1->setPosition(kCenter1);
	this->addChild(bg1, 0);

	thumb1 = Sprite::create("joystick_thumb.png");
	thumb1->setPosition(kCenter1);
	this->addChild(thumb1, 1);


	// 조이스틱 2
	kCenter2 = Vec2(JOYSTICK_RADIUS + winsize.width - 140,
		JOYSTICK_RADIUS + JOYSTICK_OFFSET_Y);


	velocity2 = Vec2::ZERO;

	Sprite* bg2 = Sprite::create("joystick_background.png");
	bg2->setPosition(kCenter2);
	this->addChild(bg2, 0);

	thumb2 = Sprite::create("joystick_thumb.png");
	thumb2->setPosition(kCenter2);
	this->addChild(thumb2, 1);



	bgLayer = new BackgroundLayer();
	bgLayer->joystickVelocity1 = &velocity1;
	bgLayer->joystickVelocity2 = &velocity2;
	bgLayer->joystickIspressed1 = &isPressed1;
	bgLayer->joystickIspressed2 = &isPressed2;
	//bgLayer->player = player;
	bgLayer->init();


	this->addChild(bgLayer, 0);
   
    return true;
}


static bool isPointInCircle(Vec2 point, Vec2 center, float radius)
{
	float dx = (point.x - center.x);
	float dy = (point.y - center.y);
	return (radius >= sqrt((dx*dx) + (dy*dy)));
}

void HelloWorld::updateVelocity1(Vec2 point)
{
	// calculate Angle and length
	float dx = point.x - kCenter1.x;
	float dy = point.y - kCenter1.y;

	float distance = sqrt(dx*dx + dy*dy);
	float angle = atan2(dy, dx); // in radians

	if (distance > JOYSTICK_RADIUS)
	{
		dx = cos(angle) * JOYSTICK_RADIUS;
		dy = sin(angle) * JOYSTICK_RADIUS;
	}

	velocity1 = Vec2((dx) / JOYSTICK_RADIUS, (dy) / JOYSTICK_RADIUS);

	if (distance>THUMB_RADIUS)
	{
		point.x = kCenter1.x + cos(angle) * THUMB_RADIUS;
		point.y = kCenter1.y + sin(angle) * THUMB_RADIUS;
	}

	thumb1->setPosition(point);
}
void HelloWorld::updateVelocity2(Vec2 point)
{
	// calculate Angle and length
	float dx = point.x - kCenter2.x;
	float dy = point.y - kCenter2.y;

	float distance = sqrt(dx*dx + dy*dy);
	float angle = atan2(dy, dx); // in radians

	if (distance > JOYSTICK_RADIUS)
	{
		dx = cos(angle) * JOYSTICK_RADIUS;
		dy = sin(angle) * JOYSTICK_RADIUS;
	}

	velocity2 = Vec2((dx) / JOYSTICK_RADIUS, (dy) / JOYSTICK_RADIUS);

	if (distance>THUMB_RADIUS)
	{
		point.x = kCenter2.x + cos(angle) * THUMB_RADIUS;
		point.y = kCenter2.y + sin(angle) * THUMB_RADIUS;
	}

	thumb2->setPosition(point);
}

void HelloWorld::resetJoystick1()
{
	this->updateVelocity1(kCenter1);
}
void HelloWorld::resetJoystick2()
{
	this->updateVelocity2(kCenter2);
}

bool HelloWorld::handleLastTouch1()
{
	bool wasPressed = isPressed1;



	if (wasPressed)
	{
		this->resetJoystick1();
		isPressed1 = false;
	}
	return (wasPressed ? true : false);
}
bool HelloWorld::handleLastTouch2()
{
	bool wasPressed = isPressed2;



	if (wasPressed)
	{
		this->resetJoystick2();
		isPressed2 = false;
	}
	return (wasPressed ? true : false);
}


void HelloWorld::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Joystick::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Joystick::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Joystick::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(Joystick::onTouchesCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{
		auto touch = item;
		Vec2 point = touch->getLocationInView();
		Vec2 touchPoint = Director::getInstance()->convertToGL(point);

		if (isPointInCircle(touchPoint, kCenter1, JOYSTICK_RADIUS))
		{
			isPressed1 = true;
			this->updateVelocity1(touchPoint);
		}
		if (isPointInCircle(touchPoint, kCenter2, JOYSTICK_RADIUS))
		{
			isPressed2 = true;
			this->updateVelocity2(touchPoint);
		}
	}



}

void HelloWorld::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{

		if (isPressed1)
		{
			auto touch = item;
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);

			this->updateVelocity1(touchPoint);
		}
		if (isPressed2)
		{
			auto touch = item;
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);

			this->updateVelocity2(touchPoint);
		}

	}


}

void HelloWorld::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{
		if (isPressed1)
		{
			auto touch = item;
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);
			this->handleLastTouch1();
		}
		if (isPressed2)
		{
			auto touch = item;
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);
			this->handleLastTouch2();
		}
		


	}
}

