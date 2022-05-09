
#ifndef GAME_OF_LIFE_LIFEHISTORY_H
#define GAME_OF_LIFE_LIFEHISTORY_H

#include "Gen.h"

class LifeHistory {
private:
    Gen current;
    LifeHistory *prev;
public:
    explicit LifeHistory(const Gen& gen) {
        current = gen;
        prev = nullptr;
    }

    Gen getCurrent() {
        return current;
    }

    LifeHistory getPrev() {
        return *prev;
    }

    void setPrev(LifeHistory *lifeHistory) {
        prev = lifeHistory;
    }

    void evolve() {
        LifeHistory aux(current);
        aux.setPrev(prev);
        current.next();
    }

};


#endif //GAME_OF_LIFE_LIFEHISTORY_H
