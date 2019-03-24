/* Orel Shalom */

#include <iostream>
#include <iterator>
#include <string>
#include "Game.h"

using namespace std;

Game::Game() {
	direction = "right";
	list<Player*> temp(0);
	players = temp;
}

Game::~Game() {
	players.clear();
	int len = players.size();
	for (int i = 0; i < len; i++) {
		delete[] players.back();
	}
}

void Game::start() {
	int num_players, num_cards, win = 0;

	cout << "How many players?" << endl;
	cin >> num_players;
	if (num_players <= 0) { cout << "NOT VALID NUMBER" << endl; return; }
	cout << "How many cards?" << endl;
	cin >> num_cards;
	if (num_cards <= 0) { cout << "NOT VALID NUMBER" << endl; return; }

	for (int i = 0; i < num_players; i++) {
		string name = "";
		cout << "player number " << (i + 1) << " name?" << endl;
		cin >> name;
		players.push_back(new Player(name, num_cards));
	}

	current = Card::generate_card();
	list<Player*>::iterator it;
	it = players.begin();

	while (win == 0) {
		bool played = (*it)->play(current);
		if ((*it)->get_cards().size() == 0) {
			cout << (*it)->get_name() << " wins!" << endl;
			win = 1;
		}
		else { next_player(it, played); }
		if (win == 1) { break; }
	}
}

void Game::next_player(list<Player*>::iterator & it, const bool played) {
	if (current.get_sign() != sign::CD) {
		if (direction.compare("right") == 0) {
			if (current.get_sign() == sign::STOP && played == true) {
				if ((*it) == players.back()) { it = players.begin(); it++; }
				else if (it == (++(++players.rbegin())).base()) { it = players.begin(); }
				else { it++; it++; }
			}
			else if (current.get_sign() != sign::PLUS || played == false) {
				if ((*it) == players.back()) { it = players.begin(); }
				else ++it;
			}
		}
		else {//left
			if (current.get_sign() == sign::STOP && played == true) {
				if (it == players.begin()) { cout << "aaa"; (*it) = players.back(); it--; }
				else if (it == (++players.begin())) { cout << "bbb"; (*it) = players.back(); }
				else { cout << "ccc"; it--; it--; }
			}
			else if (current.get_sign() != sign::PLUS || played == false) {
				if (it == players.begin()) { (*it) = players.back(); }
				else --it;
			}
		}
	}

	else { //direction changed (CD)
		if (players.size() != 2) {
			if (direction.compare("right") == 0) {
				if (played == true) direction = "left";
				if (it == players.begin()) { (*it) = players.back(); }
				else --it;
			}
			else {
				if (played == true) direction = "right";
				if ((*it) == players.back()) { it = players.begin(); }
				else ++it;
			}
		}
		else {
			if (played == false) {
				if ((*it) == players.back()) { it = players.begin(); }
				else ++it;
			}
		}
	}
}
