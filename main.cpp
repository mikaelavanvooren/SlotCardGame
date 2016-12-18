//
//  main.cpp
//  statistics
//
//  Created by Mikaela Van Vooren on 10/13/16.
//  Copyright © 2016 Mikaela Van Vooren. All rights reserved.
//

#include <iostream>
#include "math.h"
#include "slots.h"


int main() {
    srand(time(0));
    slots ownDeck = slots();
    ownDeck.outputDeck();
    ownDeck.checkWin();
    return 0;
}




