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

// 归并排序

class Solution {
public:
    ListNode* mergesort(ListNode* head)
    {
        ListNode* a = head, *b = head;

        ListNode* ptr = nullptr;    // a 的前继节点
        while(a && b)
        {
            ptr = a;
            a = a->next;
            b = b->next;
            if(!b) break;   
            b = b->next;
        }

        if (a == b) return head;    // 只有一个节点了

        // 将链表分成两份链表
        ptr->next = nullptr;
        auto L = mergesort(head);
        auto R = mergesort(a);

        // 到这里说明上述的两份链表各自内部已经有序了，现在就是合并有序链表
        ListNode* H = new ListNode();
        ptr = H;
        while(L && R)
        {
            if(L->val <= R->val)
            {
                ptr->next = L, ptr = L, L = L->next;
            }
            else
            {
                ptr->next = R, ptr = R, R = R->next;
            }
        }
        while(L)
            ptr->next = L, ptr = L, L = L->next;
        while(R)
            ptr->next = R, ptr = R, R = R->next;

        // 合并完成后返回它们的头节点
        return H->next;
    }

    ListNode* sortList(ListNode* head) 
    {
        return mergesort(head);    
    }
};