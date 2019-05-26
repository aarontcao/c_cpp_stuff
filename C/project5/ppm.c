#include "ppm.h"
#include "stdlib.h"
#include "scanner.h"

// this function adds ppmPic to the myPic of ppmPic
ppmPic *read(char *filename)
{
	ppmPic *myPic;
	myPic=(ppmPic*)malloc(sizeof(ppmPic));
	FILE *fp;
	fp = fopen(filename, "r");
	fscanf(fp, "P3 %d %d %d\n", &myPic->rows, &myPic->cols, &myPic->colors);
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	int i, j;
	for (i=0; i < myPic->rows; i++)
	{
		myPic->pixels[i]=malloc(sizeof(Pixel) * myPic->cols);
		for (j=0; j < myPic->cols; j++)
		{
			fscanf(fp, "%d", &myPic->pixels[i][j].red);
			fscanf(fp, "%d", &myPic->pixels[i][j].green);
			fscanf(fp, "%d", &myPic->pixels[i][j].blue);
		}
	}

    fclose(fp);
	return myPic;
}

void write(char *filename, ppmPic *myPic)
{
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d %d\n", myPic->rows, myPic->cols, myPic->colors);
	int i, j;
	for (i=0; i < myPic->rows; i++)
	{
		for (j=0; j < myPic->cols; j++)
		{
			fprintf(fp, "%d ", myPic->pixels[i][j].red);
			fprintf(fp, "%d ", myPic->pixels[i][j].green);
			fprintf(fp, "%d ", myPic->pixels[i][j].blue);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return;
}

void copy(char *filename, ppmPic *myPic)
{
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d %d\n", myPic->rows, myPic->cols, myPic->colors);
	int i, j;
	for (i=0; i < myPic->rows; i++)
	{
		for (j=0; j < myPic->cols; j++)
		{
			fprintf(fp, "%d ", myPic->pixels[i][j].red);
			fprintf(fp, "%d ", myPic->pixels[i][j].green);
			fprintf(fp, "%d ", myPic->pixels[i][j].blue);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return;
}

void grow(char *filename, ppmPic *myPic)
{
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d %d\n", 2*myPic->rows, 2*myPic->cols, myPic->colors);
	int i, j;
	for (i=0; i < myPic->cols; i++)
	{
		for (j=0; j < myPic->rows; j++)
		{
			fprintf(fp, "%d ", myPic->pixels[i][j].red);
			fprintf(fp, "%d ", myPic->pixels[i][j].green);
			fprintf(fp, "%d ", myPic->pixels[i][j].blue);
			fprintf(fp, "%d ", myPic->pixels[i][j].red);
			fprintf(fp, "%d ", myPic->pixels[i][j].green);
			fprintf(fp, "%d ", myPic->pixels[i][j].blue);
		}
		fprintf(fp, "\n");
		for (j=0; j < myPic->cols; j++)
		{
			fprintf(fp, "%d ", myPic->pixels[i][j].red);
			fprintf(fp, "%d ", myPic->pixels[i][j].green);
			fprintf(fp, "%d ", myPic->pixels[i][j].blue);
			fprintf(fp, "\n");
			fprintf(fp, "%d ", myPic->pixels[i][j].red);
			fprintf(fp, "%d ", myPic->pixels[i][j].green);
			fprintf(fp, "%d ", myPic->pixels[i][j].blue);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return;
}

void shrink(char *filename, ppmPic *myPic)
{
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d %d\n", (myPic->rows)/2, (myPic->cols)/2, myPic->colors);
	int i, j;
	for (i=0; i < myPic->cols; i=i+2)
	{
		for (j=0; j < myPic->rows; j=j+2)
		{
			fprintf(fp, "%d ", (myPic->pixels[i][j].red+myPic->pixels[i+1][j].red+myPic->pixels[i][j+1].red+myPic->pixels[i+1][j+1].red)/4);
			fprintf(fp, "%d ", (myPic->pixels[i][j].green+myPic->pixels[i+1][j].green+myPic->pixels[i][j+1].green+myPic->pixels[i+1][j+1].green)/4);
			fprintf(fp, "%d ", (myPic->pixels[i][j].blue+myPic->pixels[i+1][j].blue+myPic->pixels[i][j+1].blue+myPic->pixels[i+1][j+1].blue)/4);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return;
}