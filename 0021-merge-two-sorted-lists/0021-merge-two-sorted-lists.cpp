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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to use as the start of the merged list
        ListNode dummy;
        ListNode* tail = &dummy;

        // While both lists are not empty, compare the current nodes of both lists
        while (list1 != nullptr && list2 != nullptr) 
        {
            if (list1->val < list2->val) 
            {
                tail->next = list1; // append list1 node to the merged list
                list1 = list1->next; // move to the next node in list1
            }
            else
            {
                tail->next = list2; // append list2 node to the merged list
                list2 = list2->next; // move to the next node in list2
            }
            tail = tail->next; // Move the tail
        }

        // if one of the lists is not empty, append the remaining elements
        if (list1 != nullptr)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        return dummy.next; // the merged list is next to the dummy node
    }
};