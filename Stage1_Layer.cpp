#include "Stage1_Layer.h"

USING_NS_CC;


Scene* Stage1_Layer::createScene()
{
   
    auto scene = Scene::create();
    auto layer = Stage1_Layer::create();
	scene->addChild(layer);


    return scene;
}

// on "init" you need to initialize your instance
bool Stage1_Layer::init()
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
	kCenter1 = Vec2(150,150	);
	
	velocity1 = Vec2::ZERO;

	Sprite* bg1 = Sprite::create("joystick_background.png");
	bg1->setPosition(kCenter1);
	this->addChild(bg1, 1);

	thumb1 = Sprite::create("joystick_thumb.png");
	thumb1->setPosition(kCenter1);
	this->addChild(thumb1, 2);


	// 조이스틱 2
	kCenter2 = Vec2(winsize.width - 150, 150);


	velocity2 = Vec2::ZERO;

	Sprite* bg2 = Sprite::create("joystick_background.png");
	bg2->setPosition(kCenter2);
	this->addChild(bg2, 1);

	thumb2 = Sprite::create("joystick_thumb.png");
	thumb2->setPosition(kCenter2);
	this->addChild(thumb2, 2);

	player = new Player();
	
	//-----------------스테이지 객체 생성------------------

	bgLayer1 = new Stage1();//생성자 넣기
	bgLayer1->stageNum = 1;
	bgLayer1->joystickVelocity1 = &velocity1;
	bgLayer1->joystickVelocity2 = &velocity2;
	bgLayer1->joystickIspressed1 = &isPressed1;
	bgLayer1->joystickIspressed2 = &isPressed2;
	bgLayer1->player = player;
	bgLayer1->addChild(player);
	bgLayer1->init();

	bgLayer2 = new Stage1();
	bgLayer2->stageNum = 2;
	bgLayer2->joystickVelocity1 = &velocity1;
	bgLayer2->joystickVelocity2 = &velocity2;
	bgLayer2->joystickIspressed1 = &isPressed1;
	bgLayer2->joystickIspressed2 = &isPressed2;
	//-------------------------------백터에 스테이지 넣기------------------

	player->nowStage = bgLayer1;

	stage.push_back(bgLayer1);
	stage.push_back(bgLayer2);

	bgLayer1->prev = bgLayer2;
	bgLayer1->next = bgLayer2;

	bgLayer2->prev = bgLayer1;
	bgLayer2->next = bgLayer1;


	//---------------------------------------------------------------------

	this->addChild(bgLayer1, 0);
   
	this->schedule(schedule_selector(Stage1_Layer::tick, this));
    return true;
}


static bool isPointInCircle(Vec2 point, Vec2 center, float radius)
{
	float dx = (point.x - center.x);
	float dy = (point.y - center.y);
	return (radius >= sqrt((dx*dx) + (dy*dy)));
}

void Stage1_Layer::updateVelocity1(Vec2 point)
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
void Stage1_Layer::updateVelocity2(Vec2 point)
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

void Stage1_Layer::resetJoystick1()
{
	this->updateVelocity1(kCenter1);
}
void Stage1_Layer::resetJoystick2()
{
	log("2");

	this->updateVelocity2(kCenter2);
}

bool Stage1_Layer::handleLastTouch1()
{
	bool wasPressed = isPressed1;



	if (wasPressed)
	{
		this->resetJoystick1();
		isPressed1 = false;
	}
	return (wasPressed ? true : false);
}
bool Stage1_Layer::handleLastTouch2()
{
	bool wasPressed = isPressed2;



	if (wasPressed)
	{
		this->resetJoystick2();
		isPressed2 = false;
	}
	return (wasPressed ? true : false);
}

void Stage1_Layer::tick(float)
{

	if (player->getPosition().x > 1000 && player->getPosition().x < 1100 && player->getPosition().y > 480 ) // 오른쪽문
	{
		auto nowPlayerStage = (Stage1*)(player->nowStage);
		auto nextPlayerStage = ((Stage1*)(player->nowStage))->next;
		if (nowPlayerStage->next->initComplete == false)
		{
			
			//-----------플레이어의 현재 스테이지를 바꾸고 현재스테이지는 제거한다.
			player->nowStage = nextPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);
			nextPlayerStage->player = player;

			//-----------플레이어의 포지션을 정하고 다음 스테이지를 불러온다.
			player->setPosition(Vec2(450, 450));
			this->addChild(nextPlayerStage);
			nextPlayerStage->init();
			nextPlayerStage->addChild(player);
		}
		else
		{
			//------------현재 스테이지 제거
			player->nowStage = nextPlayerStage;
			nowPlayerStage->removeChild(player,false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);

			//------------다음 스테이지 불러옴
			player->setPosition(Vec2(450, 450));
			nextPlayerStage->addChild(player);
			nextPlayerStage->createPlayer(player);
			this->addChild(nextPlayerStage);
			

		}
		

	}
	else if (player->getPosition().x > 400 && player->getPosition().x < 500 && player->getPosition().y > 480 ) // 왼쪽문
	{
		auto nowPlayerStage = (Stage1*)(player->nowStage);
		auto prevPlayerStage = ((Stage1*)(player->nowStage))->prev;
		if (nowPlayerStage->next->initComplete == false)
		{

			//-----------플레이어의 현재 스테이지를 바꾸고 현재스테이지는 제거한다.
			player->nowStage = prevPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);
			prevPlayerStage->player = player;

			//-----------플레이어의 포지션을 정하고 다음 스테이지를 불러온다.
			player->setPosition(Vec2(1050, 450));
			this->addChild(prevPlayerStage);
			prevPlayerStage->init();
			prevPlayerStage->addChild(player);
		}
		else
		{
			//------------현재 스테이지 제거
			player->nowStage = prevPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);

			//------------다음 스테이지 불러옴
			player->setPosition(Vec2(1050, 450));
			prevPlayerStage->addChild(player);
			prevPlayerStage->createPlayer(player);
			this->addChild(prevPlayerStage);


		}
		
		

	}

}


void Stage1_Layer::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Stage1_Layer::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Stage1_Layer::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Stage1_Layer::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(Stage1_Layer::onTouchesCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Stage1_Layer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{
		
		auto touch = item;
		
		Vec2 point = touch->getLocationInView();
		Vec2 touchPoint = Director::getInstance()->convertToGL(point);


		if (isPointInCircle(touchPoint, kCenter1, JOYSTICK_RADIUS) )
		{
			isPressed1 = true;
			touchNum.push_back(touch->getID());
			joyNum[touch->getID()]=1;
			
			this->updateVelocity1(touchPoint);
			
		}
		if (isPointInCircle(touchPoint, kCenter2, JOYSTICK_RADIUS))
		{
			isPressed2 = true;
			touchNum.push_back(touch->getID());
			joyNum[touch->getID()] = 2;
			
			this->updateVelocity2(touchPoint);
		}
		
	}



}

void Stage1_Layer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{
		
		auto touch = item;

		

		if (isPressed1 && joyNum[touch->getID()] == 1)
		{
			
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);

			this->updateVelocity1(touchPoint);
			
		}
		if (isPressed2 && joyNum[touch->getID()] == 2)
		{
			
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);

			this->updateVelocity2(touchPoint);
			
		}
		
		
	
	}


}

void Stage1_Layer::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{
		auto touch = item;

		if (isPressed1 && joyNum[touch->getID()] == 1)
		{
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);
			this->handleLastTouch1();
			joyNum[touch->getID()] = 10;
			
		}
		if (isPressed2 && joyNum[touch->getID()] == 2)
		{
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);
			this->handleLastTouch2();
			joyNum[touch->getID()] = 10;
			
		}


		


	}
	
}
