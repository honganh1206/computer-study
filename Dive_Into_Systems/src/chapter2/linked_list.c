#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;          // Store the value
  struct node *next; // Point to the next node
};

int main() {
  struct node *head, *temp;
  int i;

  head = NULL;

  head = malloc(sizeof(struct node));
  if (head == NULL) {
    printf("Error malloc\n");
    exit(1);
  }

  head->data = 10;
  head->next = NULL; // No next element at the moment
  printf("%d\n", head->data);
  // Add 2 more nodes
  for (i = 0; i < 2; i++) {
    temp = malloc(sizeof(struct node));
    if (temp == NULL) {
      printf("Error malloc\n");
      exit(1);
    }
    temp->data = i;
    temp->next = head; // Set next to point to the current first node
    head = temp; // Change head to point to newly added node so the next node
                 // can point to
    printf("%d\n", temp->data);
    // Do NOT free temp here
    // If we do so, we will be adding a new node pointing to already freed
    // memory
  }

  // Free the entire list from the 1st node to the last
  // When the last node's value is NULL, we break out from the loop
  while (head != NULL) {
    temp = head;       // Save the current head
    head = head->next; // Move head to the next node
    free(temp);
  }

  return 0;
}
