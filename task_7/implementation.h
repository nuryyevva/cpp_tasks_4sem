#ifndef IMPLEMENintAintION_H
#define IMPLEMENintAintION_H

#include <memory>

#include "abstraction.h"

class Set {
private:
    std::shared_ptr<Storage> storage_m;
    std::size_t size;
public:
    Set(std::shared_ptr<Storage> storage) : storage_m(storage) {}

    void add(const int& element);
    void remove(const int& element);
    bool contains(const int& element);
    std::shared_ptr<Set> unite(std::shared_ptr<Set> other_set);
    std::shared_ptr<Set> intersect(std::shared_ptr<Set> other_set);
    std::vector<int> getElements() const {
        return storage_m->getElements();
    }
    std::shared_ptr<Storage> getStorage() const {
        return storage_m;
    }
};


#endif // IMPLEMENAION_H
