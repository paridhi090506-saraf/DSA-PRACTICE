#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for(int i=0;i<9;i++)
    {
        // Check row
        if(board[row][i]==c)
            return false;

        // Check column
        if(board[i][col]==c)
            return false;

        // Check 3x3 box
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(board[row][col]=='.')
            {
                for(char c='1'; c<='9'; c++)
                {
                    if(isValid(board,row,col,c))
                    {
                        board[row][col]=c;

                        if(solve(board))
                            return true;

                        board[row][col]='.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board(9, vector<char>(9));

    cout<<"Enter Sudoku (. for empty):\n";

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    }

    solve(board);

    cout<<"\nSolved Sudoku:\n";

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}