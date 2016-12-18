//
//  slots.h
//  statistics
//
//  Created by Mikaela Van Vooren on 10/15/16.
//  Copyright © 2016 Mikaela Van Vooren. All rights reserved.
//

#ifndef slots_h
#define slots_h
#include "rndCardGen.h"

// The only issue is that there's no real fix for when there's a double of something or five of a kind
// Two of the same cards doesn't show as a pair

const int totalCards = 5;

class slots{
        rndCardGen deck[totalCards];
        void valueSort();
        void suitSort();
        int suitMatches();
        int valueMatches();
        bool flushCheck();
    public:
        slots();
        void outputDeck();
        int checkWin();
    
};


slots::slots(){
    for(int i = 0; i < totalCards; i++)
    {
        deck[i] = rndCardGen();
    }
    suitSort();
    valueSort();
}

void slots::valueSort(){
    for(int i = 0; i < totalCards-1; i++){
        int minVal = i;
        for(int j = i+1; j < totalCards; j++){
            if(deck[j].cardValue() < deck[minVal].cardValue()){
                minVal = j;
            }
        }
        if(deck[minVal].cardValue()  != deck[i].cardValue()){
            swap(deck[i], deck[minVal]);
        }
    }
}

void slots::suitSort(){
    for(int i = 0; i < totalCards-1; i++){
        int minVal = i;
        for(int j = i+1; j < totalCards; j++){
            if(deck[j].cardSuit() < deck[minVal].cardSuit()){
                minVal = j;
            }
        }
        if(deck[minVal].cardSuit() != deck[i].cardSuit()){
            swap(deck[i], deck[minVal]);
        }
    }
}

int slots::suitMatches(){
    int matches[3] = {0, 0, 0};
    int index = 0;
    int j = 0;
        while(index < totalCards-1 && j < 3){
            if(deck[index].cardSuit() == deck[index+1].cardSuit())
                matches[j]++;
            else
                j++;
            index++;
        }
    if((matches[0] > matches[1]) && (matches[0] > matches[2]))
        return matches[0];
    else if(matches[1] > matches[2])
        return matches[1];
    else
        return matches[2];
}

bool slots::flushCheck(){
    int flush = 0;
    int index = 0;
    int j = 0;
    while(index < totalCards-1){
        if(deck[index].cardValue()+1 == deck[index+1].cardValue())
            flush++;
        else
            j++;
        index++;
    }
    if(flush == 4)
        return true;
    else
        return false;
}

int slots::valueMatches(){
    int matches[3] = {0, 0, 0};
    int index = 0;
    int j = 0;
        while(index < totalCards-1 && j < 3){
            if(deck[index].cardValue() == deck[index+1].cardValue())
                matches[j]++;
            else
                j++;
            index++;
        }
    if(matches[0] + matches[1] + matches[2] == 3){
        if(matches[0] == 3 || matches[1] == 3 || matches[2] == 3)
            return 3;
        else
            return 100;
    }
    else if((matches[0] > matches[1]) && (matches[0] > matches[2]))
        return matches[0];
    else if(((matches[0] && matches[1]) == 1) || ((matches[0] && matches[2]) == 1) || ((matches[1] && matches[2]) == 1))
        return 200;
    else if(matches[1] > matches[2])
        return matches[1];
    else
        return matches[2];
}

int slots::checkWin(){
    int value = valueMatches();
    int suit = suitMatches();
    bool flush = flushCheck();
    if(value == 4){
        cout << "You got five of a kind!" << endl;
        return 0;
    }
    else if(flush == true){
        cout << "You got a flush!" << endl;
        return 1;
    }
    else if(value == 3){
        cout << "You got four of a kind!" << endl;
        return 2;
    }
    else if(value == 100){
        cout << "You got a full house!" << endl;
        return 3;
    }
    else if(suit == 4){
        cout << "You got a flush!" << endl;
        return 4;
    }
    else if(flush == true){
        cout <<"You got a straight!" << endl;
        return 5;
    }
    else if(value == 2){
        cout << "You got three of a kind!" << endl;
        return 6;
    }
    else if(value == 200){
        cout << "You got two pairs!" << endl;
        return 7;
    }
    else if(value == 1){
        cout << "You got one pair!" << endl;
        return 8;
    }
    else {
        cout <<"You didn't win anything. Try again." << endl;
        return 1000;
    }
    
}


void slots::outputDeck(){
    for(int i = 0; i < totalCards; i++)
    {
        deck[i].outputCard();
    }
}

#endif /* slots_h */
