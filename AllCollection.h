//
// Created by diges on 22/09/2023.
//

#ifndef NOTE_COLLECTION_ALLCOLLECTION_H
#define NOTE_COLLECTION_ALLCOLLECTION_H

#include <list>
#include "Collection.h"

class AllCollection : public Subject {

private:
    std::list<Collection> collection;
    std::list<Observer *> observers;

public:
    void addNote(Note &note, Collection &mycollection);

    void removeNote(Note &note, Collection &mycollection);

    void addCollection(Collection &newcollection);

    void removeCollection(Collection &oldcollection);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

};


#endif //NOTE_COLLECTION_ALLCOLLECTION_H
