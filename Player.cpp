/* Orel Shalom 315532101 */

#include "Player.h"

Player::Player(string name_input, int num_of_cards_input){
	name = name_input;
	num_of_cards = num_of_cards_input;
	vector<Card> temp(0);
	cards = temp;
	for (int i = 0; i < num_of_cards; i++) {
		cards.push_back(Card::generate_card());
	}
}

Player::Player(const Player& player) {
	name = player.name;
	num_of_cards = player.num_of_cards;
	cards.clear();
	for (int i = 0; i < num_of_cards; i++) {
		cards.push_back(player.cards[i]);
	}
}

Player & Player::operator =(const Player& player) {
	name = player.name;
	num_of_cards = player.num_of_cards;
	vector<Card> temp(num_of_cards);
	cards = temp;
	for (int i = 0; i < num_of_cards; ++i) {
		cards[i] = player.cards[i];
	}
	return *this;
}

void Player::print_cards() const {
	for (size_t i = 0; i < cards.size(); i++) {
		cout << "(" << i + 1 << ")" << cards[i] << " ";
	}
}

bool Player::play(Card & card) {
	cout << "current: " << card << endl;
	cout << get_name() << ", your turn - " << endl;
	cout << "Your cards: ";
	print_cards();
	cout << endl;

	int choice;
	cin >> choice;
	if (choice > int(get_cards().size()) || choice <= 0) {
		Card c = c.generate_card();
		cards.push_back(c);
		num_of_cards++;
		return false;
	}

	while (card.is_legal(get_cards()[choice - 1]) == false) {
		cout << "You can't put " << get_cards()[choice - 1] << " on " << card << endl;
		cin >> choice;
		if (choice > int(get_cards().size()) || choice <= 0) {
			Card c = c.generate_card();
			cards.push_back(c);
			num_of_cards++;
			return false;
		}
	}
	if (card.is_legal(get_cards()[choice - 1]) == true) {
		card = get_cards()[choice - 1];
		cards.erase(cards.begin() + choice - 1);
		num_of_cards--;
		return true;
	}
	return false;
}
