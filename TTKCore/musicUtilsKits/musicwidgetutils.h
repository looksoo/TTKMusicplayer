#ifndef MUSICWIDGETUTILS_H
#define MUSICWIDGETUTILS_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

class QComboBox;

#include "musicobject.h"
#include "musicnumberdefine.h"
#include "musicglobaldefine.h"

/*! @brief The class of the utils widget object namespace.
 * @author Greedysky <greedysky@163.com>
 */
namespace MusicUtils
{
    namespace Widget
    {
        MUSIC_UTILS_EXPORT void setLabelFontSize(QWidget *widget, int size);
        /*!
         * Set widget label font.
         */
        MUSIC_UTILS_EXPORT void setLabelFontStyle(QWidget *widget, MusicObject::FontStyleMode type);
        /*!
         * Set widget label font.
         */
        MUSIC_UTILS_EXPORT QString elidedText(const QFont &font, const QString &text,
                                             Qt::TextElideMode mode, int width);
        /*!
         * Set text elided text by font.
         */
        MUSIC_UTILS_EXPORT void setTransparent(QWidget *widget, int alpha);
        /*!
         * Set widget transparent.
         */
        MUSIC_UTILS_EXPORT void setComboboxText(QComboBox *object, const QString &text);
        /*!
         * Set Combobox text.
         */
        MUSIC_UTILS_EXPORT void widgetToRound(QWidget *w, int ratioX, int ratioY);
        /*!
         * Set widget to round by ratioX and ratioY.
         */
        MUSIC_UTILS_EXPORT void fusionPixmap(QPixmap &bg, const QPixmap &fg, const QPoint &pt);
        /*!
         * Set fusion two image.
         */
        MUSIC_UTILS_EXPORT QPixmap pixmapToRound(const QPixmap &src, const QSize &size, int ratioX, int ratioY);
        /*!
         * Set pixmap to round by ratio.
         */
        MUSIC_UTILS_EXPORT QPixmap pixmapToRound(const QPixmap &src, const QRect &rect, int ratioX, int ratioY);
        /*!
         * Set pixmap to round by ratio.
         */
        MUSIC_UTILS_EXPORT QPixmap pixmapToRound(const QPixmap &src, const QPixmap &mask, const QSize &size);
        /*!
         * Set pixmap to round by ratio.
         */
        MUSIC_UTILS_EXPORT QBitmap getBitmapMask(const QRect &rect, int ratioX, int ratioY);
        /*!
         * Get bitmap mask from rect.
         */
        MUSIC_UTILS_EXPORT QByteArray getPixmapData(const QPixmap &pix);
        /*!
         * Get pximap data.
         */

        template<class T>
        MUSIC_UTILS_EXPORT T reRenderValue(const T &key, const T &alpha, const T &value)
        {
            if(alpha < 0) return 0;
            else if(alpha > key) return key;

            return (key - alpha)*1.0/100*value + alpha;
        }
        /*!
         * Rerender the custum value.
         */
        MUSIC_UTILS_EXPORT int reRenderAlpha(int alpha, int value);
        /*!
         * Rerender the image alpha.
         */
        MUSIC_UTILS_EXPORT void reRenderImage(int delta, const QImage *input, QImage *output);
        /*!
         * Rerender the image by color burn transform.
         */
        MUSIC_UTILS_EXPORT uint colorBurnTransform(int c, int delta);
        /*!
         * Image color burn transform.
         */

        MUSIC_UTILS_EXPORT QString getOpenFileDialog(QWidget *obj, const QString &title, const QString &filter);
        /*!
         * Get open file dialog.
         */
        MUSIC_UTILS_EXPORT QString getOpenFileDialog(QWidget *obj, const QString &filter);
        /*!
         * Get open file dialog.
         */
        MUSIC_UTILS_EXPORT QString getOpenFileDialog(QWidget *obj);
        /*!
         * Get open file dialog.
         */

        MUSIC_UTILS_EXPORT QStringList getOpenFilesDialog(QWidget *obj, const QString &title, const QString &filter);
        /*!
         * Get open files dialog.
         */
        MUSIC_UTILS_EXPORT QStringList getOpenFilesDialog(QWidget *obj, const QString &filter);
        /*!
         * Get open files dialog.
         */
        MUSIC_UTILS_EXPORT QStringList getOpenFilesDialog(QWidget *obj);
        /*!
         * Get open files dialog.
         */

        MUSIC_UTILS_EXPORT QString getSaveFileDialog(QWidget *obj, const QString &title, const QString &filter);
        /*!
         * Get save file dialog.
         */
        MUSIC_UTILS_EXPORT QString getSaveFileDialog(QWidget *obj, const QString &filter);
        /*!
         * Get save file dialog.
         */
        MUSIC_UTILS_EXPORT QString getSaveFileDialog(QWidget *obj);
        /*!
         * Get save file dialog.
         */

    }
}

#endif // MUSICWIDGETUTILS_H
