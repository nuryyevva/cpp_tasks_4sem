#include "implementation.h"

void Set::add(const int& element) {
    size_t start_size = storage_m->getElements().size();
    storage_m->add(element);
    if (storage_m->getElements().size() > 100 && start_size <= 100)
    {
        std::shared_ptr<Storage> new_storage = std::make_shared<MapStorage>();
        for (const int& el : storage_m->getElements()) {
            new_storage->add(el);
        }
        storage_m.reset();
        storage_m = new_storage;
    }
}

void Set::remove(const int& element) {
    size_t start_size = storage_m->getElements().size();
    storage_m->remove(element);
    if (storage_m->getElements().size() < 100 && start_size >= 100)
    {
        std::shared_ptr<Storage> new_storage = std::make_shared<VectorStorage>();
        for (const int& el : storage_m->getElements()) {
            new_storage->add(el);
        }
        storage_m.reset();
        storage_m = new_storage;
    }
}

bool Set::contains(const int& element) {
    return storage_m->contains(element);
}

std::shared_ptr<Set> Set::unite(std::shared_ptr<Set> other_set) {
    std::shared_ptr<Storage> new_vector_storage = std::make_shared<VectorStorage>();
    std::shared_ptr<Storage> new_map_storage = std::make_shared<MapStorage>();
    std::shared_ptr<Storage> united_storage = storage_m->unite(other_set->storage_m);
    if (united_storage->getElements().size() > 100) {
        std::shared_ptr<MapStorage> map_storage = std::dynamic_pointer_cast<MapStorage>(new_map_storage);
        new_vector_storage.reset();
        for (const int& el : united_storage->getElements()) {
            map_storage->add(el);
        }
        return std::make_shared<Set>(map_storage);
    } else {
        std::shared_ptr<VectorStorage> vector_storage = std::dynamic_pointer_cast<VectorStorage>(new_vector_storage);
        new_map_storage.reset();
        for (const int& el : united_storage->getElements()) {
            vector_storage->add(el);
        }
        return std::make_shared<Set>(vector_storage);
    }
}

std::shared_ptr<Set> Set::intersect(std::shared_ptr<Set> other_set) {
    std::shared_ptr<Storage> new_vector_storage = std::make_shared<VectorStorage>();
    std::shared_ptr<Storage> new_map_storage = std::make_shared<MapStorage>();
    std::shared_ptr<Storage> united_storage = storage_m->intersect(other_set->storage_m);
    if (united_storage->getElements().size() > 100)
    {
        std::shared_ptr<MapStorage> map_storage = std::dynamic_pointer_cast<MapStorage>(new_map_storage);
        new_vector_storage.reset();
        for (const int& el : united_storage->getElements()) {
            map_storage->add(el);
        }
        return std::make_shared<Set>(map_storage);
    }
    else {
        std::shared_ptr<VectorStorage> vector_storage = std::dynamic_pointer_cast<VectorStorage>(new_vector_storage);
        new_map_storage.reset();
        for (const int& el : united_storage->getElements()) {
            vector_storage->add(el);
        }
        return std::make_shared<Set>(vector_storage);
    }
}

