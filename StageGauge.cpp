//
//  StageGauge.cpp
//  LovePrincess
//
//  Created by YuichiNishioka on 2015/05/23.
//
//

#include "StageGauge.h"
#include "BaseGaugeSprite.h"
USING_NS_CC;

StageGauge::StageGauge(int gaugeMax, Layer* Layer)
{
    gaugeName = "stage_exp_bar.png";
    gaugeType = 1;
    maxGaugeCount = gaugeMax;
    gaugePointLayer = Layer;
}

StageGauge::~StageGauge()
{
}

StageGauge* StageGauge::create(Layer* Layer, Vec2 pos, int gaugeMax)
{
    // ゲージ最大数をセット
    StageGauge* pRet = new StageGauge(gaugeMax, Layer);

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

bool StageGauge::init(Layer* Layer, Vec2 pos)
{
    if (!BaseGaugeSprite::init(Layer, pos)) {
        return false;
    }
    return true;
}