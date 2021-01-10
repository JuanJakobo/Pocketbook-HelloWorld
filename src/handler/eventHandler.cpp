//------------------------------------------------------------------
// eventHandler.cpp
//
// Author:           JuanJakobo
// Date:             19.12.2020
//
//-------------------------------------------------------------------

#include "inkview.h"
#include "eventHandler.h"
#include "menuHandler.h"
#include "basicView.h"

std::unique_ptr<EventHandler> EventHandler::_eventHandlerStatic;

EventHandler::EventHandler()
{
    //create a event to handle events (for example it is used here to handle the mainmenu)
    _eventHandlerStatic = std::unique_ptr<EventHandler>(this);

    //create a new basic View to interact with the UI
    _basicView = std::unique_ptr<BasicView>(new BasicView(_menu.getContentRect()));

    FullUpdate();
}

int EventHandler::eventDistributor(int type, int par1, int par2)
{
    if (ISPOINTEREVENT(type))
        return EventHandler::pointerHandler(type, par1, par2);

    return 0;
}

void EventHandler::mainMenuHandlerStatic(int index)
{
    _eventHandlerStatic->mainMenuHandler(index);
}

void EventHandler::mainMenuHandler(int index)
{
    switch (index)
    {
    //Dialog to reset drawn stars
    case 101:
    {
        int dialogResult = DialogSynchro(ICON_QUESTION, "Question", "Are you sure that you want to clear the screen?", "Yes", "No", "Cancel");
        switch (dialogResult)
        {
        case 1:
            _basicView->clearContent();
            FullUpdate();
            break;
        default:
            break;
        }
        break;
    }
    //Exit
    case 102:
        CloseApp();
        break;
    default:
        break;
    }
}

int EventHandler::pointerHandler(int type, int par1, int par2)
{
    if (type == EVT_POINTERDOWN)
    {
        if (IsInRect(par1, par2, _menu.getMenuButtonRect()) == 1)
        {
            return _menu.createMenu(EventHandler::mainMenuHandlerStatic);
        }
        else 
        {
            _basicView->clicked(par1,par2);
            PartialUpdate(par1,par2,100,100);
            return 1;
        }
    }
    return 0;
}