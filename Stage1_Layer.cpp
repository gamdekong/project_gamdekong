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
	srand((unsigned)time(nullptr));

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
	kCenter1 = Vec2(150,120	);
	
	velocity1 = Vec2::ZERO;

	Sprite* bg1 = Sprite::create("joystick_background.png");
	bg1->setPosition(kCenter1);
	this->addChild(bg1, 2);

	thumb1 = Sprite::create("joystick_thumb.png");
	thumb1->setPosition(kCenter1);
	this->addChild(thumb1, 3);

	auto upBar = Sprite::create("ui/bar.png");
	upBar->setPosition(Vec2(winsize.width / 2, winsize.height));
	upBar->setAnchorPoint(Vec2(0.5, 1));
	this->addChild(upBar, 1);

	auto downBar = Sprite::create("ui/bar.png");
	downBar->setPosition(Vec2(winsize.width / 2, 0));
	downBar->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(downBar, 1);

	auto itemBox = MenuItemImage::create("ui/itemBox.png", "ui/itemBox.png", CC_CALLBACK_1(Stage1_Layer::ItemUse, this));
	auto pItemMenu = Menu::create(itemBox, nullptr);
	pItemMenu->setPosition(Vec2(winsize.width - 80, winsize.height - 80));
	this->addChild(pItemMenu,3);

	auto energy = Sprite::create("ui/meter-06.png");
	energy->setPosition(Vec2(upBar->getContentSize().height / 2, 50));
	energy->setAnchorPoint(Vec2( 0, 0.5));
	upBar->addChild(energy);



	// 조이스틱 2
	kCenter2 = Vec2(winsize.width - 150, 120);


	velocity2 = Vec2::ZERO;

	Sprite* bg2 = Sprite::create("joystick_background.png");
	bg2->setPosition(kCenter2);
	this->addChild(bg2, 1);

	thumb2 = Sprite::create("joystick_thumb.png");
	thumb2->setPosition(kCenter2);
	this->addChild(thumb2, 2);

	player = new Player();
	
	this->MakeMap();

	//auto bgLayer1 = new Stage1();//생성자 넣기
	//bgLayer1->stageNum=1;
	//bgLayer1->joystickVelocity1 = &velocity1;
	//bgLayer1->joystickVelocity2 = &velocity2;
	//bgLayer1->joystickIspressed1 = &isPressed1;
	//bgLayer1->joystickIspressed2 = &isPressed2;
	//bgLayer1->player = player;
	//bgLayer1->addChild(player);
	//bgLayer1->init();


	//---------------------------------------------------------------------

	stage.at(0)->init();
	this->addChild(stage.at(0), 0);
   
	this->schedule(schedule_selector(Stage1_Layer::tick));
    return true;
}


static bool isPointInCircle(Vec2 point, Vec2 center, float radius)
{
	float dx = (point.x - center.x);
	float dy = (point.y - center.y);
	return (radius >= sqrt((dx*dx) + (dy*dy)));
}

void Stage1_Layer::MakeMap()
{
	//-----------------스테이지 객체 생성------------------

	auto bgLayer1 = new Stage1();//생성자 넣기
	bgLayer1->joystickVelocity1 = &velocity1;
	bgLayer1->joystickVelocity2 = &velocity2;
	bgLayer1->joystickIspressed1 = &isPressed1;
	bgLayer1->joystickIspressed2 = &isPressed2;
	bgLayer1->player = player;
	bgLayer1->addChild(player);
	

	auto bgLayer2 = new Stage1();
	bgLayer2->joystickVelocity1 = &velocity1;
	bgLayer2->joystickVelocity2 = &velocity2;
	bgLayer2->joystickIspressed1 = &isPressed1;
	bgLayer2->joystickIspressed2 = &isPressed2;

	auto bgLayer3 = new Stage1();
	bgLayer3->joystickVelocity1 = &velocity1;
	bgLayer3->joystickVelocity2 = &velocity2;
	bgLayer3->joystickIspressed1 = &isPressed1;
	bgLayer3->joystickIspressed2 = &isPressed2;

	auto bgLayer4 = new Stage1();
	bgLayer4->joystickVelocity1 = &velocity1;
	bgLayer4->joystickVelocity2 = &velocity2;
	bgLayer4->joystickIspressed1 = &isPressed1;
	bgLayer4->joystickIspressed2 = &isPressed2;

	auto bgLayer5 = new Stage1();
	bgLayer5->joystickVelocity1 = &velocity1;
	bgLayer5->joystickVelocity2 = &velocity2;
	bgLayer5->joystickIspressed1 = &isPressed1;
	bgLayer5->joystickIspressed2 = &isPressed2;

	auto bgLayer6 = new Stage1();
	bgLayer6->joystickVelocity1 = &velocity1;
	bgLayer6->joystickVelocity2 = &velocity2;
	bgLayer6->joystickIspressed1 = &isPressed1;
	bgLayer6->joystickIspressed2 = &isPressed2;

	auto bgLayer7 = new Stage1();
	bgLayer7->joystickVelocity1 = &velocity1;
	bgLayer7->joystickVelocity2 = &velocity2;
	bgLayer7->joystickIspressed1 = &isPressed1;
	bgLayer7->joystickIspressed2 = &isPressed2;

	auto bgLayer8 = new Stage1();
	bgLayer8->joystickVelocity1 = &velocity1;
	bgLayer8->joystickVelocity2 = &velocity2;
	bgLayer8->joystickIspressed1 = &isPressed1;
	bgLayer8->joystickIspressed2 = &isPressed2;

	auto bgLayer9 = new Stage1();
	bgLayer9->joystickVelocity1 = &velocity1;
	bgLayer9->joystickVelocity2 = &velocity2;
	bgLayer9->joystickIspressed1 = &isPressed1;
	bgLayer9->joystickIspressed2 = &isPressed2;

	auto bgLayer10 = new Stage1();
	bgLayer10->joystickVelocity1 = &velocity1;
	bgLayer10->joystickVelocity2 = &velocity2;
	bgLayer10->joystickIspressed1 = &isPressed1;
	bgLayer10->joystickIspressed2 = &isPressed2;
	//-------------------------------백터에 스테이지 넣기------------------

	player->nowStage = bgLayer1;

	stage.push_back(bgLayer1);
	stage.push_back(bgLayer2);
	stage.push_back(bgLayer3);
	stage.push_back(bgLayer4);
	stage.push_back(bgLayer5);
	stage.push_back(bgLayer6);
	stage.push_back(bgLayer7);
	stage.push_back(bgLayer8);
	stage.push_back(bgLayer9);
	stage.push_back(bgLayer10);
	
	
	
	//던전 넘버 설정
	for (int i = 0; i < stage.size(); i++)
	{
		stage.at(i)->stageNum = i;

	}

	while (1)
	{
		int num = rand() % (stage.size() - 2) + 1;  // 1~4
		if (check[num] != 0)
			continue;
		else
		{
			stage.at(0)->prev = stage.at(num);
			check[num]++;
			break;
		}
	}
	while (1)
	{
		int num = rand() % (stage.size() - 2) + 1;  // 1~4
		if (check[num] != 0)
			continue;
		else
		{
			stage.at(0)->next = stage.at(num);
			check[num]++;
			break;
		}
	}

	int num = (stage.size() - 2) / 2;
	this->MakeMapRamdom(stage.at(0)->prev, stage.at(0), num, true);  //prev
	this->MakeMapRamdom(stage.at(0)->next, stage.at(0), num, false);  //next


	log("Map Make Done");
}
void Stage1_Layer::MakeMapRamdom(Stage1 *nowStage, Stage1 *preStage, int num, bool state)
{
	num--;
	if (num == 0)
	{
		if (state == true)
		{
			nowStage->next = preStage;
		}
		else if (state == false)
		{
			nowStage->prev = preStage;
		}
		if (rand() % 2 == 0 && check[stage.size() - 1] != 1)
		{
			if (state == true)
			{
				nowStage->prev = stage.at(stage.size() - 1);
				stage.at(stage.size() - 1)->next = nowStage;
			}
			else
			{
				nowStage->next = stage.at(stage.size() - 1);
				stage.at(stage.size() - 1)->prev = nowStage;
			}

			check[stage.size() - 1]++;

		}
		else if (rand() % 2 == 1 && check[stage.size() - 1] != 1)
		{
			if (state == true)
			{
				nowStage->prev = stage.at(stage.size() - 1);
				stage.at(stage.size() - 1)->next = nowStage;
			}
			else
			{
				nowStage->next = stage.at(stage.size() - 1);
				stage.at(stage.size() - 1)->prev = nowStage;
			}
			check[stage.size() - 1]++;

		}
		return;

	}

	if (state == true)
	{
		nowStage->next = preStage;
		while (1)
		{
			int num = rand() % (stage.size() - 2) + 1;  // 1~4
			if (check[num] != 0)
				continue;
			else
			{
				nowStage->prev = stage.at(num);
				check[num]++;
				break;
			}
		}
		this->MakeMapRamdom(nowStage->prev, nowStage, num, true);

	}
	else if (state == false)
	{
		nowStage->prev = preStage;
		while (1)
		{
			int num = rand() % (stage.size() - 2) + 1;  // 1~4
			if (check[num] != 0)
				continue;
			else
			{
				nowStage->next = stage.at(num);
				check[num]++;
				break;
			}
		}
		this->MakeMapRamdom(nowStage->next, nowStage, num, false);

	}

}

void Stage1_Layer::updateVelocity1(Vec2 point)
{
	// calculate Angle and length
	float dx = point.x - kCenter1.x;
	float dy = point.y - kCenter1.y;

	float distance = sqrt(dx*dx + dy*dy);
	float angle = atan2(dy, dx); // in radians

	if (dx != 0 && dy != 0)
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

void Stage1_Layer::tick(float dt)
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
		if (nowPlayerStage->prev->initComplete == false)
		{

			//-----------플레이어의 현재 스테이지를 바꾸고 현재스테이지는 제거한다.
			player->nowStage = prevPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);
			prevPlayerStage->player = player;

			//-----------플레이어의 포지션을 정하고 다음 스테이지를 불러온다.
			player->setPosition(Vec2(1050, 430));
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
			player->setPosition(Vec2(1050, 430));
			prevPlayerStage->addChild(player);
			prevPlayerStage->createPlayer(player);
			this->addChild(prevPlayerStage);


		}
		
		

	}

}

void Stage1_Layer::ItemUse(Ref * p)
{
	log("item click");
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
