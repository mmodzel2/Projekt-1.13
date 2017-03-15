/*
* Name: trainer.hpp
* Purpose: Football manager
* @author mmodzel2
* @version 1.0 15-03-2017
*/

#ifndef _TRAINER_HPP
#define _TRAINER_HPP

#include "date.hpp"

class Trainer{
private:
    const char* name_;
    const char* surname_;
    const char* country_;

    Date* date_of_birth_; //Trainer birth date

    float attack_multiplier_; //chance 0.0 to 1.0 of improving players after success training
    float defense_multiplier_;
    float shoot_multiplier_;
    float corner_multiplier_;

public:
    Trainer(const char* name, const char* surname, const char* country, const char* date_of_birth = "0000-00-00");
    ~Trainer();

    const char* get_name() const;
    const char* get_surname() const;
    const char* get_country() const;

    float get_attack_multiplier() const;
    float get_defense_multiplier() const;
    float get_shoot_multiplier() const;
    float get_corner_multiplier() const;

    void set_attack_multiplier(float attack_multiplier);
    void set_defense_multiplier(float defense_multiplier);
    void set_shoot_multiplier(float shoot_multiplier);
    void set_corner_multiplier(float corner_multiplier);

    //functions for class Console
    static unsigned int Create_Trainer(Console* console, void** args);
    static unsigned int Create_TrainerD(Console* console, void** args);

    static unsigned int get_name(Console* console, void** args);
    static unsigned int get_surname(Console* console, void** args);
    static unsigned int get_country(Console* console, void** args);

    static unsigned int get_attack_multiplier(Console* console, void** args);
    static unsigned int get_defense_multiplier(Console* console, void** args);
    static unsigned int get_shoot_multiplier(Console* console, void** args);
    static unsigned int get_corner_multiplier(Console* console, void** args);

    static unsigned int set_attack_multiplier(Console* console, void** args);
    static unsigned int set_defense_multiplier(Console* console, void** args);
    static unsigned int set_shoot_multiplier(Console* console, void** args);
    static unsigned int set_corner_multiplier(Console* console, void** args);
};

#endif // _TRAINER_HPP
