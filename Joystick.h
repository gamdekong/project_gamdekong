//
//  Joystick.h
//  JoyStickEx
//
//  Created by Jaewhan Lee on 13. 6. 5..
//  Copyright www.cocos2d-x.kr 2013년. All rights reserved.
//

#ifndef __JoyStickEx__Joystick__
#define __JoyStickEx__Joystick__

#include "cocos2d.h"


using namespace cocos2d;


#define SHORT_ATTACK 1
#define RIGHT_LONG_ATTACK 2
#define LEFT_LONG_ATTACK 3

class Joystick : public Layer
{
    
public:
    virtual bool init();
    CREATE_FUNC(Joystick);

   // Vec2 getVelocity(){ return velocity; }
	bool getisPressed();
	void setisPressed();
	int joyNum;
	int attack;
private:

   
};

#endif
