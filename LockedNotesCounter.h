//
// Created by diges on 21/09/2023.
//

#ifndef NOTE_COLLECTION_LOCKEDNOTESCOUNTER_H
#define NOTE_COLLECTION_LOCKEDNOTESCOUNTER_H


#include "Observer.h"
#include "Collection.h"

class LockedNotesCounter : public Observer {
private:
    Collection &subject;

public:
    LockedNotesCounter(Collection &s) : subject(s) {
            subject.addObserver(this);
    }

    void update() override;

    ~LockedNotesCounter() override {
        subject.removeObserver(this);
    }
};


#endif //NOTE_COLLECTION_LOCKEDNOTESCOUNTER_H
