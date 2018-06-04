#ifndef AWAKENING_GENERATOR_CHARACTER_H
#define AWAKENING_GENERATOR_CHARACTER_H

#include <string>
#include <vector>
using namespace std;

class Character {
private:
    string name;
    vector<string> classes, altClasses;
    bool hasUnique, isMale, isChosen;
    Character* spouse;
    static bool avatarIsMale;
public:
    Character();
    Character(int preset);
    Character(int preset, Character parent);

    string getName();
    string getClass();
    bool isUnitMale();
    bool isUnitChosen();
    void choose();
    vector<string> getClasses(bool childIsMale);

    Character* getSpouse();
    void marry(Character* toMarry);

    bool equals(Character toCompare);

    static bool contains(vector<string> toSearch, string toFind);
    static bool getAvatar();
    static void setAvatar(bool maleIn);
};

#endif //AWAKENING_GENERATOR_CHARACTER_H
