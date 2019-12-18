#include <iostream>
#include <sstream>
#include <algorithm>
#include <array>
#include <type_traits>



template <typename T>
class DynamicArray
{
public:
    DynamicArray(size_t n)
        : size_(n)
        , data_(new T[n])
    {
    }

    ~DynamicArray()
    {
        delete[] data_;
    }

    DynamicArray(const DynamicArray<T>& other)
    {
        size_ = other.size_;
        data_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other[i];
        }
    }

public:
    size_t size() const
    {
        return size_;
    }
    T& operator[](size_t index)
    {
        return data_[index];
    }
    const T& operator[](size_t index) const
    {
        return data_[index];
    }
    T& at(size_t index)
    {
        if (index < size_) {
            return data_[index];
        }
        throw std::out_of_range("Index out of range");
    }
    T* begin()
    {
        return data_;
    }
    const T* begin() const
    {
        return data_;
    }
    T* end()
    {
        return data_ + size_;
    }
    const T* end() const
    {
        return data_ + size_;
    }

    std::string to_string(const std::string& sep = ",")
    {
        if (size_ == 0) {
            return "";
        }
        std::ostringstream os;
        os << data_[0];
        for (int i = 1; i < size_; ++i) {
            os << sep << data_[i];
        }
        return os.str();
    }

    friend DynamicArray<T> operator+(const DynamicArray<T>& lh, const DynamicArray<T>& rh)
    {
        DynamicArray<T> arr(lh.size() + rh.size());
        std::copy(lh.begin(), lh.end(), arr.begin());
        std::copy(rh.begin(), rh.end(), arr.begin() + lh.size());
        return arr;
    }
private:
    size_t size_;
    T* data_;
};

template <typename T, size_t N>
void print_array(const std::array<T, N>& arr)
{
    for (auto& v : arr) {
        std::cout << v << std::endl;
    }
}

// common_type
template <typename... Args>
auto build_array(Args&&... args)->std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using CommonType = typename std::common_type<Args...>::type;
    return {std::forward<CommonType>(args)...};
}


//////////////////////////////////////////////////////////////////////////////////////////
struct student
{
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
    return (os << "[Name: " << s.name << ", Standard: " << s.standard << "]");
}

void test_dyarray()
{
    int n;
    std::cout << "Enter number of students in class 1 : ";
    std::cin >> n;

    DynamicArray<student> class1(n);

    for (int i = 0; i < n; ++i) {
        class1[i] = student{"John", i};
    }

    try {
        //class1[nStudents] = student{"John", 8}; // No exception, undefined behavior
        //std::cout << "class1 student set out of range without exception" << std::endl;

        class1.at(n) = student{"John", 8}; // Will throw exception
    } catch (...) {
        std::cout << "Exception caught" << std::endl;
    }

    for (auto s : class1) {
        std::cout << s << std::endl;
    }

    auto class2 = class1; // Deep copy
    std::cout << "Second class after initialized using first array : " << class2.to_string() << std::endl;
    auto class3 = class1 + class2;
    std::cout << "Combined class : ";
    std::cout << class3.to_string() << std::endl;


#if 0 // oops error!
    auto data = build_array(1, 0u, 'a', 3.2f, false);
    for (auto i : data)
        std::cout << i << " ";
    std::cout << std::endl;
#endif

}