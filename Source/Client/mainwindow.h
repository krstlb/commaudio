#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>
#include <QFile>
#include <QButtonGroup>
#include <QPushButton>
#include <QMediaPlaylist>
#include <QDebug>

#include "filetransfer.h"
#include "playback.h"
#include "recording.h"
#include "playlist.h"
#include "socket/clienttcp.h"
#include "socket/clientudp.h"
#include "socket/udprecvthread.h"
#include "socket/threadhandler.h"
#include "socket/circularbuffer.h"
#include "wavfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void udpRecvSetup();
    void temp_add_music();

signals:
    void readDataM(char* bbb);
    void addMusic();
public slots:
    void toggleIcon();
    void call_TCP();

private slots:

    void on_actionPlaylist_triggered();

    void on_actionJoin_Multicast_triggered();

    void on_actionCB_triggered();

    void on_playPauseButton_clicked(bool checked);

    void on_volumeSlider_valueChanged(int value);

    void on_connectButton_clicked();

    void on_actionRecording_triggered();

    void on_pushToTalk_clicked(bool checked);

    void on_pushButton_pressed();

    void on_pushButton_released();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int icon;
    Playback *test;
    Recording *test2;
    Playlist *list;
    bool playPauseFlag = false;
    QString fname = QString(":/qss_icons/rc/play-circle1.png");
    QString fname2 = QString(":/qss_icons/rc/pause-circle.png");
    QString fname3 = QString(":/qss_icons/rc/stopButton.png");

    WavFile *wf;

    QThread *TCPThread;
    QThread *UDPThread;
    QThread *playThread;
    QThread *musicThread;
    QThread *voiceThread;
    QThread *fileTransferThread;

    Playback *addPk;
    Playback *addVoice;

    UDPRecvThread *udpThread;
    UDPRecvThread *multiThread;

    Filetransfer *ft;
};

#endif // MAINWINDOW_H
