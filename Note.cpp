//
// Created by diges on 19/09/2023.
//

#include "Note.h"

bool Note::getModify() const {
    return modify;
}

bool Note::operator==(const Note &other) {
    return title == other.title;
}

std::string Note::getTitle() const {
    return title;
}