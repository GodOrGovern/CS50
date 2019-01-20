# Questions

## What's `stdint.h`?

stdint.h defines new integer types that increase the portability of programs compiled in C99.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They create uniformly sized variables.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE is one byte; a DWORD is four bytes; a LONG is also four bytes; a WORD is two bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes must be BM (in ASCII).

## What's the difference between `bfSize` and `biSize`?

bfSize specifies the size (in bytes) of the entire file, biSize specifies only the size (in bytes) of the structure BITMAPINFOHEADER.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is top-down DIB that originates in the upper-left corner and it cannot be compressed.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The field biBitCount specifies the bits-per-pixel in a bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

In line 24 it might return NULL if the given infile does not exist, is corrupted, or cannot be accessed for some other reason. In line 32 it might return NULL if there is not enough memory to create or enough storage to keep the given outfile.

## Why is the third argument to `fread` always `1` in our code?

The third argument is 1 because each structure constitutes one item of data.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

It assigns a value of 3 to padding.

## What does `fseek` do?

fseek() changes what part of a file is being addressed by moving some distance away from a given location. In this case it is used to skip over padding at the end of a scanline.

## What is `SEEK_CUR`?

SEEK_CUR is used as the third argument in fseek(). It indicates an offset from the current location.
