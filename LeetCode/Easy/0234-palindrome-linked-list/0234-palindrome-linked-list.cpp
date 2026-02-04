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

    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = mid(head);
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        while(prev != nullptr && head != nullptr){
            if(head->val != prev->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};