// Copyright 2009-2022 The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#ifndef MUMBLE_MUMBLE_USERVIEW_H_
#define MUMBLE_MUMBLE_USERVIEW_H_

#include <QtCore/QtGlobal>
#include <QtWidgets/QStyledItemDelegate>
#include <QtWidgets/QTreeView>

#include "Timer.h"

class UserDelegate : public QStyledItemDelegate {
private:
	Q_OBJECT
	Q_DISABLE_COPY(UserDelegate)

	int m_flagTotalDimension;
	int m_flagIconPadding;
	int m_flagIconDimension;

public:
	UserDelegate(QObject *parent, int flagTotalDimension, int flagIconPadding, int flagIconDimension);
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

public slots:
	bool helpEvent(QHelpEvent *event, QAbstractItemView *view, const QStyleOptionViewItem &option,
				   const QModelIndex &index) Q_DECL_OVERRIDE;
};

class UserView : public QTreeView {
private:
	Q_OBJECT
	Q_DISABLE_COPY(UserView)

	int m_flagTotalDimension;

protected:
	void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;
	void keyPressEvent(QKeyEvent *) Q_DECL_OVERRIDE;
	bool event(QEvent *) Q_DECL_OVERRIDE;

public:
	UserView(QWidget *);
	void keyboardSearch(const QString &search) Q_DECL_OVERRIDE;
	void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight,
					 const QVector< int > &roles = QVector< int >()) Q_DECL_OVERRIDE;

public slots:
	void nodeActivated(const QModelIndex &idx);
	void updateChannel(const QModelIndex &index);
};

#endif
