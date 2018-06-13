//
//  panelmanager.hpp
//  midnight
//
//  Created by Chris Wild on 13/06/2018.
//

#ifndef panelmanager_hpp
#define panelmanager_hpp

#include "../library/libinc/mxtypes.h"
#include "ringcontroller.h"

using namespace chilli::types;
#include "panel_id.h"

FORWARD_REFERENCE( uipanel );

enum transition_t {
    
    TRANSITION_NONE=0,
    
    TRANSITION_SLIDEUP,
    TRANSITION_SLIDEDOWN,
    TRANSITION_PUSHUP,
    TRANSITION_PUSHDOWN,
    
    TRANSITION_SLIDELEFT,
    TRANSITION_SLIDERIGHT,
    TRANSITION_PUSHLEFT,
    TRANSITION_PUSHRIGHT,
    
    TRANSITION_FADEIN,
    
    
};

class panelmanager : public ringcontroller
{
public:
    
    // ** PANEL STUFF
    void SetPanelMode ( panelmode_t mode, bool history = false);
    void SetPanelMode ( panelmode_t mode, transition_t transition, bool history = false );
    uipanel* CurrentPanel();
    uipanel* GetPanel( panelmode_t mode );

    void ReturnToPrevious();
    void ReturnToPrevious( transition_t transition );
    
    //
    panelmode_t     currentmode;
    panelmode_t     previousmode;
    uipanel*        currentpanel;
    uipanel*        outgoing_panel;
    
protected:
    void SetCurrentPanel( uipanel* panel, transition_t transition );
    void PushCurrentPanel( uipanel* panel, transition_t transition );

    transition_t    reverseTransition;
    
};




#endif /* panelmanager_hpp */
