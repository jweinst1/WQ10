#ifndef WQ10_TYPES_H
#define WQ10_TYPES_H

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


#endif // WQ10_TYPES_H
