/* Orel Shalom 315532101 */

#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <vector>
#include "Card.h"

using namespace std;


class Player {

private:
	string name;
	int num_of_cards;
	vector<Card> cards;

public:
	Player(string name, int num_of_cards);
	Player(const Player& player);
	Player & operator = (const Player& player);

	void print_cards() const;
	string get_name() const { return name; }
	int get_num_of_cards() const { return num_of_cards; }
	vector<Card> get_cards() const { return cards; }

	bool play(Card&);
};
#endif