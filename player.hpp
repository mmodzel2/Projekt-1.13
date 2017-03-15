/*
* Name: player.hpp
* Purpose: Football manager
* @author mmodzel2
* @version 1.0 15-03-2017
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "console.hpp"
#include "date.hpp"

class Player {
private:
    const char* name_;
    const char* surname_;
    const char* country_;
    Date* date_of_birth_; //Player birth date

    unsigned long int cost_; //cost of the Player

    float wage_;
    unsigned char growth_;

    float attack_; //match stats for player from 0.0 to 100.0
    float defense_;
    float shoot_;
    float corner_;

    unsigned int goals_; //goals count
    unsigned int assists_; //assists count
    unsigned int matches_; //matches_count
    unsigned int red_cards_; //red_cards count
    unsigned int yellow_cards_; //yellow_cards count

    void Player_create_(const char* name, const char* surname, const char* date_of_birth, const char* country);
public:
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country);
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country, unsigned long int cost);
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner);
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned long int cost);
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists);
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards);
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned long int cost);
    Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards, unsigned long int cost);
    ~Player();

    void set_cost(unsigned long int cost);
    void set_wage(float wage);
    void set_assists(unsigned int assists);
    void set_goals(unsigned int goals);
    void set_matches(unsigned int matches);
    void set_red_cards(unsigned int red_cards);
    void set_yellow_cards(unsigned int yellow_cards);

    void set_attack(float attack);
    void set_defense(float defense);
    void set_shoot(float shoot);
    void set_corner(float corner);

    const char* get_name() const;
    const char* get_surname() const;
    const char* get_country() const;

    unsigned long int get_cost() const;
    float get_wage() const;
    unsigned int get_goals() const;
    unsigned int get_assists() const;
    unsigned int get_matches() const;
    unsigned int get_red_cards() const;
    unsigned int get_yellow_cards() const;

    float get_attack() const;
    float get_defense() const;
    float get_shoot() const;
    float get_corner() const;

    void add_goals(unsigned int goals_to_add=1);
    void add_assists(unsigned int assists_to_add=1);
    void add_matches(unsigned int matches_to_add=1);
    void add_red_cards(unsigned int red_cards_to_add=1);
    void add_yellow_cards(unsigned int yellow_cards_to_add=1);

    void add_attack(float attack_to_add);
    void add_defense(float defense_to_add);
    void add_shoot(float shoot_to_add);
    void add_corner(float corner_to_add);

    //functions for class Console
    static unsigned int Create_Player(Console* console, void** args);
    static unsigned int Create_PlayerC(Console* console, void** args);
    static unsigned int Create_PlayerS(Console* console, void** args);
    static unsigned int Create_PlayerSC(Console* console, void** args);
    static unsigned int Create_PlayerSM(Console* console, void** args);
    static unsigned int Create_PlayerSMC(Console* console, void** args);
    static unsigned int Create_PlayerSMCards(Console* console, void** args);
    static unsigned int Create_PlayerSMCCards(Console* console, void** args);

    static unsigned int set_cost(Console* console, void** args);
    static unsigned int set_wage(Console* console, void** args);
    static unsigned int set_assists(Console* console, void** args);
    static unsigned int set_goals(Console* console, void** args);
    static unsigned int set_matches(Console* console, void** args);
    static unsigned int set_red_cards(Console* console, void** args);
    static unsigned int set_yellow_cards(Console* console, void** args);

    static unsigned int set_attack(Console* console, void** args);
    static unsigned int set_defense(Console* console, void** args);
    static unsigned int set_shoot(Console* console, void** args);
    static unsigned int set_corner(Console* console, void** args);

    static unsigned int get_name(Console* console, void** args);
    static unsigned int get_surname(Console* console, void** args);
    static unsigned int get_country(Console* console, void** args);

    static unsigned int get_cost(Console* console, void** args);
    static unsigned int get_wage(Console* console, void** args);
    static unsigned int get_goals(Console* console, void** args);
    static unsigned int get_assists(Console* console, void** args);
    static unsigned int get_matches(Console* console, void** args);
    static unsigned int get_red_cards(Console* console, void** args);
    static unsigned int get_yellow_cards(Console* console, void** args);

    static unsigned int get_attack(Console* console, void** args);
    static unsigned int get_defense(Console* console, void** args);
    static unsigned int get_shoot(Console* console, void** args);
    static unsigned int get_corner(Console* console, void** args);

    static unsigned int add_assists(Console* console, void** args);
    static unsigned int add_goals(Console* console, void** args);
    static unsigned int add_matches(Console* console, void** args);
    static unsigned int add_red_cards(Console* console, void** args);
    static unsigned int add_yellow_cards(Console* console, void** args);

    static unsigned int add_attack(Console* console, void** args);
    static unsigned int add_defense(Console* console, void** args);
    static unsigned int add_shoot(Console* console, void** args);
    static unsigned int add_corner(Console* console, void** args);
};

#endif
