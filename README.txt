# Members: Quang Nguyen
	   Vinh Tran

# CPSC 351-04

# Professor: Kenytt Avery

# Project 1: File Copy Reversed

## Summary: 

The program is designed to copy and reverse the content of a source file and copy it to a destination file using system calls. 

## Operation:
 
If the process receives three valid arguments which are the executive file, the source file, 
and the destination file respectively from the command line, it will continue doing its task.
Otherwise, the error message will be displayed, and the process is terminated.

## Task:

1. The source file is opened, and the cursor will be moved to the end of the file. Also, there is a counter to count the
number of characters in the content.
2. The destination file is created (if it does not exist) and opened.
3. Read and write the content of the source file into the destination file by reversing and copying character by character
until reaching the value of the counter.
4. Close the source file and the destination file.
5. Display the message to inform the completed task.

## "CPSC-351-Project1.tar.gz" Contents:

1. README.txt       // This file
2. main.cpp         // The source code of the program
3. output.txt       // The output of running 'strace' command

## Compile and Run The Program:

1. To compile the source code, command:
$ c++ -o FileCopyReversed -std=c++ -Wall main.cpp     // "FileCopyReversed" is created as the executive file

2. To run the program by only copying and writing the reversed contents of the input file into the 
destination file, command:
$ ./FileCopyReversed your_source_file.txt your_destination_file.txt

3. To run the program by writing the output of 'strace' command into "output.txt" file and copying and 
writing the reversed contents of the input file into the destination file, command:
$ strace -o output.txt ./FileCopyReversed your_source_file.txt your_destination_file.txt