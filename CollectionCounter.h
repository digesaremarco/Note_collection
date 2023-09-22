//
// Created by diges on 22/09/2023.
//

#ifndef NOTE_COLLECTION_COLLECTIONCOUNTER_H
#define NOTE_COLLECTION_COLLECTIONCOUNTER_H


#include "Observer.h"
#include "AllCollection.h"

class CollectionCounter : public Observer {
private:
    AllCollection &subject;

public:
    CollectionCounter(AllCollection s) : subject(s) {
            subject.addObserver(this);
    }

    void update() override;

    ~CollectionCounter() override {
        subject.removeObserver(this);
    }
};


#endif //NOTE_COLLECTION_COLLECTIONCOUNTER_H
