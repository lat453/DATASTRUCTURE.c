#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

typedef struct {
    int **grid;
    int rows, cols;
} Grid;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

Grid* createGrid(int rows, int cols) {
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    grid->rows = rows;
    grid->cols = cols;
    grid->grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid->grid[i] = (int *)malloc(cols * sizeof(int));
    }
    return grid;
}

void freeGrid(Grid *grid) {
    for (int i = 0; i < grid->rows; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

int isValid(int x, int y, Grid *grid, int **visited) {
    return x >= 0 && y >= 0 && x < grid->rows && y < grid->cols && grid->grid[x][y] != 1 && visited[x][y] == 0;
}

Path* findShortestPath(Grid *grid, Point start, Point goal) {
    int **visited = (int **)malloc(grid->rows * sizeof(int *));
    for (int i = 0; i < grid->rows; i++) {
        visited[i] = (int *)malloc(grid->cols * sizeof(int));
        for (int j = 0; j < grid->cols; j++) {
            visited[i][j] = 0;
        }
    }
    
    int **dist = (int **)malloc(grid->rows * sizeof(int *));
    for (int i = 0; i < grid->rows; i++) {
        dist[i] = (int *)malloc(grid->cols * sizeof(int));
        for (int j = 0; j < grid->cols; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    dist[start.x][start.y] = 0;
    visited[start.x][start.y] = 1;

    Point *queue = (Point *)malloc(grid->rows * grid->cols * sizeof(Point));
    int front = 0, rear = 0;
    queue[rear++] = start;

    while (front < rear) {
        Point curr = queue[front++];
        
        for (int i = 0; i < 4; i++) {
            int newX = curr.x + directions[i][0];
            int newY = curr.y + directions[i][1];
            
            if (isValid(newX, newY, grid, visited)) {
                visited[newX][newY] = 1;
                dist[newX][newY] = dist[curr.x][curr.y] + 1;
                queue[rear++] = (Point){newX, newY};
                
                if (newX == goal.x && newY == goal.y) {
                    free(queue);
                    for (int i = 0; i < grid->rows; i++) {
                        free(visited[i]);
                        free(dist[i]);
                    }
                    free(visited);
                    free(dist);
                    Path *path = (Path *)malloc(sizeof(Path));
                    path->points = (Point *)malloc(dist[goal.x][goal.y] * sizeof(Point));
                    path->size = dist[goal.x][goal.y];
                    Point p = goal;
                    for (int i = path->size - 1; i >= 0; i--) {
                        path->points[i] = p;
                        for (int j = 0; j < 4; j++) {
                            int prevX = p.x - directions[j][0];
                            int prevY = p.y - directions[j][1];
                            if (prevX >= 0 && prevY >= 0 && prevX < grid->rows && prevY < grid->cols && dist[prevX][prevY] == dist[p.x][p.y] - 1) {
                                p = (Point){prevX, prevY};
                                break;
                            }
                        }
                    }
                    return path;
                }
            }
        }
    }
    
    free(queue);
    for (int i = 0; i < grid->rows; i++) {
        free(visited[i]);
        free(dist[i]);
    }
    free(visited);
    free(dist);
    return NULL;
}

void freePath(Path *path) {
    free(path->points);
    free(path);
}

void printPath(Path *path) {
    if (path) {
        for (int i = 0; i < path->size; i++) {
            printf("(%d, %d) ", path->points[i].x, path->points[i].y);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter grid size (rows cols): ");
    scanf("%d %d", &rows, &cols);
    
    Grid *grid = createGrid(rows, cols);
    
    printf("Enter the grid (0 for empty, 1 for obstacle):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid->grid[i][j]);
        }
    }
    
    Point start, goal;
    printf("Enter start point (x y): ");
    scanf("%d %d", &start.x, &start.y);
    printf("Enter goal point (x y): ");
    scanf("%d %d", &goal.x, &goal.y);

    Path *path = findShortestPath(grid, start, goal);
    printPath(path);
    
    if (path) freePath(path);
    freeGrid(grid);
    
    return 0;
}
