//Given the head of a sorted linked list, delete all duplicates 
//such that each element appears only once. Return the linked list sorted as well.

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* lastPtr = head;

        while(lastPtr != nullptr && lastPtr->next != nullptr)
        {
            ListNode* nextPtr = lastPtr->next;
            if(nextPtr->val == lastPtr->val)
            {
                lastPtr->next = lastPtr->next->next;
                //free(nextPtr);
            }
            else
            {
                lastPtr = lastPtr->next;
            }
        }
        return head;
    }
};