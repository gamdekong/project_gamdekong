#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Player.h"

using namespace cocos2d;

class ContactListener : public b2ContactListener {
public:
	ContactListener(Player *player);
	~ContactListener();

	Player *player;
	virtual void BeginContact(b2Contact *contact);
	virtual void EndContact(b2Contact *contact);
	virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};
