//
// Created by diges on 21/09/2023.
//

#ifndef NOTE_COLLECTION_OBSERVER_H
#define NOTE_COLLECTION_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;

    virtual ~Observer() {}
};


#endif //NOTE_COLLECTION_OBSERVER_H
