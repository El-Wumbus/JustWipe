#include "main.h"
#include "drive.h"

int confirm(char *message) {
  /* Allocating memory for a single character. */
  char *answer = calloc(1, sizeof(char));
  while (1) { /* An infinite loop. */
    /* Asking the user to input a string and then storing it in the variable
     * `answer`. */
    printf("%s (y/n): ", message);
    scanf("%s", answer);

    /* Comparing the string `answer` to the string `y`. If they are equal, it
     * returns 1. */
    if (strcmp(answer, "y") == 0) {
      free(answer);
      return 1;
    }

    /* Comparing the string `answer` to the string `n`. If they are equal, it
       returns 0. */
    else if (strcmp(answer, "n") == 0) {
      free(answer);
      return 0;
    }

    /* Printing an error message if the user enters an invalid answer. */
    else {
      printf("Invalid answer.\n");
    }
  }
}

int main(int argc, char *argv[]) {
  int opt;
  int verbose, help = 0;

  /* Parsing the command line arguments. */
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

  /* Checking if the user has entered a command line argument. If they haven't,
  it prints the usage message and exits. */
  if (argc < 2 || help) {
    printf("Usage: %s <drive|partiton> (/dev/sdc or /dev/sdc1)\n", argv[0]);
    return 1;
  }

  /* Creating an array of strings. */
  char *menu_items[WIPE_MENU_SIZE] = {"Write zeros to drive", "Exit"};

  /* Printing the menu items. */
  for (int i = 0; i < WIPE_MENU_SIZE; i++) {
    printf("%s [%d]\n", menu_items[i], i);
  }

  /* Asking the user to enter a menu choice. */
  int menu_choice = 1;
  printf("Enter menu choice: ");
  scanf("%d", &menu_choice);

  /* Checking if the user has entered a valid menu choice. */
  if (menu_choice != 0 && menu_choice != 1) {
    printf("Invalid menu choice.\n");
    return 1;
  }

  if (menu_choice == 0) {
    /* Asking the user if they are sure they want to wipe the drive. If
    they say no, it prints "Wipe cancelled." */
    if (!confirm("Are you sure you want to wipe the drive?")) {
      printf("Wipe cancelled.\n");
      return 0;
    }

    /* Printing the string "Writing 0s to " and then the value of the
    variable `argv[2]`. */
    printf("Writing 0s to %s\n", argv[2]);


    if (verbose == 1) { /* Checking if the user has entered the `-v` command line argument. */

      if (write_zeros_512_verbose(argv[2]) == 0) {
        printf("Wipe successful.\n");
      } else {
        printf("Wipe failed.\n");
        return 1;
      }
    } else {
      if (write_zeros_512(argv[1]) == 0) {
        printf("Wipe successful.\n");
      } else {
        printf("Wipe failed.\n");
      }
    }
  }
}