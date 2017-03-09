#include <cstring>
#include <iostream>
#include <cassert>

#include "player.hpp"

using namespace std;

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->cost_ = 0; //values are not known
    this->wage_ = 0;
    this->growth_ = 0;

    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;
}

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country, unsigned long int cost){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->cost_ = cost;
    //values are not known
    this->wage_ = 0;
    this->growth_ = 0;

    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;
}

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = 0; //values are not known
    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;
}

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, unsigned long int cost){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = cost;
    //values are not known
    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;
}

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = 0; //value is not known
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;
}

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists, const unsigned int red_cards, const unsigned int yellow_cards){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = 0; //value is not known
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = red_cards;
    this->yellow_cards_ = yellow_cards;
}

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists, const unsigned int red_cards, const unsigned int yellow_cards, unsigned long int cost){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = cost;
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;
}

player::player(const char* name, const char* surname, const char* date_of_birth, const char* country, const unsigned char wage, const unsigned char growth, const unsigned int matches, const unsigned int goals, const unsigned int assists, unsigned long int cost){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    this->name_[strlen_name] = 0;
    this->surname_[strlen_surname] = 0;
    this->country_[strlen_country] = 0;

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) >= 10);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = cost;
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;
}

player::~player(){
    delete[] this->name_;
    delete[] this->surname_;
    delete[] this->country_;
}

    void player::set_cost(unsigned long int cost) {this->cost_ = cost;}
    void player::set_wage(unsigned char wage) {this->wage_ = wage;}
    void player::set_assists(unsigned int assists) {this->assists_ = assists;}
    void player::set_goals(unsigned int goals) {this->goals_ = goals;}
    void player::set_matches(unsigned int matches) {this->matches_ = matches;}
    void player::set_red_cards(unsigned int red_cards) {this->red_cards_ = red_cards;}
    void player::set_yellow_cards(unsigned int yellow_cards) {this->yellow_cards_ = yellow_cards;}

    char* player::get_name() const {return this->name_;}
    char* player::get_surname() const {return this->surname_;}
    char* player::get_country() const {return this->country_;}

    unsigned char player::get_day_of_birth() const {return this->day_of_birth_;} //get player birth date
    unsigned char player::get_month_of_birth() const {return this->month_of_birth_;}
    unsigned short player::get_year_of_birth() const {return this->year_of_birth_;}

    unsigned long int player::get_cost() const {return this->cost_;}
    unsigned char player::get_wage() const {return this->wage_;}
    unsigned int player::get_goals() const {return this->goals_;}
    unsigned int player::get_assists() const {return this->assists_;}
    unsigned int player::get_matches() const {return this->matches_;}
    unsigned int player::get_red_cards() const {return this->red_cards_;}
    unsigned int player::get_yellow_cards() const {return this->yellow_cards_;}

    void player::add_goals(unsigned int goals_to_add) {this->goals_+=goals_to_add;}
    void player::add_assists(unsigned int assists_to_add) {this->assists_+=assists_to_add;}
    void player::add_matches(unsigned int matches_to_add) {this->matches_+=matches_to_add;}
    void player::add_red_cards(unsigned int red_cards_to_add) {this->red_cards_+=red_cards_to_add;}
    void player::add_yellow_cards(unsigned int yellow_cards_to_add) {this->yellow_cards_+=yellow_cards_to_add;}

    void player_test(){
        player p1("Lionel", "Messi", "1987-06-24", "Argentina",67,169,561,491,195,1,70,580000000);
        p1.add_matches(3);
        p1.add_yellow_cards();

        cout << "Test function" << endl;
        cout << "Player's name: " << p1.get_name() << endl;
        cout << "Player's surname: " << p1.get_surname() << endl;
        cout << "Player's country: " << p1.get_country() << endl;

        cout << "Player's matches count: " << p1.get_matches() << endl;
        cout << "Player's yellow cards: " << p1.get_yellow_cards() << endl;
    }
