/*
 * Copyright 2008 Benjamin C. Meyer <ben@meyerhome.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QtGui>
#include <QtWebKit/QtWebKit>
#include "actioncollection.h"
#include "actionmanager.h"

class SubWebView : public QWebView, public ActionCollection
{
    Q_OBJECT
public:
    SubWebView(QWidget *parent = 0);

};

class SubTextEdit : public QTextEdit, public ActionCollection
{
    Q_OBJECT
public:
    SubTextEdit(QWidget *parent = 0);

};

class MainWindow : public QMainWindow, public ActionCollection
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

private slots:
    void currentChanged(int);
    void configureShortcuts();

private:
    QTabWidget *tabWidget;
    ActionManager *actionManager;
};


#endif // MAINWINDOW_H
