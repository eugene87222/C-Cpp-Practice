#include "bmpReader.h"
#include "bmpReader.cpp"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

#define MYRED	2
#define MYGREEN 1
#define MYBLUE	0

int imgWidth, imgHeight;
int MEAN_FILTER_SIZE = 9;
int SOBEL_FILTER_SIZE;
int FILTER_SCALE;
int wsize = 3;
int *filter_gx, *filter_gy;
sem_t *sem_mean;

const char *inputfile_name[5] = {
	"input1.bmp",
	"input2.bmp",
	"input3.bmp",
	"input4.bmp",
	"input5.bmp"
};
const char *outputMed_name[5] = {
	"output1.bmp",
	"output2.bmp",
	"output3.bmp",
	"output4.bmp",
	"output5.bmp"
};

unsigned char *pic_in, *pic_grey, *pic_mean, *pic_final;

unsigned char RGB2grey(int w, int h) {
	int tmp = (
		pic_in[3 * (h*imgWidth + w) + MYRED] +
		pic_in[3 * (h*imgWidth + w) + MYGREEN] +
		pic_in[3 * (h*imgWidth + w) + MYBLUE] )/3;

	if (tmp > 255) tmp = 255;
	return (unsigned char)tmp;
}

void *ThreadMeanFilter(void *arg) {
	int a, b, sum;
	for (int j = 0; j < imgHeight; j++) {
		for (int i = 0; i < imgWidth; i++) {
			sum = 0;
			for (int y = 0; y < wsize; y++) {
				for (int x = 0; x < wsize; x++) {
					a = i + x - (wsize / 2);
					b = j + y - (wsize / 2);
					if (a<0 || b<0 || a>=imgWidth || b>=imgHeight) continue;
					sum = sum + pic_grey[b*imgWidth + a];
				}
			}
			sum = sum / MEAN_FILTER_SIZE;
			if (sum > 255) sum = 255;
			pic_mean[j*imgWidth + i] = (unsigned char)sum;
			sem_post(&sem_mean[j*imgWidth + i]);
	 	}
	}
}

void *ThreadSobelFilter(void *arg) {
	unsigned char color;
	int gx, gy, a, b;
	for (int j = 0; j < imgHeight; j++) {
		for (int i = 0; i < imgWidth; i++) {
			gx = 0;
			gy = 0;
			if (i + 1 == imgWidth && j + 1 != imgHeight) {
				sem_wait(&sem_mean[(j+1)*imgWidth + i]);
				for (int y = 0; y < wsize; y++) {
					for (int x = 0; x < wsize; x++) {
						a = i + x - (wsize / 2);
						b = j + y - (wsize / 2);
						if (a<0 || b<0 || a>=imgWidth || b>=imgHeight) continue;
						gx += filter_gx[y*wsize + x] * pic_mean[b*imgWidth + a];
						gy += filter_gy[y*wsize + x] * pic_mean[b*imgWidth + a];
					}
				}
				sem_post(&sem_mean[(j+1)*imgWidth + i]);
			}
			else if (i + 1 != imgWidth && j + 1 == imgHeight) {
				sem_wait(&sem_mean[j*imgWidth + i + 1]);
				for (int y = 0; y < wsize; y++) {
					for (int x = 0; x < wsize; x++) {
						a = i + x - (wsize / 2);
						b = j + y - (wsize / 2);
						if (a<0 || b<0 || a>=imgWidth || b>=imgHeight) continue;
						gx += filter_gx[y*wsize + x] * pic_mean[b*imgWidth + a];
						gy += filter_gy[y*wsize + x] * pic_mean[b*imgWidth + a];
					}
				}
				sem_post(&sem_mean[j*imgWidth + i + 1]);
			}
			else if (i + 1 != imgWidth && j + 1 != imgHeight) {
				sem_wait(&sem_mean[(j+1)*imgWidth + i + 1]);
				for (int y = 0; y < wsize; y++) {
					for (int x = 0; x < wsize; x++) {
						a = i + x - (wsize / 2);
						b = j + y - (wsize / 2);
						if (a<0 || b<0 || a>=imgWidth || b>=imgHeight) continue;
						gx += filter_gx[y*wsize + x] * pic_mean[b*imgWidth + a];
						gy += filter_gy[y*wsize + x] * pic_mean[b*imgWidth + a];
					}
				}
				sem_post(&sem_mean[(j+1)*imgWidth + i + 1]);
			}
			else {
				for (int y = 0; y < wsize; y++) {
					for (int x = 0; x < wsize; x++) {
						a = i + x - (wsize / 2);
						b = j + y - (wsize / 2);
						if (a<0 || b<0 || a>=imgWidth || b>=imgHeight) continue;
						gx += filter_gx[y*wsize + x] * pic_mean[b*imgWidth + a];
						gy += filter_gy[y*wsize + x] * pic_mean[b*imgWidth + a];
					}
				}
			}
			if (gx < 0) gx = 0;
			if (gx > 255) gx = 255;
			if (gy < 0) gy = 0;
			if (gy > 255) gy = 255;
			int color = sqrt(gx*gx + gy*gy);
			if (color > 255) color = 255;
			pic_final[3 * (j*imgWidth + i) + MYRED] = (unsigned char)color;
			pic_final[3 * (j*imgWidth + i) + MYGREEN] = (unsigned char)color;
			pic_final[3 * (j*imgWidth + i) + MYBLUE] = (unsigned char)color;
		}
	}
}

int main() {
	FILE* mask;

	mask = fopen("mask_Sobel.txt", "r");
	fscanf(mask, "%d", &SOBEL_FILTER_SIZE);

	filter_gx = new int[SOBEL_FILTER_SIZE];
	filter_gy = new int[SOBEL_FILTER_SIZE];

	for (int i=0; i<SOBEL_FILTER_SIZE; i++)
		fscanf(mask, "%d", &filter_gx[i]);

	for (int i=0; i<SOBEL_FILTER_SIZE; i++)
		fscanf(mask, "%d", &filter_gy[i]);

	fclose(mask);
	
	BmpReader* bmpReader = new BmpReader();
	for (int k = 0; k < 5; k++) {
		pic_in = bmpReader->ReadBMP(inputfile_name[k], &imgWidth, &imgHeight);

		pic_grey = (unsigned char*)malloc(imgWidth*imgHeight*sizeof(unsigned char));
		pic_mean = (unsigned char*)malloc(imgWidth*imgHeight*sizeof(unsigned char));
		pic_final = (unsigned char*)malloc(3 * imgWidth*imgHeight*sizeof(unsigned char));

		sem_mean = (sem_t*)malloc(imgWidth*imgHeight*sizeof(sem_t));

		for (int j = 0; j < imgHeight; j++) {
			for (int i = 0; i < imgWidth; i++) {
				sem_init(&sem_mean[j*imgWidth + i], 0, 0);
				pic_grey[j*imgWidth + i] = RGB2grey(i, j);
			}
		}

		pthread_t tid_mean;
		pthread_t tid_sobel;
		pthread_create(&tid_mean, NULL, ThreadMeanFilter, NULL);
		pthread_create(&tid_sobel, NULL, ThreadSobelFilter, NULL);
		pthread_join(tid_mean, NULL);
		pthread_join(tid_sobel, NULL);

		bmpReader->WriteBMP(outputMed_name[k], imgWidth, imgHeight, pic_final);

		free(pic_in);
		free(pic_grey);
		free(pic_mean);
		free(pic_final);
		free(sem_mean);
	}

	return 0;
}