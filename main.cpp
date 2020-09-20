#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

// Compile code: c++ -o FileCopyReversed -std=c++17 -Wall main.cpp
// Run the program: ./FileCopyReversed (The program is error due to missing argument(s))
//              or: ./FileCopyReversed input.txt (The program is error due to missing argument(s))
//              or: ./FileCopyReversed input.txt output.txt (The program works perfectly)

int main(int argc, char *argv[]) {
  if (argc < 3) {
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
    // Users allow to read, write, and execute this file
    int outputFile = open(argv[2], O_WRONLY | O_CREAT, 0700);

    // Move the cursor backwardly char by char in a string until reaching the beginning of the file
    // Also, concurrently, store each character in a string into "characters" array
    for (int i = 0; i < countChar; i++) {
      char ch;
      // Move backwardly one by one character from the end of the file
      currentCursor--;
      lseek(inputFile, currentCursor, SEEK_END);

      // Read the character
      read(inputFile, &ch, 1);

      // Write all elements of "characters" into the output file
      write(outputFile, &ch, 1);
    }

    // Close the files
    close(inputFile);
    close(outputFile);
  }

  cout << "The content of \"" << argv[1] << "\" was successfully reversed and copied to \"" << argv[2] << "\""
       << endl;
  return EXIT_SUCCESS;
}
