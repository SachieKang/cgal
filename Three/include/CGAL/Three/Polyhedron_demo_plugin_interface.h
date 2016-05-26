// Copyright (c) 2009-2015  GeometryFactory Sarl (France)
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
//
// Author(s)     : Laurent RINEAU

//! \file Polyhedron_demo_plugin_interface.h
#ifndef POLYHEDRON_DEMO_PLUGIN_INTERFACE_H
#define POLYHEDRON_DEMO_PLUGIN_INTERFACE_H

#include <QString>
#include <QList>
#include <QtPlugin>
#include <QDebug>

class QAction;
class QMainWindow;
class Messages_interface;
namespace CGAL {
namespace Three {
class Scene_interface;
  /*!
   * This class gives some virtual functions to help making a plugin
   */
class Polyhedron_demo_plugin_interface 
{
public:
  //! Destructor
  virtual ~Polyhedron_demo_plugin_interface() {}
  //!Initializes the plugin.
  virtual void init(QMainWindow*, CGAL::Three::Scene_interface*) {}
  //!Initializes the plugin.
  virtual void init(QMainWindow* mw, CGAL::Three::Scene_interface* sc, Messages_interface*) {
    init(mw, sc);
  }

  //! Checks the current state of the `Scene` or `MainWindow` and decides
  //! if the plugin can function, given that state.  Its actions are
  //! visible in contextmenus, if this returns true, not visible
  //! otherwise.  
  //!
  //! @returns \c true, if the plugin is applicable, \c false
  //! otherwise
  virtual bool applicable(QAction*) const = 0;
  //!The list of the actions of the plugin.
  virtual QList<QAction*> actions() const = 0;
  //!If you need to do something when the plugin is closed, do it here
  virtual void closure() {
 }
};
}
}
Q_DECLARE_INTERFACE(CGAL::Three::Polyhedron_demo_plugin_interface,
                    "com.geometryfactory.PolyhedronDemo.PluginInterface/1.0")

#endif // POLYHEDRON_DEMO_PLUGIN_INTERFACE_H
