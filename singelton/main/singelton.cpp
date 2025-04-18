#include <iostream>
#include <mutex>


//https://stackoverflow.com/questions/86582/singleton-how-should-it-be-used


// THIS IS SCOTT MYERS SINGLETON CLASS
// PRIVATE CONSTRUCTOE DESTEUCTOE
// STATIC METHOD WHICH RETURNS AN STATIC INSTANCE OF CLASS
 // Delete copy constructor and assignment operator to prevent copying - IN PUBLIC
class NikkiSingleton{

    public:
    NikkiSingleton(const NikkiSingleton&) = delete;
    NikkiSingleton& operator=(const NikkiSingleton&)= delete;

   static NikkiSingleton& getNikkiInstance()
   {static NikkiSingleton nikinstance;
     return nikinstance;}
    private:
    NikkiSingleton(){
std::cout<<"NikkiSingleton constructor called"<<std::endl;
    }
    ~NikkiSingleton(){
std::cout<<"NikkiSingleton destructor called"<<std::endl;
    }
};
int main() {
    // Access the Singleton instance
    NikkiSingleton& instance = NikkiSingleton::getNikkiInstance();

    return 0;
}