#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "Feet.h"

class GameScene : public cocos2d::Layer
{
private:
	cocos2d::Sprite* pause;
	Feet *feet;

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	bool onTouchBegan(cocos2d::Touch *, cocos2d::Event *);
    
    CREATE_FUNC(GameScene);
};

#endif // __GAMESCENE_SCENE_H__
