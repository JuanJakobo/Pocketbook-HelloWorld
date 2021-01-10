//------------------------------------------------------------------
// menuHandler.cpp
//
// Author:           JuanJakobo
// Date:             19.12.2020
//
//-------------------------------------------------------------------

#include "inkview.h"
#include "menuHandler.h"

#include <string>

using namespace std;

MenuHandler::MenuHandler(const string &name)
{
    //Define panel size
    _panelMenuHeight = ScreenHeight() / 18;
    _panelMenuBeginY = 0;
    _mainMenuWidth = ScreenWidth() / 3;
    _panelMenuBeginX = ScreenWidth() - _mainMenuWidth;

    _menuButtonRect = iRect(_mainMenuWidth * 2, _panelMenuBeginY, _mainMenuWidth, _panelMenuHeight, ALIGN_RIGHT);
    _menuFont = std::unique_ptr<ifont>(OpenFont("LiberationMono-Bold", _panelMenuHeight / 2, 1));

    SetFont(_menuFont.get(), BLACK);
    DrawTextRect(0, _panelMenuBeginY, ScreenWidth(), _panelMenuHeight, name.c_str(), ALIGN_CENTER);
    DrawTextRect2(&_menuButtonRect, "Menu");
    DrawLine(0, _panelMenuHeight - 1, ScreenWidth(), _panelMenuHeight - 1, BLACK);

    _contentRect = iRect(0, _panelMenuHeight, ScreenWidth(), (ScreenHeight() - PanelHeight() - _panelMenuHeight), 0);

    SetHardTimer("PANELUPDATE", panelHandlerStatic, 110000);
    DrawPanel(NULL, "", NULL, -1);
}

void MenuHandler::panelHandlerStatic()
{
    DrawPanel(NULL, "", NULL, -1);
    SetHardTimer("PANELUPDATE", panelHandlerStatic, 110000);
}

int MenuHandler::createMenu(iv_menuhandler handler)
{
    imenu mainMenu[] =
        {
            {ITEM_HEADER, 0, "Menu", NULL},
            {ITEM_ACTIVE, 101, "Clear screen", NULL},
            {ITEM_ACTIVE, 102, "Close App"},
            {0, 0, NULL, NULL}};

    mainMenu[2].type = ITEM_ACTIVE;

    OpenMenu(mainMenu, 0, _panelMenuBeginX, _panelMenuBeginY, handler);

    return 1;
}