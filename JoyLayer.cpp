#include "JoyLayer.h"

USING_NS_CC;

Scene* JoyLayer::createScene()
{

	auto scene = Scene::create();
	auto layer = JoyLayer::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool JoyLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}


	auto listener = EventListenerTouchAllAtOnce::create();
	// Swallow touches only available in OneByOne mode.
	// �ڵ鸵�� ��ġ �̺�Ʈ�� ��ġ �̺�Ʈ array���� ����ڴٴ� �ǹ��̴�.

	listener->onTouchesBegan = CC_CALLBACK_2(JoyLayer::TouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(JoyLayer::TouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(JoyLayer::TouchesEnded, this);

	// The priority of the touch listener is based on the draw order of sprite
	// ��ġ�������� �켱������ (��尡) ȭ�鿡 �׷��� ������� �Ѵ�.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	

	JControlManager::getInstance();
	JControlManager::getInstance()->Initialize(this);//this ���̾ ����

	schedule(schedule_selector(JoyLayer::Update), 1.f / 60.f);



	////////////////////////////////////////////////////////////////////////////////////////////////



	joystick1 = new Joystick();
	joystick1->joyNum = 0;
	joystick1->init();

	//joystick2 = new Joystick();
	//joystick2->joyNum = 1;
	//joystick2->init();


	this->addChild(joystick1);
	//joyLayer->addChild(joystick2);

	//this->addChild(joyLayer, 1);

	bgLayer = new BackgroundLayer();
	bgLayer->joystick1 = joystick1;
	//bgLayer->joystick2 = joystick2;
	bgLayer->init();


	//bgLayer = new BackgroundLayer();
	//bgLayer->init();
	//bgLayer->player = player;
	//
	////�÷��̾� ����
	//
	//
	//bgLayer->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));

	//
	////----���̽�ƽ ����


	return true;
}


void JoyLayer::Update(float deltaTime)
{
	JControlManager::getInstance()->Update(deltaTime);

	if (JControlManager::getInstance()->GetDistance() == 0.f)
	{

	}
	else
	{
		float distance = JControlManager::getInstance()->GetDistance() * 0.5f + 0.5f;
		float speed = distance * 100.f *deltaTime;
		Vec2 axis = JControlManager::getInstance()->GetAxis();
		auto velocity = axis * speed;

//		pMan->setPosition(pMan->getPosition() + velocity);

		if (axis.x < 0.f)
		{
			//			dir_LEFT;
		}
		else if (axis.x > 0.f)
		{
			//			dir_ = RIGHT;
		}
	}
}

void JoyLayer::TouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto &item : touches)
	{
		auto touch = item;
		point = touch->getLocationInView();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; a++)
		{
			if (JControlManager::getInstance()->IsButtonContainsPoint((eButtonID)a, touchGlPoint))
			{
				JControlManager::getInstance()->btnTouchID_[a] = touch;
				JControlManager::getInstance()->btnState_[a] = BEGIN;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;

			}
		}
	}
	JControlManager::getInstance()->SetTouchState(BEGIN);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}

void JoyLayer::TouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto &item : touches)
	{
		auto touch = item;
		point = touch->getLocationInView();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; a++)
		{
			if (touch == JControlManager::getInstance()->btnTouchID_[a])
			{
				JControlManager::getInstance()->btnState_[a] = MOVE;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;

			}
		}
	}
	JControlManager::getInstance()->SetTouchState(MOVE);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);

}

void JoyLayer::TouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto &item : touches)
	{
		auto touch = item;
		point = touch->getLocationInView();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; a++)
		{
			if (touch == JControlManager::getInstance()->btnTouchID_[a])
			{
				JControlManager::getInstance()->btnState_[a] = END;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;

			}
		}
	}
	JControlManager::getInstance()->SetTouchState(END);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}
