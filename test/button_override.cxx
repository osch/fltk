//
// "$Id$"
//
// Shows how to override button handle method for the Fast Light Tool Kit (FLTK).
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
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Tooltip.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>

class SpecialClassOverrides : Fl_Button, Fl_Light_Button {

  struct ButtonOverrideData : public Fl_Override_Data {
    Fl_Color mouse_hover_color;
    Fl_Color background_color;
    ButtonOverrideData() {
      mouse_hover_color = -1;
      background_color  = -1;
    }
  };

  static Fl_Override_Data* button_init() {
    return new ButtonOverrideData();
  }
  static int button_handle(Fl_Button* w, int event) {
    ButtonOverrideData* d = (ButtonOverrideData*)Fl_Button::override_data(w);
    if (d->background_color == -1) {
      d->background_color = w->color();
      Fl_Color light_color = fl_contrast(FL_WHITE, FL_FOREGROUND_COLOR);
      d->mouse_hover_color = fl_color_average(light_color, d->background_color, 0.7);
    }
    if (event == FL_ENTER && w->color() != d->mouse_hover_color) {
      w->color(d->mouse_hover_color);
      if (w->type() != FL_TOGGLE_BUTTON) 
        w->down_color(d->mouse_hover_color);
      w->redraw();
    } else if ((event == FL_LEAVE || event == FL_HIDE) && w->color() != d->background_color) {
      w->color(d->background_color);
      if (w->type() != FL_TOGGLE_BUTTON) 
        w->down_color(d->background_color);
      w->redraw();
    }
    return Fl_Button::default_handle(w, event);
  }
  
  static void light_button_draw(Fl_Light_Button* w) {
    fl_rectf(w->x(), w->y(), w->w(), w->h(), w->color());
    Fl_Light_Button::default_draw(w);
  }
  
public:
  static void setup() {
    Fl_Button::override_init(&button_init);
    Fl_Button::override_handle(&button_handle);
    Fl_Light_Button::override_draw(&light_button_draw);
  }

};



void buttoncb(Fl_Widget *, void *) {
  fl_choice("fl_choice box has overridden button handle methods.", "button1", "button2", "button3");
}



int main(int argc, char ** argv) {

  // Init global FLTK stuff:
  
  Fl::get_system_colors();
  Fl::args(argc, argv);

  // Init overriden class methods:
  
  SpecialClassOverrides::setup();
  
  // Normal application code:

  Fl_Window *window = new Fl_Window(320,130);
  Fl_Button *b1 = new Fl_Button(10, 10, 130, 30, "Fl_Button");
  Fl_Return_Button *b2 = new Fl_Return_Button(150, 10, 160, 30, "Fl_Return_Button");
  Fl_Repeat_Button *b3 = new Fl_Repeat_Button(10,50,130,30,"Fl_Repeat_Button");
  Fl_Light_Button  *b4 = new Fl_Light_Button(10,90,130,30,"Fl_Light_Button");
  Fl_Round_Button  *b5 = new Fl_Round_Button(150,50,160,30,"Fl_Round_Button");
  Fl_Check_Button  *b6 = new Fl_Check_Button(150,90,160,30,"Fl_Check_Button");
  b1->tooltip("This is a Tooltip.");
  b1->callback(buttoncb, 0);
  b2->callback(buttoncb, 0);
  b2->color(0x00cc0000);
  window->end();
  window->show();
  return Fl::run();
}

//
// End of "$Id$".
//
