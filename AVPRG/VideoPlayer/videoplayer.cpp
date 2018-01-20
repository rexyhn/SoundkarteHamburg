#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"
#include "brightnessprocessor.h"
#include <QTextStream>
#include <QDebug>
#include <QTimer>

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
    , videoProcessor(new ColorProcessor)
{
    ui->setupUi(this);
    videoThread->setProcessor(videoProcessor);
    connect(videoThread, &VideoEngine::sendInputImage,
            ui->inputFrame, &VideoWidget::setImage);
    connect(videoThread, &VideoEngine::sendProcessedImage,
            ui->processedFrame, &VideoWidget::setImage);
    QStringList connections = midiOutput.connections(true);
    ui->comboBox->addItems(connections);
    midiOutput.open("LoopBe Internal MIDI");
    QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this,SLOT(sendMidi()));
       timer->start(1000); //time specified in ms
}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete ui;
    delete videoProcessor;
}

void VideoPlayer::on_actionKamera_ffnen_triggered()
{
    videoThread->openCamera();


}

void VideoPlayer::on_actionPlay_triggered()
{   int tmp=0;
    bool isnew =true;
    int i=0;
    videoThread->start();


}

void VideoPlayer::on_horizontalSlider_valueChanged(int value)
{
    videoProcessor->setThreshold(value);

}
void VideoPlayer::on_comboBox_activated(const QString &arg1)
{
    midiOutput.open(arg1);
}
void VideoPlayer::sendMidi(){
int tmp=videoProcessor->getCenterandColor(videoProcessor->getImage());
midiOutput.sendNoteOn(0,tmp,127);
ui->lcdNumber->display(tmp);
//QTextStream out(stdout);
//out<<tmp;
}
