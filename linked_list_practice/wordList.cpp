/*
The purpose of this program is to create 3 different
linked lists of words.  One will be created by adding nodes
to the front.  Another will be created by adding nodes at the end.
Another will be created by inserting nodes in alphabetical order.

The class will be a doubly-linked list of nodes whose only
value is a string (word).
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Node {
  string data;
  Node *prev;
  Node *next;

  Node(string d, Node *p = NULL, Node *n = NULL) {
    data = d;
    prev = p;
    next = n;
  }
};

class WordList {
private:
  Node *head;
  Node *tail;
  int listSize;

public:
  // Constructor
  WordList() {
    head = NULL;
    tail = NULL;
    listSize = 0;
  }

  // Insert a word at the front of the list
  void insertAtFront(string word) {
    Node *temp = new Node(word, NULL, head);

    if (head == NULL) {
      tail = temp; // If list is empty, new node is also the tail
    } else {
      head->prev = temp;
    }

    head = temp;

    listSize++;
  }

  // Insert a word at the end of the list
  void insertAtEnd(string word) {
    Node *temp = new Node(word, tail, NULL);

    if (tail == NULL) {
      head = temp;
    } else {
      tail->next = temp;
    }

    tail = temp;

    listSize++;
  }

  // Insert a word in alphabetical order
  void insertInOrder(string word) {
    Node *temp = new Node(word);

    if (head == NULL || word < head->data) {
      insertAtFront(word);
    } else {
      Node *traverse = head;

      while (traverse->next != NULL && traverse->next->data < word) {
        traverse = traverse->next;
      }

      temp->next = traverse->next;
      temp->prev = traverse;

      if (traverse->next != NULL) {
        traverse->next->prev = temp;
      }

      traverse->next = temp;

      if (temp->next == NULL) {
        tail = temp;
      }

      listSize++;
    }
  }

  // Remove a word from the list
  void remove(string word) {
    Node *traverse = head;

    while (traverse != NULL && traverse->data != word) {
      traverse = traverse->next;
    }

    if (traverse == NULL) {
      return; // Word not found
    }

    if (traverse->prev != NULL) {
      traverse->prev->next = traverse->next;
    } else {
      head = traverse->next;
    }

    if (traverse->next != NULL) {
      traverse->next->prev = traverse->prev;
    } else {
      tail = traverse->prev;
    }

    delete traverse;
    listSize--;
  }

  // Display the list
  void displayList(ofstream &outfile) {
    Node *traverse = head;
    while (traverse != NULL) {
      outfile << traverse->data << " ";
      traverse = traverse->next;
    }
    outfile << endl;
  }

  // Display the list in reverse order
  void displayListReversed(ofstream &outfile) {
    Node *traverse = tail;

    while (traverse != NULL) {
      outfile << traverse->data << " ";
      traverse = traverse->prev;
    }
    outfile << endl;
  }

  // Return the size of the list
  int size() { return listSize; }

  // Destructor
  ~WordList() {
    while (head) {
      Node *temp = head->next;
      delete head;
      head = temp;
    }
  }
};

int main() {
  ifstream infile;
  ofstream outfile;
  string word;
  infile.open("words.dat");

  // Use your last name here
  outfile.open("Bhatta_List.txt");
  WordList listA, listB, listC;

  if (infile && outfile) {
    outfile << "Serwes Bhatta\n";
    outfile << "Linked Lists Program\n\n";

    // Read until sentinel of STOP_READING is found
    // Use insert at Front
    while (infile >> word && word != "STOP_READING") {
      listA.insertAtFront(word);
    }

    outfile << "List built with insertAtFront:\n";
    listA.displayList(outfile);

    // Remove words from list until
    // STOP_REMOVING is found
    while (infile >> word && word != "STOP_REMOVING") {
      listA.remove(word);
    }

    outfile << "After removing:\n";
    listA.displayList(outfile);

    outfile << "Size: " << listA.size() << endl;

    outfile << "Reversed:\n";
    listA.displayListReversed(outfile);
    outfile << endl;

    // Test insert at End
    // Read until sentinel of STOP_READING is found
    while (infile >> word && word != "STOP_READING") {
      listB.insertAtEnd(word);
    }

    outfile << "List build with insertAtEnd:\n";
    listB.displayList(outfile);

    // Remove words from list until
    // STOP_REMOVING is found
    while (infile >> word && word != "STOP_REMOVING") {
      listB.remove(word);
    }

    outfile << "After removing:\n";
    listB.displayList(outfile);

    outfile << "Size: " << listB.size() << endl;

    outfile << "Reversed: \n";
    listB.displayListReversed(outfile);
    outfile << endl;

    // Test Insert in Order
    // Read until sentinel of "STOP_READING" is found
    // Use insertInOrder
    while (infile >> word && word != "STOP_READING") {
      listC.insertInOrder(word);
    }

    outfile << "List built with insertInOrder:\n";
    listC.displayList(outfile);

    // Remove words from list until
    // STOP_REMOVING is found
    while (infile >> word && word != "STOP_REMOVING") {
      listC.remove(word);
    }

    outfile << "After removing:\n";
    listC.displayList(outfile);

    outfile << "Size: " << listC.size() << endl;

    outfile << "Reversed:\n";
    listC.displayListReversed(outfile);
    outfile << endl;

    // Close files
    outfile.close();
    infile.close();
  }

  else
    cout << "Couldn't open one or more files.\n";

  return 0;
}