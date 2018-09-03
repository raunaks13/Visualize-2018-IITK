#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int visited[8][8];
int path[64][2];
int f;

int isPath(int x, int y, int maze[8][8])
{
    if ( x<0 || x>= 8 || y <0 || y >= 8 )
        return 0;
    else if (maze[x][y] == 0)
        return 0;
    else if (visited[x][y] == 1)  
        return 0;
        
    else if (x == 7 && y == 7)
    {   
        return 1;
    }
    
    else
    {  
        visited[x][y] = 1;

        if(isPath(x+1, y, maze) == 1)
        {
            path[f][0] = x+1;
            path[f][1] = y;
            f++;
            return 1;
        }
        else if(isPath(x, y+1, maze) == 1)
        {
            path[f][0] = x;
            path[f][1] = y+1;
            f++;
            return 1;
        }
        else if (isPath(x-1,y, maze) == 1)
        {
            path[f][0] = x-1;
            path[f][1] = y;
            f++;
            return 1;
        }
        else if(isPath(x, y-1, maze) == 1)
        {
            path[f][0] = x;
            path[f][1] = y-1;
            f++;
            return 1;
        }

        else
            return 0;
    }
}

int main( int argc, char** argv )
{
    String imageName( "Sample_Problem2.png" );
    // String imageName( "Test_2.png" );
    // String imageName( "test1.png" );
    // String imageName( "test4.png" );

    if( argc > 1)
    {
        imageName = argv[1];
    }
    Mat image;
    image = imread( imageName, IMREAD_COLOR );
    if( image.empty() )                      
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    

    Mat image_thresholded;
    inRange(image, cv::Scalar(254, 254, 254), cv::Scalar(255, 255, 255), image_thresholded);
    Mat opening_closing_kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5), cv::Point(2, 2));
    morphologyEx(image_thresholded, image_thresholded, cv::MORPH_CLOSE, opening_closing_kernel, cv::Point(-1, -1), 2);
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    findContours(image_thresholded, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE, cv::Point(0, 0));
    Rect bounding_rectangle;
    bounding_rectangle = boundingRect(Mat(contours[0]));
    int box_dim = bounding_rectangle.br().y - bounding_rectangle.tl().y;
    int center_x = bounding_rectangle.tl().x + box_dim/16;
    int center_y = bounding_rectangle.tl().y + box_dim/16;
    int mat[8][8];
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 8 ; j++) {
            if(((int)image.at<Vec3b>(center_y, center_x)[0]) == 0) {
                mat[i][j] = 0; 
            }
            else mat[i][j] = 1;
            center_x += box_dim/8;
        }
        center_y += box_dim/8;
        center_x = bounding_rectangle.tl().x + box_dim/16;
    }   

    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 8 ; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0;i<8;i++)
    {
        for(int j = 0;j<8;j++)
            visited[i][j] = 0; 
    }

    for(int i = 0;i<64;i++)
    {
        path[i][0] = 0;
        path[i][1] = 0;
    }

    int a = isPath(0, 0, mat);

    int index;
    for(int i = 0;i<64;i++)
    {
        if(path[i][0] == 0 && path[i][1] == 0)
        {
            index = i;
            break;
        }
    }

    cout << "Shortest path:";
    for(int i = index;i>=0;i--)
        cout << "(" << path[i][1]+1 << "," << path[i][0]+1 << ") ";

    return 0;
}