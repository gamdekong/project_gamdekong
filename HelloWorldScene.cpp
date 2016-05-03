﻿#include "HelloWorldScene.h"

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
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }

	//----------------배경	
	auto bg = Sprite::create("stage/stage-1.png");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 100));
	//this->addChild(bg);

	//----------------플레이어 텍스쳐
	playerMoveTexture = Director::getInstance()->getTextureCache()->addImage("player/move/move.png");
	playerAttackTexture = Director::getInstance()->getTextureCache()->addImage("player/attack/attack.png");
	playerIdleTexture = Director::getInstance()->getTextureCache()->addImage("player/idle/idle.png");
	playerDeadTexture = Director::getInstance()->getTextureCache()->addImage("player/dead/dead.png");

	pSprite = Sprite::createWithTexture(playerIdleTexture, Rect(0, 0, 160, 160));
	this->addChild(pSprite);
	pSprite->setPosition(Vec2(300, 200));

	
	//--------이동	
	auto animation1 = Animation::create();
	animation1->setDelayPerUnit(0.1);
	for (int i = 0; i < 6; i++)
	{
		int column = i % 6;

		animation1->addSpriteFrameWithTexture(playerMoveTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate1 = Animate::create(animation1);

	auto seq1 = Sequence::create(animate1, nullptr);
	auto playerMoveSeq = RepeatForever::create(seq1);

	pSprite->runAction(playerMoveSeq);

	//--------휴식
	auto animation2 = Animation::create();
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;

		animation2->addSpriteFrameWithTexture(playerIdleTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate2 = Animate::create(animation2);

	auto seq2 = Sequence::create(animate2, nullptr);
	auto playerIdleSeq = RepeatForever::create(seq2);


	//---------공격
	auto animation3 = Animation::create();
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;

		animation3->addSpriteFrameWithTexture(playerAttackTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate3 = Animate::create(animation3);

	auto seq3 = Sequence::create(animate3, nullptr);
	auto playerAttackSeq = RepeatForever::create(seq3);

	//----------죽음
	auto animation4 = Animation::create();
	for (int i = 0; i < 6; i++)
	{
		int column = i % 6;

		animation4->addSpriteFrameWithTexture(playerDeadTexture, Rect(160 * column, 0, 160, 160));
	}

	auto animate4 = Animate::create(animation4);

	auto seq4 = Sequence::create(animate4, nullptr);
	auto playerDeadSeq = RepeatForever::create(seq4);



	//-------------월드 생성
	if (this->createWorld(true))
		this->schedule(schedule_selector(HelloWorld::tick));

	
	
	//--------------플레이어 바디생성
	b2BodyDef playerBodyDef;
	playerBodyDef.type = b2_dynamicBody;
	playerBodyDef.position.Set(pSprite->getPosition().x / PTM_RATIO, pSprite->getPosition().y / PTM_RATIO);
	playerBodyDef.linearDamping = 20;
	playerBodyDef.userData = pSprite;
	

	playerBody = _world->CreateBody(&playerBodyDef);
	
	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);
	
	b2PolygonShape playerPolygon;
	playerPolygon.SetAsBox((pSprite->getContentSize().width / 2) / PTM_RATIO, (pSprite->getContentSize().height / 2) / PTM_RATIO);

	b2FixtureDef playerFixtureDef;
	playerFixtureDef.shape = &playerPolygon;
	playerFixtureDef.density = 0.0f;
	
	playerBody->CreateFixture(&playerFixtureDef);


	//----조이스틱 생성
	joystick1 = Joystick::create();
	this->addChild(joystick1);
	joyNum = 1;

	joystick2 = Joystick::create();
	this->addChild(joystick2);
	

   
    return true;
}

bool HelloWorld::createWorld(bool debug)
{
	//월드 생성 시작

	b2Vec2 gravity = b2Vec2(0.0f, .0f);

	//월드를 생성한다.
	_world = new b2World(gravity);

	//휴식 상태일 때 포함된 바디들을 멈추게(sleep)할 것인지 결정한다
	_world->SetAllowSleeping(true);

	//지속적인 물리작용을 할 것인지 결정한다. :테스트
	_world->SetContinuousPhysics(true);


	if (debug)
	{
		//적색 : 현재 물리 운동을 하는 것
		//회색 : 현재 물리 운동량이 없는 것
		m_debugDraw = new GLESDebugDraw(PTM_RATIO);
		_world->SetDebugDraw(m_debugDraw);

		uint32 flags = 0;

		flags += b2Draw::e_shapeBit;

		m_debugDraw->SetFlags(flags);
	}




	//가장자리(테두리)를 지정해 공간(Ground Box)을 만든다.

	//바디데프에 좌표를 설정한다.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	//월드에 바디데프의 정보(좌표)로 바디를 만든다.
	b2Body *groundBody = _world->CreateBody(&groundBodyDef);

	//가장 자리(테두리) 경계선을 그릴수 있는 모양의 객체를 만든다.

	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;

	//에지 모양의 객체에 Set(점1, 점2)선을 만든다.
	//그리고 바디(groundBody)에 모양(groundEdge)을 고정시킨다.

	//왼쪽
	groundEdge.Set(b2Vec2(0, 100/PTM_RATIO), b2Vec2(200/ PTM_RATIO, 400/PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//아래쪽
	groundEdge.Set(b2Vec2(0, 100/PTM_RATIO), b2Vec2(1500/PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//위쪽
	groundEdge.Set(b2Vec2(200/PTM_RATIO, 400 / PTM_RATIO), b2Vec2(1300/ PTM_RATIO, 400 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//오른쪽
	groundEdge.Set(b2Vec2(1300 / PTM_RATIO, 400 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 100/PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//월드 생성 끝-----------------------
	this->schedule(schedule_selector(HelloWorld::tick));

	return true;
}


HelloWorld::~HelloWorld()
{
	delete _world;
	_world = nullptr;

}


void HelloWorld::onEnter()
{
	Layer::onEnter();

}

void HelloWorld::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Layer::onExit();
}


void HelloWorld::draw(Renderer * renderer, const Mat4 & transform, uint32_t flags)
{
	//Layer::draw();
	Layer::draw(renderer, transform, flags);
GL:ccGLEnableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);

	kmGLPushMatrix();
	_world->DrawDebugData();
	kmGLPopMatrix();


}

void HelloWorld::tick(float dt)
{
	//물리적 위치를 이용해 그래픽 위치는 갱신한다.

	//velocityIterations : 바디들을 정상적으로 이동시키기 위해 필요한 충돌들을
	//반복적으로 계산
	//positionIterations : 조인트 분리와 겹침 현상을 줄이기 위해 바디의 위치를
	//반복적으로 적용
	//값이 클수록 정확한 연산이 가능하지만 성능이 떨어진다.

	//메뉴얼 상의 권장값
	int velocityIterations = 8;
	int positionIterations = 3;

	//Step : 물리 세계를 시뮬레이션한다.
	_world->Step(dt, velocityIterations, positionIterations);
	//모든 물리 객체들은 링크드 리스트에 저장되어 참조해 볼수 있게 구현돼 있다.
	//만들어진 객체만큼 루프를 돌리면서 바디에 붙인 스프라이트를 여기서 제어한다.
	for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite *spriteData = (Sprite*)b->GetUserData();
			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO));
			spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));

			float vx = joystick1->getVelocity().x * 5;//스피드
			float vy = joystick1->getVelocity().y * 5;
			log("%f %f", vx, vy);
			log("%f", b->GetLinearVelocity());
			//set ball velocity by Joystick
			b->SetLinearVelocity(b2Vec2(vx, vy) + (b->GetLinearVelocity()));
			
		}
		if (!joystick1->getisPressed())
			playerBody->SetLinearVelocity(b2Vec2(0, 0));
	}
	if (joystick1->getVelocity().x < 0)
		pSprite->setFlippedX(true);
	else
		pSprite->setFlippedX(false);

}


void HelloWorld::addNewSpriteAtPosition(Vec2 location)
{
	//스프라이트를 파라미터로 넘어온 위치에 만든다.
	Sprite *pSprite = Sprite::createWithTexture(texture, Rect(0, 0, 37, 37));
	pSprite->setPosition(Vec2(location.x, location.y));
	pSprite->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(pSprite);

	//바디데프를 만들고 속성들을 지정한다.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);



	//유저데이터에 스프라이트를 붙인다.
	bodyDef.userData = pSprite;



	//월드에 바디데프의 정보로 바디를 만든다.
	b2Body *body = _world->CreateBody(&bodyDef);

	//바디에 적용할 물리 속성용 바디의 모양을 만든다.
	//원형태를 선택해 반지름을 지정한다.
	b2CircleShape circle;
	circle.m_radius = 0.3f;

	//그리고 바디에 모양을(circle)을 고정시킨다.

	b2FixtureDef fixtureDef;

	//모양을 지정한다.
	fixtureDef.shape = &circle;

	//밀도
	fixtureDef.density = 1.0;

	//마찰력 0~1
	fixtureDef.friction = 0.2;

	//반발력 
	fixtureDef.restitution = 0.2f;

	body->CreateFixture(&fixtureDef);
}