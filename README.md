Applicant Management System

Overview

The Applicant Management System is a C program designed to efficiently manage and process job applicants. It reads applicant data from an input file, processes the data to calculate scores, updates applicant statuses, and outputs the results to both a file and the console. The program utilizes a linked list to manage applicant records and perform various operations based on their qualifications.

Features

1. Read Applicant Data

Imports applicant information from a text file, skipping non-data lines.

Creates a linked list of applicants.

2. Calculate Points

Computes a score for each applicant based on education and experience.

Applicants with a Master's degree receive additional points.

3. Update Applicant Status

Sets each applicant's status based on their major.

Assigns the highest-scoring applicant as "Assigned".

4. Write Results to File

Outputs the list of all applicants, candidates, and the assigned applicant to an output file.

5. Print Results to Console

Displays the list of all applicants, candidates, and the assigned applicant on the console.

File Structure

Applicants.txt: Input file containing applicant data.

Output_Applicants.txt: Output file where results are written.

main.c: The source file containing the main program and functions.

Prerequisites

To run the program, ensure you have the following:

A C compiler (e.g., GCC)

Basic understanding of C programming and linked lists

Compilation and Execution

Follow these steps to compile and execute the program:

1️⃣ Compile the Program:

gcc -o applicant_management main.c

2️⃣ Prepare the Input File:

Create an Applicants.txt file with applicant data formatted as follows:

<ID> <Name> <Education> <Experience> <Major> <GPA> <State>

Example Applicants.txt Format:

1 JohnDoe MSc 5 CSC 3.8 California
2 JaneSmith BSc 2 InS 3.5 NewYork
3 AliceBrown MSc 3 SWE 3.9 Texas
4 BobJohnson BSc 4 CEN 3.6 Florida

3️⃣ Run the Program:

./applicant_management

4️⃣ View Results:

Output File: Check the Output_Applicants.txt file for results.

Console Output: Displays the same information as in the output file.

Contribution

If you'd like to contribute, feel free to fork the repository, make improvements, and submit a pull request.
