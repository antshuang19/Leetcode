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
    
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        vector<int> array;
        int count =0;
        while(head != NULL)
        {
            array.push_back(head->val);
            head = head->next;
            count++;
        }
        vector<int> reversed{{array}};
        reverse(begin(reversed),end(reversed));
        for(int i =0; i < count;i++)
        {
            if(reversed[i] != array[i])
                return false;
        }
        return true;
    }
};