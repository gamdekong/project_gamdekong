#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Joystick.h"
#include "Player.h"
#include "BackgroundLayer.h"

#define PTM_RATIO 32


using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
   
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	
	
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

#endif // __HELLOWORLD_SCENE_H__
