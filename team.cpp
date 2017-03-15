/*
* Name: team.cpp
* Purpose: Football manager
* @author mmodzel2
* @version 1.0 15-03-2017
*/

#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <ctime>

#include "team.hpp"

using namespace std;

void Team::Team_create_(const char* name, const char* country, const char* city, const char* formation){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_country = strlen(country);
    unsigned int strlen_city = strlen(city);
    unsigned int strlen_formation = strlen(formation);

    srand(time(NULL));

    this->name_ = new char[strlen_name+1];
    this->country_ = new char[strlen_country+1];
    this->city_ = new char[strlen_city+1];
    this->formation_ = new char[strlen_formation+1];

    assert(this->name_ != nullptr);
    assert(this->country_ != nullptr);
    assert(this->city_ != nullptr);
    assert(this->formation_ != nullptr);

    char* n = (char *)this->name_;
    char* co = (char *)this->country_;
    char* ci = (char *)this->city_;
    char* f = (char *)this->formation_;

    n[strlen_name] = 0;
    co[strlen_country] = 0;
    ci[strlen_city] = 0;
    f[strlen_name] = 0;

    strcpy(n, name); //copy context
    strcpy(co, country);
    strcpy(ci, city);
    strcpy(f, formation);

    for (int i = 0; i < 11; i++) pitch_players_[i] = nullptr;

    this->players_ = nullptr;
    this->players_count_ = 0;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation){
    this->Team_create_(name, country, city, formation);

    this->goals_ = 0; //goals count
    this->matches_ = 0; //matches_count
    this->red_cards_ = 0; //red_cards count
    this->yellow_cards_ = 0; //yellow_cards count

    this->money_ = 0;

    this->trainer_ = nullptr;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer){
    this->Team_create_(name, country, city, formation);

    this->goals_ = 0; //goals count
    this->matches_ = 0; //matches_count
    this->red_cards_ = 0; //red_cards count
    this->yellow_cards_ = 0; //yellow_cards count

    this->money_ = 0;

    this->trainer_ = trainer;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation, long int money){
    this->Team_create_(name, country, city, formation);

    this->goals_ = 0; //goals count
    this->matches_ = 0; //matches_count
    this->red_cards_ = 0; //red_cards count
    this->yellow_cards_ = 0; //yellow_cards count

    this->money_ = money;

    this->trainer_ = nullptr;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer, long int money){
    this->Team_create_(name, country, city, formation);

    this->goals_ = 0; //goals count
    this->matches_ = 0; //matches_count
    this->red_cards_ = 0; //red_cards count
    this->yellow_cards_ = 0; //yellow_cards count

    this->money_ = money;

    this->trainer_ = trainer;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards){
    this->Team_create_(name, country, city, formation);

    this->goals_ = goals; //goals count
    this->matches_ = matches; //matches_count
    this->red_cards_ = red_cards; //red_cards count
    this->yellow_cards_ = yellow_cards; //yellow_cards count

    this->money_ = 0;

    this->trainer_ = nullptr;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards){
    this->Team_create_(name, country, city, formation);

    this->goals_ = goals; //goals count
    this->matches_ = matches; //matches_count
    this->red_cards_ = red_cards; //red_cards count
    this->yellow_cards_ = yellow_cards; //yellow_cards count

    this->money_ = 0;

    this->trainer_ = trainer;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, long int money){
    this->Team_create_(name, country, city, formation);

    this->goals_ = goals; //goals count
    this->matches_ = matches; //matches_count
    this->red_cards_ = red_cards; //red_cards count
    this->yellow_cards_ = yellow_cards; //yellow_cards count

    this->money_ = money;

    this->trainer_ = nullptr;
}

Team::Team(const char* name, const char* country, const char* city, const char* formation, Trainer* trainer, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, long int money){
    this->Team_create_(name, country, city, formation);

    this->goals_ = goals; //goals count
    this->matches_ = matches; //matches_count
    this->red_cards_ = red_cards; //red_cards count
    this->yellow_cards_ = yellow_cards; //yellow_cards count

    this->money_ = money;

    this->trainer_ = trainer;
}

Team::~Team(){
    delete[] this->name_;
    delete[] this->country_;
    delete[] this->city_;
    delete[] this->formation_;
    if (this->players_ != nullptr) free(this->players_);
}

void Team::set_trainer(Trainer* trainer){this->trainer_ = trainer;}

void Team::delete_players(){
    if (this->players_ != nullptr){
        for (unsigned int i = 0; i < this->players_count_; i++)
            delete this->players_[i];

        delete this->players_; //free memory reserved by players list

        this->players_ = nullptr;

        for (unsigned int i = 0; i < 11; i++)
            this->pitch_players_[i] = nullptr;
    }
}

unsigned int Team::add_player(Player* p){
    Player** pointer;

    if (p == nullptr) return 1; //no playr to add

    if (this->players_ != nullptr){
        for (unsigned int i = 0; i < this->players_count_; i++)
            if (players_[i] == p) return 2; //player added
    }

    pointer = (Player **)realloc(this->players_, (sizeof (Player*))*(players_count_+1));
    if (pointer == nullptr) return 1; //error allocation

    this->players_ = pointer;

    this->players_[this->players_count_] = p;
    this->players_count_++;

    return 0; //success
}

unsigned int Team::add_player(Player* p, unsigned char pos){
    unsigned int ret = this->add_player(p);
    if (ret == 1) return 1;

    for (int i = 0; i < 11; i++)
        if (pitch_players_[i] == p) pitch_players_[i] = 0;

    pitch_players_[pos] = p;

    return ret;
}

void Team::remove_player(Player* p){
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

Player* Team::find(const char* name, const char* surname){
    for (unsigned int i = 0; i < this->players_count_; i++)
        if ((strcmp(this->players_[i]->get_name(), name) == 0) || (strcmp(this->players_[i]->get_surname(), surname) == 0)) return this->players_[i];

    return nullptr;
}

Player* Team::find(const char* name, const char* surname, const char* country){
   for (unsigned int i = 0; i < this->players_count_; i++)
        if ((strcmp(this->players_[i]->get_name(), name) == 0) || (strcmp(this->players_[i]->get_surname(), surname) == 0) || (strcmp(this->players_[i]->get_country(), country) == 0)) return this->players_[i];

    return nullptr;
}

Player* Team::get_player_position(unsigned char pos){
    if (pos > 11) return nullptr;
    return this->pitch_players_[pos];
}

void Team::set_player_position(Player* p, unsigned char pos){
    if (pos > 11) return;
    this->pitch_players_[pos] = p;
}

    void Team::set_goals(unsigned int goals) {this->goals_ = goals;}
    void Team::set_matches(unsigned int matches) {this->matches_ = matches;}
    void Team::set_red_cards(unsigned int red_cards) {this->red_cards_ = red_cards;}
    void Team::set_yellow_cards(unsigned int yellow_cards) {this->yellow_cards_ = yellow_cards;}
    void Team::set_money(long int money) {this->money_ = money;}

    const char* Team::get_name() const {return this->name_;}
    const char* Team::get_country() const {return this->country_;}
    const char* Team::get_city() const {return this->city_;}
    const char* Team::get_formation() const {return this->formation_;}

    unsigned int Team::get_goals() const {return this->goals_;}
    unsigned int Team::get_matches() const {return this->matches_;}
    unsigned int Team::get_red_cards() const {return this->red_cards_;}
    unsigned int Team::get_yellow_cards() const {return this->yellow_cards_;}
    long int Team::get_money() const {return this->money_;}

    unsigned int Team::get_players_count() const {return this->players_count_;}

    void Team::add_matches(unsigned int matches) {this->matches_+=matches;}
    void Team::add_money(long int money) {this->money_+=money;}

    unsigned int Team::add_goals(Player* p, unsigned int goals){
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
    unsigned int Team::add_goals(const char* name, const char* surname, unsigned int goals){
        if (name == nullptr || surname == nullptr) return 2; //no player

        Player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_goals(goals);
        this->goals_ += goals;
        return 0; //success
    }
    unsigned int Team::add_goals(const char* name, const char* surname, const char* country, unsigned int goals){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        Player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_goals(goals);
        this->goals_ += goals;
        return 0; //success
    }

    unsigned int Team::add_assists(Player* p, unsigned int assists){
        if (p == nullptr) return 2;

        for (unsigned int i = 0; i < this->players_count_; i++){
            if (this->players_[i] == p){
                this->players_[i]->add_assists(assists);
                return 0; //success
            }
        }
        return 1; //player not found
    }
    unsigned int Team::add_assists(const char* name, const char* surname, unsigned int assists){
        if (name == nullptr || surname == nullptr) return 2; //no player

        Player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_assists(assists);
        return 0; //success
    }
    unsigned int Team::add_assists(const char* name, const char* surname, const char* country, unsigned int assists){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        Player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_assists(assists);
        return 0; //success
    }


    unsigned int Team::add_red_cards(Player* p, unsigned int red_cards){
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
    unsigned int Team::add_red_cards(const char* name, const char* surname, unsigned int red_cards){
        if (name == nullptr || surname == nullptr) return 2; //no player

        Player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_red_cards(red_cards);
        this->red_cards_ += red_cards;
        return 0; //success
    }
    unsigned int Team::add_red_cards(const char* name, const char* surname, const char* country, unsigned int red_cards){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        Player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_red_cards(red_cards);
        this->red_cards_ += red_cards;
        return 0; //success
    }

    unsigned int Team::add_yellow_cards(Player* p, unsigned int yellow_cards){
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
    unsigned int Team::add_yellow_cards(const char* name, const char* surname, unsigned int yellow_cards){
        if (name == nullptr || surname == nullptr) return 2; //no player

        Player* p = this->find(name, surname);
        if (p == nullptr) return 1; //;player not found

        p->add_yellow_cards(yellow_cards);
        this->yellow_cards_ += yellow_cards;
        return 0; //success
    }
    unsigned int Team::add_yellow_cards(const char* name, const char* surname, const char* country, unsigned int yellow_cards){
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        Player* p = this->find(name, surname, country);
        if (p == nullptr) return 1; //;player not found

        p->add_yellow_cards(yellow_cards);
        this->yellow_cards_ += yellow_cards;
        return 0; //success
    }

    unsigned int Team::buy(Team* t, Player* p){
        unsigned long int cost; //cost of player
        if (t == nullptr) return 1; //error - pointer to Team from which to buy player is null
        if (p == nullptr) return 1; //error - no player

        for (unsigned int i = 0; i < t->players_count_; i++){
            if(t->players_[i] == p){
                cost = p->get_cost();
                if ((unsigned int long)this->money_ >= cost) {
                    this->add_money(-cost); //sub money from account of Team
                    t->add_money(cost); //add money to account of Team
                    t->remove_player(p);
                    this->add_player(p);
                    return 0; //success
                } else
                    return 3; //not enough money
            }
        }

        return 2; //no players in Team from which to buy player
    }
    unsigned int Team::buy(Team* t, const char* name, const char* surname){
        Player* p;
        unsigned long int cost; //cost of player

        if (t == nullptr) return 1; //error - pointer to Team from which to buy player is null
        if (name == nullptr || surname == nullptr) return 1; //no player

        p = t->find(name, surname);
        if (p == nullptr) return 2; //no players in Team from which to buy player

        cost = p->get_cost();
        if ((unsigned int long)this->money_ >= cost) {
            this->add_money(-cost); //sub money from account of Team
            t->add_money(cost); //add money to account of Team
            t->remove_player(p);
            this->add_player(p);
        } else
            return 3; //not enough money

        return 0; //success
    }
    unsigned int Team::buy(Team* t, const char* name, const char* surname, const char* country){
        Player* p;
        unsigned long int cost; //cost of player
        if (t == nullptr) return 1; //error - pointer to Team from which to buy player is null
        if (name == nullptr || surname == nullptr || country == nullptr) return 2; //no player

        p = t->find(name, surname, country);
        if (p == nullptr) return 2; //no players in Team from which to buy player

        cost = p->get_cost();
        if ((unsigned int long)this->money_ >= cost) {
            this->add_money(-cost); //sub money from account of Team
            t->add_money(cost); //add money to account of Team
            t->remove_player(p);
            this->add_player(p);
        } else
            return 3; //not enough money

        return 0; //success
    }

    unsigned int Team::transfer(Team* t, Player* p){
        if (t == nullptr) return 1; //error - pointer to Team from which to transfer player is null
        if (p == nullptr) return 1; //error - no player

        for (unsigned int i = 0; i < t->players_count_; i++){
            if(t->players_[i] == p){
                    t->remove_player(p);
                    this->add_player(p);
                    return 0; //success
            }
        }

        return 2; //no players in Team from which to transfer player
    }
    unsigned int Team::transfer(Team* t, const char* name, const char* surname){
        Player* p;

        if (t == nullptr) return 1; //error - pointer to Team from which to transfer player is null
        if (name == nullptr || surname == nullptr) return 1; //no player

        p = t->find(name, surname);
        if (p == nullptr) return 2; //no players in Team from which to transfer player

        t->remove_player(p);
        this->add_player(p);

        return 0; //success
    }
    unsigned int Team::transfer(Team* t, const char* name, const char* surname, const char* country){
        Player* p;

        if (t == nullptr) return 1; //error - pointer to Team from which to transfer player is null
        if (name == nullptr || surname == nullptr) return 1; //no player

        p = t->find(name, surname);
        if (p == nullptr) return 2; //no players in Team from which to transfer player

        t->remove_player(p);
        this->add_player(p);

        return 0; //success
    }

    unsigned int Team::train(){
        float stat;

        if (this->trainer_ == nullptr) return 1; //error
        if (this->players_count_ == 0) return 1; //error - no players

        if ((rand()%2) == 0) return 2; //training with no success

        for (unsigned int i = 0; i < this->players_count_; i++){
            stat = this->players_[i]->get_attack();
            stat = (((this->trainer_->get_attack_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->players_[i]->add_attack(stat);

            stat = this->players_[i]->get_defense();
            stat = (((this->trainer_->get_defense_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->players_[i]->add_defense(stat);

            stat = this->players_[i]->get_shoot();
            stat = (((this->trainer_->get_shoot_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->players_[i]->add_shoot(stat);

            stat = this->players_[i]->get_corner();
            stat = (((this->trainer_->get_corner_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->players_[i]->add_corner(stat);
        }

        //additional training to pitch players
        if ((rand()%2) == 0) return 0; //additional training with no success

        for (unsigned int i = 0; i < 11; i++){
            if (pitch_players_[i] == nullptr) continue;

            if (pitch_players_[i]->get_attack()+pitch_players_[i]->get_defense()+pitch_players_[i]->get_shoot()+pitch_players_[i]->get_corner() > (float)(rand()%400)) continue; //individual training with no success

            stat = this->pitch_players_[i]->get_attack();
            stat = (((this->trainer_->get_attack_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->pitch_players_[i]->add_attack(stat);

            stat = this->pitch_players_[i]->get_defense();
            stat = (((this->trainer_->get_defense_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->pitch_players_[i]->add_defense(stat);

            stat = this->pitch_players_[i]->get_shoot();
            stat = (((this->trainer_->get_shoot_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->pitch_players_[i]->add_shoot(stat);

            stat = this->pitch_players_[i]->get_corner();
            stat = (((this->trainer_->get_corner_multiplier())*((float)(rand()%100)))- stat)/100.0;
            if (stat > 0.0) this->pitch_players_[i]->add_corner(stat);
        }

        return 0; //success
    }

    Team & Team::operator+=(Player &p){add_player(&p); return *this;}
    Team & Team::operator-=(Player &p){remove_player(&p); return *this;}

    unsigned int Team::Create_Team(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Team(const char* name, const char* country, const char* city, const char* formation);*/
        Team* t = new Team((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4]);
        unsigned int ret = console->register_variable((const char *)args[0], t);
        if (ret == 1 || t == nullptr){
            if (t != nullptr) delete t;
            (console->get_stream()) << "Lack of free memory. Team cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete t;
            (console->get_stream()) << "Variable name reserved. Cannot create team with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Team has been created." << endl;
        return 0;
    }

    unsigned int Team::Create_TeamM(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Team(const char* name, const char* country, const char* city, const char* formation, unsigned long int money);*/
        Team* t = new Team((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(unsigned long int *)args[4]);
        unsigned int ret = console->register_variable((const char *)args[0], t);
        if (ret == 1 || t == nullptr){
            if (t != nullptr) delete t;
            (console->get_stream()) << "Lack of free memory. Team cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete t;
            (console->get_stream()) << "Variable name reserved. Cannot create team with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Team has been created." << endl;
        return 0;
    }

    unsigned int Team::Create_TeamS(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards);*/
        Team* t = new Team((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(unsigned int *)args[5],*(unsigned int *)args[6],*(unsigned int *)args[7],*(unsigned int *)args[8]);
        unsigned int ret = console->register_variable((const char *)args[0], t);
        if (ret == 1 || t == nullptr){
            if (t != nullptr) delete t;
            (console->get_stream()) << "Lack of free memory. Team cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete t;
            (console->get_stream()) << "Variable name reserved. Cannot create team with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Team has been created." << endl;
        return 0;
    }

    unsigned int Team::Create_TeamSM(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Team(const char* name, const char* country, const char* city, const char* formation, unsigned int matches, unsigned int goals, unsigned int red_cards, unsigned int yellow_cards, long int money);*/
        Team* t = new Team((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(unsigned int *)args[5],*(unsigned int *)args[6],*(unsigned int *)args[7],*(unsigned int *)args[8],*(unsigned long int *)args[9]);
        unsigned int ret = console->register_variable((const char *)args[0], t);
        if (ret == 1 || t == nullptr){
            if (t != nullptr) delete t;
            (console->get_stream()) << "Lack of free memory. Team cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete t;
            (console->get_stream()) << "Variable name reserved. Cannot create team with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Team has been created." << endl;
        return 0;
    }

    unsigned int Team::set_money(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->set_money(*(long int*)args[1]);
        return 0;
    }
    unsigned int Team::set_goals(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->set_goals(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Team::set_matches(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->set_matches(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Team::set_red_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->set_red_cards(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Team::set_yellow_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->set_yellow_cards(*(unsigned int*)args[1]);
        return 0;
    }

    unsigned int Team::get_name(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_name() << endl;
        return 0;
    }
    unsigned int Team::get_city(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_city() << endl;
        return 0;
    }
    unsigned int Team::get_country(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_country() << endl;
        return 0;
    }
    unsigned int Team::get_formation(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_formation() << endl;
        return 0;
    }

    unsigned int Team::get_money(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_money() << endl;
        return 0;
    }
    unsigned int Team::get_goals(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_goals() << endl;
        return 0;
    }
    unsigned int Team::get_matches(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_matches() << endl;
        return 0;
    }
    unsigned int Team::get_red_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_red_cards() << endl;
        return 0;
    }
    unsigned int Team::get_yellow_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Team *)args[0])->get_yellow_cards() << endl;
        return 0;
    }


    unsigned int Team::add_goals(Console* console, void** args){
        if (args[0] == nullptr && args[1] == nullptr){
            (console->get_stream()) << "Team and player do not exist." << endl;
            return 1;
        } else if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        } else if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->add_goals((Player *)args[1], *(unsigned int*)args[2]);
        return 0;
    }
    unsigned int Team::add_assists(Console* console, void** args){
        if (args[0] == nullptr && args[1] == nullptr){
            (console->get_stream()) << "Team and player do not exist." << endl;
            return 1;
        } else if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        } else if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->add_assists((Player *)args[1], *(unsigned int*)args[2]);
        return 0;
    }
    unsigned int Team::add_matches(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->add_matches(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Team::add_red_cards(Console* console, void** args){
        if (args[0] == nullptr && args[1] == nullptr){
            (console->get_stream()) << "Team and player do not exist." << endl;
            return 1;
        } else if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        } else if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->add_red_cards((Player *)args[1], *(unsigned int*)args[2]);
        return 0;
    }
    unsigned int Team::add_yellow_cards(Console* console, void** args){
        if (args[0] == nullptr && args[1] == nullptr){
            (console->get_stream()) << "Team and player do not exist." << endl;
            return 1;
        } else if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        } else if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->add_yellow_cards((Player *)args[1], *(unsigned int*)args[2]);
        return 0;
    }

    unsigned int Team::get_trainer(Console* console, void** args){
        const char* name;
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        if (((Team *)args[0])->get_trainer() == nullptr){
            (console->get_stream()) << "Trainer has not been added." << endl;
            return 2;
        }
        name = console->get_variable((void*)((Team *)args[0])->get_trainer());
        if (name == nullptr) {
            (console->get_stream()) << "Critical error - problem with finding variable" << endl;
            return 3;
        }
        (console->get_stream()) << name << endl;
        return 0;
    }

    unsigned int Team::set_trainer(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->set_trainer((Trainer*)args[1]);
        return 0;
    }

    unsigned int Team::get_player_position(Console* console, void** args){
        const char* name;
        Player* p;

        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        if (*(unsigned char*)args[1] >= 11){
            (console->get_stream()) << "Too big position number." << endl;
            return 2;
        }
        p = ((Team *)args[0])->get_player_position(*(unsigned char*)args[1]);
        if (p == nullptr){
            (console->get_stream()) << "No player is set on this position." << endl;
            return 3;
        }
        name = console->get_variable((void*)p);
        if (name == nullptr) {
            (console->get_stream()) << "Critical error - problem with finding variable" << endl;
            return 3;
        }
        (console->get_stream()) << name << " " << p->get_name() << " " << p->get_surname() << endl;
        return 0;
    }

    unsigned int Team::set_player_position(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->set_player_position((Player*)args[1],*(unsigned char*)args[2]);
        return 0;
    }

    unsigned int Team::add_player(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->add_player((Player*)args[1]);
        return 0;
    }

    unsigned int Team::add_player_position(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->add_player((Player*)args[1],*(unsigned char*)args[2]);
        return 0;
    }

    unsigned int Team::remove_player(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Team *)args[0])->remove_player((Player*)args[1]);
        return 0;
    }

    unsigned int Team::find_player(Console* console, void** args){
        Player* p;
        const char* name;

        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        p = ((Team *)args[0])->find((const char*)args[1],(const char*)args[2]);
        if (p == nullptr){
            (console->get_stream()) << "Player has not been found." << endl;
            return 2;
        }

        name = console->get_variable((void*)p);
        if (name == nullptr) {
            (console->get_stream()) << "Critical error - problem with finding variable" << endl;
            return 3;
        }
        (console->get_stream()) << name << endl;
        return 0;
    }

    unsigned int Team::find_player_country(Console* console, void** args){
        Player* p;
        const char* name;

        if (args[0] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        p = ((Team *)args[0])->find((const char*)args[1],(const char*)args[2],(const char*)args[3]);
        if (p == nullptr){
            (console->get_stream()) << "Player has not been found." << endl;
            return 2;
        }

        name = console->get_variable((void*)p);
        if (name == nullptr) {
            (console->get_stream()) << "Critical error - problem with finding variable" << endl;
            return 3;
        }
        (console->get_stream()) << name << endl;
        return 0;
    }

    unsigned int Team::buy(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team1 does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Team2 does not exist." << endl;
            return 1;
        }
        if (args[2] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }

        ((Team *)args[0])->buy((Team *)args[1],(Player *)args[2]);

        return 0;
    }
    unsigned int Team::buy_name(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team1 does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Team2 does not exist." << endl;
            return 1;
        }

        ((Team *)args[0])->buy((Team *)args[1],(const char *)args[2],(const char *)args[3]);

        return 0;
    }
    unsigned int Team::buy_namec(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team1 does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Team2 does not exist." << endl;
            return 1;
        }

        ((Team *)args[0])->buy((Team *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4]);

        return 0;
    }

    unsigned int Team::transfer(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team1 does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Team2 does not exist." << endl;
            return 1;
        }
        if (args[2] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }

        ((Team *)args[0])->transfer((Team *)args[1],(Player *)args[2]);

        return 0;
    }
    unsigned int Team::transfer_name(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team1 does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Team2 does not exist." << endl;
            return 1;
        }

        ((Team *)args[0])->transfer((Team *)args[1],(const char *)args[2],(const char *)args[3]);

        return 0;
    }
    unsigned int Team::transfer_namec(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Team1 does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Team2 does not exist." << endl;
            return 1;
        }

        ((Team *)args[0])->transfer((Team *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4]);

        return 0;
    }

    unsigned int Team::train(Console* console, void** args){
        unsigned int ret;
        if (args[0] == nullptr){
            (console->get_stream()) << "Team1 does not exist." << endl;
            return 1;
        }

        ret = ((Team *)args[0])->train();
        if (ret == 1){
            (console->get_stream()) << "No players or trainer in team." << endl;
            return 1;
        } else if (ret == 2){
            (console->get_stream()) << "Training with no success." << endl;
            return 2;
        }
        (console->get_stream()) << "Training succeeded." << endl;
        return 0;
    }

    void Team::delete_players(Console* console){
    if (this->players_ != nullptr){
        for (unsigned int i = 0; i < this->players_count_; i++){
            console->remove_variable((void *)players_[i]);
            delete this->players_[i];
        }

        delete this->players_; //free memory reserved by players list

        this->players_ = nullptr;

        for (unsigned int i = 0; i < 11; i++)
            this->pitch_players_[i] = nullptr;
    }
}


