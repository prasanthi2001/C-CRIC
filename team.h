/*Declare Team class attributes to store information such as team name, total runs
scored by the team, total wickets lost, total balls bowled, and list of team players.*/

#include <vector>
#include "player.h"

class Team {
	public:
		Team();
		std::string name;
		int totalRunsScored;
		int wicketsLost;
		int totalBallsBowled;
		std::vector<Player> players;
};
