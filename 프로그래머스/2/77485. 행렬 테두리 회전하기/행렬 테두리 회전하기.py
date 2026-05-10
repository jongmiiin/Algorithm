# def turn(ex_grid, grid, y1, x1, y2, x2):
#     mn = grid[y1][x1]
#     temp = grid[y1][x1]
#     for x in range(x1+1, x2+1):
#         grid[y1][x] = temp
#         temp = ex_grid[y1][x]
#         mn = min(mn, temp)
        
#     for y in range(y1+1, y2+1):
#         grid[y][x2] = temp
#         temp = ex_grid[y][x2]
#         mn = min(mn, temp)
        
#     for x in range(x2-1, x1-1, -1):
#         grid[y2][x] = temp
#         temp = ex_grid[y2][x]
#         mn = min(mn, temp)
        
#     for y in range(y2-1, y1-1, -1):
#         grid[y][x1] = temp
#         temp = ex_grid[y][x1]
#         mn = min(mn, temp)
        
    
#     return mn

def turn(grid, y1, x1, y2, x2):
    mn = grid[y1][x1]
    push_temp = grid[y1][x1]
    store_temp = 0
    for x in range(x1+1, x2+1):
        store_temp = grid[y1][x]
        grid[y1][x] = push_temp
        push_temp = store_temp
        mn = min(mn, push_temp)
        
    for y in range(y1+1, y2+1):
        store_temp = grid[y][x2]
        grid[y][x2] = push_temp
        push_temp = store_temp
        mn = min(mn, push_temp)
        
    for x in range(x2-1, x1-1, -1):
        store_temp = grid[y2][x]
        grid[y2][x] = push_temp
        push_temp = store_temp
        mn = min(mn, push_temp)
        
    for y in range(y2-1, y1-1, -1):
        store_temp = grid[y][x1]
        grid[y][x1] = push_temp
        push_temp = store_temp
        mn = min(mn, push_temp)
        
    
    return mn

def solution(rows, columns, queries):
    answer = []
    grid = [[i+j*columns for i in range(1,columns+1)] for j in range(rows)]
    
    for query in queries:
        mn = turn(grid, query[0]-1, query[1]-1, query[2]-1, query[3]-1);
        # print(*grid)
        answer.append(mn)
    return answer