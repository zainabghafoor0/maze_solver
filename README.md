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
g++ -o maze_solver maze_solver.cpp
./maze_solver

### Results
Maze loaded: 13x15
Start: (3, 0)
Target: (11, 14)

Original Maze:
█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ 
█               █           █ 
█   █ █ █   █   █   █   █ █ █ 
S       █   █   █   █       █ 
█ █ █ █ █   █ █ █   █ █ █   █ 
█                   █       █ 
█   █   █   █ █ █   █   █ █ █ 
█   █   █       █   █       █ 
█   █   █ █ █   █   █ █ █   █ 
█   █       █   █   █   █   █ 
█   █ █ █   █ █ █   █   █   █ 
█       █       █       █   T 
█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ 
Path found!

Maze Solution:
# # # # # # # # # # # # # # # 
# * * * * *     # * * *     # 
# * # # # * #   # * # * # # # 
S *     # * #   # * # * * * # 
# # # # # * # # # * # # # * # 
#         * * * * * # * * * # 
#   #   #   # # #   # * # # # 
#   #   #       #   # * * * # 
#   #   # # #   #   # # # * # 
#   #       #   #   #   # * # 
#   # # #   # # #   #   # * # 
#       #       #       # * T 
# # # # # # # # # # # # # # # 

Path coordinates:
(3, 0) -> (3, 1) -> (2, 1) -> (1, 1) -> (1, 2) -> (1, 3) -> (1, 4) -> (1, 5) -> (2, 5) -> (3, 5) -> (4, 5) -> (5, 5) -> (5, 6) -> (5, 7) -> (5, 8) -> (5, 9) -> (4, 9) -> (3, 9) -> (2, 9) -> (1, 9) -> (1, 10) -> (1, 11) -> (2, 11) -> (3, 11) -> (3, 12) -> (3, 13) -> (4, 13) -> (5, 13) -> (5, 12) -> (5, 11) -> (6, 11) -> (7, 11) -> (7, 12) -> (7, 13) -> (8, 13) -> (9, 13) -> (10, 13) -> (11, 13) -> (11, 14)
Path length: 39 steps

### Challenges
- The results are not exactly the same as the expected ones given in the lab handout.  
- The lookup time for linked lists is much slower. 
- The vector sorting step also takes more time for big inputs.  
- For the last test (Sorted Linked List with N=500000), my program did finish, but it took a little longer than expected.  
