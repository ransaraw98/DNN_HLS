// DNN.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctgmath>
#include "Header.h"




          
double P1[H];
double y[H];
double e = -4.385542661890289e-06;
double P2[K];

double sigmoid(double alpha) {
    return 1 / (1 + pow(2.71828, -alpha));
}

int main()
{
    double temp1 =0;
    int iteration = 0;
    //computing P1
    for (int col = 0; col < H; col++) {
        for (int row = 0; row < DIN + 1; row++) {
            temp1 += W1[row][col] * inputImg[row];
        }
        P1[iteration] = temp1;
        temp1 = 0;
        iteration++;
    }

    for (int col = 0; col < H; col++) {
        y[col] = sigmoid(P1[col]);
    }

    //computing P2
    iteration = 0;
    temp1 = 0;
    for (int col = 0; col < K; col++) {
        for (int row = 0; row < H; row++) {
            temp1 += W2[row][col] * y[row];
        }
        P2[iteration] = temp1;
        temp1 = 0;
        iteration++;
    }

    for (int i = 0; i < 10;i++) {
        std::cout << P2[i] << std::endl;
    
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
