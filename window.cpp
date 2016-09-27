#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>


#include "png/png.hpp"
using namespace std;


void writePng(int center, int width, string fileName, bool ct)
{
	png::image< png::gray_pixel_16 > image(fileName);

	png::image< png::gray_pixel > imageOut(image.get_width(),image.get_height());


	int colorStartRange = 0;
	int colorEndRange = 255;

	int min = (center - 0.5) - ((width - 1) / 2);
	int max = (center - 0.5) + ((width - 1) / 2);

	printf ("min: %d, max: %d \n", min, max);


	for (size_t y=0; y < image.get_height(); ++y){
		for (size_t x=0; x < image.get_width(); ++x){

			png::gray_pixel_16 pt = image.get_pixel(x,y);

			if (ct == true){
				//pt = (pt*1) - 1024;
			}

			if (pt <= min) {
				imageOut[y][x] = colorStartRange;
			} else if (pt > max) {
				imageOut[y][x] = colorEndRange;
			} else {
				imageOut[y][x] = ((pt - (center - 0.5))/(width - 1) + 0.5)*(colorEndRange-colorStartRange)+colorStartRange;
			}
		}
	}

	imageOut.write("testo.png");

}

void returnUid(char name[])
{

	int len = strlen(name);

	printf("name %s",name);

	char * pos;

	pos = strchr(name,'_');

	int lok = pos-name+1;

	cout << "position:" << lok;

	char outName[];


	//return "nieco";
}

int main(int argc, char* argv[])
{

	if (argc < 4){
		cout << "Not enough parameters !!!!" << endl;
		exit(1);
	}

	stringstream centerStr;
	centerStr << argv[1];
	stringstream widthStr;
	widthStr << argv[2];

	string fileName;
	stringstream fileNameStr;
	fileNameStr << argv[3];

	returnUid(argv[3]);
	exit(1);

	int center;
	centerStr >> center;

	int width;
	widthStr >> width;

	fileNameStr >> fileName;

	if (!std::ifstream(argv[3])){
		cout << "PNG file not exists !!!!!" << endl;
		exit(1);
	}

	printf("center: %d width: %d filename: %s \n",center,width,argv[3]);


	writePng(center,width,fileName,true);

	return 0;

}
