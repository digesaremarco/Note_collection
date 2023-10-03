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

    void addNote(const Note &newnote);

    void removeNote(const Note &oldnote);

    Note findNote(const std::string &title) const;

    void updateNote(const Note &note, const std::string &ti, const std::string &t);

    void updateLocked(const Note &note);

    void setTitle(const std::string &t);

    std::string getTitle() const;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

    int getSize() const;

    int getLockedNotes() const;

    bool operator==(const Collection &other);

    bool getImportant() const;
};


#endif //NOTE_COLLECTION_COLLECTION_H
