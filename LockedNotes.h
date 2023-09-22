//
// Created by diges on 21/09/2023.
//

#ifndef NOTE_COLLECTION_LOCKEDNOTES_H
#define NOTE_COLLECTION_LOCKEDNOTES_H


#include "Observer.h"
#include "Collection.h"

class LockedNotes : public Observer {
private:
    Collection &subject;

public:
    LockedNotes(Collection &s) : subject(s) {
        subject.addObserver(this);
    }

    void update() override;

    ~LockedNotes() override {
        subject.removeObserver(this);
    }
};


#endif //NOTE_COLLECTION_LOCKEDNOTES_H