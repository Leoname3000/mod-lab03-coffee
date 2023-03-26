#ifndef MOD_LAB03_COFFEE_INCLUDE_AUTOMATA_H_
#define MOD_LAB03_COFFEE_INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

using namespace std;

class Automata {
  public:
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK,
    };

    Automata();
    string getMenu();
    string getStateString();
    STATES getState();

    void on();
    void off();
    void coin(unsigned int);
    void choice(unsigned int);
    void cancel();

  private:
    unsigned int cash;
    vector<string> menu;
    vector<unsigned int> prices;
    STATES state;

    void change();
    void check(unsigned int);
    void cook(unsigned int);
    void finish();
};

#endif //MOD_LAB03_COFFEE_INCLUDE_AUTOMATA_H_
