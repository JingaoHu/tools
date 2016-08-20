#include <iostream>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <cv.h>
#include <highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

   
int main( int argc, char** argv )  
{  
    //����IplImageָ��  
    IplImage* pFrame = NULL;  
    IplImage* img;  
  
    //��ȡ����ͷ  
    CvCapture* pCapture = cvCreateCameraCapture(-1);  
  
    //��������  
    cvNamedWindow("video", 1);  
    CvVideoWriter *writer = NULL;  
    int isColor = 1;  
    int fps = 25; // or 30  
    int frameW = 640; //   
    int frameH = 480;  
      
    writer=cvCreateVideoWriter("out.avi",CV_FOURCC('X','V','I','D'),fps,cvSize(frameW,frameH),isColor);  
  
    //��ʾ����  
    while(1)  
    {  
        pFrame=cvQueryFrame( pCapture );  
        if(!pFrame)break;  
        cvShowImage("video",pFrame);  
        cvGrabFrame(pCapture); // capture a frame  
        img = cvRetrieveFrame(pCapture); // retrieve the captured frame  
        cvWriteFrame(writer,img); // add the frame to the file  
        char c=cvWaitKey(33);  
        if(c==27)break;  
    }  
        cvReleaseImage(&pFrame);  
        cvReleaseImage(&img);  
        cvReleaseVideoWriter(&writer);  
        cvReleaseCapture(&pCapture);  
        cvDestroyWindow("video");  
}  
