// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, created) {
    Automata automata;
    EXPECT_EQ(Automata::STATES::OFF, automata.getState());
}

TEST(automata, power_on) {
    Automata automata;
    automata.on();
    EXPECT_EQ(Automata::STATES::WAIT, automata.getState());
}

TEST(automata, power_off) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(Automata::STATES::OFF, automata.getState());
}

TEST(automata, no_power) {
    Automata automata;
    automata.coin(10);
    EXPECT_EQ(Automata::STATES::OFF, automata.getState());
}

TEST(automata, deposit) {
    Automata automata;
    automata.on();
    automata.coin(10);
    EXPECT_EQ(Automata::STATES::ACCEPT, automata.getState());
}

TEST(automata, wrong_off) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.off();
    EXPECT_EQ(Automata::STATES::ACCEPT, automata.getState());
}

TEST(automata, cancel) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.cancel();
    EXPECT_EQ(Automata::STATES::WAIT, automata.getState());
}

TEST(automata, free_drink) {
    Automata automata;
    automata.on();
    automata.choice(3);
    EXPECT_EQ(Automata::STATES::WAIT, automata.getState());
}

TEST(automata, not_enough) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.choice(3);
    EXPECT_EQ(Automata::STATES::ACCEPT, automata.getState());
}

TEST(automata, enough) {
    Automata automata;
    automata.on();
    automata.coin(60);
    automata.choice(3);
    EXPECT_EQ(Automata::STATES::WAIT, automata.getState());
}

TEST(automata, wrong_id) {
    Automata automata;
    automata.on();
    automata.coin(60);
    automata.choice(9);
    EXPECT_EQ(Automata::STATES::ACCEPT, automata.getState());
}

TEST(automata, full_cycle) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(9);
    automata.choice(4);
    automata.cancel();
    automata.coin(100);
    automata.choice(9);
    automata.choice(4);
    EXPECT_EQ(Automata::STATES::WAIT, automata.getState());
}
