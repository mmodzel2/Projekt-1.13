#include <cstring>
#include <cstdarg>
#include <iostream>
#include <cassert>

#include "manager.hpp"

using namespace std;

manager::manager(const char* name, const char* surname, const char* country){
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

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->team_ = nullptr;
}

manager::manager(const char* name, const char* surname, const char* country, team* team){
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

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->team_ = team;
}

manager::~manager(){
    delete[] this->name_;
    delete[] this->surname_;
    delete[] this->country_;
}

void manager::delete_team(){ //delete team with players and trainer
    if (this->team_ != nullptr){
        this->team_->delete_players();

        if (this->team_->get_trainer() != nullptr) delete this->team_->get_trainer();
        delete this->team_;

        this->team_ = nullptr;
    }
}

void manager::delete_team_players(){ //delete team with players
    if (this->team_ != nullptr){
        this->team_->delete_players();

        delete this->team_;

        this->team_ = nullptr;
    }
}

    char* manager::get_name() const {return this->name_;}
    char* manager::get_surname() const {return this->surname_;}
    char* manager::get_country() const {return this->country_;}

    team* manager::get_team() const {return this->team_;}
    void manager::set_team(team* team) {this->team_ = team;}

    void manager::match(unsigned int n, ...){ /* n - players count, const char* name, const char* surname, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards, ... */
        va_list va;
        const char* name;
        const char* surname;
        player* p;
        unsigned int goals, assists, red_cards, yellow_cards;

        if (this->team_ == nullptr) return;
        if (n == 0) return;

        va_start(va, n);

        do{
            name = va_arg(va, const char*);
            surname = va_arg(va, const char*);
            goals = va_arg(va, unsigned int);
            assists = va_arg(va, unsigned int);
            red_cards = va_arg(va, unsigned int);
            yellow_cards = va_arg(va, unsigned int);

            p = this->team_->find(name, surname);
            if (p == nullptr) continue;

            this->team_->add_goals(p, goals);
            this->team_->add_assists(p, assists);
            this->team_->add_red_cards(p, red_cards);
            this->team_->add_yellow_cards(p, yellow_cards);
        } while(--n);
        va_end(va);
    }

void manager_test(){
    manager m("Adam", "Smith", "SPAIN");
    team t("FC BARCELONA", "SPAIN", "BARCELONA", "4-3-3", 700000000);
    player p("Lionel", "Messi", "1987-06-24", "Argentina",67,169,561,491,195,1,70,580000000);

    m.set_team(&t);
    t.add_player(&p, 10);
    m.match(1, "Lionel", "Messi", 3, 1, 0, 1);

    cout << "Test function" << endl;
    cout << "Goals after match: " << t.get_goals() << endl;
    cout << "Red cards after match: " << t.get_red_cards() << endl;
    cout << "Yellow cards after match: " << t.get_yellow_cards() << endl << endl;
    cout << "Player's goals after match: " << p.get_goals() << endl;
    cout << "Player's red cards after match: " << p.get_red_cards() << endl;
    cout << "Player's yellow cards after match: " << p.get_yellow_cards() << endl;
    cout << "Player's assists after match: " << p.get_assists() << endl;
}
