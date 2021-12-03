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
        if(head == NULL || (head->next == NULL && n==1)) return NULL;
        int numOfNodes = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            temp = temp->next;
            numOfNodes++;
        }
        ListNode *back = NULL;
        ListNode *front = head;
        n = numOfNodes - n + 1;
        if(n==1 && head->next!=NULL){
            head = head->next;
            return head;
        }
        n--;
        while(n >0){
            back = front;
            front = front->next;
            n--;
        }
        if(front->next == NULL) back->next = NULL;
        else back->next = front->next;
        
        return head;
        
    }
};
