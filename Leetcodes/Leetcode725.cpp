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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Intution
        // The idea in here is really very simple. First we will store the len of the linked list in a temp variable for verifing the conditions. Then, we will check if the length of the list is divisible by k or not. If it is divisble then we need to change the start and the current pointers to the null values and then add the node to the vector. Finally, return to the result.

        int size = 0;

        ListNode *temp = head;

        while(temp){
            size += 1;
            temp = temp->next;
        }


        int number = size / k;
        int remain = size % k;

        ListNode *prev  = NULL;
        ListNode *start = head;

        ListNode *curr  = head;

        int currN = 0;

        vector<ListNode *> answer;

        if(k > size){
            ListNode *currT = head;
            ListNode *prev  = NULL;
            while(k > 0){
                prev  = currT;
                if(currT) currT = currT->next;
                if(prev) prev->next = NULL;
                answer.push_back(prev);
                k--;
            }
            return answer;
        }

        for(int i = 0 ; i < size ; i++){

            prev = curr;
            curr = curr->next;
            currN += 1;

            int alpha = 0;

            if(remain > 0){
                alpha = number + 1;
            }

            else alpha = number;


            if(currN == alpha){
                answer.push_back(start);
                if(prev) prev->next = NULL;
                start = curr;
                if(remain > 0) remain -= 1;
                currN = 0;
            }

        }

        return answer;
        

    }
};