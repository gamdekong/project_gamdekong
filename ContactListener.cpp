#include "ContactListener.h"
#include "SwordMissile.h"
#include "Monster.h"
#include "Player.h"

ContactListener::ContactListener(b2World *world) {
	_world = world;
}

ContactListener::~ContactListener() {
}

void ContactListener::BeginContact(b2Contact *contact)
{
	//CCLog("Contact:Begin");
}

void ContactListener::EndContact(b2Contact *contact)
{

	log("Contact:End");
	b2Fixture *fixA = contact->GetFixtureA();
	b2Fixture *fixB = contact->GetFixtureB();

	b2Body *bodyA = fixA->GetBody();
	b2Body *bodyB = fixB->GetBody();
	
	if (bodyA->GetType() == b2_dynamicBody)
	{
		auto spriteA = (Sprite*)bodyA->GetUserData();

		if (spriteA->getTag() == 3)
		{
			SwordMissile *missileSprite = (SwordMissile*)spriteA;
			missileSprite->endAction(missileSprite->missileNum);
			bodyA->SetUserData(nullptr);

		}
		

	}
	if (bodyB->GetType() == b2_dynamicBody)
	{
		auto spriteB = (Sprite*)bodyB->GetUserData();

		if (spriteB->getTag() == 3)
		{
			SwordMissile *missileSprite = (SwordMissile*)spriteB;
			missileSprite->endAction(missileSprite->missileNum);
			bodyB->SetUserData(nullptr);
		}


	}
	

	
	

	//_world->DestroyBody(bodyA);
}

void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
	//CCLog("Contact:PreSolve");
}

void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
	

	//b2Fixture *fixA = contact->GetFixtureA();
	//b2Fixture *fixB = contact->GetFixtureB();

	//b2Body *bodyA = fixA->GetBody();
	//b2Body *bodyB = fixB->GetBody();
	//

	//if (bodyA->GetType() == b2_dynamicBody || bodyB->GetType() == b2_dynamicBody) {
	//	log("Contact:impulse .. %f", impulse->normalImpulses[0]);
	//}
}
