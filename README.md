# Maze Solver

**Name:** Zainab Ghafoor  
**ID:** 008259427  
**GitHub repository link:** [https://github.com/zainabghafoor0/maze_solver.git](https://github.com/zainabghafoor0/maze_solver.git)

---

## Collaboration & Sources

- The base `Dictionary` interface and `UnsortedVectorDict` example were provided.  
- These are the files I worked:  
  - `maze_solver.cpp`  
  - `maze0-1_input.txt`

I changed and tested everything myself until it worked.  

---

## Implementation Details
The program tests four dictionary implementations:  

1. **Unsorted Vector** – insert at end, linear search for lookup.  
2. **Sorted Vector** – bulk insert then sort once, binary search for lookup.  
3. **Unsorted Linked List** – insert at head, linear search for lookup.  
4. **Sorted Linked List** – bulk insert at head, then sort once, linear traversal for lookup.  

### Files I changed
- `SortedVectorDict.cpp/.hpp` → added `finalize()` function and made insert use push_back before sorting.  
- `SortedLinkedListDict.cpp/.hpp` → added `finalize()` function, added `clear()` helper, fixed destructor so list is deleted safely, changed insert to push at head first then rebuild sorted list in finalize.  
- `UnsortedLinkedListDict.cpp/.hpp` → wrote the full implementation of insert, lookup, and remove.  
- `main.cpp` → added removal time.

The data structures used are simple arrays (`std::vector`) and singly linked lists (with `Node` struct).  

---

## Testing & Status
The program was compiled with:  
```bash
g++ -std=c++20 *.cpp -o a.out
./a.out

### Results
Unsorted Vector [N=5000] — Insert: 103us, Avg Lookup: 18248ns, Remove: 470us
Sorted Vector [N=5000] — Insert: 86us, Avg Lookup: 259ns, Remove: 215us
Unsorted Linked List [N=5000] — Insert: 148us, Avg Lookup: 8645ns, Remove: 4126us
Sorted Linked List [N=5000] — Insert: 125us, Avg Lookup: 5470ns, Remove: 2160us

Unsorted Vector [N=500000] — Insert: 9156us, Avg Lookup: 1811830ns, Remove: 4525938us
Sorted Vector [N=500000] — Insert: 8806us, Avg Lookup: 386ns, Remove: 763420us
Unsorted Linked List [N=500000] — Insert: 14175us, Avg Lookup: 821579ns, Remove: 35534888us
Sorted Linked List [N=500000] — Insert: 14151us, Avg Lookup: 718269ns, Remove: 18453638us

### Challenges
- The results are not exactly the same as the expected ones given in the lab handout.  
- The lookup time for linked lists is much slower. 
- The vector sorting step also takes more time for big inputs.  
- For the last test (Sorted Linked List with N=500000), my program did finish, but it took a little longer than expected.  
