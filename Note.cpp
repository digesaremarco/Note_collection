//
// Created by diges on 19/09/2023.
//

#include "Note.h"

bool Note::getLocked() const {
    return locked;
}

bool Note::operator==(const Note &other) {
    return title == other.title;
}

std::string Note::getTitle() const {
    return title;
}

void Note::setTitle(const std::string &t) {
    title = t;
}

void Note::setLocked(bool l) {
    locked = l;
}

std::string Note::getText() const {
    return text;
}

void Note::setText(const std::string &t) {
    text = t;
}
