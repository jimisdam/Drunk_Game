#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
private:
	cocos2d::Sprite* pause;
	cocos2d::Sprite* feet;

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(GameScene);
};

#endif // __GAMESCENE_SCENE_H__
