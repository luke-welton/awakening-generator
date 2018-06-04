#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Character.h"

bool Character::avatarIsMale = true;

inline void marryChrom(Character* Chrom, Character romances[]);
inline void marrySumia(Character* Sumia, Character romances[]);
void marry(Character* unit, Character romances[]);
inline void marryAvatar(Character* Robin, Character romances[]);

int main() {
    srand(time(0));
    Character::setAvatar(rand() % 2 == 1);

    Character playableCharacters[43];

    for (unsigned i = 0; i <= 29; i++) {
        playableCharacters[i] = Character(i);
    }
    marryChrom(&playableCharacters[1], playableCharacters);
    marrySumia(&playableCharacters[9], playableCharacters);

    int females[] = {2, 23, 14, 4, /*9,*/ 17, 24, 15, 8, 21, 19};

    for (unsigned i = 0; i < 10; i++) {
        marry(&playableCharacters[females[i]], playableCharacters);
    }

    playableCharacters[30] = Character(1, *playableCharacters[1].getSpouse());
    playableCharacters[31] = Character(6, *playableCharacters[9].getSpouse());
    for (unsigned i = 0; i < 10; i++) {
        if (i < 4) {
            playableCharacters[32 + i] = Character(i + 2, *playableCharacters[females[i]].getSpouse());
        }
        else {
            playableCharacters[32 + i] = Character(i + 3, *playableCharacters[females[i]].getSpouse());
        }
    }

    marryAvatar(&playableCharacters[0], playableCharacters);
    playableCharacters[42] = Character(0, *playableCharacters[0].getSpouse());

    Character chosenChars[16];
    chosenChars[0] = playableCharacters[1];
    playableCharacters[1].choose();
    for (unsigned i = 1; i < 16; i++) {
        Character *chosen = nullptr;
        bool exit = false;
        while (!exit) {
            chosen = &playableCharacters[rand() % 43];
            if (!chosen->isUnitChosen()) {
                chosen->choose();
                chosenChars[i] = *chosen;
                exit = true;
            }
        }
    }

    string sex = Character::getAvatar() ? "male" : "female";
    cout << "Your avatar is " << sex << "." << endl << endl;

    cout << "Here is your team:" << endl;
    for (unsigned i = 0; i < 16; i++) {
        cout << chosenChars[i].getClass() << "!" << chosenChars[i].getName() << endl;
    }

    cout << endl;

    cout << "Here are your pairings: " << endl;

    cout << "Robin" << "/" << playableCharacters[0].getSpouse()->getName() << endl;

    if (playableCharacters[0].getSpouse()->getName() != "Chrom") {
        cout << "Chrom" << "/" << playableCharacters[1].getSpouse()->getName() << endl;
    }

    if (!playableCharacters[0].getSpouse()->equals(playableCharacters[9]) &&
        !playableCharacters[1].getSpouse()->equals(playableCharacters[9])) {
        cout << "Sumia" << "/" << playableCharacters[9].getSpouse()->getName() << endl;
    }

    for (unsigned i = 0; i < 10; i++) {
        if (!playableCharacters[0].getSpouse()->equals(playableCharacters[females[i]]) &&
            !playableCharacters[1].getSpouse()->equals(playableCharacters[females[i]])) {
            cout << playableCharacters[females[i]].getName() << "/"
                 << playableCharacters[females[i]].getSpouse()->getName() << endl;
        }
    }

    return 0;
}

void marryChrom(Character *Chrom, Character romances[]) {
    int options = Character::getAvatar() ? 4 : 5;

    switch (rand() % options) {
        default:
        case 0: {
            Chrom->marry(&romances[9]);
            romances[9].marry(Chrom);
            break;
        }
        case 1: {
            Chrom->marry(&romances[4]);
            romances[4].marry(Chrom);
            break;
        }
        case 2: {
            Chrom->marry(&romances[14]);
            romances[14].marry(Chrom);
            break;
        }
        case 3: {
            Chrom->marry(&romances[23]);
            romances[23].marry(Chrom);
            break;
        }
        case 4: {
            Chrom->marry(&romances[0]);
            romances[0].marry(Chrom);
            break;
        }
    }
}

void marrySumia(Character* Sumia, Character romances[]) {
    int options = Character::getAvatar() ? 5 : 4;

    while (Sumia->getSpouse() == nullptr) {
        switch (rand() % options) {
            default:
            case 0: {
                if (romances[1].getSpouse() == nullptr) {
                    Sumia->marry(&romances[1]);
                    romances[1].marry(Sumia);
                }
                break;
            }
            case 1: {
                Sumia->marry(&romances[3]);
                romances[3].marry(Sumia);
                break;
            }
            case 2: {
                Sumia->marry(&romances[16]);
                romances[16].marry(Sumia);
                break;
            }
            case 3: {
                Sumia->marry(&romances[25]);
                romances[25].marry(Sumia);
                break;
            }
            case 4: {
                Sumia->marry(&romances[0]);
                romances[0].marry(Sumia);
                break;
            }
        }
    }
}

void marry(Character* unit, Character romances[]) {
    int *males = nullptr, numMales = 0;
    if (!Character::getAvatar()) {
        int m[] = {3, 5, 6, 7, 10, 11, 12, 13, 16, 18, 20, 25};
        males = m;
        numMales = 12;
    }
    else {
        int m[] = {3, 5, 6, 7, 10, 11, 12, 13, 16, 18, 20, 25, 0};
        males = m;
        numMales = 13;
    }

    while (unit->getSpouse() == nullptr) {
        Character *toMarry = &romances[males[rand() % numMales]];
        if (toMarry->getSpouse() == nullptr) {
            unit->marry(toMarry);
            toMarry->marry(unit);
        }
    }

    delete [] males;
}

void marryAvatar(Character* Robin, Character romances[]) {
    while (Robin->getSpouse() == nullptr) {
        Character *toMarry = &romances[rand() % 42];
        if (toMarry->getSpouse() == nullptr && Robin->isUnitMale() != toMarry->isUnitMale()) {
            Robin->marry(toMarry);
            toMarry->marry(Robin);
        }
    }
}