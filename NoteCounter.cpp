//
// Created by diges on 21/09/2023.
//

#include <iostream>
#include "NoteCounter.h"

void NoteCounter::update() {
    std::cout << "There are " << subject.getSize() << " notes" << std::endl;
}

int NoteCounter::getCounter() const {
    return subject.getSize();
}
