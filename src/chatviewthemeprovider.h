/*
 * chatviewthemeprovider.h - adapter for set of chatview themes
 * Copyright (C) 2010 Rion (Sergey Ilinyh)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */


#ifndef CHATVIEWTHEMEPROVIDER_H
#define CHATVIEWTHEMEPROVIDER_H

#include "psithemeprovider.h"

class ChatViewTheme;

class ChatViewThemeProvider : public PsiThemeProvider
{
	Q_OBJECT

public:
	ChatViewThemeProvider(QObject *);

	const char* type() const { return "chatview"; }
	const QStringList themeIds() const;
	Theme* load(const QString &themeId);
	bool loadCurrent();
	Theme *current() const { return (Theme*)curTheme; }
	void setCurrentTheme(const QString &);
	virtual int screenshotWidth() const { return 512; } // hack

	QString optionsName() const { return tr("Chat Message Style"); }
	QString optionsDescription() const { return tr("Configure your chat theme here"); }

protected:
	virtual const char* optionString() const { return "options.ui.chat.theme"; }

signals:
	void themeChanged();

private:
	ChatViewTheme *curTheme;
};

class GroupChatViewThemeProvider : public ChatViewThemeProvider
{
	Q_OBJECT

public:
	GroupChatViewThemeProvider(QObject *parent) :
		ChatViewThemeProvider(parent) {}

	const char* type() const { return "groupchatview"; }
	QString optionsName() const { return tr("Groupchat Message Style"); }
	QString optionsDescription() const { return tr("Configure your groupchat theme here"); }

protected:
	const char* optionString() const { return "options.ui.muc.theme"; }
};

#endif // CHATVIEWTHEMEPROVIDER_H
