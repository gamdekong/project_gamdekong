#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Joystick.h"
#include "Player.h"
#include "BackgroundLayer.h"

#define JOYSTICK_OFFSET_X 5.0f
#define JOYSTICK_OFFSET_Y 5.0f

#define JOYSTICK_RADIUS 64.0f
#define THUMB_RADIUS 40.0f  //레버가 움직이는 범위

#define PTM_RATIO 32
//#define SHORT_ATTACK 1
//#define RIGHT_LONG_ATTACK 2
//#define LEFT_LONG_ATTACK 3

using namespace cocos2d;



class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
   
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	
	//b2World *_world;
	Joystick *joystick1;
	Joystick *joystick2;
	vector<int> touchNum;
	//vector<int> joyNum;
	int joyNum[5] = { 10 };
	//Player *player;
	//Sprite *pSprite;
	//b2Body *playerBody;
	BackgroundLayer *bgLayer;
	Layer *joyLayer;
	int count = 0;
	

	Vec2 kCenter1, kCenter2;
	Sprite* thumb1, *thumb2;
	bool isPressed1,isPressed2;

	Vec2 velocity1, velocity2;
	

	void updateVelocity1(Vec2 point);
	void updateVelocity2(Vec2 point);
	void resetJoystick1();
	void resetJoystick2();
	bool handleLastTouch1();
	bool handleLastTouch2();




	void onEnter();
	virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	//virtual void onTouchesCancelled(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);

};



#endif // __HELLOWORLD_SCENE_H__
