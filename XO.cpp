#include <iostream>
#include <ctime>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void printBoard(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {

        cout << "-------------" << endl;
        cout << "| ";
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j];
            if (j < COLS)
            {
                cout << " | ";
            }
        }
        cout << endl;
    }
    cout << "-------------" << endl;
}

bool checkWin(char board[ROWS][COLS], char player)
{
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool checkDraw(char board[ROWS][COLS])
{
    if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[1][0] != ' ' && board[1][1] != ' ' && 
        board[1][2] != ' ' && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') return true;
    return false;
}

void playGame()
{
    int row, col;
    char player = 'X';
    char board[ROWS][COLS]
      { {' ',' ',' '}, 
        {' ',' ',' '}, 
        {' ',' ',' '} };

    for (int i = 0; i < ROWS; i++)
    {
        
        cout << "-------------" << endl;
        cout << "| ";
        for (int j = 0; j < COLS;j++)
        {
            cout << board[i][j];
            if (j < COLS)
            {
                cout << " | ";
            }
        }
        cout << endl;

    }
    cout << "-------------" << endl;

    while (true)
    {
        cout << "Ходит игрок " << player << endl;
        cout << "Куда ходит игрок? Введите значение от 1 до 3 для строчки и колонки:";
        cin >> row >> col;
        --row, --col;
        
        if (board[row][col] != ' ')
        {
            cout << "Походите в другое место" << endl;
            continue;
        }
        board[row][col] = player;
        cout << endl;
        printBoard(board);

        if (checkWin(board, player))
        {
            cout << "Игрок " << player << " победил! Поздравим нашего слона" << endl;
            break;
        }
        if (checkDraw(board))
        {
            cout << "Ничья. Перемоги не буде" << endl;
            break;
        }

        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    playGame();
}