# Sword_offer
> 《剑指offer》题目练习及笔记
>
> 笔记直接记录到 README.md 中，可结合每道对应代码理解。
>
> 文件夹命名方式为数字，代表面试题号，例如，03 代表面试题 3，每个文件夹中包含
>
> 1. 官方答案程序：大写字母开头
> 2. 自己编写程序：小写字母开头

[TOC]

## 面试题 1

- 参考网页 [面试题1：复制运算符 - JudgeGong - CSDN博客](https://blog.csdn.net/qq_30483585/article/details/79414675)
- 字符串指针初始化时赋值无错无警告 用这个 `char test[] = "hello";`
- 注意 cout  的使用

```c++
cout << test << endl; //输出的是 hello
cout << *test << endl; //输出的是 h
```

- 异常安全性原则（Exception Safety）：

  指程序运行有问题，但不会破坏已有的数据。

## 面试题 3

- 注意 break 不能连着写，因为执行第一个 break 时，第二个就不执行了。

- 思路：搜索：多想着二分法 $log(n)$ 

## 面试题 4

- 注意 `vector<cector<int> >` 有个空格，不然报错。
- 声明不能写在 if 和 else 里面。

- 思路:既然有顺序，那就依然想着从中间搜索。二分法思想。

## 面试题 5

- \0 和 空格不一样，空格是一个字符，ASCII 码是32；\0 是空字符，代表字符串的结束，ASCII 码是0。
- 连续输入两个 vector，在两个中间要加

```c++
cin.clear();
cin.get();
```

- vector 注意 size 和 capacity，test.cpp 帮助理解。
- 动态数组没有长度，静态数组长度求法：`sizeof(nums)/sizeof(nums[0])`
  但是初始化时必须有长度：`int* nums = new int[10]; delete[] nums;`，test.cpp 帮助理解。

## 面试题 6

- List 的尾部添加和删除某一个，都必须传入 ListNode**
- struct 具有默认的构造函数，`ListNode* a=new ListNode();`，`ListNode* b=new listNode;`，a 调用了默认构造函数，而 b 没有，a 中的成员具有初始值，但是 b 没有，b 必须在后面给值。

## 面试题 7

- 树本身就是递归构建的，因此很多操作可以使用递归进行
- 递归--循环
- 三种遍历的 6 种实现方法

##面试题 8

- 也不是所有树都用递归做方便，画出树找规律
- 一个函数尽量不要写多个 return

## 面试题 9

两个栈实现队列的加一个，减一个

- 队列：双通口单操作
- 栈：单通口双操作
- 队列尾部加一个 -》 栈尾部操作 -》 stack1
- 队列头部减一个 -》 栈头部操作 -》 stack2
- 要点：stack1 与 stack2 相反，一个倒序，一个正序
- 因此，可以想象 stack1 与 stack2 连接起来行成队列

### 思考题

- 要把栈的压入和弹出分开解决

## 面试题 10

- 写结构的构造函数时，记得要给默认值，否则无法初始化一个没有初值的结构对象.
- 结构可以赋值，说明有默认的拷贝构造函数.

## 面试题 11

### 随机数

- 产生一个随机数： `rand()`，但是，虽然是随机数，但每次固定。

- 产生一定范围内并且变化的随机数：

  ```c++
  #include<time.h>
  srand( (int)time(0) ); //产生一个随时间变化的种子
  int num = rand(); //产生了变化的随机数
  num = num%(x-y+1)+x //产生了 x<=num<=y 的随机数
  ```

### 查找最小

- 有规律，考虑二分查找

## 面试题 12

- 回溯法：遍历剪枝，维护一个**全局变量**，扩展枝条更新它，扩展的不对就回溯，也就是恢复它。

## 面试题13

- 递归的 core 函数要写通用部分，可以通过递推公式写这个函数。

## 面试题14

- 虽然用递归去分析，也就是由上至下的分析，但是为了避免重复的运算，代码用从下至上的思路去写，也就是循环求解每一子问题的值，并且存储到一个数组中，之后直接使用。
- 注意题目要去必须剪，即 m>1，也就是 n=3 时，最大为 2。但是子问题中，剩余绳子为 3 时，最优的子问题解是 3 。code 中需要特殊处理。
- 贪心算法，比较贪心，容易错，需要有数学证明支持。

## 面试题15

- 一个规律记住，减 1 做 &，就是把右边 1 变成 0

## 面试题16

- double 型的数不能和 0 判断是否相等，应该用如下：

  ```c++
  bool equal_0(double n){
  	double accurate=1e-8;
  	if(fabs(n)<accurate)
  		return true;
  	else
  		return false;
  }
  ```

- 边界值判断有时能加入到正常功能代码中

- 位运算和与运算比除法和模运算效率高

  ```c++
  n>>1; //就是n/2
  if((n&1)==1) //判断n是奇数
  ```

## 面试题17

1. 用字符串解决大数问题
	- 打印时注意是从非零开始，而不是非零就不打印
	- 加一时可以边加边判断是否到规定最大

2. 全排列问题
   - 递归实现，树结构
   - 注意到树的末梢时要结束

## 面试题18

1. 时间o(1)复杂度删除某个节点
	
	- … a->b->c ...
	
	- 删除某个节点 b 需要知道前一个节点 a 指针，用来连接后面 c；由于单向链表无法向前移动，所以只能删除后面的一个节点 c，并把 c 的内容复制到 b 节点
	- 最后注意考虑边界情况
	
2. 删除重复节点

   - 此问题容错出现越界而发生段错误，注意访问下一个节点的条件是本节点不为空
   - 如果可能改变头节点，函数就要传入`**Head`

## 面试题19

- 递归、树

## 面试题20

[const char * 、char const *、 char * const 三者的区别](https://blog.csdn.net/silentob/article/details/76994618)

- const char* ptr，不可以通过 ptr 修改所指内容
- char const *ptr，与上面的等价
- char* const ptr，

## 面试题21

- 扩展性

## 面试题22

- 单向链表，由于不可倒着遍历，因此可以使用两个指针一前一后。

## 面试题23

- 先确定是否有环，注意环的规律，Solve1 时间复杂度为：n
- 使用 unordered_map 也可以，时间 n*logn

## 面试题24

- 每次改变一个箭头，注意保留指针下次用

## 面试题25

- 链表的操作不会耗费额外的空间，因为 pHead 加入节点 a，就会让 a 与之前的节点断开。因此不要考虑把 pHead1 的节点一个一个的插入到 pHead2 。要新建一个链表，一个一个的把当前最小的加入到新的链表。这里要敏感的发现每次处理的情况一样，所以递归。