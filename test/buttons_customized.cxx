//
// "$Id$"
//
// Another button test program for the Fast Light Tool Kit (FLTK).
// Show how to modify button appearance using boxtypes.
//
// Copyright 1998-2010 by Bill Spitzak and others.
//
// This library is free software. Distribution and use rights are outlined in
// the file "COPYING" which should have been included with this file.  If this
// file is missing or damaged, see the license at:
//
//     http://www.fltk.org/COPYING.php
//
// Please report all bugs and problems on the following page:
//
//     http://www.fltk.org/str.php
//

#include <stdlib.h>
#include <stdio.h>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Tooltip.H>
#include <FL/fl_ask.H>

static void draw_up_box(int x, int y, int w, int h, Fl_Color c) {
  fl_color(c);
  fl_rectf(x, y, w, h);
  fl_color(FL_WHITE);
  fl_line(x, y+h-1, x, y, x+w-1, y);
  fl_color(FL_BLACK);
  fl_line(x+w-1, y+1, x+w-1, y+h-1, x+1, y+h-1);
}
static void draw_down_box(int x, int y, int w, int h, Fl_Color c) {
  fl_color(c);
  fl_rectf(x, y, w, h);
  fl_color(FL_BLACK);
  fl_line(x, y+h-1, x, y, x+w-1, y);
  fl_color(FL_WHITE);
  fl_line(x+w-1, y+1, x+w-1, y+h-1, x+1, y+h-1);
}

/** The parameters x,y,w,h,color are the same that are used for  
    drawing the underlying box type background. */
static void draw_focus_rect(int x, int y, int w, int h, Fl_Color color) {
  fl_color(0xb0b0b000);
  fl_rect(x, y, w, h);
}
static void draw_focus_rect_up(int x, int y, int w, int h, Fl_Color color) {
  fl_color(0xb0b0b000);
  fl_rect(x+2, y+2, w-4, h-4);
}
static void draw_focus_rect_down(int x, int y, int w, int h, Fl_Color color) {
  // could be different than draw_focus_rect_up
  fl_color(0xb0b0b000);
  fl_rect(x+2, y+2, w-4, h-4);
}

void buttoncb(Fl_Widget *, void *) {
  fl_choice("fl_choice box.", "button1", "button2", "button3");
}

int main(int argc, char** argv) {

  // Init global FLTK stuff:
  Fl::args(argc, argv);
  // Init application specific theming
  Fl::set_color(FL_BACKGROUND_COLOR,  0xede9e300);
  Fl::set_color(FL_BACKGROUND2_COLOR, 0xffffff00);
  Fl::set_focus_rect(FL_NO_BOX, draw_focus_rect);
  Fl::set_boxtype(FL_UP_BOX,   &draw_up_box,   2,2,4,4, &draw_focus_rect_up);
  Fl::set_boxtype(FL_DOWN_BOX, &draw_down_box, 3,3,4,4, &draw_focus_rect_down);
    
  // Normal application code:
  Fl_Window* window = new Fl_Window(320,130);
  Fl_Button*        b1 = new Fl_Button(10, 10, 130, 30, "Fl &Button");
  Fl_Return_Button* b2 = new Fl_Return_Button(150, 10, 160, 30, "Fl Return Button");
  Fl_Repeat_Button* b3 = new Fl_Repeat_Button(10,50,130,30,"Fl Repeat Button");
  Fl_Light_Button*  b4 = new Fl_Light_Button(10,90,130,30,"Fl &Light Button");
  Fl_Round_Button*  b5 = new Fl_Round_Button(150,50,160,30,"Fl &Round Button");
  Fl_Check_Button*  b6 = new Fl_Check_Button(150,90,160,30,"Fl &Check Button");
  b1->tooltip("This is a Tooltip.");
  b2->callback(buttoncb, 0);
  window->end();
  window->show();
  return Fl::run();
}

//
// End of "$Id$".
//
