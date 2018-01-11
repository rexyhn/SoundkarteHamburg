#ifndef BRIGHTNESSPROCESSOR_H
#define BRIGHTNESSPROCESSOR_H

#include "videoprocessor.h"

class BrightnessProcessor : public VideoProcessor
{
public:
    BrightnessProcessor();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat& input);
    void setBrightness(int brightness);
 private:
    int brightness;
};

#endif // BRIGHTNESSPROCESSOR_H
