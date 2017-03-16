/*
* Name: player.cpp
* Purpose: Football manager
* @author mmodzel2
* @version 1.0 15-03-2017
*/

#include <cstring>
#include <iostream>
#include <cassert>

#include "player.hpp"

using namespace std;

void Player::Player_create_(const char* name, const char* surname, const char* date_of_birth, const char* country){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) == 10);
    assert(date_of_birth[4] == '-' && date_of_birth[7] == '-');

    char* n = (char *)this->name_;
    char* s = (char *)this->surname_;
    char* c = (char *)this->country_;

    n[strlen_name] = 0;
    s[strlen_surname] = 0;
    c[strlen_name] = 0;

    strcpy(n, name); //copy context
    strcpy(s, surname);
    strcpy(c, country);

    this->date_of_birth_ = new Date(date_of_birth);
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country){
    this->Player_create_(name, surname, date_of_birth, country);

    this->cost_ = 0; //values are not known
    this->wage_ = 0;
    this->growth_ = 0;

    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;

    this->attack_ = 50;
    this->defense_ = 50;
    this->shoot_ = 50;
    this->corner_ = 50;
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country, unsigned long int cost){
    this->Player_create_(name, surname, date_of_birth, country);

    this->cost_ = cost;
    //values are not known
    this->wage_ = 0;
    this->growth_ = 0;

    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;

    this->attack_ = 50;
    this->defense_ = 50;
    this->shoot_ = 50;
    this->corner_ = 50;
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner){
    this->Player_create_(name, surname, date_of_birth, country);

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = 0; //values are not known
    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;

    this->attack_ = 50;
    this->defense_ = 50;
    this->shoot_ = 50;
    this->corner_ = 50;
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned long int cost){
    this->Player_create_(name, surname, date_of_birth, country);

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = cost;
    //values are not known
    this->goals_ = 0;
    this->assists_ = 0;
    this->matches_ = 0;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;

    this->attack_ = attack;
    this->defense_ = defense;
    this->shoot_ = shoot;
    this->corner_ = corner;
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists){
    this->Player_create_(name, surname, date_of_birth, country);

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = 0; //value is not known
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;

    this->attack_ = attack;
    this->defense_ = defense;
    this->shoot_ = shoot;
    this->corner_ = corner;
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards){
    this->Player_create_(name, surname, date_of_birth, country);

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = 0; //value is not known
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = red_cards;
    this->yellow_cards_ = yellow_cards;

    this->attack_ = attack;
    this->defense_ = defense;
    this->shoot_ = shoot;
    this->corner_ = corner;
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards, unsigned long int cost){
    this->Player_create_(name, surname, date_of_birth, country);

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = cost;
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = red_cards;
    this->yellow_cards_ = yellow_cards;

    this->attack_ = attack;
    this->defense_ = defense;
    this->shoot_ = shoot;
    this->corner_ = corner;
}

Player::Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned long int cost){
    this->Player_create_(name, surname, date_of_birth, country);

    this->wage_ = wage;
    this->growth_ = growth;

    this->cost_ = cost;
    this->goals_ = goals;
    this->assists_ = assists;
    this->matches_ = matches;

    this->red_cards_ = 0;
    this->yellow_cards_ = 0;

    this->attack_ = attack;
    this->defense_ = defense;
    this->shoot_ = shoot;
    this->corner_ = corner;
}

Player::~Player(){
    delete[] this->name_;
    delete[] this->surname_;
    delete[] this->country_;
    delete this->date_of_birth_;
}

    void Player::set_cost(unsigned long int cost) {this->cost_ = cost;}
    void Player::set_wage(float wage) {this->wage_ = wage;}
    void Player::set_assists(unsigned int assists) {this->assists_ = assists;}
    void Player::set_goals(unsigned int goals) {this->goals_ = goals;}
    void Player::set_matches(unsigned int matches) {this->matches_ = matches;}
    void Player::set_red_cards(unsigned int red_cards) {this->red_cards_ = red_cards;}
    void Player::set_yellow_cards(unsigned int yellow_cards) {this->yellow_cards_ = yellow_cards;}

    void Player::set_attack(float attack) {this->attack_ = attack;}
    void Player::set_defense(float defense) {this->defense_ = defense;}
    void Player::set_shoot(float shoot) {this->shoot_ = shoot;}
    void Player::set_corner(float corner) {this->corner_ = corner;}

    const char* Player::get_name() const {return this->name_;}
    const char* Player::get_surname() const {return this->surname_;}
    const char* Player::get_country() const {return this->country_;}

    unsigned long int Player::get_cost() const {return this->cost_;}
    float Player::get_wage() const {return this->wage_;}
    unsigned int Player::get_goals() const {return this->goals_;}
    unsigned int Player::get_assists() const {return this->assists_;}
    unsigned int Player::get_matches() const {return this->matches_;}
    unsigned int Player::get_red_cards() const {return this->red_cards_;}
    unsigned int Player::get_yellow_cards() const {return this->yellow_cards_;}

    float Player::get_attack() const {return this->attack_;}
    float Player::get_defense() const {return this->defense_;}
    float Player::get_shoot() const {return this->shoot_;}
    float Player::get_corner() const {return this->corner_;}

    void Player::add_goals(unsigned int goals_to_add) {this->goals_+=goals_to_add;}
    void Player::add_assists(unsigned int assists_to_add) {this->assists_+=assists_to_add;}
    void Player::add_matches(unsigned int matches_to_add) {this->matches_+=matches_to_add;}
    void Player::add_red_cards(unsigned int red_cards_to_add) {this->red_cards_+=red_cards_to_add;}
    void Player::add_yellow_cards(unsigned int yellow_cards_to_add) {this->yellow_cards_+=yellow_cards_to_add;}

    void Player::add_attack(float attack_to_add) {this->attack_ += attack_to_add;}
    void Player::add_defense(float defense_to_add) {this->defense_ += defense_to_add;}
    void Player::add_shoot(float shoot_to_add) {this->shoot_ += shoot_to_add;}
    void Player::add_corner(float corner_to_add) {this->corner_ += corner_to_add;}

    unsigned int Player::Create_Player(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4]);
        unsigned int ret = console->register_variable((const char *)args[0], p);
        if (ret == 1 || p == nullptr){
            if (p != nullptr) delete p;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::Create_PlayerC(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country, unsigned long int cost);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(unsigned long int*)args[5]);
        unsigned int ret = console->register_variable((const char *)args[0], p);
        if (ret == 1 || p == nullptr){
            if (p != nullptr) delete p;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::Create_PlayerS(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(float*)args[5],*(unsigned char*)args[6],*(float*)args[7],*(float*)args[8],*(float*)args[9],*(float*)args[10]);
        unsigned int ret = console->register_variable((const char *)args[0], p);
        if (ret == 1 || p == nullptr){
            if (p != nullptr) delete p;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::Create_PlayerSC(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(float*)args[5],*(unsigned char*)args[6],*(float*)args[7],*(float*)args[8],*(float*)args[9],*(float*)args[10],*(unsigned long int*)args[11]);
        unsigned int ret = console->register_variable((const char *)args[0], p);
        if (ret == 1 || p == nullptr){
            if (p != nullptr) delete p;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::Create_PlayerSM(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(float*)args[5],*(unsigned char*)args[6],*(float*)args[7],*(float*)args[8],*(float*)args[9],*(float*)args[10],*(unsigned int*)args[11],*(unsigned int*)args[12],*(unsigned int*)args[13]);
        unsigned int ret = console->register_variable((const char *)args[0], p);
        if (ret == 1 || p == nullptr){
            if (p != nullptr) delete p;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::Create_PlayerSMC(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned long int cost);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(float*)args[5],*(unsigned char*)args[6],*(float*)args[7],*(float*)args[8],*(float*)args[9],*(float*)args[10],*(unsigned int*)args[11],*(unsigned int*)args[12],*(unsigned int*)args[13],*(unsigned long int*)args[14]);
        unsigned int ret = console->register_variable((const char *)args[0], p);
        if (ret == 1 || p == nullptr){
            if (p != nullptr) delete p;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::Create_PlayerSMCards(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(float*)args[5],*(unsigned char*)args[6],*(float*)args[7],*(float*)args[8],*(float*)args[9],*(float*)args[10],*(unsigned int*)args[11],*(unsigned int*)args[12],*(unsigned int*)args[13],*(unsigned int*)args[14],*(unsigned int*)args[15]);
        unsigned int ret = console->register_variable((const char *)args[0], &p);
        if (ret == 1 || p == nullptr){
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::Create_PlayerSMCCards(Console* console, void** args){
        /* Function for creating player - prepared to use with class console (args has pointers to arguments in the same order as in function
        Player(const char* name, const char* surname, const char* date_of_birth, const char* country, float wage, unsigned char growth, float attack, float defense, float shoot, float corner, unsigned int matches, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards,unsigned long int cost);*/
        if (strlen((const char *)args[3]) != 10 || ((const char *)args[3])[4] != '-' || ((const char *)args[3])[7] != '-'){
            (console->get_stream()) << "Bad date format." << endl;
            return 4; //bad date format
        }

        Player* p = new Player((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4],*(float*)args[5],*(unsigned char*)args[6],*(float*)args[7],*(float*)args[8],*(float*)args[9],*(float*)args[10],*(unsigned int*)args[11],*(unsigned int*)args[12],*(unsigned int*)args[13],*(unsigned int*)args[14],*(unsigned int*)args[15],*(unsigned long int*)args[16]);
        unsigned int ret = console->register_variable((const char *)args[0], &p);
        if (ret == 1 || p == nullptr){
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete p;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Player has been created." << endl;
        return 0;
    }

    unsigned int Player::set_cost(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_cost(*(unsigned long int*)args[1]);
        return 0;
    }
    unsigned int Player::set_wage(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_wage(*(float*)args[1]);
        return 0;
    }
    unsigned int Player::set_goals(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_goals(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::set_assists(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_assists(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::set_matches(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_matches(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::set_red_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_red_cards(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::set_yellow_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_yellow_cards(*(unsigned int*)args[1]);
        return 0;
    }

    unsigned int Player::set_attack(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_attack(*(float*)args[1]);
        return 0;
    }
    unsigned int Player::set_defense(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_defense(*(float*)args[1]);
        return 0;
    }
    unsigned int Player::set_shoot(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_shoot(*(float*)args[1]);
        return 0;
    }
    unsigned int Player::set_corner(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->set_corner(*(float*)args[1]);
        return 0;
    }

    unsigned int Player::get_name(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_name() << endl;
        return 0;
    }
    unsigned int Player::get_surname(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_surname() << endl;
        return 0;
    }
    unsigned int Player::get_country(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_country() << endl;
        return 0;
    }

    unsigned int Player::get_cost(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_cost() << endl;
        return 0;
    }
    unsigned int Player::get_wage(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_wage() << endl;
        return 0;
    }
    unsigned int Player::get_goals(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_goals() << endl;
        return 0;
    }
    unsigned int Player::get_assists(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_assists() << endl;
        return 0;
    }
    unsigned int Player::get_matches(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_matches() << endl;
        return 0;
    }
    unsigned int Player::get_red_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_red_cards() << endl;
        return 0;
    }
    unsigned int Player::get_yellow_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_yellow_cards() << endl;
        return 0;
    }

    unsigned int Player::get_attack(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_attack() << endl;
        return 0;
    }
    unsigned int Player::get_defense(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_defense() << endl;
        return 0;
    }
    unsigned int Player::get_shoot(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_shoot() << endl;
        return 0;
    }
    unsigned int Player::get_corner(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Player *)args[0])->get_corner() << endl;
        return 0;
    }


    unsigned int Player::add_goals(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_goals(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::add_assists(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_assists(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::add_matches(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_matches(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::add_red_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_red_cards(*(unsigned int*)args[1]);
        return 0;
    }
    unsigned int Player::add_yellow_cards(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_yellow_cards(*(unsigned int*)args[1]);
        return 0;
    }

    unsigned int Player::add_attack(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_attack(*(float*)args[1]);
        return 0;
    }
    unsigned int Player::add_defense(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_defense(*(float*)args[1]);
        return 0;
    }
    unsigned int Player::add_shoot(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_shoot(*(float*)args[1]);
        return 0;
    }
    unsigned int Player::add_corner(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Player does not exist." << endl;
            return 1;
        }
        ((Player *)args[0])->add_corner(*(float*)args[1]);
        return 0;
    }


