//
// Created by diges on 21/09/2023.
//

#ifndef NOTE_COLLECTION_NOTECOUNTER_H
#define NOTE_COLLECTION_NOTECOUNTER_H


#include "Observer.h"
#include "Collection.h"

class NoteCounter : public Observer {
private:
    Collection &subject;

public:
    NoteCounter(Collection s) : subject(s) {
        subject.addObserver(this);
    }

    void update() override;

    ~NoteCounter() override {
        subject.removeObserver(this);
    }
};


#endif //NOTE_COLLECTION_NOTECOUNTER_H