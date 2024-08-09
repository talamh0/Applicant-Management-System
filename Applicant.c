#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define a struct to represent an applicant
struct Applicant {
    int id;
    char applicant[20];
    char education[20];
    char major[5];
    int Experience;
    float GPA;
    float Points;
    char State[10];
    struct Applicant *next;
};

// Declare a global variable to store the list of applicants
struct Applicant *list = NULL;

// Function to read applicant data from a file and create a linked list of applicants
void addApplicant() {
    struct Applicant *head = NULL, *current = NULL;

    // Open the file for reading
    FILE* file = fopen("Applicants.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Count the number of lines in the file
    int numOfLines = 0;
    int ch;
    while ((ch = getc(file)) != EOF) {
        if (ch == '\n') numOfLines++;
    }
    rewind(file);

    // Skip the first two lines
    for (int i = 0; i < 2; i++) {
        while ((ch = getc(file)) != '\n' && ch != EOF);
    }

    // Loop through the lines in the file and create Applicant structs for each line
    for (int i = 3; i <= numOfLines; i++) {
        struct Applicant *temp = (struct Applicant *) malloc(sizeof(struct Applicant));
        if (temp == NULL) {
            perror("Memory allocation failed");
            fclose(file);
            return;
        }

        if (fscanf(file, "%d %19s %19s %d %4s %f %9s", &temp->id, temp->applicant, temp->education, 
                    &temp->Experience, temp->major, &temp->GPA, temp->State) != 7) {
            fprintf(stderr, "Error reading data\n");
            free(temp);
            continue;
        }

        temp->Points = 0;
        temp->next = NULL;

        // Add the new Applicant struct to the linked list
        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = current->next;
        }
    }

    // Update the global list pointer to point to the head of the linked list
    list = head;
    fclose(file);
}

// Function to calculate points for each applicant based on their education and experience
void calculatePoints() {
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    struct Applicant *current = list;
    while (current != NULL) {
        if (strcmp(current->education, "MSc") == 0) {
            current->Points = current->GPA + current->Experience + 10;
        } else {
            current->Points = current->GPA + current->Experience;
        }
        current = current->next;
    }
}

// Function to set the state of each applicant based on their major
void setApplicantState(char* MajorList) {
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    struct Applicant *current = list;
    float max = 0;

    // Find the maximum points among candidates with majors in MajorList
    while (current != NULL) {
        if (strstr(MajorList, current->major) != NULL) {
            strcpy(current->State, "candidate");
            if (current->Points > max) max = current->Points;
        }
        current = current->next;
    }

    // Set the applicant with the highest points among candidates to "Assigned"
    current = list;
    while (current != NULL) {
        if (current->Points == max && strcmp(current->State, "candidate") == 0) {
            strcpy(current->State, "Assigned");
            break;
        }
        current = current->next;
    }
}

// Function to write the list of applicants to a file
void writeAssignedApplicants() {
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    FILE *file = fopen("Output_Applicants.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Applicant *current = list;
    fprintf(file, "The input Applicant list is:\n");
    fprintf(file, "%-15s %-20s %-20s %-20s %-15s %-15s %-20s\n", "ID", "Name", "Education", "Experience", "Major", "GPA", "State");
    while (current != NULL) {
        fprintf(file, "%-15d %-20s %-20s %-20d %-15s %-15.1f %-20s\n",
                current->id, current->applicant, current->education, current->Experience,
                current->major, current->GPA, current->State);
        current = current->next;
    }

    fprintf(file, "\n-------------\n");
    fprintf(file, "The candidate's list is:\n");
    fprintf(file, "%-15s %-20s %-20s %-20s %-15s %-20s\n", "ID", "Applicant", "Education", "Major", "Points", "State");
    current = list;
    while (current != NULL) {
        if (strcmp(current->State, "candidate") == 0 || strcmp(current->State, "Assigned") == 0) {
            fprintf(file, "%-15d %-20s %-20s %-20s %-15.2f %-20s\n",
                    current->id, current->applicant, current->education, current->major,
                    current->Points, current->State);
        }
        current = current->next;
    }

    fprintf(file, "\n-------------\n");
    fprintf(file, "The Assigned Applicant is:\n");
    current = list;
    while (current != NULL) {
        if (strcmp(current->State, "Assigned") == 0) {
            fprintf(file, "%-15d %-20s %-20s %-20s %-15.2f %-20s\n",
                    current->id, current->applicant, current->education, current->major,
                    current->Points, current->State);
            break;
        }
        current = current->next;
    }

    fclose(file);
}

// Function to print the list of applicants to the console
void printList() {
    if (list == NULL) {
        printf("Empty list\n");
        return;
    }

    struct Applicant *current = list;
    printf("The input Applicant list is:\n");
    printf("%-15s %-20s %-20s %-20s %-15s %-15s %-20s\n", "ID", "Name", "Education", "Experience", "Major", "GPA", "State");
    while (current != NULL) {
        printf("%-15d %-20s %-20s %-20d %-15s %-15.1f %-20s\n",
               current->id, current->applicant, current->education, current->Experience,
               current->major, current->GPA, current->State);
        current = current->next;
    }

    printf("\n-------------\n");
    printf("The candidate's list is:\n");
    printf("%-15s %-20s %-20s %-20s %-15s %-20s\n", "ID", "Applicant", "Education", "Major", "Points", "State");
    current = list;
    while (current != NULL) {
        if (strcmp(current->State, "candidate") == 0 || strcmp(current->State, "Assigned") == 0) {
            printf("%-15d %-20
