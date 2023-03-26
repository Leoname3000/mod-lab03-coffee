// Copyright 2022 UNN-IASR

#include <iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu = {"Espresso", "Cappuccino", "Latte",
            "Hot Chocolate", "Double Chocolate", "Hot Water"};
    prices = {60, 65, 70, 50, 75, 20};
    state = OFF;
}

void Automata::on() {
    if (state != OFF) return;
    if (menu.size() != prices.size()) {
        std::cout << "Incorrect menu/prices info" << std::endl;
        return;
    }
    std::cout << std::endl << "Starting up..." << std::endl;
    state = WAIT;
}
void Automata::off() {
    if (state != WAIT) return;
    std::cout << "Shutting down..." << std::endl;
    state = OFF;
}
void Automata::coin(unsigned int amount) {
    if (state != WAIT && state != ACCEPT) return;
    state = ACCEPT;
    cash += amount;
    std::cout << "Balance: " << cash << std::endl;
}
void Automata::cancel() {
    if (state != ACCEPT) return;
    state = WAIT;
    change();
}
void Automata::change() {
    if (state != WAIT) return;
    std::cout << "Your change: " << cash << std::endl;
    cash = 0;
}
void Automata::choice(unsigned int id) {
    if (state != ACCEPT) return;
    state = CHECK;
    check(id);
}
void Automata::check(unsigned int id) {
    if (state != CHECK) return;
    if (id >= prices.size()) {
        std::cout << "No item with id " << id << std::endl;
        state = ACCEPT;
    } else if (cash < prices[id]) {
        std::cout << "Not enough balance" << std::endl;
        state = ACCEPT;
    } else {
        cash -= prices[id];
        cook(id);
    }
}
void Automata::cook(unsigned int id) {
    std::cout << "Cooking " << menu[id] << "..." << std::endl;
    state = COOK;
    finish();
}
void Automata::finish() {
    if (state != COOK) return;
    std::cout << "Your drink is ready!" << std::endl;
    state = WAIT;
    if (cash > 0) change();
}

std::string Automata::getMenu() {
    std::string result;
    for (size_t i = 0; i < menu.size(); i++) {
        result += menu[i] + " - " + std::to_string(prices[i]) + "\n";
    }
    return result;
}
std::string Automata::getStateString() {
    switch (state) {
        case OFF: return "Off";
        case WAIT: return "Wait";
        case ACCEPT: return "Accept";
        case CHECK: return "Check";
        case COOK: return "Cook";
    }
    throw std::runtime_error("State not provided!");
}
Automata::STATES Automata::getState() {
    return state;
}
