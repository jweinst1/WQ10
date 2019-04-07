#include <stdio.h>
#include <stdlib.h>
#include "dopng.h"

static const char* FILE_PATH_NAME = "examp.png";

int main(int argc, char *argv[])
{
	unsigned char* buffer;

	int width = 50;
	int height = 50;


	printf("Creating Image at path:%s\n", FILE_PATH_NAME);
	buffer = malloc(50 * 50 * 3);
	if (buffer == NULL) {
		fprintf(stderr, "%s\n", "malloc returned null");
		return 1;
	}

	// Save the image to a PNG file
	// The 'title' string is stored as part of the PNG file
	printf("Saving PNG to path:%s\n", FILE_PATH_NAME);
	int result = write_png_to_file(FILE_PATH_NAME, width, height, buffer, "This is my test image");
	if(result) {
		fprintf(stderr, "PNG Creation failed with status: %d\n", result);
		free(buffer);
		return result;
	}
	// Free up the memorty used to store the image
	free(buffer);

	return result;
}
