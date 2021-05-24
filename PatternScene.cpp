#include "PatternScene.h"
#include "ResLoader.h"
#include "resource.h"

PatternScene::PatternScene()
{
	auto delay = gcnew Delay(1.0f);
	auto opacityBy = gcnew OpacityBy(2.0f, 1.0f);
	auto sequence = gcnew Sequence({ delay, opacityBy });

	// 添加背景
	auto background = gcnew Sprite(ResLoader::getImage(L"Pattern"));
	background->setAnchor(0, 0);
	this->addChild(background);

	//设置返回主界面精灵

	auto returnMain = gcnew Sprite(ResLoader::getImage(L"ReturnScene"));
	auto returnMain_selected = gcnew Sprite(ResLoader::getImage(L"ReturnScene"));
	returnMain->setScale(1.0f);
	returnMain_selected->setScale(0.8f);
	returnMain_selected->movePosY((returnMain->getHeight() - returnMain_selected->getHeight()) / 2);
	returnMain_selected->movePosX((returnMain_selected->getWidth() - returnMain_selected->getWidth()) / 2);

	//添加返回主菜单按钮
	auto returnMain_btn = gcnew Button(returnMain, returnMain_selected);
	returnMain_btn->setOpacity(0.0f);
	auto sequence_2 = gcnew Sequence({ delay->clone(), sequence->clone() });
	returnMain_btn->runAction(sequence_2->clone());
	// 按下开始按钮，进入 主菜单 场景
	returnMain_btn->setClickFunc([]
		{
			SceneManager::back();
		});

	returnMain_btn->setPos(Window::getWidth() - 50, Window::getHeight() - 50);
	this->addChild(returnMain_btn);
	
	
}
