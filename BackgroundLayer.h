#ifndef __BackgroundLayer_SCENE_H__
#define __BackgroundLayer_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Joystick.h"
#include "Player.h"
#include "Monster.h"

#define PTM_RATIO 32
#define GROUP_INDEX_PLAYER -10
#define GROUP_INDEX_MONSTER 10


#define CATEGORY_PLAYER 0x0001
#define CATEGORY_MONSTER 0x0002
#define CATEGORY_GROUND 0x0003


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
	void createMonster(Sprite *monster);
	void createBackground();

	b2World *_world;
	Joystick *joystick1;
	Joystick *joystick2;
	Player *player;
	Monster *monster;
	Sprite *pSprite;
	b2Body *playerBody;
	b2Body *monsterBody;
	
	int count = 0;


	//for debugging
	GLESDebugDraw *m_debugDraw;
};

#endif // __BackgroundLayer_SCENE_H__
