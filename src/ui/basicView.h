//------------------------------------------------------------------
// basicView.h
//
// Author:           JuanJakobo
// Date:             19.12.2020
// Description:      An basic UI class that displays fingertips on the screen 
//-------------------------------------------------------------------

#ifndef LISTVIEW
#define LISTVIEW

#include "inkview.h"

class BasicView
{
public:
    /**
        * Clears the contentarea and defines the content size for the View 
        * 
        * @param ContentRect area of the screen where the list view is placed
        */
    BasicView(const irect *contentRect);

    /**
     * Destructor
     */
    ~BasicView();

    /**
        * Clears the contentarea 
        * 
        */
    void clearContent();

    /**
        * draws a star on the position touched by the user
        * 
        * @param x x-coordinate
        * @param y y-coordinate
        */
    void clicked(int x, int y);

private:
    const irect *_contentRect;
    int _fontHeight = 35;
    ifont *_font = OpenFont("LiberationMono", _fontHeight, 1);

};
#endif