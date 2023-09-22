//
// Created by diges on 22/09/2023.
//

#ifndef NOTE_COLLECTION_IMPORTANTCOLLECTIONCOUNTER_H
#define NOTE_COLLECTION_IMPORTANTCOLLECTIONCOUNTER_H


#include "Observer.h"
#include "AllCollection.h"

class ImportantCollectionCounter : public Observer {
private:
    AllCollection &subject;

public:
    ImportantCollectionCounter(AllCollection s) : subject(s) {
            subject.addObserver(this);
    }

    void update() override;

    ~ImportantCollectionCounter() override {
        subject.removeObserver(this);
    }
};


#endif //NOTE_COLLECTION_IMPORTANTCOLLECTIONCOUNTER_H
