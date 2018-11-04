#ifndef IMAGE_H
#define IMAGE_H
#define HEADER_SIZE 54

#define TURN_ON(t, p)   ((t) |= 1<<(p))
#define TURN_OFF(t, p)  ((t) &= ~(1<<(p)))
#define IS_ON(t, p)     ((t) & (1<<p))


/* contains all info about a image */
typedef struct 
{
	int width;
	int height;
	int size;
	char *pixels;
	char *header;
} image;

int getImage(image *dst, char *name);

void encodeMsg(image *img, char *msg);

void decodeMsg(image *img, char *outp);

int writeImage(image *img, char *newfile);

#endif