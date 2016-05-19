#include "Intro.h"


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

	auto bg = Sprite::create("intro/background-star1.png");
	auto gameName = Sprite::create("intro/title.png");
	bg->setPosition(Vec2(0 , 0));
	bg->setAnchorPoint(Vec2(0, 0));
	gameName->setPosition(Vec2(winsize.width / 2, winsize.height/2 + 150));

	auto bg2 = Sprite::create("intro/bg2.png");
	bg2->setAnchorPoint(Vec2(0, 0));
	bg2->setPosition(Vec2(0, 0));
	
	
	

	auto click = Sprite::create("intro/click.png");
	click->setPosition(Vec2(winsize.width / 2, 100));
	
	
	this->addChild(click, 10);
	this->addChild(bg,0);
	//this->addChild(bg2, 4);
	this->addChild(gameName, 10);


	

	this->schedule(schedule_selector(Intro::tick));
	
	/*auto fi = FadeIn::create(5);
	auto fo = FadeOut::create(5);
	auto move1 = MoveBy::create(20,(Vec2(100, 0)));
	auto seq = Sequence::create(fi, fo, nullptr);
	auto spawn1 = Spawn::create(seq, move1, nullptr);
	auto r1 = RepeatForever::create(spawn1);


	auto fi1 = FadeIn::create(3);
	auto fo1 = FadeOut::create(3);
	auto move2 = MoveBy::create(20, (Vec2(-100, 0)));
	auto seq2 = Sequence::create(fi1, fo1, nullptr);
	auto spawn2 = Spawn::create(seq2, move2, nullptr);
	auto r2 = RepeatForever::create(spawn2);


	orora->runAction(r1);
	orora2->runAction(r2);*/
	//orora2->runAction(moveRight);

	return true;
}

void Intro::doParticles()
{

	int x = rand() % 1200 - 200 ;
	int y = rand() % 700 + 300;
	int type = rand() % 2 + 1;
	int speed = rand() % 8 +4;
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
			auto move = MoveBy::create(speed, Vec2(1300, -2000));
			auto seq = Sequence::create(move, RemoveSelf::create(), nullptr);
			particleTest1->runAction(seq);
			this->addChild(particleTest1,5);

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
			auto move = MoveBy::create(speed, Vec2(1300, -2000));
			auto seq = Sequence::create(move, RemoveSelf::create(), nullptr);
			particleTest2->runAction(seq);
			this->addChild(particleTest2,5);

		}
	}
	

}

void Intro::doStar()
{
	int x = rand() % 1280 + 1;
	int y = rand() % 720 + 1;
	float size = (float)(rand() % 3 + 2) / 10;

	auto star = Sprite::create("images/stars.png");
	star->setPosition(Vec2(x, y));
	star->setOpacity(0);
	star->setScale(size);
	this->addChild(star,3);

	auto starFadein = FadeIn::create(1);
	auto starFadeout = FadeOut::create(1);
	auto rotate = RotateBy::create(2, 360);
	auto fade = Sequence::create(starFadein,starFadeout, nullptr);
	
	auto spawnAction = Spawn::create(fade, rotate, nullptr);
	auto seq = Sequence::create(spawnAction, RemoveSelf::create(), nullptr);
	
	star->runAction(seq);
}

void Intro::tick(float dt)
{
	


	int time = rand() % 100 + 1;
	//if (time < 3)
	//{
	//	this->doParticles();
	//}
	if (time > 80)
	{
		this->doStar();
	}

	
}


void Intro::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Intro::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Intro::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Intro::onTouchesEnded, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Intro::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{


}

void Intro::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
	



	

}

void Intro::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
	auto pScene = LobbyLayer::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, pScene));

}