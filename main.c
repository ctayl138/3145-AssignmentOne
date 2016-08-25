#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nums
{
  int num;
  struct nums *next;
};
typedef struct nums node;

void   insert(node*, int); //prototype of function that adds a node to the list
void   delete(node*); //prototype of function that traverses the singly-linked list and removes each node as it traverses
void   print(node*);

int main()
{
   node *start; //declaring node structure pointers
   start = (node *) malloc(sizeof(node)); // allocating memory for first node
   srand(time(NULL));
   int r;

   for(int n = 1; n < 20; n++){
        insert(start, r = rand() % 20);
   }

   print(start);
   delete(start);

   return 0;
}

void insert(node *ptr, int num){
  while(ptr->next!=NULL)
  {
    ptr = ptr -> next;
  }
  ptr-> next = (node *) malloc(sizeof(node));
  ptr = ptr-> next;
  ptr-> num = num;
  ptr-> next = NULL;
}

void delete(node *ptr){
  node *next, *cur;
  cur = ptr;
   while (cur) {
    next = cur-> next;
    free(cur);
    cur = next;
   }
  ptr = NULL;
}
void print(node* head) {
    node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->num);
        cur = cur->next;
    }
}

