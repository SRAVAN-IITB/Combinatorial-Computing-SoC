from z3 import *

def solve_sudoku(input_board):
    # Create a 9x9 grid of integer variables
    board = [[Int(f"cell_{i}_{j}") for j in range(9)] for i in range(9)]
    
    # Set the constraints for each cell
    for i in range(9):
        for j in range(9):
            # Each cell must be between 1 and 9
            cell = board[i][j]
            cell_constraint = And(1 <= cell, cell <= 9)
            
            # If the input board has a non-zero value, fix the cell to that value
            if input_board[i][j] != 0:
                cell_constraint = And(cell_constraint, cell == input_board[i][j])
            
            # Add the constraint to the solver
            solver.add(cell_constraint)
    
    # Set the constraints for each row
    for i in range(9):
        row = [board[i][j] for j in range(9)]
        solver.add(Distinct(row))
    
    # Set the constraints for each column
    for j in range(9):
        col = [board[i][j] for i in range(9)]
        solver.add(Distinct(col))
    
    # Set the constraints for each 3x3 sub-grid
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            subgrid = [board[row][col] for row in range(i, i + 3) for col in range(j, j + 3)]
            solver.add(Distinct(subgrid))
    
    # Check if there is a satisfying solution
    if solver.check() == sat:
        model = solver.model()
        solution = [[model.evaluate(board[i][j]).as_long() for j in range(9)] for i in range(9)]
        return solution
    
    return -1

# # Example input
# input_board = [
#     [5, 3, 0, 0, 7, 0, 0, 0, 0],
#     [6, 0, 0, 1, 9, 5, 0, 0, 0],
#     [0, 9, 8, 0, 0, 0, 0, 6, 0],
#     [8, 0, 0, 0, 6, 0, 0, 0, 3],
#     [4, 0, 0, 8, 0, 3, 0, 0, 1],
#     [7, 0, 0, 0, 2, 0, 0, 0, 6],
#     [0, 6, 0, 0, 0, 0, 2, 8, 0],
#     [0, 0, 0, 4, 1, 9, 0, 0, 5],
#     [0, 0, 0, 0, 8, 0, 0, 7, 9]
# ]

# Get the input as a space-separated string
input_board = input("Enter the elements of the 2D array in row-major form (space-separated): ")

# Split the input string into individual elements
elements = input_board.split()

# Calculate the number of rows and columns based on the number of elements
rows = 9
columns = len(elements) // rows

# Create the 2D array
input_board = []

# Populate the 2D array
for i in range(rows):
    row = []
    for j in range(columns):
        element = int(elements[i * columns + j])
        row.append(element)
    input_board.append(row)

# Print the 2D array
for row in input_board:
    print(row)

print("")

# Create a solver instance
solver = Solver()

# Solve the Sudoku problem
solution = solve_sudoku(input_board)

# Print the solution
if solution != -1:
    for row in solution:
        print(row)
else:
    print("No solution exists.")
#   -Sravan K Suresh {22B3936}
