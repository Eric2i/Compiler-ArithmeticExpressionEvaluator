# **编译原理作业--题目1.2 算术表达式求值**

*本文档使用markdown格式*
*为了更好的视觉效果，*
*建议您使用支持markdown的阅读器*

## 文件目录

- Makefile 本项目使用makefile辅助开发
- readme.md 本说明文件
- bin/: 可执行文件
- src/: 源代码文件
- obj/: 目标文件
- test/: 测试输入输出数据

## 测试

1. 清除可能存在的二进制文件或目标文件

   ```bash
   make clean
   ```
2. 针对以下四个表达式进行求值计算的测试

   - "1-2+3-4+5-6"
   - "(1+2)*(3+4)*5+6"
   - "(((1+2)*(3+4)))*5+6"
   - "24/0"

   ```bash
   make test
   ```

*Notes: 以上四个表达式分别对最朴素的加减运算、带括号的四则运算、多余括号的四则运算与零作分母这四种情况进行了测试。该过程通过Makefile中预设的test目标完成，您可以在src/test.cpp中进一步修改这四个表达式的具体形式。*

## 使用

1. 编译

   ```bash
   make build
   ```

   执行生成bin/evaluator
2. 运行

   - bin/evaluator 支持若干表达式作为参数，表达式之间请用空格分隔开

   ```bash
   bin/evaluator <expression1> <expression2> ... <expressionk>
   ```

   - 程序将根据您输入表达式的顺序，依次给出其结果。

   ```bash
   (1 of k) <expression1> = <result1>
   (2 of k) <expression2> = <result2>
   ... 
   (k of k) <expressionk> = <resultk>
   ```

## 异常与处理

- [x] 零作为除数:

  - 程序内部会抛出一个运行时错误，同时打印在屏幕上

  ```bash
  divide by zero
  ```

  - 同时该表达式的值会以INFINITY的形式回传给求值函数的调用者

  *notes: 严谨来说,表达式存在分母为零，表达式可能为无穷大，如$\lim_{x\rightarrow 0}1/x$; 也可能为常数，如$\lim_{x\rightarrow 0} sin(x)/x$。因此个人认为当出现异常时候，与其给出一个INIFITY，不如直接向调用者抛出一个运行时错误。但这样对于没有准备好异常处理的调用者而言，这样会中断后续有效表达式的执行，因此这里仅仅将“Divide by zero”信息打印到屏幕上。*

- [ ] others:
    - 出现非法字符集
    - 括号匹配失败
    - 错误排列+-*/^的算符位置
    
    对于以上可能存在的错误，在具体的实践中应当给予进一步讨论。但考虑到本项目为中缀表达式的求值的编程作业，这里因此不妨假设所给输入的中缀表达式本身是符合有效数学定义的。
    

## 编译环境

**本项目测试开发所采用的编译器信息:**

```
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: arm64-apple-darwin22.2.0
Thread model: posix
```

## Git

本项目的开发使用Git进行了版本管理，您可以通过git log来查看开发过程中的历史版本信息。