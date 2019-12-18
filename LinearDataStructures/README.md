## Linear data structures

�������ݽṹ�����·�Ϊ˳��洢�ṹ��array������ʽ�洢�ṹ��list����  
##### SequenceContainer
- **std::array:** &emsp;      C�������ļ򵥷�װ���������ṩ��С����֧�ֲ���ɾ����ʹ��stack�ڴ�
- **std::vector** &emsp;      �ɶ�̬���ݣ�ָ�����������������random access iterator������ɾ����Ч��ע��iteratorʧЧ
- **std::forward_list**&emsp; ������ļ򵥷�װ����֧��back��صĲ�����ǰ��forward iterator
- **std::list**&emsp;         ˫������˫��bidirectional iterator
- **std::deque**&emsp;        �����vector����������ڴ������������������β��Ч�ز���/ɾ��


##### Container Adaptors
- **std::stack** &emsp;������Ϊ LIFO (Last In First Out)���ײ�Ĭ��deque
- **std::queue**&emsp;FIFO (First In First Out) �ײ�Ĭ��deque
- **std::priority_queue**&emsp;ʵ�ֽṹ��heap��std::make_heap����Ĭ�ϴ󶥣��ײ�vector  
����ջ������û�����壬��׼�ⲻ�ṩIterator

