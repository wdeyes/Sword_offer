## 面试题 1：赋值运算符

- 参考网页 [面试题1：复制运算符 - JudgeGong - CSDN博客](https://blog.csdn.net/qq_30483585/article/details/79414675)
- 字符串指针初始化时赋值无错无警告 用这个 `char test[] = "hello";`
- 注意 cout  的使用
```c++
cout << test << endl; //输出的是 hello
cout << *test << endl; //输出的是 h
```

- 异常安全性原则（Exception Safety）：

  指程序运行有问题，但不会破坏已有的数据。