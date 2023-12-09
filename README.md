# Description

This project compares two programming languages, C and Python. It focuses on the execution differences in implementing a dictionary using hash tables with the 'chaining' collision resolution technique. Both programs allow users to input a word for lookup and retrieve word definitions from the 'dictionary.txt' file, which contains a collection of 100 words.

# Requirements/Commands

Requires C compiler and python interpreter

C:

```
gcc -o hash_table hash_table.c
./hash_table
```

Python:

```
python3 hash_table.py

```

# Comparison

## Concept 1: Compiler vs Interpreter

C and Python are executed differently due to their being a compiled and interpreted languages, respectively.

In C, a compiler like GCC is used to compile the code into an executable format. The C code is converted into a machine-readable binary file (an executable). Any compilation errors are reported during this stage, before the program can be run. Once the executable file is generated, it can be executed immediately any number of times. Only when the code is modified does the program need to be recompiled. This approach leads to faster execution times since the code is already in a machine-readable format.

Python, on the other hand uses an interpreter to execute the code. Using the interpreter means there is no separate compilation step to create an executable file. Instead, the interpreter reads and executes the Python script directly. Each time a Python program is executed, the interpreter processes the code, translating it into machine-readable instructions immediately. While this makes Python scripts very flexible and easy to test and modify, it can result in slower execution times compared to pre-compiled C programs, as the interpretation needs to happen every time the program is run.

## Concept 2: Garbage Collection

In C and Python, garbage collection is done differently.

In C, even though there is no automatic garbage collectoion, there are built-in functions 'malloc', to allocate memory and 'free' to deallocate memory. With these functions, memory management is handled manually by the programmer. As seen in the C program, ' malloc' is used to allocate memory dynamically when creating data structures, such as instances of 'WordDefPair' and 'HashTable'. Correspondingly, memory deallocation is handled through user-defined functions, namely 'freeWordDefPair' and 'freeHashTable', which utilize the free function. This approach to memory management gives programmers control over memory allocation and deallocation, which can be advantageous when optimizing memory usage is important. However, it also means that programmers are responsibile for managing memory, which can lead to issues like memory leaks if not handled carefully.

Python on the other hand, has an automatic garbage collector, which automates the process of memory management. This is as seen in the Python program where there is an absence of explicit memory allocation or deallocation functions. This is because Python's garbage collector automatically reclaims memory from objects that are no longer in use, significantly simplifying memory management for the programmer. This automatic garbage collection makes coding in Python easier and less error-prone with regard to memory management, as it reduces the risk of memory leaks and other memory-related errors. However, it may also result in less control over memory handling compared to C.

## Concept 3: Paradigms

C and Python, as shown in the provided programs, have different programming paradigms. C primarily employs an imperative programming paradigm, while Python utilizes both imperative and object-oriented paradigms.

In the C program, the imperative paradigm is evident in the way data structures and functions are defined and used. The structures , 'WordDefPair' and 'HashTable' and the functions ,'insert', 'search', etc. are defined separately. Functions operate on these structures by explicitly modifying their state, characteristic of imperative programming. This paradigm emphasizes a sequence of commands to manipulate program state.

On the other hand, the Python program demonstrates object-oriented principles through its use of classes and objects. The 'WordDefPair' and 'DicHashTable' are defined as classes, with each instance of these classes being an object that encapsulates both data and the methods that operate on that data. In Object Oriented programming, data structures (objects) have associated methods, enabling a more modular and intuitive approach to handling data and functionalities.

# Output

![C output](./outputs/c%20output.JPG)
![Python output](./outputs/python%20output.JPG)
