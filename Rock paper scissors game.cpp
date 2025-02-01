#include <iostream>
#include"MyLibrary.h"
#include<cmath>
#include<cstdlib>
enum enGameChoice
{
    Stone=1,
    Paper=2,
    Scissors=3

};
enum enWinner
{
    Player=1 ,Computer=2 ,Draw=3

};
struct stGameResult
{
    short GameRounds = 0;
    short PlayWinTimes = 0;
    short ComputerWinTime = 0;
    short DrawTime = 0;
    enWinner GameWinner;
    string Winner = ""; 
};
struct stRoundInf
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};
enGameChoice ReadPlayerChoice() {
    short Choice = 1;
    do
    {
        cout << "\nYour Choice : [1]:Stone,[2]:Paper,[3]:Scissors ?";
        cin >> Choice;
    } while (Choice<1||Choice>3);
    return (enGameChoice)Choice;
}
enGameChoice ReadComputerChoice() {

    return (enGameChoice)MyLibrary::GenerateKeysRandom::RandomNumber(1, 3);

}

enWinner WhoWinTheRound(stRoundInf RoundInf) {

    if (RoundInf.PlayerChoice == RoundInf.ComputerChoice) {
        return enWinner::Draw;
    }
    switch (RoundInf.PlayerChoice)
    {
    case enGameChoice::Stone:
        if (RoundInf.ComputerChoice == enGameChoice::Paper) {
            return enWinner::Computer;
        }
        break;

    case enGameChoice::Paper:
        if (RoundInf.ComputerChoice == enGameChoice::Scissors) {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInf.ComputerChoice == enGameChoice::Stone) {
            return enWinner::Computer;
        }
        break;
    }
    return enWinner::Player;
}
string WinnerName(enWinner winner) {

    string  arrWinnerName[3] = { "Player","Computer","No Winner" };
    return arrWinnerName[winner - 1];
}


short ReadHowManyRound() {
    short GameRound = 1;
    do
    {
        cout << "How Many Rounds 1 to 10   :\n";
        cin >> GameRound;
    } while (GameRound<1||GameRound>10);
    return GameRound;
}
string ChoiceName(enGameChoice Choice) {
    string arrGameChoice[3] = {"Stone","Paper","Scissors"};
    return arrGameChoice[Choice - 1]; 
}
void SetWinnerScreenColor(enWinner winner) {
    switch (winner) {
    case enWinner::Player:
        system("color 2F"); //turn screen to Green
        break;
    case enWinner::Computer:
        system("color 4F"); //turn screen to Red   
        cout << "\a";
    break; default:
        system("color 6F"); //turn screen to Yellowbreak; 
    }
}
void PrintRoundResults(stRoundInf RoundInf) {
    cout << "\n-----------Round [" << RoundInf.RoundNumber << "]-------------\n\n";
    cout << "Player Choice : " << ChoiceName(RoundInf.PlayerChoice) << endl;
    cout << "Computer Choice : " << ChoiceName(RoundInf.ComputerChoice) << endl;
    cout << "Round Winner : [" << RoundInf.WinnerName << "]\n";
    cout << "-----------------------------\n" << endl;
    SetWinnerScreenColor(RoundInf.Winner);
}

enWinner WhoWinTheGame(short PlayWinTimes, short ComputerWinTime) {

    if (PlayWinTimes > ComputerWinTime)
        return enWinner::Player;
    else if (ComputerWinTime > PlayWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}
stGameResult FillGameResults(short GameRounds, short PlayWinTimes ,short ComputerWinTime , short DrawTime )
{
    stGameResult GameResult;
    GameResult.GameRounds = GameRounds;
    GameResult.PlayWinTimes = PlayWinTimes;
    GameResult.ComputerWinTime = ComputerWinTime;
    GameResult.DrawTime = DrawTime;
    GameResult.GameWinner = WhoWinTheGame(PlayWinTimes, ComputerWinTime);
    GameResult.Winner = WinnerName(GameResult.GameWinner);
    return GameResult;
}
string Tabs(short Num) {
    string tab = "";
    for (int  i = 1; i <Num; i++)
    {
        tab += "\t";
        cout << tab;
    }
    
    return tab;
}
void ShowGameOverScreen() {
    cout<<Tabs(2)<< "--------------------------------------------------------\n\n";
    cout<<Tabs(2)<< "                     +++ G a m e O v e r +++            \n\n";
    cout<<Tabs(2)<< "--------------------------------------------------------\n\n";

}
stGameResult PlayGame(short HowMany) {

    stRoundInf RoundInf;
    short PlayWinTimes = 0, ComputerWinTime = 0, DrawTime = 0;
    for (short GameRound = 1; GameRound <= HowMany; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] Begins : \n";
        RoundInf.RoundNumber = GameRound;
        RoundInf.PlayerChoice = ReadPlayerChoice();
        RoundInf.ComputerChoice = ReadComputerChoice();
        RoundInf.Winner = WhoWinTheRound(RoundInf);
        RoundInf.WinnerName = WinnerName(RoundInf.Winner);

        if (RoundInf.Winner == enWinner::Player) {
            PlayWinTimes++;
        }
        else if (RoundInf.Winner == enWinner::Computer)
        {
            ComputerWinTime++;

        }
        else {
            DrawTime++;
        }
        PrintRoundResults(RoundInf);
    }
    return FillGameResults(HowMany,PlayWinTimes,ComputerWinTime,DrawTime);

}
void ShowFinalGameResult(stGameResult GameResults) {
    cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 Win times  : " << GameResults.PlayWinTimes << endl;
    cout << Tabs(2) << "Computer Win times : " << GameResults.ComputerWinTime << endl;
    cout << Tabs(2) << "Draw times         : " << GameResults.DrawTime << endl;
    cout << Tabs(2) << "Final Winner       : " << GameResults.Winner << endl;
    cout << Tabs(2) << "___________________________________________________________\n";
    SetWinnerScreenColor(GameResults.GameWinner);
}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
void StartGames() {
    char playAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResult GameResults = PlayGame(ReadHowManyRound());
        ShowGameOverScreen();
        ShowFinalGameResult(GameResults);
        cout << endl << Tabs(3) << "Do You Want to Play again ! Y/N ?";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
}

int main(){
        srand((unsigned)time(NULL));
        StartGames();

}