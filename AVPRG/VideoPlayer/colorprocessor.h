#ifndef COLORPROCESSOR_H
#define COLORPROCESSOR_H

#include "videoprocessor.h"

class ColorProcessor: public VideoProcessor
{
public:
    ColorProcessor();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat& input);
    void setThreshold(int threshold);
    int getCenterandColor(const cv::Mat& input);
    int getRegion(int x, int y);
    cv:: Mat processedImage;
    cv::Mat getImage();
 private:
    int threshold;

};

#endif // COLORPROCESSOR_H
