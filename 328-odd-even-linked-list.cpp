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
    ListNode* oddEvenList(ListNode* head) {  
        if (head == nullptr) {  
            return head;  
        }  
        ListNode* pOdd  = head->next;  
        if (pOdd == nullptr) {  
            return head;  
        }  
        pOdd = pOdd->next;  
        ListNode* pGroupCurr = head;  
        ListNode* pEven = head->next;  
        while (pOdd != nullptr) {  
            pEven->next = pOdd->next;  
            pOdd->next = pGroupCurr->next;  
            pGroupCurr->next = pOdd;  
            pOdd = pEven->next;  
            if (pOdd == nullptr) {  
                break;  
            }  
            pOdd = pOdd->next;  
            pGroupCurr = pGroupCurr->next;  
            pEven = pEven->next;  
        }  
        return head;  
    }  
};  