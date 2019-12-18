## Linear data structures

线性数据结构，大致分为顺序存储结构（array）和链式存储结构（list）。  
##### SequenceContainer
- **std::array:** &emsp;      C风格数组的简单封装，编译器提供大小，不支持插入删除，使用stack内存
- **std::vector** &emsp;      可动态扩容（指数增长），随机访问random access iterator，插入删除低效，注意iterator失效
- **std::forward_list**&emsp; 单链表的简单封装，不支持back相关的操作，前向forward iterator
- **std::list**&emsp;         双向链表，双向bidirectional iterator
- **std::deque**&emsp;        特殊的vector，多个连续内存块链起来，在序列首尾高效地插入/删除


##### Container Adaptors
- **std::stack** &emsp;限制行为 LIFO (Last In First Out)，底层默认deque
- **std::queue**&emsp;FIFO (First In First Out) 底层默认deque
- **std::priority_queue**&emsp;实现结构堆heap（std::make_heap），默认大顶，底层vector  
遍历栈，队列没有意义，标准库不提供Iterator

