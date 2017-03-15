#include <cstring>
#include <iostream>
#include <cassert>

#include "console.hpp"
#include "trainer.hpp"

using namespace std;

Trainer::Trainer(const char* name, const char* surname, const char* country){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    char* n = (char *)this->name_;
    char* s = (char *)this->surname_;
    char* c = (char *)this->country_;

    n[strlen_name] = 0;
    s[strlen_surname] = 0;
    c[strlen_name] = 0;

    strcpy(n, name); //copy context
    strcpy(s, surname);
    strcpy(c, country);

    this->date_of_birth_ = new Date("0000-00-00");
}

Trainer::Trainer(const char* name, const char* surname, const char* country, const char* date_of_birth){
    unsigned int strlen_name = strlen(name);
    unsigned int strlen_surname = strlen(surname);
    unsigned int strlen_country = strlen(country);

    this->name_ = new char[strlen_name+1];
    this->surname_ = new char[strlen_surname+1];
    this->country_ = new char[strlen_country+1];

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    assert(strlen(date_of_birth) != 10);

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

Trainer::~Trainer(){
    delete[] this->name_;
    delete[] this->surname_;
    delete[] this->country_;
    delete this->date_of_birth_;
}

    const char* Trainer::get_name() const {return this->name_;}
    const char* Trainer::get_surname() const {return this->surname_;}
    const char* Trainer::get_country() const {return this->country_;}

    float Trainer::get_attack_multiplier() const {return this->attack_multiplier_;}
    float Trainer::get_defense_multiplier() const {return this->defense_multiplier_;}
    float Trainer::get_shoot_multiplier() const {return this->shoot_multiplier_;}
    float Trainer::get_corner_multiplier() const {return this->corner_multiplier_;}

    void Trainer::set_attack_multiplier(float attack_multiplier) {if(attack_multiplier > 1.0) this->attack_multiplier_ = 1.0; else if(attack_multiplier < 0.0)this->attack_multiplier_ = 0.0; else this->attack_multiplier_ = attack_multiplier;}
    void Trainer::set_defense_multiplier(float defense_multiplier) {if(defense_multiplier > 1.0) this->defense_multiplier_ = 1.0; else if(defense_multiplier < 0.0)this->defense_multiplier_ = 0.0; else this->defense_multiplier_ = defense_multiplier;}
    void Trainer::set_shoot_multiplier(float shoot_multiplier) {if(shoot_multiplier > 1.0) this->shoot_multiplier_ = 1.0; else if(shoot_multiplier < 0.0)this->shoot_multiplier_ = 0.0; else this->shoot_multiplier_ = shoot_multiplier;}
    void Trainer::set_corner_multiplier(float corner_multiplier) {if(corner_multiplier > 1.0) this->corner_multiplier_ = 1.0; else if(corner_multiplier < 0.0)this->corner_multiplier_ = 0.0; else this->corner_multiplier_ = corner_multiplier;}

    unsigned int Trainer::Create_Trainer(Console* console, void** args){
        /* Function for creating trainer - prepared to use with class console (args has pointers to arguments in the same order as in function
        Trainer(const char* name, const char* surname, const char* country);*/
        Trainer* tr = new Trainer((const char *)args[1],(const char *)args[2],(const char *)args[3]);
        unsigned int ret = console->register_variable((const char *)args[0], tr);

        if (ret == 1 || tr == nullptr){
            if (tr != nullptr) delete tr;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete tr;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Trainer has been created." << endl;
        return 0;
    }
    unsigned int Trainer::Create_TrainerD(Console* console, void** args){
        /* Function for creating trainer - prepared to use with class console (args has pointers to arguments in the same order as in function
        Trainer(const char* name, const char* surname, const char* country, const char* date_of_birth);*/
        Trainer* tr = new Trainer((const char *)args[1],(const char *)args[2],(const char *)args[3],(const char *)args[4]);
        unsigned int ret = console->register_variable((const char *)args[0], tr);
        if (ret == 1 || tr == nullptr){
            if (tr != nullptr) delete tr;
            (console->get_stream()) << "Lack of free memory. Player cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete tr;
            (console->get_stream()) << "Variable name reserved. Cannot create player with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Trainer has been created." << endl;
        return 0;
    }

    unsigned int Trainer::get_name(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Trainer *)args[0])->get_name() << endl;
        return 0;
    }
    unsigned int Trainer::get_surname(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Trainer *)args[0])->get_surname() << endl;
        return 0;
    }
    unsigned int Trainer::get_country(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Trainer *)args[0])->get_country() << endl;
        return 0;
    }

    unsigned int Trainer::get_attack_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Trainer *)args[0])->get_attack_multiplier() << endl;
        return 0;
    }
    unsigned int Trainer::get_defense_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Trainer *)args[0])->get_defense_multiplier() << endl;
        return 0;
    }
    unsigned int Trainer::get_shoot_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Trainer *)args[0])->get_shoot_multiplier() << endl;
        return 0;
    }
    unsigned int Trainer::get_corner_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Trainer *)args[0])->get_corner_multiplier() << endl;
        return 0;
    }

    unsigned int Trainer::set_attack_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        ((Trainer *)args[0])->set_attack_multiplier(*(float*)args[1]);
        return 0;
    }
    unsigned int Trainer::set_defense_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        ((Trainer *)args[0])->set_defense_multiplier(*(float*)args[1]);
        return 0;
    }
    unsigned int Trainer::set_shoot_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        ((Trainer *)args[0])->set_shoot_multiplier(*(float*)args[1]);
        return 0;
    }
    unsigned int Trainer::set_corner_multiplier(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Trainer does not exist." << endl;
            return 1;
        }
        ((Trainer *)args[0])->set_corner_multiplier(*(float*)args[1]);
        return 0;
    }
