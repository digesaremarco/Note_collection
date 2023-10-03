//
// Created by diges on 19/09/2023.
//

#include <iostream>
#include "Collection.h"

void Collection::addNote(const Note &newnote) {
    bool found = false;
    for (auto n: notes) {
        if (n == newnote)
            found = true;
    }
    if (!found) {
        notes.push_back(newnote); //insert only if it doesn't find the note
        std::cout << "new note added" << std::endl;
        notify();
    } else std::cout << "note already present" << std::endl;
}

void Collection::removeNote(const Note &oldnote) {
    bool found = false;
    for (auto n: notes) {
        if (n == oldnote)
            found = true;
    }
    if (found && !oldnote.getLocked()) {
        notes.remove(oldnote); //remove only if it finds the note and it is editable
        std::cout << "note removed" << std::endl;
        notify();
    } else std::cout << "note not found" << std::endl;
}

void Collection::setTitle(const std::string &t) {
    title = t;
}

std::string Collection::getTitle() const {
    return title;
}

Note Collection::findNote(const std::string &title) const {
    bool found = false;
    for (auto n: notes) {
        if (n.getTitle() == title) {
            return n;
        }
    }
    if (!found)
        return Note("", "", false);
}

void Collection::updateNote(const Note &note, const std::string &ti, const std::string &t) {
    bool found = false;
    for (auto n: notes) {
        if (n == note && !note.getLocked()) {
            found = true;
            Note newnote(ti, t, note.getLocked());
        }
    }
    if (!found)
        std::cout << "error" << std::endl;
}

void Collection::updateLocked(const Note &note) {
    bool found = false;
    for (auto n: notes) {
        if (n == note) {
            found = true;
            Note newnote(note.getTitle(), note.getText(), !note.getLocked());
        }
    }
    if (found) {
        Note newnote(note.getTitle(), note.getText(), !note.getLocked());
        notes.remove(note);
        notes.push_back(newnote);
        notify();
    } else std::cout << "note not found" << std::endl;
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

int Collection::getSize() const {
    return notes.size();
}

int Collection::getLockedNotes() const {
    int count = 0;
    for (auto n: notes) {
        if (n.getLocked())
            count++;
    }
    return count;
}

bool Collection::operator==(const Collection &other) {
    return title == other.title;
}

bool Collection::getImportant() const {
    return important;
}