#include "wq10_hasher.h"



extern int hash_input_into_buf(struct output_buf* buf, const char* input)
{
	struct image_grid grid;
	load_start_values(&grid);
	put_squares_to_buf(buf, &grid);
	buf->data[0] = (unsigned char)*input; // todo fix
	return 1;
}
