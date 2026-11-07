#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student node
struct Student
{
    int rollNo;
    char name[50];
    float marks;
    struct Student *next;
};

// Head pointer
struct Student *head = NULL;

/* Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void countStudents();*/

// 1. Add student
void addStudent()
{
    struct Student *newStudent;
    struct Student *temp;

    newStudent = (struct Student *)malloc(sizeof(struct Student));

    if (newStudent == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent->rollNo);

    printf("Enter Name: ");
    scanf(" %49[^\n]", newStudent->name);

    printf("Enter Marks: ");
    scanf("%f", &newStudent->marks);

    newStudent->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newStudent;
    }

    printf("\nStudent added successfully!\n");
}

// 2. Display all students
void displayStudents()
{
    struct Student *temp = head;

    if (head == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n------ STUDENT DATABASE ------\n");

    while (temp != NULL)
    {
        printf("\nRoll Number : %d\n", temp->rollNo);
        printf("Name        : %s\n", temp->name);
        printf("Marks       : %.2f\n", temp->marks);

        temp = temp->next;
    }
}

// 3. Search student
void searchStudent()
{
    int roll;
    struct Student *temp = head;

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    while (temp != NULL)
    {
        if (temp->rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", temp->rollNo);
            printf("Name        : %s\n", temp->name);
            printf("Marks       : %.2f\n", temp->marks);

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found.\n");
}

// 4. Update student
void updateStudent()
{
    int roll;
    struct Student *temp = head;

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    while (temp != NULL)
    {
        if (temp->rollNo == roll)
        {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", temp->name);

            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("\nStudent record updated successfully!\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found.\n");
}

// 5. Delete student
void deleteStudent()
{
    int roll;

    struct Student *temp = head;
    struct Student *previous = NULL;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    // Find student
    while (temp != NULL && temp->rollNo != roll)
    {
        previous = temp;
        temp = temp->next;
    }

    // Student not found
    if (temp == NULL)
    {
        printf("\nStudent not found.\n");
        return;
    }

    // First node
    if (previous == NULL)
    {
        head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    free(temp);

    printf("\nStudent deleted successfully!\n");
}

// 6. Count students
void countStudents()
{
    int count = 0;

    struct Student *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("\nTotal Students = %d\n", count);
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n==============================");
        printf("\n  LINKED LIST STUDENT DATABASE");
        printf("\n==============================");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Count Students");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                countStudents();
                break;

            case 7:
                printf("\nExiting Student Database...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
/*Save and load student records using file handling.
Sort student records by marks or student ID.
Prevent duplicate student IDs.
Add a menu-driven interface with input validation.*/
