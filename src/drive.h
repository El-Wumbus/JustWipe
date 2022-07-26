#ifndef DRIVE_H
#define DRIVE_H
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int write_zeros_512(char *drive);
int write_zeros_512_verbose(char *drive);
#endif // DRIVE_H