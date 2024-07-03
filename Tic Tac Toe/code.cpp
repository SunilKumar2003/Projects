#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string p1, p2;
char token = 'x';
int row, column;
bool draw = false;

void f1()
{
    cout << "   | " << "  | " << '\n';
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << '\n';
    cout << "___|" << "___|" << "___" << '\n';
    cout << "   | " << "  | " << '\n';
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << '\n';
    cout << "___|" << "___|" << "___" << '\n';
    cout << "   | " << "  | " << '\n';
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << '\n';
    cout << "   | " << "  | " << '\n';
}

void f2()
{
    int digit;

    if (token == 'x')
    {
        cout << p1 << " please enter : ";
        cin >> digit;
    }
    else if (token == '0')
    {
        cout << p2 << " please enter : ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else
    {
        cout << "Invalid!!" << '\n';
    }

    if (token == 'x' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = 'x';
        token = '0';
    }
    else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'x';
    }
    else
    {
        cout << "there is no empty space!" << '\n';
    }
}

bool f3()
{
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }
    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[2][0] == space[1][1] && space[2][0] == space[0][2]))
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}

int main()
{

    cout << "Enter the name of first player : ";
    getline(cin, p1);
    cout << "Enter the name of second player :";
    getline(cin, p2);
    cout << p1 << " is player1 so he/she will play first\n";
    cout << p2 << " is player2 so he/she will play second\n";

    while (!f3())
    {
        f1();
        f2();
        f3();
    }
    f1();
    if (token == '0' && draw == false)
    {
        cout << p1 << " Wins" << '\n';
    }
    else if (token == 'x' && draw == false)
    {
        cout << p2 << " Wins" << '\n';
    }
    else
    {
        cout << "It's a Draw" << '\n';
    }
}