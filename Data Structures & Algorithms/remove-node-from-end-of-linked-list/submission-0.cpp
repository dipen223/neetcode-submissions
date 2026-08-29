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
        ListNode dummy(0, head);
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp->next;
            size+=1;
        }
        ListNode* temp2 = &dummy;
        for(int i=0; i<size-n;i++){
            temp2 = temp2->next;
        }
        ListNode* tobeRemoved = temp2->next;
        temp2->next = tobeRemoved->next;
        delete tobeRemoved;
        return dummy.next;

        
    }
};


