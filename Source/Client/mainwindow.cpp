#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QString fname = QString(":/qss_icons/rc/play-circle1.png");
    //QString fname2 = QString(":/qss_icons/rc/pause-circle.png");
    // QString fname3 = QString(":/qss_icons/rc/stopButton.png");

    ui->playPauseButton->setIconSize(QSize(32, 32));
    ui->playPauseButton->setStyleSheet("QPushButton{border: none;outline: none;}");
    ui->playPauseButton->setIcon(QIcon(fname));

  //  ui->pauseButton->setStyleSheet("QPushButton{border: none;outline: none;}");
   // ui->pauseButton->setIcon(QIcon(fname2));

    ui->stopButton->setStyleSheet("QPushButton{border: none;outline: none;}");
    ui->stopButton->setIcon(QIcon(fname3));

//  ui->playList->addItems(items);

    ui->userList->addItem("Oscar");
  //  connect(ui->playPauseButton, SIGNAL(clicked()), this, SLOT(toggleIcon()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleIcon()
{

}

void MainWindow::on_actionTest_1_triggered()
{
    test = new Playback();
}

void MainWindow::on_actionPause_triggered()
{
    test->pause();
}

void MainWindow::on_actionResume_triggered()
{
    test->resume();
}

void MainWindow::on_actionTest_2_triggered()
{
    test2 = new Recording();
}

void MainWindow::on_actionPause2_triggered()
{
    test2->pause();
}

void MainWindow::on_actionPlaylist_triggered()
{
    list = new Playlist("../Demo");
    list->update_list();
    qDebug() << "updated";
    ui->playList->clear();
    ui->playList->addItems(list->get_playlist());
    qDebug() << "got list";

}

void MainWindow::on_actionRingBuf_triggered()
{
    /*
    CircularBuffer *cb;
    initBuffer(cb);
    Playback *cbtest = new Playback(cb);
    */

    Playback *pb = new Playback(new RingBuffer());

}


void MainWindow::on_actionJoin_Multicast_triggered()
{
    ThreadHandler *TCPthread = new ThreadHandler();
    UDPRecvThread *multiThread = new UDPRecvThread(this);
    qDebug() << "JOIN multicast";
    ClientUDP *udp = new ClientUDP();
    if(!udp->Start() || !udp->initData() ||!udp->multiSetup()){
        udp->close();
        return ;
    }
    connect(multiThread, SIGNAL(startTCP()), TCPthread, SLOT(createThread()));
    connect(multiThread, SIGNAL(recvData()), udp, SLOT(writeFile()));
    multiThread->start();

}

void MainWindow::on_playPauseButton_clicked()
{
    playPauseFlag = true;

    ui->playPauseButton->setIcon(QIcon(fname2));

}
