#include<iostream>
class Visitor;
class Monster{
    public:
    Monster(){}
    virtual ~ Monster(){}

    Monster(const Monster&) = default;
    Monster(Monster&& ) = default;
    Monster& operator=(const Monster& ) = default;
    Monster& operator=(Monster&&) = default;

    virtual void roar() = 0;
    virtual void accept(Visitor& visitor) =0;

};
class Orc; //Notice how orc and visitor have to be forward declared
           //Orc already existed
           //The main idea behind Visito pattern to seperate out the behavuour to a seperate class
           // Used to extend existing code. Like here Orc already existing
           //Refer:https://www.modernescpp.com/index.php/the-visitor-pattern/#Example
           //The basic idea of the visitor pattern is to have a `Visitor` base class that visits a bunch 
           //of objects of the class hierarchy (i.e. the `Monster`s) in question.
          //It calls an `accept` or `acceptVisitor` method on each object
          //This method in turn is implemented in each class of the hierarchy. Its responsibility 
          //is to call back a `visit` method on the visitor specific to the visited object’s class. 
          
class Visitor{
    public:
    Visitor()=default;
    virtual ~Visitor()=default;

    Visitor(const Visitor&)=default;
    Visitor(Visitor&&)=default;
    Visitor& operator=(const Visitor&)=default;
    Visitor& operator=(Visitor&&)=default;

   virtual void visit(Orc& orc)=0;
};

class OrcVisitor : public Visitor{
    public:
    OrcVisitor(){std::cout<<"OrcVisitor ctor "<<std::endl;}
    virtual void visit(Orc& orc) override{
        std::cout<<"Orc visitor called /n";
    }
};


class Orc: public Monster{
   public:
    Orc() : Monster(){}
     ~Orc(){

    }
    Orc(const Orc&) = default;
    Orc(Orc&&) =default;
    Orc& operator=(const Orc& )= default;
    Orc& operator=(Orc&&)= default;

    virtual void roar() override{std::cout<<"Orc roaring "<<std::endl;}
    virtual void accept(Visitor& visitor) override{
         std::cout<<"OrcAccept called. "<<std::endl;
         visitor.visit(*this);
        }

};


int main(){
  std::cout<<"Visitor pattern /n";
   OrcVisitor v;
   Orc orc;
   orc.accept(v);

    return 0;
}