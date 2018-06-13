//
//  CreditsScene.cpp
//  midnight
//
//  Created by Chris Wild on 02/12/2017.
//

#include "../Extensions/CustomDirector.h"

#include "panel_credits.h"
#include "panel_mainmenu.h"

#include "../system/resolutionmanager.h"
#include "../system/panelmanager.h"


bool panel_credits::init()
{
    if ( !uipanel::init() )
    {
        return false;
    }
    
    SetBackground("credits.png");

    Exit(5.0);
    
    return true;
}


