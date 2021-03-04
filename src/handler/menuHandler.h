//------------------------------------------------------------------
// menuHandler.h
//
// Author:           JuanJakobo
// Date:             19.12.2020
// Description:      Handles the menubar and the menu
//-------------------------------------------------------------------

#ifndef MENU_HANDLER
#define MENU_HANDLER

#include <string>
#include <memory>

class MenuHandler
{
public:
    /**
        * Defines fonds, sets global Event Handler and starts new content 
        */
    explicit MenuHandler(const std::string &name);

    ~MenuHandler();

    irect *getContentRect() { return &_contentRect; };
    irect *getMenuButtonRect() { return &_menuButtonRect; };

    int createMenu(iv_menuhandler handler);

private:
    ifont *_menuFont;

    char *_menu = strdup("Menu");
    char *_clearScreen = strdup("Clear screen");
    char *_closeApp = strdup("Close App");
    int _panelMenuBeginX;
    int _panelMenuBeginY;
    int _panelMenuHeight;
    int _mainMenuWidth;
    irect _menuButtonRect;
    irect _loadingScreenRect;

    imenu _mainMenu;
    irect _contentRect;

    /**
        * Functions needed to call C function, handles the panel
        * 
        * @return void
        */
    static void panelHandlerStatic();
};

#endif