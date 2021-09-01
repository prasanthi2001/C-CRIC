/*Declare Player class attributes to store information such as name, unique id, runs
scored, balls played, balls bowled, runs given, and wickets taken in the match.*/

#include <string>

#define GAP "\t\t\t\t\t\t\t\t\t\t"

class Player {
	public:
		Player();
		std::string name;
		int id;
		int runsScored;
		int ballsPlayed;
		int ballsBowled;
		int runsGiven;
		int wicketsTaken;
};
