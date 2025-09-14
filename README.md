# Maze Solver

**Name:** Zainab Ghafoor  
**ID:** 008259427  
**GitHub repository link:** [https://github.com/zainabghafoor0/maze_solver.git](https://github.com/zainabghafoor0/maze_solver.git)

---

## Project Description

This project implements a maze solving algorithm using **backtracking** to find a path from a start position to a target position. The maze is represented as a grid where `1` represents walls and `0` represents open paths that can be traversed.

The algorithm uses a stack-based approach to explore possible paths and automatically backtracks when encountering dead ends, ensuring all possible routes are explored until a solution is found.

---

## Collaboration & Sources

- The project requirements and maze input format were provided in the course materials.
- The backtracking algorithm pseudocode was referenced from the project PDF documentation.
- These are the files I implemented:  
  - `maze_solver.cpp` - Main implementation with backtracking algorithm
  - `maze0-1_input.txt` - Input maze file (13x15 grid)

I developed, tested, and debugged the complete implementation independently.

---

## Implementation Details

The program implements a maze solver with the following key components:

### 1. **MazeSolver Class**
- Loads maze from text file format
- Automatically detects start and target positions
- Implements backtracking algorithm using STL stack
- Provides visualization of original maze and solution path

### 2. **Core Algorithm: Backtracking**
```
1. Push start cell onto stack
2. While stack is not empty:
   - If current cell is target → SUCCESS
   - If unexplored adjacent cells exist:
     → Choose one, mark as visited, push to stack
   - Else (dead end):
     → Pop from stack (backtrack)
3. If stack becomes empty → NO PATH EXISTS
```

### 3. **Key Features**
- **File I/O**: Reads maze from text file with 1s (walls) and 0s (paths)
- **Pathfinding**: Uses 4-directional movement (up, right, down, left)
- **Visualization**: Displays original maze and solution with path markers
- **Path Analysis**: Shows complete coordinate sequence and path length

### 4. **Data Structures Used**
- `std::stack<std::pair<int, int>>` - For maintaining current path and backtracking
- `std::vector<std::vector<int>>` - 2D array for maze representation
- `std::vector<std::vector<bool>>` - Visited cells tracking

---

## Compilation & Usage

### Prerequisites
- C++ compiler (g++ recommended)
- Input maze file in the same directory

### Compilation
```bash
g++ -o maze_solver maze_solver.cpp
```

### Execution
```bash
./maze_solver
```

---

## Testing & Results

### Input Maze Format
The maze is provided as a 13x15 grid in `maze0-1_input.txt`:
```
111111111111111
100000001000001
101110101010111
000010101010001
111110111011101
100000000010001
101010111010111
101010001010001
101011101011101
101000101010101
101110111010101
100010001000100
111111111111111
```

### Program Output
```
Maze loaded: 13x15
Start: (3, 0)
Target: (11, 14)

Original Maze:
# # # # # # # # # # # # # # # 
#               #           # 
# S # # #   #   #   #   # # # 
        #   #   #   #       # 
# # # # #   # # #   # # #   # 
#                   #       # 
#   #   #   # # #   #   # # # 
#   #   #       #   #       # 
#   #   # # #   #   # # #   # 
#   #       #   #   #   #   # 
#   # # #   # # #   #   #   # 
#       #       #       #   T 
# # # # # # # # # # # # # # # 

Path found!

Maze Solution:
# # # # # # # # # # # # # # # 
# * * * * * * # * * * * * * # 
# S # # # * #   # * #   # # # 
* * * * # * #   # * #   * * # 
# # # # # * # # # * # # # * # 
# * * * * *         # * * * # 
# * # * # * # # #   # * # # # 
# * # * #       #   # * * * # 
# * # * # # #   #   # # # * # 
# * #       #   #   #   # * # 
# * # # #   # # #   #   # * # 
# * * * #       #       # * T 
# # # # # # # # # # # # # # # 

Path coordinates:
(3, 0) -> (3, 1) -> (3, 2) -> (3, 3) -> (2, 3) -> (1, 3) -> (1, 4) -> ... -> (11, 14)
Path length: 39 steps
```

---

## Algorithm Complexity

- **Time Complexity**: O(4^(R×C)) in worst case, where R×C is the maze size
- **Space Complexity**: O(R×C) for visited array and maximum stack depth
- **Practical Performance**: Much better than worst case due to early termination and pruning

---

## Challenges & Solutions

### 1. **Compilation Issues**
- **Problem**: Multi-character constant warnings with Unicode characters
- **Solution**: Replaced Unicode block characters (`█`) with ASCII (`#`)

### 2. **Missing Header Dependencies**
- **Problem**: `std::reverse` not found
- **Solution**: Implemented manual array reversal using `std::swap`

### 3. **Start/Target Detection**
- **Problem**: Automatically identifying start and target positions
- **Solution**: Search for open cells on maze borders, fallback to first/last open cells

### 4. **Path Visualization**
- **Problem**: Converting stack-based path to readable format
- **Solution**: Copy stack to vector, reverse order, and mark path on display grid

---

## Files Structure

```
maze_solver/
├── maze_solver.cpp      # Main implementation
├── maze0-1_input.txt    # Input maze file
└── README.md           # This file
```

---

## Future Enhancements

- Support for multiple maze file formats
- Implementation of alternative algorithms (A*, Dijkstra)
- Interactive maze editor
- Performance benchmarking tools
- Support for larger maze sizes

---

## License

This project is developed for educational purposes as part of coursework.
