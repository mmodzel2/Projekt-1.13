#ifndef _TEST_HPP
#define _TEST_HPP

#include "console.hpp"
#include "manager.hpp"

class Test{
private:
    void manager_test();
    void team_test();
    void player_test();
    void trainer_test();
    void console_test();
public:
    Test(unsigned int mode=0){
        switch (mode){
            case 0:
                manager_test();
                break;
            case 1:
                team_test();
                break;
            case 2:
                trainer_test();
                break;
            case 3:
                player_test();
                break;
            case 4:
                console_test();
                break;
        }
    }
    static void manager_console(Console &console);
};

#endif
