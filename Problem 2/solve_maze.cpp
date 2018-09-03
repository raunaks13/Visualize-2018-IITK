#include <bits/stdc++.h>
using namespace std;
// #define ROW 8
// #define COL 8
 
// struct Point
// {
//     int x;
//     int y;
// };
 
// // An Data Structure for queue used in BFS
// struct queueNode
// {
//     Point pt;  // The cordinates of a cell
//     int dist;  // cell's distance of from the source
// };
 
// // check whether given cell (row, col) is a valid
// // cell or not.
// bool isValid(int row, int col)
// {
//     // return true if row number and column number
//     // is in range
//     return (row >= 0) && (row < ROW) &&
//            (col >= 0) && (col < COL);
// }

// // These arrays are used to get row and column
// // numbers of 4 neighbours of a given cell
// int rowNum[] = {-1, 0, 0, 1};
// int colNum[] = {0, -1, 1, 0};
 
// // function to find the shortest path between
// // a given source cell to a destination cell.
// int BFS(int mat[][COL], Point src, Point dest)
// {
//     // check source and destination cell
//     // of the matrix have value 1
//     if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
//         return INT_MAX;
 
//     bool visited[ROW][COL];
//     memset(visited, false, sizeof visited);
     
//     // Mark the source cell as visited
//     visited[src.x][src.y] = true;
 
//     // Create a queue for BFS
//     queue<queueNode> q;
     
//     // distance of source cell is 0
//     queueNode s = {src, 0};
//     q.push(s);  // Enqueue source cell
 
//     // Do a BFS starting from source cell
//     while (!q.empty())
//     {
//         queueNode curr = q.front();
//         Point pt = curr.pt;
 
//         // If we have reached the destination cell,
//         // we are done
//         if (pt.x == dest.x && pt.y == dest.y)
//             return curr.dist;
 
//         // Otherwise dequeue the front cell in the queue
//         // and enqueue its adjacent cells

//         q.pop();
 
//         for (int i = 0; i < 4; i++)
//         {
//             int row = pt.x + rowNum[i];
//             int col = pt.y + colNum[i];
             
//             // if adjacent cell is valid, has path and
//             // not visited yet, enqueue it.
//             if (isValid(row, col) && mat[row][col] && 
//                !visited[row][col])
//             {
//                 // mark cell as visited and enqueue it
//                 visited[row][col] = true;

//                 queueNode Adjcell = { {row, col},
//                                       curr.dist + 1 };
//                 q.push(Adjcell);
//             }
//         }
//     }
 
//     //return -1 if destination cannot be reached
//     return INT_MAX;
// }
 
// int main()
// {
//     int mat[ROW][COL] =
//     {
//         { 1, 0, 1, 1, 1, 1, 0, 1},
//         { 1, 0, 1, 0, 1, 1, 1, 0},
//         { 1, 1, 1, 0, 1, 1, 0, 1},
//         { 0, 0, 0, 0, 1, 0, 1, 1},
//         { 1, 1, 1, 0, 1, 1, 1, 0},
//         { 1, 0, 1, 1, 1, 1, 1, 1},
//         { 1, 0, 0, 0, 0, 0, 0, 1},
//         { 1, 0, 1, 1, 1, 1, 0, 1}
//     };
 
//     Point source = {0, 0};
//     Point dest = {7, 7};
 
//     int dist = BFS(mat, source, dest);
 
//     if (dist != INT_MAX)
//         cout << "Shortest Path is " << dist + 1 << endl;
//     else
//         cout << "Shortest Path doesn't exist";
 
//     return 0;
// }

int visited[8][8];
int path[64][2];
int f;

int isPath(int x, int y, int maze[8][8])
{
    //if current location is outside the maze
    if ( x<0 || x>= 8 || y <0 || y >= 8 )
        return 0;
    //if current location is a "Wall"
    else if (maze[x][y] == 0)
        return 0;
    //if current location is already visited
    else if (visited[x][y] == 1)  
        return 0;
        
    //current location is exit
    else if (x == 7 && y == 7)
    {   
        return 1;
    }
    
    else
    {  
        //mark the location is visited
        visited[x][y] = 1;
        //print out the position 
        // cout << "(" << x << "," << y << ") ";	     
        
        //if there is a path from one of the neighbors then there 
        //is a path from current location
        if (isPath(x-1,y, maze) == 1)
        {
            path[f][0] = x-1;
            path[f][1] = y;
            f++;
            return 1;
        }
        else if(isPath(x+1, y, maze) == 1)
        {
            path[f][0] = x+1;
            path[f][1] = y;
            f++;
            return 1;
        }
        else if(isPath(x, y-1, maze) == 1)
        {
            path[f][0] = x;
            path[f][1] = y-1;
            f++;
            return 1;
        }
        else if(isPath(x, y+1, maze) == 1)
        {
            path[f][0] = x;
            path[f][1] = y+1;
            f++;
            return 1;
        }
        else
            return 0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    
    cout << "strt";
    int maze[8][8] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1},
        { 1, 0, 1, 0, 1, 1, 1, 0},
        { 1, 1, 1, 0, 1, 1, 0, 1},
        { 0, 0, 0, 0, 1, 0, 1, 1},
        { 1, 1, 1, 0, 1, 1, 1, 0},
        { 1, 0, 1, 1, 1, 1, 1, 1},
        { 1, 0, 0, 0, 0, 0, 0, 1},
        { 1, 0, 1, 1, 1, 1, 0, 1}
    };

    for(int i = 0;i<8;i++)
    {
        for(int j = 0;j<8;j++)
            visited[i][j] = 0;
    }
    
    for(int i = 0;i<64;i++)
    {
        path[i][0] = 0;
        path[i][1] = 0;
    }

    int a = isPath(0, 0, maze);
    cout << a;

    for(int i = 0;i<64;i++)
    {
        if(path[i][0] == 0 && path[i][1] == 0)
            break;
        cout << "(" << path[i][0] << "," << path[i][1] << ") ";
    }
}