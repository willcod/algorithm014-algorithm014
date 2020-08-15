# .NET Framework 4.8 版本 Queue和Priority Queue源码分析



## [Queue](https://referencesource.microsoft.com/#system/compmod/system/collections/generic/queue.cs,bd8dd1fa50192d7b)

.NET Framework 4.8 版本 Queue是一个数组，通过维护头尾两个下标以及size变量来实现的。

| 接口     | 分析                                         | 时间复杂度 |
| -------- | -------------------------------------------- | ---------- |
| 构造     | 创建一个数组成员，头尾下标以及size都为 0     | O(1)       |
| Count    | 返回size变量值                               | O(1)       |
| Enqueue  | 将对象赋给数组的末尾元素，尾下标加1，size加1 | O(1)       |
| Dequeue  | 将数组头元素返回，头下标加1，size减1         | O(1)       |
| Peek     | 将数组头元素返回                             | O(1)       |
| Contains | 遍历整个数组                                 | O(n)       |



## Priority Queue

.NET Platform 没有公开实现的PriorityQueue。但是在WindowsBase和PresentationCore里各含有一个内部实现。WindowsBase里的[PriorityQueue](https://referencesource.microsoft.com/#WindowsBase/Base/MS/Internal/PriorityQueue.cs)实现比较复杂牵扯到其他相关类以及调度优先级等等。所以这里就PresentationCore里的[PriorityQueue](https://referencesource.microsoft.com/#PresentationCore/Shared/MS/Internal/PriorityQueue.cs,3779854732f36d06)进行分析。

这个版本的内部是通过以数组作为底层数据结构构建的堆(heap)来实现的。在实际运行中，类似于栈，总是操作顶部元素。

| 接口 | 分析                                                         | 时间复杂度 |
| ---- | ------------------------------------------------------------ | ---------- |
| 构造 | 除了传入初始化size以外，还需要传入一个compare函数来用于优先级的比较 | O(1)       |
| Top  | 返回根节点                                                   | O(1)       |
| Push | 将新值加入到堆尾，如果新值小于父节点，则向上移动，直到大于等于父节点 | O(log n)   |
| Pop  | 去除根节点，将剩余元素通过compare函数调整到正确位置          | O(log n)   |

