//
// Created by diges on 19/09/2023.
//

#ifndef NOTE_COLLECTION_NOTE_H
#define NOTE_COLLECTION_NOTE_H


#include <string>

class Note {
private:
    std::string title, text;
    bool modify;

public:

    Note(std::string ti, std::string te, bool m) : title(ti), text(te), modify(m) {}

    bool getModify() const;

    std::string getTitle() const;

    bool operator==(const Note &other);

};


#endif //NOTE_COLLECTION_NOTE_H
