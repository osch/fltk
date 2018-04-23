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

class SpecialClassOverrides {
  
   struct ButtonOverrideData {
      Fl_Color mouse_hover_color;
      Fl_Color background_color;
      ButtonOverrideData() {
        mouse_hover_color = -1;
        background_color  = -1;
      }
  };
  
  static int button_handle(Fl_Button* w, ButtonOverrideData* d, int event) {
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
    return 0;
  }

  class SpecialButton : public Fl_Button {
    ButtonOverrideData data;
  public:  
    SpecialButton(int X, int Y, int W, int H, const char *L = 0) 
      : Fl_Button(X, Y, W, H, L) {
    }
    static Fl_Button* create(int X, int Y, int W, int H, const char *L = 0) {
      return new SpecialButton(X, Y, W, H, L);
    }
    virtual int handle(int event) {
      if (!button_handle(this, &data, event)) {
        return Fl_Button::handle(event);
      }
    }
  };

  class SpecialLightButton : public Fl_Light_Button {
    ButtonOverrideData data;
  public:  
    SpecialLightButton(int X, int Y, int W, int H, const char *L = 0) 
      : Fl_Light_Button(X, Y, W, H, L) {
    }
    static Fl_Light_Button* create(int X, int Y, int W, int H, const char *L = 0) {
      return new SpecialLightButton(X, Y, W, H, L);
    }
    virtual int handle(int event) {
      if (!button_handle(this, &data, event)) {
        return Fl_Light_Button::handle(event);
      }
    }
    virtual void draw() {
      fl_rectf(x(), y(), w(), h(), color());
      Fl_Light_Button::draw();
    }
  };
  
  class SpecialReturnButton : public Fl_Return_Button {
    ButtonOverrideData data;
  public:  
    SpecialReturnButton(int X, int Y, int W, int H, const char *L = 0) 
      : Fl_Return_Button(X, Y, W, H, L) {
    }
    static Fl_Return_Button* create(int X, int Y, int W, int H, const char *L = 0) {
      return new SpecialReturnButton(X, Y, W, H, L);
    }
    virtual int handle(int event) {
      if (!button_handle(this, &data, event)) {
        return Fl_Return_Button::handle(event);
      }
    }
  };

  class SpecialRepeatButton : public Fl_Repeat_Button {
    ButtonOverrideData data;
  public:  
    SpecialRepeatButton(int X, int Y, int W, int H, const char *L = 0) 
      : Fl_Repeat_Button(X, Y, W, H, L) {
    }
    static Fl_Repeat_Button* create(int X, int Y, int W, int H, const char *L = 0) {
      return new SpecialRepeatButton(X, Y, W, H, L);
    }
    virtual int handle(int event) {
      if (!button_handle(this, &data, event)) {
        return Fl_Repeat_Button::handle(event);
      }
    }
  };

  class SpecialRoundButton : public Fl_Round_Button {
    ButtonOverrideData data;
  public:  
    SpecialRoundButton(int X, int Y, int W, int H, const char *L = 0) 
      : Fl_Round_Button(X, Y, W, H, L) {
    }
    static Fl_Round_Button* create(int X, int Y, int W, int H, const char *L = 0) {
      return new SpecialRoundButton(X, Y, W, H, L);
    }
    virtual int handle(int event) {
      if (!button_handle(this, &data, event)) {
        return Fl_Round_Button::handle(event);
      }
    }
    virtual void draw() {
      fl_rectf(x(), y(), w(), h(), color());
      Fl_Round_Button::draw();
    }
  };

  class SpecialCheckButton : public Fl_Check_Button {
    ButtonOverrideData data;
  public:  
    SpecialCheckButton(int X, int Y, int W, int H, const char *L = 0) 
      : Fl_Check_Button(X, Y, W, H, L) {
    }
    static Fl_Check_Button* create(int X, int Y, int W, int H, const char *L = 0) {
      return new SpecialCheckButton(X, Y, W, H, L);
    }
    virtual int handle(int event) {
      if (!button_handle(this, &data, event)) {
        return Fl_Check_Button::handle(event);
      }
    }
    virtual void draw() {
      fl_rectf(x(), y(), w(), h(), color());
      Fl_Check_Button::draw();
    }
  };
public:
  static void setup() {
    Fl_Button::widget_factory(&SpecialButton::create);
    Fl_Light_Button::widget_factory(&SpecialLightButton::create);
    Fl_Return_Button::widget_factory(&SpecialReturnButton::create);
    Fl_Repeat_Button::widget_factory(&SpecialRepeatButton::create);
    Fl_Round_Button::widget_factory(&SpecialRoundButton::create);
    Fl_Check_Button::widget_factory(&SpecialCheckButton::create);
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
  Fl_Button *b1 = Fl_Button::create(10, 10, 130, 30, "Fl_Button");
  Fl_Return_Button *b2 = Fl_Return_Button::create(150, 10, 160, 30, "Fl_Return_Button");
  Fl_Repeat_Button *b3 = Fl_Repeat_Button::create(10,50,130,30,"Fl_Repeat_Button");
  Fl_Light_Button  *b4 = Fl_Light_Button::create(10,90,130,30,"Fl_Light_Button");
  Fl_Round_Button  *b5 = Fl_Round_Button::create(150,50,160,30,"Fl_Round_Button");
  Fl_Check_Button  *b6 = Fl_Check_Button::create(150,90,160,30,"Fl_Check_Button");
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
