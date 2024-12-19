/*
Created by: Emily (Em_iIy) Winnink
Created on: 05/09/2024
*/
#ifndef BMP_H
#define BMP_H

#include <stdint.h>

#define BMP_HEADER_SIZE 14
#define DIB_MAX_HEADER_SIZE 124
#define BMP_SIGNATURE 0x4D42

/*
* Stores the useful info from the BMP and BIP headers
* file_size: The full size of the file
* data_offset: The offset where the data of the image is stored
* bitmap_width: The width of the image in pixels
* bitmap_height: The height of the image in pixels
* DIB_header_size: length of the DIB header
* id: The signature of the file
* BMP_header_raw_bytes: The array where the BMP header gets stored
* BIP_header_raw_bytes: The array where the BIP header gets stored
*/
typedef struct bmp_header_s {
	uint32_t	file_size;
	uint32_t	bitmap_size;
	uint32_t	data_offset;
	uint32_t	bitmap_width;
	uint32_t	bitmap_height;
	uint32_t	DIB_header_size;
	uint16_t	bits_per_pixel;
	uint16_t	id;
	uint8_t		BMP_header_raw_bytes[BMP_HEADER_SIZE];
	uint8_t		DIB_header_raw_bytes[DIB_MAX_HEADER_SIZE];
}	bmp_header_t;

/*
* Stores the final info and data of the image
* size: The size of the data array
* width: The width of the image in pixels
* height: The height of the image in pixels
* data: The raw bytes of the image in RGB format
*/
typedef struct bmp_s {
	uint32_t	size;
	uint32_t	width;
	uint32_t	height;
	uint32_t	pixel_size;
	uint8_t		*data;
}	bmp_t;

/*
* Loads a bmp file into memory
* file_name: The name of the file
* Returns a bmp_t struct: contains size, width, height and data of the image
* Error: returns bmp.data = NULL
*/
bmp_t	load_bmp(const char *file_name);

/*
* Frees the bmp struct
*/
void	free_bmp(bmp_t bmp);

#endif
