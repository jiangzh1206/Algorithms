#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 给链表加个头指针
        auto new_head = new ListNode;
        new_head->next = head;
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }

        auto h = new_head;
        for (int i = 0; i < len - n; ++i) {
            h = h->next;
        }

        auto temp = h->next;
        h->next = temp->next;
        delete temp;
        auto res = new_head->next;
        delete new_head;
        return res;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* data = new ListNode(2);
    ListNode* data1 = new ListNode(3);

    head->next = data;
    data->next = data1;

    Solution sln;
    auto res_head = sln.removeNthFromEnd(head, 2);

    while(res_head){
        cout << res_head->val << ",";
        res_head = res_head->next;
    }
    
}