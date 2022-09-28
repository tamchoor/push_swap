# push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.


Writing a sorting algorithm is always a very important step in a developer’s journey. It is often the first encounter with the concept of complexity.
Sorting algorithms and their complexity are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts since you’ll have to face them at some point.

The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

                                      The rules

• You have 2 stacks named a and b.

• At the beginning:

◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.


External functs. : • read, write, malloc, free, exit
• ft_printf and any equivalent YOU coded


Your project must comply with the following rules:

• You have to turn in a Makefile which will compile your source files. It must not relink.

• Global variables are forbidden.

• You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).

• The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.

• Instructions must be separated by a ’\n’ and nothing else.

• The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.

• If no parameters are specified, the program must not display anything and give the prompt back.

• In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
