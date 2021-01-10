//------------------------------------------------------------------
// eventHandler.h
//
// Author:           JuanJakobo
// Date:             19.12.2020
// Description:
//-------------------------------------------------------------------

#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include "menuHandler.h"
#include "basicView.h"

#include <memory>

class EventHandler
{
public:
    /**
        * Defines fonds, sets global Event Handler and starts new content 
        */
    EventHandler();

    /**
        * Handles events and redirects them
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
    int eventDistributor(int type, int par1, int par2);

    
private:
    static std::unique_ptr<EventHandler> _eventHandlerStatic;
    std::unique_ptr<BasicView> _basicView;
    MenuHandler _menu = MenuHandler("Hello World");

    /**
        * Functions needed to call C function, redirects to real function
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
    static void mainMenuHandlerStatic(int index);
    /**
        * Handles menu events and redirects them
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
    void mainMenuHandler(int index);

    /**
        * Handles pointer Events
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
    int pointerHandler(int type, int par1, int par2);
};

#endif