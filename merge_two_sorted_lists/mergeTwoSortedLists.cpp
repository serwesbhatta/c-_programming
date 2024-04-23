#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int data = 0, ListNode *n = NULL) {
    val = data;
    next = n;
  }
};

class Solution {
private:
  ListNode *head = nullptr;

public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr && list2 == nullptr) {
      return nullptr;
    }

    if (list1 == nullptr) {
      return list2;
    }

    if (list2 == nullptr) {
      return list1;
    }

    ListNode * traverse = new ListNode();
    head = traverse;

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        traverse->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        traverse->next = new ListNode(list2->val);
        list2 = list2->next;
      }
      traverse = traverse->next;
    }

    while (list1 != nullptr) {
      traverse->next = new ListNode(list1->val);
      list1 = list1->next;
      traverse = traverse->next;
    }

    while (list2 != nullptr) {
      traverse->next = new ListNode(list2->val);
      list2 = list2->next;
      traverse = traverse->next;
    }

    return head->next;
  }

  void insertAtFront(int data) {
    ListNode *temp = new ListNode(data, head);

    if (!head) {
      head = temp;
    }
    else {
      temp->next = head;
      head = temp;
    }
  }

  void insertInOrder(int data) {
    ListNode *temp = new ListNode(data);

    if (head == nullptr || data < head->val) {
      insertAtFront(data);
    } else {
      ListNode *traverse = head;

      while (traverse->next != nullptr && traverse->next->val < data) {
        traverse = traverse->next;
      }

      temp->next = traverse->next;
      traverse->next = temp;
    }
  }

  void printList() {
    ListNode * traverse = head;

    while (traverse) {
      cout << traverse->val << "\t";
      traverse = traverse->next;
    }
    cout << endl;
  }

  void printList(ListNode *list) {
    ListNode * traverse = list;

    while (traverse) {
      cout << traverse->val << "\t";
      traverse = traverse->next;
    }
    cout << endl;
  }

  ListNode *list() { return head; }
};

int main() {
  Solution list1, list2, solution;

  list1.insertInOrder(1);
  list1.insertInOrder(2);
  list1.insertInOrder(4);

  list2.insertInOrder(1);
  list2.insertInOrder(3);
  list2.insertInOrder(4);

  list1.printList();
  list2.printList();

  ListNode *list3 = solution.mergeTwoLists(list1.list(), list2.list());

  solution.printList(list3);

  return 0;
}