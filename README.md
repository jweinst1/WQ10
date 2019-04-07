# png-template

*A template for projects writing pure bytes into a new PNG image*

## Intro

This project serves as a template or starting point for C programs that need to output a PNG image. It provides a simple interface to convert an array of bytes (unsigned 8-bit integer) into a PNG image. The bytes must represent RBG pixels, with no alpha channel. The main purpose is to abstract away the header and chunk writing, setting all the meta data, to make image generation a bit more simple.

## Building

In order to build the project, execute the following commands in your shell.

```
mkdir -p bin
cd bin
cmake ..
make
```

This will build the `dopng` STATIC library. To extend this functionality to other C executables or libraries, simply link this library. You can optionally add a CMAKE line to build a shared library if desired.

## Usage

The `dopng` library provides a single C function, declared as the following:

```c

extern int write_png_to_file(const char* filename, 
	            int width, 
	            int height, 
	            unsigned char *buffer, 
	            char* title);
```

#### Params

Here is an explanation of the parameters

* `filename`: This is a file path with a `.png` extension of where you want the output to go.
* `width`: Desired width of the output image. Cannot be `0`.
* `height`: Desired height of the output image. Cannot be `0`.
* `buffer`: A buffer of bytes to be written into the image output as pixel data. The function does not obtain ownership of this pointer, you can use either a static, dynamic, or other allocated pointer here.
* `title`: The meta data title written into the output PNG image.


### Notes

- The function returns zero for success, one if something failed.
- The function assumes 24-bit aligned data, 3 bytes per pixel.

## License

This project is licensed under the BSD-3 clause license.

*Note*: Beware the dependency, `libpng`, has it's own license, `PNG Reference Library License version 2`. This can be founder under `libpng/LICENSE`.
