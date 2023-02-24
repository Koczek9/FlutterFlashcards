
//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order, and each of their nodes contains a single digit.
//Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result = nullptr;
        ListNode* last = nullptr;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry)
        {
            int sum = carry;

            if(l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;

            if (!result)
            {
                result = temp;
                last = temp;
            }
            else
            {
                last->next = temp;
                last = last->next;
            }
        }

        return result;
    }
};