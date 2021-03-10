#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    // 21. Merge Two List
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;    
        }
    }

    // 23. Merge k Sorted Lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        // 分治
        if (l == r) {
            return lists[l];
        }
        int mid = (l + r) / 2;
        auto l1 = merge(lists, l, mid);
        auto l2 = merge(lists, mid+1, r);

        return mergeTwoLists(l1, l2);
    }

    ListNode* use_priority_queue(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* left, ListNode* right) { 
            return left->val > right ->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp) > q(cmp);
        for(auto l : lists) {
            q.push(l);
        }
        ListNode* dummy = new ListNode;
        auto p = dummy;
        while (!q.empty()) {
            // 取最小值加入链表
            auto node = q.top();
            q.pop();
            p->next = node;
            p = node;

            // 将node下个节点加入队列
            if (node->next) {
                q.push(node->next);
            }
        }
        return dummy->next;
    }

    // 24. Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto p = head;
        auto q = head->next;
        p->next = q->next;
        q->next = p;
    
        p->next = swapPairs(head->next);

        return q;
    }

    // 链表倒置
    ListNode* reverse_list(ListNode* head) {
        ListNode* p = nullptr;
        while (head){
            auto next = head->next;
            head->next = p;
            p = head;
            head = next;
        }
        return p;
    }

    bool valide (ListNode* head, int k) {
        int n = 0;
        while(head){
            if (++n == k) return true;
            head = head->next;
        }
        return false;
    }

    // 25. Reverse Nodes in k-Group
    // 非递归k个分组分别倒置
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 终止条件:长度是否合法
        if (!valide(head, k)) {
            return head;
        }
        // 取k个组成链表
        ListNode node;
        auto p = &node;
        for (int i = 0; i < k; ++i) {
            p->next = head;
            p = head;
            head = head->next;
        }
        p->next = nullptr;
        auto ret = reverse_list(node.next);
        // 旋转k个后head变成tail,递归调用剩下的
        node.next->next = reverseKGroup(head, k);

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    auto ret = sln.reverseKGroup(p1, 2);

    return 0;
}
