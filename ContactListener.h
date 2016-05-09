#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;

class ContactListener : public b2ContactListener {
public:
	ContactListener(b2World *world);
	~ContactListener();

	b2World *_world;
	virtual void BeginContact(b2Contact *contact);
	virtual void EndContact(b2Contact *contact);
	virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};
