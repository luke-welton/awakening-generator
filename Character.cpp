#include <cstdlib>
#include "Character.h"

Character::Character() {
    name = "wtf the fuck";
    isChosen = true;
    spouse = nullptr;
}

Character::Character(int preset) {
    spouse = nullptr;

    if (preset == 1 || preset == 23) {
        hasUnique = true;
    }
    else {
        hasUnique = false;
    }

    switch (preset) {
        //Robin
        case 0:
        default: {
            name = "Robin";

            classes.push_back("Grandmaster");
            classes.push_back("Paladin");
            classes.push_back("Great Knight");
            classes.push_back("General");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Hero");
            classes.push_back("Bow Knight");
            classes.push_back("Sniper");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Sorcerer");
            classes.push_back("Dark Knight");
            classes.push_back("Sage");

            if (avatarIsMale) {
                classes.push_back("Berserker");
                classes.push_back("Warrior");
                classes.push_back("War Monk");

                isMale = true;
            }
            else {
                classes.push_back("Falcon Knight");
                classes.push_back("Dark Flier");
                classes.push_back("War Cleric");
                classes.push_back("Valkyrie");

                isMale = false;
            }

            altClasses = classes;
            break;
        }

        //Chrom
        case 1: {
            name = "Chrom";

            classes.push_back("Great Lord");
            classes.push_back("Paladin");
            classes.push_back("Great Knight");
            classes.push_back("Sniper");
            classes.push_back("Bow Knight");

            altClasses.insert(altClasses.end(), classes.begin() + 1, classes.end());

            isMale = true;
            break;
        }

        //Lissa
        case 2: {
            name = "Lissa";

            classes.push_back("War Cleric");
            classes.push_back("Sage");
            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");
            classes.push_back("Valkyrie");

            altClasses = classes;

            isMale = false;
            break;
        }

        //Frederick
        case 3: {
            name = "Frederick";

            classes.push_back("Great Knight");
            classes.push_back("Paladin");
            classes.push_back("General");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");

            altClasses = classes;
            isMale = true;
            break;
        }

        //Sully
        case 4: {
            name = "Sully";

            classes.push_back("Paladin");
            classes.push_back("Great Knight");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Virion
        case 5: {
            name = "Virion";

            classes.push_back("Sniper");
            classes.push_back("Bow Knight");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");

            altClasses = classes;
            isMale = true;
            break;
        }

        //Stahl
        case 6: {
            name = "Stahl";

            classes.push_back("Paladin");
            classes.push_back("Great Knight");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Bow Knight");
            classes.push_back("Sniper");

            altClasses = classes;
            isMale = true;
            break;
        }

        //Vaike
        case 7: {
            name = "Vaike";

            classes.push_back("Berserker");
            classes.push_back("Warrior");
            classes.push_back("Hero");
            classes.push_back("Trickster");
            classes.push_back("Assassin");

            altClasses.insert(altClasses.end(), classes.begin() + 3, classes.end());
            altClasses.push_back("General");
            altClasses.push_back("Great Knight");
            altClasses.push_back("Hero");
            altClasses.push_back("Bow Knight");

            isMale = true;
            break;
        }

        //Miriel
        case 8: {
            name = "Miriel";

            classes.push_back("Sage");
            classes.push_back("Dark Knight");
            classes.push_back("Valkyrie");
            classes.push_back("War Cleric");
            classes.push_back("Sorcerer");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Sumia
        case 9: {
            name = "Sumia";

            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");
            classes.push_back("Great Knight");
            classes.push_back("General");
            classes.push_back("War Cleric");
            classes.push_back("Sage");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Kellam
        case 10: {
            name = "Kellam";

            classes.push_back("General");
            classes.push_back("Great Knight");
            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Sage");
            classes.push_back("War Monk");

            altClasses.insert(altClasses.end(), classes.begin(), classes.end() - 1);
            altClasses.push_back("War Cleric");

            isMale = true;
            break;
        }

        //Donnel
        case 11: {
            name = "Donnel";

            classes.push_back("Warrior");
            classes.push_back("Hero");
            classes.push_back("Bow Knight");

            altClasses.insert(altClasses.end(), classes.begin() + 1, classes.end());
            altClasses.push_back("Falcon Knight");
            altClasses.push_back("Dark Flier");
            altClasses.push_back("Valkyrie");
            altClasses.push_back("War Cleric");

            isMale = true;
            break;
        }

        //Lon'qu
        case 12: {
            name = "Lon'qu";

            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");

            isMale = true;
            altClasses = classes;
            break;
        }

        //Ricken
        case 13: {
            name = "Ricken";

            classes.push_back("Sage");
            classes.push_back("Dark Knight");
            classes.push_back("Paladin");
            classes.push_back("Great Knight");
            classes.push_back("Sniper");
            classes.push_back("Bow Knight");

            isMale = true;
            altClasses = classes;
            break;
        }

        //Maribelle
        case 14: {
            name = "Maribelle";

            classes.push_back("Valkyrie");
            classes.push_back("War Cleric");
            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");

            isMale = false;
            altClasses = classes;
            break;
        }

        //Panne
        case 15: {
            name = "Panne";

            classes.push_back("Taguel");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Trickster");
            classes.push_back("Assassin");

            isMale = false;
            altClasses = classes;
            break;
        }

        //Gaius
        case 16: {
            name = "Gaius";

            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Swordmaster");
            classes.push_back("Warrior");
            classes.push_back("Hero");

            altClasses.insert(altClasses.end(), classes.begin(), classes.end() - 2);
            altClasses.push_back("Falcon Knight");
            altClasses.push_back("Dark Flier");

            isMale  = true;
            break;
        }

        //Cordelia
        case 17: {
            name = "Cordelia";

            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");
            classes.push_back("Sorcerer");
            classes.push_back("Dark Knight");
            classes.push_back("Hero");
            classes.push_back("Bow Knight");

            isMale = false;
            altClasses = classes;
            break;
        }

        //Gregor
        case 18: {
            name = "Gregor";

            classes.push_back("Hero");
            classes.push_back("Bow Knight");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Berserker");
            classes.push_back("Warrior");

            altClasses.insert(altClasses.end(), classes.begin(), classes.end() - 2);
            altClasses.push_back("Valkyrie");
            altClasses.push_back("War Cleric");

            isMale = true;
            break;
        }

        //Nowi
        case 19: {
            name = "Nowi";

            classes.push_back("Manakete");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Libra
        case 20: {
            name = "Libra";

            classes.push_back("War Monk");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");
            classes.push_back("Sorcerer");

            altClasses = classes;
            isMale = true;
            break;
        }

        //Tharja
        case 21: {
            name = "Tharja";

            classes.push_back("Sorcerer");
            classes.push_back("Dark Knight");
            classes.push_back("General");
            classes.push_back("Great Knight");
            classes.push_back("Sniper");
            classes.push_back("Bow Knight");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Anna
        case 22: {
            name = "Anna";

            classes.push_back("Trickster");
            classes.push_back("Assassin");
            classes.push_back("Sniper");
            classes.push_back("Bow Knight");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Olivia
        case 23: {
            name = "Olivia";

            classes.push_back("Dancer");
            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");

            altClasses.insert(altClasses.end(), classes.begin() + 1, classes.end());
            isMale = false;
            break;
        }

        //Cherche
        case 24: {
            name = "Cherche";

            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("War Cleric");
            classes.push_back("Valkyrie");
            classes.push_back("Sage");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Henry
        case 25: {
            name = "Henry";

            classes.push_back("Sorcerer");
            classes.push_back("Dark Knight");
            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Berserker");
            classes.push_back("Warrior");

            altClasses.insert(altClasses.end(), classes.begin(), classes.end() - 2);
            altClasses.push_back("Valkyrie");
            altClasses.push_back("War Cleric");

            isMale = true;
            break;
        }

        //Say'ri
        case 26: {
            name = "Say'ri";

            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");

            altClasses = classes;
            isMale = false;
            break;
        }

        //Tiki
        case 27: {
            name = "Tiki";

            classes.push_back("Manakete");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");

            altClasses = classes;
            break;
        }

        //Basilio
        case 28: {
            name = "Basilio";

            classes.push_back("Warrior");
            classes.push_back("Hero");
            classes.push_back("Great Knight");
            classes.push_back("General");
            classes.push_back("Berserker");

            altClasses = classes;
            isMale = true;
            break;
        }

        //Flavia
        case 29: {
            name = "Flavia";

            classes.push_back("Hero");
            classes.push_back("Bow Knight");
            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Great Knight");
            classes.push_back("General");

            altClasses = classes;
            isMale = false;
            break;
        }
    }
}

Character::Character(int preset, Character parent) {
    hasUnique = false;
    spouse = nullptr;

    vector<string> parentClasses;
    switch (preset) {
        //Morgan
        case 0:
        default: {
            name = "Morgan";

            classes.push_back("Grandmaster");
            classes.push_back("Paladin");
            classes.push_back("Great Knight");
            classes.push_back("General");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Hero");
            classes.push_back("Bow Knight");
            classes.push_back("Sniper");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Sorcerer");
            classes.push_back("Dark Knight");
            classes.push_back("Sage");

            if (!avatarIsMale) {
                classes.push_back("Berserker");
                classes.push_back("Warrior");
                classes.push_back("War Monk");

                parentClasses = parent.getClasses(true);
                isMale = true;
            }
            else {
                classes.push_back("Falcon Knight");
                classes.push_back("Dark Flier");
                classes.push_back("War Cleric");
                classes.push_back("Valkyrie");

                parentClasses = parent.getClasses(false);
                isMale = false;
            }

            break;
        }

        //Lucina
        case 1: {
            name = "Lucina";

            classes.push_back("Great Lord");
            classes.push_back("Sniper");
            classes.push_back("Bow Knight");
            classes.push_back("Great Knight");
            classes.push_back("Paladin");

            parentClasses = parent.getClasses(false);

            hasUnique = true;
            isMale = false;
            break;
        }

        //Owain
        case 2: {
            name = "Owain";

            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("War Monk");
            classes.push_back("Sage");
            classes.push_back("Berserker");
            classes.push_back("Warrior");

            parentClasses = parent.getClasses(true);

            isMale = true;
            break;
        }

        //Inigo
        case 3: {
            name = "Inigo";

            classes.push_back("Hero");
            classes.push_back("Bow Knight");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Berserker");
            classes.push_back("Warrior");

            parentClasses = parent.getClasses(true);

            isMale = true;
            break;
        }

        //Brady
        case 4: {
            name = "Brady";

            classes.push_back("War Monk");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");
            classes.push_back("Paladin");
            classes.push_back("Great Knight");

            parentClasses = parent.getClasses(true);

            isMale = true;
            break;
        }

        //Kjelle
        case 5: {
            name = "Kjelle";

            classes.push_back("General");
            classes.push_back("Great Knight");
            classes.push_back("Swordmaster");
            classes.push_back("Assassin");
            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");

            parentClasses = parent.getClasses(false);

            isMale = false;
            break;
        }

        //Cynthia
        case 6: {
            name = "Cynthia";

            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");
            classes.push_back("General");
            classes.push_back("Great Knight");
            classes.push_back("War Cleric");
            classes.push_back("Sage");

            parentClasses = parent.getClasses(false);

            isMale = false;
            break;
        }

        //Severa
        case 7: {
            name = "Severa";

            classes.push_back("Hero");
            classes.push_back("Bow Knight");
            classes.push_back("Dark Knight");
            classes.push_back("Sorcerer");
            classes.push_back("Falcon Knight");
            classes.push_back("Dark Flier");

            parentClasses = parent.getClasses(false);

            isMale = false;
            break;
        }

        //Gerome
        case 8: {
            name = "Gerome";

            classes.push_back("Wyvern Lord");
            classes.push_back("Griffon Rider");
            classes.push_back("Warrior");
            classes.push_back("Hero");
            classes.push_back("War Monk");
            classes.push_back("Sage");

            parentClasses = parent.getClasses(true);

            isMale = true;
            break;
        }

        //Yarne
        case 9: {
            name = "Yarne";

            classes.push_back("Taguel");
            classes.push_back("Assassin");
            classes.push_back("Trickster");
            classes.push_back("Berserker");
            classes.push_back("Warrior");

            parentClasses = parent.getClasses(true);

            isMale = true;
            break;
        }

        //Laurent
        case 10: {
            name = "Laurent";

            classes.push_back("Sage");
            classes.push_back("Dark Knight");
            classes.push_back("Berserker");
            classes.push_back("Warrior");
            classes.push_back("Sorcerer");

            parentClasses = parent.getClasses(true);

            isMale = true;
            break;
        }

        //Noire
        case 11: {
            name = "Noire";

            classes.push_back("Sniper");
            classes.push_back("Bow Knight");
            classes.push_back("Sorcerer");
            classes.push_back("Dark Knight");
            classes.push_back("General");
            classes.push_back("Great Knight");

            parentClasses = parent.getClasses(false);

            isMale = false;
            break;
        }

        //Nah
        case 12: {
            name = "Nah";

            classes.push_back("Manakete");
            classes.push_back("Sage");
            classes.push_back("Dark Knight");
            classes.push_back("Griffon Rider");
            classes.push_back("Wyvern Lord");

            parentClasses = parent.getClasses(false);

            isMale = false;
            break;
        }
    }

    for (unsigned i = 0; i < parentClasses.size(); i++) {
        if (!contains(classes, parentClasses[i])) {
            classes.push_back(parentClasses[i]);
        }
    }

    if (preset == 1) {
        altClasses.insert(altClasses.begin(), classes.begin() + 1, classes.end());
    }
    else {
        altClasses = classes;
    }
}

string Character::getName() {
    return name;
}

string Character::getClass() {
    return classes[rand() % classes.size()];
}

bool Character::isUnitMale() {
    return isMale;
}

bool Character::isUnitChosen() {
    return isChosen;
}

void Character::choose() {
    isChosen = true;
}

vector<string> Character::getClasses(bool childIsMale) {
    return !childIsMale || hasUnique ? altClasses : classes;
}

Character* Character::getSpouse() {
    return spouse;
}

void Character::marry(Character *toMarry) {
    spouse = toMarry;
}

bool Character::equals(Character toCompare) {
    return name == toCompare.getName();
}

bool Character::contains(vector<string> toSearch, string toFind) {
    for (unsigned i = 0; i < toSearch.size(); i++) {
        if (toSearch[i] == toFind) {
            return true;
        }
    }

    return false;
}

bool Character::getAvatar() {
    return avatarIsMale;
}

void Character::setAvatar(bool maleIn) {
    avatarIsMale = maleIn;
}