#ifndef _TEAM_HPP
#define _TEAM_HPP

#include "player.hpp"
#include "trainer.hpp"

class team{
private:
	char* name_;
	char* country_;
	char* city_;

	char* formation_;

	player* pitch_players_[11];
	player** players_; //rest of field

	trainer* trainer_;

	unsigned int players_count_;

    unsigned int goals_; //goals count
    unsigned int matches_; //matches_count
    unsigned int red_cards_; //red_cards count
    unsigned int yellow_cards_; //yellow_cards count

    long int money_;
public:
    team(const char* name, const char* country, const char* city, const char* formation);
    team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer);
    team(const char* name, const char* country, const char* city, const char* formation, unsigned int money);
    team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer, unsigned int money);
    team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards);
    team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards);
    team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, unsigned int money);
    team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, unsigned int money);
    ~team();

    player* get_player_position(unsigned char pos);
    void set_player_position(player* p, unsigned char pos);

    unsigned int add_player(player* p);
    unsigned int add_player(player* p, unsigned char pos);
    void remove_player(player* p);

    player* find(const char* name, const char* surname);
    player* find(const char* name, const char* surname, const char* country);

    void set_goals(unsigned int goals);
    void set_matches(unsigned int matches);
    void set_red_cards(unsigned int red_cards);
    void set_yellow_cards(unsigned int yellow_cards);
    void set_money(unsigned long int money);

    char* get_name() const;
    char* get_country() const;
    char* get_city() const;
    char* get_formation() const;

    unsigned int get_goals() const;
    unsigned int get_matches() const;
    unsigned int get_red_cards() const;
    unsigned int get_yellow_cards() const;
    long int get_money() const;

    void add_matches(unsigned int matches);
    void add_money(long int money);

    unsigned int add_goals(player* p, unsigned int goals);
    unsigned int add_goals(const char* name, const char* surname, unsigned int goals);
    unsigned int add_goals(const char* name, const char* surname, const char* country, unsigned int goals);

    unsigned int add_assists(player* p, unsigned int assists);
    unsigned int add_assists(const char* name, const char* surname, unsigned int assists);
    unsigned int add_assists(const char* name, const char* surname, const char* country, unsigned int assists);

    unsigned int add_red_cards(player* p, unsigned int red_cards);
    unsigned int add_red_cards(const char* name, const char* surname, unsigned int red_cards);
    unsigned int add_red_cards(const char* name, const char* surname, const char* country, unsigned int red_cards);

    unsigned int add_yellow_cards(player* p, unsigned int yellow_cards);
    unsigned int add_yellow_cards(const char* name, const char* surname, unsigned int yellow_cards);
    unsigned int add_yellow_cards(const char* name, const char* surname, const char* country, unsigned int yellow_cards);

    unsigned int buy(team* t, player* p);
    unsigned int buy(team* t, const char* name, const char* surname);
    unsigned int buy(team* t, const char* name, const char* surname, const char* country);

    unsigned int transfer(team* t, player* p);
    unsigned int transfer(team* t, const char* name, const char* surname);
    unsigned int transfer(team* t, const char* name, const char* surname, const char* country);
};

#endif // _TEAM_HPP
