//
//  layout_id.h
//  midnight
//
//  Created by Chris Wild on 02/12/2017.
//

#ifndef layout_id_h
#define layout_id_h

enum ICON_ID
{
    
#if defined(_LOM_)
    ID_SEEK=1,              // 1
    ID_HIDE,
    ID_UNHIDE,
    ID_FIGHT,
#endif
    
#if defined(_DDR_)
    ID_GIVE=1,
    ID_TAKE,
    ID_USE,
    ID_REST,
#endif
    
    ID_APPROACH,
    ID_RECRUITMEN,
    ID_POSTMEN,
    ID_ATTACK,
    ID_HOME,
    
    ID_DEBUG_EMAIL,         // 10
    ID_UNDO,
    ID_UNDO_NIGHT,
    ID_UNDO_DAWN,
    ID_CHAR1,
    ID_CHAR2,
    ID_CHAR3,
    ID_CHAR4,
    ID_SELECT_ALL,
    ID_SELECT_ALL2,
    
    ID_ACTIONS,             // 20
    ID_UP,
    ID_LEFT,
    ID_DOWN,
    ID_RIGHT,
    ID_PLUS,
    ID_MINUS,
    ID_RECRUIT_PLUS,
    ID_RECRUIT_MINUS,
    
    ID_ARROW_UP,
    ID_ARROW_LEFT,          // 30
    
    ID_ARROW_DOWN,
    ID_ARROW_RIGHT,
    ID_LOOK,
    ID_THINK,
    ID_NIGHT,
    ID_MAP,
    ID_DAWN,
    ID_MANUAL,
    ID_GUIDE,
    ID_HELP,                // 40
    
    ID_TUTORIAL_ONOFF,
    ID_MAP_OVERVIEW,
    ID_MAP_DISCOVERY,
    ID_MAP_FOLLOW,
    ID_FILTER_CRITTERS,
    ID_VISIBLE,
    ID_NOT_VISIBLE,
    ID_THINK_PERSON,
    ID_THINK_PLACE,
    ID_THINK_ARMY,          // 50
    
    ID_THINK_BATTLE,
    ID_BUTTON1,
    ID_BUTTON2,
    ID_BOOKMARK,
    ID_BOOKMARK_OVERLAY,
    ID_BOOK,
    ID_CLOSE,               // 57
    ID_BOX,
    
    ID_GROUP_LEAVE,
    ID_GROUP_DISBAND,
    ID_ENTER_TUNNEL,
    ID_SHOW_TUNNELS,
    ID_CLEANUP_SELECT,
    
    // no images
    
    ID_NEW_STORY,
    ID_CONTINUE_STORY,      // 60
    ID_END_STORY,
    ID_CAMPAIGNS,
    ID_CREDITS,
    ID_EXIT,
    ID_UPDATE,
    
    ID_OPTIONS,
    ID_MENU_DISPLAY,
    ID_MENU_GAME,
    ID_MENU_CONTROL,
    ID_MENU_HELP,
    
    ID_OPTION_SCREENMODE,
    
    ID_OPTION_AUTO_FIGHT,
    ID_OPTION_AUTO_UNHIDE,
    ID_OPTION_MOVE_INDICATORS,
    ID_OPTION_TUTORIAL,
    ID_OPTION_NAVIGATION,
    ID_OPTION_TRANSITIONS,
    ID_OPTION_NOVELLA,
    
    ID_OPTION_COMPASS_DELAY,
    ID_OPTION_COMPASS_FEEDBACK,
    ID_OPTION_THINK_PAGING,
    ID_OPTION_NIGHT_DISPLAY,
    ID_OPTION_BATTLE_FULL,
    ID_OPTION_KEYBOARD_STYLE,
    
    ID_SHOW_LEADER,
    ID_DEBUG_MAP,
    
    ID_YES,
    ID_NO,
    
    ID_FILTER_DAWN,
    ID_FILTER_NIGHT,
    ID_FILTER_BATTLE,
    ID_FILTER_DEAD,
    ID_FILTER_CURRENT_LOC,
    
    ID_COMPASS_N,
    ID_COMPASS_NE,
    ID_COMPASS_E,
    ID_COMPASS_SE,
    ID_COMPASS_S,
    ID_COMPASS_SW,
    ID_COMPASS_W,
    ID_COMPASS_NW,
    
    ID_HELP_CLOSE,
    
    ID_GROUP_LEFT,
    ID_GROUP_RIGHT,
    
    ID_SELECT_CHAR=1000,
    ID_LANDSCAPE=2000,
    ID_STORIES=3000,
    ID_TUNNEL=4000,
    ID_SHOW_TOOLTIP=5000,
};



#endif /* layout_id_h */