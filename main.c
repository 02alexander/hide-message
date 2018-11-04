#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "imghandler/image.h"

void freeImage(image *img);

int main(int argc, char *argv[])
{
	image img;
	int i, j;
	char ch;
	char *output;
	char *input;

	for (i = 1; i < argc; ++i) {
		if (*argv[i]++ == '-') {
			switch(*argv[i]) {
				case 'd':
					/* decodes image */
					if (getImage(&img, argv[i+1]) > 0) {
						fprintf(stderr, "getImage() error: %s\n", strerror(errno));
						return 1;
					}
					output = malloc(img.size / 8);
					decodeMsg(&img, output);
					printf("%s", output);
					freeImage(&img);
					free(output);
					break;
				case 'e':
					/* encodes image */
					if (getImage(&img, argv[i+1]) > 0) {
						fprintf(stderr, "getImage() error: %s\n", strerror(errno));
						return 1;
					}
					input = malloc(img.size / 8);
					for (j = 0; j < img.size / 8 - 1 && (ch=getchar()) != EOF;++j)
						input[j] = ch;
					input[j] = '\0';
					encodeMsg(&img, input);
					if (writeImage(&img, argv[i+1]) > 0) 
						fprintf(stderr, "writeImage() error: %s\n", strerror(errno));
					free(input);
					break;
			
			}
		}
	}
}

void freeImage(image *img)
{
	free(img->pixels);
	img->pixels = NULL;
	free(img->header);
	img->header = NULL;
}
