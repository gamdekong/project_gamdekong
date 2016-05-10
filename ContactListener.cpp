#include "ContactListener.h"
#include "SwordMissile.h"
#include "Monster.h"

ContactListener::ContactListener(Player *player) {
	this->player = player;
}

ContactListener::~ContactListener() {
}

void ContactListener::BeginContact(b2Contact *contact)
{
	//CCLog("Contact:Begin");
}

void ContactListener::EndContact(b2Contact *contact)
{

	b2Fixture *fixA = contact->GetFixtureA();
	b2Fixture *fixB = contact->GetFixtureB();

	b2Body *bodyA = fixA->GetBody();
	b2Body *bodyB = fixB->GetBody();
	
	if (bodyA->GetType() == b2_dynamicBody)
	{
		log("Contact:EndA");

		auto spriteA = (Sprite*)bodyA->GetUserData();

		if (spriteA != nullptr)
		{
			if (spriteA->getTag() == 3)
			{
				SwordMissile *missileSprite = (SwordMissile*)spriteA;
				missileSprite->endAction(missileSprite->missileNum);
				bodyA->SetUserData(nullptr);

			}
			if (spriteA->getTag() == 2)
			{
				Monster *monsterSprite = (Monster*)spriteA;
				monsterSprite->nowEnergy -= player->power;
				if (monsterSprite->nowEnergy < 0)
					bodyA->SetUserData(nullptr);
				


			}
		}
		
		

	}
	if (bodyB->GetType() == b2_dynamicBody)
	{
		log("Contact:EndB");
		auto spriteB = (Sprite*)bodyB->GetUserData();
		if (spriteB != nullptr)
		{
			if (spriteB->getTag() == 3)
			{
				SwordMissile *missileSprite = (SwordMissile*)spriteB;
				missileSprite->endAction(missileSprite->missileNum);
				bodyB->SetUserData(nullptr);
			}
			if (spriteB->getTag() == 2)
			{
				Monster *monsterSprite = (Monster*)spriteB;
				monsterSprite->nowEnergy -= player->power;
				if (monsterSprite->nowEnergy < 0)
					bodyA->SetUserData(nullptr);



			}
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
