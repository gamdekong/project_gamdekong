#pragma once
#include "cocos2d.h"
#include "Joystick.h"
#include "Player.h"
#include "BackgroundLayer.h"
#include "HelloWorldScene.h"
#include "ControlManager.h"
#include "Entity.h"

#define PTM_RATIO 32


using namespace cocos2d;

class JoyLayer : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(JoyLayer);

	void TouchesBegan(const std::vector<Touch*>& touches, Event *event);
	void TouchesMoved(const std::vector<Touch*>& touches, Event *event);
	void TouchesEnded(const std::vector<Touch*>& touches, Event *event);
	void Update(float deltaTime);

	b2World *_world;
	Joystick *joystick1;
	Joystick *joystick2;
	Player *player;
	Sprite *pSprite;
	b2Body *playerBody;
	BackgroundLayer *bgLayer;
	Layer *joyLayer;
	int count = 0;


};
