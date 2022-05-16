/*
 * Copyright (C) 2022 UnionTech Technology Co., Ltd.
 *
 * Author:     yeshanshan <yeshanshan@uniontech.com>
 *
 * Maintainer: yeshanshan <yeshanshan@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QObject>

#include <com_deepin_daemon_display.h>
#include <com_deepin_daemon_display_monitor.h>
#include <com_deepin_dde_daemon_dock.h>
using DisplayInter = com::deepin::daemon::Display;
using DockInter = com::deepin::dde::daemon::Dock;

class GeometryHandler : public QObject {
    Q_OBJECT
public:
    explicit GeometryHandler(QObject *parent = nullptr);
    virtual ~GeometryHandler() override;

    QRect getGeometry(const int expectedWidth);

    QRect calcDisplayRect(const QRect &dockRect);
private:
    DisplayInter *m_displayInter = nullptr;
    DockInter *m_dockDeamonInter = nullptr;
};