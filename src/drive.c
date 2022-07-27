#include "drive.h"

/**
 * Opens the drive for writing, allocates 512 bytes of memory and initializes it
 * to 0, and writes 512 bytes of zeros to the drive
 *
 * @param drive The drive that you want to write zeros to.
 *
 * @return 0.
 */
int write_zeros_512(char *drive) {
  /* Opening the drive for writing. */
  int fd = open(drive, O_WRONLY);
  /* Allocating 512 bytes of memory and initializing it to 0. */
  char *zeros = calloc(512, sizeof(char));
  ssize_t written = 0;

  /* Checking if the file descriptor is less than 0. If it is, it prints an
  error message and returns -1. */
  if (fd < 0) {
    perror("open");
    return -1;
  }

  /* Checking if the calloc function failed. If it did, it prints an error
   * message and returns -1. */
  if (zeros == NULL) {
    perror("calloc");
    return -1;
  }

  /* Writing 512 bytes of zeros to the drive. */
  do {
    written = write(fd, zeros, 512);
  } while (written ==
           512); /* Checking if the number of bytes written is equal to 512. If
it is, it will continue to write 512 bytes of zeros to the drive. */

  /* Close the file descriptor. */
  close(fd);

  /* Freeing the memory that was allocated by the calloc function. */
  free(zeros);
  return 0;
}

int write_zeros_512_verbose(char *drive) {
  /* Opening the drive for writing. */
  int fd = open(drive, O_WRONLY);
  /* Allocating 512 bytes of memory and initializing it to 0. */
  char *zeros = calloc(512, sizeof(char));
  ssize_t written, total = 0;

  /* Checking if the file descriptor is less than 0. If it is, it prints an
  error message and returns -1. */
  if (fd < 0) {
    perror("open");
    return -1;
  }

  /* Checking if the calloc function failed. If it did, it prints an error
  message and returns -1. */
  if (zeros == NULL) {
    perror("calloc");
    return -1;
  }

  do {
    /* Adding the number of bytes written to the total number of bytes
    written. */
    total += written = write(fd, zeros, 512);
    /* Printing the total number of bytes written to the drive. */
    printf("\nBytes written: %ld", total);
  } while (written == 512); /* Checking if the number of bytes written is equal to 512. If it is,
  it will continue to write 512 bytes of zeros to the drive. */

  /* Close the file descriptor. */
  close(fd);

  /* Freeing the memory that was allocated by the calloc function. */
  free(zeros);
  return 0;
}
