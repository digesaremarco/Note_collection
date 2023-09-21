//
// Created by diges on 19/09/2023.
//

#include <iostream>
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
        notes.remove(oldnote); //remove only if it finds the note and it is editable
    } else std::cout << "error"<< std::endl;
}

void Collection::setTitle(std::string t) {
    title = t;
}

std::string Collection::getTitle() const {
    return title;
}

void Collection::showNote(Note &note) const {
    bool found = false;
    for (auto n: notes) {
        if (n == note)
            found = true;
    }
    if (found) {
        std::cout << "title : " << note.getTitle()<< std::endl;//show only if it finds the note
        std::cout << "text : " << note.getText()<< std::endl;
        std::cout << "locked : " << note.getLocked()<< std::endl;
    } else std::cout << "error"<< std::endl;
}

void Collection::updateNote(Note &note) {
    bool found = false;
    bool choose = false;
    std::string t;
    for (auto n: notes) {
        if (n == note)
            found = true;
    }
    if (found && note.getLocked()) {//update only if it finds the note and it is editable
        std::cout << "do you want to change the title?"<< std::endl;
        std::cin >> choose;
        if(choose){
            std::cout << "write the title : "<< std::endl;
            std::cin >> t;
            note.setTitle(t);
        }
        std::cout << "do you want to change the text?"<< std::endl;
        std::cin >> choose;
        if(choose){
            std::cout << "write the text : "<< std::endl;
            std::cin >> t;
            note.setText(t);
        }
    } else std::cout << "error"<< std::endl;
}

void Collection::updateLocked(Note &note) {
    bool found = false;
    for (auto n: notes) {
        if (n == note)
            found = true;
    }
    if (found) {
        note.setLocked(!note.getLocked()); //change only if it finds the note
    } else std::cout << "error"<< std::endl;
}
