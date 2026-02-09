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
    ListNode* merge(ListNode* head, ListNode* head2){
        ListNode temp(-1);
        ListNode* dummy = &temp;

        while(head && head2){
            if(head->val > head2->val){
                dummy->next = head2;
                head2 = head2->next;
            }
            else{
                dummy->next = head;
                head = head->next;
            }
            dummy = dummy->next;
        }

        if(head) dummy->next = head;
        if(head2) dummy->next = head2;

        return temp.next;
    }

    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow -> next = nullptr;

        head = mergeSort(head);
        head2 = mergeSort(head2);

        return merge(head, head2);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};