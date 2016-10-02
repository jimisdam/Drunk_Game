#include "MenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene() {
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();

    scene->addChild(layer);

	return scene;
}

bool MainMenuScene::init() {
	if (!Layer::init()) {
		return false;
	}
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
	auto background = DrawNode::create();
	background->drawSolidRect(origin, visibleSize, Color4F(0.5, 0.5, 0.5, 1.0));
	this->addChild(background);

	auto playButton = MenuItemImage::create("images/play.png", 
										    "images/play.png", 
										     CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
	playButton->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	
	auto menu = Menu::create(playButton, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref *sender) {
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}