#ifndef _TEAM_HPP
#define _TEAM_HPP

#include "player.hpp"

class team{
private:
	char* name_;
	char* country_;
	char* city_;

	char* formation_;

	player* pitch_players_[11];
	player** players_; //rest of field

	unsigned int players_count_;

    unsigned int goals_; //goals count
    unsigned int matches_; //matches_count
    unsigned int red_cards_; //red_cards count
    unsigned int yellow_cards_; //yellow_cards count

    unsigned int money_;
public:
    team(char* name, char* country, char* city, char* formation);
    team(char* name, char* country, char* city, char* formation, unsigned int money);
    team(char* name, char* country, char* city, char* formation, unsigned int goals, unsigned int matches, unsigned int red_cards, unsigned int yellow_cards);
    team(char* name, char* country, char* city, char* formation, unsigned int goals, unsigned int matches, unsigned int red_cards, unsigned int yellow_cards, unsigned int money);
    ~team();

    player* get_player_position(unsigned char pos);

    unsigned int add_player(player* p);
    unsigned int add_player(player* p, unsigned char pos);
    void remove_player(player* p);

    player* find(char* name, char* surname);
    player* find(char* name, char* surname, char* country);
};

#endif // _TEAM_HPP
