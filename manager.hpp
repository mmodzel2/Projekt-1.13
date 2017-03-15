/*
* Name: manager.hpp
* Purpose: Football manager
* @author mmodzel2
* @version 1.0 15-03-2017
*/

#ifndef _MANAGER_HPP
#define _MANAGER_HPP

#include "team.hpp"

class Manager{
private:
    const char* name_;
    const char* surname_;
    const char* country_;

    Team* team_;

public:
    Manager(const char* name, const char* surname, const char* country, Team* team = nullptr);
    ~Manager();

    void delete_team();
    void delete_team_players();

    Team* get_team() const;
    void set_team(Team* team);

    const char* get_name() const;
    const char* get_surname() const;
    const char* get_country() const;

    void match(unsigned int n, ...);
    unsigned int match(Manager* vs_manager);

    //functions for class Console
    static unsigned int Create_Manager(Console* console, void** args);
    static unsigned int Create_ManagerT(Console* console, void** args);

    static unsigned int get_name(Console* console, void** args);
    static unsigned int get_surname(Console* console, void** args);
    static unsigned int get_country(Console* console, void** args);

    static unsigned int get_team(Console* console, void** args);
    static unsigned int set_team(Console* console, void** args);

    static unsigned int delete_team(Console* console, void** args);
    static unsigned int delete_team_players(Console* console, void** args);

    static unsigned int match(Console* console, void** args);
};

#endif // _MANAGER_HPP
