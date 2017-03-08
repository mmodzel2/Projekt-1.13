#ifndef _MANAGER_HPP
#define _MANAGER_HPP

#include "team.hpp"

class manager{
private:
    char* name_;
    char* surname_;
    char* country_;

    team* team_;

public:
    manager(const char* name, const char* surname, const char* country);
    manager(const char* name, const char* surname, const char* country, team* team);
    ~manager();

    void delete_team();
    void delete_team_players();

    team* get_team() const;
    void set_team(team* team);

    char* get_name() const;
    char* get_surname() const;
    char* get_country() const;

    void match(unsigned int n, ...);
};

#endif // _MANAGER_HPP
