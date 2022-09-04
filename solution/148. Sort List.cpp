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
    ListNode * merge(ListNode * a, ListNode *b)
    {
        if(a == NULL) return b;
        if(b == NULL) return a;
        ListNode * result =NULL;
        if(a->val <= b->val)
        {
            result = a;
            result->next = merge(a->next,b);
        }
        else 
        {
            result = b;
            result->next =  merge(a,b->next);
        }
        return result;
    }
    void fronBacksplit(ListNode *head,ListNode **a,ListNode ** b)
    {
        if(head == NULL or head->next == NULL)
        {
            *a = head;
            *b = NULL;
            return;
        }
        ListNode * fast=head->next, *slow=head;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast!= NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }
    void mergesort(ListNode ** head)
    {
        if(*head == NULL or (*head)->next == NULL)
        {
            return;
        }
        ListNode *a , *b;
        fronBacksplit(*head,&a,&b);
        mergesort(&a);
        mergesort(&b);
        *head = merge(a,b);
    }
    ListNode* sortList(ListNode* head) 
    {
        mergesort(&head);
        return head;
    }
};