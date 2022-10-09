# CG_hw1

OS: Windows 10;

IDE: NotePad++ and command line g++ through MinGW;

C:\> ./g++ hw1.cpp -o hw1

C:\> ./hw1


 

I instead implemented the (R cos@, R sin@) method. With every 360 cycle,
variation causes a sideways shift in pixel selection that served to 
extend my line with many cycle passes.

There was an arifact persitently present in my outfile image after being 
converted online to a jpg. This artifact was interesting in itself. 
It appeared throughout all three converted outputs the different programs I
worked on for this assignment 

Although they were all different, they all contained the same 32bit binary 
number 1000111010101010101010100110011 with another 0 at either the beginning
or end. Interestingly, if you place the 0 in the beginning, the resulting 
number is close to the number of bytes the image uses in storage. The placement 
and effect of the artifact was reminiscent of watermarking copies. 













BELOW are the other algorithyms I considered:



(One, was the standard book algorithym from the 
reading. Two, was this origin-theta based algorithym I submitted here as hw1. 
Three, was an algorithym based on using y = +/- sqrt(R^2 - x^2) and complex 
numbers.)


ONE:========================================================================================================================================



#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;




int size = 400;
bool **image;


void renderPixel(int x, int y) {
	//assert(x >= 0 && y >= 0 && x <= size && y <= size);
	image[x][y] = 1;
	image[y][x] = 1;
	


	//image[y][1-x] = 1;
	//image[x][1-y] = 1;

	//image[-x][y] = 1;
	//image[-y][x] = 1;


	//image[-x][-y] = 1;
	//image[-y][-x] = 1;

	// TODO:  light up the pixel's symmetric counterpart
	
	
}

/*
void CirclePoints( int x, int y, int value)
{
	WritePixel(x, y, value);
	WritePixel(y, x, value);
	WritePixel(y, -x, value);
	WritePixel(x, -y, value);
	WritePixel(-x, -y, value);
	WritePixel(-y, -x, value);
	WritePixel(-y, x, value);
	WritePixel(-x, y, value); 
}
*/


void MidpointCircle(int radius) 
{
	/*
	int x = 200;
	int y = 200+radius;
	int d = 1 - radius;
	int deltaE= 3;
	int deltaSE= -2 *radius+ 5;
	renderPixel(x, y);
	
	while (y > x) {
		if (d < 0) {
			d +=deltaE;
			deltaE+= 2;
			deltaSE += 2;
		} else {
		d += deltaSE;
		deltaE+= 2;
		deltaSE += 4;
		y--;
		}
		x++;
		renderPixel(x, y);

	}
	
	int x2 = 200;
	int y2 = 200-radius;
	int d2 = 1 - radius;
	int deltaE2= 3;
	int deltaSE2= -2 *radius+ 5;
	renderPixel(x2, y2);
	
	while (y2 < x2) {
		if (d2 < 0) {
			d2 += deltaE2;
			deltaE2 += 2;
			deltaSE2 += 2;
		} else {
		d2 += deltaSE2;
		deltaE2 += 2;
		deltaSE2 += 4;
		y2++;
		}
		x2--;
		renderPixel(x2, y2);

	}

*/
	int x3 = 300;
	int y3 = +radius;
	int d3 = 1 - radius;
	int deltaE3= 3;
	int deltaSE3= -2 *radius+ 5;
	renderPixel(x3, y3);
	
	while (y3 < x3) {
		if (d3 < 0) {
			d3 += deltaE3;
			deltaE3 += 2;
			deltaSE3 += 2;
		} else {
		d3 += deltaSE3;
		deltaE3 += 2;
		deltaSE3 += 4;
		y3++;
		}
		x3--;
		renderPixel(x3, y3);

	}
}

void rasterizeArc() 
{

	MidpointCircle(100); 
	MidpointCircle(150);

}

	
	


// You shouldn't need to change anything below this point.
//=======================================================

int main(int argc, char *argv[]) {
	if (argc != 1) {
		cout << "Usage: " << argv[0] << " hw1\n";
		return 0;
	}
	
	
	// reserve image as 2d array
	image = new bool*[size+1];
	for (int i = 0; i <= size; i++) image[i] = new bool[size+1];
	
	rasterizeArc();
	
	char filename[50];
	sprintf(filename, "circle%d.ppm", size);	
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










(One, was the standard book algorithym from the 
reading. Two, was this origin-theta based algorithym I submitted here as hw1. 
Three, was an algorithym based on using y = +/- sqrt(R^2 - x^2) and complex 
numbers.)


THREE:=============================================================================================================================================



#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <complex>
using namespace std;

int size = 400;
bool **image;

void rasterizeArcs() 
{

 	int x  = 0;//200;
  	int y  = 0;//200;
	int x2 = 0;//200;
	int y1 = 0;//200;
	complex<double> y2 = 0;//200;
	int r1 = 100;
	int r2 = 150;
	
	//real(complex)
	//complex<int> i = sqrt(-30000);// "Square root of -4 is  (pow(r1,2)-pow(x,2)
	//int rl = i.real();
	//int im = i.imag();
	//complex<double> i2 = sqrt(complex<double>(pow(r1,2)-pow(x,2), -0.00));// "Square root of -4 is 
	//double rl2 = real(i2);
	//<<std::sqrt(std::complex<double>(-4, 0))
	//cout<<" i = "<< i<<" rl = "<< rl<<" im = "<< im;


	//y1 = sqrt(pow(r1,2)-pow(x,2));
	//cout<<" x, y1 = "<< x <<" "<< y1;
	while(x <= 399){
		//int rl = i.real();
		//int im = i.imag();
		//<<std::sqrt(std::complex<double>(-4, 0))
		int rt = pow(r2,2)-pow(x,2);
		y2 = sqrt(complex<double>(rt, 0));//y2 = sqrt(pow(r2,2)-pow(x,2));
		int y2r = y2.real();//int y2i = sqrt(complex<double>(rt, 0));//y2 = sqrt(pow(r2,2)-pow(x,2));
		int y2i = y2.imag();//int y2i = sqrt(complex<double>(rt, 0));//y2 = sqrt(pow(r2,2)-pow(x,2));

		//cout<<" x, y2, y2r, y2i = "<< x <<"  "<< y2<<"  "<<y2r<<"  "<<y2i; 

		if (y2r >= 200  && y2r <= 399 || y2i >= 200  && y2i <= 399){
			image[x][y2r] = 1;
			cout<<" *x, *y2i *y2r = "<< x <<" "<< y2i<<"  "<<y2r; 
		
		}
		cout<<" ~1 ";
		if(x == 0){
			cout<<" ~2 ";
			
			y = 0;
			while(y <= 399){
		
				y1 = sqrt(pow(r1,2)-pow(y,2));
				//cout<<" x, y1 = "<< x <<" "<< y1; 

				if(y1 >= 200  && y1 <= 399){
					image[y][y1] = 1;
					cout<<" *x, *y1 = "<< x <<" "<< y1; 
					y++;
					break;
				}
				y++;
			}
		
		}
		x++;	
	}
	
}

// You shouldn't need to change anything below this point.
//========================================================

int main(int argc, char *argv[]) {
	if (argc != 1) {
		cout << "Usage: " << argv[0] << " hw1\n";
		return 0;
	}
	
	
	// reserve image as 2d array
	image = new bool*[size+1];
	for (int i = 0; i <= size; i++) image[i] = new bool[size+1];
	//for (int i = size; i >= 0; i--) image[i] = new bool[size+1];

	rasterizeArcs();
	
	char filename[50];

	sprintf(filename, "circle%d.ppm", size);
	
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






