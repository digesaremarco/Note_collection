//
// Created by diges on 22/09/2023.
//

#include <iostream>
#include "ImportantCollectionCounter.h"

void ImportantCollectionCounter::update() {
    std::cout << "There are " << subject.getImportantCounter() << " important collections" << std::endl;
}
