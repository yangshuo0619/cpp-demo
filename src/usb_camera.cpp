#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    if (argc != 2 )
    {
      printf("usage: ./usb_camera <video index>\n");
      return -1;
    }

    VideoCapture cap;
    int video_index = atoi(argv[1]);
    printf("video index: %d \n", video_index);
    cap.open(video_index);
    if(!cap.isOpened())
    {
        printf("don`t open camera!\n");
        return -1;
    }

    Mat frame;
    int frameHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    int frameWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    
    while(1)
    {
        cap >> frame;
        if(!frame.empty())
        {
            imshow("camera", frame);
        }

        if(char(waitKey(40) == 'q'))
        {
            break;
        }
    }
    cap.release();
    return 0;
}
