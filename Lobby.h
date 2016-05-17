#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Player.h"
#include "Monster.h"
#include "SwordMissile.h"
#include "ContactListener.h"
#include "Stage1_Layer.h"


#define PTM_RATIO 32
#define GROUP_INDEX_PLAYER -10
#define GROUP_INDEX_MONSTER 10
#define RIGHTLONGATTACK 100
#define LEFTLONGATTACK 200


#define CATEGORY_PLAYER 0x0001
#define CATEGORY_MONSTER 0x0002
#define CATEGORY_GROUND 0x0003
#define CATEGORY_MISSILE 0x0004


using namespace cocos2d;
using namespace std;

class Lobby : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Lobby);

	
	void tick(float);
	void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

	//bool onTouchBegan(Touch *touch, Event *event);
	bool createWorld(bool);
	void createPlayer(Sprite *player);
	void createMonster(Sprite *monster);
	
	void createBackground();
	
	void LongAttack(int num);
	void RightLongAttack(float);
	void LeftLongAttack(float);
	void clearTime(float);
	

	b2World *_world;
	int tCount = 0;
	Size winSize;
	//Joystick *joystick1;
	//Joystick *joystick2;
	Vec2 *joystickVelocity1, *joystickVelocity2;
	bool *joystickIspressed1, *joystickIspressed2;
	Player *player;
	//Sprite *pSprite;
	b2Body *playerBody;
	vector<b2Body*> missileBodyVector;
	vector<b2Body*> monsterBodyVector;
	ContactListener* myContactListener;
	int clickCount = 0;
	int count = 0;
	bool isAttacking;


	//for debugging
	GLESDebugDraw *m_debugDraw;
};