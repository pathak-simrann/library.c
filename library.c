#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book library[MAX];
    int count = 0, choice;

    do {
        printf("\n===== Library Management Menu =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To clear input buffer after scanf

        switch (choice) {
            case 1:
                if (count < MAX) {
                    // Add book
                    printf("Enter Book ID: ");
                    scanf("%d", &library[count].id);
                    getchar();  // To clear newline from input buffer

                    printf("Enter Book Title: ");
                    fgets(library[count].title, sizeof(library[count].title), stdin);
                    library[count].title[strcspn(library[count].title, "\n")] = '\0';  // Remove newline from title

                    printf("Enter Book Author: ");
                    fgets(library[count].author, sizeof(library[count].author), stdin);
                    library[count].author[strcspn(library[count].author, "\n")] = '\0';  // Remove newline from author

                    count++;
                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No books available.\n");
                } else {
                    // Display all books
                    printf("\n--- Book List ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("ID: %d\n", library[i].id);
                        printf("Title: %s\n", library[i].title);
                        printf("Author: %s\n\n", library[i].author);
                    }
                }
                break;

            case 3: {
                int searchId, found = 0;
                // Search book by ID
                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);

                for (int i = 0; i < count; i++) {
                    if (library[i].id == searchId) {
                        printf("\nBook Found!\n");
                        printf("ID: %d\n", library[i].id);
                        printf("Title: %s\n", library[i].title);
                        printf("Author: %s\n\n", library[i].author);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Book with ID %d not found.\n", searchId);
                }
                break;
            }

            case 4:
                printf("Exited the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}