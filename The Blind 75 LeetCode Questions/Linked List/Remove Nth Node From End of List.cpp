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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> temp;
        ListNode* t = head;
        while(t != nullptr){
            temp.push_back(t);
            t = t->next;
        }
        if(n==temp.size()){
            return head->next;
        }
        else{
            t = temp[temp.size()-n-1];
            t->next = (t->next)->next;
        }
        return head;
    }
};
