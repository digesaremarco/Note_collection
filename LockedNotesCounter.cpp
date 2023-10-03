//
// Created by diges on 21/09/2023.
//

#include <iostream>
#include "LockedNotesCounter.h"

void LockedNotesCounter::update() {
    std::cout << "There are " << subject.getLockedNotes() << " locked notes" << std::endl;
}

