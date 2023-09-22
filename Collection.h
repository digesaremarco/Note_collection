//
// Created by diges on 19/09/2023.
//

#ifndef NOTE_COLLECTION_COLLECTION_H
#define NOTE_COLLECTION_COLLECTION_H


#include <string>
#include <list>
#include "Note.h"
#include "Subject.h"

class Collection : public Subject {
private:
    std::string title;
    std::list<Note> notes;
    std::list<Observer *> observers;
    bool important;

public:
    Collection(std::string t, bool i) : title(t), important(i) {}

    void addNote(Note &newnote);

    void removeNote(Note &oldnote);

    void showNote(Note &note) const;

    void updateNote(Note &note);

    void updateLocked(Note &note);

    void setTitle(std::string t);

    std::string getTitle() const;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

    int getSize() const;

    int getLockedNotes() const;

    bool operator==(const Collection &other);
};


#endif //NOTE_COLLECTION_COLLECTION_H
