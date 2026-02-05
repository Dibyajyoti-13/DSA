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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* intersection = NULL;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ intersection = slow; break;}
        }
        
        slow = head;

        while(slow && intersection){
            if(slow == intersection) return slow;
            slow = slow->next;
            intersection = intersection->next;
        }
        
        return NULL;
    }
};