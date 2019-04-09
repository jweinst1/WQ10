#include "wq10_hasher.h"

enum color_load_mode {
	MAJOR_GREEN,
	MAJOR_BLUE,
	MAJOR_RED
};


static const unsigned OFFSET_VALUES[] = {
	5, 3, 1, 4, 8, 4, 2, 9
};

static const unsigned long OFFSET_VALUES_SIZE = sizeof(OFFSET_VALUES) / sizeof(unsigned);

extern void load_start_values(struct image_grid* grid)
{
	int i;
	enum color_load_mode picker;
	unsigned char last_red, last_green, last_blue;
	unsigned offset;
	last_red = 0;
	last_green = 0;
	last_blue = 0;
	offset = 0;
	for(i = 0; i < 100 ;i++)
	{
		

	}
}
