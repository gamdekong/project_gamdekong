#pragma once
#include "cocos2d.h"
using namespace cocos2d;



class Intro : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Intro);

	void doParticles();
	void tick(float);
};
