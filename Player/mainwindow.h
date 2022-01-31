#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QSlider>
#include <QLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_actionChoose_To_Play_triggered();

    void on_actionStop_triggered();

    void on_actionPreviouse_triggered();

    void on_actionRewinde_triggered();

    void on_actionPause_triggered();

    void on_actionPlay_triggered();

    void on_actionNext_triggered();

    void on_actionForward_triggered();

    void on_actionPlaylist_triggered();

    void on_horizontalSlider_3_sliderMoved(int position);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_actionMute_triggered();

    void on_actionVolume_triggered();

    void on_pushButton_clicked();

    void on_actionSetting_changed();

    void on_comboBox_activated(int rate);

private:
    Ui::MainWindow *ui;
    QVideoWidget *videoWidget;
    QMediaPlayer *mediaPlayer;
    QSlider *slider;
    QVBoxLayout *layout;

};
#endif // MAINWINDOW_H
