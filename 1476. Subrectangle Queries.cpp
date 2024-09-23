#include <iostream>
#include <vector>
using namespace std;
class SubrectangleQueries
{
public:
    vector<vector<int>> rect;
    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        rect = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                rect[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return rect[row][col];
    }
};

int main()
{
    vector<vector<int>> rectangle={{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
    SubrectangleQueries subrectangleQueries = /*new*/ SubrectangleQueries(rectangle);
    subrectangleQueries.getValue(0, 2); // return 1
    // The initial rectangle (4x3) looks like:
    // 1 2 1
    // 4 3 4
    // 3 2 1
    // 1 1 1
    subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
    // After this update the rectangle looks like:
    // 5 5 5
    // 5 5 5
    // 5 5 5
    // 5 5 5
    subrectangleQueries.getValue(0, 2); // return 5
    subrectangleQueries.getValue(3, 1); // return 5
    subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
    // After this update the rectangle looks like:
    // 5   5   5
    // 5   5   5
    // 5   5   5
    // 10  10  10
    subrectangleQueries.getValue(3, 1); // return 10
    subrectangleQueries.getValue(0, 2); // return 5
    return 0;
}