#include "GameScene.h"
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

    feet = Sprite::create("feet.png");
    feet->setScale(1);
    feet->setPosition(Vec2(visibleSize.width / 2, feet->getContentSize().height / 2));
    this->addChild(feet);

    pause = Sprite::create("pause.png");
    pause->setScale(1);
	pause->setPosition(Vec2(visibleSize.width - pause->getContentSize().width, pause->getContentSize().height));
	this->addChild(pause);

    return true;
}
