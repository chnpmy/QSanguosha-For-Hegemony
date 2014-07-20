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
/*
#include "ChooseTriggerOrderBox.h"
#include "engine.h"
#include "roomscene.h"
#include "protocol.h"
#include "button.h"
#include "SkinBank.h"

#include <QApplication>

ChooseTriggerOrderBox::ChooseTriggerOrderBox()
    : optional(true), progress_bar(NULL)
{
    setFlag(ItemIsFocusable);
    setFlag(ItemIsMovable);
}

int ChooseTriggerOrderBox::getGeneralNum() const
{
    if (options.isEmpty())
        return 0;

    int count = 0;
    if (options.contains("GameRule_AskForGeneralShowHead"))
        ++ count;
    if (options.contains("GameRule_AskForGeneralShowDeputy"))
        ++ count;

    return count;
}

void ChooseTriggerOrderBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setBrush(QBrush(G_COMMON_LAYOUT.m_chooseGeneralBoxBackgroundColor));
    QRectF rect = boundingRect();
    const int x = rect.x();
    const int y = rect.y();
    const int w = rect.width();
    const int h = rect.height();
    painter->drawRect(QRect(x, y, w, h));
    painter->drawRect(QRect(x, y, w, top_dark_bar));
    G_COMMON_LAYOUT.m_chooseGeneralBoxTitleFont.paintText(painter, QRect(x, y, w, top_dark_bar), Qt::AlignCenter | Qt::AlignJustify, Sanguosha->translate(reason));
    painter->restore();
    painter->setPen(G_COMMON_LAYOUT.m_chooseGeneralBoxBorderColor);
    painter->drawRect(QRect(x + 1, y + 1, w - 2, h - 2));
}

QRectF ChooseTriggerOrderBox::boundingRect() const
{
    const int generalNum = getGeneralNum();
    const QSize generalSize = G_ROOM_SKIN.getGeneralPixmap(Self->getAvatarGeneral()->objectName() ,
                                                           G_DASHBOARD_LAYOUT.m_primaryAvatarSize()).size();
    const int width = generalSize * qMax(generalNum, 1) + left_blank_width * 2;

    int height = top_blank_width
            + (options.size() - generalNum) * default_button_height
            + (options.size() - generalNum - 1) * interval
            + bottom_blank_width;

    if (ServerInfo.OperationTimeout != 0)
        height += 12;

    if (generalNum > 0)
        height += generalSize.height() + interval;

    if (optional)
        height += cancel->boundingRect().height() + interval;

    return QRectF(0, 0, width, height);
}

void ChooseTriggerOrderBox::chooseOption(const QString &reason, const QStringList &options, const bool optional)
{
    this->reason = reason;
    this->options = options;
    this->optional = optional;
    update();

    buttons.clear();
    int z = 100;
    foreach (QString option, options) {
        QString title = QString("%1:%2").arg(skill_name).arg(option);
        QString tranlated = Sanguosha->translate(title);
        if (tranlated == title)
            tranlated = Sanguosha->translate(option);
        Button *button = new Button(tranlated, QSizeF(default_button_width, default_button_height), true);
        button->setFlag(QGraphicsItem::ItemIsFocusable);
        button->setObjectName(option);
        buttons << button;
        button->setParentItem(this);

        QString original_tooltip = QString(":%1").arg(title);
        QString tooltip = Sanguosha->translate(original_tooltip);
        if (tooltip == original_tooltip) {
            original_tooltip = QString(":%1").arg(option);
            tooltip = Sanguosha->translate(original_tooltip);
        }
        connect(button, SIGNAL(clicked()), this, SLOT(reply()));
        connect(button, SIGNAL(clicked()), ClientInstance, SLOT(onPlayerMakeChoice()));
        button->setZValue(--z);
        if (tooltip != original_tooltip) {
            //button->setToolTip(QString("<font color=%1>%2</font>").arg(Config.SkillDescriptionInToolTipColor.name()).arg(tooltip));
            ToolTipBox *tip_box = new ToolTipBox(tooltip);
            tip_box->hide();
            tip_box->setParentItem(button);
            tip_box->setZValue(10000);
            connect(button, SIGNAL(hover_entered()), tip_box, SLOT(showToolTip()));
            connect(button, SIGNAL(hover_left()), tip_box, SLOT(hideToolTip()));
        }
    }

    setPos(RoomSceneInstance->tableCenterPos() - QPointF(boundingRect().width() / 2, boundingRect().height() / 2));
    show();

    for (int i = 0; i < buttons.length(); ++i) {
        Button *button = buttons.at(i);

        QPointF pos;
        pos.setX(left_blank_width);
        pos.setY(top_blank_width + default_button_height * i + (i - 1) * interval + default_button_height / 2);

        button->setPos(pos);
    }

    if (ServerInfo.OperationTimeout != 0) {
        if (!progress_bar) {
            progress_bar = new QSanCommandProgressBar();
            progress_bar->setMaximumWidth(boundingRect().width() - 16);
            progress_bar->setMaximumHeight(12);
            progress_bar->setTimerEnabled(true);
            progress_bar_item = new QGraphicsProxyWidget(this);
            progress_bar_item->setWidget(progress_bar);
            progress_bar_item->setPos(boundingRect().center().x() - progress_bar_item->boundingRect().width() / 2, boundingRect().height() - 20);
            connect(progress_bar, SIGNAL(timedOut()), this, SLOT(reply()));
        }
        progress_bar->setCountdown(QSanProtocol::S_COMMAND_MULTIPLE_CHOICE);
        progress_bar->show();
    }
}

void ChooseTriggerOrderBox::reply()
{
    if (progress_bar != NULL){
        progress_bar->hide();
        progress_bar->deleteLater();
    }
    clear();
}

void ChooseTriggerOrderBox::clear()
{
    foreach(Button *button, buttons)
        button->deleteLater();

    buttons.clear();

    hide();
}
*/