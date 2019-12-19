#pragma once

#include <iostream>
#include <queue>
#include <string>

struct TreeNode
{
    std::string Data;
    TreeNode* Left;
    TreeNode* Right;
};

struct OrgTree
{
    TreeNode* root;

    static OrgTree create_tree(const std::string& name)
    {
        OrgTree org;
        org.root = new TreeNode{name, nullptr, nullptr};
        return org;
    }

    static TreeNode* find(TreeNode* node, const std::string& name)
    {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->Data == name) {
            return node;
        }

        auto find = OrgTree::find(node->Left, name);
        if (find) {
            return find;
        }
        return OrgTree::find(node->Right, name);
    }

    bool add_item(const std::string& name, const std::string& add_name)
    {
        auto node = find(root, name);
        if (!node) {
            std::cout << "add item name is null" << std::endl;
            return false;
        }

        if (node->Left && node->Right) {
            std::cout << "the node has two itmes" << std::endl;
            return false;
        }

        if (!node->Left) {
            node->Left = new TreeNode{add_name, nullptr, nullptr};
        } else {
            node->Right = new TreeNode{add_name, nullptr, nullptr};
        }
        return true;
    }

    static void pre_order(TreeNode* start)
    {
        if (!start) {
            return;
        }
        std::cout << start->Data << std::endl;
        pre_order(start->Left);
        pre_order(start->Right);
    }
    static void in_order(TreeNode* start)
    {
        if (!start) {
            return;
        }
        in_order(start->Left);
        std::cout << start->Data << std::endl;
        in_order(start->Right);
    }
    static void post_order(TreeNode* start)
    {
        if (!start) {
            return;
        }
        post_order(start->Left);
        post_order(start->Right);
        std::cout << start->Data << std::endl;
    }
    static void level_order(TreeNode* start)
    {
        if (!start) {
            return;
        }
        std::queue<TreeNode*> q;
        q.push(start);
        while (!q.empty()) {
            int size = q.size();
            for (size_t i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                std::cout << node->Data << std::endl;
                if (node->Left) {
                    q.push(node->Left);
                }
                if (node->Right) {
                    q.push(node->Right);
                }
            }
        }
    }
};


void test_trees()
{
    auto tree = OrgTree::create_tree("A");
    tree.add_item("A", "B");
    tree.add_item("A", "F");
    tree.add_item("B", "C");
    tree.add_item("B", "D");
    tree.add_item("D", "E");
    tree.add_item("F", "G");
    tree.add_item("F", "I");

    std::cout << "preorder:" << std::endl;
    OrgTree::pre_order(tree.root);

    std::cout << "in-order:" << std::endl;
    OrgTree::in_order(tree.root);

    std::cout << "post-order:" << std::endl;
    OrgTree::post_order(tree.root);

    std::cout << "level-order:" << std::endl;
    OrgTree::level_order(tree.root);
}