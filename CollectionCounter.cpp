//
// Created by diges on 22/09/2023.
//

#include <iostream>
#include "CollectionCounter.h"

void CollectionCounter::update() {
    std::cout << "There are " << subject.getSize() << " collections" << std::endl;
}
