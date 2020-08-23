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
    ListNode* reverse(ListNode *p)
    {
        ListNode * prev = NULL;
        ListNode * curr = p;
        ListNode * next;
        
        while(curr)
        {
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }
        return prev;
    }
    void merge(ListNode *l1,ListNode *l2)
    {
        
       
        while(l1 != NULL)
        {
            ListNode *l1_nxt = l1->next;
            ListNode *l2_nxt = l2->next;
            
            l1->next = l2;
            if(l1_nxt == NULL) break;
            
            l2->next = l1_nxt;
            l1 = l1_nxt;
            l2 = l2_nxt;
        }
        
       

    }
    void reorderList(ListNode* head) {
        if( head == NULL || head->next == NULL) return;
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * root = head;
        ListNode * prev ; 
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
       prev->next = NULL;
       slow = reverse(slow);
        
//         while(slow)
//         {
//             cout<<slow->val<<endl;
//             slow = slow->next;
//         }
        merge(root,slow);
        
    }
    
};
