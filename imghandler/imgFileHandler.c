#include "image.h"
#include <stdlib.h>
#include <stdio.h>

int getImage(image *dst, char *name)
{
	FILE *fimg;

	if (dst == NULL)
		return 2;
	if ((fimg = fopen(name, "r")) == NULL)
		return 1;

	dst->header = malloc(HEADER_SIZE);
	fread(dst->header, 1, HEADER_SIZE, fimg);

	dst->width = *(int*)&dst->header[18];
	dst->height = *(int*)&dst->header[22];
	dst->size = 3 * dst->width * dst->height;
	dst->pixels = malloc(dst->size);

	fread(dst->pixels, 1, dst->size, fimg);

	fclose(fimg);
	return 0;
}

int writeImage(image *img, char *fname)
{
	FILE *fp;

	if ((fp = fopen(fname, "w")) == NULL) 
		return 1;
	fwrite(img->header, 1, HEADER_SIZE, fp);
	fwrite(img->pixels, 1, img->size, fp);
	fflush(fp);
	fclose(fp);

	return 0;
}