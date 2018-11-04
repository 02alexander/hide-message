#include "image.h"
#include <stdio.h>

void encodeMsg(image *img, char *msg)
{
	char tch;
	int curpx;

	// loops through every 8th pixel 
	for (curpx = 0; curpx < img->size - 1; ++msg, curpx += 8) {


		tch = *msg; /* temporary char so
		 * the shift operator doesn't change the original value */

		/* loops through each bit in msg and
		 * puts it in the first bit of a pixel  */
		for (int i = 0; i < 8; ++i, tch<<=1) {
			if (IS_ON(tch, 7)) {
				TURN_ON(img->pixels[curpx + i], 0);
			} else {
				TURN_OFF(img->pixels[curpx + i], 0);
			}
		}
		if (*msg == '\0') // make sure it adds the terminating character
			return;
	} 
}

void decodeMsg(image *img, char *outp)
{
	/* loops through each pixel */
	for (int i = 0; i < img->size; ++outp, i += 8) {

		for (int j = 0; j < 8; ++j) {
			if (IS_ON(img->pixels[i + j], 0)) {
				TURN_ON(*outp, 0);
			} else {
				TURN_OFF(*outp, 0);
			}
			if (j != 7)
				*outp<<=1;
		}
		if (*outp == '\0') /* checks if the decoded char is the end */
			return;
	}	

}