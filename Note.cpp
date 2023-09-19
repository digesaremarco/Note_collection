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

void Note::setTitle(std::string t) {
    title = t;
}

void Note::setModify(bool m) {
    modify = m;
}

std::string Note::getText() const {
    return text;
}

void Note::setText(std::string t) {
    text = t;
}
