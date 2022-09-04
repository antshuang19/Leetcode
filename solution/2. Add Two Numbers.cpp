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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1 || !l2)
        {
            if(l1)
            {
                return l1;
            }
            else
            {
                return l2;
            }
        }
        else
        {
            ListNode * result = new ListNode , *temp = NULL;
            int carry = l1->val + l2->val;
            l1= l1->next;
            l2= l2->next;
            result->val = carry% 10;
            carry/=10;
            result->next = NULL;
            temp = result;
            while(1)
            {
                if(!l1 && !l2)
                {
                    if(carry != 0)
                    {
                        ListNode * newNode = new ListNode;
                        newNode ->val = carry;
                        newNode->next = NULL;
                        temp->next = newNode;
                        temp = temp->next;
                    }
                    break;
                }
                else if(l1 && l2)
                {
                    carry = carry+l1->val + l2->val;
                    ListNode * newNode = new ListNode;
                    newNode ->val = carry % 10;
                    newNode->next = NULL;
                    l1= l1->next;l2= l2->next;
                    carry /=10;
                    temp->next = newNode;
                    temp = temp->next;
                }
                else 
                {
                    if(l1)
                    {
                        carry = carry+l1->val;
                        ListNode * newNode = new ListNode;
                        newNode ->val = carry % 10;
                        newNode->next = NULL;
                        l1= l1->next;
                        carry /=10;
                        temp->next = newNode;
                        temp = temp->next;
                    }
                    else
                    {
                       carry = carry+l2->val;
                        ListNode * newNode = new ListNode;
                        newNode ->val = carry % 10;
                        newNode->next = NULL;
                        l2= l2->next;
                        carry /=10;
                        temp->next = newNode;
                        temp = temp->next; 
                    }
                }
            }
            return result;
        }
    }
};