#include "game.h"
using namespace std;

Game :: Game(){
	
	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;
	
	players[0]="Rohit";
	players[1]="Virat";
	players[2]="Dhoni";
	players[3]="Rayudu";
	players[4]="Sachin";
	players[5]="Hardik";
	players[6]="Dravid";
	players[7]="Bumrah";
	players[8]="Nattu";
	players[9]="Siraj";
	players[10]="Curran";
	
	isFirstInnings=false;
	teamA.name="Team-A";
	teamB.name="Team-B";
}

void Game :: welcome(){
	cout<<GAP<<"-------------------------------------\n";
	cout<<GAP<<"|===============CRIC-IN==============\n";
	cout<<GAP<<"|                                   |\n";
	cout<<GAP<<"|  Welcome to Virtual Cricket Game  |\n";
	cout<<GAP<<"-------------------------------------\n\n";
	cout<<GAP<<"---------------------------------------------------\n";
	cout<<GAP<<"|===================INSTRUCTIONS==================|\n";
	cout<<GAP<<"---------------------------------------------------\n";
	cout<<GAP<<"|                                                 |\n";
	cout<<GAP<<"| 1. Create 2 teams(Team A and Team B with 4      |\n";
	cout<<GAP<<"|    players each) from a given pool of 11 players|\n";
	cout<<GAP<<"| 2. Lead the toss and decide the choice of play. |\n";
	cout<<GAP<<"| 3. Each innings will be of 6 balls              |\n";
	cout<<GAP<<"---------------------------------------------------\n";
}

void Game::showAllPlayers(){
	
	cout<<"\n\n"<<GAP<<"-----------------------------------------\n";
	cout<<GAP<<"|=============Pool of Players===========|\n";
	cout<<GAP<<"-----------------------------------------\n";
	
	for (size_t i=0;i<11;++i)
    {
        cout <<"\n\t\t\t\t\t\t\t\t\t\t              ["<<i<<"] "<< players[i];
	}
}

int Game::takeIntegerInput(){
	int n;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid Input! Pls Enter Valid Input";
	}
	return n;
}

void Game::selectPlayers(){
	cout<<GAP<<"---------------------------------------------------\n";
	cout<<GAP<<"|============CREATE TEAM-A AND TEAM-B=============|\n";
	cout<<GAP<<"---------------------------------------------------\n";
	
	for(int i=0;i<playersPerTeam;i++)
	{
		teamASelection:
		cout<<endl<<GAP<<"Select Player "<<i+1<<" of Team A - ";
		int playerIndexTeamA=takeIntegerInput();
		
		if(playerIndexTeamA<0 || playerIndexTeamA>10){
			cout<<endl<<GAP<<"Pls select from the given players\n";
			goto teamASelection;
		} else if(!(validateSelectedPlayer(playerIndexTeamA))) {
			cout<<"\n\nPlayer has been already selected. Pls select another player\n\n";
			goto teamASelection;
		} else {
			Player teamAPlayer;
			teamAPlayer.id=playerIndexTeamA;
			teamAPlayer.name=players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
		}
		teamBSelection:
			cout<<endl<<GAP<<"Select Player "<<i+1<<" of Team B - ";
			int playerIndexTeamB=takeIntegerInput();
		
		if(playerIndexTeamB<0 || playerIndexTeamB>10){
			cout<<endl<<GAP<<"Pls select from the given players\n";
			goto teamBSelection;
		} else if(!(validateSelectedPlayer(playerIndexTeamB))) {
			cout<<"\n\nPlayer has been already selected. Pls select another player\n\n";
			goto teamBSelection;
		} else {
			Player teamBPlayer;
			//teamBPlayer.id=playerIndexTeamB;
			teamBPlayer.name=players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);
		}
	}
}

bool Game::validateSelectedPlayer(int index){
	int n;
	vector<Player> players;
	players=teamA.players;
	n=players.size();
	for(int i=0;i<n;i++){
		if(players[i].id==index){
			return false;
		}
	}
	players=teamB.players;
	n=players.size();
	for(int i=0;i<n;i++){
		if(players[i].id==index){
			return false;
		}
	}
	return true;
	
}

void Game::showTeamPlayers(){
	vector<Player> teamAPlayers=teamA.players;
	vector<Player> teamBPlayers=teamB.players;
	
	cout<<GAP<<"--------------------------\t\t--------------------------\n";
	cout<<GAP<<"|======== Team-A ========|\t\t|======== Team-B ========|\n";
	cout<<GAP<<"--------------------------\t\t--------------------------\n";
	for(int i=0;i<playersPerTeam;i++){
		cout<<GAP<<"\t[" << i << "] "  << teamAPlayers[i].name << "\t\t\t";
		cout<< "\t[" << i << "] " << teamBPlayers[i].name<<endl;
	}
	cout<<GAP<<"--------------------------\t\t--------------------------\n\n";
	
}
void Game::toss(){
	cout<<GAP<<"-----------------------------------------\n";
	cout<<GAP<<"|============== Let's Toss =============|\n";
	cout<<GAP<<"-----------------------------------------\n\n";
	cout<<GAP<<"Tossing the coin...\n\n";
	
	srand(time(0));
	int tossResult=rand()%2;
	if(tossResult==0) {
	cout<<GAP<<"Team-A won the Toss\n\n";
	tossChoice(teamA);
	} else {
	cout<<GAP<<"Team-B won the Toss\n\n";
	tossChoice(teamB);
	}
}

void Game::tossChoice(Team tossWinnerTeam)
{
	cout<<GAP<<"Enter 1 to bat or 2 to bowl first. "<<endl<<GAP<<" 1.Bat"<<endl<<GAP<<" 2.Bowl\n"<<GAP;
	int tossInput=takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(tossInput){
		case 1:
			cout<<endl<<GAP<<tossWinnerTeam.name<<" won the toss and elected to bat first\n\n";
			if(tossWinnerTeam.name.compare("Team-A")==0){
				battingTeam=&teamA;
				bowlingTeam=&teamB;
			} else {
				battingTeam=&teamB;
				bowlingTeam=&teamA;
			}
			break;
		case 2:
			cout<<endl<<GAP<<tossWinnerTeam.name<<" won the toss and elected to bowl first\n\n";
			if(tossWinnerTeam.name.compare("Team-A")==0){
				battingTeam=&teamB;
				bowlingTeam=&teamA;
			} else {
				battingTeam=&teamA;
				bowlingTeam=&teamB;
			}
			break;
		default:
			cout<<"\nInvalid Input. Pls try again\n\n";
			tossChoice(tossWinnerTeam);
			break;
	}
	
}

void Game :: startFirstInnings()
{
	cout<<GAP<<"\t\t||| FIRST INNINGS STARTS |||";
	isFirstInnings=true;
	initializePlayers();
	playInnings();
}

void Game :: initializePlayers()
{
	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];
	
	cout<<endl<<endl<<GAP<<battingTeam->name<<" - "<<batsman->name<<" is batting.";
	cout<<endl<<GAP<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling."<<endl<<endl;	
	
}

void Game :: playInnings()
{
	for(int i=0;i<maxBalls;i++)
	{
		cout<<GAP<<"Press Enter to bowl...";
		getchar();
		bat();
		if(!(validateInnningsScore()))
		{
			break;
		}
	}
}
void Game :: bat()
{
	srand(time(NULL));
	int runsScored=rand()%7;
	
	batsman->runsScored=batsman->runsScored+runsScored;
	batsman->ballsPlayed=batsman->ballsPlayed+1;
	battingTeam->totalRunsScored=battingTeam->totalRunsScored+runsScored;
	
	bowler->ballsBowled=bowler->ballsBowled+1;
	bowler->runsGiven=bowler->runsGiven+runsScored;
	bowlingTeam->totalBallsBowled=bowlingTeam->totalBallsBowled+1;
	
	if(runsScored!=0)
	{
		cout<<endl<<GAP<<bowler->name<<" to "<<batsman->name<<" "<<runsScored<<" runs!"<<endl;
		showGameScoreCard();
	} else {
		cout<<endl<<GAP<<bowler->name<<" to "<<batsman->name<<" OUT!\n";
		
		battingTeam->wicketsLost=battingTeam->wicketsLost+1;
		bowler->wicketsTaken=bowler->wicketsTaken+1;
		
		showGameScoreCard();
		
		int nextPlayerIndex=battingTeam->wicketsLost;
		batsman=&battingTeam->players[nextPlayerIndex];
		
	}
}

bool Game :: validateInnningsScore()
{
	if(isFirstInnings)
	{
		if(battingTeam->wicketsLost==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls)
		{
			cout<<endl<<GAP<<"\t\t||| FIRST INNINGS ENDS |||\n\n";
			cout<<GAP<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "<<battingTeam->wicketsLost<<" ("<<battingTeam->totalBallsBowled<<")\n\n";
			cout<<GAP<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored+1<<" to win the match\n\n";
			return false;
		}	
	} 
	return true;
}

void Game :: showGameScoreCard()
{
	cout<<endl<<GAP<<"-------------------------------------------------------------------";
	cout<<endl<<GAP<<"\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")";
	cout<<" | "<<batsman->name<<" "<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<")\t";
	cout<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" "<<bowler->wicketsTaken;
	cout<<endl<<GAP<<"-------------------------------------------------------------------\n";
}

void Game :: startSecondInnings()
{
	cout<<GAP<<"\t\t||| SECOND INNINGS STARTS |||";
	isFirstInnings=false;
	if(battingTeam->name.compare("Team-A")==0)
	{
		battingTeam=&teamB;
		bowlingTeam=&teamA;
	} else {
		battingTeam=&teamA;
		bowlingTeam=&teamB;
	}
	initializePlayers();
	playInnings();
	cout<<endl<<GAP<<"---------------------------------------------------------";
	if(teamA.totalRunsScored>teamB.totalRunsScored)
	{
		cout<<endl<<GAP<<"|\t\tTeam-A won the game by "<<teamA.totalRunsScored-teamB.totalRunsScored<<" runs\t\t|";
	} else {
		cout<<endl<<GAP<<"|\t\tTeam-B won the game by "<<teamB.totalRunsScored-teamA.totalRunsScored<<" runs\t\t|";
	}
	cout<<endl<<GAP<<"---------------------------------------------------------";
	matchScoreCard();
}
