#include <cstring>
#include <cstdio>
#include <iostream>

#include "console.hpp"
#include "test.hpp"
#include "manager.hpp"

using namespace std;

Console* console;

unsigned int help(Console* console, void** args);
unsigned int test(Console* console, void** args);

int main()
{
    console = new Console(cout);
    string str;

    if (console == nullptr){
        cout << "Error. No free memory." << endl;
        return 1;
    }

    console->register_instruction(Player::Create_Player,"create_player",5,8,8,8,8,8);
    console->register_instruction(Player::Create_Player,"create_p",5,8,8,8,8,8);
    console->register_instruction(Player::Create_Player,"cp",5,8,8,8,8,8);

    console->register_instruction(Player::Create_PlayerC,"create_player",6,8,8,8,8,8,7);
    console->register_instruction(Player::Create_PlayerC,"create_p",6,8,8,8,8,8,7);
    console->register_instruction(Player::Create_PlayerC,"cp",6,8,8,8,8,8,7);

    console->register_instruction(Player::Create_PlayerS,"create_player",11,8,8,8,8,8,9,4,9,9,9,9);
    console->register_instruction(Player::Create_PlayerS,"create_p",11,8,8,8,8,8,9,4,9,9,9,9);
    console->register_instruction(Player::Create_PlayerS,"cp",11,8,8,8,8,8,9,4,9,9,9,9);

    console->register_instruction(Player::Create_PlayerSC,"create_player",12,8,8,8,8,8,9,4,9,9,9,9,7);
    console->register_instruction(Player::Create_PlayerSC,"create_p",12,8,8,8,8,8,9,4,9,9,9,9,7);
    console->register_instruction(Player::Create_PlayerSC,"cp",12,8,8,8,8,8,9,4,9,9,9,9,7);

    console->register_instruction(Player::Create_PlayerSM,"create_player",14,8,8,8,8,8,9,4,9,9,9,9,6,6,6);
    console->register_instruction(Player::Create_PlayerSM,"create_p",14,8,8,8,8,8,9,4,9,9,9,9,6,6,6);
    console->register_instruction(Player::Create_PlayerSM,"cp",14,8,8,8,8,8,9,4,9,9,9,9,6,6,6);

    console->register_instruction(Player::Create_PlayerSMCards,"create_player",15,8,8,8,8,8,9,4,9,9,9,9,6,6,6,7);
    console->register_instruction(Player::Create_PlayerSMCards,"create_p",15,8,8,8,8,8,9,4,9,9,9,9,6,6,6,7);
    console->register_instruction(Player::Create_PlayerSMCards,"cp",15,8,8,8,8,8,9,4,9,9,9,9,6,6,6,7);

    console->register_instruction(Player::Create_PlayerSMCCards,"create_player",17,8,8,8,8,8,9,4,9,9,9,9,6,6,6,6,7);
    console->register_instruction(Player::Create_PlayerSMCCards,"create_p",17,8,8,8,8,8,9,4,9,9,9,9,6,6,6,6,7);
    console->register_instruction(Player::Create_PlayerSMCCards,"cp",17,8,8,8,8,8,9,4,9,9,9,9,6,6,6,6,7);

    console->register_instruction(Player::set_cost,"player_set_cost",2,11,7);
    console->register_instruction(Player::set_cost,"pset_cost",2,11,7);
    console->register_instruction(Player::set_cost,"psc",2,11,7);

    console->register_instruction(Player::set_wage,"player_set_wage",2,11,9);
    console->register_instruction(Player::set_wage,"pset_wage",2,11,9);
    console->register_instruction(Player::set_wage,"psw",2,11,9);

    console->register_instruction(Player::set_goals,"player_set_goals",2,11,6);
    console->register_instruction(Player::set_goals,"pset_goals",2,11,6);
    console->register_instruction(Player::set_goals,"psg",2,11,6);

    console->register_instruction(Player::set_assists,"player_set_assists",2,11,6);
    console->register_instruction(Player::set_assists,"pset_assists",2,11,6);
    console->register_instruction(Player::set_assists,"psa",2,11,6);

    console->register_instruction(Player::set_matches,"player_set_matches",2,11,6);
    console->register_instruction(Player::set_matches,"pset_matches",2,11,6);
    console->register_instruction(Player::set_matches,"psm",2,11,6);

    console->register_instruction(Player::set_red_cards,"player_set_red_cards",2,11,6);
    console->register_instruction(Player::set_red_cards,"pset_red_cards",2,11,6);
    console->register_instruction(Player::set_red_cards,"psrc",2,11,6);

    console->register_instruction(Player::set_yellow_cards,"player_set_yellow_cards",2,11,6);
    console->register_instruction(Player::set_yellow_cards,"pset_yellow_cards",2,11,6);
    console->register_instruction(Player::set_yellow_cards,"psyc",2,11,6);

    console->register_instruction(Player::set_attack,"player_set_attack",2,11,9);
    console->register_instruction(Player::set_attack,"pset_attack",2,11,9);
    console->register_instruction(Player::set_attack,"psatk",2,11,9);

    console->register_instruction(Player::set_defense,"player_set_defense",2,11,9);
    console->register_instruction(Player::set_defense,"pset_defense",2,11,9);
    console->register_instruction(Player::set_defense,"psdef",2,11,9);

    console->register_instruction(Player::set_shoot,"player_set_shoot",2,11,9);
    console->register_instruction(Player::set_shoot,"pset_shoot",2,11,9);
    console->register_instruction(Player::set_shoot,"psshoot",2,11,9);

    console->register_instruction(Player::set_corner,"player_set_corner",2,11,9);
    console->register_instruction(Player::set_corner,"pset_corner",2,11,9);
    console->register_instruction(Player::set_corner,"pscorner",2,11,9);

    console->register_instruction(Player::get_name,"player_get_name",1,11);
    console->register_instruction(Player::get_name,"pget_name",1,11);
    console->register_instruction(Player::get_name,"pgn",1,11);

    console->register_instruction(Player::get_surname,"player_get_surname",1,11);
    console->register_instruction(Player::get_surname,"pget_surname",1,11);
    console->register_instruction(Player::get_surname,"pgs",1,11);

    console->register_instruction(Player::get_country,"player_get_country",1,11);
    console->register_instruction(Player::get_country,"pget_country",1,11);
    console->register_instruction(Player::get_country,"pgcountry",1,11);

    console->register_instruction(Player::get_cost,"player_get_cost",1,11);
    console->register_instruction(Player::get_cost,"pget_cost",1,11);
    console->register_instruction(Player::get_cost,"pgc",1,11);

    console->register_instruction(Player::get_wage,"player_get_wage",1,11);
    console->register_instruction(Player::get_wage,"pget_wage",1,11);
    console->register_instruction(Player::get_wage,"pgw",1,11);

    console->register_instruction(Player::get_goals,"player_get_goals",1,11);
    console->register_instruction(Player::get_goals,"pget_goals",1,11);
    console->register_instruction(Player::get_goals,"pgg",1,11);

    console->register_instruction(Player::get_assists,"player_get_assists",1,11);
    console->register_instruction(Player::get_assists,"pget_assists",1,11);
    console->register_instruction(Player::get_assists,"pga",1,11);

    console->register_instruction(Player::get_matches,"player_get_matches",1,11);
    console->register_instruction(Player::get_matches,"pget_matches",1,11);
    console->register_instruction(Player::get_matches,"pgm",1,11);

    console->register_instruction(Player::get_red_cards,"player_get_red_cards",1,11);
    console->register_instruction(Player::get_red_cards,"pget_red_cards",1,11);
    console->register_instruction(Player::get_red_cards,"pgrc",1,11);

    console->register_instruction(Player::get_yellow_cards,"player_get_yellow_cards",1,11);
    console->register_instruction(Player::get_yellow_cards,"pget_yellow_cards",1,11);
    console->register_instruction(Player::get_yellow_cards,"pgyc",1,11);

    console->register_instruction(Player::get_attack,"player_get_attack",1,11);
    console->register_instruction(Player::get_attack,"pget_attack",1,11);
    console->register_instruction(Player::get_attack,"pgatk",1,11);

    console->register_instruction(Player::get_defense,"player_get_defense",1,11);
    console->register_instruction(Player::get_defense,"pget_defense",1,11);
    console->register_instruction(Player::get_defense,"pgdef",1,11);

    console->register_instruction(Player::get_shoot,"player_get_shoot",1,11);
    console->register_instruction(Player::get_shoot,"pget_shoot",1,11);
    console->register_instruction(Player::get_shoot,"pgshoot",1,11);

    console->register_instruction(Player::get_corner,"player_get_corner",1,11);
    console->register_instruction(Player::get_corner,"pget_corner",1,11);
    console->register_instruction(Player::get_corner,"pgcorner",1,11);

    console->register_instruction(Player::add_goals,"player_add_goals",2,11,6);
    console->register_instruction(Player::add_goals,"padd_goals",2,11,6);
    console->register_instruction(Player::add_goals,"pag",2,11,6);

    console->register_instruction(Player::add_assists,"player_add_assists",2,11,6);
    console->register_instruction(Player::add_assists,"padd_assists",2,11,6);
    console->register_instruction(Player::add_assists,"paa",2,11,6);

    console->register_instruction(Player::add_matches,"player_add_matches",2,11,6);
    console->register_instruction(Player::add_matches,"padd_matches",2,11,6);
    console->register_instruction(Player::add_matches,"pam",2,11,6);

    console->register_instruction(Player::add_red_cards,"player_add_red_cards",2,11,6);
    console->register_instruction(Player::add_red_cards,"pset_add_cards",2,11,6);
    console->register_instruction(Player::add_red_cards,"parc",2,11,6);

    console->register_instruction(Player::add_yellow_cards,"player_add_yellow_cards",2,11,6);
    console->register_instruction(Player::add_yellow_cards,"padd_yellow_cards",2,11,6);
    console->register_instruction(Player::add_yellow_cards,"payc",2,11,6);

    console->register_instruction(Player::add_attack,"player_add_attack",2,11,9);
    console->register_instruction(Player::add_attack,"padd_attack",2,11,9);
    console->register_instruction(Player::add_attack,"paatk",2,11,9);

    console->register_instruction(Player::add_defense,"player_add_defense",2,11,9);
    console->register_instruction(Player::add_defense,"padd_defense",2,11,9);
    console->register_instruction(Player::add_defense,"padef",2,11,9);

    console->register_instruction(Player::add_defense,"player_add_shoot",2,11,9);
    console->register_instruction(Player::add_defense,"padd_shoot",2,11,9);
    console->register_instruction(Player::add_defense,"pashoot",2,11,9);

    console->register_instruction(Player::add_defense,"player_add_corner",2,11,9);
    console->register_instruction(Player::add_defense,"padd_corner",2,11,9);
    console->register_instruction(Player::add_defense,"pacorner",2,11,9);


    console->register_instruction(Team::Create_Team,"create_team",5,8,8,8,8,8);
    console->register_instruction(Team::Create_Team,"create_t",5,8,8,8,8,8);
    console->register_instruction(Team::Create_Team,"ct",5,8,8,8,8,8);

    console->register_instruction(Team::Create_TeamM,"create_team",6,8,8,8,8,8,7);
    console->register_instruction(Team::Create_TeamM,"create_t",6,8,8,8,8,8,7);
    console->register_instruction(Team::Create_TeamM,"ct",6,8,8,8,8,8,7);

    console->register_instruction(Team::Create_TeamS,"create_team",8,8,8,8,8,8,6,6,6);
    console->register_instruction(Team::Create_TeamS,"create_t",8,8,8,8,8,8,6,6,6);
    console->register_instruction(Team::Create_TeamS,"ct",8,8,8,8,8,8,6,6,6);

    console->register_instruction(Team::Create_TeamSM,"create_team",9,8,8,8,8,8,6,6,6,7);
    console->register_instruction(Team::Create_TeamSM,"create_t",9,8,8,8,8,8,6,6,6,7);
    console->register_instruction(Team::Create_TeamSM,"ct",9,8,8,8,8,8,6,6,6,7);

    console->register_instruction(Team::set_money,"Team::set_money",2,11,3);
    console->register_instruction(Team::set_money,"tset_money",2,11,3);
    console->register_instruction(Team::set_money,"tsm",2,11,3);

    console->register_instruction(Team::set_goals,"team_set_goals",2,11,6);
    console->register_instruction(Team::set_goals,"tset_goals",2,11,6);
    console->register_instruction(Team::set_goals,"tsg",2,11,6);

    console->register_instruction(Team::set_matches,"team_set_matches",2,11,6);
    console->register_instruction(Team::set_matches,"tset_matches",2,11,6);
    console->register_instruction(Team::set_matches,"tsm",2,11,6);

    console->register_instruction(Team::set_red_cards,"team_set_red_cards",2,11,6);
    console->register_instruction(Team::set_red_cards,"tset_red_cards",2,11,6);
    console->register_instruction(Team::set_red_cards,"tsrc",2,11,6);

    console->register_instruction(Team::set_yellow_cards,"team_set_yellow_cards",2,11,6);
    console->register_instruction(Team::set_yellow_cards,"tset_yellow_cards",2,11,6);
    console->register_instruction(Team::set_yellow_cards,"tsyc",2,11,6);

    console->register_instruction(Team::get_name,"team_get_name",1,11);
    console->register_instruction(Team::get_name,"tget_name",1,11);
    console->register_instruction(Team::get_name,"tgn",1,11);

    console->register_instruction(Team::get_city,"team_get_city",1,11);
    console->register_instruction(Team::get_city,"tget_city",1,11);
    console->register_instruction(Team::get_city,"tgcity",1,11);

    console->register_instruction(Team::get_country,"team_get_country",1,11);
    console->register_instruction(Team::get_country,"tget_country",1,11);
    console->register_instruction(Team::get_country,"tgcountry",1,11);

    console->register_instruction(Team::get_formation,"team_get_formation",1,11);
    console->register_instruction(Team::get_formation,"tget_formation",1,11);
    console->register_instruction(Team::get_formation,"tgf",1,11);

    console->register_instruction(Team::get_money,"team_get_money",1,11);
    console->register_instruction(Team::get_money,"tget_money",1,11);
    console->register_instruction(Team::get_money,"tgm",1,11);

    console->register_instruction(Team::get_goals,"team_get_goals",1,11);
    console->register_instruction(Team::get_goals,"tget_goals",1,11);
    console->register_instruction(Team::get_goals,"tgg",1,11);

    console->register_instruction(Team::get_matches,"team_get_matches",1,11);
    console->register_instruction(Team::get_matches,"tget_matches",1,11);
    console->register_instruction(Team::get_matches,"tgm",1,11);

    console->register_instruction(Team::get_red_cards,"team_get_red_cards",1,11);
    console->register_instruction(Team::get_red_cards,"tget_red_cards",1,11);
    console->register_instruction(Team::get_red_cards,"tgrc",1,11);

    console->register_instruction(Team::get_yellow_cards,"team_get_yellow_cards",1,11);
    console->register_instruction(Team::get_yellow_cards,"tget_yellow_cards",1,11);
    console->register_instruction(Team::get_yellow_cards,"tgyc",1,11);

    console->register_instruction(Team::add_goals,"team_add_goals",3,11,11,6);
    console->register_instruction(Team::add_goals,"tadd_goals",3,11,11,6);
    console->register_instruction(Team::add_goals,"tag",3,11,11,6);

    console->register_instruction(Team::add_assists,"team_add_assists",3,11,11,6);
    console->register_instruction(Team::add_assists,"tadd_assists",3,11,11,6);
    console->register_instruction(Team::add_assists,"taa",3,11,11,6);

    console->register_instruction(Team::add_matches,"team_add_matches",2,11,6);
    console->register_instruction(Team::add_matches,"tadd_matches",2,11,6);
    console->register_instruction(Team::add_matches,"tam",2,11,6);

    console->register_instruction(Team::add_red_cards,"team_add_red_cards",3,11,11,6);
    console->register_instruction(Team::add_red_cards,"tset_add_cards",3,11,11,6);
    console->register_instruction(Team::add_red_cards,"tarc",3,11,11,6);

    console->register_instruction(Team::add_yellow_cards,"team_add_yellow_cards",3,11,11,6);
    console->register_instruction(Team::add_yellow_cards,"tadd_yellow_cards",3,11,11,6);
    console->register_instruction(Team::add_yellow_cards,"tayc",3,11,11,6);

    console->register_instruction(Team::get_trainer,"team_get_trainer",1,11);
    console->register_instruction(Team::get_trainer,"tget_trainer",1,11);
    console->register_instruction(Team::get_trainer,"tgt",1,11);

    console->register_instruction(Team::set_trainer,"team_set_trainer",2,11,11);
    console->register_instruction(Team::set_trainer,"tset_trainer",2,11,11);
    console->register_instruction(Team::set_trainer,"tst",2,11,11);

    console->register_instruction(Team::get_player_position,"team_get_player_position",2,11,6);
    console->register_instruction(Team::get_player_position,"tget_player_position",2,11,6);
    console->register_instruction(Team::get_player_position,"tgpp",2,11,6);

    console->register_instruction(Team::set_player_position,"team_set_player_position",3,11,11,6);
    console->register_instruction(Team::set_player_position,"tset_player_position",3,11,11,6);
    console->register_instruction(Team::set_player_position,"tspp",3,11,11,6);

    console->register_instruction(Team::add_player,"team_add_player",2,11,11);
    console->register_instruction(Team::add_player,"tadd_player",2,11,11);
    console->register_instruction(Team::add_player,"tap",2,11,11);

    console->register_instruction(Team::add_player_position,"team_add_player_position",3,11,11,6);
    console->register_instruction(Team::add_player_position,"tadd_player_position",3,11,11,6);
    console->register_instruction(Team::add_player_position,"tapp",3,11,11,6);

    console->register_instruction(Team::remove_player,"team_remove_player",2,11,11);
    console->register_instruction(Team::remove_player,"tremove_player",2,11,11);
    console->register_instruction(Team::remove_player,"trp",2,11,11);

    console->register_instruction(Team::find_player,"team_find_player",3,11,8,8);
    console->register_instruction(Team::find_player,"tfind_player",3,11,8,8);
    console->register_instruction(Team::find_player,"tfp",3,11,8,8);

    console->register_instruction(Team::find_player_country,"team_find_playerc",4,11,8,8,8);
    console->register_instruction(Team::find_player_country,"tfind_playerc",4,11,8,8,8);
    console->register_instruction(Team::find_player_country,"tfpc",4,11,8,8,8);

    console->register_instruction(Team::buy,"team_buy",3,11,11,11);
    console->register_instruction(Team::buy,"tbuy",3,11,11,11);
    console->register_instruction(Team::buy,"tb",3,11,11,11);

    console->register_instruction(Team::buy_name,"team_buy",4,11,11,8,8);
    console->register_instruction(Team::buy_name,"tbuy",4,11,11,8,8);
    console->register_instruction(Team::buy_name,"tb",4,11,11,8,8);

    console->register_instruction(Team::buy_name,"team_buy",5,11,11,8,8,8);
    console->register_instruction(Team::buy_name,"tbuy",5,11,11,8,8,8);
    console->register_instruction(Team::buy_name,"tb",5,11,11,8,8,8);

    console->register_instruction(Team::transfer,"team_transfer",3,11,11,11);
    console->register_instruction(Team::transfer,"ttransfer",3,11,11,11);
    console->register_instruction(Team::transfer,"tt",3,11,11,11);

    console->register_instruction(Team::transfer_name,"team_transfer",4,11,11,8,8);
    console->register_instruction(Team::transfer_name,"ttransfer",4,11,11,8,8);
    console->register_instruction(Team::transfer_name,"tt",4,11,11,8,8);

    console->register_instruction(Team::transfer_name,"team_transfer",5,11,11,8,8,8);
    console->register_instruction(Team::transfer_name,"ttransfer",5,11,11,8,8,8);
    console->register_instruction(Team::transfer_name,"tt",5,11,11,8,8,8);

    console->register_instruction(Team::train,"team_train",1,11);
    console->register_instruction(Team::train,"ttrain",1,11);
    console->register_instruction(Team::train,"ttr",1,11);

    console->register_instruction(Trainer::Create_Trainer,"create_trainer",4,8,8,8,8);
    console->register_instruction(Trainer::Create_Trainer,"create_tr",4,8,8,8,8);
    console->register_instruction(Trainer::Create_Trainer,"ctr",4,8,8,8,8);

    console->register_instruction(Trainer::Create_TrainerD,"create_trainer",5,8,8,8,8,8);
    console->register_instruction(Trainer::Create_TrainerD,"create_tr",5,8,8,8,8,8);
    console->register_instruction(Trainer::Create_TrainerD,"ctr",5,8,8,8,8,8);

    console->register_instruction(Trainer::get_name,"trainer_get_name",1,11);
    console->register_instruction(Trainer::get_name,"trget_name",1,11);
    console->register_instruction(Trainer::get_name,"trgn",1,11);

    console->register_instruction(Trainer::get_surname,"trainer_get_surname",1,11);
    console->register_instruction(Trainer::get_surname,"trget_surname",1,11);
    console->register_instruction(Trainer::get_surname,"trgs",1,11);

    console->register_instruction(Trainer::get_country,"trainer_get_country",1,11);
    console->register_instruction(Trainer::get_country,"trget_country",1,11);
    console->register_instruction(Trainer::get_country,"trgcountry",1,11);

    console->register_instruction(Trainer::get_attack_multiplier,"trainer_get_attack_multiplier",1,11);
    console->register_instruction(Trainer::get_attack_multiplier,"trget_attack_multiplier",1,11);
    console->register_instruction(Trainer::get_attack_multiplier,"trgam",1,11);

    console->register_instruction(Trainer::get_defense_multiplier,"trainer_get_defense_multiplier",1,11);
    console->register_instruction(Trainer::get_defense_multiplier,"trget_defense_multiplier",1,11);
    console->register_instruction(Trainer::get_defense_multiplier,"trgdm",1,11);

    console->register_instruction(Trainer::get_shoot_multiplier,"trainer_get_shoot_multiplier",1,11);
    console->register_instruction(Trainer::get_shoot_multiplier,"trget_shoot_multiplier",1,11);
    console->register_instruction(Trainer::get_shoot_multiplier,"trgsm",1,11);

    console->register_instruction(Trainer::get_corner_multiplier,"trainer_get_corner_multiplier",1,11);
    console->register_instruction(Trainer::get_corner_multiplier,"trget_corner_multiplier",1,11);
    console->register_instruction(Trainer::get_corner_multiplier,"trgcm",1,11);

    console->register_instruction(Trainer::set_attack_multiplier,"trainer_set_attack_multiplier",2,11,9);
    console->register_instruction(Trainer::set_attack_multiplier,"trset_attack_multiplier",2,11,9);
    console->register_instruction(Trainer::set_attack_multiplier,"trsam",2,11,9);

    console->register_instruction(Trainer::set_defense_multiplier,"trainer_set_defense_multiplier",2,11,9);
    console->register_instruction(Trainer::set_defense_multiplier,"trset_defense_multiplier",2,11,9);
    console->register_instruction(Trainer::set_defense_multiplier,"trsdm",2,11,9);

    console->register_instruction(Trainer::set_shoot_multiplier,"trainer_set_shoot_multiplier",2,11,9);
    console->register_instruction(Trainer::set_shoot_multiplier,"trset_shoot_multiplier",2,11,9);
    console->register_instruction(Trainer::set_shoot_multiplier,"trssm",2,11,9);

    console->register_instruction(Trainer::set_corner_multiplier,"trainer_set_corner_multiplier",2,11,9);
    console->register_instruction(Trainer::set_corner_multiplier,"trset_corner_multiplier",2,11,9);
    console->register_instruction(Trainer::set_corner_multiplier,"trscm",2,11,9);

    console->register_instruction(Manager::Create_Manager,"create_manager",4,8,8,8,8);
    console->register_instruction(Manager::Create_Manager,"create_m",4,8,8,8,8);
    console->register_instruction(Manager::Create_Manager,"cm",4,8,8,8,8);

    console->register_instruction(Manager::Create_ManagerT,"create_manager",5,8,8,8,8,11);
    console->register_instruction(Manager::Create_ManagerT,"create_mr",5,8,8,8,8,11);
    console->register_instruction(Manager::Create_ManagerT,"cmr",5,8,8,8,8,11);

    console->register_instruction(Manager::get_name,"manager_get_name",1,11);
    console->register_instruction(Manager::get_name,"mget_name",1,11);
    console->register_instruction(Manager::get_name,"mgn",1,11);

    console->register_instruction(Manager::get_surname,"trainer_get_surname",1,11);
    console->register_instruction(Manager::get_surname,"mget_surname",1,11);
    console->register_instruction(Manager::get_surname,"mgs",1,11);

    console->register_instruction(Manager::get_country,"manager_get_country",1,11);
    console->register_instruction(Manager::get_country,"mget_country",1,11);
    console->register_instruction(Manager::get_country,"mgcountry",1,11);

    console->register_instruction(Manager::set_team,"manager_set_team",2,11,11);
    console->register_instruction(Manager::set_team,"mset_team",2,11,11);
    console->register_instruction(Manager::set_team,"mst",2,11,11);

    console->register_instruction(Manager::get_team,"manager_get_team",1,11);
    console->register_instruction(Manager::get_team,"mget_team",1,11);
    console->register_instruction(Manager::get_team,"mgt",1,11);

    console->register_instruction(Manager::delete_team,"manager_delete_team_all",1,11);
    console->register_instruction(Manager::delete_team,"mdelete_team_all",1,11);
    console->register_instruction(Manager::delete_team,"mdta",1,11);

    console->register_instruction(Manager::delete_team_players,"manager_delete_team",1,11);
    console->register_instruction(Manager::delete_team_players,"mdelete_team",1,11);
    console->register_instruction(Manager::delete_team_players,"mdt",1,11);

    console->register_instruction(Manager::match,"manager_match",2,11,11);
    console->register_instruction(Manager::match,"mmatch",2,11,11);
    console->register_instruction(Manager::match,"match",2,11,11);

    console->register_instruction(help,"help",0);
    console->register_instruction(help,"h",0);

    console->register_instruction(test,"test",0);
    console->register_instruction(test,"t",0);

    cout << "Write an instruction:" << endl;
    while(1){
        getline(cin,str);
        if (str == "exit" || str == "quit") break;
        console->parse(str.c_str());
    }

    return 0;
}

unsigned int help(Console* console, void** args){
    ostream &os = console->get_stream();
    os << "Creating player:" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country]" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country] [cost]" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country] [wage] [growth] [attack] [defense] [shoot] [corner]" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country] [wage] [growth] [attack] [defense] [shoot] [corner] [cost]" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country] [wage] [growth] [attack] [defense] [shoot] [corner] [matches] [goals] [assists]" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country] [wage] [growth] [attack] [defense] [shoot] [corner] [matches] [goals] [assists] [cost]" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country] [wage] [growth] [attack] [defense] [shoot] [corner] [matches] [goals] [assists] [red_cards] [yellow_cards]" << endl;
    os << "create_player [variable_name] [name] [surname] [date_of_birth] [country] [wage] [growth] [attack] [defense] [shoot] [corner] [matches] [goals] [assists] [red_cards] [yellow_cards] [cost]" << endl;

    os << endl << "Set player information:" << endl;
    os << "player_set_cost [variable_name] [cost]" << endl;
    os << "player_set_wage [variable_name] [wage]" << endl;
    os << "player_set_assists [variable_name] [assists]" << endl;
    os << "player_set_goals [variable_name] [goals]" << endl;
    os << "player_set_matches [variable_name] [matches]" << endl;
    os << "player_set_red_cards [variable_name] [red_cards]" << endl;
    os << "player_set_yellow_cards [variable_name] [yellow_cards]" << endl;
    os << "player_set_attack [variable_name] [attack]" << endl;
    os << "player_set_defense [variable_name] [defense]" << endl;
    os << "player_set_shoot [variable_name] [shoot]" << endl;
    os << "player_set_corner [variable_name] [corner]" << endl;

    os << endl << "Get player information:" << endl;
    os << "player_get_name [variable_name]" << endl;
    os << "player_get_surname [variable_name]" << endl;
    os << "player_get_country [variable_name]" << endl;
    os << "player_get_wage [variable_name]" << endl;
    os << "player_get_goals [variable_name]" << endl;
    os << "player_get_assists [variable_name]" << endl;
    os << "player_get_matches [variable_name]" << endl;
    os << "player_get_red_cards [variable_name]" << endl;
    os << "player_get_yellow_cards [variable_name]" << endl;
    os << "player_get_attack [variable_name]" << endl;
    os << "player_get_defense [variable_name]" << endl;
    os << "player_get_shoot [variable_name]" << endl;
    os << "player_get_corner [variable_name]" << endl;

    os << endl << "Add to player stats:" << endl;
    os << "player_add_cost [variable_name] [cost]" << endl;
    os << "player_add_wage [variable_name] [wage]" << endl;
    os << "player_add_assists [variable_name] [assists]" << endl;
    os << "player_add_goals [variable_name] [goals]" << endl;
    os << "player_add_matches [variable_name] [matches]" << endl;
    os << "player_add_red_cards [variable_name] [red_cards]" << endl;
    os << "player_add_yellow_cards [variable_name] [yellow_cards]" << endl;
    os << "player_add_attack [variable_name] [attack]" << endl;
    os << "player_add_defense [variable_name] [defense]" << endl;
    os << "player_add_shoot [variable_name] [shoot]" << endl;
    os << "player_add_corner [variable_name] [corner]" << endl;

    os << endl << "Creating team:" << endl;
    os << "create_team [variable_name] [name] [country] [city] [formation]" << endl;
    os << "create_team [variable_name] [name] [country] [city] [formation] [money]" << endl;
    os << "create_team [variable_name] [name] [country] [city] [formation] [matches] [goals] [red_cards] [yellow_cards]" << endl;
    os << "create_team [variable_name] [name] [country] [city] [formation] [matches] [goals] [red_cards] [yellow_cards] [money]" << endl;

    os << endl << "Set team information:" << endl;
    os << "team_set_money [variable_name] [money]" << endl;
    os << "team_set_goals [variable_name] [goals]" << endl;
    os << "team_set_matches [variable_name] [matches]" << endl;
    os << "team_set_red_cards [variable_name] [red_cards]" << endl;
    os << "team_set_yellow_cards [variable_name] [yellow_cards]" << endl;
    os << "team_set_trainer [team_variable_name] [trainer_variable_name]" << endl;
    os << "team_set_player_position [team_variable_name] [player_variable_name] [position]" << endl;
    os << "team_add_player [team_variable_name] [player_variable_name]" << endl;
    os << "team_add_player_position [team_variable_name] [player_variable_name] [position]" << endl;

    os << endl << "Get team information:" << endl;
    os << "team_get_name [variable_name]" << endl;
    os << "team_get_country [variable_name]" << endl;
    os << "team_get_city [variable_name]" << endl;
    os << "team_get_formation [variable_name]" << endl;
    os << "team_get_money [variable_name]" << endl;
    os << "team_get_goals [variable_name]" << endl;
    os << "team_get_matches [variable_name]" << endl;
    os << "team_get_red_cards [variable_name]" << endl;
    os << "team_get_yellow_cards [variable_name]" << endl;
    os << "team_get_trainer [team_variable_name]" << endl;
    os << "team_get_player_position [team_variable_name] position]" << endl;
    os << "team_find_player [team_variable_name] [player_name] [player_surname]" << endl;
    os << "team_find_player [team_variable_name] [player_name] [player_surname] [player_country]" << endl;

    os << endl << "Add to team statistics:" << endl;
    os << "team_add_money [team_variable_name] [player_variable_name] [money]" << endl;
    os << "team_add_assists [team_variable_name] [player_variable_name] [yellow_cards]" << endl;
    os << "team_add_goals [team_variable_name] [player_variable_name] [goals]" << endl;
    os << "team_add_matches [team_variable_name] [player_variable_name] [matches]" << endl;
    os << "team_add_red_cards [team_variable_name] [player_variable_name] [red_cards]" << endl;
    os << "team_add_yellow_cards [team_variable_name] [player_variable_name] [yellow_cards]" << endl;

    os << endl << "Other team management functions:" << endl;
    os << "team_remove_player [team_variable_name] [player_variable_name]" << endl;
    os << "team_buy [team_variable_name_buying] [team_variable_name_selling] [player_variable_name]" << endl;
    os << "team_buy [team_variable_name_buying] [team_variable_name_selling] [player_name] [player_surname]" << endl;
    os << "team_buy [team_variable_name_buying] [team_variable_name_selling] [player_name] [player_surname] [player_country]" << endl;

    os << "team_transfer [team_variable_name_to_transfer] [team_variable_name_from_transfer] [player_variable_name]" << endl;
    os << "team_transfer [team_variable_name_to_transfer] [team_variable_name_from_transfer] [player_name] [player_surname]" << endl;
    os << "team_transfer [team_variable_name_to_transfer] [team_variable_name_from_transfer] [player_name] [player_surname] [player_country]" << endl;
    os << "team_train [team_variable_name]" << endl;

    os << endl << "Creating trainer" << endl;
    os << "create_trainer [variable_name] [name] [surname] [country]" << endl;
    os << "create_trainer [variable_name] [name] [surname] [country] [date_of_birth]" << endl;

    os << endl << "Set trainer information:" << endl;
    os << "player_set_attack_multiplier [variable_name] [attack_multiplier]" << endl;
    os << "player_set_defense_multiplier [variable_name] [defense_multiplier]" << endl;
    os << "player_set_shoot_multiplier [variable_name] [shoot_multiplier]" << endl;
    os << "player_set_corner_multiplier [variable_name] [corner_multiplier]" << endl;

    os << endl << "Get trainer information:" << endl;
    os << "player_get_name [variable_name]" << endl;
    os << "player_get_surname [variable_name]" << endl;
    os << "player_get_country [variable_name]" << endl;
    os << "player_get_attack_multiplier [variable_name]" << endl;
    os << "player_get_defense_multiplier [variable_name]" << endl;
    os << "player_get_shoot_multiplier [variable_name]" << endl;
    os << "player_get_corner_multiplier [variable_name]" << endl;

    os << endl << "Creating manager" << endl;
    os << "create_manager [variable_name] [name] [surname] [country]" << endl;
    os << "create_manager [variable_name] [name] [surname] [country] [team_variable_name]" << endl;

    os << endl << "Set manager information:" << endl;
    os << "manager_set_team [manager_variable_name] [team_variable_name]" << endl;

    os << endl << "Get manager information:" << endl;
    os << "manager_get_team [variable_name] " << endl;
    os << "player_get_surname [variable_name]" << endl;
    os << "player_get_country [variable_name]" << endl;
    os << "player_get_attack_multiplier [variable_name]" << endl;
    os << "player_get_defense_multiplier [variable_name]" << endl;
    os << "player_get_shoot_multiplier [variable_name]" << endl;
    os << "player_get_corner_multiplier [variable_name]" << endl;

    os << endl << "Other manager management functions:" << endl;
    os << "manager_delete_team [variable_name] - delete team players [player variables will be deleted]" << endl;
    os << "manager_delete_team_all [variable_name] - delete team players and trainer [variables will be delete without manager]" << endl;
    os << "match [manager_variable_name1] [manager_variable_name2]" << endl;

    return 0;
}

unsigned int test(Console* console, void** args){
    Test::manager_console(*console);

    return 0;
}
