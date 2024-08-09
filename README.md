//Applicant Management System
#Overview
The Applicant Management System is a C program designed to manage and process job applicants. It reads applicant data from an input file, processes the data to calculate scores, updates applicant statuses, and outputs the results to both a file and the console. The program utilizes a linked list to manage applicant records and perform various operations based on the applicant's qualifications.

#Features
1/Read Applicant Data: Imports applicant information from a text file, skipping non-data lines, and creates a linked list of applicants.
2/Calculate Points: Calculates a score for each applicant based on their education and experience. Applicants with a Master's degree receive additional points.
3/Update Applicant State: Sets each applicant's status based on their major and assigns the highest-scoring applicant as "Assigned".
4/Write Results to File: Outputs the list of all applicants, candidates, and the assigned applicant to an output file.
5/Print Results to Console: Displays the list of all applicants, candidates, and the assigned applicant on the console.

#File Structure
1/Applicants.txt: Input file containing applicant data.
2/Output_Applicants.txt: Output file where results are written.
3/main.c: The source file containing the main program and functions.

#Prerequisites
1/A C compiler (e.g., GCC)
2/A basic understanding of C programming and linked lists

#Compilation and Execution
To compile and run the program, follow these steps:

1/Compile the Program:
gcc -o applicant_management main.c
Prepare Input File:

2/Create an Applicants.txt file with applicant data formatted as follows:
php
<ID> <Name> <Education> <Experience> <Major> <GPA> <State>

3/Run the Program:
bash
./applicant_management

4/View Results:
Check the Output_Applicants.txt file for the output.
Results will also be printed to the console.

*Example
Sample Applicants.txt Format:
css:
1 JohnDoe MSc 5 CSC 3.8 California
2 JaneSmith BSc 2 InS 3.5 NewYork
3 AliceBrown MSc 3 SWE 3.9 Texas
4 BobJohnson BSc 4 CEN 3.6 Florida

Output:
In Output_Applicants.txt:
Includes the full list of applicants, candidates, and the assigned applicant.
On Console:
Displays the same information as in the output file.
Contributing
