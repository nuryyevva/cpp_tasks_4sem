#include "expression_factory.h"
#include "operators.h"

int main() {
    ExpressionFactory factory = ExpressionFactory::GetInstance();
    std::shared_ptr<Constant> c = factory.CreateConstant(2);
    std::shared_ptr<Variable> v = factory.CreateVariable("x");
    std::shared_ptr<Addition> expression1 = std::make_shared<Addition>(c, v);
    std::shared_ptr<Subtraction> expression2 = std::make_shared<Subtraction>(c, v);

    std::map<std::string, int> context;
    context["x"] = 7;

    expression1->PrintExpression();
    std::cout << " = " << expression1->Calculate(context) << std::endl;

    expression2->PrintExpression();
    std::cout << " = " << expression2->Calculate(context) << std::endl;


    expression1.reset();
    expression2.reset();
    factory.DeleteVariable("x");

    return 0;
}
