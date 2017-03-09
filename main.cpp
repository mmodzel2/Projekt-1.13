#include <iostream>
#include <cstring>

void team_test();
void manager_test();
void player_test();
void trainer_test();

int func_test();

using namespace std;

int main()
{
    team_test();
    //manager_test();
    //player_test();
    //trainer_test();

    func_test();

    return 0;
}

int func_test(){
    int* a = new int[4];
    int b;

    a[0] = 10;
    a[1] = 2;
    a[5] = 0x45;

    b = a[0];

    char str[] = "Test function";
    char* str1 = new char[100];

    cout << b << endl;

    strncpy(str, str1, 100);

    return 0;
}
