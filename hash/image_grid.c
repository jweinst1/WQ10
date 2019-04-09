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
	picker = MAJOR_GREEN;
	for(i = 0; i < 100 ;i++) {
		switch(picker) {
			case MAJOR_GREEN:
			    grid->hash_blocks[i].green = 255;
			    grid->hash_blocks[i].blue = OFFSET_VALUES[offset];
			    grid->hash_blocks[i].red = OFFSET_VALUES[offset] + 3;
			    break;
			case MAJOR_RED:
			    grid->hash_blocks[i].green = OFFSET_VALUES[offset] + 5;
			    grid->hash_blocks[i].blue = OFFSET_VALUES[offset];
			    grid->hash_blocks[i].red = 255;
			    break;
			case MAJOR_BLUE:
			    grid->hash_blocks[i].green = OFFSET_VALUES[offset] + 5;
			    grid->hash_blocks[i].blue = 255;
			    grid->hash_blocks[i].red = OFFSET_VALUES[offset] + 3;			
			    break;
		}
		offset = (offset == OFFSET_VALUES_SIZE ? 0 : (offset + 1));
	}
}

#define PUT_COLOR_TO_BYTE(byte, color) \
                             *byte++ = color.red; \
                             *byte++ = color.green; \
                             *byte++ = color.blue

#define PUT_COLOR_TO_BYTE_10X(byte, color) \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color); \
                             PUT_COLOR_TO_BYTE(byte, color)

extern void put_squares_to_buf(struct output_buf* des, struct image_grid* src)
{
	unsigned row, row_n, row_inc;
	struct rgb_t color;
	unsigned char* writer = des->data;
	for(row = 0; row < 10; row++) {
		row_inc = row * 10;
		row_n = 0;
		while( row_n++ < 10 ) {
			color = src->hash_blocks[row_inc];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 1];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 2];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 3];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 4];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 5];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 6];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 7];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 8];
			PUT_COLOR_TO_BYTE_10X(writer, color);
			color = src->hash_blocks[row_inc + 9];
			PUT_COLOR_TO_BYTE_10X(writer, color);
		}
	}
}
