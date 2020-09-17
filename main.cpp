#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <cstring>
using namespace std;

// Compile code: c++ -o FileCopyReversed -std=c++17 -Wall main.cpp
// Run the program: ./FileCopyReversed
//              or: ./FileCopyReversed input.txt output.txt
// To open and read "output.txt", you must use "chmod" command
// chmod u=rwx output.txt

int main(int argc, char *argv[]) {
  if (argc < 3) {
    perror("There is no input/output file to copy.\n");
    return EXIT_FAILURE;
  } else {
    char ch;
    // Open and read the input file
    int inputFile = open(argv[1], O_RDONLY);
    // Create (if does not exist) and open the output file
    int outputFile = open(argv[2], O_WRONLY | O_CREAT, 0755);
    // Read the content of the input file
    // And write them into "ch" array
    while (read(inputFile, &ch, 1) != 0) {
      // Write all elements from "ch" array into the output file
      write(outputFile, &ch, 1);
    }

    close(inputFile);
    close(outputFile);
  }
  return EXIT_SUCCESS;
}
