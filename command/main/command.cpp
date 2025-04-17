#include <iostream>
#include <vector>

// Command pattern
// Intend is to seperate invoker and receiver
//  Converts an action or command into an object
//  Useful when storing and reverting/undoing a string of commands
// https://gameprogrammingpatterns.com/command.html



// Command Design Pattern decouples operand & operation. 
// Thus facilitates extensions to add a new command is easy and without changing the existing code.
// Example here a new command such as rotate can be easily added

// By queueing commands, you can also define a rollback functionality in the system as we did below with undo functopm
// possible uses - in games undoing action, in bank account undoing transactions.

// As the Command Design Pattern has a separate structure to store a set of operations, we have the leverage to schedule it.
// We can store the commands in a queue or stack and fire away
// or in case of bank transactions store each 'command or transaction ' made during weekends and schedule it to be run on Monday 


//TODO https://trussel.ch/cpp/design%20patterns/2020/10/18/command-pattern.html
class GameCharacter
{
public:
    GameCharacter(int _current_pos_x = 0U, int _current_pos_y = 0U) : current_pos_x{_current_pos_x},
     current_pos_y{_current_pos_y}, previous_pos_x{0U}, previous_pos_y{0U}
    {

        std::cout << "Character initialized. Position is x: " << current_pos_x << " y: " << current_pos_y << std::endl;
    }
    int current_pos_x;
    int current_pos_y;
    int previous_pos_x;
    int previous_pos_y;
};

class Command
{
public:
    virtual void execuete(GameCharacter &g) = 0;
    virtual void undo(GameCharacter &g) = 0;
};

class JumpCommand : public Command
{
public:
    virtual void execuete(GameCharacter &g)
    {
        g.previous_pos_x = g.current_pos_x;
        g.current_pos_y = g.current_pos_y;
        g.current_pos_x ++;
        g.current_pos_y ++;
        std::cout << "Character jumped. Position is x: " << g.current_pos_x << " y: " << g.current_pos_y << std::endl;
    }
    virtual void undo(GameCharacter &g)
    {  
        g.previous_pos_x = g.current_pos_x;
        g.current_pos_y = g.current_pos_y;
        g.current_pos_x --;
        g.current_pos_y --;
        std::cout << "Character jump undo called. Position is x: " << g.current_pos_x << " y: " << g.current_pos_y << std::endl;
    }
};
int main()
{
    std::cout << "Command pattern " << std::endl;
    std::vector<Command*> commands;
    
    JumpCommand j1;
    commands.push_back(&j1);
    JumpCommand j2;
    commands.push_back(&j2);
    JumpCommand j3;
    commands.push_back(&j3);
    JumpCommand j4;
    commands.push_back(&j4);
    JumpCommand j5;
    commands.push_back(&j5);
    GameCharacter g(10, 10);
    j1.execuete(g);
    
    for(int i =0; i< commands.size();i++)
        commands[i]->execuete(g);
    
    for(int i = commands.size() -1 ; i > -1; i --)
        commands[i]->undo(g);
    return 0;
}