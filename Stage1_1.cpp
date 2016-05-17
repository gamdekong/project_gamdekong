#include "Stage1_1.h"

USING_NS_CC;

Scene* Stage1_1::createScene()
{

	auto scene = Scene::create();
	auto layer = Stage1_1::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Stage1_1::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	missileBodyVector.clear();
	monsterBodyVector.clear();


	//player = new Player();
	//this->addChild(player, 1);

	
	auto monster1 = new Monster(1);
	monster1->setPosition(Vec2(500, 200));
	this->addChild(monster1, 1);
	auto monster2 = new Monster(2);
	monster2->setPosition(Vec2(800, 300));
	this->addChild(monster2, 1);
	auto monster3 = new Monster(3);
	monster3->setPosition(Vec2(1000, 300));
	this->addChild(monster3, 1);
	auto monster4 = new Monster(4);
	monster4->setPosition(Vec2(500, 400));
	this->addChild(monster4, 1);
	auto monster5 = new Monster(5);
	monster5->setPosition(Vec2(1400, 300));
	this->addChild(monster5, 1);
	
	
	if (this->createWorld(true))
	{
		this->schedule(schedule_selector(Stage1_1::tick));
		myContactListener = new ContactListener(player);

		_world->SetContactListener((b2ContactListener*)myContactListener);
	}

	this->createPlayer(player);  //�ٵ� ����
	this->createMonster(monster1);
	this->createMonster(monster2);
	this->createMonster(monster3);
	this->createMonster(monster4);
	this->createMonster(monster5);

	this->createBackground();   //��� �̹��� ����
	this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�


	return true;
}

bool Stage1_1::createWorld(bool debug)
{
	//���� ���� ����

	b2Vec2 gravity = b2Vec2(0.0f, .0f);

	//���带 �����Ѵ�.
	_world = new b2World(gravity);

	//�޽� ������ �� ���Ե� �ٵ���� ���߰�(sleep)�� ������ �����Ѵ�
	_world->SetAllowSleeping(true);

	//�������� �����ۿ��� �� ������ �����Ѵ�. :�׽�Ʈ
	_world->SetContinuousPhysics(true);


	if (debug)
	{
		//���� : ���� ���� ��� �ϴ� ��
		//ȸ�� : ���� ���� ����� ���� ��
		m_debugDraw = new GLESDebugDraw(PTM_RATIO);
		_world->SetDebugDraw(m_debugDraw);

		uint32 flags = 0;

		flags += b2Draw::e_shapeBit;

		m_debugDraw->SetFlags(flags);
	}




	//�����ڸ�(�׵θ�)�� ������ ����(Ground Box)�� �����.

	//�ٵ����� ��ǥ�� �����Ѵ�.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	//���忡 �ٵ����� ����(��ǥ)�� �ٵ� �����.
	b2Body *groundBody = _world->CreateBody(&groundBodyDef);

	//���� �ڸ�(�׵θ�) ��輱�� �׸��� �ִ� ����� ��ü�� �����.

	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;
	boxShapeDef.filter.categoryBits = CATEGORY_GROUND;
	boxShapeDef.filter.maskBits = CATEGORY_MONSTER + CATEGORY_PLAYER;

	//���� ����� ��ü�� Set(��1, ��2)���� �����.
	//�׸��� �ٵ�(groundBody)�� ���(groundEdge)�� ������Ų��.

	//���� �����
	groundEdge.Set(b2Vec2(0, 240 / PTM_RATIO), b2Vec2(200 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//����
	groundEdge.Set(b2Vec2(0, 100 / PTM_RATIO), b2Vec2(0, 240 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//�Ʒ���
	groundEdge.Set(b2Vec2(0, 100 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//����1
	groundEdge.Set(b2Vec2(200 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1000 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);
	//����2
	groundEdge.Set(b2Vec2(1100 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1300 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//������ �����
	groundEdge.Set(b2Vec2(1300 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 240 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//������
	groundEdge.Set(b2Vec2(1500 / PTM_RATIO, 240 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//���� ���� ��-----------------------

	

	return true;
}

void Stage1_1::createPlayer(Sprite * player)
{
	
	//--------------�÷��̾� �ٵ����
	b2BodyDef playerBodyDef;
	playerBodyDef.type = b2_dynamicBody;
	playerBodyDef.position.Set(player->getPosition().x / PTM_RATIO, player->getPosition().y / PTM_RATIO);
	playerBodyDef.linearDamping = 20;
	playerBodyDef.userData = player;


	playerBody = _world->CreateBody(&playerBodyDef);

	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape playerPolygon;
	playerPolygon.SetAsBox((player->getContentSize().width /6) / PTM_RATIO, (player->getContentSize().height / 2) / PTM_RATIO);
	log(" %f ", (player->getContentSize().height / 2.5));

	b2FixtureDef playerFixtureDef;
	playerFixtureDef.shape = &playerPolygon;
	playerFixtureDef.density = 0.0f;
	playerFixtureDef.filter.groupIndex = GROUP_INDEX_PLAYER;
	playerFixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	playerFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	playerBody->CreateFixture(&playerFixtureDef);

}

void Stage1_1::createMonster(Sprite * monster)
{
	//--------------�÷��̾� �ٵ����
	b2BodyDef monsterBodyDef;
	monsterBodyDef.type = b2_dynamicBody;
	monsterBodyDef.position.Set(monster->getPosition().x / PTM_RATIO, monster->getPosition().y / PTM_RATIO);
	monsterBodyDef.linearDamping = 20;
	monsterBodyDef.userData = monster;


	auto monsterBody = _world->CreateBody(&monsterBodyDef);

	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape monsterPolygon;
	monsterPolygon.SetAsBox((monster->getContentSize().width / 3) / PTM_RATIO, (monster->getContentSize().height / 3) / PTM_RATIO);
	//log(" %f ", (monster->getContentSize().height / 2.5));

	b2FixtureDef monsterFixtureDef;
	monsterFixtureDef.shape = &monsterPolygon;
	monsterFixtureDef.density = 0.0f;
	monsterFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER;

	monsterBody->CreateFixture(&monsterFixtureDef);
	monsterBodyVector.push_back(monsterBody);
	auto mon = (Monster*)monster;
	mon->IdleAction();
}

void Stage1_1::createBackground()
{
	auto bg = Sprite::create("stage/stage-1.png");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 100));
	this->addChild(bg,0);

	auto door = Sprite::create("structure/door.png");
	door->setAnchorPoint(Vec2(0, 0));
	door->setPosition(Vec2(985, 390));
	this->addChild(door, 0);
}


Stage1_1::~Stage1_1()
{
	delete _world;
	_world = nullptr;

}


void Stage1_1::onEnter()
{
	Layer::onEnter();

}
//
//void Stage1_1::onExit()
//{
//	_eventDispatcher->removeAllEventListeners();
//	Layer::onExit();
//}


void Stage1_1::draw(Renderer * renderer, const Mat4 & transform, uint32_t flags)
{
	//Layer::draw();
	Layer::draw(renderer, transform, flags);
GL:ccGLEnableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);

	kmGLPushMatrix();
	_world->DrawDebugData();
	kmGLPopMatrix();


}

void Stage1_1::tick(float dt)
{
	//������ ��ġ�� �̿��� �׷��� ��ġ�� �����Ѵ�.

	//velocityIterations : �ٵ���� ���������� �̵���Ű�� ���� �ʿ��� �浹����
	//�ݺ������� ���
	//positionIterations : ����Ʈ �и��� ��ħ ������ ���̱� ���� �ٵ��� ��ġ��
	//�ݺ������� ����
	//���� Ŭ���� ��Ȯ�� ������ ���������� ������ ��������.

	//�޴��� ���� ���尪
	int velocityIterations = 8;
	int positionIterations = 3;

	//Step : ���� ���踦 �ùķ��̼��Ѵ�.
	_world->Step(dt, velocityIterations, positionIterations);
	//��� ���� ��ü���� ��ũ�� ����Ʈ�� ����Ǿ� ������ ���� �ְ� ������ �ִ�.
	//������� ��ü��ŭ ������ �����鼭 �ٵ� ���� ��������Ʈ�� ���⼭ �����Ѵ�.
	for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite *spriteData = (Sprite*)b->GetUserData();
			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO));
			spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));

			if (b->GetUserData() == player)
			{
				float vx = joystickVelocity1->x* 5;//���ǵ�
				float vy = joystickVelocity1->y * 5;
				//set ball velocity by Joystick
				b->SetLinearVelocity(b2Vec2(vx, vy) + (b->GetLinearVelocity()));

			}
			

		}
		

	}

	//for (vector<b2Body*>::iterator it = missileBodyVector.begin(); it != missileBodyVector.end(); it++)
	//{
	//	if ((*it)->GetUserData() == nullptr)
	//	{
	//		
	//		it
	//		//missileBodyVector.erase(it);
	//		_world->DestroyBody((*it));

	//	}

	//}

	//�̻��� �ٵ� ������ ���Ϳ����� �ٵ� ����
	for (int i = 0; i < missileBodyVector.size(); i++)
	{
	
		if (missileBodyVector[i]->GetUserData() == nullptr)
		{
			_world->DestroyBody(missileBodyVector[i]);
			missileBodyVector.erase(missileBodyVector.begin() + i);
			//log("%d", missileBodyVector.size());
		}
		//if (missileBodyVector.size() > 0)

			//log("%d", missileBodyVector.size());

	}




	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		if (monsterBodyVector[i]->GetUserData() == nullptr)
		{
			log("1%d", monsterBodyVector.size());

			_world->DestroyBody(monsterBodyVector[i]);
			log("2%d", monsterBodyVector.size());

			monsterBodyVector.erase(monsterBodyVector.begin() + i);
		}

	}
	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		Monster *monster = (Monster*)(monsterBodyVector[i]->GetUserData());

		//  �浹 ó��
		if (player->getPosition().y < monster->getPosition().y + 30 && player->getPosition().y > monster->getPosition().y -30)
		{
			//log("dddd");
			auto newFilter = new b2Filter();
			auto oldFilter = new b2Filter();
			*oldFilter = monsterBodyVector[i]->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter->maskBits = CATEGORY_PLAYER;
			monsterBodyVector[i]->GetFixtureList()->SetFilterData(*newFilter);
		}
		else
		{
			auto newFilter = new b2Filter();
			auto oldFilter = new b2Filter();
			*oldFilter = monsterBodyVector[i]->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter->maskBits = 200;
			monsterBodyVector[i]->GetFixtureList()->SetFilterData(*newFilter);

		}

		// ZOrder ó��
		if (player->getPosition().y > monster->getPosition().y + 30)
			player->setZOrder(monster->getZOrder() - 1);
		else if (player->getPosition().y < monster->getPosition().y + 30)
			player->setZOrder(monster->getZOrder() + 1);



	}


	// ĳ���� ���� ���� �κ�
	/*if (!joystickIspressed2 && joystick2->attack != 0)
	{
		if (joystick2->attack == SHORT_ATTACK)
		{
			player->stopAllActions();
			player->AttackAction();
			joystick2->attack = 0;

		}
		
	
	}*/


	if (joystickVelocity2->x > 0.9  )
	{
		LongAttack(RIGHTLONGATTACK);
		
	}
	else if (joystickVelocity2->x < -0.9)
	{
		LongAttack(LEFTLONGATTACK);
	}
				

	


	// ĳ���� �̵� ���� �κ�
	if (joystickVelocity1->x == 0 && joystickVelocity1->y == 0 && count == 0)
	{
		
		player->stopAllActions();
		player->IdleAction();
		count = 1;

	}
	else if (joystickVelocity1->x < 0)
	{
		//log("%f", joystick1->getVelocity().x);
		if (count == 1)
		{
			player->stopAllActions();
			player->MoveAction();
			count = 0;
		}
		player->setFlippedX(true);

	}
	else if (joystickVelocity1->x > 0)
	{
		//log("%f", joystick1->getVelocity().x);
		if (count == 1)
		{
			player->stopAllActions();
			player->MoveAction();
			count = 0;
		}
		player->setFlippedX(false);

	}

	//if (player->getPosition().x > 1000 && player->getPosition().x < 1100 && player->getPosition().y > 500 && tCount == 0)
	//{
	//	tCount++;
	//	auto pScene = Stage1_2Layer::createScene();

	//	Director::getInstance()->replaceScene(TransitionFade::create(0.1, pScene));
	//}

}

void Stage1_1::LongAttack(int num)
{
	switch (num)
	{
	case RIGHTLONGATTACK:
	
		if (!this->isScheduled(schedule_selector(Stage1_1::RightLongAttack)) &&
			!this->isScheduled(schedule_selector(Stage1_1::clearTime)))
		{
			this->RightLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Stage1_1::RightLongAttack)))
			this->scheduleOnce(schedule_selector(Stage1_1::RightLongAttack), player->attackSpeed);
		break;


	case LEFTLONGATTACK:
		if (!this->isScheduled(schedule_selector(Stage1_1::LeftLongAttack)) &&
			!this->isScheduled(schedule_selector(Stage1_1::clearTime)))
		{
			this->LeftLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Stage1_1::LeftLongAttack)))
			this->scheduleOnce(schedule_selector(Stage1_1::LeftLongAttack), player->attackSpeed);
		break;
	}
}

void Stage1_1::RightLongAttack(float dt)
{
	log("������ �˱�");

	SwordMissile *missile = new SwordMissile(1);
	missile->setPosition(Vec2(player->getPosition().x + 50.f, player->getPosition().y));
	missile->setFlipX(true);
	missile->setAnchorPoint(Vec2(0.8, 0.5));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(false);
	player->AttackAction();
	missile->startAction(missile->missileNum);
	//auto move = MoveBy::create(1.75f, Vec2(1500, 0));
	//missile->runAction(move);
	
	b2BodyDef missileBodyDef;
	missileBodyDef.type = b2_dynamicBody;
	missileBodyDef.position.Set((missile->getPosition().x) / PTM_RATIO, missile->getPosition().y / PTM_RATIO);
	missileBodyDef.linearDamping = 0;
	missileBodyDef.userData = missile;
	
	auto missileBody = _world->CreateBody(&missileBodyDef);
	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);
	b2PolygonShape missilePolygon;
	missilePolygon.SetAsBox((missile->getContentSize().width / 30) / PTM_RATIO, (missile->getContentSize().height / 3) / PTM_RATIO);

	b2FixtureDef missileFixtureDef;
	missileFixtureDef.shape = &missilePolygon;
	missileFixtureDef.density = 0.0f;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	//monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	//monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER;
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(10, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Stage1_1::clearTime), player->attackSpeed);

}
void Stage1_1::LeftLongAttack(float dt)
{
	log("���� �˱�");

	SwordMissile *missile = new SwordMissile(1);
	missile->setPosition(Vec2(player->getPosition().x - 50.f, player->getPosition().y));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(true);
	missile->setAnchorPoint(Vec2(0.2, 0.5));
	player->AttackAction();
	missile->startAction(missile->missileNum);
	

	//auto move = MoveBy::create(1.75f, Vec2(1500, 0));
	//missile->runAction(move);

	b2BodyDef missileBodyDef;
	missileBodyDef.type = b2_dynamicBody;
	missileBodyDef.position.Set(missile->getPosition().x / PTM_RATIO, missile->getPosition().y / PTM_RATIO);
	missileBodyDef.linearDamping = 0;
	missileBodyDef.userData = missile;

	auto missileBody = _world->CreateBody(&missileBodyDef);
	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);
	b2PolygonShape missilePolygon;
	missilePolygon.SetAsBox((missile->getContentSize().width / 30) / PTM_RATIO, (missile->getContentSize().height / 3) / PTM_RATIO);

	b2FixtureDef missileFixtureDef;
	missileFixtureDef.shape = &missilePolygon;
	missileFixtureDef.density = 0.0f;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	//monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	//monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER;
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(-10, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Stage1_1::clearTime), player->attackSpeed);

}

void Stage1_1::clearTime(float)
{
}

