/* Orel Shalom */

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <list>

using namespace std;

class Game {

private:
	Card current;
	list<Player*> players;
	string direction;
	Game(const Game& game) {};
	Game & operator= (const Game & game) { return *this; };

public:
	Game();
	~Game();

	void start();
	void next_player(list<Player*>::iterator & it, const bool played);
};
#endif
