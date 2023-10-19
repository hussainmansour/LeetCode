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
    bool hasCycle(ListNode *head) {
       int count =0;
       while(head!=NULL){
           if(count == 1e5)break;
           count++;
           head = head->next;
       }
       if(head == NULL)
            return false;
        return true; 
    }
};
