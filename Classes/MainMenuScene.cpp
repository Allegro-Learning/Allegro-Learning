/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MainMenuScene.h"
#include "SongSelectScene.h"
#include "GameSettings.h"
#include "extensions/cocos-ext.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
//USING_NC_CC_EXT;
using namespace ui;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}



// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    //SELECT SONG BUTTON
    auto winSize = Director::getInstance()->getWinSize();
    auto selectButton = Button::create("button.png", "buttonPress.png");
    selectButton->setTitleText("Select Song");
    selectButton->setTitleFontName("fonts/Marker Felt.ttf");
    selectButton->setTitleFontSize(12.0f);
    selectButton->setPosition(Vec2(winSize.width / 2, (winSize.height / 2)));
    selectButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
                                  {
                                      switch (type)
                                      {
                                          default:
                                              break;
                                          case cocos2d::ui::Widget::TouchEventType::BEGAN:
                                              break;
                                          case cocos2d::ui::Widget::TouchEventType::MOVED:
                                              break;
                                          case cocos2d::ui::Widget::TouchEventType::ENDED:
                                              // create a scene. it's an autorelease object
                                              auto scene = SongSelect::createScene();

                                              // run
                                              Director::getInstance()->replaceScene(scene);
                                              break;
                                      }
                                  });
    this->addChild(selectButton);

    //SETTINGS BUTTON
    auto settingsButton = Button::create("button.png", "buttonPress.png");
    settingsButton->setTitleText("Settings");
    settingsButton->setTitleFontName("fonts/Marker Felt.ttf");
    settingsButton->setTitleFontSize(12.0f);
    settingsButton->setPosition(Vec2(winSize.width / 2, winSize.height / 2 - 70));
    settingsButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            default:
                break;
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                // create a scene. it's an autorelease object
                auto scene = GameSettings::createScene();

                // run
                Director::getInstance()->replaceScene(scene);
                break;
            }
        });
    this->addChild(settingsButton);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Allegro", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        //problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(winSize.width / 2, (winSize.height/2) + 70));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
    return true;
}

