/* Include Files */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data2.h"

float in[128] = {A_ARRAY};
float out[128];
#define TRUE 1
#define N 20
#define PI 3.141592653589793
#define MAX_SIZE 128
#define PERIOD 10
#define FREQ 0.1

void rect(float* out) {
	int i = 0;
	for(i = 0; i < MAX_SIZE; i++) {
		if(i > 0){
			out[i] = 1;
		} else {
			out[i] = 0;
		}
	}
}

void sinc(float* out) {
	int i, j = 0;
	float real = 0;
	float image = 0;
	
	for(i = 0; i < MAX_SIZE; i++) {
		for(j = 0; j < PERIOD; j++) {
			real += in[i] * cos(2 * PI / PERIOD * i * j);
			image -= in[i] * sin(2 * PI / PERIOD * i * j);
		}
		out[i] *= real * real + image * image;
		real = 0;
		image = 0;
	}
}


/* Main Code */
void main() {
	rect(out);
	sinc(out);
	return;
}

