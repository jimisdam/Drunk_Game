#include "Feet.h"

USING_NS_CC;

Feet::Feet(cocos2d::Layer *layer) {
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	feetSprite = Sprite::create("images/feet.png");
	feetSprite->setScale(1);
	feetSprite->setPosition(Vec2(visibleSize.width / 2, feetSprite->getContentSize().height / 2));
	layer->addChild(feetSprite);
}

void Feet::Move(cocos2d::Vec2 touch_location) {
	feetSprite->stopActionByTag(1);

	MoveTo *move;
	RotateTo *rotate;

	if (touch_location.x - feetSprite->getPosition().x > 0) {
		auto time = (visibleSize.width - feetSprite->getPosition().x) / velocity;
		move = MoveTo::create(time, Vec2(visibleSize.width, feetSprite->getContentSize().height / 2));

		time = (slope - feetSprite->getRotation()) / slope_velocity;
		time /= 2 * slope;

		rotate = RotateTo::create(time, slope);
	}
	else {
		auto time = feetSprite->getPosition().x / velocity;
		move = MoveTo::create(time, Vec2(0, feetSprite->getContentSize().height / 2));
		
		time = (feetSprite->getRotation() + slope) / slope_velocity;
		time /= 2 * slope;

		rotate = RotateTo::create(time, -slope);
	}

	auto action = Spawn::createWithTwoActions(move, rotate);
	action->setTag(1);

	feetSprite->runAction(action);
}