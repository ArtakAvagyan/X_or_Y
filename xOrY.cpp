#include <iostream>

class Tic_Tac_Toe{
private:
    char board[3][3];
    int count;
    int x;
    int y;
    std::string player1;
    std::string player2;
public:
    Tic_Tac_Toe();
    void play ();
private:
    void win_game();
    bool check ();
    void step ();
    void display ();
    void play_again();
    void clear_board();
    bool is_empty_board ();
    bool is_full_board ();
    void set_name1 (std::string);
    void set_name2 (std::string);
    bool check_diagonal ();
    bool check_vertical ();
    bool check_horizontal ();
    bool valid_step();
};
bool Tic_Tac_Toe::valid_step()
{
    if(x > 2 || x < 0 || y > 2 || y < 0 ){return true;}
    if(board[x][y] == ' ' ){return false;}
    return true;
}

Tic_Tac_Toe::Tic_Tac_Toe(){
    clear_board();
    count = 0;
}
void Tic_Tac_Toe::win_game()
{
    if (count %2 == 1 ){
        std::cout << player1 +  " You Win Game Bro" << std::endl;
    }else {
        std::cout << player2 +  " You Win Game Bro" << std::endl;
    }
    if(count == 9)
    {
        std::cout<< "bro normal xaxa senc chexav !!!" << std::endl;
    }
}
void Tic_Tac_Toe::clear_board(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ' ;
        }    
    }
}

void Tic_Tac_Toe::step (){
    if (count %2 == 1 ){
        std::cout << player1 +  " Your turn ." << std::endl;
    }else {
        std::cout << player2 +  " Your turn ." << std::endl;
    }
    do{
    std::cout << "Please input coordinate";
    std::cin >> x >> y ;
    }while(valid_step());
    board[x][y] = count % 2 == 1 ? 'O' : 'X' ;
}

void Tic_Tac_Toe::display (){
    std::system("clear");
    std::cout<< "_______"<<std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "|" <<board[i][j] ;
        }
    std::cout << "\n_______" << std::endl;
    }
}
bool Tic_Tac_Toe::is_empty_board(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool Tic_Tac_Toe::is_full_board(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void Tic_Tac_Toe::play(){
    std::string tmp;
    std::cout << "Please input name of first player: ";
    std::cin >> tmp;
    set_name1(tmp);
    std::cout << "Please input name of second player: ";
    std::cin >> tmp;
    set_name2(tmp);
    //if ( !is_empty_board()){ play_again(); }
    
    while ( !check() ){
        step ();
        display ();
        count ++;
    }

    win_game();

    play_again();
}

    void Tic_Tac_Toe::play_again(){
        std::cout << "Do you want play again (input YES if you want)" <<std::endl;
        std::string tmp;
        std::cin >> tmp;
        if (tmp == "YES"){
            clear_board();
            play();
        }
        else 
        {
            return ;
        }
    }
    bool Tic_Tac_Toe::check_diagonal ()
    {
        if(board[0][0]== board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' '){return true;}
        else if(board[0][2]== board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' '){return true;}
        return false ;
    }
    bool Tic_Tac_Toe::check_horizontal ()
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            if(board[i][0]==board[i][1] && board[i][1]== board[i][2] && board[i][2] != ' '){return true;}
        }
        return false ;
    }
    bool Tic_Tac_Toe::check_vertical ()
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            if(board[0][i]==board[1][i] && board[1][i]== board[2][i] && board[2][i] != ' '){return true;}
        }
        return false ;
    }
    bool Tic_Tac_Toe::check()
    {
        return check_diagonal() || check_horizontal() || check_vertical()  || is_full_board();
    }
    void Tic_Tac_Toe::set_name1(std::string  name)
    {
        player1 = name;
    }
    void Tic_Tac_Toe::set_name2(std::string  name)
    {
        player2 = name;
    }

    int main()
    {
        Tic_Tac_Toe a;
        a.play();
    }