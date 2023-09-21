//
// Created by diges on 21/09/2023.
//

#include <iostream>
#include "LockedNotes.h"

void LockedNotes::update() {
    std::cout << "There are " << subject.getLockedNotes() << " notes" << std::endl;
}
