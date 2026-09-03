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
    ListNode* reverseList(ListNode* head,int k){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int count = 0;

        while(temp != nullptr && count < k){
            ListNode* nextNode = temp->next;
            temp -> next = prev;
            prev = temp;
            temp = nextNode;
            count++;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr && count < k){
            temp = temp->next;
            count++;
        }
        if(count < k) return head;
        ListNode* newHead = reverseList(head,k);
        head->next = reverseKGroup(temp,k);
        return newHead;
    }
};

