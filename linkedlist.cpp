#include <iostream>
using namespace std;

class IntNode {
   public:
      IntNode(int value) {
         numVal = value;
      }

      ~IntNode() {
         cout << numVal << endl;
      }

      int numVal;
      IntNode* next;
};

class IntLinkedList {
   public:
      IntLinkedList();
      ~IntLinkedList();
      void Prepend(int);

      IntNode* head;
};

IntLinkedList::IntLinkedList() {
   head = nullptr;
}

IntLinkedList::~IntLinkedList() {
   while (head) {
      IntNode* next = head->next;
      delete head;
      head = next;
   }
   cout << "end of list" << endl;
}

void IntLinkedList::Prepend(int dataValue) {
   IntNode* newNode = new IntNode(dataValue);
   newNode->next = head;
   head = newNode;
}

int main() {
   IntLinkedList* list = new IntLinkedList();

   list->Prepend(2);
   list->Prepend(3);
   list->Prepend(6);
   list->Prepend(7);

   delete list;

   return 0;
}