//------------------------------------------------------------------
// listView.cpp
//
// Author:           JuanJakobo
// Date:             19.12.2020
//
//-------------------------------------------------------------------

#include "inkview.h"
#include "basicView.h"

BasicView::BasicView(const irect *contentRect) : _contentRect(contentRect)
{
}

BasicView::~BasicView()
{
    CloseFont(_font);
}


void BasicView::clearContent()
{
    FillAreaRect(_contentRect,WHITE);
}

void BasicView::clicked(int x, int y)
{
    SetFont(_font, BLACK);
    DrawTextRect(x,y,_fontHeight,_fontHeight,"*",ALIGN_CENTER);
}