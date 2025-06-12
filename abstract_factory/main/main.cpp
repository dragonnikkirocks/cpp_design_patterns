#include<iostream>

//actually should be an abstract class
class Shoes{
    
    public:
    std::string sole_type;
    std::string sole_height;
};

//parameters should be private
class MensShoes : public Shoes {
    public:
    std::string shoe_name;
};

class WomensShoes : public Shoes {
    public:
    std::string shoe_name;
};

//AbstractFactory
class FactoryInterfaceShoes{
    public:
    virtual WomensShoes* makeWomenShoes()  = 0;
    virtual MensShoes* makeMensShoes()  = 0;

};

class Gucci:FactoryInterfaceShoes{
public:

virtual WomensShoes* makeWomenShoes() override {

    WomensShoes gucci_sandals;
    gucci_sandals.shoe_name = "Gucci";
    gucci_sandals.sole_height = "5inch";
    gucci_sandals.sole_type = "leather";
    return &gucci_sandals;
}
virtual MensShoes* makeMensShoes() override {

    MensShoes gucci_sandals;
    gucci_sandals.shoe_name = "Gucci";
    gucci_sandals.sole_height = "1inch";
    gucci_sandals.sole_type = "leather";
    return &gucci_sandals;
}
};

class Louboutins:FactoryInterfaceShoes{
public:

virtual WomensShoes* makeWomenShoes() override {

    WomensShoes l_shoes;
    l_shoes.shoe_name = "Louboutins";
    l_shoes.sole_height = "5inch";
    l_shoes.sole_type = "red sole";
    return &l_shoes;
}
virtual MensShoes* makeMensShoes() override {

    MensShoes l_shoes;
    l_shoes.shoe_name = "Louboutins";
    l_shoes.sole_height = "1inch";
    l_shoes.sole_type = "red soles";
}
};


int main(){
    return 0;
}