#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene() {
    auto scene = Scene::create();
    auto layer = GameScene::create();

    scene->addChild(layer);

	return scene;
}

bool GameScene::init() {
	if (!Layer::init()) {
		return false;
	}
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
	auto background = DrawNode::create();
	background->drawSolidRect(origin, visibleSize, Color4F(0.5, 0.5, 0.5, 1.0));
	this->addChild(background);

    pause = Sprite::create("images/pause.png");
    pause->setScale(1);
	pause->setPosition(Vec2(visibleSize.width - pause->getContentSize().width, pause->getContentSize().height));
	this->addChild(pause);

	feet = new Feet(this);

	auto eventListener = EventListenerTouchOneByOne::create();
	eventListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
	
	feet->Move(touch->getLocation());
	return true;
}