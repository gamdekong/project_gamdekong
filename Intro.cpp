#include "Intro.h"

USING_NS_CC;


Scene* Intro::createScene()
{

	auto scene = Scene::create();
	auto layer = Intro::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Intro::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	srand((unsigned)time(NULL));


	auto winsize = Director::getInstance()->getWinSize();

	auto bg = Sprite::create("intro/background-star.png");
	auto gameName = Sprite::create("intro/game_name.png");
	bg->setAnchorPoint(Vec2(0, 0));
	
	gameName->setPosition(Vec2(winsize.width / 2, 500));

	this->addChild(bg,0);
	this->addChild(gameName, 10);

	this->schedule(schedule_selector(Intro::tick, this));

	

	return true;
}

void Intro::doParticles()
{

	int x = rand() % 1200 - 200 ;
	int y = rand() % 700 + 300;
	int type = rand() % 2 + 1;
	int speed = rand() % 4 +1;
	float size = (float)(rand() % 3+1 ) / 10;
	//ParticleSystem* particleTest = ParticleFire::create();
	ParticleSystem* particleTest1 = ParticleSun::create();
	//ParticleSystem* particleTest = ParticleGalaxy::create();
	//ParticleSystem* particleTest = ParticleSmoke::create();
	ParticleSystem* particleTest2 = ParticleMeteor::create();
	//ParticleSystem* particleTest = ParticleSpiral::create();   //fire.png
	//ParticleSystem* particleTest = ParticleFlower::create();
	//ParticleSystem* particleTest = ParticleFireworks::create();
	//ParticleSystem* particleTest = ParticleExplosion::create();  //stars.png

	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/fire.png");
	if (type == 1)
	{
		particleTest1->setTexture(texture);
		if (particleTest1 != nullptr)
		{

			//파티클의 크기 조정
			particleTest1->setScale(size);

			//파티클의 지속 시간 조정 : -1 means 'foerver'
			//particleTest->setDuration(1,0);

			//파티클의 위치 조정
			particleTest1->setPosition(Vec2(x, y));
			auto move = MoveBy::create(speed, Vec2(800, -1500));
			auto seq = Sequence::create(move, RemoveSelf::create(), nullptr);
			particleTest1->runAction(seq);
			this->addChild(particleTest1);

		}
		
	}
	else if (type == 2)
	{
		particleTest2->setTexture(texture);
		if (particleTest2 != nullptr)
		{

			//파티클의 크기 조정
			particleTest2->setScale(size);

			//파티클의 지속 시간 조정 : -1 means 'foerver'
			//particleTest->setDuration(1,0);

			//파티클의 위치 조정
			particleTest2->setPosition(Vec2(x, y));
			auto move = MoveBy::create(speed, Vec2(800, -1500));
			auto seq = Sequence::create(move, RemoveSelf::create(), nullptr);
			particleTest2->runAction(seq);
			this->addChild(particleTest2);

		}
	}
	

}

void Intro::tick(float)
{
	int time = rand() % 100 + 1;
	if (time >40 && time < 50 )
	{
		this->doParticles();
	}
	
}
