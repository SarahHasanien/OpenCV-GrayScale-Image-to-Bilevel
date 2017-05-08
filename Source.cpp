#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;
using namespace cv;
//Function that takes image name and a threshold then return a vector of vectors or (2d array)
vector<vector<int>> convertImageToBinaryData(string imgName,int threshold)
{
	Mat image = imread(imgName, CV_LOAD_IMAGE_GRAYSCALE);
	int rows = image.rows;
	int cols = image.cols;
	vector <vector<int>> arr;
	//filling the bilevel image
	for (int r = 0; r < rows; r++)
	{
		vector <int> row;
		for (int c = 0; c < cols; c++)
		{
			if (image.at<uint8_t>(r, c)>threshold)
			{
				row.push_back(1);
				image.at<uint8_t>(r, c) = 255;
			}
			else
			{
				row.push_back(0);
				image.at<uint8_t>(r, c) = 0;
			}
		}
		arr.push_back(row);
	}
	return arr;
}
int main(int argc, char** argv)
{
	/*vector <vector<vector<int>>> vec; //vector of 2d vectors or consider it as an array of 2d arrays :v
	Mat original, modified,colored;
	vector <vector <int>>arr;
	vec.push_back[arr];//Works well (y), no errors*/
	vector <vector <int>>arr=convertImageToBinaryData("gurl.jpg", 180);
	Mat originalGrayScaled = imread("gurl.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat bilevel = imread("gurl.jpg" ,CV_LOAD_IMAGE_GRAYSCALE);
	//The following for loop puts white or black in bilevel image depending on the corresponding 
	//value in the 2d vector returned from the function
	for (int r = 0; r < bilevel.rows; r++)
	{
		for (int c = 0; c < bilevel.cols; c++)
		{
			if (arr.at(r).at(c))
				bilevel.at<uint8_t>(r, c) = 255;
			else
				bilevel.at<uint8_t>(r, c) = 0;

		}
	}
	imshow("Grayscale", originalGrayScaled);//Not actually needed. Just to visualize the differences between the 2 images
	imshow("Bilevel", bilevel);
	waitKey();
	return 0;
}
