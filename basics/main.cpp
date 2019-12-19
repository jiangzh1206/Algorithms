// basics.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "basics.h"

#include <array>
#include <forward_list>
#include "../LinearDataStructures/linear_structures.h"
#include "../LinearDataStructures/singly_list.h"
#include "../NonLinearStructures/binary_tree.h"
#include "../NonLinearStructures/binary_search_tree.h"
#include "../NonLinearStructures/n_ary_tree.h"

int main()
{
    // test_singly_list();

    //test_dyarray();

    //test_trees();

    // test_bst();

    test_nary_tree();

    std::cout << "Hello World!\n";
}
