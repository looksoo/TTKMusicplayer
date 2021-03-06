#ifndef MUSICBACKGROUNDSKINDIALOG_H
#define MUSICBACKGROUNDSKINDIALOG_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicabstractmovedialog.h"

namespace Ui {
class MusicBackgroundSkinDialog;
}

class MusicBackgroundListWidget;
class MusicBackgroundRemoteWidget;

/*! @brief The class of the local background widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicBackgroundSkinDialog : public MusicAbstractMoveDialog
{
    Q_OBJECT
public:
    explicit MusicBackgroundSkinDialog(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~MusicBackgroundSkinDialog();

    static QString getClassName();
    /*!
     * Get class object name.
     */

    static QPixmap setMBackground(QString &name);
    /*!
     * Set artist background picture by name.
     */
    static bool themeValidCheck(QString &name, QString &path);
    /*!
     * Theme valid check.
     */
    static QString cpoyArtFileToLocal(const QString &path);
    /*!
     * Copy art file to local themes dir path.
     */
    void updateArtFileTheme(const QString &theme);
    /*!
     * Update art file theme.
     */

    void setCurrentBgTheme(const QString &theme, int alpha, int listAlpha);
    /*!
     * Select current item by name\alpha\listAlpha when the widget show.
     */
    int getBackgroundListAlpha() const;
    /*!
     * Get list bg skin alpha.
     */
    bool getBackgroundTransparentEnable() const;
    /*!
     * Get bg window skin enable.
     */

    void setSkinTransToolText(int value);
    /*!
     * Set skin transparent tool text.
     */
    void setListTransToolText(int value);
    /*!
     * Set list transparent tool text.
     */

Q_SIGNALS:
    void currentTextChanged(const QString &text);
    /*!
     * Update app bg when user change the current bg emit.
     */

public Q_SLOTS:
    void showPaletteDialog();
    /*!
     * Change index to palette dialog.
     */
    void showPaletteDialog(const QString &path);
    /*!
     * Change index to palette dialog.
     */
    void showCustomSkinDialog();
    /*!
     * Change index to custom skin dialog.
     */
    void backgroundListWidgetChanged(int index);
    /*!
     * Background list widget changed.
     */
    void backgroundListWidgetItemClicked(const QString &name);
    /*!
     * Background list widget item has clicked.
     */
    void myBackgroundListWidgetItemClicked(const QString &name);
    /*!
     * My background list widget item has clicked.
     */
    void remoteBackgroundListWidgetItemClicked(const QString &name);
    /*!
     * Remote background list widget item has clicked.
     */
    void currentColorChanged(const QString &path);
    /*!
     * Update app bg when user change the current bg emit.
     */
    void windowTransparentChanged(bool state);
    /*!
     * Window transparent changed.
     */
    virtual int exec();
    /*!
     * Override exec function.
     */

protected:
    void listWidgetItemClicked(MusicBackgroundListWidget *item, const QString &name);
    /*!
     * Background list widget item has clicked changed.
     */
    void addThemeListWidgetItem();
    /*!
     * Add all theme into list.
     */
    void cpoyFileFromLocal(const QString &path);
    /*!
     * Copy custom file to local themes dir path.
     */
    static int cpoyFileToLocalIndex();
    /*!
     * Copy custom file index.
     */
    static int cpoyFileToLocal(const QString &path);
    /*!
     * Copy custom file .
     */

    int m_myThemeIndex;
    Ui::MusicBackgroundSkinDialog *m_ui;
    MusicBackgroundListWidget *m_backgroundList, *m_myBackgroundList;
    MusicBackgroundRemoteWidget *m_remoteBackgroundList;

};

#endif // MUSICBACKGROUNDSKINDIALOG_H
