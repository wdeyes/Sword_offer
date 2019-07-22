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

## 面试题 10 菲波那切数列

- 写结构的构造函数时，记得要给默认值，否则无法初始化一个没有初值的结构对象.
- 结构可以赋值，说明有默认的拷贝构造函数.

## 面试题 11 旋转数组最小数字

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

## 面试题 12 矩阵中的路径

- 回溯法：遍历剪枝，维护一个**全局变量**，扩展枝条更新它，扩展的不对就回溯，也就是恢复它。

## 面试题13 机器人的运动范围

- 递归的 core 函数要写通用部分，可以通过递推公式写这个函数。

## 面试题14 剪绳子

- 虽然用递归去分析，也就是由上至下的分析，但是为了避免重复的运算，代码用从下至上的思路去写，也就是循环求解每一子问题的值，并且存储到一个数组中，之后直接使用。
- 注意题目要去必须剪，即 m>1，也就是 n=3 时，最大为 2。但是子问题中，剩余绳子为 3 时，最优的子问题解是 3 。code 中需要特殊处理。
- 贪心算法，比较贪心，容易错，需要有数学证明支持。

## 面试题15 二进制中1的个数

- 一个规律记住，减 1 做 &，就是把右边 1 变成 0

## 面试题16 数值的整数次方

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

## 面试题17 打印从1到最大的n位数

1. 用字符串解决大数问题
	- 打印时注意是从非零开始，而不是非零就不打印
	- 加一时可以边加边判断是否到规定最大

2. 全排列问题
   - 递归实现，树结构
   - 注意到树的末梢时要结束

## 面试题18 删除链表的节点

1. 时间o(1)复杂度删除某个节点
	
	- … a->b->c ...
	
	- 删除某个节点 b 需要知道前一个节点 a 指针，用来连接后面 c；由于单向链表无法向前移动，所以只能删除后面的一个节点 c，并把 c 的内容复制到 b 节点
	- 最后注意考虑边界情况
	
2. 删除重复节点

   - 此问题容错出现越界而发生段错误，注意访问下一个节点的条件是本节点不为空
   - 如果可能改变头节点，函数就要传入`**Head`

## 面试题19 正则表达式

- 递归、树

## 面试题20 表示数值的字符串

[const char * 、char const *、 char * const 三者的区别](https://blog.csdn.net/silentob/article/details/76994618)

- const char* ptr，不可以通过 ptr 修改所指内容
- char const *ptr，与上面的等价
- char* const ptr，

## 面试题21 调整数组顺序使奇数位于偶数前面

- 扩展性

## 面试题22 链表中倒数k个节点

- 单向链表，由于不可倒着遍历，因此可以使用两个指针一前一后。

## 面试题23 链表中环的入口节点

- 先确定是否有环，注意环的规律，Solve1 时间复杂度为：n
- 使用 unordered_map 也可以，时间 n*logn

## 面试题24 反转链表

- 每次改变一个箭头，注意保留指针下次用

## 面试题25 合并两个排序的链表

- 链表的操作不会耗费额外的空间，因为 pHead 加入节点 a，就会让 a 与之前的节点断开。因此不要考虑把 pHead1 的节点一个一个的插入到 pHead2 。要新建一个链表，一个一个的把当前最小的加入到新的链表。这里要敏感的发现每次处理的情况一样，所以递归。

## 面试题26 树的子结构

- 递归可以先考虑主体部分，再考虑前面的判断结束语句。

## 面试题30 包含 min 函数的栈

- 栈是一种先进后出的结构，首先不能破坏这种结构，不然就不叫栈了。因此考虑增加一个成员变量存储 min，新进来一个更新一次，但是弹出一个，无法更新，因此需要存每一个时刻的 min，因此考虑增加一个成员变量——“**栈**”来存每一时刻的 min。

## 面试题34 二叉树中和为某一值的路径

- 二叉树的递归遍历中本身包含回溯效果，注意理解递归调用的细节。

## 面试题35 复杂链表的复制

- 复制 m_pNext 容易，复制 m_pSibling 不容易，因为它连到哪里需要数距离，并且有可能需要连接的节点还没有复制。因此考虑第一步先复制链表，第二步再连接 m_pSibling。第一步时可以将每一个节点与它的复制存在一个 hash 表中，这样第二步时可以快速定位。
- 第二种方式需要经验和灵感，在链表的每个节点旁边复制，这样可以利用 m_pNext 快速访问，原来的节点 m_pSibling 连接到哪里，那么它旁边节点就连接到那里的旁边。最后再奇偶拆开。

## 面试题36 二叉搜索树与双向链表

- 不要把二叉树左右分开，它们是一样的，递归就可以。
- 递归不知道传入什么变量时，要考虑维护一个变量，指针之类的。

## 面试题 38 字符串的排列

- 递归：子问题要选择相对容易传递的，字符串每次选一个，就可以变成，把第一个字符和后面的每一个交换，这样就每次选第一个，传递后面更容易。至于后面的顺序，可以在传递完之后交换回来。
- 本题扩展：答案都是最后输出，先存答案。递归函数不要跳入，假装已经完成。有些地方计算机处理和人不一样，但有相似地方，这组合问题就是每次的字符有选择和不选择两种，之间的分叉就是递归调用栈回去进行分叉。

## 面试题39 数组中出现次数超过一半的数字

- 分析时间复杂度，简介的估计方法是：对于递归这种按照理想情况就是 logn 层递归。所以快排的 T(n)=n*logn。这道题 Solution1 也按照理想情况每次对半就是：T(n)=n+n/2+n/4+…+1，等比数列，求和得O(n)。
- Solution2 方法太强了，完全利用的数组的特点。

## 面试题41 数字流中的中位数

- 使用最大堆，vector， make_heap，pop_heap 实现堆。

## 面试题43 1~n整数中1出现的次数

- 书上分析较为复杂，《编程之美》“1的数目”分析更好。方法二为参考上面的代码。

- 自己考虑过按照数位找是 1 的次数，但是，第一会有其它位重叠的部分，第二数字里面的 1 次数有时不为 1 。

  但是看《编程之美》发现，按照数位分类，不管是否重叠刚好就是总共的次数。比如 n=22，个位1情况：1、11、21 三种；十位 1 情况：10~19 十种。虽然两次都算了 11，但是它刚好就是有两个 1 。所以 n=22 时，答案为 13 。

- 《编程之美》分析很明白，规律知道了，但是代码实现比较巧，因此较难实现，需要分析代码。代码中 iFacter 使用的很好，是精髓所在。

## 面试题47 礼物的最大价值

- 典型的动态规划思想，由下而上的实现，因为每次更新之和上面的值和左边的值有关，所以不用存储所有的值，优化空间。

## 面试题48 最长不含重复字符的字符串

- 找有没有重复不仅可以用 hash 表，还可以用数组下标定位看值，这个值还可以存位置，O(1) 使用。

## 面试题 51 数组中的逆序对

- 归并排序
- 理解递归时最好假设上一个条件已知。然后初始条件能完成。就像数学归纳法那样。

## 面试题54 二叉搜索树的第 k 大节点

- 递归报段错误，很难找到错误，最后发现没有用引用。
- 以后维护全局变量时一定要用引用类型，保持好习惯。尤其是递归。
- 递归时一定要注意，该引用时候就引用，尤其是指针，不引用就相当于没改变；即使不是指针，该引用也要引用，不然改变的是另一个空间的量，调用函数完成后就释放了，递归调用栈回去的那个函数里面量没有改变。

## 面试题 56 数组中数字出现的次数

- 数组中只出现一次的两个数字，其他出现两次

  注意数字题目考虑异或等位运算。

- 数组中唯一只出现一次的数字，其他出现三次

  这类题可以先把数字都想象成二进制数。根据书上思路写出了更好的代码，可以边算某一位边维护答案。

## 面试题59 队列的最大值

- deque 一种前后都可以 push 和 pop 的队列，两头队列。
- 通过这种队列来维护可能的答案，这个答案里面是递减的。

## 面试题60 n个骰子的点数

- [剑指%20Offer%20题解%20-%2060~68.md#60-n-个骰子的点数](https://github.com/CyC2018/CS-Notes/blob/master/notes/)
- 动态规划不是一定要解决求优问题，递推关系的也可以。

## 面试题64 求1+……+n

- 循环不能用 while，设计一个类，里面有静态变量，将++写到构造函数中，建一个n维数组时就可以++n次。
- 递归，但是不能用if，无法判断递归的初始条件，virtual 函数可以当做判断，类和它的继承类。同一个函数名，不同对象的函数。
- 递归，没有virtual，可以用函数指针实现，两个函数名同一个函数指针类型。
- 递归，模板类型
- 递归，&&(与)的短路特性实现初始条件与其他条件的区分。