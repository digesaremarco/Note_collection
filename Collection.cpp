//
// Created by diges on 19/09/2023.
//

#include "Collection.h"

void Collection::addNote(Note &newnote) {
    notes.push_back(newnote);
}

void Collection::removeNote(Note &oldnote) {
    bool found = false;
    for (auto n: notes) {
        if (n == oldnote)
            found = true;
    }
    if (found && oldnote.getLocked()) {
        notes.remove(oldnote); //removes only if it finds the note and it is editable
    } else std::printf("error");
}

void Collection::setTitle(std::string t) {
    title = t;
}

std::string Collection::getTitle() const {
    return title;
}
