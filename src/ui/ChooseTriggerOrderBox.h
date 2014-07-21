/********************************************************************
    Copyright (c) 2013-2014 - QSanguosha-Hegemony Team

    This file is part of QSanguosha-Hegemony.

    This game is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    See the LICENSE file for more details.

    QSanguosha-Hegemony Team
    *********************************************************************/

#ifndef CHOOSETRIGGERORDERBOX_H
#define CHOOSETRIGGERORDERBOX_H

class OptionButton : public QGraphicsObject {
    Q_OBJECT

    friend class ChooseTriggerOrderBox;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

private:
    explicit OptionButton(QGraphicsObject *parent, const QString &general, const QString &skill, const int width);

    QString skillName;
    QString generalName;
    int width;
};

class GeneralButton : public QGraphicsObject {
    Q_OBEJCT

    friend class ChooseTriggerOrderBox;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

private:
    explicit GeneralButton(QGraphicsObject *parent, const QString &general, const bool isHead);

    QString generalName;
    bool isHead;
};

class ChooseTriggerOrderBox : public QGraphicsObject {
    Q_OBJECT

public:
    explicit ChooseTriggerOrderBox();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void clear();

    inline void setSkillName(const QString &skillName) { skill_name = skillName; }

public slots:
    void chooseOption(const QString &reason, const QStringList &options, const bool optional);
    void reply();

private:
    QList<OptionButton *> buttons;
    static const int default_button_width = 100;
    static const int default_button_height = 30;
    static const int top_dark_bar = 27;
    static const int top_blank_width = 42;
    static const int bottom_blank_width = 25;
    static const int interval = 15;
    static const int left_blank_width = 37;

    QString reason;
    QStringList options;
    bool optional;

    Button *cancel;
    QGraphicsProxyWidget *progress_bar_item;
    QSanCommandProgressBar *progressBar;

    int getGeneralNum() const;
};

#endif // CHOOSETRIGGERORDERBOX_H
