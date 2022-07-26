#include "drive.h"

int write_zeros_512(char *drive) {
  int fd = open(drive, O_WRONLY);
  char *zeros = calloc(512, sizeof(char));
  ssize_t written = 0;

  if (fd < 0) {
    perror("open");
    return -1;
  }

  if (zeros == NULL) {
    perror("calloc");
    return -1;
  }
  do {
    written = write(fd, zeros, 512);
  } while (written == 512);

  close(fd);
  free(zeros);
  return 0;
}

int write_zeros_512_verbose(char *drive)
{
  int fd = open(drive, O_WRONLY);
  char *zeros = calloc(512, sizeof(char));
  ssize_t written, total = 0;

  if (fd < 0) {
    perror("open");
    return -1;
  }

  if (zeros == NULL) {
    perror("calloc");
    return -1;
  }
  do {
    total += written = write(fd, zeros, 512);
    printf("\nBytes written: %ld", total);
  } while (written == 512);

  close(fd);
  free(zeros);
  return 0;
}
