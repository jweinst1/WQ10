#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wq10_hasher.h"
#include "dopng.h"

#ifndef WQ10_OUTPUT_TITLE
#  warning "Option WQ10_OUTPUT_TITLE not set."
#endif // WQ10_OUTPUT_TITLE

static struct wq10_info WQ_10_OPTIONS;
static struct output_buf HASHED_OUTPUT;

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
	if(!get_wq10_options(argv + 1)) {
		fprintf(stderr, "%s\n", "Exiting.");
		exit(1);
	}
	printf("Preparing image hash of '%s', with size '%lu'\n", WQ_10_OPTIONS.input, WQ_10_OPTIONS.input_len);

	if(!hash_input_into_buf(&HASHED_OUTPUT, WQ_10_OPTIONS.input)) {
		fprintf(stderr, "%s\n", "HashError: Could not complete image hashing, exiting...");
		exit(2);
	}

	if(write_png_to_file(WQ_10_OPTIONS.output_path, 100, 100, HASHED_OUTPUT.data, WQ10_OUTPUT_TITLE) == 1) {
		fprintf(stderr, "%s\n", "Failed to write to png file, see other errors.");
		exit(4);
	}
	printf("Hashed image written to '%s'.\n", WQ_10_OPTIONS.output_path);
	return 0;
}
