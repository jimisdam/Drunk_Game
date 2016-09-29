#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene() {
    auto scene = Scene::create();
    auto layer = HelloWorld::create();

    scene->addChild(layer);

	return scene;
}

bool HelloWorld::init() {
	if (!Layer::init()) {
		return false;
	}
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
	auto background = DrawNode::create();
	background->drawSolidRect(origin, visibleSize, Color4F(0.5, 0.5, 0.5, 1.0));
	this->addChild(background);

	pause = Sprite::create("pause.png");
	pause->setPosition(Vec2(visibleSize.width / 10, visibleSize.height / 10));
	this->addChild(pause);

    return true;
}