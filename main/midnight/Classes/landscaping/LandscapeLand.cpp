//
//  LandscapeLand.cpp
//  citadel
//
//  Created by Chris Wild on 22/08/2017.
//
//

#include "LandscapeView.h"

const std::string floor_graphics[] = {
      "t_land1"
    , "t_snow1"
    , "t_water0"
    , "t_water1"
    , "t_water3"
    , "t_snow1"
};



void LandscapeLand::Init( LandscapeOptions* options )
{
    LandscapeNode::Init(options);
    
    setContentSize( Size(RES(1024),RES(80*4)) );
    
    auto floor = Sprite::createWithSpriteFrameName( "floor" );
    
    float scalex = getContentSize().width / floor->getContentSize().width ;
    
    floor->setScale(scalex,1.0);
    floor->setPosition(0, 0);
    floor->setAnchorPoint( Vec2(0,0) );
    
    if ( options->debugLand )
        floor->setColor(Color3B::YELLOW);
    
    addChild(floor);
    
    BuildFloors( options->generator->items );
    
}


void LandscapeLand::BuildFloors( LandscapeItems* items )
{
    LandscapeItem* loc1=nullptr;
    LandscapeItem* loc2=nullptr;
    
    for(auto const& item: *items) {
        
        if ( item->loc == options->currentLocation)
            loc1 = item;
        
        if ( item->loc == options->aheadLocation )
            loc2 = item;
    }
    
    auto fnDrawTerrain = [=]( LandscapeItem* item, f32 adjustX, f32 adjustY )
    {
        if ((item->position.z>=options->generator->viewportNear)&&(item->position.z<options->generator->viewportFar))
        {
            auto graphic = GetFloorImage(item->floor);
            
            if ( graphic ) {
                graphic->setPosition(options->generator->NormaliseXPosition(item->position.x), this->getContentSize().height - item->position.y);
                
                graphic->setScaleX( graphic->getScaleX() * item->scale*adjustX );
                graphic->setScaleY( graphic->getScaleY() * item->scale*adjustY );
                
                this->addChild(graphic);
                
            }
        }
        
    };
    
    auto fnDrawItem = [=]( LandscapeItem* item ) {
        
        if ( item == loc1  )
            return;
        
        if ( item != loc2) {
            fnDrawTerrain(item, 1.0f, 1.0f);
            return ;
        }
        
        LandscapeItem under;
        under.floor = item->floor;
        under.position = item->position;
        under.scale = item->scale;
        //fnDrawTerrain(&under, 1.0f, 1.0f);
        
        //        under.floor = item->floor;
        //        under.position = item->position;
        //        under.position.x -= 128 * loc2->scale;
        //        fnDrawTerrain(&under, 1.0f, 1.0f);
        //
        //        under.floor = item->floor;
        //        under.position = item->position;
        //        under.position.x += 128 * loc2->scale;
        //        fnDrawTerrain(&under, 1.0f, 1.0f);
        
        //        under.floor = item->floor;
        //        under.position = item->position;
        //        under.position.y -= 20;
        //        fnDrawTerrain(&under, 1.0f, 1.0f);
        //
        //        under.floor = item->floor;
        //        under.position = item->position;
        //        under.position.y += 20 ;
        //        fnDrawTerrain(&under, 1.0f, 1.0f);
        
        
    };
    
    
    
    
    //
    // Do the water first
    //
    if ( options->showWater ) {
        for(auto const& item: *items) {
            if ( item->floor != floor_river && item->floor != floor_sea && item->floor != floor_lake )
                continue;
            
            fnDrawItem(item);
        }
    }
    
    
    
    //
    // The everything else apart from snow
    //
    if ( options->showLand ) {
        for(auto const& item: *items) {
            if ( item->floor != floor_normal && item->floor != floor_debug )
                continue;
            
            fnDrawItem(item);
        }
        
        //
        // then snow
        //
        for(auto const& item: *items) {
            
            if ( item->floor != floor_snow )
                continue;
            
            fnDrawItem(item);
            
        }
        
    }
    
    
    
    
    LandscapeItem under;
    under.floor = floor_debug; //loc1->floor;
    under.position = loc1->position;
    under.position.y = options->generator->HorizonCentreY + options->generator->PanoramaHeight + (options->generator->LocationHeight/2);
    under.position.z = 1;
    
    under.scale = 1.0;
    //fnDrawTerrain(&under, 1.0f, 1.0f);
    
    //    under.position.x = loc1->position.x - RES(1024) ;
    //    fnDrawTerrain(&under, 1.0f, 1.0f);
    //
    //    under.position.x = loc1->position.x - RES(2048) ;
    //    fnDrawTerrain(&under, 1.0f, 1.0f);
    //
    //    under.position.x = loc1->position.x + RES(1024) ;
    //    fnDrawTerrain(&under, 1.0f, 1.0f);
    //
    //    under.position.x = loc1->position.x + RES(2048) ;
    //    fnDrawTerrain(&under, 1.0f, 1.0f);
    
    
    
    //
    //        under.floor = item->floor;
    //        under.position = item->position;
    //        under.position.x += 128 * loc2->scale;
    //        fnDrawTerrain(&under, 1.0f, 1.0f);
    
    //        under.floor = item->floor;
    //        under.position = item->position;
    //        under.position.y -= 20;
    //        fnDrawTerrain(&under, 1.0f, 1.0f);
    //
    //        under.floor = item->floor;
    //        under.position = item->position;
    //        under.position.y += 20 ;
    //        fnDrawTerrain(&under, 1.0f, 1.0f);
    
    
}

Sprite* LandscapeLand::GetFloorImage( floor_t floor )
{
    
    Sprite* image = Sprite::createWithSpriteFrameName( floor_graphics[floor] );
    
    if ( image == nullptr )
        return image;
    
    //image->setScale(masterScale);
    
    //if ( floor == floor_water )
    //    image->setScale(0.5);
    
    //image->setBlendFunc(cocos2d::BlendFunc::ALPHA_NON_PREMULTIPLIED);
    //image->setGLProgramState( glProgramState->clone() );
    
    image->setScaleX(options->landScaleX);
    image->setScaleY(options->landScaleY);
    
    if ( floor == floor_debug ) {
        image->setColor(Color3B::YELLOW);
    }
    
    
    return image;
}
