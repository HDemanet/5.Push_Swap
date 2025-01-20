<p align="center">
  <img src="push_swape.png" alt="Push_swap Logo">
</p>

# Push_Swap  

The **push_swap** project from the 42 school curriculum is a fundamental algorithm exercise where we sort a list of random numbers using only a limited set of instructions. The goal is to minimize the number of actions while sorting efficiently using two stacks. 

---

## 📋 Mandatory Features  

### The push_swap function must
#### Use two stacks: stack A and stack B.
Perform a series of operations to sort numbers from stack A into ascending order in the most efficient way.

#### Use the following instructions:
- pa (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
- pb (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
- sa (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
- sb (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
- ss: sa and sb at the same time.
- ra (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
- rb (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
- rr: ra and rb at the same time.
- rra (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
- rrb (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

### Performance Requirements
To pass this project, you must be able to:
- Sort 100 random integers in less than 700 operations (average).
- Sort 500 random integers in less than 5500 operations (average).
 
