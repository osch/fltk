//
// "$Id$"
//
// fltk3::ScrollGroup test program for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2010 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems on the following page:
//
//     http://www.fltk.org/str.php
//

#include <fltk3/run.h>
#include <fltk3/Double_Window.h>
#include <fltk3/Scroll.h>
#include <fltk3/Light_Button.h>
#include <fltk3/Choice.h>
#include <fltk3/Box.h>
#include <string.h>
#include <stdio.h>
#include <fltk3/draw.h>
#include <FL/math.h>

class Drawing : public Fl_Widget {
  void draw();
public:
  Drawing(int X,int Y,int W,int H,const char* L) : Fl_Widget(X,Y,W,H,L) {
    align(FL_ALIGN_TOP);
    box(FL_FLAT_BOX);
    color(FL_WHITE);
  }
};

void Drawing::draw() {
  draw_box();
  fl_push_matrix();
  fl_translate(x()+w()/2, y()+h()/2);
  fl_scale(w()/2, h()/2);
  fl_color(FL_BLACK);
  for (int i = 0; i < 20; i++) {
    for (int j = i+1; j < 20; j++) {
      fl_begin_line();
      fl_vertex(cos(M_PI*i/10+.1), sin(M_PI*i/10+.1));
      fl_vertex(cos(M_PI*j/10+.1), sin(M_PI*j/10+.1));
      fl_end_line();
    }
  }
  fl_pop_matrix();
}

fltk3::ScrollGroup* thescroll;

void box_cb(Fl_Widget* o, void*) {
  thescroll->box(((Fl_Button*)o)->value() ? FL_DOWN_FRAME : FL_NO_BOX);
  thescroll->redraw();
}

void type_cb(Fl_Widget*, void* v) {
  thescroll->type((uchar)((fl_intptr_t)v));
  thescroll->redraw();
}

fltk3::MenuItem choices[] = {
  {"0", 0, type_cb, (void*)0},
  {"HORIZONTAL", 0, type_cb, (void*)fltk3::ScrollGroup::HORIZONTAL},
  {"VERTICAL", 0, type_cb, (void*)fltk3::ScrollGroup::VERTICAL},
  {"BOTH", 0, type_cb, (void*)fltk3::ScrollGroup::BOTH},
  {"HORIZONTAL_ALWAYS", 0, type_cb, (void*)fltk3::ScrollGroup::HORIZONTAL_ALWAYS},
  {"VERTICAL_ALWAYS", 0, type_cb, (void*)fltk3::ScrollGroup::VERTICAL_ALWAYS},
  {"BOTH_ALWAYS", 0, type_cb, (void*)fltk3::ScrollGroup::BOTH_ALWAYS},
  {0}
};

void align_cb(Fl_Widget*, void* v) {
  thescroll->scrollbar.align((uchar)((fl_intptr_t)v));
  thescroll->redraw();
}

fltk3::MenuItem align_choices[] = {
  {"left+top", 0, align_cb, (void*)(FL_ALIGN_LEFT+FL_ALIGN_TOP)},
  {"left+bottom", 0, align_cb, (void*)(FL_ALIGN_LEFT+FL_ALIGN_BOTTOM)},
  {"right+top", 0, align_cb, (void*)(FL_ALIGN_RIGHT+FL_ALIGN_TOP)},
  {"right+bottom", 0, align_cb, (void*)(FL_ALIGN_RIGHT+FL_ALIGN_BOTTOM)},
  {0}
};

int main(int argc, char** argv) {
  Fl_Window window(5*75,400);
  window.box(FL_NO_BOX);
  fltk3::ScrollGroup scroll(0,0,5*75,300);

  int n = 0;
  for (int y=0; y<16; y++) for (int x=0; x<5; x++) {
    char buf[20]; sprintf(buf,"%d",n++);
    Fl_Button* b = new Fl_Button(x*75,y*25+(y>=8?5*75:0),75,25);
    b->copy_label(buf);
    b->color(n);
    b->labelcolor(FL_WHITE);
  }
  Drawing drawing(0,8*25,5*75,5*75,0);
  scroll.end();
  window.resizable(scroll);

  Fl_Box box(0,300,5*75,window.h()-300); // gray area below the scroll
  box.box(FL_FLAT_BOX);

  Fl_Light_Button but1(150, 310, 200, 25, "box");
  but1.callback(box_cb);
  
  fltk3::Choice choice(150, 335, 200, 25, "type():");
  choice.menu(choices);
  choice.value(3);

  fltk3::Choice achoice(150, 360, 200, 25, "scrollbar.align():");
  achoice.menu(align_choices);
  achoice.value(3);

  thescroll = &scroll;

  //scroll.box(FL_DOWN_BOX);
  //scroll.type(fltk3::ScrollGroup::VERTICAL);
  window.end();
  window.show(argc,argv);
  return fltk3::run();
}

//
// End of "$Id$".
//
