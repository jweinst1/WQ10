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


struct image_grid {
	struct rgb_t hash_blocks[100];
};

struct output_buf {
	unsigned char data[WQ10_OUTPUT_BUF_SIZE];
};


#endif // WQ10_TYPES_H
