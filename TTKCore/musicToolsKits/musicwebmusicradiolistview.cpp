#include "musicwebmusicradiolistview.h"
#include "musicradiochannelthread.h"
#include "musicwebmusicradiowidget.h"
#include "musicwidgetutils.h"
#include "musicuiobject.h"

#include <QNetworkCookieJar>

MusicWebMusicRadioListView::MusicWebMusicRadioListView(QWidget *parent)
    : QListWidget(parent), m_getChannelThread(nullptr), m_musicRadio(nullptr)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setFrameShape(QFrame::NoFrame);
    setStyleSheet(MusicUIObject::MScrollBarStyle03);

    setViewMode(QListView::IconMode);
    setMovement(QListView::Static);

    MusicUtils::Widget::setTransparent(this, 0);

    m_cookJar = new QNetworkCookieJar(this);
#ifdef Q_OS_WIN
    setSpacing(17);
#else
    setSpacing(16);
#endif
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(itemHasClicked(QListWidgetItem*)));
}

MusicWebMusicRadioListView::~MusicWebMusicRadioListView()
{
    delete m_getChannelThread;
    delete m_musicRadio;
    delete m_cookJar;
}

QString MusicWebMusicRadioListView::getClassName()
{
    return staticMetaObject.className();
}

void MusicWebMusicRadioListView::initListItems()
{
    if(count() == 0)
    {
        delete m_getChannelThread;
        m_getChannelThread = new MusicRadioChannelThread(this, m_cookJar);
        connect(m_getChannelThread, SIGNAL(downLoadDataChanged(QString)), SLOT(addListWidgetItem()));
        m_getChannelThread->startToDownload(QString());
    }
}

void MusicWebMusicRadioListView::addListWidgetItem()
{
    MusicRadioChannelInfos channels = m_getChannelThread->getMusicChannel();

    foreach(const MusicRadioChannelInfo &channel, channels)
    {
        QListWidgetItem *item = new QListWidgetItem(channel.m_name, this);
        item->setSizeHint(QSize(80, 30));
        addItem(item);
    }
}

void MusicWebMusicRadioListView::itemHasClicked(QListWidgetItem *item)
{
    MusicRadioChannelInfos channels = m_getChannelThread->getMusicChannel();
    if(m_musicRadio == nullptr)
    {
        m_musicRadio = new MusicWebMusicRadioWidget(this);
        m_musicRadio->setNetworkCookie(m_cookJar);
    }

    if(!channels.isEmpty())
    {
        m_musicRadio->updateRadioList(channels[row(item)].m_id);
    }
    m_musicRadio->show();
}
