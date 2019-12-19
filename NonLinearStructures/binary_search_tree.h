#pragma once
#include <iostream>
#include <queue>

struct BSTNode
{
    int Data;
    BSTNode* Left;
    BSTNode* Right;
};

struct BST
{
    using Node = BSTNode;

    Node* root = nullptr;

    Node* find(int val)
    {
        return find_impl(root, val);
    }

    void insert(int val)
    {
        if (!root) {
            root = new Node{val, nullptr, nullptr};
        } else {
            insert_impl(root, val);
        }
    }
    void delete_value(int val)
    {
        root = delete_impl(root, val);
    }
    // 后继者
    Node* successor(Node* start)
    {
        auto node = start->Right;
        while (node && node->Left) {
            node = node->Left;
        }
        return node;
    }

    void in_order()
    {
        in_order_impl(root);
    }
    void level_order()
    {
        level_order_impl(root);
    }
private:
    Node* find_impl(Node* start, int val)
    {
        if (!start) {
            return nullptr;
        }
        if (val == start->Data) {
            return start;
        }
        if (val > start->Data) {
            return find_impl(start->Right, val);
        } else {
            return find_impl(start->Left, val);
        }
    }

    void insert_impl(Node* start, int val)
    {
        if (!start) {
            return;
        }
        if (val < start->Data) {
            if (!start->Left) {
                start->Left = new Node{val, nullptr, nullptr};
            } else {
                insert_impl(start->Left, val);
            }
        }
        if (val > start->Data) {
            if (!start->Right) {
                start->Right = new Node{val, nullptr, nullptr};
            } else {
                insert_impl(start->Right, val);
            }
        }
    }

    Node* delete_impl(Node* start, int val)
    {
        if (!start) {
            return nullptr;
        }

        if (val < start->Data) {
            start->Left = delete_impl(start->Left, val);
        } else if (val > start->Data) {
            start->Right = delete_impl(start->Right, val);
        } else {
            if (!start->Left) {
                // 无子节点，无左节点
                auto tmp = start->Right;
                delete start;
                // 子节点直接替换父节点
                return tmp;
            }
            if (!start->Right) {
                // 无右节点
                auto tmp = start->Left;
                delete start;
                return tmp;
            }

            // 存在左右节点
            auto succ = successor(start);
            start->Data = succ->Data;  // 替换
            start->Right = delete_impl(start->Right, succ->Data);  // 删除后继者，一定是右子树上的
        }

        return start;
    }

    void in_order_impl(Node* start)
    {
        if (!start) {
            return;
        }
        in_order_impl(start->Left);
        std::cout << start->Data << " ";
        in_order_impl(start->Right);
    }

    void level_order_impl(Node* start)
    {
        if (!start) {
            return;
        }
        std::queue<BSTNode*> q;
        q.push(start);
        while (!q.empty()) {
            int size = q.size();
            for (size_t i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                std::cout << node->Data << "\t";
                if (node->Left) {
                    q.push(node->Left);
                }
                if (node->Right) {
                    q.push(node->Right);
                }
            }
            std::cout << "\n";
        }
    }
};


void test_bst()
{
    BST tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    std::cout << "Inorder: ";
    tree.in_order(); // This will print all the elements in ascending order
    std::cout << std::endl;

    std::cout << "-------------" << std::endl;
    tree.level_order();

    tree.delete_value(12);
    std::cout << "Inorder after deleting 12: ";
    tree.in_order(); // This will print all the elements in ascending order
    std::cout << std::endl;

    std::cout << "-------------" << std::endl;
    tree.level_order();

    if (tree.find(12))
        std::cout << "Element 12 is present in the tree" << std::endl;
    else
        std::cout << "Element 12 is NOT present in the tree" << std::endl;
}
