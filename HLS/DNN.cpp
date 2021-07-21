// DNN.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define H 200
#define DIN 785
#define K 10


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctgmath>
#include "weights.h"
#include <hls_stream.h>
          
double P1[H];
double y[H];
double P2[K];
unsigned short img[785];

double sigmoid(double alpha) {
    return 1 / (1 + pow(2.71828, -alpha));
}

void dnn(hls::stream<unsigned short int> &image,hls::stream<double> &scores)
{

	LOAD_IMG:for(int n=0; n < 785; n++){

		image.read(img[n]);

	}

    double temp1 =0;
    int iteration = 0;
    //computing P1
    COMPUTE_P1:for (int col = 0; col < H; col++) {
        COMPUTE_P1_INNER:for (int row = 0; row < DIN + 1; row++) {
            temp1 += W1[row][col] * img[row];
        }
        P1[iteration] = temp1;
        temp1 = 0;
        iteration++;
    }

    COMPUTE_y:for (int col = 0; col < H; col++) {
        y[col] = sigmoid(P1[col]);
    }

    //computing P2
    iteration = 0;
    temp1 = 0;
    COMPUTE_P2:for (int col = 0; col < K; col++) {
        COMPUTE_P2_INNER:for (int row = 0; row < H; row++) {
            temp1 += W2[row][col] * y[row];
        }
        P2[iteration] = temp1;
        temp1 = 0;
        iteration++;
    }

    OUTPUT:for (int i = 0; i < 10;i++) {
#ifndef __SYNTHESIS__
        std::cout << P2[i] << std::endl;
#endif
        scores.write(P2[i]);
    }

}

