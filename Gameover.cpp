#include "Gameover.h"

USING_NS_CC;

Scene* Gameover::createScene()
{

	auto scene = Scene::create();
	auto layer = Gameover::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Gameover::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	auto winSize = Director::getInstance()->getWinSize();

	auto gameOver = LabelTTF::create("Game Over", "Arial", 60);
	gameOver->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	gameOver->setColor(Color3B(255, 255, 255));
	this->addChild(gameOver);
	


	return true;
}

void Gameover::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Gameover::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Gameover::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Gameover::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(Gameover::onTouchesCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Gameover::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
}

void Gameover::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
}

void Gameover::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	
		auto pScene = LobbyLayer::createScene();

		Director::getInstance()->replaceScene(TransitionFade::create(0.5, pScene));
	
}
