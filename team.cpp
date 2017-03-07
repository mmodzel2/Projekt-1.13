#include <cstring>
#include <cstdlib>

#include "team.hpp"

team::team(char* name, char* country, char* city, char* formation){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    strcpy(this->name_, name); //copy context
    strcpy(this->country_, country);
    strcpy(this->city_, city);
    strcpy(this->formation_, formation);

    for (int i = 0; i < 11; i++) pitch_players_[i] = 0;

    this->players_ = nullptr;
    this->players_count_ = 0;

    this->goals_ = 0; //goals count
    this->matches_ = 0; //matches_count
    this->red_cards_ = 0; //red_cards count
    this->yellow_cards_ = 0; //yellow_cards count

    this->money_ = 0;
}

team::team(char* name, char* country, char* city, char* formation, unsigned int money){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    strcpy(this->name_, name); //copy context
    strcpy(this->country_, country);
    strcpy(this->city_, city);
    strcpy(this->formation_, formation);

    for (int i = 0; i < 11; i++) pitch_players_[i] = 0;

    this->players_ = nullptr;
    this->players_count_ = 0;

    this->goals_ = 0; //goals count
    this->matches_ = 0; //matches_count
    this->red_cards_ = 0; //red_cards count
    this->yellow_cards_ = 0; //yellow_cards count

    this->money_ = money;
}

team::team(char* name, char* country, char* city, char* formation, unsigned int goals, unsigned int matches, unsigned int red_cards, unsigned int yellow_cards){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    strcpy(this->name_, name); //copy context
    strcpy(this->country_, country);
    strcpy(this->city_, city);
    strcpy(this->formation_, formation);

    for (int i = 0; i < 11; i++) pitch_players_[i] = 0;

    this->players_ = nullptr;
    this->players_count_ = 0;

    this->goals_ = goals; //goals count
    this->matches_ = matches; //matches_count
    this->red_cards_ = red_cards; //red_cards count
    this->yellow_cards_ = yellow_cards; //yellow_cards count

    this->money_ = 0;
}

team::team(char* name, char* country, char* city, char* formation, unsigned int goals, unsigned int matches, unsigned int red_cards, unsigned int yellow_cards, unsigned int money){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    strcpy(this->name_, name); //copy context
    strcpy(this->country_, country);
    strcpy(this->city_, city);
    strcpy(this->formation_, formation);

    for (int i = 0; i < 11; i++) pitch_players_[i] = 0;

    this->players_ = nullptr;
    this->players_count_ = 0;

    this->goals_ = goals; //goals count
    this->matches_ = matches; //matches_count
    this->red_cards_ = red_cards; //red_cards count
    this->yellow_cards_ = yellow_cards; //yellow_cards count

    this->money_ = money;
}

team::~team(){
    delete this->name_;
    delete this->country_;
    delete this->city_;
    delete this->formation_;
}

unsigned int team::add_player(player* p){
    player** pointer;

    if (this->players_ != nullptr){
        for (unsigned int i = 0; i < this->players_count_; i++)
            if (players_[i] == p) return 2; //player added
    }

    pointer = (player **)realloc(this->players_, (sizeof (player*))*(players_count_+1));
    if (pointer == nullptr) return 1; //error allocation

    this->players_ = pointer;

    this->players_[this->players_count_] = p;
    this->players_count_++;

    return 0; //success
}

unsigned int team::add_player(player* p, unsigned char pos){
    unsigned int ret = this->add_player(p);
    if (ret == 1) return 1;

    for (int i = 0; i < 11; i++)
        if (pitch_players_[i] == p) pitch_players_[i] = 0;

    pitch_players_[pos] = p;

    return ret;
}

void team::remove_player(player* p){

}

player* team::find(char* name, char* surname){
    for (unsigned int i = 0; i < this->players_count_; i++)
        if ((strcmp(this->players_[i]->get_name(), name) == 0) || (strcmp(this->players_[i]->get_surname(), surname) == 0)) return this->players_[i];

    return nullptr;
}

player* team::find(char* name, char* surname, char* country){
    for (unsigned int i = 0; i < this->players_count_; i++)
        if ((strcmp(this->players_[i]->get_name(), name) == 0) || (strcmp(this->players_[i]->get_surname(), surname) == 0) || (strcmp(this->players_[i]->get_country(), country) == 0)) return this->players_[i];

    return nullptr;
}
