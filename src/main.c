#include "main.h"
#include "drive.h"

int confirm(char *message) {
  char *answer = calloc(1, sizeof(char));
  while (1) {
    printf("%s (y/n): ", message);
    scanf("%s", answer);
    if (strcmp(answer, "y") == 0) {
      free(answer);
      return 1;
    } else if (strcmp(answer, "n") == 0) {
      free(answer);
      return 0;
    } else {
      printf("Invalid answer.\n");
    }
  }
}
int main(int argc, char *argv[]) {
  int opt;
  int verbose, help = 0;
  while ((opt = getopt(argc, argv, "hv")) != -1) {
    switch (opt) {
    case 'v':
      verbose = 1;
      break;
    case 'h':
      help = 1;
      break;
    }
  }

  if (argc < 2 || help) {
    printf("Usage: %s <drive|partiton> (/dev/sdc or /dev/sdc1)\n", argv[0]);
    return 1;
  }

  char *menu_items[WIPE_MENU_SIZE] = {"Write zeros to drive", "Exit"};

  for (int i = 0; i < WIPE_MENU_SIZE; i++) {
    printf("%s [%d]\n", menu_items[i], i);
  }

  int menu_choice = 1;
  scanf("%d", &menu_choice);

  if (menu_choice != 0 && menu_choice != 1) {
    printf("Invalid menu choice.\n");
    return 1;
  }

  if (menu_choice == 0) {
    if (confirm("Are you sure you want to wipe the drive?")) {
      if (verbose) {
        printf("working... (Use -v to see progress)\n");
        if (write_zeros_512_verbose(argv[1]) == 0) {
          printf("Wipe successful.\n");
        } else {
          printf("Wipe failed.\n");
        }
      } else {
        printf("working... (Use -v to see progress)\n");
        if (write_zeros_512(argv[1]) == 0) {
          printf("Wipe successful.\n");
        } else {
          printf("Wipe failed.\n");
        }
      }

    } else {
      printf("Wipe cancelled.\n");
    }
  }
}