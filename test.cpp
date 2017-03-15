#include <iostream>

#include "console.hpp"
#include "test.hpp"

using namespace std;

    void Test::player_test(){
        Player p1("Lionel", "Messi", "1987-06-24", "Argentina",67,169,90,63,75,65,561,491,195,1,70,580000000);
        p1.add_matches(3);
        p1.add_yellow_cards();

        cout << "Test function" << endl;
        cout << "Player's name: " << p1.get_name() << endl;
        cout << "Player's surname: " << p1.get_surname() << endl;
        cout << "Player's country: " << p1.get_country() << endl;

        cout << "Player's matches count: " << p1.get_matches() << endl;
        cout << "Player's yellow cards: " << p1.get_yellow_cards() << endl;
    }

    void Test::team_test(){ //test function for class Team
        Team t1("FC BARCELONA", "SPAIN", "BARCELONA", "4-3-3", 700000000);
        Team t2("TEST Team", "POLAND", "WARSAW", "4-3-3", 800000000);
        Player p1("Lionel", "Messi", "1987-06-24", "Argentina",67,169,90,63,75,65,561,491,195,1,70,580000000);
        t1+=p1;
        //t1.add_player(&p1, 10);

        cout << "Test function" << endl;
        cout << "Goals before match: " << t1.get_goals() << endl;
        t1.add_goals("Lionel", "Messi", 3);
        cout << "Goals after match: " << t1.get_goals() << endl;
        cout << "Account of TEST Team: " << t2.get_money() << endl;
        t2.buy(&t1, "Lionel", "Messi");
        cout << "Account of FC BARCELONA after selling a player: " << t1.get_money() << endl;
        cout << "Account of TEST Team after buying a player: " << t2.get_money() << endl;

        if (t1.find("Lionel", "Messi") == nullptr) cout << "Buying players works." << endl;
        else cout << "Buying players is not working." << endl;
    }

    void Test::trainer_test(){
        Trainer* t;
        t = new Trainer("George", "Brooklyn", "the USA", "1990-03-09");

        cout << "Test function" << endl;
        cout << "Trainer name: " << t->get_name() << endl;
        cout << "Trainer surname: " << t->get_surname() << endl;
        cout << "Trainer country: " << t->get_country() << endl;
    }

    void Test::manager_test(){
        Manager m("Adam", "Smith", "SPAIN");
        Team t("FC BARCELONA", "SPAIN", "BARCELONA", "4-3-3", 700000000);
        Player p("Lionel", "Messi", "1987-06-24", "Argentina",67,169,90,63,75,65,561,491,195,1,70,580000000);

        m.set_team(&t);
        t.add_player(&p, 10);
        m.match(1, "Lionel", "Messi", 3, 1, 0, 1);

        cout << "Test function" << endl;
        cout << "Goals after match: " << t.get_goals() << endl;
        cout << "Red cards after match: " << t.get_red_cards() << endl;
        cout << "Yellow cards after match: " << t.get_yellow_cards() << endl << endl;
        cout << "Player's goals after match: " << p.get_goals() << endl;
        cout << "Player's red cards after match: " << p.get_red_cards() << endl;
        cout << "Player's yellow cards after match: " << p.get_yellow_cards() << endl;
        cout << "Player's assists after match: " << p.get_assists() << endl;
    }

    unsigned int console_test_function(Console* console, void** args){
        cout << "Test function" << endl;
        cout << *(short *)(args[0]) << endl;
        cout << *(int *)(args[1]) << endl;
        cout << *(int *)(args[2]) << endl;
        cout << (char *)(args[3]) << endl;
        cout << *(int *)(args[4]) << endl;
        return 1;
    }

    void Test::console_test(){
        Console console(cout);

        int a = 2;

        cout << console.register_instruction(console_test_function,"Test", 5, 1, 2, 2, 8, 11) << endl;
        cout << console.register_variable("x", &a) << endl;

        console.parse("Test 123 456 789 :D x");
    }

    void Test::manager_console(Console &console){
        //main has to been run

        console.parse("cp p1 name1 surname1 0000-00-00 country");
        console.parse("cp p2 name2 surname2 0000-00-00 country");
        console.parse("cp p3 name3 surname3 0000-00-00 country");
        console.parse("cp p4 name4 surname4 0000-00-00 country");
        console.parse("cp p5 name5 surname5 0000-00-00 country");
        console.parse("cp p6 name6 surname6 0000-00-00 country");
        console.parse("cp p7 name7 surname7 0000-00-00 country");
        console.parse("cp p8 name8 surname8 0000-00-00 country");
        console.parse("cp p9 name9 surname9 0000-00-00 country");
        console.parse("cp p10 name10 surname10 0000-00-00 country");
        console.parse("cp p11 name11 surname11 0000-00-00 country");
        console.parse("cp p12 name12 surname12 0000-00-00 country");
        console.parse("cp p13 name13 surname13 0000-00-00 country");
        console.parse("cp p14 name14 surname14 0000-00-00 country");
        console.parse("cp p15 name15 surname15 0000-00-00 country");
        console.parse("cp p16 name16 surname16 0000-00-00 country");
        console.parse("cp p17 name17 surname17 0000-00-00 country");
        console.parse("cp p18 name18 surname18 0000-00-00 country");
        console.parse("cp p19 name19 surname19 0000-00-00 country");
        console.parse("cp p20 name20 surname20 0000-00-00 country");
        console.parse("cp p21 name21 surname21 0000-00-00 country");
        console.parse("cp p22 name22 surname22 0000-00-00 country");

        console.parse("ctr tr1 name1 surname1 country");
        console.parse("ctr tr2 name1 surname1 country");

        console.parse("trainer_set_attack_multiplier tr1 0.95");
        console.parse("trainer_set_defense_multiplier tr2 0.85");

        console.parse("ct t1 \"Team 1\" country city 4-3-3");
        console.parse("ct t2 \"Team 2\" country city 4-3-3");

        console.parse("tapp t1 p1 0");
        console.parse("tapp t1 p2 1");
        console.parse("tapp t1 p3 2");
        console.parse("tapp t1 p4 3");
        console.parse("tapp t1 p5 4");
        console.parse("tapp t1 p6 5");
        console.parse("tapp t1 p7 6");
        console.parse("tapp t1 p8 7");
        console.parse("tapp t1 p9 8");
        console.parse("tapp t1 p10 9");
        console.parse("tapp t1 p11 10");

        console.parse("tapp t2 p12 0");
        console.parse("tapp t2 p13 1");
        console.parse("tapp t2 p14 2");
        console.parse("tapp t2 p15 3");
        console.parse("tapp t2 p16 4");
        console.parse("tapp t2 p17 5");
        console.parse("tapp t2 p18 6");
        console.parse("tapp t2 p19 7");
        console.parse("tapp t2 p20 8");
        console.parse("tapp t2 p21 9");
        console.parse("tapp t2 p22 10");

        console.parse("cmr m1 name1 surname1 country t1");
        console.parse("cmr m2 name1 surname1 country t2");

        console.parse("team_set_trainer t1 tr1");
        console.parse("team_set_trainer t2 tr2");

        for (int i = 0; i < 10; i++) {
                console.parse("team_train t1");
                console.parse("team_train t2");
        }

        console.parse("match m1 m2");
    }
