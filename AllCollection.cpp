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

void AllCollection::addNote(Note &note, Collection &mycollection) {
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

void AllCollection::removeNote(Note &note, Collection &mycollection) {
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

void Collection::addObserver(Observer *o) {
    observers.push_back(o);
}

void Collection::removeObserver(Observer *o) {
    observers.remove(o);
}

void Collection::notify() {
    for (auto ob: observers)
        ob->update();
}
