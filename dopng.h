#ifndef PNG_TEMPLATE_DO_PNG_H
#define PNG_TEMPLATE_DO_PNG_H


/**
 * This serves as a singular function interface to write a
 * 24-bit aligned buffer of bytes into a png image
 * to a file path.
 * Note: The function returns non-zero if the operation fails.
 */
extern int write_png_to_file(const char* filename, 
	            int width, 
	            int height, 
	            unsigned char *buffer, 
	            char* title);

#endif // PNG_TEMPLATE_DO_PNG_H
