#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

const int N = 3;
int imageArray[N][N];
vector<pair<int, int>> sequence;
int mouseClick_x = -1;
int mouseClick_y = -1;
int mouseUp_x = -1;
int mouseUp_y = -1;
int win = 0;
// Randomize
void randomArray(int num) {
	srand(time(NULL));
	for (int i = 0; i < N * N; i++) imageArray[i / N][i % N] = i;
	for (int i = 0;;) {
		if (i >= num) break;
		int r = rand() % (N * N);
		int d = rand() % 4;
		int y = r / N, x = r % N;
		switch (d) {
		case 0:  y-=1; break;
		case 1:  y +=1; break;
		case 2:  x -=1; break;
		case 3:  x +=1; break;
		}
		if (x < 0) x = 0;
		else if (x >= N-1) x = N-1;
		if (y < 0) y = 0;
		else if (y >= N-1) y = N-1;
		int next = y * N + x;
		if (next == r) continue;

		printf("r=%d, next = %d\n", r, next);

		sequence.push_back(pair<int, int>(r, next));
		int temp = imageArray[r / N][r % N];
		imageArray[r / N][r % N] = imageArray[y][x];
		imageArray[y][x] = temp;

		i++;
	}
	for (int i = 0; i < N * N; i++)  printf("%2d", imageArray[i / N][i % N]);
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		mouseClick_x = x;
		mouseClick_y = y;
		//cout << "mouseClick_x=" << mouseClick_x << "mouseClick_y=" << mouseClick_y << endl;
		//printf("i=%d,j=%d,index=%d\n", mouseClick_x/(1100/3), mouseClick_y/(813/3)); 
	} 
	else if (event == EVENT_LBUTTONUP)
	{
		mouseUp_x = x;
		mouseUp_y = y;
	}

}

int main()
{
	Mat img = imread("world2.jpg", -1);
	
	int height = img.size().height;
	int width = img.size().width;
	Point pt1, pt2;
	for (int i=0, step = height/N; i<height; i+=step)
	  line(img, Point(0, i), Point(width, i), Scalar(255, 0, 0), 3, 8);

	for (int i = 0, step = width / N; i < width; i += step)
		line(img, Point(i, 0), Point(i, height), Scalar(255, 0, 0), 3, 8);

	randomArray(2);
	//cout << "image.width=" << width << "image.height=" << height << endl;
	Mat matDst = Mat::zeros(img.size(), img.type());
	namedWindow("dst", WINDOW_NORMAL);
	setMouseCallback("dst", CallBackFunc, NULL);

	int index = 0;
	int x, y;

	while (1) {
		       
		x = index % N, y = index / N;
		if (mouseClick_x >= 0) {
			x = mouseClick_x / (width / N);
			y = mouseClick_y / (height / N);
			if (x < 0) x = 0;
			else if (x >= N - 1) x = N - 1;
			if (y < 0) y = 0;
			else if (y >= N - 1) y = N - 1;
			index = y * N + x;
			mouseClick_x = -1;
			mouseClick_y = -1;
		}

		if (mouseUp_x >= 0) {
			int moveto_x = mouseUp_x / (width / N);
			int moveto_y = mouseUp_y / (height / N);
			if (moveto_x < 0) moveto_x = 0;
			else if (moveto_x >= N - 1) moveto_x = N - 1;

			if (moveto_y < 0) moveto_y = 0;
			else if (moveto_y >= N - 1) moveto_y = N - 1;

			if ((x != moveto_x && y == moveto_y && abs(x - moveto_x) == 1) ||
				(y != moveto_y && x == moveto_x && abs(y - moveto_y) == 1))
			{
				int temp = imageArray[y][x];
				imageArray[y][x] = imageArray[moveto_y][moveto_x];
				imageArray[moveto_y][moveto_x] = temp;
				printf("swap (%d, %d) - (%d, %d)\n", y, x, moveto_y, moveto_x);
				printf("\n");
				for (int i = 0; i < N * N; i++)  printf("%2d", imageArray[i / N][i % N]);
				printf("\n");
			}

			mouseUp_x = -1;
			moveto_y = -1;
		}

		//cout << "mouseClick_x=" << mouseClick_x << "mouseClick_y=" << mouseClick_y <<  endl;
		matDst = Mat::zeros(img.size(), img.type());
		for (int i = 0; i < N; i++)   // y
			for (int j = 0; j < N; j++) {   //x
				if ((i * N + j) == index) {
					//printf("i=%d,j=%d,index=%d\n", i, j, index); 
					continue;
				}
				int d = imageArray[i][j];
				Rect src(j * width / N, i * height / N, width / N, height / N);
				Rect dst((d % N) * width / N, (d / N) * height / N, width / N, height / N);
				
				
				img(src).copyTo(matDst(dst));
		}
		imshow("dst", matDst);
		int key = waitKey(200);
		/*if (key < 0) continue;
		switch (key) {
			case 'w':   if (y>0)y--;
			break;
			case 's':   if(y< N-1)y++;
			break;
			case 'a':   if (x > 0) x--;
			break;
			case 'd':   if (x < N-1) x++;
				break;
		}
		index = y * N + x;

		int temp = imageArray[index / N][index % N];
		imageArray[index / N][index % N] = imageArray[y][x];
		imageArray[y][x] = temp;
		*/
		win = 1;
		for (int i = 0; i < N * N; i++)  if (imageArray[i / N][i % N] != i) win = 0;
		//cout << win << endl;
		if (key == 'q' || key == 27) break;
				
	}
	

	return 0;
}
