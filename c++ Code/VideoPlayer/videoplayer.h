#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "copyprocessor.h"
#include "brightnessprocessor.h"
#include "colorprocessor.h"
#include "midioutput.h"
#include "QTimer"

namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

private slots:
    void on_actionKamera_ffnen_triggered();
    void on_actionPlay_triggered();
    void on_horizontalSlider_valueChanged(int value);
    void on_comboBox_activated(const QString &arg1);
    void sendMidi();


private:
    Ui::VideoPlayer *ui;
    VideoEngine *videoThread;
    ColorProcessor *videoProcessor;
    MIDIOutput midiOutput;
    QTimer timer;
    int midichannel;
    bool isOn;
};

#endif // VIDEOPLAYER_H
