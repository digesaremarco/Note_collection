//
// Created by diges on 19/09/2023.
//

#ifndef NOTE_COLLECTION_NOTE_H
#define NOTE_COLLECTION_NOTE_H


#include <string>

class Note {
private:
    std::string title, text;
    bool locked; //allows modification and deletion

public:

    Note(std::string ti, std::string te, bool l) : title(ti), text(te), locked(l) {}

    bool getLocked() const;
    void setLocked(bool l);

    std::string getTitle() const;

    void setTitle(std::string t);

    std::string getText() const;

    void setText(std::string t);

    bool operator==(const Note &other);

};


#endif //NOTE_COLLECTION_NOTE_H
