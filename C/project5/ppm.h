#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pixel {
	int red;
	int green;
	int blue;
} Pixel;

typedef struct ppm {
	int rows;		//number of rows
	int cols;		//number of columns
	int colors;		// number of colors
	Pixel **pixels;	//actual pixel data
} ppmPic;

ppmPic *read(char *);

void write(char *, ppmPic *);

void copy(char *, ppmPic *);

void grow(char *, ppmPic *);

void shrink(char *, ppmPic *);