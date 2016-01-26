//
//  BaseGauge.h
//  LovePrincess
//
//  Created by YuichiNishioka on 2015/05/23.
//
//

#ifndef __LovePrincess__BaseGaugeSprite__
#define __LovePrincess__BaseGaugeSprite__

USING_NS_CC;

class BaseGaugeSprite : public Sprite
{
public:
    BaseGaugeSprite();
    virtual ~BaseGaugeSprite();
    static BaseGaugeSprite* create(Layer* Layer, Vec2 pos, int gaugeMax);
    virtual bool init(Layer* Layer, Vec2 pos);
    
    const char* gaugeName = "";
    int maxGaugeCount = 1;
    int gaugeType = 1;
    int nowGaugePoint = 0;
    Layer* gaugePointLayer;
    virtual int updateGaugePoint(int point);

    Sprite* SpriteGauge;
    Sprite* bgGaugeBar;
    Sprite* pointGauge;
    
};

#endif /* defined(__LovePrincess__BaseGaugeSprite__) */
