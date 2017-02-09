/*
 * Copyright (C) 2016 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#include <QCoreApplication>

#include <QLocale>
#include <QLibraryInfo>
#include <QTranslator>

#include <iostream>

#include "wsgi.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(QStringLiteral("Cutelyst"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("cutelyst.org"));
    QCoreApplication::setApplicationName(QStringLiteral("cutelyst-wsgi"));
    QCoreApplication::setApplicationVersion(QStringLiteral(VERSION));

    CWSGI::WSGI wsgi;

    QCoreApplication app(argc, argv);

    qputenv("QT_LOGGING_CONF", "/home/daniel/cutelyst.ini");

//    QTranslator qtTranslator;
//    qtTranslator.load(QLatin1String("qt_") % QLocale::system().name(),
//                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
//    QCoreApplication::installTranslator(&qtTranslator);

    int ret = wsgi.load();
    if (ret) {
        return ret;
    }

    ret = app.exec();
    std::cout << "Cutelyst WSGI quit" << ret << QCoreApplication::applicationPid() << std::endl;
    return ret;
}
