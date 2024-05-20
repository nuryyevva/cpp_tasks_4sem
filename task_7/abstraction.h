#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <memory>


class Storage {
public:
    virtual void add(const int& element) = 0;
    virtual void remove(const int& element) = 0;
    virtual bool contains(const int& element) = 0;

    virtual std::shared_ptr<Storage> unite(std::shared_ptr<Storage> other_set) = 0;
    virtual std::shared_ptr<Storage> intersect(std::shared_ptr<Storage> other_set) = 0;

    virtual std::vector<int> getElements() const = 0;

    virtual ~Storage() = default;
};


class VectorStorage : public Storage {
private:
    std::vector<int> storage_m;
public:
    void add(const int& element) override;
    void remove(const int& element) override;
    bool contains(const int& element) override;
    std::shared_ptr<Storage> unite(std::shared_ptr<Storage> other_set) override;
    std::shared_ptr<Storage> intersect(std::shared_ptr<Storage> other_set) override;
    std::vector<int> getElements() const override { return storage_m; }
    ~VectorStorage() override { storage_m.clear(); }
};


class MapStorage : public Storage {
private:
    std::unordered_set<int> storage_m;
public:
    void add(const int& element) override;
    void remove(const int& element) override;
    bool contains(const int& element) override;
    std::shared_ptr<Storage> unite(std::shared_ptr<Storage> other_set) override;
    std::shared_ptr<Storage> intersect(std::shared_ptr<Storage> other_set) override;
    std::vector<int> getElements() const override {
        std::vector elements(storage_m.begin(), storage_m.end());
        return elements;
    }
};

#endif // STORAGE_H
