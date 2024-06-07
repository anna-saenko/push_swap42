# push_swap

This is a project implememted as a task at 42Luxembourg school.


**The rules**

• You have 2 stacks named a and b.

• At the beginning:

◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.

◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:


__sa (swap a)__: Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

__sb (swap b)__: Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

__ss__ : sa and sb at the same time.

__pa (push a)__: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

__pb (push b)__: Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

__ra (rotate a)__: Shift up all elements of stack a by 1.
The first element becomes the last one.

__rb (rotate b)__: Shift up all elements of stack b by 1. The first element becomes the last one.
__rr__ : ra and rb at the same time.

__rra (reverse rotate a)__: Shift down all elements of stack a by 1.
The last element becomes the first one.

__rrb (reverse rotate b)__: Shift down all elements of stack b by 1. The last element becomes the first one.
__rrr__ : rra and rrb at the same time.


