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
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            list.push_back(temp);
            temp = temp->next;
        }
        int i=0,j=list.size()-1;
        while(i<j){
            list[i]->next = list[j];
            i++;
            if(i==j)
            {    
                break;
            }
            list[j]->next = list[i];
            j--;
        }
        list[j]->next = nullptr;
    }
};
