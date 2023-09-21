//
// Created by diges on 21/09/2023.
//

#ifndef NOTE_COLLECTION_SUBJECT_H
#define NOTE_COLLECTION_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void addObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify() = 0;

    virtual ~Subject() {}
};


#endif //NOTE_COLLECTION_SUBJECT_H
