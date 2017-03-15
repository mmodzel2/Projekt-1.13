#include <cstring>
#include <cstdarg>
#include <iostream>
#include <cassert>
#include <cstdlib>

#include "manager.hpp"

using namespace std;

Manager::Manager(const char* name, const char* surname, const char* country){
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

    this->team_ = nullptr;
}

Manager::Manager(const char* name, const char* surname, const char* country, Team* team){
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

    this->team_ = team;
}

Manager::~Manager(){
    delete[] this->name_;
    delete[] this->surname_;
    delete[] this->country_;
}

void Manager::delete_team(){ //delete team with players and trainer
    if (this->team_ != nullptr){
        this->team_->delete_players();

        if (this->team_->get_trainer() != nullptr) {
                delete this->team_->get_trainer();
                this->team_->set_trainer(nullptr);
        }
        delete this->team_;

        this->team_ = nullptr;
    }
}

void Manager::delete_team_players(){ //delete team with players
    if (this->team_ != nullptr){
        this->team_->delete_players();

        delete this->team_;

        this->team_ = nullptr;
    }
}

    const char* Manager::get_name() const {return this->name_;}
    const char* Manager::get_surname() const {return this->surname_;}
    const char* Manager::get_country() const {return this->country_;}

    Team* Manager::get_team() const {return this->team_;}
    void Manager::set_team(Team* team) {this->team_ = team;}

    void Manager::match(unsigned int n, ...){ /* n - players count, const char* name, const char* surname, unsigned int goals, unsigned int assists, unsigned int red_cards, unsigned int yellow_cards, ... */
        va_list va;
        const char* name;
        const char* surname;
        Player* p;
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

    unsigned int Manager::match(Manager* vs_manager){
        Player* p;
        Player* p1;
        Team* t[2];
        unsigned int choosen, temp;
        float m_attack[2] = {0.0, 0.0}, m_defense[2] = {0.0, 0.0}, m_shoot[2] = {0.0, 0.0}, m_corner[2] = {0.0, 0.0}; //sum of players stats for team 1 and 2
        unsigned int players_goals[22] = {0};
        unsigned int goals[2] = {0,0};

        t[0] = this->get_team();
        t[1] = vs_manager->get_team();

        if (t[0] == nullptr || t[1] == nullptr) return 0xFFFFFFFE; //manager without team

        for (int i = 0; i < 11; i++){ //count sum
            p = t[0]->get_player_position(i);
            if (p == nullptr) return 0xFFFFFFFF; //no player on position - match cannot start

            m_attack[0] += p->get_attack();
            m_defense[0] += p->get_defense();
            m_shoot[0] += p->get_shoot();
            m_corner[0] += p->get_corner();

            p = t[1]->get_player_position(i);
            if (p == nullptr) return 0xFFFFFFFF; //no player on position - match cannot start

            m_attack[1] += p->get_attack();
            m_defense[1] += p->get_defense();
            m_shoot[1] += p->get_shoot();
            m_corner[1] += p->get_corner();
        }

        //match starts

        for (int i = 0; i < 30; i++){ //30 iterations for match - one iteration = 3 min
            choosen = rand()%2;
            if (m_attack[choosen] > m_defense[(choosen+1)%2]){
                temp = rand()%3;
                if (temp == 0 || temp == 2){ //shoot
                    if ((rand()%5) != 0){ //shoot with statics
                        temp = rand()%11; //choose player who will shoot
                        p = t[choosen]->get_player_position(temp); //choose player who will shoot
                        p1 = t[(choosen+1)%2]->get_player_position(0); //get goalkeeper against team
                        if (p->get_attack() >= p1->get_defense()) {
                            players_goals[choosen*11+temp]++;
                            goals[choosen]++;
                        }
                    } else { //goal
                        temp = rand()%11; //choose player who will shoot goal
                        players_goals[choosen*11+temp]++;
                        goals[choosen]++;
                    }
                } else if (m_corner[choosen] > m_defense[(choosen+1)%2]) {
                    if ((rand()%2) == 0) {
                            temp = rand()%11; //choose player who will shoot goal
                            players_goals[choosen*11+temp]++;
                            goals[choosen]++; //goal is shot from corner
                    }
                }
            } else {
                temp = rand()%10;
                if (temp == 0){ //shoot
                    if ((rand()%3) != 0){ //shoot with statics
                        temp = rand()%11; //choose player who will shoot
                        p = t[choosen]->get_player_position(temp); //choose player who will shoot
                        p1 = t[(choosen+1)%2]->get_player_position(0); //get goalkeeper against team
                        if (p->get_attack() >= p1->get_defense()) {
                            players_goals[choosen*11+temp]++;
                            goals[choosen]++;
                        }
                    } else { //goal
                        temp = rand()%11; //choose player who will shoot goal
                        players_goals[choosen*11+temp]++;
                        goals[choosen]++;
                    }
                }
            }
        }

        //match ends
        //add goals to players
        for (int i = 0; i < 11; i++) {
                if (players_goals[i] != 0){
                        p = t[0]->get_player_position(i);
                        t[0]->add_goals(p,players_goals[i]);
                }
                if (players_goals[i+11] != 0){
                        p = t[1]->get_player_position(i);
                        t[1]->add_goals(p,players_goals[i+11]);
                }
        }

        if (goals[0] != 0) {
                temp = rand()%goals[0];
                for (unsigned int i = 0; i < temp; i++){
                    if ((rand()%3) == 0){
                        choosen = rand()%11;
                        p = t[0]->get_player_position(choosen);
                        t[0]->add_assists(p,1);
                    }
                }
        }
        if (goals[1] != 0) {
                temp = rand()%goals[1];
                for (unsigned int i = 0; i < temp; i++){
                    if ((rand()%3) == 0){
                        choosen = rand()%11;
                        p = t[1]->get_player_position(choosen);
                        t[1]->add_assists(p,1);
                    }
                }
        }

        //add yellow cards to players
        temp = (rand()%(goals[0]+1));
        if (temp != 0) temp = rand()%temp;
        for (unsigned int i = 0; i < temp; i++){
                choosen = rand()%11;
                p = t[0]->get_player_position(choosen);
                t[0]->add_yellow_cards(p,1);
        }
        temp = (rand()%(goals[1]+1));
        if (temp != 0) temp = rand()%temp;
        for (unsigned int i = 0; i < temp; i++){
                choosen = rand()%11;
                p = t[1]->get_player_position(choosen);
                t[1]->add_yellow_cards(p,1);
        }

        //add red cards to players
        if ((rand()%10) == 0){
                choosen = rand()%11;
                p = t[0]->get_player_position(choosen);
                t[0]->add_red_cards(p,1);
        }
        if ((rand()%10) == 0){
                choosen = rand()%11;
                p = t[1]->get_player_position(choosen);
                t[1]->add_red_cards(p,1);
        }

        return goals[0]*1000+goals[1]; //final score
    }

    unsigned int Manager::Create_Manager(Console* console, void** args){
        /* Function for creating manager - prepared to use with class console (args has pointers to arguments in the same order as in function
        Manager(const char* name, const char* surname, const char* country);*/
        Manager* m = new Manager((const char *)args[1],(const char *)args[2],(const char *)args[3]);
        unsigned int ret = console->register_variable((const char *)args[0], m);
        if (ret == 1 || m == nullptr){
            if (m != nullptr) delete m;
            (console->get_stream()) << "Lack of free memory. Manager cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete m;
            (console->get_stream()) << "Variable name reserved. Cannot create manager with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Manager has been created." << endl;
        return 0;
    }

    unsigned int Manager::Create_ManagerT(Console* console, void** args){
        /* Function for creating manager - prepared to use with class console (args has pointers to arguments in the same order as in function
        Manager(const char* name, const char* surname, const char* country, Team* team);*/
        Manager* m = new Manager((const char *)args[1],(const char *)args[2],(const char *)args[3],(Team *)args[4]);
        unsigned int ret = console->register_variable((const char *)args[0], m);
        if (ret == 1 || m == nullptr){
            if (m != nullptr) delete m;
            (console->get_stream()) << "Lack of free memory. Manager cannot be created." << endl;
            return 2;
        } else if (ret == 3) {
            delete m;
            (console->get_stream()) << "Variable name reserved. Cannot create manager with given variable name." << endl;
            return 1;
        }

        (console->get_stream()) << "Manager has been created." << endl;
        return 0;
    }

    unsigned int Manager::get_name(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Manager *)args[0])->get_name() << endl;
        return 0;
    }
    unsigned int Manager::get_surname(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Manager *)args[0])->get_surname() << endl;
        return 0;
    }
    unsigned int Manager::get_country(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        (console->get_stream()) << ((Manager *)args[0])->get_country() << endl;
        return 0;
    }

    unsigned int Manager::get_team(Console* console, void** args){
        const char* name;
        if (args[0] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        if(((Manager *)args[0])->get_team() == nullptr){
            (console->get_stream()) << "Manager has no team." << endl;
            return 2;
        }
        name = console->get_variable((void*)((Manager *)args[0])->get_team());
        if (name == nullptr){
            (console->get_stream()) << "Critical error - problem with finding variable" << endl;
            return 3;
        }
        (console->get_stream()) << name << " " << ((Manager *)args[0])->get_team()->get_name() << endl;
        return 0;
    }

    unsigned int Manager::set_team(Console* console, void** args){
        if (args[0] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        if (args[1] == nullptr){
            (console->get_stream()) << "Team does not exist." << endl;
            return 1;
        }
        ((Manager *)args[0])->set_team((Team*)args[1]);
        return 0;
    }

    unsigned int Manager::delete_team(Console* console, void** args){ //delete team with players and trainer
        if (args[0] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        if (((Manager *)args[0])->get_team() != nullptr){
            (((Manager *)args[0]))->get_team()->delete_players(console);

            if (((Manager *)args[0])->get_team()->get_trainer() != nullptr) {
                    console->remove_variable((void *)((Manager *)args[0])->get_team()->get_trainer());
                    delete ((Manager *)args[0])->get_team()->get_trainer();
                    ((Manager *)args[0])->get_team()->set_trainer(nullptr);
            }
            delete ((Manager *)args[0])->get_team();

            ((Manager *)args[0])->set_team(nullptr);
        } else {
            (console->get_stream()) << "Manager has no team." << endl;
        }
        return 0;
    }

    unsigned int Manager::delete_team_players(Console* console, void** args){ //delete team with players
        if (args[0] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        if (((Manager *)args[0])->get_team() != nullptr){
            (((Manager *)args[0])->get_team())->delete_players(console);

            delete ((Manager *)args[0])->get_team();

            ((Manager *)args[0])->set_team(nullptr);
        } else {
            (console->get_stream()) << "Manager has no team." << endl;
        }
        return 0;
    }

    unsigned int Manager::match(Console* console, void** args){ //delete team with players
        unsigned int score;
        if (args[0] == nullptr || args[1] == nullptr){
            (console->get_stream()) << "Manager does not exist." << endl;
            return 1;
        }
        score = ((Manager *)args[0])->match(((Manager *)args[1]));
        if (score == 0xFFFFFFFE){
            cout << "Manager without a team." << endl;
            return 1;
        }
        if (score == 0xFFFFFFFF){
            cout << "Players not set on pitch." << endl;
            return 1;
        }

        cout << "Score: " << (unsigned int)(score / 1000) << ":" << score%1000 << endl;
        return 0;
    }
