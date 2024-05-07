struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  ListNode *temp;
  ListNode *traverse;

public:
  ListNode *deleteDuplicates(ListNode *head) {
    traverse = head;

    if (head == nullptr) {
      return head;
    }

    while (traverse != nullptr && traverse->next != nullptr) {
      while (traverse->next != nullptr &&
             traverse->val == traverse->next->val) {
        temp = traverse->next;
        if (traverse->next->next != nullptr) {
          traverse->next = traverse->next->next;
          delete temp;
        } else {
          traverse->next = nullptr;
          delete temp;
          return head;
        }
      }
      traverse = traverse->next;
    }

    return head;
  }
};