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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(!list1) return list2;
        if(!list2) return list1;
        if(!list1 and !list2) return NULL;
        int val ;
        ListNode * head = new ListNode,*temp=NULL;
        if(list1->val <= list2->val)
        {
            val = list1->val;
            list1 =list1->next;
        }
        else 
        {
            val = list2->val;
            list2=list2->next;
        }
        head ->val = val;
        head->next = NULL;
        temp =head;
        while(true)
        {
            if(list1 == NULL and list2==NULL) break;
            ListNode * newNode = new ListNode;
            if(list1 == NULL) 
            {
                newNode->val =list2->val;
                newNode->next = NULL;
                list2=list2->next;
            }
            else if(list2 == NULL) 
            {
                newNode->val =list1->val;
                newNode->next = NULL;
                list1=list1->next;
            }
            else if(list1->val <= list2->val)
            {
                newNode->val =list1->val;
                newNode->next = NULL;
                list1=list1->next;
            }
            else
            {
                newNode->val =list2->val;
                newNode->next = NULL;
                list2=list2->next;
            }
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
};