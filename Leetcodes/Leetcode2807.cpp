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
    int gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while (ptr->next)
        {
            int value = gcd(ptr->val, ptr->next->val);
            ListNode* temp = new ListNode(value);
            temp->next = ptr->next;
            ptr->next=temp;
            ptr= temp->next;
        }
        return head;
    }
};