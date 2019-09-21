/*!
 * This file is part of SmartServoFramework.
 * Copyright (c) 2014, INRIA, All rights reserved.
 *
 * SmartServoFramework is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software. If not, see <http://www.gnu.org/licenses/lgpl-3.0.txt>.
 *
 * \file settings.h
 * \date 05/11/2014
 * \author Emeric Grange <emeric.grange@gmail.com>
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include "SmartServoFramework/ServoTools.h"

#include <vector>

#include <QSettings>
#include <QWidget>

namespace Ui {
class Settings;
}

struct portConfig
{
    bool enabled = false;
    QString path;
    ServoProtocol protocol = ServoProtocol::PROTOCOL_DXLv1;
    int speed = 1000000;
    int firstAddress = 0;
    int lastAddress = 253;
};

class Settings : public QWidget
{
    Q_OBJECT

    enum PortWidgetColumns {
        Col_Enabled,
        Col_PortName,
        Col_Protocol,
        Col_Baud,
        Col_FirstAddress,
        Col_LastAddress
    };

    Ui::Settings *ui;

    // Settings
    bool ui_pause = false;
    bool ctrl_autoscan = true;
    bool ctrl_locks = true;
    int ctrl_freq = 10;
    QVector<struct portConfig> serial_ports;
    QSettings m_settings;
    void addPortWidgets(const struct portConfig config, int row);
    void loadSettings();

    void loadSerialPorts();

private slots:
    void on_pushButton_save_clicked();

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    bool getAutoScan();
    bool getLock();
    bool getPause();
    int getFreq();
    const QVector<portConfig> &getSerialPortsConfig();
    const portConfig *getSerialPortConfig(const QString& portPath);

    int writeSettings();

    void reloadPorts();

signals:
    void settingsSaved();
};

#endif // SETTINGS_H
