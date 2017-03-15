/*
* Name: date.hpp
* Purpose: Football manager
* @author mmodzel2
* @version 1.0 15-03-2017
*/

#ifndef _DATE_HPP
#define _DATE_HPP

class Date{
private:
    const char* date_;

    unsigned char day_;
    unsigned char month_;
    unsigned short year_;

public:
    Date(const char* date);
    ~Date();

    const char* get_date() const;

    unsigned char get_day() const;
    unsigned char get_month() const;
    unsigned short get_year() const;
};

#endif // _DATE_HPP
