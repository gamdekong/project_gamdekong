#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Joystick.h"

#define PTM_RATIO 32

using namespace cocos2d;

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
   
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	~HelloWorld();
	void onEnter();
	void onExit();
	void tick(float);
	void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

	//bool onTouchBegan(Touch *touch, Event *event);
	void addNewSpriteAtPosition(Vec2);
	bool createWorld(bool);
	
	b2World *_world;
	Joystick *joystick1;
	Joystick *joystick2;
	Sprite *pSprite;
	b2Body *playerBody;
	

	/////Texture
	Texture2D *texture;
	Texture2D *playerMoveTexture;
	Texture2D *playerAttackTexture;
	Texture2D *playerIdleTexture;
	Texture2D *playerDeadTexture;

	


	//for debugging
	GLESDebugDraw *m_debugDraw;
};

#endif // __HELLOWORLD_SCENE_H__
