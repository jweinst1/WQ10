#include "wq10_hasher.h"


static void hash_feed_into_grid(struct image_grid* grid, const char* input)
{
	struct rgb_t* cptr;
	unsigned color_i;
	unsigned char feed;
	color_i = 0;
	cptr = grid->hash_blocks + color_i;
	while(*input)
	{
		feed = (unsigned char)(*input);
		cptr->red ^= feed;
		cptr->blue ^= feed - 50;
		cptr->green ^= ~feed;
		input++;
	}
}


extern int hash_input_into_buf(struct output_buf* buf, const char* input)
{
	struct image_grid grid;
	load_start_values(&grid);
	// Feed the input into the grid, round one.
	hash_feed_into_grid(&grid, input);
	put_squares_to_buf(buf, &grid);
	return 1;
}
