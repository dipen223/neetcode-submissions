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
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* nextNode = temp->next;

            temp->next = prev;
            prev = temp;
            temp = nextNode;

        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //find the mid
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        second = reverseList(second);


        ListNode* list1 = head;
        ListNode* list2 = second;

        while(list1 != NULL && list2 != NULL){
            ListNode* l1Next = list1->next; 
            ListNode* l2Next = list2->next; 

            list1->next = list2;

            if(l1Next != nullptr){
                list2->next = l1Next;
            }

            list1 = l1Next;
            list2 = l2Next;
            
        }
    }
};
