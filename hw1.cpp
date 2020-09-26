//g++ hw1.cpp -o hw1
//hw1 

#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

int size = 400;
bool **image;

void rasterizeArcs() 
{
	int theta1 = 0;	
	int x1c = 100 * cos(theta1) + 200;
	int y1s = 100 * sin(theta1) + 200;
	int x2c = 150 * cos(theta1) + 200;
	int y2s = 150 * sin(theta1) + 200;

	while (theta1 < 129600) {
		x1c = 100 * cos(theta1) + 200;
		y1s = 100 * sin(theta1) + 200;
		if (y1s >= 200) {
			
			//x1c =  99 * cos(theta1) + 200;//cos(theta1)
			//y1s =  99 * sin(theta1) + 200;//sin(theta1)
			//image[x1c][y1s] = 1;

			//x1c = 100 * cos(theta1) + 200;
			//y1s = 100 * sin(theta1) + 200;
			image[x1c][y1s] = 1;

			//x1c = 101 * cos(theta1) + 200;
			//y1s = 101 * sin(theta1) + 200;
			//image[x1c][y1s] = 1;
			
			//cout<<" *x1c, y1s = "<< x1c <<" "<< y1s<<" theta = "<< theta1; }
		}
		x2c = 150 * cos(theta1) + 200;
		y2s = 150 * sin(theta1) + 200;
		if (x2c >= 200) {
			
			//x2c = 149 * cos(theta1) + 200;//cos(theta1)
			//y1s = 149 * sin(theta1) + 200;//sin(theta1)
			//image[x2c][y1s] = 1;

			//x2c = 150 * cos(theta1) + 200;
			//y2s = 150 * sin(theta1) + 200;
			image[x2c][y2s] = 1;

			//x2c = 151 * cos(theta1) + 200;
			//y2s = 151 * sin(theta1) + 200;
			//image[x2c][y2s] = 1;
			
			//cout<<" *x2c, y2s = "<< x2c <<" "<< y2s<<" theta = "<< theta1;	}
		}		
		theta1++;
	}
}

int main(int argc, char *argv[]) {
	if (argc != 1) {
		cout << "Usage: " << argv[0] << " hw1\n";
		return 0;
	}

	image = new bool*[size+1];
	for (int i = 0; i <= size; i++) image[i] = new bool[size+1];
	//for (int i = size; i >= 0; i--) image[i] = new bool[size+1];

	
	rasterizeArcs();
	char filename[50];
	sprintf(filename, "circle.ppm");	
	ofstream outfile(filename);
	outfile << "P3\n# " << filename << "\n";
	outfile << size+1 << ' ' << size+1 << ' ' << 1 << endl;

	for (int i = 0; i <= size; i++)
	for (int j = 0; j <= size; j++)	
		outfile << image[size-i][j] << " 0 0\n";
	
	// delete image data
	for (int i = 0; i <= size; i++) delete [] image[i];
	delete [] image;
	
	return 0;
}


