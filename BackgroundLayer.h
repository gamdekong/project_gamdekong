#ifndef __BackgroundLayer_SCENE_H__
#define __BackgroundLayer_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Joystick.h"
#include "Player.h"

#define PTM_RATIO 32


using namespace cocos2d;

class BackgroundLayer : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(BackgroundLayer);

	~BackgroundLayer();
	void onEnter();
	void onExit();
	void tick(float);
	void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

	//bool onTouchBegan(Touch *touch, Event *event);
	bool createWorld(bool);
	void createPlayer(Sprite *player);
	void createBackground();

	b2World *_world;
	Joystick *joystick1;
	Joystick *joystick2;
	Player *player;
	Sprite *pSprite;
	b2Body *playerBody;
	
	int count = 0;


	//for debugging
	GLESDebugDraw *m_debugDraw;
};

#endif // __BackgroundLayer_SCENE_H__
