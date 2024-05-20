#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "operators.h"

// Class for variables and constant creation
class ExpressionFactory {
private:
    std::map<int, std::shared_ptr<Constant>> constants;
    std::map<std::string, std::shared_ptr<Variable>> variables;

    ExpressionFactory() {
        for (int i = -5; i <= 256; i++) {
            constants[i] = std::make_shared<Constant>(i);
        }
    }
public:
    static ExpressionFactory& GetInstance() {
        static ExpressionFactory instance;
        return instance;
    }

    std::shared_ptr<Constant> CreateConstant(const int value) {
        if (value >= -5 && value <= 256) {
            return constants[value];
        } else {
            std::make_shared<Constant>(value); // Создание новой константы, если значение не входит в диапазон
        }
    }
    std::shared_ptr<Variable> CreateVariable(const std::string& name) {
        if (variables.find(name) != variables.end())
            return variables[name];
        else {
            std::shared_ptr<Variable> var = std::make_shared<Variable>(name);
            variables[name] = var;
            return var;
        }
    }
    void DeleteVariable(const std::string& name) {
        if (variables.find(name) != variables.end()) {
            variables.erase(name);
        }
    }

    void DeleteConstant(int constant) {
        if (constants.find(constant) != constants.end()) {
            constants.erase(constant);
        }
    }
};


#endif // EXPRESSIONFACTORY_H
