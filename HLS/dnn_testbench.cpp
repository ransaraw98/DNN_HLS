#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctgmath>
#include "functions.h"
#include <hls_stream.h>
#include "image.h"



int main(){



	hls::stream<unsigned short int> image;
	hls::stream<double> scores;

	for (int i=0;i<785;i++){

		image.write(inputImg[i]);
	}

	dnn(image,scores);

	for (int i =0;i<10;i++){

		std::cout << scores.read() << std::endl;
	}
}
