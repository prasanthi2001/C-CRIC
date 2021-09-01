/*Declare Game class attributes to store information such as team A and team B
details, players per team, maximum deliveries allowed in each innings, names of
all the 11 given players, and a variable to check which innings is going on.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"

class Game {
	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];
		
		bool isFirstInnings;
		Team teamA,teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman,*bowler;
		
		void welcome();
		void showAllPlayers();
		int takeIntegerInput();
		void selectPlayers();
		bool validateSelectedPlayer(int);
		void showTeamPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInnningsScore();
		void showGameScoreCard();
		void startSecondInnings();
		void matchScoreCard();
};
