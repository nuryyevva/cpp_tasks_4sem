#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>
#include <map>
#include <memory>


// Base Class for operators
class Operator {
public:
    virtual void PrintExpression() const = 0;
    virtual int Calculate(std::map<std::string, int>& context) const = 0;
};



// class for sum operator
class Addition : public Operator {
private:
    std::shared_ptr<Operator> left;
    std::shared_ptr<Operator> right;
public:
    Addition(std::shared_ptr<Operator> left_operand, std::shared_ptr<Operator> right_operand)
        : left(left_operand), right(right_operand) {}

    void PrintExpression() const override {
        left->PrintExpression();
        std::cout << " + ";
        right->PrintExpression();
    }

    int Calculate (std::map<std::string, int>& context) const override
    { return left->Calculate(context) + right->Calculate(context); }
};


class Subtraction : public Operator {
private:
    std::shared_ptr<Operator> left;
    std::shared_ptr<Operator> right;
public:
    Subtraction(std::shared_ptr<Operator> leftOperand, std::shared_ptr<Operator> rightOperand)
        : left(leftOperand), right(rightOperand) {}

    void PrintExpression() const override {
        left->PrintExpression();
        std::cout << " - ";
        right->PrintExpression();
    }

    int Calculate(std::map<std::string, int>& context) const override {
        return left->Calculate(context) - right->Calculate(context);
    }
};


// Class for variable
class Variable : public Operator {
private:
    std::string name;
public:
    Variable(const std::string& var_name) : name(var_name) {}
    void PrintExpression() const override { std::cout << name; }
    int Calculate(std::map<std::string, int>& context) const override { return context[name]; }
};




// Class for Constant
class Constant : public Operator {
private:
    int value;
public:
    Constant(const int const_value) : value(const_value) {}
    void PrintExpression() const override { std::cout << value; }
    int Calculate (std::map<std::string, int>& context) const override { return value; }
};


#endif // OPERATORS_H
