#include "abstraction.h"

void VectorStorage::add(const int& element) {
    if (std::find(storage_m.begin(), storage_m.end(), element) == storage_m.end())
        storage_m.push_back(element);
}

void VectorStorage::remove(const int& element) {
    if (contains(element))
        storage_m.erase(std::remove(storage_m.begin(), storage_m.end(), element), storage_m.end());
}

bool VectorStorage::contains(const int& element) {
    return std::find(storage_m.begin(), storage_m.end(), element) != storage_m.end();
}

std::shared_ptr<Storage> VectorStorage::unite(std::shared_ptr<Storage> other_set) {
    std::shared_ptr<Storage> new_set = std::make_shared<VectorStorage>();
    for (const int& element : storage_m)
        new_set->add(element);
    for (const int& element : std::dynamic_pointer_cast<VectorStorage>(other_set)->storage_m)
        new_set->add(element);
    return new_set;
}

std::shared_ptr<Storage> VectorStorage::intersect(std::shared_ptr<Storage> other_set) {
    std::shared_ptr<Storage> new_set = std::make_shared<VectorStorage>();
    for (const int& element : storage_m)
        if (std::dynamic_pointer_cast<VectorStorage>(other_set)->contains(element))
            new_set->add(element);
    return new_set;
}




void MapStorage::add(const int& element) {
    storage_m.insert(element);
}

void MapStorage::remove(const int& element) {
    storage_m.erase(element);
}

bool MapStorage::contains(const int& element) {
    return storage_m.find(element) != storage_m.end();
}

std::shared_ptr<Storage> MapStorage::unite(std::shared_ptr<Storage> other_set) {
    std::shared_ptr<Storage> new_set = std::make_shared<MapStorage>();
    for (const int& element : storage_m)
        new_set->add(element);
    for (const int& element : std::dynamic_pointer_cast<MapStorage>(other_set)->getElements())
        new_set->add(element);
    return new_set;
}

std::shared_ptr<Storage> MapStorage::intersect(std::shared_ptr<Storage> other_set) {
    std::shared_ptr<Storage> new_set = std::make_shared<MapStorage>();
    for (const int& element : storage_m)
        if (std::dynamic_pointer_cast<MapStorage>(other_set)->contains(element))
            new_set->add(element);
    return new_set;
}
