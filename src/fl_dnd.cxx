//
// "$Id: fl_dnd.cxx,v 1.9 2004/03/25 18:13:18 spitzak Exp $"
//
// Drag & Drop code for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2003 by Bill Spitzak and others.
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
// Please report all bugs and problems to "fltk-bugs@fltk.org".
//

#include <config.h>
#if USE_X11
# include "fl_dnd_x.cxx"
#elif defined(_WIN32)
# include "fl_dnd_win32.cxx"
#elif defined(__APPLE__)
# include "fl_dnd_mac.cxx"
#else
#error
#endif

//
// End of "$Id: fl_dnd.cxx,v 1.9 2004/03/25 18:13:18 spitzak Exp $".
//
