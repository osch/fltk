//
// "$Id: Fl_Choice.cxx,v 1.48 2000/08/20 04:31:38 spitzak Exp $"
//
// Choice widget for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-1999 by Bill Spitzak and others.
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
// Please report all bugs and problems to "fltk-bugs@easysw.com".
//

#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_draw.H>

// The dimensions for the glyph in this and the Fl_Menu_Button are exactly
// the same, so that glyphs may be shared between them.

extern char fl_draw_shortcut;

void Fl_Choice::draw() {
  draw_button();
  int X=x(); int Y=y(); int W=w(); int H=h(); box()->inset(X,Y,W,H);
  int w1 = H*4/5;
  Fl_Widget* o = children() ? item() : 0;

// CET - this would look great for a combo box but not for a choice
//  Fl_Color label_color = o ? o->label_color() : lc;
//  if (focused()) {
//    Fl_Color c = selection_color();
//    if (c) {
//      fl_color(c);
//      fl_rectf(X+2, Y+2, W-w1-4, H-4);
//      c = selection_text_color(); if (c) label_color = c;
//    }
//  }
  if (o) {
    fl_clip(X+2, Y+2, W-w1-2, H-4);
    o->x(X);
    o->y(Y+(H-o->height())/2);
    int save_w = o->w(); o->w(W-w1);
    fl_color(o->label_color());
    if (!(flags() & FL_NO_SHORTCUT_LABEL)) fl_draw_shortcut = 2;
    o->clear_flag(FL_SELECTED);
    o->draw();
    fl_draw_shortcut = 0;
    o->w(save_w);
    fl_pop_clip();
  }
  // draw the little mark at the right:
  draw_glyph(FL_GLYPH_CHOICE, X+W-w1-2, Y, w1, H, 0);
}

// int Fl_Choice::value(int v) {
//   value(find(v));
//   redraw();
//   return 1;
// }

int Fl_Choice::handle(int e) {
  if (!children()) return 0;
  switch (e) {

  case FL_FOCUS:
  case FL_UNFOCUS:
    damage(FL_DAMAGE_HIGHLIGHT);
    return 1;

  case FL_ENTER:
  case FL_LEAVE:
    if (highlight_color() && takesevents()) damage(FL_DAMAGE_HIGHLIGHT);
  case FL_MOVE:
    return 1;

  case FL_PUSH:
    // If you uncomment this line (or make a subclass that does this),
    // a mouse click picks the current item, and the menu goes away.  The
    // user must drag the mouse to select a different item.  Depending on
    // the size and usage of the menu, this may be more user-friendly.
//  Fl::event_is_click(0);
    take_focus();
  EXECUTE:
    if (pulldown(x(), y(), w(), h(), 0)) redraw();
    return 1;

  case FL_SHORTCUT:
    if (test_shortcut()) goto EXECUTE;
    if (handle_shortcut()) {redraw(); return 1;}
    return 0;

  case FL_KEYBOARD:
    switch (Fl::event_key()) {

    case FL_Enter:
    case ' ':
      goto EXECUTE;

    case FL_Up: {
      int i = value(); if (i < 0) i = children();
      while (i > 0) {
	Fl_Widget* w = child(--i);
	if (w->takesevents()) {value(i); execute(w); redraw(); break;}
      }
      return 1;}
    case FL_Down: {
      int i = value();
      while (++i < children()) {
	Fl_Widget* w = child(i);
	if (w->takesevents()) {value(i); execute(w); redraw(); break;}
      }
      return 1;}
    }
    return 0;

  default:
    return 0;
  }
}

static void revert(Fl_Style* s) {
//  s->selection_color = FL_GRAY;
//  s->selection_text_color = FL_BLACK;
  s->text_box = FL_NO_BOX;
  s->text_background = FL_GRAY;
}

static Fl_Named_Style* style = new Fl_Named_Style("Choice", revert, &style);

Fl_Choice::Fl_Choice(int x,int y,int w,int h, const char *l) : Fl_Menu_(x,y,w,h,l) {
  value(0);
  style(::style);
  clear_flag(FL_ALIGN_MASK);
  set_flag(FL_ALIGN_LEFT);
  when(FL_WHEN_RELEASE);
}

//
// End of "$Id: Fl_Choice.cxx,v 1.48 2000/08/20 04:31:38 spitzak Exp $".
//
