// basics.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "basics.h"

#include <array>
#include <forward_list>
#include "../LinearDataStructures/linear_structures.h"
#include "../LinearDataStructures/singly_list.h"

int main()
{
    test_singly_list();

    std::array<int, 4> arr{1,2,3,4};
    
    //print_array(arr);

    //test_dyarray();

    std::cout << "Hello World!\n";
}
