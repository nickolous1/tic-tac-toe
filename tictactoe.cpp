
#include <iostream>
using namespace std;

void display(char board[]) {
    system("cls");
    cout << "     |     |     " << endl;
    cout << " " << board[1] << "   |  " << board[2] << "  |  " << board[3] << endl; 
    cout << "_____|_____|_____" << endl; 
    cout << "     |     |     " << endl;
    cout << " " << board[4] << "   |  " << board[5] << "  |  " << board[6] << endl; 
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << " " << board[7] << "   |  " << board[8] << "  |  " << board[9] << endl;
    cout << "     |     |     " << endl;

}

void turn(char mark, char board[]) {
    int move;
    display(board);
    cout << "Where do you want to go? (1-9)" << endl;
    cin >> move;

    if (board[move] == 'x' || board[move] == 'o' ) {
        cout << "please move somewhere else that isnt taken" << endl;
        turn(mark, board);
    }
    else {
        board[move] = mark;
    }
}

bool win(char board[], int count) {
    display(board);
    if (board[1] == board[2] && board[2] == board[3]) {
        cout << board[1] << " wins!" << endl;
        return true;
    }
    else if (board[4] == board[5] && board[5] == board[6]) {
        cout << board[4] << " wins!" << endl;
        return true;
    }
    else if (board[7] == board[8] && board[8] == board[9]) {
        cout << board[7] << " wins!" << endl;
        return true;
    }
    else if (board[1] == board[4] && board[4] == board[7]) {
        cout << board[1] << " wins!" << endl;
        return true;
    }
    else if (board[2] == board[5] && board[5] == board[8]) {
        cout << board[2] << " wins!" << endl;
        return true;
    }
    else if (board[3] == board[6] && board[6] == board[9]) {
        cout << board[3] << " wins!" << endl;
        return true;
    }
    else if (board[1] == board[5] && board[5] == board[9]) {
        cout << board[1] << " wins!" << endl;
        return true;
    }
    else if (board[3] == board[5] && board[5] == board[7]) {
        cout << board[3] << " wins!" << endl;
        return true;
    }
    else if (count == 5) {
        cout << "It's a tie" << endl; 
        return true; 
    }
    return false; 
}

int main()
{
    char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int count = 0;
    display(board);

    bool game = true;
    while (game) { 
        
        //p1 turn
        turn('x', board);
        count++;
        if (win(board,count)) {
            game = false; 
        }
    
        //p2 turn
        if (game) {
            turn('o', board);

            if (win(board, count)) {
                game = false;
            }
        }
    }
}

