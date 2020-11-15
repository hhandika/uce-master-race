/*
Heru Handika
1 August 2020
A library for for calculator functions
MIT License
*/

#ifndef UTILS_H_
#define UTILS_H_

unsigned int getSampleSize(void);

void calculateEthanol80(int sampleSize, int perSampleConcentration);

void calculateQubitSolution(int sampleSize);

void timer(int time);

void beadCleanUpProtocols(void);

#endif