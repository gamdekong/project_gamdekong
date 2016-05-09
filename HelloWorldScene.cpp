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


	//player = new Player();
	//this->addChild(player,1);
	//this->runAction(Follow::create(player,Rect(0, 0,1500, 720)));

	joyLayer = Layer::create();

	joystick1 = new Joystick();
	joystick1->joyNum = 0;
	joystick1->init();

	joystick2 = new Joystick();
	joystick2->joyNum = 1;
	joystick2->init();
	

	joyLayer->addChild(joystick1);
	joyLayer->addChild(joystick2);
	this->addChild(joyLayer,1);

	bgLayer = new BackgroundLayer();
	bgLayer->joystick1 = joystick1;
	bgLayer->joystick2 = joystick2;
	//bgLayer->player = player;
	bgLayer->init();
	

	this->addChild(bgLayer,0);

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
	

   
    return true;
}