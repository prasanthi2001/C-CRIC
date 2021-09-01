#include "game.h"
using namespace std;

int main() {
	
	Game game;
	game.welcome();
	cout<<endl<<GAP<<"Press Enter to Continue: ";
	getchar();
	game.showAllPlayers();
	cout<<"\n\n"<<GAP<<"Press Enter to Continue: ";
	getchar();
	game.selectPlayers();
	cout<<endl<<endl;
	game.showTeamPlayers();
	
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"\n\n"<<GAP<<"Press Enter to Toss: ";
	getchar();
	game.toss();
	game.startFirstInnings();
	game.startSecondInnings();
	return 0;
}
