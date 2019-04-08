#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wq10_types.h"

static struct wq10_info WQ_10_OPTIONS;

static void clear_wq10_options(void)
{
	WQ_10_OPTIONS.input = NULL;
	WQ_10_OPTIONS.input_len = 0;
	WQ_10_OPTIONS.output_path = NULL;
}

static int get_wq10_options(const char** arguments)
{
	clear_wq10_options();
	while(*arguments != NULL)
	{
		if(strcmp(WQ10_OUTPUT_OPTION, *arguments) == 0) {
			arguments++;
			WQ_10_OPTIONS.output_path = *arguments;
			arguments++;

		} else if(strcmp(WQ10_INPUT_OPTION, *arguments) == 0) {
			arguments++;
			WQ_10_OPTIONS.input = *arguments;
			WQ_10_OPTIONS.input_len = strlen(WQ_10_OPTIONS.input);
			arguments++;
		} else {
			fprintf(stderr, "Error: Found unknown option '%s'.\n", *arguments);
			return 0;
		}
	}
	if(WQ_10_OPTIONS.input == NULL) {
		fprintf(stderr, "Error: Option '%s' not found.\n", WQ10_INPUT_OPTION);
		return 0;
	} else if(WQ_10_OPTIONS.output_path == NULL) {
		fprintf(stderr, "Error: Option '%s' not found.\n", WQ10_OUTPUT_OPTION);
		return 0;
	}
	return 1;
}




int main(int argc, char const *argv[])
{
	printf("the output size is %d\n", WQ10_OUTPUT_BUF_SIZE);
	return 0;
}
