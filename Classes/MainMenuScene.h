#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer
{
private:
	cocos2d::Sprite* pause;
	cocos2d::Sprite* feet;

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void GoToGameScene(cocos2d::Ref *);
    
    CREATE_FUNC(MainMenuScene);
};

#endif // __MAINMENU_SCENE_H__
