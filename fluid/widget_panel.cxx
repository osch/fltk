// generated by Fast Light User Interface Designer (fluid) version 2.0000

#include "widget_panel.h"

Fl_Tabs *panel_tabs=(Fl_Tabs *)0;

Fl_Box *image_label=(Fl_Box *)0;

Fl_Light_Button *include_image_button=(Fl_Light_Button *)0;

Fl_Value_Input *widget_x=(Fl_Value_Input *)0;

Fl_Value_Input *widget_y=(Fl_Value_Input *)0;

Fl_Value_Input *widget_width=(Fl_Value_Input *)0;

Fl_Value_Input *widget_height=(Fl_Value_Input *)0;

Fl_Light_Button *set_xy=(Fl_Light_Button *)0;

Fl_Input *v_input[4]={(Fl_Input *)0};

Fl_Box *callback_label=(Fl_Box *)0;

Fl_Light_Button *overlaybutton=(Fl_Light_Button *)0;

Fl_Window* make_widget_panel() {
  Fl_Window* w;
  { Fl_Window* o = new Fl_Window(380, 375);
    w = o;
    ((Fl_Window*)(o))->hotspot(o);
    { Fl_Tabs* o = panel_tabs = new Fl_Tabs(10, 10, 365, 320);
      o->callback((Fl_Callback*)propagate_tabs);
      { Fl_Group* o = new Fl_Group(10, 35, 365, 295, "GUI");
        o->callback((Fl_Callback*)propagate_group);
        { Fl_Input* o = new Fl_Input(90, 45, 275, 25, "Label:");
          o->callback((Fl_Callback*)label_cb);
          o->when(FL_WHEN_CHANGED);
          o->tooltip("Text displayed on or next to the widget");
        }
        { Fl_Box* o = image_label = new Fl_Box(19, 70, 71, 20, "Image:");
          o->align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE);
        }
        { Fl_Button* o = new Fl_Button(90, 70, 195, 25, "Image name");
          o->callback((Fl_Callback*)image_cb);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
          o->tooltip("Select an image to label the widget");
          o->color(o->window_color());
          o->box(o->window_box());
        }
        { Fl_Light_Button* o = include_image_button = new Fl_Light_Button(285, 70, 80, 25, "image inlined");
          o->label_size(10);
          o->callback((Fl_Callback*)image_inlined_cb);
          o->align(132|FL_ALIGN_INSIDE);
          o->tooltip("Include the datas of the image inlined in \nthe code or keep it in an externa\
l file");
        }
        { Fl_Box* o = new Fl_Box(20, 100, 70, 20, "Alignment:");
          o->align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE);
        }
        { Fl_Button* o = new Fl_Button(90, 100, 44, 20, "tiled");
          o->type(101);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_TILED));
          o->tooltip("Draw the image tiled");
        }
        { Fl_Button* o = new Fl_Button(134, 100, 43, 20, "clip");
          o->type(101);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_CLIP));
          o->tooltip("Turn on clipping to the widget\'s area when drawing\nlabel.  This is slower s\
o it should be left off if label will fit");
        }
        { Fl_Button* o = new Fl_Button(177, 100, 43, 20, "wrap");
          o->type(101);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_WRAP));
          o->tooltip("Word-wrap the label");
        }
        { Fl_Button* o = new Fl_Button(265, 100, 20, 20, "@-1<-");
          o->type(101);
          o->label_type(FL_SYMBOL_LABEL);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_LEFT));
          o->tooltip("Places label on the left of the widget");
        }
        { Fl_Button* o = new Fl_Button(285, 100, 20, 20, "@-1->");
          o->type(101);
          o->label_type(FL_SYMBOL_LABEL);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_RIGHT));
          o->tooltip("Places label on the right of the widget");
        }
        { Fl_Button* o = new Fl_Button(305, 100, 20, 20, "@-18");
          o->type(101);
          o->label_type(FL_SYMBOL_LABEL);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_TOP));
          o->tooltip("Places label on the top of the widget");
        }
        { Fl_Button* o = new Fl_Button(325, 100, 20, 20, "@-12");
          o->type(101);
          o->label_type(FL_SYMBOL_LABEL);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_BOTTOM));
          o->tooltip("Places label on the bottom of the widget");
        }
        { Fl_Button* o = new Fl_Button(345, 100, 20, 20, "@-3square");
          o->type(101);
          o->label_type(FL_SYMBOL_LABEL);
          o->callback((Fl_Callback*)align_cb, (void*)(FL_ALIGN_INSIDE));
          o->tooltip("Places label inside the widget");
        }
        { Fl_Value_Input* o = widget_x = new Fl_Value_Input(90, 135, 55, 25, "X:");
          o->label_size(10);
          o->maximum(2000);
          o->step(1);
          o->value(10);
          o->callback((Fl_Callback*)x_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->tooltip("The x coordinate of the widget.");
        }
        { Fl_Value_Input* o = widget_y = new Fl_Value_Input(145, 135, 55, 25, "Y:");
          o->label_size(10);
          o->maximum(2000);
          o->step(1);
          o->value(10);
          o->callback((Fl_Callback*)y_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->tooltip("The y coordinate of the widget.");
        }
        { Fl_Value_Input* o = widget_width = new Fl_Value_Input(200, 135, 55, 25, "Width:");
          o->label_size(10);
          o->maximum(2000);
          o->step(1);
          o->value(10);
          o->callback((Fl_Callback*)width_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->tooltip("The width of the widget.");
        }
        { Fl_Value_Input* o = widget_height = new Fl_Value_Input(255, 135, 55, 25, "Height:");
          o->label_size(10);
          o->maximum(2000);
          o->step(1);
          o->value(10);
          o->callback((Fl_Callback*)height_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->tooltip("The height of the widget.");
        }
        { Fl_Light_Button* o = set_xy = new Fl_Light_Button(310, 135, 55, 25, "Set xy");
          o->label_size(10);
          o->callback((Fl_Callback*)set_xy_cb);
          o->tooltip("Determines if a window is initially set to a given position.");
        }
        { Fl_Input* o = new Fl_Input(90, 165, 95, 25, "X Class:");
          o->callback((Fl_Callback*)xclass_cb);
          o->when(FL_WHEN_CHANGED);
          o->tooltip("The X class name which should be used for this widget.  This can be used to c\
hoose icons.");
        }
        { Fl_Light_Button* o = new Fl_Light_Button(185, 165, 55, 25, "Border");
          o->label_size(10);
          o->callback((Fl_Callback*)border_cb);
          o->tooltip("Enable the window manager border");
        }
        { Fl_Light_Button* o = new Fl_Light_Button(240, 165, 55, 25, "Modal");
          o->label_size(10);
          o->callback((Fl_Callback*)modal_cb);
          o->tooltip("This window will stay on top of others in the\napplication and will prevent e\
vents from going to other windows.");
        }
        { Fl_Light_Button* o = new Fl_Light_Button(295, 165, 70, 25, "Nonmodal");
          o->label_size(10);
          o->callback((Fl_Callback*)non_modal_cb);
          o->tooltip("This window will stay on top of others in the application.");
        }
        { Fl_Value_Input* o = new Fl_Value_Input(90, 170, 53, 20, "Value:");
          o->label_size(10);
          o->callback((Fl_Callback*)value_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->hide();
          o->tooltip("The initial value (integer) of this widget");
        }
        { Fl_Value_Input* o = new Fl_Value_Input(143, 170, 53, 20, "Minimum:");
          o->label_size(10);
          o->callback((Fl_Callback*)min_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->hide();
          o->tooltip("The minimum value for this valuator");
        }
        { Fl_Value_Input* o = new Fl_Value_Input(196, 170, 53, 20, "Maximum:");
          o->label_size(10);
          o->value(1);
          o->callback((Fl_Callback*)max_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->hide();
          o->tooltip("The maximum value for this valuator");
        }
        { Fl_Value_Input* o = new Fl_Value_Input(249, 170, 53, 20, "Size:");
          o->label_size(10);
          o->callback((Fl_Callback*)slider_size_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->hide();
          o->tooltip("The size of the scroller");
        }
        { Fl_Value_Input* o = new Fl_Value_Input(302, 170, 63, 20, "Step:");
          o->label_size(10);
          o->callback((Fl_Callback*)step_cb);
          o->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
          o->hide();
          o->tooltip("Amount to change this valuator when mouse moves 1 pixel");
        }
        { Fl_Group* o = new Fl_Group(90, 190, 275, 25, "Attributes:");
          o->callback((Fl_Callback*)propagate_group);
          o->align(FL_ALIGN_LEFT);
          { Fl_Light_Button* o = new Fl_Light_Button(90, 190, 70, 25, "Visible");
            o->label_size(10);
            o->callback((Fl_Callback*)visible_cb);
            o->tooltip("Determines whether the widget is initially visible");
          }
          { Fl_Light_Button* o = new Fl_Light_Button(160, 190, 65, 25, "Active");
            o->label_size(10);
            o->callback((Fl_Callback*)active_cb);
            o->tooltip("Determines whether the widget is initially active (enabled)");
          }
          { Fl_Light_Button* o = new Fl_Light_Button(225, 190, 70, 25, "Resizable");
            o->label_size(10);
            o->callback((Fl_Callback*)resizable_cb);
            o->when(FL_WHEN_CHANGED);
            o->tooltip("If on, this widget and all it\'s parents are resizable.  When the parent resi\
zes it moves/resizes all it\'s children so that this widget\'s edges remain th\
e same distance from all four sides of the parent.  If this is off this widget\
 will not resize, unless it overlaps a resizable sibling.");
          }
          { Fl_Light_Button* o = new Fl_Light_Button(295, 190, 70, 25, "Hotspot");
            o->label_size(10);
            o->callback((Fl_Callback*)hotspot_cb);
            o->when(FL_WHEN_CHANGED);
            o->tooltip("Positions the window so this widget is under the mouse.  This is done when sh\
ow() is called.");
          }
          o->end();
        }
        { Shortcut_Button* o = new Shortcut_Button(90, 215, 275, 25, "Shortcut:");
          o->callback((Fl_Callback*)shortcut_in_cb);
          o->align(FL_ALIGN_LEFT);
          o->tooltip("To set a shortcut click here, then type the key combination you want.  To del\
ete the shortcut type backspace.  To stop setting the shortcut click the mouse\
 on some other field.");
        }
        { Fl_Input* o = new Fl_Input(90, 240, 275, 80, "Tooltip:");
          o->type(4);
          o->callback((Fl_Callback*)tooltip_cb);
          o->tooltip("The pop up tooltip which should be used for the widget.");
        }
        { Fl_Box* o = new Fl_Box(90, 240, 275, 80, "resizable");
          o->hide();
          o->deactivate();
          Fl_Group::current()->resizable(o);
        }
        o->end();
        Fl_Group::current()->resizable(o);
      }
      { Fl_Group* o = new Fl_Group(10, 35, 365, 295, "Style");
        o->callback((Fl_Callback*)propagate_group);
        o->hide();
        { Fl_Choice* o = new Fl_Choice(95, 45, 270, 25, "Box:"); o->begin();
          o->callback((Fl_Callback*)box_cb);
          o->tooltip("Type of box to draw around the widget (or the raised parts such as buttons of\
 a complex widget)");
          o->menu(boxmenu);
          o->end();
        }
        { Fl_Choice* o = new Fl_Choice(95, 70, 270, 25, "Window Box:"); o->begin();
          o->callback((Fl_Callback*)window_box_cb);
          o->tooltip("Type of box to draw around a text display or other sunken area of the widget.");
          o->menu(boxmenu);
          o->end();
        }
        { Fl_Choice* o = new Fl_Choice(95, 95, 270, 25, "Label Type:"); o->begin();
          o->callback((Fl_Callback*)labeltype_cb);
          o->tooltip("How to draw the label");
          o->menu(labeltypemenu);
          o->end();
        }
        { Fl_Choice* o = new Fl_Choice(95, 120, 215, 25, "Label Font:"); o->begin();
          o->callback((Fl_Callback*)labelfont_cb);
          o->tooltip("Font to use for the label");
          o->menu(fontmenu);
          o->end();
        }
        { Fl_Value_Input* o = new Fl_Value_Input(310, 120, 55, 25);
          o->maximum(100);
          o->step(1);
          o->value(14);
          o->callback((Fl_Callback*)labelsize_cb);
          o->tooltip("Size of the font to use for the label");
        }
        { Fl_Choice* o = new Fl_Choice(95, 145, 215, 25, "Text Font:"); o->begin();
          o->callback((Fl_Callback*)textfont_cb);
          o->tooltip("Font to use for text displayed inside the widget");
          o->menu(fontmenu);
          o->end();
        }
        { Fl_Value_Input* o = new Fl_Value_Input(310, 145, 55, 25);
          o->maximum(100);
          o->step(1);
          o->value(14);
          o->callback((Fl_Callback*)textsize_cb);
          o->tooltip("Size of the font to use for text displayed inside the widget");
        }
        { Fl_Light_Button* o = new Fl_Light_Button(95, 180, 135, 25, "Color");
          o->label_size(10);
          o->callback((Fl_Callback*)color_cb);
          o->tooltip("Color of the widget (or of raised parts such as buttons of a complex widget)");
          o->type(0);
        }
        { Fl_Light_Button* o = new Fl_Light_Button(230, 180, 135, 25, "Label Color");
          o->label_size(10);
          o->callback((Fl_Callback*)labelcolor_cb);
          o->tooltip("Color to draw the label");
          o->type(0);
        }
        { Fl_Light_Button* o = new Fl_Light_Button(95, 205, 135, 25, "Highlight Color");
          o->label_size(10);
          o->callback((Fl_Callback*)highlightcolor_cb);
          o->tooltip("Color to use to draw the widget highlighted.  Use color zero (the black top-l\
eft chip in the color chooser) to disable highlighting.");
          o->type(0);
        }
        { Fl_Light_Button* o = new Fl_Light_Button(230, 205, 135, 25, "Highlight Label Color");
          o->label_size(10);
          o->callback((Fl_Callback*)highlight_label_color_cb);
          o->tooltip("Color to draw the label when the widget is highlighted.  Use color zero (the \
black top-left chip in the color chooser) to leave the label colors unchanged.");
          o->type(0);
        }
        { Fl_Box* o = new Fl_Box(30, 220, 63, 20, "Colors:");
          o->align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE);
        }
        { Fl_Light_Button* o = new Fl_Light_Button(95, 230, 135, 25, "Window Color");
          o->label_size(10);
          o->callback((Fl_Callback*)color3_cb);
          o->tooltip("Color to draw a text display or other sunken area.");
          o->type(0);
        }
        { Fl_Light_Button* o = new Fl_Light_Button(230, 230, 135, 25, "Text Color");
          o->label_size(10);
          o->callback((Fl_Callback*)textcolor_cb);
          o->tooltip("Color to draw text displayed inside the widget");
          o->type(0);
        }
        { Fl_Light_Button* o = new Fl_Light_Button(95, 255, 135, 25, "Selection Color");
          o->label_size(10);
          o->callback((Fl_Callback*)color2_cb);
          o->tooltip("Color to draw behind selected text, or to color in buttons that are turned on\
.");
          o->type(0);
        }
        { Fl_Light_Button* o = new Fl_Light_Button(230, 255, 135, 25, "Selected Text Color");
          o->label_size(10);
          o->callback((Fl_Callback*)selected_textcolor_cb);
          o->tooltip("Color to draw selected text inside the widget");
          o->type(0);
        }
        { Fl_Box* o = new Fl_Box(95, 180, 270, 100, "resizable");
          o->hide();
          o->deactivate();
          Fl_Group::current()->resizable(o);
        }
        { Fl_Button* o = new Fl_Button(95, 295, 124, 25, "Reset to default");
          o->callback((Fl_Callback*)default_cb);
          o->tooltip("Resets the style to this widget\'s default values");
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(10, 35, 365, 295, "C++");
        o->callback((Fl_Callback*)propagate_group);
        o->hide();
        { Fl_Input* o = new Fl_Input(90, 45, 170, 25, "Class:");
          o->callback((Fl_Callback*)subclass_cb, (void*)(4));
          o->when(FL_WHEN_CHANGED);
          o->tooltip("This allows you to name a user-defined class that this widget is an instance \
of, rather than an fltk built-in class. You will need to add a #include declar\
ation so that the definition of your class is included in the fluid output.");
        }
        { Fl_Choice* o = new Fl_Choice(260, 45, 105, 25); o->begin();
          o->callback((Fl_Callback*)subtype_cb);
          o->tooltip("Selects a value for type() for this widget");
          o->end();
        }
        { Fl_Input* o = new Fl_Input(90, 70, 220, 25, "Name:");
          o->callback((Fl_Callback*)name_cb);
          o->when(FL_WHEN_CHANGED);
          o->tooltip("The variable or member name in which to store a pointer to this widget.");
        }
        { Fl_Light_Button* o = new Fl_Light_Button(310, 70, 55, 25, "public");
          o->label_size(10);
          o->callback((Fl_Callback*)name_public_cb);
          o->when(FL_WHEN_CHANGED);
          o->tooltip("Make the variable public");
        }
        { Fl_Input* o = v_input[0] = new Fl_Input(90, 95, 275, 25, "Extra Code:");
          o->callback((Fl_Callback*)v_input_cb, (void*)(0));
          o->tooltip("Extra code to be exectuted when the widget is created");
        }
        { Fl_Input* o = v_input[1] = new Fl_Input(90, 120, 275, 25);
          o->callback((Fl_Callback*)v_input_cb, (void*)(1));
          o->tooltip("Extra code to be exectuted when the widget is created");
        }
        { Fl_Input* o = v_input[2] = new Fl_Input(90, 145, 275, 25);
          o->callback((Fl_Callback*)v_input_cb, (void*)(2));
          o->tooltip("Extra code to be exectuted when the widget is created");
        }
        { Fl_Input* o = v_input[3] = new Fl_Input(90, 170, 275, 25);
          o->callback((Fl_Callback*)v_input_cb, (void*)(3));
          o->tooltip("Extra code to be exectuted when the widget is created");
        }
        { Fl_Box* o = callback_label = new Fl_Box(20, 195, 70, 20, "Callback:");
          o->align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE);
        }
        { Fl_Input* o = new Fl_Input(90, 195, 275, 80);
          o->type(4);
          o->callback((Fl_Callback*)callback_cb);
          o->tooltip("The name of the callback function, or code body of the callback function");
        }
        { Fl_Box* o = new Fl_Box(90, 200, 165, 65, "resizable");
          o->hide();
          o->deactivate();
          Fl_Group::current()->resizable(o);
        }
        { Fl_Input* o = new Fl_Input(90, 275, 130, 25, "User Data:");
          o->callback((Fl_Callback*)user_data_cb);
          o->tooltip("Value passed as the second argument to the callback.  This must be of the typ\
e given below.");
        }
        { Fl_Choice* o = new Fl_Choice(255, 275, 110, 25, "When:"); o->begin();
          o->label_size(10);
          o->callback((Fl_Callback*)when_cb);
          o->when(FL_WHEN_NEVER);
          o->tooltip("What actions cause the callback to be called.");
          o->menu(whenmenu);
          o->end();
        }
        { Fl_Input* o = new Fl_Input(90, 300, 130, 25, "Type:");
          o->callback((Fl_Callback*)user_data_type_cb);
          o->tooltip("Type of the user data (must \\\"long\\\" or a pointer type)");
        }
        { Fl_Light_Button* o = new Fl_Light_Button(255, 300, 110, 25, "no change");
          o->label_size(10);
          o->callback((Fl_Callback*)when_button_cb);
          o->when(FL_WHEN_NEVER);
          o->tooltip("Further modifies When so that the callback is done even if the widget\'s valu\
e has not changed.");
        }
        o->end();
      }
      o->end();
      Fl_Group::current()->resizable(o);
    }
    { Fl_Group* o = new Fl_Group(95, 340, 275, 25);
      { Fl_Light_Button* o = overlaybutton = new Fl_Light_Button(95, 340, 90, 25, "&Overlays");
        o->callback((Fl_Callback*)overlay_cb);
        o->tooltip("Turns overlays (red outlines)  of the selected  widgets on or off");
        o->value(!overlays_invisible);
      }
      { Fl_Return_Button* o = new Fl_Return_Button(225, 340, 65, 25, "OK");
        o->shortcut(0xff0d);
        o->callback((Fl_Callback*)ok_cb);
        o->tooltip("Closes this attribute window");
      }
      { Fl_Button* o = new Fl_Button(300, 340, 70, 25, "Cancel");
        o->callback((Fl_Callback*)cancel_cb);
      }
      o->end();
    }
    o->end();
  }
  return w;
}
