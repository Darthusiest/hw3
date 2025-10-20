#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if (head == nullptr){
    smaller = nullptr; 
    larger = nullptr;
    return;
    }
  
  Node* temp = head;
  Node* nxt_val = head->next;

  llpivot(nxt_val, smaller, larger, pivot);

  temp->next = nullptr;

  if (temp->val <= pivot){
    temp->next = smaller; // <--
    smaller = temp; // <--
  }else{
    temp->next = larger;
    larger = temp;
  }

  head = nullptr;
}

