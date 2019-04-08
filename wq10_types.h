#ifndef WQ10_TYPES_H
#define WQ10_TYPES_H

#define WQ10_OUTPUT_BUF_SIZE 30000

struct wq10_info {
	const char* input;
	unsigned long input_len;
	const char* output_path;
};

/**
 * Struct representing 24-bit rgb color
 */
struct rgb_t {
	unsigned char red;
	unsigned char blue;
	unsigned char green;
};
/**
 * This struct represents the 10 x 10 grid of colored squares.
 * Once the hash completes, these colors will be expanded into the actual
 * pixels in the output_buf. Since all the pixels in the same square
 * are the same color, we only need one rgb_t to keep track of the color.
 */
struct image_grid {
	struct rgb_t hash_blocks[100];
};

struct output_buf {
	unsigned char data[WQ10_OUTPUT_BUF_SIZE];
};

/*option macro forms*/

#define WQ10_OUTPUT_OPTION "--output"
#define WQ10_INPUT_OPTION "--input"


#endif // WQ10_TYPES_H
