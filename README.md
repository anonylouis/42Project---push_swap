# 42Project---push_swap

The push_swap program should received a list of numbers and returns some instructions to sort the initial list.

But only some actions are available to sort the list.

## The rules

- They are two stacks A and B.
- At the begining : the stack A is fully filled by the initial list and the stack B is empty.

To sort the list here are the instructions available :
- **sa** (or sb) : Swap the first 2 elements at the top of the stack A (or B)
- **ss** : Equivalent to sa and sb 
- **pa (or pb)** : Move the first element at the top of the stack B to the top of the stack A
- **ra (or rb)** : Shift up all elements of stack A (or B) by 1
- **rr** : Equivalent to ra and rb
- **rra (or rrb)** : Shift down all elements of stack A (or B) by 1
- **rrr** : Equivalent to rra and rrb

## My strategy

### len <= 3

If there are 3 elements or less then the sort is trivial. Just list the cases and found how to sort.

### len <= 7

If there are 7 elements or less then I used a Quicksort algorithm to sort the list. I choose the median element as a pivot 

### len > 7

If there are more than 7 elements, I made a sort based on the insertion sort algorithm !
Some explanations :
- The goal is to push all elements from stack A to stack B one by one until stack A is empty and maintaining the stack B reverse sorted at each moment.
- The stack B should be reverse sorted at each moment but the biggest element could not be at the top (just imagine stack B as a circle, so we don't care where we start if all elements are in there good positions) : the stack B could be for exemple : 2 1 5 4 3
- To choose the element from A to push on B we will choose the element which need the less instructions.
	The cost of every element can be calculated by additioning :
	- The number of ra/rra to shift up the element to the top of A
	- The number of rb/rrb to maintain the stack B reverse sorted after the push of the element
	- 1 for a pb operation
- When stack A is empty just made some rb/rrb to put the biggest element at the top of stack B and push back (with pa) all elements from B to A. As B is reverse sorted, stack A will be sorted !!!

