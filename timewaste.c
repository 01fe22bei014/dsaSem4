#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE_LENGTH 100
#define TABLE_SIZE 100

typedef struct Node

 {
    char data[MAX_LINE_LENGTH];
    struct Node* next;

} Node;

typedef struct
 {
    Node* head;

} HashTable;

int hashFunction(const char *key)
 {
    int hash = 0;
    while (*key) {
        hash += *key;
        key++;
    }

    return hash % TABLE_SIZE;
}

void insertIntoHashTable(HashTable* table, const char *data) {

    int index = hashFunction(data);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->data, data, MAX_LINE_LENGTH - 1);
    newNode->data[MAX_LINE_LENGTH - 1] = '\0';
    newNode->next = NULL;

    newNode->next = table[index].head;
    table[index].head = newNode;
}


void displayHashTable(HashTable* table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
        {
        printf("Index %d: ", i);

        Node* current = table[i].head;
        while (current != NULL)
            {
            printf("%s ", current->data);
            current = current->next;
        }

        printf("\n");
    }
}

Node* searchHashTableByBID(HashTable* table, const char* bid)
{
    for (int i = 0; i < TABLE_SIZE; i++)
        {
        Node* current = table[i].head;
        while (current != NULL)
        {
            char currentBid[MAX_LINE_LENGTH];
            strncpy(currentBid, current->data, MAX_LINE_LENGTH - 1);
            currentBid[MAX_LINE_LENGTH - 1] = '\0';

            if (strstr(currentBid, bid) != NULL) {
                return current;
            }
            current = current->next;
        }
    }

    return NULL;
}

void displayDataFromFile(const char *filePath, HashTable* hashTable)
{
    FILE* filePointer;
    char dataToBeRead[MAX_LINE_LENGTH];

    filePointer = fopen(filePath, "r");

    if (filePointer == NULL)
        {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    } else
    {
        printf("The file is now opened.\n");

        while(fgets(dataToBeRead, sizeof(dataToBeRead), filePointer) != NULL)

            {
            printf("%s", dataToBeRead);
            insertIntoHashTable(hashTable, dataToBeRead);
        }

        fclose(filePointer);

        printf("\nData successfully read from file.\n");
        printf("The file is now closed.\n");
    }
}

void readDistancesFromFile(const char *filePath, int distances[TABLE_SIZE][TABLE_SIZE]) {
    FILE* filePointer;
    char line[MAX_LINE_LENGTH];
    int i = 0, j = 0;

    filePointer = fopen(filePath, "r");

    if (filePointer == NULL) {
        perror("Error opening distances file");
        exit(EXIT_FAILURE);
    } else {
        printf("Distances file is now opened.\n");

        while (fgets(line, sizeof(line), filePointer) != NULL) {
            char* token = strtok(line, " ");
            while (token != NULL) {
                distances[i][j++] = atoi(token);
                token = strtok(NULL, " ");
            }
            i++;
            j = 0;
        }

        fclose(filePointer);

        printf("\nDistances successfully read from file.\n");
        printf("Distances file is now closed.\n");
     }
 }
 void deleteFromHashTable(HashTable* table, const char* data) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        Node* prev = NULL;

        while (current != NULL) {
            if (strcmp(current->data, data) == 0) {
                if (prev == NULL) {
                    // If the node to be deleted is the head of the list
                    table[i].head = current->next;
                } else {
                    // If the node to be deleted is not the head
                    prev->next = current->next;
                }

                free(current);
                printf("Data deleted from hash table: %s\n", data);
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    printf("Data not found in hash table: %s\n", data);
}

// Dijkstra's Algorithm
void dijkstra(int distances[TABLE_SIZE][TABLE_SIZE], int start) {
    int visited[TABLE_SIZE];
    int shortestDistance[TABLE_SIZE];
    int parent[TABLE_SIZE];

    // Initialization
    for (int i = 0; i < TABLE_SIZE; i++) {
        visited[i] = 0;
        shortestDistance[i] = INT_MAX;
        parent[i] = -1;
    }

    shortestDistance[start] = 0;

    for (int count = 0; count < TABLE_SIZE - 1; count++) {
        int u = -1;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!visited[i] && (u == -1 || shortestDistance[i] < shortestDistance[u]) && shortestDistance[u] != INT_MAX) {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < TABLE_SIZE; v++) {
            if (!visited[v] && distances[u][v] != -1 && shortestDistance[u] + distances[u][v] < shortestDistance[v]) {
                shortestDistance[v] = shortestDistance[u] + distances[u][v];
                parent[v] = u;
            }
        }
    }

    // Print final results
    printf("\nShortest paths from building %d:\n", start + 1);
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (i != start && shortestDistance[i] != 999999) {
            printf("To building %d: Distance = %d, Path = ", i + 1, shortestDistance[i]);
            int current = i;
            while (current != -1) {
                printf("%d ", current + 1); // Adjust index for output
                current = parent[current];
            }
            printf("\n");
        }
    }
}

// Prim's Algorithm

void prim(int distances[TABLE_SIZE][TABLE_SIZE], int start) {
    int parent[TABLE_SIZE];
    int key[TABLE_SIZE];
    int mstSet[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[start] = 0;
    parent[start] = -1;

    for (int count = 0; count < TABLE_SIZE - 1; count++) {
        int u = -1;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!mstSet[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mstSet[u] = 1;

        for (int v = 0; v < TABLE_SIZE; v++) {
            if (distances[u][v] != -1 && !mstSet[v] && distances[u][v] < key[v]) {
                parent[v] = u;
                key[v] = distances[u][v];
            }
        }
    }

    int co777 = 0;

    // Print the MST edges
    printf("\nMinimum Spanning Tree (Prim's algorithm):\n");
    for (int i = 1; i < TABLE_SIZE; i++) {
        if (distances[i][parent[i]] != 999999) {
            co777++;
            printf("Edge: %d - %d, Weight: %d\n", parent[i] + 1, i + 1, distances[i][parent[i]]);
        }
    }

    printf("\n\nThe number of vertex : %d\n", co777);
}


void insertionSort(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        Node* sortedList = NULL;

        while (current != NULL) {
            Node* next = current->next;

            if (sortedList == NULL || strcmp(current->data, sortedList->data) < 0) {
                // Insert at the beginning of the sorted list
                current->next = sortedList;
                sortedList = current;
            } else {
                // Find the correct position to insert in the sorted list
                Node* temp = sortedList;
                while (temp->next != NULL && strcmp(current->data, temp->next->data) > 0) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        table[i].head = sortedList;
    }
}
void displayInsertionSort(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        Node* sortedList = NULL;

        printf("Original list at index %d: ", i);
        while (current != NULL) {
            printf("%s ", current->data);
            current = current->next;
        }
        printf("\n");

        current = table[i].head;

        while (current != NULL) {
            Node* next = current->next;

            if (sortedList == NULL || strcmp(current->data, sortedList->data) < 0) {
                // Insert at the beginning of the sorted list
                current->next = sortedList;
                sortedList = current;
            } else {
                // Find the correct position to insert in the sorted list
                Node* temp = sortedList;
                while (temp->next != NULL && strcmp(current->data, temp->next->data) > 0) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            // Display the current state of the sorted list
            printf("Sorted list at index %d: ", i);
            Node* displayNode = sortedList;
            while (displayNode != NULL) {
                printf("%s ", displayNode->data);
                displayNode = displayNode->next;
            }
            printf("\n");

            current = next;
        }

        table[i].head = sortedList;
    }
}


// ... (Previous code remains unchanged)

int main() {
    // Hash Table Initialization
    HashTable hashTable[TABLE_SIZE] = {0};

    // Graph Initialization
    int distances[TABLE_SIZE][TABLE_SIZE];
    int index, jndex;
    for (index = 0; index < TABLE_SIZE; index++) {
        for (jndex = 0; jndex < TABLE_SIZE; jndex++)
            distances[index][jndex] = 999999;
    }

    // File Paths


    char buildingFilePath[] = "C:\\Users\\anart\\OneDrive\\Desktop\\BUILDINGS.txt";
    char distancesFilePath[] = "C:\\Users\\anart\\OneDrive\\Desktop\\test.txt";

    // Read Data into Hash Table

    displayDataFromFile(buildingFilePath, hashTable);

    // Read Distances into Graph

    readDistancesFromFile(distancesFilePath, distances);

   int choice;

    do {
        printf("____________________________________________\n");
        printf("|                                          |\n");
        printf("| Choose an option:                        |\n");
        printf("| 1. Display contents of the hash table    |\n");
        printf("| 2. Search in the hash table              |\n");
        printf("| 3. Display distances matrix              |\n");
        printf("| 4. Run Dijkstra's algorithm              |\n");
        printf("| 5. Run Prim's algorithm                  |\n");
        printf("| 6. Delete data from hash table           |\n");
        printf("| 7. Insert data into hash table           |\n");
        printf("| 8. Sort hash table using Insertion Sort  |\n");
        printf("| 9. Exit                                  |\n");
        printf("|__________________________________________|\n");
        printf("|Enter your choice:                        |\n");

        // Move the cursor to the "Enter your choice" box

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayHashTable(hashTable);
                break;
            case 2: {
                char searchBID[MAX_LINE_LENGTH];
                printf("Enter the BID to search: ");
                getchar();
                fgets(searchBID, sizeof(searchBID), stdin);
                searchBID[strcspn(searchBID, "\n")] = '\0';
                Node* result = searchHashTableByBID(hashTable, searchBID);
                if (result != NULL) {
                    printf("BID found in hash table: %s\n", result->data);
                } else {
                    printf("BID not found in hash table.\n");
                }
            }
            break;
            case 3:
                displayDataFromFile(distancesFilePath, hashTable);
                break;
            case 4: {
                int startBuilding;
                printf("Enter the starting building for Dijkstra's algorithm: ");
                scanf("%d", &startBuilding);
                // Adjust the index for the array
                startBuilding -= 1;
                dijkstra(distances, startBuilding);
            }
            break;
            case 5: {
                int startBuilding;
                printf("Enter the starting building for Prim's algorithm: ");
                scanf("%d", &startBuilding);
                // Adjust the index for the array
                startBuilding -= 1;
                prim(distances, startBuilding);
            }
            break;
            case 6: {
                char dataToDelete[MAX_LINE_LENGTH];
                printf("Enter the data to delete: ");
                getchar();
                fgets(dataToDelete, sizeof(dataToDelete), stdin);
                dataToDelete[strcspn(dataToDelete, "\n")] = '\0';
                deleteFromHashTable(hashTable, dataToDelete);
            }
            break;
            case 7: {
                char dataToInsert[MAX_LINE_LENGTH];
                printf("Enter the data to insert: ");
                getchar();
                fgets(dataToInsert, sizeof(dataToInsert), stdin);
                dataToInsert[strcspn(dataToInsert, "\n")] = '\0';
                insertIntoHashTable(hashTable, dataToInsert);
            }
            break;
            case 8:
                insertionSort(hashTable);
                printf("Hash table sorted using Insertion Sort.\n");

                break;
            case 9:
                printf("Press 9 to exit\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 9);

    // Free allocated memory for nodes in the hash table

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i].head;
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}
