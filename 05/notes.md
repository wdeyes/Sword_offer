## 面试题5

- \0 和 空格不一样，空格是一个字符，ASCII 码是32；\0 是空字符，代表字符串的结束，ASCII 码是0。
- 连续输入两个 vector，在两个中间要加
```c++
cin.clear();
cin.get();
```
- vector 注意 size 和 capacity，test.cpp 帮助理解。
- 动态数组没有长度，静态数组长度求法：`sizeof(nums)/sizeof(nums[0])`
但是初始化时必须有长度：`int* nums = new int[10]; delete[] nums;`，test.cpp 帮助理解。
