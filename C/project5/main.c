#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#include "ppm.h"

int main(int argc, char *argv[]) {
	char *filename;
	char *filelame;
	char *cmd;
	cmd=argv[1];
	filename=argv[2];
	filelame=argv[3];
	ppmPic *myPic;
	myPic=read(filename);
	if (strcmp(cmd, "copy")==0)
	{
		copy(filelame, myPic);
	}
	else if (strcmp(cmd, "grow")==0)
	{
		grow(filelame, myPic);
	}
	else if (strcmp(cmd, "shrink")==0)
	{
		shrink(filelame, myPic);
	}
	return 0;
}
