#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* result = new ListNode();
    ListNode* head = result;

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        while(list1 != nullptr && list2 !=nullptr) {
            if (list1->val <= list2->val) {
                result->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                result->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            result = result->next;
        }

        while(list1 != nullptr) {
            result->next = new ListNode(list1->val);
            list1 = list1->next;
            result = result->next;
        }

        while(list2 != nullptr) {
            result->next = new ListNode(list2->val);
            list2 = list2->next;
            result = result->next;
        }

        return head->next;
    }
};