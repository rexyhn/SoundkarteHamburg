#include "colorprocessor.h"
#include <math.h>
#include <QTextStream>

using namespace cv;

ColorProcessor::ColorProcessor()
    :threshold(10)


{

}
cv::Mat processedImage;
void ColorProcessor::startProcessing(const VideoFormat& format)
{}

void ColorProcessor::setThreshold(int threshold){
    this->threshold = threshold;
}


cv::Mat ColorProcessor::process(const cv::Mat& input){
   Mat output(input.rows, input.cols, input.type());
   //QTextStream out(stdout);
   //out<<input.rows;
   for(int x = 0; x < input.cols; x++){
       for(int y = 0; y < input.rows; y++){

           Vec3b inputPixel = input.at<Vec3b>(y,x);
           int r = inputPixel[2];
           int g = inputPixel[1];
           int b = inputPixel[0];
            //yellow ist jetz blau
           int distanceyellow = sqrt((r-0)*(r-0) + (g-25)*(g-25) + (b-80)*(b-80));
           int distancered = sqrt((r-250)*(r-250) + (g-40)*(g-40) + (b-0)*(b-0));
           int distancegreen = sqrt((r-0)*(r-0) + (g-100)*(g-100) + (b-0)*(b-0));

           if(distanceyellow < threshold){
               if(x>100&&x<605&&y>90&&y<415){
               r = 0;
               g = 25;
               b=85;
            }
               else{
                   r = g = b = 0;
               }


           }
           else if(distancered < threshold){
               if(x>100&&x<605&&y>90&&y<415){
               r=150;
               g=11;
               b=15;
               }
               else{
                   r = g = b = 0;
               }

           }
           else if(distancegreen < threshold){
                if(x>100&&x<605&&y>90&&y<415){
               r=0;
               g=200;
               b=50;
                }
                else{
                    r = g = b = 0;
                }
           }
           else{
               r = g = b = 0;
           }
           Vec3b outputPixel(b, g, r);
           output.at<Vec3b>(y,x) = outputPixel;
       }
   }
   processedImage=output;
    //getCenterandColor(output);
   return output;
}
int ColorProcessor::getCenterandColor(const Mat &input){
    int region;
    int blackpixel=0;
    int yellowpixel=0;
    int redpixel=0;
    int greenpixel=0;
    int rsumy =0;
    int rsumx =0;
    int ysumy =0;
    int ysumx =0;
    int gsumy =0;
    int gsumx =0;
    int centerX=0;
    int centerY=0;
    for(int x = 0; x < input.cols; x++){
        for(int y = 0; y < input.rows; y++){
            Vec3b inputPixel = input.at<Vec3b>(y,x);
            int r = inputPixel[2];
            int g = inputPixel[1];
            int b = inputPixel[0];
            if(r==0&&g==25&&b==85){
                yellowpixel++;
                ysumx += x;
                ysumy += y;
            }
            else if(r==150&&g==11){
                redpixel++;
                rsumx += x;
                rsumy += y;
            }
            else if(r==0&&g==200){
                greenpixel++;
                gsumx += x;
                gsumy += y;
            }
            else{
                blackpixel++;
            }
        }
    }
    if(yellowpixel>redpixel&&yellowpixel>greenpixel){
        centerX = ysumx/yellowpixel;
        centerY = ysumy/yellowpixel;
        region=getRegion(centerX,centerY)+3;

    }
    else if(greenpixel>yellowpixel&&greenpixel>redpixel){
        centerX = gsumx/greenpixel;
        centerY = gsumy/greenpixel;
        region=getRegion(centerX,centerY)+2;
    }
    else if(redpixel>yellowpixel&&redpixel>greenpixel){
        centerX = rsumx/redpixel;
        centerY = rsumy/redpixel;
        region=getRegion(centerX,centerY)+1;
    }
    else{
        centerX=0;
        centerY=0;
        region=getRegion(centerX,centerY);
    }

    //QTextStream out(stdout);
    //out<<centerX;
    return region;
}
int ColorProcessor::getRegion(int x, int y){
    int region=0;
    //6 if abfragen einfügen
    //Theater
    if(327>x&&x>230&&180>y&&y>90){
        region=10;
    }
    //Elbphil
    else if(514>x&&x>446&&222>y&&y>150){
        region=20;
    }
    //Speicherstadt
    else if(580>x&&x>518&&286>y&&y>225){
        region=30;
    }
    //Michaelis
    else if(437>x&&x>346&&422>y&&y>350){
        region=40;
    }
    //Landungsbrücken
    else if(244>x&&x>174&&356>y&&y>297){
        region=50;
    }
    //Elbtunnel
    else if(165>x&&x>97&&354>y&&y>294){
        region=60;
    }
    else{
        region=0;
    }

    //QTextStream out(stdout);
    //out<<region;
    return region;
}
cv::Mat ColorProcessor::getImage(){
    return processedImage;
}


