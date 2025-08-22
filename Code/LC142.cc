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
    // 假设 sl 走了 x + a = n 的距离，那么fs就走了 x + b = 2n 的距离
    // sl 进入圈后必定在第一圈时和 fs 相遇， 因为在圈中只有走了圈长的整数倍才能追赶到另一个节点
    // 因此 b - a = 2n - n = n 的长度一定是圈长的整数倍 kL
    // 让sl重新到起点，两者以同样的速度再走一遍，此时fs 距离起点位置 算是 x + a = n = kL
    // 再走 x 的距离 sl 走了 x ，而fs则走了 x + kL的距离，因为距离相差kL，
    // 所以当sl一进圈，它们就相遇了

    ListNode *detectCycle(ListNode *head) 
    {
        if(!head) return nullptr;
        int n = 0;
        ListNode* sl = head, *fs = head;
        do
        {
            sl = sl->next;
            fs = fs->next;
            if(!fs) break;
            fs = fs->next;
            ++n;
        }while(fs && sl != fs);
        if(!fs) return nullptr;

        sl = head;
        while(sl != fs)
        {
            sl = sl->next;
            fs = fs->next;
        }
        return sl;
    }
};