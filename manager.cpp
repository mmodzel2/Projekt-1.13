#include <cstring>
#include <cstdarg>

#include "manager.hpp"

manager::manager(const char* name, const char* surname, const char* country){
    this->name_ = new char[strlen(name)];
    this->surname_ = new char[strlen(surname)];
    this->country_ = new char[strlen(country)];

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->team_ = nullptr;
}

manager::manager(const char* name, const char* surname, const char* country, team* team){
    this->name_ = new char[strlen(name)];
    this->surname_ = new char[strlen(surname)];
    this->country_ = new char[strlen(country)];

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->team_ = team;
}

manager::~manager(){
    delete this->name_;
    delete this->surname_;
    delete this->country_;
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


