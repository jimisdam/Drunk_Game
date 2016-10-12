#ifndef __FEET_H__
#define __FEET_H__

#include "cocos2d.h"

class Feet
{
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite *feetSprite;
	const double velocity = 100;
	const double slope = 35;
	const double slope_velocity = 1;

public:
	explicit Feet(cocos2d::Layer *);
	void Move(cocos2d::Vec2);
};

#endif // __FEET_H__
