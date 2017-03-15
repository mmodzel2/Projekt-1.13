/*
* Name: team.hpp
* Purpose: Football manager
* @author mmodzel2
* @version 1.0 15-03-2017
*/

#ifndef _Team_HPP
#define _Team_HPP

#include "player.hpp"
#include "trainer.hpp"

class Team{
private:
	const char* name_;
	const char* country_;
	const char* city_;
	const char* formation_;

	Player* pitch_players_[11];
	Player** players_; //rest of field

	Trainer* trainer_;

	unsigned int players_count_;

    unsigned int goals_; //goals count
    unsigned int matches_; //matches_count
    unsigned int red_cards_; //red_cards count
    unsigned int yellow_cards_; //yellow_cards count

    long int money_;

    void Team_create_(const char* name, const char* country, const char* city, const char* formation);
public:
    Team(const char* name, const char* country, const char* city, const char* formation);
    Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer);
    Team(const char* name, const char* country, const char* city, const char* formation, long int money);
    Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer, int long money);
    Team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards);
    Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards);
    Team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, int long money);
    Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, int long money);
    ~Team();

    void delete_players();

    Trainer* get_trainer() const {return this->trainer_;}
    void set_trainer(Trainer* trainer);

    Player* get_player_position(unsigned char pos);
    void set_player_position(Player* p, unsigned char pos);

    unsigned int add_player(Player* p);
    unsigned int add_player(Player* p, unsigned char pos);
    void remove_player(Player* p);

    Player* find(const char* name, const char* surname);
    Player* find(const char* name, const char* surname, const char* country);

    void set_goals(unsigned int goals);
    void set_matches(unsigned int matches);
    void set_red_cards(unsigned int red_cards);
    void set_yellow_cards(unsigned int yellow_cards);
    void set_money(long int money);

    const char* get_name() const;
    const char* get_country() const;
    const char* get_city() const;
    const char* get_formation() const;

    unsigned int get_goals() const;
    unsigned int get_matches() const;
    unsigned int get_red_cards() const;
    unsigned int get_yellow_cards() const;
    long int get_money() const;

    unsigned int get_players_count() const;

    void add_matches(unsigned int matches);
    void add_money(long int money);

    unsigned int add_goals(Player* p, unsigned int goals);
    unsigned int add_goals(const char* name, const char* surname, unsigned int goals);
    unsigned int add_goals(const char* name, const char* surname, const char* country, unsigned int goals);

    unsigned int add_assists(Player* p, unsigned int assists);
    unsigned int add_assists(const char* name, const char* surname, unsigned int assists);
    unsigned int add_assists(const char* name, const char* surname, const char* country, unsigned int assists);

    unsigned int add_red_cards(Player* p, unsigned int red_cards);
    unsigned int add_red_cards(const char* name, const char* surname, unsigned int red_cards);
    unsigned int add_red_cards(const char* name, const char* surname, const char* country, unsigned int red_cards);

    unsigned int add_yellow_cards(Player* p, unsigned int yellow_cards);
    unsigned int add_yellow_cards(const char* name, const char* surname, unsigned int yellow_cards);
    unsigned int add_yellow_cards(const char* name, const char* surname, const char* country, unsigned int yellow_cards);

    unsigned int buy(Team* t, Player* p);
    unsigned int buy(Team* t, const char* name, const char* surname);
    unsigned int buy(Team* t, const char* name, const char* surname, const char* country);

    unsigned int transfer(Team* t, Player* p);
    unsigned int transfer(Team* t, const char* name, const char* surname);
    unsigned int transfer(Team* t, const char* name, const char* surname, const char* country);

    unsigned int train();

    Team & operator+=(Player &p);
    Team & operator-=(Player &p);

    void delete_players(Console* console); //for console class use

    //functions for class Console
    static unsigned int Create_Team(Console* console, void** args);
    static unsigned int Create_TeamM(Console* console, void** args);
    static unsigned int Create_TeamS(Console* console, void** args);
    static unsigned int Create_TeamSM(Console* console, void** args);

    static unsigned int set_money(Console* console, void** args);
    static unsigned int set_goals(Console* console, void** args);
    static unsigned int set_matches(Console* console, void** args);
    static unsigned int set_red_cards(Console* console, void** args);
    static unsigned int set_yellow_cards(Console* console, void** args);

    static unsigned int get_name(Console* console, void** args);
    static unsigned int get_city(Console* console, void** args);
    static unsigned int get_country(Console* console, void** args);
    static unsigned int get_formation(Console* console, void** args);

    static unsigned int get_money(Console* console, void** args);
    static unsigned int get_goals(Console* console, void** args);
    static unsigned int get_matches(Console* console, void** args);
    static unsigned int get_red_cards(Console* console, void** args);
    static unsigned int get_yellow_cards(Console* console, void** args);

    static unsigned int add_money(Console* console, void** args);
    static unsigned int add_goals(Console* console, void** args);
    static unsigned int add_assists(Console* console, void** args);
    static unsigned int add_matches(Console* console, void** args);
    static unsigned int add_red_cards(Console* console, void** args);
    static unsigned int add_yellow_cards(Console* console, void** args);

    static unsigned int get_trainer(Console* console, void** args);
    static unsigned int set_trainer(Console* console, void** args);
    static unsigned int get_player_position(Console* console, void** args);
    static unsigned int set_player_position(Console* console, void** args);
    static unsigned int add_player(Console* console, void** args);
    static unsigned int add_player_position(Console* console, void** args);
    static unsigned int remove_player(Console* console, void** args);
    static unsigned int find_player(Console* console, void** args);
    static unsigned int find_player_country(Console* console, void** args);

    static unsigned int buy(Console* console, void** args);
    static unsigned int buy_name(Console* console, void** args);
    static unsigned int buy_namec(Console* console, void** args);

    static unsigned int transfer(Console* console, void** args);
    static unsigned int transfer_name(Console* console, void** args);
    static unsigned int transfer_namec(Console* console, void** args);

    static unsigned int train(Console* console, void** args);
    static void delete_players(Console* console, Team* team);
};

#endif // _Team_HPP
