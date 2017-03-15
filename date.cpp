#include <cstring>
#include <cassert>

#include "date.hpp"

Date::Date(const char* date){
    unsigned int strlen_date = strlen(date);

    assert(strlen(date) == 10);

    this->date_ = new char[strlen_date+1];

    char* d = (char *)this->date_;
    d[strlen_date] = 0;

    strcpy(d, date); //copy context

    this->year_ = date[0]*1000+date[1]*100+date[2]*10+date[3];
    this->month_ = date[5]*10+date[6];
    this->day_ = date[8]*10+date[9];
}

Date::~Date(){
    delete[] this->date_;
}

    const char* Date::get_date() const {return this->date_;}

    unsigned char Date::get_day() const {return this->day_;}
    unsigned char Date::get_month() const {return this->month_;}
    unsigned short Date::get_year() const {return this->year_;}
