// Copyright 2022 UNN-IASR

#include <iostream>
#include "Automata.h"

int main() {
    Automata automata;
    std::cout << "Current state is: " << automata.getStateString() << std::endl;

    automata.on();
    std::cout << std::endl << automata.getMenu() << std::endl;
    std::cout << "Current state is: " << automata.getStateString() << std::endl << std::endl;

    automata.coin(45);
    std::cout << "Current state is: " << automata.getStateString() << std::endl << std::endl;

    automata.choice(3);
    std::cout << "Current state is: " << automata.getStateString() << std::endl << std::endl;

    automata.choice(9);
    std::cout << "Current state is: " << automata.getStateString() << std::endl << std::endl;

    automata.coin(10);
    std::cout << "Current state is: " << automata.getStateString() << std::endl << std::endl;

    automata.choice(3);
    std::cout << "Current state is: " << automata.getStateString() << std::endl << std::endl;

    automata.off();
    std::cout << "Current state is: " << automata.getStateString() << std::endl;
    return 0;
}
