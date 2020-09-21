Members: Quang Nguyen
	 Vinh Tran
CPSC 351-04
Professor: Kenytt Avery
Project: File Copy Reversed


Summary: The program is designed to take the content of a file and then reverse the content and copy it to another file using only system call. If the output file is
not exist, the program will create one.

Documenting: The program will take in three argument, the name of the program, the name of the file to reverse and the file to copy to. If the user fail to provide, 
an error will be called. After that, the variable inputFile and outputFile is created to store the input file and output file using the system call open(). A variable
countChar is also created to store the number of character in the input file by using the system call lseek(). The program will enter a for loop and use the read()
and write() system call to start copying the content from the input file to the output file. However, by using the lseek(), the program can relocate the cursor to the
end of the input file and start copying.

How to use the program: First, the user will need to compile the code by implementing this line in the kernel mode "g++ main.cpp -o main". Second, the user need to make
sure that there is already an input file existed in the PC since the program can only create the output file, and it will throw error if it can not find the input file. 
Third, the user input this line to use the program "./main 'nameOfTheInputFile.txt' 'nameOfTheOutputFile.txt'".