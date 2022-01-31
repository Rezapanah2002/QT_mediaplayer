#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    layout = new QVBoxLayout();

    //playing video in box
    layout->addWidget(videoWidget);
    ui->groupBox->setLayout(layout);

    //play video
    mediaPlayer->setVideoOutput(videoWidget);

    //sync slider with video process
    connect(mediaPlayer, &QMediaPlayer::durationChanged, ui->horizontalSlider_3, &QSlider::setMaximum);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, ui->horizontalSlider_3, &QSlider::setValue);

    //set first volume 50
    this->on_horizontalSlider_2_valueChanged(50);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//choose video from files
void MainWindow::on_actionChoose_To_Play_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Video File(*.*)");

    mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mediaPlayer->play();
}

//play
void MainWindow::on_actionPlay_triggered()
{
    mediaPlayer->play();
}

//pause
void MainWindow::on_actionPause_triggered()
{
    mediaPlayer->pause();
}

//stop
void MainWindow::on_actionStop_triggered()
{
    mediaPlayer->stop();
}

//mute
void MainWindow::on_actionMute_triggered()
{
    mediaPlayer->setVolume(0);
    ui->horizontalSlider_2->setSliderPosition(0);
}

//unmute
void MainWindow::on_actionVolume_triggered()
{
    mediaPlayer->setVolume(50);
    ui->horizontalSlider_2->setSliderPosition(50);
}

//seek on video with slider
void MainWindow::on_horizontalSlider_3_sliderMoved(int position)
{
    mediaPlayer->setPosition(position);
}

//change volume with slider
void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}

//rewind 10 sec
void MainWindow::on_actionRewinde_triggered()
{
    mediaPlayer->setPosition(mediaPlayer->position()-10000);
}

//forward 10 sec
void MainWindow::on_actionForward_triggered()
{
    mediaPlayer->setPosition(mediaPlayer->position()+10000);
}

//change rate of video
void MainWindow::on_comboBox_activated(int rate)
{
    qreal nowrate = 0;

    switch (rate) {
        case 0:
        {
            nowrate = 1;
            break;
        }
        case 1:
        {
            nowrate = 0.5;
            break;
        }
        case 2:
        {
            nowrate = 2;
            break;
        }
    }
        mediaPlayer->setPlaybackRate(nowrate);
}

//fullscreen
void MainWindow::on_pushButton_clicked()
{
    setWindowState(windowState() ^ Qt::WindowFullScreen);
}

void MainWindow::on_actionPreviouse_triggered()
{

}

void MainWindow::on_actionNext_triggered()
{

}

void MainWindow::on_actionSetting_changed()
{

}

void MainWindow::on_actionPlaylist_triggered()
{

}
