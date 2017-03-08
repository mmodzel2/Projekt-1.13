#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iostream>

#include "team.hpp"

using namespace std;

team::team(const char* name, const char* country, const char* city, const char* formation){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    assert(this->name_ == nullptr);
    assert(this->country_ == nullptr);
    assert(this->city_ == nullptr);
    assert(this->formation_ == nullptr);

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

    this->trainer_ = nullptr;
}

team::team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    assert(this->name_ == nullptr);
    assert(this->country_ == nullptr);
    assert(this->city_ == nullptr);
    assert(this->formation_ == nullptr);

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

    this->trainer_ = trainer;
}

team::team(const char* name, const char* country, const char* city, const char* formation, unsigned int money){
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

    this->trainer_ = nullptr;
}

team::team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer, unsigned int money){
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

    this->trainer_ = trainer;
}

team::team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    assert(this->name_ == nullptr);
    assert(this->country_ == nullptr);
    assert(this->city_ == nullptr);
    assert(this->formation_ == nullptr);

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

    this->trainer_ = nullptr;
}

team::team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    assert(this->name_ == nullptr);
    assert(this->country_ == nullptr);
    assert(this->city_ == nullptr);
    assert(this->formation_ == nullptr);

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

    this->trainer_ = trainer;
}

team::team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, unsigned int money){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    assert(this->name_ == nullptr);
    assert(this->country_ == nullptr);
    assert(this->city_ == nullptr);
    assert(this->formation_ == nullptr);

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

    this->trainer_ = nullptr;
}

team::team(const char* name, const char* country, const char* city, const char* formation, trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, unsigned int money){
    this->name_ = new char[strlen(name)];
    this->country_ = new char[strlen(country)];
    this->city_ = new char[strlen(city)];
    this->formation_ = new char[strlen(formation)];

    assert(this->name_ == nullptr);
    assert(this->country_ == nullptr);
    assert(this->city_ == nullptr);
    assert(this->formation_ == nullptr);

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

    this->trainer_ = trainer;
}

team::~team(){
    delete this->name_;
    delete this->country_;
    delete this->city_;
    delete this->formation_;
}

unsigned int team::add_player(player* p){
    player** pointer;

    if (p == nullptr) return 1; //no playr to add

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
    if (p == nullptr) return; //no playr to remove

    for (unsigned int i = 0; i < 11; i++)
        if (this->pitch_players_[i] == p) this->pitch_players_[i] = 0;

    for (unsigned int i = 0; i < this->players_count_; i++)
        if (this->players_[i] == p) {
            players_count_--;
            for (; i < this->players_count_; i++)
                this->players_[i] = this->players_[i+1];
            this->players_[i] = 0;
            break;
        }
}

player* team::find(const char* name, const char* surname){
    for (unsigned int i = 0; i < this->players_count_; i++)
        if ((strcmp(this->players_[i]->get_name(), name) == 0) || (strcmp(this->players_[i]->get_surname(), surname) == 0)) return this->players_[i];

    return nullptr;
}

player* team::find(const char* name, const char* surname, const char* country){
   for (unsigned int i = 0; i < this->players_count_; i++)
        if ((strcmp(this->players_[i]->get_name(), name) == 0) || (strcmp(this->players_[i]->get_surname(), surname) == 0) || (strcmp(this->players_[i]->get_country(), country) == 0)) return this->players_[i];

    return nullptr;
}

player* team::get_player_position(unsigned char pos){
    if (pos > 11) return nullptr;
    return this->pitch_players_[pos];
}

void team::set_player_position(player* p, unsigned char pos){
    if (pos > 11) return;
    this->pitch_players_[pos] = p;
}

    void team::set_goals(unsigned int goals) {this->goals_ = goals;}
    void team::set_matches(unsigned int matches) {this->matches_ = matches;}
    void team::set_red_cards(unsigned int red_cards) {this->red_cards_ = red_cards;}
    void team::set_yellow_cards(unsigned int yellow_cards) {this->yellow_cards_ = yellow_cards;}
    void team::set_money(unsigned long int money) {this->money_ = money;}

    char* team::get_name() const {return this->name_;}
    char* team::get_country() const {return this->country_;}
    char* team::get_city() const {return this->city_;}
    char* team::get_formation() const {return this->formation_;}

    unsigned int team::get_goals() const {return this->goals_;}
    unsigned int team::get_matches() const {return this->matches_;}
    unsigned int team::get_red_cards() const {return this->red_cards_;}
    unsigned int team::get_yellow_cards() const {return this->yellow_cards_;}
    long int team::get_money() const {return this->money_;}

    void team::add_matches(unsigned int matches) {this->matches_+=matches;}
    void team::add_money(long int money) {this->money_+=money;}

    unsigned int team::add_goals(player* p, unsigned int goals){
        if (p == nullptr) return 2; //no player

        for (unsigned int i = 0; i < this->players_count_; i++){
            if (this->players_[i] == p){
                this->players_[i]->add_goals(goals);
                this->goals_ += goals;
                return 0; //success
            }
        }
        return 1; //player not found
    }
    unsigned int team::add_goals(const char* name, const char* surname, unsigned int goals){
        if (name == nullptr || surname == nullptr) return 2; //no player

        player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_goals(goals);
        this->goals_ += goals;
        return 0; //success
    }
    unsigned int team::add_goals(const char* name, const char* surname, const char* country, unsigned int goals){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_goals(goals);
        this->goals_ += goals;
        return 0; //success
    }

    unsigned int team::add_assists(player* p, unsigned int assists){
        if (p == nullptr) return 2;

        for (unsigned int i = 0; i < this->players_count_; i++){
            if (this->players_[i] == p){
                this->players_[i]->add_assists(assists);
                return 0; //success
            }
        }
        return 1; //player not found
    }
    unsigned int team::add_assists(const char* name, const char* surname, unsigned int assists){
        if (name == nullptr || surname == nullptr) return 2; //no player

        player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_assists(assists);
        return 0; //success
    }
    unsigned int team::add_assists(const char* name, const char* surname, const char* country, unsigned int assists){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_assists(assists);
        return 0; //success
    }


    unsigned int team::add_red_cards(player* p, unsigned int red_cards){
        if (p == nullptr) return 2; //no player

        for (unsigned int i = 0; i < this->players_count_; i++){
            if (this->players_[i] == p){
                this->players_[i]->add_red_cards(red_cards);
                this->red_cards_ += red_cards;
                return 0; //success
            }
        }
        return 1; //player not found
    }
    unsigned int team::add_red_cards(const char* name, const char* surname, unsigned int red_cards){
        if (name == nullptr || surname == nullptr) return 2; //no player

        player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_red_cards(red_cards);
        this->red_cards_ += red_cards;
        return 0; //success
    }
    unsigned int team::add_red_cards(const char* name, const char* surname, const char* country, unsigned int red_cards){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_red_cards(red_cards);
        this->red_cards_ += red_cards;
        return 0; //success
    }

    unsigned int team::add_yellow_cards(player* p, unsigned int yellow_cards){
        if (p == nullptr) return 2; //no playet

        for (unsigned int i = 0; i < this->players_count_; i++){
            if (this->players_[i] == p){
                this->players_[i]->add_yellow_cards(yellow_cards);
                this->yellow_cards_ += yellow_cards;
                return 0; //success
            }
        }
        return 1; //player not found
    }
    unsigned int team::add_yellow_cards(const char* name, const char* surname, unsigned int yellow_cards){
        if (name == nullptr || surname == nullptr) return 2; //no player

        player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_yellow_cards(yellow_cards);
        this->yellow_cards_ += yellow_cards;
        return 0; //success
    }
    unsigned int team::add_yellow_cards(const char* name, const char* surname, const char* country, unsigned int yellow_cards){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_yellow_cards(yellow_cards);
        this->yellow_cards_ += yellow_cards;
        return 0; //success
    }

    unsigned int team::buy(team* t, player* p){
        unsigned long int cost; //cost of player
        if (t == nullptr) return 1; //error - pointer to team from which to buy player is null
        if (p == nullptr) return 1; //error - no player

        for (unsigned int i = 0; i < t->players_count_; i++){
            if(t->players_[i] == p){
                cost = p->get_cost();
                if ((unsigned int long)this->money_ >= cost) {
                    this->add_money(-cost); //sub money from account of team
                    t->add_money(cost); //add money to account of team
                    t->remove_player(p);
                    this->add_player(p);
                    return 0; //success
                } else
                    return 3; //not enough money
            }
        }

        return 2; //no players in team from which to buy player
    }
    unsigned int team::buy(team* t, const char* name, const char* surname){
        player* p;
        unsigned long int cost; //cost of player

        if (t == nullptr) return 1; //error - pointer to team from which to buy player is null
        if (name == nullptr || surname == nullptr) return 1; //no player

        p = t->find(name, surname);
        if (p == nullptr) return 2; //no players in team from which to buy player

        cost = p->get_cost();
        if ((unsigned int long)this->money_ >= cost) {
            this->add_money(-cost); //sub money from account of team
            t->add_money(cost); //add money to account of team
            t->remove_player(p);
            this->add_player(p);
        } else
            return 3; //not enough money

        return 0; //success
    }
    unsigned int team::buy(team* t, const char* name, const char* surname, const char* country){
        player* p;
        unsigned long int cost; //cost of player
        if (t == nullptr) return 1; //error - pointer to team from which to buy player is null
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        p = t->find(name, surname, country);
        if (p == nullptr) return 2; //no players in team from which to buy player

        cost = p->get_cost();
        if ((unsigned int long)this->money_ >= cost) {
            this->add_money(-cost); //sub money from account of team
            t->add_money(cost); //add money to account of team
            t->remove_player(p);
            this->add_player(p);
        } else
            return 3; //not enough money

        return 0; //success
    }

    unsigned int team::transfer(team* t, player* p){
        if (t == nullptr) return 1; //error - pointer to team from which to transfer player is null
        if (p == nullptr) return 1; //error - no player

        for (unsigned int i = 0; i < t->players_count_; i++){
            if(t->players_[i] == p){
                    t->remove_player(p);
                    this->add_player(p);
                    return 0; //success
            }
        }

        return 2; //no players in team from which to transfer player
    }
    unsigned int team::transfer(team* t, const char* name, const char* surname){
        player* p;

        if (t == nullptr) return 1; //error - pointer to team from which to transfer player is null
        if (name == nullptr || surname == nullptr) return 1; //no player

        p = t->find(name, surname);
        if (p == nullptr) return 2; //no players in team from which to transfer player

        t->remove_player(p);
        this->add_player(p);

        return 0; //success
    }
    unsigned int team::transfer(team* t, const char* name, const char* surname, const char* country){
        player* p;

        if (t == nullptr) return 1; //error - pointer to team from which to transfer player is null
        if (name == nullptr || surname == nullptr) return 1; //no player

        p = t->find(name, surname);
        if (p == nullptr) return 2; //no players in team from which to transfer player

        t->remove_player(p);
        this->add_player(p);

        return 0; //success
    }

    void team_test(){ //test function for class team
        team t1("FC BARCELONA", "SPAIN", "BARCELONA", "4-3-3", 700000000);
        team t2("TEST TEAM", "POLAND", "WARSAW", "4-3-3", 800000000);
        player p1("Lionel", "Messi", "1987-06-24", "Argentina",67, 169,561,491,195,1,70,580000000);
        t1.add_player(&p1, 10);
        cout << "Goals before match: " << t1.get_goals() << endl;
        t1.add_goals("Lionel", "Messi", 3);
        cout << "Goals after match: " << t1.get_goals() << endl;
        cout << "Account of TEST TEAM: " << t2.get_money() << endl;
        t2.buy(&t1, "Lionel", "Messi");
        cout << "Account of FC BARCELONA after selling a player: " << t1.get_money() << endl;
        cout << "Account of TEST TEAM after buying a player: " << t2.get_money() << endl;
    }
