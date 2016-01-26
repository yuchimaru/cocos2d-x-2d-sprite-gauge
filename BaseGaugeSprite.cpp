//
//  BaseGaugeSprite.cpp
//  LovePrincess
//
//  Created by YuichiNishioka on 2015/05/23.
//
//

#include "BaseGaugeSprite.h"
BaseGaugeSprite::BaseGaugeSprite()
{
}

BaseGaugeSprite::~BaseGaugeSprite()
{
}

BaseGaugeSprite* BaseGaugeSprite::create(Layer* Layer, Vec2 pos, int gaugeMax)
{
    // ゲージ最大数をセット
    BaseGaugeSprite* pRet = new BaseGaugeSprite();
    
    if (pRet && pRet->init(Layer, pos))
    {
        // 参照カウンタ1　解放わすれずに
        pRet->retain();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool BaseGaugeSprite::init(Layer* Layer, Vec2 pos)
{
    if(gaugeName == NULL){
        return false;
    }

    SpriteGauge = Sprite::create(gaugeName);
    SpriteGauge->setPosition(Vec2(pos));
    Layer->addChild(SpriteGauge, 3);

    bgGaugeBar = Sprite::create();
    bgGaugeBar->setTextureRect(Rect(0, 0, SpriteGauge->getContentSize().width, SpriteGauge->getContentSize().height));
    bgGaugeBar->setPosition(Vec2(pos));
    bgGaugeBar->setColor(Color3B::BLACK);
    Layer->addChild(bgGaugeBar, 1);

    pointGauge = Sprite::create();
    pointGauge->setTextureRect(Rect(0, 0, 0, 0));
    pointGauge->setPosition(Vec2(pos.x - SpriteGauge->getContentSize().width / 2,pos.y));
    pointGauge->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    pointGauge->setColor(Color3B::RED);
    Layer->addChild(pointGauge, 2);

    return true;
};

int BaseGaugeSprite::updateGaugePoint(int point)
{
    // ポイント加算
    nowGaugePoint += point;

    // 加算式ゲージ
    if(gaugeType == 1){
        // ポイントマックス
        if(nowGaugePoint > maxGaugeCount){
            // もし超えても最大をセットしておく
            nowGaugePoint = maxGaugeCount;
            // 超えている
            return 2;
        }
        // ゲージの進捗
        float progressPer = (float)nowGaugePoint / (float)maxGaugeCount;
        // gaugeを更新
        auto pointWidth = SpriteGauge->getContentSize().width * progressPer;
        pointGauge->setTextureRect(Rect(0, 0, pointWidth, SpriteGauge->getContentSize().height));
        // Gauge max
        if(nowGaugePoint == maxGaugeCount){
            return 1;
        }
    }else if(gaugeType == 2){
        // 減算式ゲージ
        
        // ポイントなし
        if(nowGaugePoint <= 0){
            return 1;
        }
    }
    // ポイントの更新のみ
    return 0;
};