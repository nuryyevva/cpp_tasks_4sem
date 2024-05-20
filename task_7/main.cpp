#include <iostream>

#include "implementation.h"

void SimpleVectorStorageTest() {
    std::cout << "SIMPLE VECTOR STORAGE TEST" << std::endl;

    VectorStorage vector;

    for (size_t i = 0; i < 200; i++)
        vector.add(i);

    int counter = 0;
    for (size_t j = 0; j < 200; j++)
        counter += vector.contains(j);
    std::cout << "There are 200 elements in vector, counter = " << counter << ";\n";

    vector.remove(2);
    vector.remove(102);
    std::cout << "Deleted 102 and 2, contains(102): " << vector.contains(102) << ", contains(2): " << vector.contains(2) << ";\n";

    std::shared_ptr<Storage> vector_union_intersect = std::make_shared<VectorStorage>();
    vector_union_intersect->add(2);
    vector_union_intersect->add(102);

    std::shared_ptr<Storage> united_vector = vector.unite(vector_union_intersect);
    std::cout << "Added from unit 102 and 2, contains(102): " << united_vector->contains(102) << ", contains(2): " << united_vector->contains(2) << ";\n";

    std::shared_ptr<Storage> intersected_vector = vector.intersect(vector_union_intersect);
    int counter_intersect = 0;
    for (size_t j = 0; j < 200; j++)
        counter += intersected_vector->contains(j);
    std::cout << "There are 0 elements in vector, counter = " << counter_intersect << ";\n\n";
}

void SimpleHashStorageTest() {
    std::cout << "SIMPLE HASH STORAGE TEST" << std::endl;

    MapStorage map;

    for (size_t i = 0; i < 200; i++)
        map.add(i);

    int counter = 0;
    for (size_t j = 0; j < 200; j++)
        counter += map.contains(j);
    std::cout << "There are 200 elements in map, counter = " << counter << ";\n";

    map.remove(2);
    map.remove(102);
    std::cout << "Deleted 102 and 2, contains(102): " << map.contains(102) << ", contains(2): " << map.contains(2) << ";\n";

    std::shared_ptr<Storage> map_union_intersect = std::make_shared<MapStorage>();
    map_union_intersect->add(2);
    map_union_intersect->add(102);

    std::shared_ptr<Storage> united_map = map.unite(map_union_intersect);
    std::cout << "Added from unit 102 and 2, contains(102): " << united_map->contains(102) << ", contains(2): " << united_map->contains(2) << ";\n";

    std::shared_ptr<Storage> intersected_map = map.intersect(map_union_intersect);
    int counter_intersect = 0;
    for (size_t j = 0; j < 200; j++)
        counter += intersected_map->contains(j);
    std::cout << "There are 0 elements in map, counter = " << counter_intersect << ";\n\n";
}

void SimpleSetTest() {
    std::shared_ptr<Storage> vector_st = std::make_shared<VectorStorage>();
    std::shared_ptr<Set> set = std::make_shared<Set>(vector_st);
    for (size_t i = 0; i < 200; i ++)
        set->add(i);

    std::shared_ptr<Storage> map_st = std::make_shared<MapStorage>();
    std::shared_ptr<Set> set2 = std::make_shared<Set>(map_st);
    for (size_t i = 200; i < 250; i ++)
        set->add(i);

    std::shared_ptr<Set> set_united = set->unite(set2);
    std::cout << "Count of elements in united set " << set_united->getElements().size() << std::endl;

    std::shared_ptr<Set> set_intersected = set->intersect(set2);
    std::cout << "Count of elements in intersected set " << set_intersected->getElements().size() << std::endl;
    std::cout << std::endl;
}

int main()
{
    SimpleVectorStorageTest();
    SimpleHashStorageTest();

    SimpleSetTest();
    return 0;
}
