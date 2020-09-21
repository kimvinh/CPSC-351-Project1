/*
  Members: Vinh Tran (Email: kimvinh@csu.fullerton.edu)
           Quang Nguyen (Email: quangdnguyen2211@csu.fullerton.edu)
  Course: CPSC 351 - 04
  Professor: Kenytt Avery
  Project 1: File Copy Reversed
*/

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
  // Check the number of arguments from the command line
  if (argc < 3) {
    // Display the error message
    perror("There is a lack of argument(s) in the command line.\n");
    return EXIT_FAILURE;
  } else {
    int currentCursor = 0;

    // Open and read the input file
    int inputFile = open(argv[1], O_RDONLY);

    // Move the cursor to the end of the file
    // Also, count and store the number of characters in a string of the file into "countChar"
    int countChar = lseek(inputFile, currentCursor, SEEK_END);

    // Create (if does not exist) and open the output file
    // Users can read, write, and execute this file
    int outputFile = open(argv[2], O_WRONLY | O_CREAT, 0700);

    // Reverse the content and write it to the output file until reaching the value of "countChar"
    for (int i = 0; i < countChar; i++) {
      char ch;
      // Move the cursor backwardly through one by one character from the end of the file
      currentCursor--;
      lseek(inputFile, currentCursor, SEEK_END);

      // Read the character
      read(inputFile, &ch, 1);

      // Write the character into the output file
      write(outputFile, &ch, 1);
    }

    // Close the files
    close(inputFile);
    close(outputFile);
  }

  // Display the message about the completed task
  cout << "The content of \"" << argv[1] << "\" was successfully reversed and copied to \"" << argv[2] << "\""
       << endl;
  return EXIT_SUCCESS;
}
