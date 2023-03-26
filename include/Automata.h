// Copyright 2022 UNN-IASR

#include <string>
#include <vector>

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
    std::string getMenu();
    std::string getStateString();
    STATES getState();

    void on();
    void off();
    void coin(unsigned int);
    void choice(unsigned int);
    void cancel();

   private:
    unsigned int cash;
    std::vector<std::string> menu;
    std::vector<unsigned int> prices;
    STATES state;

    void change();
    void check(unsigned int);
    void cook(unsigned int);
    void finish();
};
