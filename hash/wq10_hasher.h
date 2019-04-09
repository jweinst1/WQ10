#ifndef WQ10_HASHER_H
#define WQ10_HASHER_H

#include <stdlib.h>
#include <string.h>
#include "wq10_types.h"

extern void load_start_values(struct image_grid* grid);

extern void put_squares_to_buf(struct output_buf* des, struct image_grid* src);

extern int hash_input_into_buf(struct output_buf* buf, const char* input);

#endif // WQ10_HASHER_H
