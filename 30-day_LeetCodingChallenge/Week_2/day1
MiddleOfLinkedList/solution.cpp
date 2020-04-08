/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* headPtr = head;
        ListNode * ans = head;
        while(headPtr!=NULL)
        {
            headPtr = headPtr->next;
            n++;
        }
        n/=2;
        while(n--)
        {
            ans = ans->next;
        }
        return ans;
        
    }
};