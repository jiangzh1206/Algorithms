## Lookup
&emsp; ���ٲ���

#### Hash Table
&emsp;ɢ�б���ϣ��  
Hash��һ�㷭������ɢ�С���Ҳ��ֱ������Ϊ����ϣ���ģ����ǰ����ⳤ�ȵ����룬ͨ��ɢ���㷨���任�ɹ̶����ȵ���������������ɢ��ֵ  
��ײ: 
* ����ַ������ͻkey��ֵ��������  
* ���Ŷ�ַ����ͨ��ĳ��̽�⼼��������̽�⣬2��̽�⣩��ȥ����̽��������Ԫ��ֱ��̽�鵽����ͻΪֹ����Ԫ����ӽ�ȥ  
* �ٹ�ϣ�����ڷ�����ϣ��ͻ��ʹ������һ����ϣ�㷨����һ���µĵ�ַ��ֱ����������ͻΪֹ  

Perfect Hashing �C Cuckoo Hashing������hash-������ɢ�У�  


load factor ����״̬1��<1 �˷ѣ�>1 ������ 
![File](image\file.png)
***

#### Bloom Filter
&emsp;��¡������


##### Divide-and-Conquer
���η�  
- �ֽ⣺��ԭ����ֽ�Ϊ���ɸ���ģ��С���໥��������ԭ������ʽ��ͬ��������
- ��������������ģ��С�����ױ������ֱ�ӽ⣬����ݹ�ؽ����������
- �ϲ���������������Ľ�ϲ�Ϊԭ����Ľ�

##### �鲢����  
�ⲿ�����㷨�����Բ�פ���ڼ�������ڴ��е����ݽ�����������ʱ���ڴ��б����������ݵ�һС����  
��һ�����Ԫ�ؼ������������һ��С��Ԫ���Ӽ�����������һ���ģ�Ȼ��ϲ��������Ӽ����Ӷ���֤Ԫ�ص����ӻ�ݼ���˳��


<img src="image\mergesort.png" width=400 height=400>

---

##### ��������
ѡ���׼Ԫ�أ�pivot element)��������L��С��P�� P R������P��  

<img src="image\quick_sort.png" width=400 height=280>


##### ����ʱ��ѡ��
��iСԪ��

![Stl](image/stl.png)

##### MapReduce
```MapReduce is a programming model and an associated implementation for processing
and generating large datasets. Users specify a map function that processes a key-value
pair to generate a set of intermediate key/value pairs, and a reduce function that merges
all the intermediate values associated with the same intermediate key.
```

***Map*** is an operation that takes in a container, C, and applies a given function, f(x), to
each element of C. An example of using f(x) = x 2 is shown in the following diagram:  
<img src="image\map.png" width=400 height=100>

***Reduce*** is an operation that aggregates values in a container, C, by applying a given
function, f(acc, x), to each element, x, of C, and returning a single value. This is shown in
the following diagram:  
<img src="image\reduce.png" width=400 height=100>  
The C++ Standard Library contains map and reduce operations, that is std\:\:transform() 
and std\:\:accumulate(), respectively (std\:\:reduce() is also available in
C++ 17).std\:\:reduce() , which is more general and can be parallelized.  

**Generalized MapReduce framework**
<img src="image\map_reduce.png" width=450 height=150> 
