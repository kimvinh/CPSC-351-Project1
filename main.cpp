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
  if (argc < 2) {
    perror("There is no input file to copy.\n");
    return EXIT_FAILURE;
  } else {
    // Creat "ch" array to save the content of the input file
    char ch[11];
    // Open and read the input file
    int inputFile = open(argv[1], O_RDONLY);
    // Read the content of the input file
    // And write them into "ch" array
    read(inputFile, ch, 11);
    // Create (if does not exist) and open the output file
    int outputFile = open(argv[2], O_RDWR | O_CREAT);
    // Write all elements from "ch" array into the output file
    write(outputFile, ch, 11);

    close(inputFile);
    close(outputFile);
  }
  return EXIT_SUCCESS;
}
