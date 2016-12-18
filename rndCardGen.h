//
//  rndCardGen.h
//  statistics
//
//  Created by Mikaela Van Vooren on 10/15/16.
//  Copyright © 2016 Mikaela Van Vooren. All rights reserved.
//

#ifndef rndCardGen_h
#define rndCardGen_h

#include <cstdlib>
#include <ctime>
using namespace std;

class rndCardGen{
        int suitInt;
        int value;
        string suitString;
        int pickCard();
        void readCard(int card);
    public:
        rndCardGen();
        rndCardGen(int value);
        void outputCard();
        int cardSuit();
        int cardValue();
        void setValue(int newVal);
        void setSuit(int newSuit);

};

rndCardGen::rndCardGen(){
    int card = pickCard();
    readCard(card);
}

rndCardGen::rndCardGen(int givenValue){
    readCard(givenValue);
}

int rndCardGen::cardValue(){
    return value;
}

int rndCardGen::cardSuit(){
    return suitInt;
}

void rndCardGen::setSuit(int newSuit){
    suitInt = newSuit;
    if(newSuit == 1)
        suitString = "Clubs";
    else if(newSuit == 2)
        suitString = "Diamonds";
    else if(newSuit == 3)
        suitString = "Hearts";
    else if(newSuit == 4)
        suitString = "Spades";
}

void rndCardGen::setValue(int newVal){
    value = newVal;
}

void rndCardGen::outputCard(){
    if(value == 11)
        cout <<  "Jack" << " of " << suitString << endl;
    else if(value == 12)
        cout <<  "Queen" << " of " << suitString << endl;
    else if(value == 13)
        cout <<  "King" << " of " << suitString << endl;
    else if(value == 14)
        cout <<  "Ace" << " of " << suitString << endl;
    else
        cout <<  value << " of " << suitString << endl;
}

//picks number from 1-54 and translates into a card
//srand needs to be run in main before this can work
//joker value 100
//? maybe make actually random
int rndCardGen::pickCard(){
    int card;
    card = rand() % 52 + 1;
    return card;
}

void rndCardGen::readCard(int card){
    if(card % 13 == 1)
        value = 2;
    else if(card % 13 == 2)
        value = 3;
    else if(card % 13 == 3)
        value = 4;
    else if(card % 13 == 4)
        value = 5;
    else if(card % 13 == 5)
        value = 6;
    else if(card % 13 == 6)
        value = 7;
    else if(card % 13 == 7)
        value = 8;
    else if(card % 13 == 8)
        value = 9;
    else if(card % 13 == 9)
        value = 10;
    else if(card % 13 == 10)
        //Jack
        value = 11;
    else if(card % 13 == 11)
        //Queen
        value = 12;
    else if(card % 13 == 12)
        //King
        value = 13;
    else
        //Ace
        value = 14;
    
    if(card < 14)
    {
        suitInt = 1;
        suitString = "Clubs";
        
    }
    else if(card < 27){
        suitInt = 2;
        suitString = "Diamonds";
        }
    else if(card < 40){
        suitInt = 3;
        suitString = "Hearts";
        }
    else{
        suitInt = 4;
        suitString = "Spades";
        }
}

#endif /* rndCardGen_h */
