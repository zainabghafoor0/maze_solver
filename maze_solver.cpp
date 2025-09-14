#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <string>

class MazeSolver {
private:
    std::vector<std::vector<int>> maze;
    std::vector<std::vector<bool>> visited;
    std::stack<std::pair<int, int>> path;
    int rows, cols;
    std::pair<int, int> start, target;
    
    // Directions: up, right, down, left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
public:
    MazeSolver() : rows(0), cols(0) {}
    
    // Load maze from file
    bool loadMaze(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return false;
        }
        
        std::vector<std::string> lines;
        std::string line;
        
        // Read all lines
        while (std::getline(file, line)) {
            if (!line.empty()) {
                lines.push_back(line);
            }
        }
        file.close();
        
        if (lines.empty()) {
            std::cerr << "Error: Empty maze file" << std::endl;
            return false;
        }
        
        rows = lines.size();
        cols = lines[0].length();
        
        // Initialize maze and visited arrays
        maze.assign(rows, std::vector<int>(cols));
        visited.assign(rows, std::vector<bool>(cols, false));
        
        // Parse maze and find start/target positions
        bool startFound = false, targetFound = false;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maze[i][j] = lines[i][j] - '0';  // Convert char to int
                
                // Find start and target positions
                // Looking for open cells (0) on the border that could be start/target
                if (maze[i][j] == 0) {
                    if ((i == 0 || i == rows-1 || j == 0 || j == cols-1)) {
                        if (!startFound) {
                            start = {i, j};
                            startFound = true;
                        } else if (!targetFound) {
                            target = {i, j};
                            targetFound = true;
                        }
                    }
                }
            }
        }
        
        // If we couldn't find start/target on borders, find first and last open cells
        if (!startFound || !targetFound) {
            for (int i = 0; i < rows && !startFound; i++) {
                for (int j = 0; j < cols && !startFound; j++) {
                    if (maze[i][j] == 0) {
                        start = {i, j};
                        startFound = true;
                    }
                }
            }
            
            for (int i = rows-1; i >= 0 && !targetFound; i--) {
                for (int j = cols-1; j >= 0 && !targetFound; j--) {
                    if (maze[i][j] == 0 && !(i == start.first && j == start.second)) {
                        target = {i, j};
                        targetFound = true;
                    }
                }
            }
        }
        
        std::cout << "Maze loaded: " << rows << "x" << cols << std::endl;
        std::cout << "Start: (" << start.first << ", " << start.second << ")" << std::endl;
        std::cout << "Target: (" << target.first << ", " << target.second << ")" << std::endl;
        
        return startFound && targetFound;
    }
    
    // Check if a cell is valid to move into
    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && 
               maze[x][y] == 0 && !visited[x][y];
    }
    
    // Backtracking algorithm to solve maze
    bool solveMaze() {
        // Clear any previous state
        while (!path.empty()) path.pop();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                visited[i][j] = false;
            }
        }
        
        // Push start cell onto stack
        path.push(start);
        visited[start.first][start.second] = true;
        
        while (!path.empty()) {
            auto current = path.top();
            int x = current.first;
            int y = current.second;
            
            // Check if we reached the target
            if (x == target.first && y == target.second) {
                std::cout << "Path found!" << std::endl;
                return true;
            }
            
            // Look for unexplored adjacent cells
            bool foundNext = false;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (isValid(newX, newY)) {
                    path.push({newX, newY});
                    visited[newX][newY] = true;
                    foundNext = true;
                    break;  // Move to the next cell
                }
            }
            
            // If no unexplored adjacent cell found, backtrack
            if (!foundNext) {
                path.pop();
            }
        }
        
        std::cout << "No path exists from start to target!" << std::endl;
        return false;
    }
    
    // Print the maze
    void printMaze() {
        std::cout << "\nOriginal Maze:" << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == start.first && j == start.second) {
                    std::cout << "S ";
                } else if (i == target.first && j == target.second) {
                    std::cout << "T ";
                } else {
                    std::cout << (maze[i][j] == 1 ? "█ " : "  ");
                }
            }
            std::cout << std::endl;
        }
    }
    
    // Print the solution path
    void printSolution() {
        if (path.empty()) {
            std::cout << "No solution to print!" << std::endl;
            return;
        }
        
        // Create a copy of the maze for display
        std::vector<std::vector<char>> display(rows, std::vector<char>(cols));
        
        // Fill display with maze structure
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                display[i][j] = (maze[i][j] == 1) ? '#' : ' ';
            }
        }
        
        // Mark the path - convert stack to vector in correct order
        std::stack<std::pair<int, int>> tempStack = path;
        std::vector<std::pair<int, int>> pathVector;
        
        // First collect all elements
        while (!tempStack.empty()) {
            pathVector.push_back(tempStack.top());
            tempStack.pop();
        }
        
        // Reverse manually to get correct order (start to target)
        for (int i = 0; i < pathVector.size() / 2; i++) {
            std::swap(pathVector[i], pathVector[pathVector.size() - 1 - i]);
        }
        
        // Mark path on display
        for (const auto& pos : pathVector) {
            display[pos.first][pos.second] = '*';
        }
        
        // Mark start and target
        display[start.first][start.second] = 'S';
        display[target.first][target.second] = 'T';
        
        std::cout << "\nMaze Solution:" << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << display[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        std::cout << "\nPath coordinates:" << std::endl;
        for (int i = 0; i < pathVector.size(); i++) {
            std::cout << "(" << pathVector[i].first << ", " << pathVector[i].second << ")";
            if (i < pathVector.size() - 1) std::cout << " -> ";
        }
        std::cout << std::endl;
        std::cout << "Path length: " << pathVector.size() << " steps" << std::endl;
    }
};

int main() {
    MazeSolver solver;
    
    // Load the maze from file
    std::string filename = "maze0-1_input.txt";
    if (!solver.loadMaze(filename)) {
        return 1;
    }
    
    // Print the original maze
    solver.printMaze();
    
    // Solve the maze
    if (solver.solveMaze()) {
        solver.printSolution();
    }
    
    return 0;
}