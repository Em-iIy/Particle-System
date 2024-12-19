/*
Created by: Emily (Em_iIy) Winnink
Created on: 05/09/2024
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "bmp/bmp.h"


static uint16_t get_2_bytes(uint8_t *buff, size_t offset)
{
	return *(uint16_t *)(&buff[offset]);
}

static uint32_t get_4_bytes(uint8_t *buff, size_t offset)
{
	return *(uint32_t *)(&buff[offset]);
}

static void	bmp_print_header(bmp_header_t *hdr)
{
	printf("file signature:\t%X\n", hdr->id);
	printf("file size:\t%d\n", hdr->file_size);
	printf("data offset:\t%d\n", hdr->data_offset);
	printf("bitmap size:\t%d\n", hdr->bitmap_size);
	printf("bits per pixel:\t%d\n", hdr->bits_per_pixel);
	printf("width: %d\theight: %d\n", hdr->bitmap_width, hdr->bitmap_height);
	printf("BMP header bytes:\n");
	printf("%X:\t", 0);
	for (uint32_t i = 0; i < BMP_HEADER_SIZE; i++)
	{
		printf("[%02X]\t", hdr->BMP_header_raw_bytes[i]);
	}
	printf("\n");
	printf("BMP header bytes:");
	for (uint32_t i = 0; i < hdr->DIB_header_size; i++)
	{
		if (i % 16 == 0)
		{
			printf("\n%X:\t", BMP_HEADER_SIZE + i);
		}
		printf("[%02X]\t", hdr->DIB_header_raw_bytes[i]);
	}
	printf("\n");

}

static bool bmp_read_DIB_header(int fd, bmp_header_t *hdr)
{
	int			bytes_read;

	// Read in the DIB header size
	bytes_read = read(fd, &hdr->DIB_header_size, sizeof(hdr->DIB_header_size));
	if (bytes_read < 0)
	{
		perror("bmp_read_DIB_header read");
		return (false);
	}
	// Give error if the DIB header size could not be read
	if (bytes_read < (int)sizeof(hdr->DIB_header_size))
	{
		fprintf(stderr, "bmp error: invalid header\n");
		return (false);
	}
	// Return to the start of the DIB header
	if (lseek(fd, BMP_HEADER_SIZE, SEEK_SET) == -1)
	{
		perror("bmp_read_DIB_header lseek");
		return (false);
	}
	// Read in the DIB header
	bytes_read = read(fd, hdr->DIB_header_raw_bytes, hdr->DIB_header_size);
	if (bytes_read < 0)
	{
		perror("bmp_read_DIB_header read");
		return (false);
	}
	// Give error if the full header could not be read
	if (bytes_read < (int)hdr->DIB_header_size)
	{
		fprintf(stderr, "bmp error: invalid header\n");
		return (false);
	}
	// Retrieve the values from the DIB header
	hdr->bitmap_width = get_4_bytes(hdr->DIB_header_raw_bytes, 4);
	hdr->bitmap_height = get_4_bytes(hdr->DIB_header_raw_bytes, 8);
	hdr->bits_per_pixel = get_2_bytes(hdr->DIB_header_raw_bytes, 14);
	hdr->bitmap_size = get_4_bytes(hdr->DIB_header_raw_bytes, 20);
	return (true);
}

static bool bmp_read_BMP_header(int fd, bmp_header_t *hdr)
{
	int	bytes_read;

	// Read in the BMP header
	bytes_read = read(fd, hdr->BMP_header_raw_bytes, BMP_HEADER_SIZE);
	if (bytes_read < 0)
	{
		perror("bmp_read_BMP_header read");
		return (false);
	}
	// Give error if the bmp file does not have a full header
	if (bytes_read < BMP_HEADER_SIZE)
	{
		fprintf(stderr, "bmp error: invalid header\n");
		return (false);
	}
	hdr->id = get_2_bytes(hdr->BMP_header_raw_bytes, 0);
	// Give error if the bmp file does not start with "BM"
	if (hdr->id != BMP_SIGNATURE)
	{
		fprintf(stderr, "bmp error: invalid signature\n");
		return (false);
	}
	// Retrieve values from the header
	hdr->file_size = get_4_bytes(hdr->BMP_header_raw_bytes, 2);
	hdr->data_offset = get_4_bytes(hdr->BMP_header_raw_bytes, 10);
	return (true);
}

static bool	bmp_read_data_32bpp(int fd, bmp_header_t *hdr, bmp_t *bmp)
{
	uint8_t	*buffer;
	uint8_t	temp;
	int		bytes_read;

	// Set the fd to the start of the bit map
	if (lseek(fd, hdr->data_offset, SEEK_SET) == -1)
	{
		perror("bmp_read_data lseek");
		return (false);
	}
	// Allocate a buffer to read in the bitmap data
	buffer = (uint8_t *)malloc(hdr->bitmap_size);
	if (!buffer)
	{
		perror("malloc");
		return (false);
	}
	// Read in the bitmap data
	bytes_read = read(fd, buffer, hdr->bitmap_size);
	if (bytes_read < 0)
	{
		perror("read");
		return (false);
	}
	if (bytes_read < (int)hdr->bitmap_size)
	{
		fprintf(stderr, "bmp error: invalid data\n");
		return (false);
	}
	// Save useful values to the bmp_t struct
	bmp->width = hdr->bitmap_width;
	bmp->height = hdr->bitmap_height;
	bmp->pixel_size = hdr->bits_per_pixel / 8;
	bmp->size = bmp->width * bmp->height * bmp->pixel_size;

	// If padding is not used, there is no need to allocate a new array
	// to store the data in without the padding.
	bmp->data = buffer;
	for (uint32_t y = 0; y < bmp->height; y++)
	{
		for (uint32_t x = 0; x < bmp->width; x++)
		{
			// The current index of the pixel is:
			// amount of rows * length of row + the pixel in row * 4 bytes
			uint32_t i = i = (y * bmp->width + x) * bmp->pixel_size;
			
			// Here the pixels get converted from BGR to RGB
			temp = bmp->data[i];
			bmp->data[i] = bmp->data[i + 2];
			bmp->data[i + 2] = temp;
		}
	}
	return (true);
}

static bool	bmp_read_data_24bpp(int fd, bmp_header_t *hdr, bmp_t *bmp)
{
	uint8_t	*buffer;
	uint8_t	temp;
	int		bytes_read;
	int		count = 0;
	int		padding = 0;

	// Set the fd to the start of the bit map
	if (lseek(fd, hdr->data_offset, SEEK_SET) == -1)
	{
		perror("bmp_read_data lseek");
		return (false);
	}
	// Allocate a buffer to read in the bitmap data
	buffer = (uint8_t *)malloc(hdr->bitmap_size);
	if (!buffer)
	{
		perror("malloc");
		return (false);
	}
	// Read in the bitmap data
	bytes_read = read(fd, buffer, hdr->bitmap_size);
	if (bytes_read < 0)
	{
		perror("read");
		return (false);
	}
	if (bytes_read < (int)hdr->bitmap_size)
	{
		fprintf(stderr, "bmp error: invalid data\n");
		return (false);
	}
	// Save useful values to the bmp_t struct
	bmp->width = hdr->bitmap_width;
	bmp->height = hdr->bitmap_height;
	bmp->pixel_size = hdr->bits_per_pixel / 8;
	bmp->size = bmp->width * bmp->height * bmp->pixel_size;

	// Determine whether there would be padding
	// Each row has to be a multiple of 4 bytes long
	// So (amount of pixels * 3 bytes per pixel) % 4 should be 0
	// Otherwise padding is used to round up to the next multiple of 4
	// Because of this, buffer needs to get transferred to the
	// data array without the padding
	if ((bmp->width * bmp->pixel_size) % 4 != 0)
	{
		padding = 4 - (bmp->width * bmp->pixel_size) % 4;
		bmp->data = (uint8_t *)malloc(bmp->size);
		if (!bmp->data)
		{
			free(buffer);
			perror("malloc");
			return (false);
		}
		for (uint32_t y = 0; y < bmp->height; y++)
		{
			for (uint32_t x = 0; x < bmp->width; x++)
			{
				// The current index of the pixel is:
				// amount of rows * length of row + the pixel in row * 3 bytes
				uint32_t i = y * (bmp->width * bmp->pixel_size + padding) + x * bmp->pixel_size;
				// Here the pixels get converted from BGR to RGB
				bmp->data[count] = buffer[i + 2];
				bmp->data[count + 1] = buffer[i + 1];
				bmp->data[count + 2] = buffer[i];
				count += 3;
			}
		}
		free(buffer);
	}
	// If padding is not used, there is no need to allocate a new array
	// to store the data in without the padding.
	else
	{
		bmp->data = buffer;
		for (uint32_t y = 0; y < bmp->height; y++)
		{
			for (uint32_t x = 0; x < bmp->width; x++)
			{
				// The current index of the pixel is:
				// amount of rows * length of row + the pixel in row * 3 bytes
				uint32_t i = y * (bmp->width * bmp->pixel_size + padding) + x * bmp->pixel_size;
				// Here the pixels get converted from BGR to RGB
				temp = bmp->data[i];
				bmp->data[i] = bmp->data[i + 2];
				bmp->data[i + 2] = temp;
			}
		}
	}
	return (true);
}

bmp_t load_bmp(const char *file_name)
{
	int				fd;
	bmp_header_t	hdr;
	bmp_t			bmp;

	bzero(&bmp, sizeof(bmp_t));
	if (!file_name)
	{
		return (bmp);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("load_bmp: open");
		return (bmp);
	}
	// Read in headers
	if (bmp_read_BMP_header(fd, &hdr) == false)
	{
		close(fd);
		return (bmp);
	}
	if (bmp_read_DIB_header(fd, &hdr) == false)
	{
		close(fd);
		return (bmp);
	}
	// Read in data
	switch (hdr.bits_per_pixel)
	{
	case 24:
		if (bmp_read_data_24bpp(fd, &hdr, &bmp) == false)
		{
			close(fd);
			return (bmp);
		}
		break;

	case 32:
		if (bmp_read_data_32bpp(fd, &hdr, &bmp) == false)
		{
			close(fd);
			return (bmp);
		}
		break;
	
	default:
		fprintf(stderr, "bmp error: %d bits per pixel not supported\n", hdr.bits_per_pixel);
		close(fd);
		return (bmp);
		break;
	}
	close(fd);
	return (bmp);
	bmp_print_header(&hdr);
}

void	free_bmp(bmp_t bmp)
{
	free(bmp.data);
}
