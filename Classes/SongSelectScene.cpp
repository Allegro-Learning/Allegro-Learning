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

#include "SongSelectScene.h"
#include "PlayGameScene.h"
#include "MainMenuScene.h"
#include "GameSettings.h"
#include "extensions/cocos-ext.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
//USING_NC_CC_EXT;
using namespace ui;

Scene* SongSelect::createScene()
{
    return SongSelect::create();
}



// on "init" you need to initialize your instance
bool SongSelect::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto winSize = Director::getInstance()->getWinSize();



    //SELECT SONG SCROLL VIEW (CAN USE A LIST VIEW AS WELL)
    ScrollView  *scrollView = ScrollView::create();
    scrollView->setDirection(ScrollView::Direction::VERTICAL);
    scrollView->setContentSize(Size(300, 200));
    scrollView->setInnerContainerSize(Size(1280,2500));
    scrollView->setBounceEnabled(true);
    scrollView->setAnchorPoint(Vec2(0.5, 0.5));
    scrollView->setPosition(Vec2(winSize.width / 2 + origin.x, winSize.height / 4 + origin.y));
    //add 50 temporary buttons to scrollView
    for (int i = 0; i < 50; i++) {
        Button *button = Button::create("button.png", "buttonPress.png");
        button->setPosition(Vec2(scrollView->getContentSize().width/2, i*50));
        button->setTitleText("Song");
        button->setTitleFontName("fonts/Marker Felt.ttf");
        button->setTitleFontSize(12.0f);
        button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
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
                    auto scene = PlayGame::createScene();

                    // run
                    Director::getInstance()->replaceScene(scene);
                    break;
                }
            });
        scrollView->addChild(button);
           
    }
    this->addChild(scrollView);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Select Song", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        //problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(winSize.width / 2, (3*winSize.height / 4)));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    //Back BUTTON
    auto backButton = Button::create("button.png", "buttonPress.png");
    backButton->setScale(0.75, 0.75);
    backButton->setTitleText("Back");
    backButton->setTitleFontName("fonts/Marker Felt.ttf");
    backButton->setTitleFontSize(12.0f);
    backButton->setPosition(Vec2(winSize.width / 5, 3 * winSize.height / 4));
    backButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
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
                auto scene = MainMenu::createScene();

                // run
                Director::getInstance()->replaceScene(scene);
                break;
            }

        });
    this->addChild(backButton);
    auto settingsButton = Button::create("settings.png", "settings.png");
    settingsButton->setScale(2, 2);
    settingsButton->setPosition(Vec2(4 * winSize.width / 5, 3 * winSize.height / 4));
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
    return true;
}

