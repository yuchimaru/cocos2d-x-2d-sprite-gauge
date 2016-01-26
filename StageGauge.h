//
//  StageGauge.h
//  LovePrincess
//
//  Created by YuichiNishioka on 2015/05/23.
//
//

#ifndef __LovePrincess__StageGauge__
#define __LovePrincess__StageGauge__

#include "BaseGaugeSprite.h"
USING_NS_CC;

class StageGauge : public BaseGaugeSprite
{
public:
    StageGauge(int gaugeMax,Layer* Layer);
    virtual ~StageGauge();
    static StageGauge* create(Layer* Layer, Vec2 pos, int gaugeMax);
    virtual bool init(Layer* Layer, Vec2 pos);
};
#endif /* defined(__LovePrincess__StageGauge__) */
