/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** No Commercial Usage
** This file contains pre-release code and may only be used for
** evaluation and testing purposes.  It may not be used for commercial
** development.  You may use this file in accordance with the terms and
** conditions contained in the either Technology Preview License
** Agreement or the Beta Release License Agreement.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
** Qt for Windows(R) Licensees
** As a special exception, Nokia, as the sole copyright holder for Qt
** Designer, grants users of the Qt/Eclipse Integration plug-in the
** right for the Qt/Eclipse Integration to link to functionality
** provided by Qt Designer and its related libraries.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
****************************************************************************/

#include "edittreeview.h"

#include <QtGui/QKeyEvent>

EditTreeView::EditTreeView(QWidget *parent)
    : QTreeView(parent)
{
}

void EditTreeView::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Delete
        || event->key() == Qt::Key_Backspace)
        && model()) {
        removeOne();
    } else {
        QAbstractItemView::keyPressEvent(event);
    }
}

void EditTreeView::removeOne()
{
    if (!model())
        return;
    QModelIndex ci = currentIndex();
    int row = ci.row();
    model()->removeRow(row, ci.parent());
}

void EditTreeView::removeAll()
{
    if (!model())
        return;
    model()->removeRows(0, model()->rowCount(rootIndex()), rootIndex());
}

