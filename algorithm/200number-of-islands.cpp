#include <iostream>
#include <vector>
using namespace std;


class Point {
public:
    Point(int _x, int _y):x(_x),y(_y){}
    int x,y;
};


int colorVec(vector<vector<char> >& grid, int i, int j) {
    vector<Point> stack;
    stack.push_back(Point(i, j));
    while (!stack.empty()) {
        Point p = stack.back();
        stack.pop_back();
        int x = p.x;
        int y = p.y;
        //cout << "stack:" << stack.size() << ",x=" <<x << ",y=" << y << endl;
        grid[x][y] = '2';
        if (x-1 >= 0 && grid[x-1][y] == '1') {
            stack.push_back(Point(x-1, y));
        }
        if (x+1 < grid.size() && grid[x+1][y] == '1') {
            stack.push_back(Point(x+1, y));
        }
        if (y+1 < grid[x].size() && grid[x][y+1] == '1') {
            stack.push_back(Point(x, y+1));
        }
        if (y-1 >= 0 && grid[x][y-1] == '1') {
            stack.push_back(Point(x, y-1));
        }
        
    }
}

void printVec(vector<vector<char> >& grid)
{
    for (int i =0; i< grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl;
}


int numIslands(vector<vector<char> >& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                count++;
                colorVec(grid, i, j);
                printVec(grid);
            }
        }
    }
    return count;
}

int main()
{
    vector<std::vector<char> > vv;
    std::vector<char> v;
    v.push_back('1');
    v.push_back('1');
    v.push_back('1');
    vv.push_back(v);

    std::vector<char> v2;
    v2.push_back('0');
    v2.push_back('1');
    v2.push_back('0');
    vv.push_back(v2);

    std::vector<char> v3;
    v3.push_back('1');
    v3.push_back('1');
    v3.push_back('1');
    vv.push_back(v3);
    cout << numIslands(vv) << endl;

    return 0;
}