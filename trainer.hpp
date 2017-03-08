#ifndef _TRAINER_HPP
#define _TRAINER_HPP

class trainer{
private:
    char* name_;
    char* surname_;
    char* country_;

    unsigned char day_of_birth_; //player birth date
    unsigned char month_of_birth_;
    unsigned short year_of_birth_;

public:
    trainer(const char* name, const char* surname, const char* country);
    trainer(const char* name, const char* surname, const char* country, const char* date_of_birth);
    ~trainer();

    char* get_name() const;
    char* get_surname() const;
    char* get_country() const;

    unsigned char get_day_of_birth() const; //get player birth date
    unsigned char get_month_of_birth() const;
    unsigned short get_year_of_birth() const;
};

#endif // _TRAINER_HPP
