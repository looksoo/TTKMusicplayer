#ifndef MUSICINITOBJECT_H
#define MUSICINITOBJECT_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QDebug>
#include "musicobject.h"
#include "musicversion.h"
#include "musicrunglobaldefine.h"

#define S_APPDATA_DIR_FULL        MusicObject::getAppDir() + APPDATA_DIR
#define S_DOWNLOADS_DIR_FULL      MusicObject::getAppDir() + DOWNLOADS_DIR

#define S_LRC_DIR_FULL            S_DOWNLOADS_DIR_FULL + LRC_DIR
#define S_MUSIC_DIR_FULL          S_DOWNLOADS_DIR_FULL + MUSIC_DIR
#define S_MOVIE_DIR_FULL          S_DOWNLOADS_DIR_FULL + MOVIE_DIR
#define S_TEMPORARY_DIR_FULL      S_DOWNLOADS_DIR_FULL + TEMPORARY_DIR
#define S_CACHE_DIR_FULL          S_DOWNLOADS_DIR_FULL + CACHE_DIR
#define S_ART_DIR_FULL            S_DOWNLOADS_DIR_FULL + ART_DIR
#define S_BACKGROUND_DIR_FULL     S_DOWNLOADS_DIR_FULL + BACKGROUND_DIR
#define S_UPDATE_DIR_FULL         S_DOWNLOADS_DIR_FULL + UPDATE_DIR

#define S_COFIGPATH_FULL          S_APPDATA_DIR_FULL + COFIGPATH
#define S_MUSICPATH_FULL          S_APPDATA_DIR_FULL + MUSICPATH
#define S_NORMALDOWNPATH_FULL     S_APPDATA_DIR_FULL + NORMALDOWNPATH
#define S_CLOUDDOWNPATH_FULL      S_APPDATA_DIR_FULL + CLOUDDOWNPATH
#define S_MUSICSEARCH_FULL        S_APPDATA_DIR_FULL + MUSICSEARCH
#define S_DARABASEPATH_FULL       S_APPDATA_DIR_FULL + DARABASEPATH
#define S_USERPATH_FULL           S_APPDATA_DIR_FULL + USERPATH
#define S_BARRAGEPATH_FULL        S_APPDATA_DIR_FULL + BARRAGEPATH
#define S_AVATAR_DIR_FULL         S_APPDATA_DIR_FULL + AVATAR_DIR
#define S_USER_THEME_DIR_FULL     S_APPDATA_DIR_FULL + USER_THEME_DIR

#define S_THEME_DIR_FULL          MusicObject::getAppDir() + TTKMUSIC_VERSION_STR + "/" + THEME_DIR
#define S_PLUGINS_DIR_FULL        MusicObject::getAppDir() + TTKMUSIC_VERSION_STR + "/" + PLUGINS_DIR
#define S_LANGUAGE_DIR_FULL       MusicObject::getAppDir() + TTKMUSIC_VERSION_STR + "/" + LANGUAGE_DIR

#ifdef Q_OS_WIN
#define S_TTKSERVICE_FULL         MusicObject::getAppDir() + TTKMUSIC_VERSION_STR + "/TTKService.exe"
#else
#define S_TTKDD_FULL              MusicObject::getAppDir() + TTKMUSIC_VERSION_STR + "/TTKLDD.sh"
#define S_TTKSERVICE_FULL         MusicObject::getAppDir() + TTKMUSIC_VERSION_STR + "/TTKService.sh"
#endif


/*! @brief The class of the music init object.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_RUN_EXPORT MusicInitObject : public QObject
{
    Q_OBJECT
public:
    explicit MusicInitObject(QObject *parent = 0);
    /*!
     * Object contsructor.
     */

    void checkValid();
    /*!
     * Check current setting file's validation.
     */
    void init();
    /*!
     * Init all parameter.
     */

    void dirIsExist(const QString &name);
    /*!
     * Check current dir is exist, no, just create it.
     */
    void checkTheDirectoryExist();
    /*!
     * Check the related dir is exist.
     */
    void checkTheFileNeededExist();
    /*!
     * Check the related file is exist.
     */
    void copyFileOverwrite(const QString &origin, const QString &des);
    /*!
     * Copy file by overwrite.
     */
    void copyFile(const QString &origin, const QString &des);
    /*!
     * Copy file.
     */

};

#endif // MUSICINITOBJECT_H
