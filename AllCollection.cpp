//
// Created by diges on 22/09/2023.
//

#include <iostream>
#include "AllCollection.h"

void AllCollection::addCollection(Collection &newcollection) {
    bool found = false;
    for (auto c: collection) {
        if (c == newcollection) {
            found = true;
        }
    }
    if (!found) {
        collection.push_back(newcollection);
        std::cout << "new collection added" << std::endl;
    } else std::cout << "collection already present" << std::endl;
}

void AllCollection::removeCollection(Collection &oldcollection) {
    bool found = false;
    for (auto c: collection) {
        if (c == oldcollection) {
            found = true;
        }
    }
    if (found) {
        collection.remove(oldcollection);
        std::cout << "collection removed" << std::endl;
    } else std::cout << "error" << std::endl;
}

void AllCollection::addNote(Note &note, Collection &mycollection) const {
    bool found = false;
    for (auto c: collection) {
        if (c == mycollection) {
            found = true;
        }
    }
    if (found) {
        mycollection.addNote(note);
        std::cout << "note added" << std::endl;
    } else std::cout << "error" << std::endl;
}

void AllCollection::removeNote(Note &note, Collection &mycollection) const {
    bool found = false;
    for (auto c: collection) {
        if (c == mycollection) {
            found = true;
        }
    }
    if (found) {
        mycollection.removeNote(note);
        std::cout << "note removed" << std::endl;
    } else std::cout << "error" << std::endl;
}

void AllCollection::addObserver(Observer *o) {
    observers.push_back(o);
}

void AllCollection::removeObserver(Observer *o) {
    observers.remove(o);
}

void AllCollection::notify() {
    for (auto ob: observers)
        ob->update();
}

int AllCollection::getSize() const {
    return collection.size();
}

int AllCollection::getImportantCounter() const {
    int counter = 0;
    for (auto c: collection) {
        if (c.getImportant()) {
            counter++;
        }
    }
    return counter;
}

