# **Compiler(preparation): Arithmetic Expression Evaluator**
IMPORTANT: 本项目衍生自本人编译原理课程作业，但仅仅在作业截止期限后上传至此处。任何学术不端的行为都应该受到强烈谴责。

## Directory Structure 

- Makefile
- readme.md
- bin/
- src/
- obj/
- test/

## Testing

1. remove binary files or target files

   ```bash
   make clean
   ```
2. test following expressions

   - "1-2+3-4+5-6"
   - "(1+2)*(3+4)*5+6"
   - "(((1+2)*(3+4)))*5+6"
   - "24/0"

   ```bash
   make test
   ```

## Usage

1. Compile

   ```bash
   make build
   ```

   This will create bin/evaluator
2. Execute

   - bin/evaluator allow mutiple arguments seperated by a space (' ') 

   ```bash
   bin/evaluator <expression1> <expression2> ... <expressionk>
   ```
   
   - Expected output

   ```bash
   (1 of k) <expression1> = <result1>
   (2 of k) <expression2> = <result2>
   ... 
   (k of k) <expressionk> = <resultk>
   ```

## Compiling Environment


```
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: arm64-apple-darwin22.2.0
Thread model: posix
```
