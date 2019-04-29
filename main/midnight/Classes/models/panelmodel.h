//
//  panelmodel.h
//  midnight
//
//  Created by Chris Wild on 09/12/2018.
//  Copyright © 2018 Chilli Hugger Software. All rights reserved.
//

#pragma once
#include "../library/libinc/mxtypes.h"

using namespace chilli;
//using namespace chilli::types;

class panelmodel
{
    virtual void serialize( u32 version, lib::archive& ar );
    virtual void setDefaults();
    
};
