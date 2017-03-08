#include <cstring>
#include <iostream>
#include <cassert>

#include "trainer.hpp"

using namespace std;

trainer::trainer(const char* name, const char* surname, const char* country){
    this->name_ = new char[strlen(name)];
    this->surname_ = new char[strlen(surname)];
    this->country_ = new char[strlen(country)];

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = 0;
    this->month_of_birth_ = 0;
    this->day_of_birth_ = 0;
}

trainer::trainer(const char* name, const char* surname, const char* country, const char* date_of_birth){
    this->name_ = new char[strlen(name)];
    this->surname_ = new char[strlen(surname)];
    this->country_ = new char[strlen(country)];

    assert(this->name_ != nullptr);
    assert(this->surname_ != nullptr);
    assert(this->country_ != nullptr);

    strcpy(this->name_, name); //copy context
    strcpy(this->surname_, surname);
    strcpy(this->country_, country);

    this->year_of_birth_ = date_of_birth[0]*1000+date_of_birth[1]*100+date_of_birth[2]*10+date_of_birth[3];
    this->month_of_birth_ = date_of_birth[5]*10+date_of_birth[6];
    this->day_of_birth_ = date_of_birth[8]*10+date_of_birth[9];
}

trainer::~trainer(){
    delete this->name_;
    delete this->surname_;
    delete this->country_;
}

    char* trainer::get_name() const {return this->name_;}
    char* trainer::get_surname() const {return this->surname_;}
    char* trainer::get_country() const {return this->country_;}

    unsigned char trainer::get_day_of_birth() const {return this->day_of_birth_;} //get player birth date
    unsigned char trainer::get_month_of_birth() const {return this->month_of_birth_;}
    unsigned short trainer::get_year_of_birth() const {return this->year_of_birth_;}

    void trainer_test(){
        trainer* t;
        t = new trainer("George", "Brooklyn", "USA", "1990-03-09");

        cout << "Test function" << endl;
        cout << "Trainer name: " << t->get_name() << endl;
        cout << "Trainer surname: " << t->get_surname() << endl;
        cout << "Trainer country: " << t->get_country() << endl;
    }
