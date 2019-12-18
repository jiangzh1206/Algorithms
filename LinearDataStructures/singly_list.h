#include <iostream>
#include <algorithm>

template <typename T>
struct Node
{
    T Data;
    Node* Next = nullptr;
};

template <typename T>
class SinglyList
{
public:
    SinglyList() = default;
    SinglyList(const SinglyList& other)
    {
        if (!other.head_) {
            return;
        }
        auto cur = head_;
        for (auto& v : other) {
            auto node = new Node<T>{v.Data, nullptr};
            if (cur) {
                cur->Next = node;
                cur = cur->Next;
            } else {
                head_ = cur = node;
            }
        }
    }
    SinglyList(std::initializer_list<T> ilist)
    {
        for (auto it = std::rbegin(ilist); it != std::rend(ilist); it++) {
            push_front(*it);

        }
    }
public:
    void push_front(const T& val)
    {
        auto new_node = new Node<T>{val, nullptr};
        if (head_ != nullptr) {
            new_node->Next = head_;
        }
        head_ = new_node;
    }
    void pop_front()
    {
        auto first = head_;
        if (head_) {
            head_ = head_->Next;
            delete first;
        } else {
            throw "List is empty£¡";
        }
    }

    class Iterator
    {
    public:
        Iterator() : ptr_(nullptr)
        {
        }
        Iterator(Node<T>* ptr) : ptr_(ptr)
        {
        }
        Iterator(Iterator& other)
        {
            ptr_ = other.ptr_;
        }

        Iterator& operator ++()
        {// pre ++
            ptr_ = ptr_->Next;
            return *this;
        }
        Iterator operator ++(int)
        {// post ++
            auto result = *this;
            ++(*this);
            return result;
        }
        bool operator !=(const Iterator& other)
        {
            return ptr_ != other.ptr_;
        }
        friend bool operator==(const Iterator& left, const Iterator& right)
        {
            return left.ptr_ == right.ptr_;
        }
        Node<T>& operator*()
        {
            return *ptr_;
        }
    private:
        Node<T>* ptr_;
    };

    Iterator begin()
    {
        return Iterator(head_);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
    Iterator begin() const
    {
        return Iterator(head_);
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }
private:
    Node<T>* head_ = nullptr;
};



void test_singly_list()
{
    SinglyList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    for (auto l : list) {
        std::cout << l.Data << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
    SinglyList<int> list1 = list;
    for (auto l : list1) {
        std::cout << l.Data << std::endl;
    }

    SinglyList<int>::Iterator it;

    std::cout << "---------------------------------" << std::endl;
    SinglyList<std::string> list2{"a", "b", "c", "d", "e"};
    for (auto l : list2) {
        std::cout << l.Data << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
    list2.pop_front();
    for (auto l : list2) {
        std::cout << l.Data << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
    list2.pop_front();
    for (auto l : list2) {
        std::cout << l.Data << std::endl;
    }
}