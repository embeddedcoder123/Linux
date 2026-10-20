Singlton Class
/************Design Singleton class in C++ with example – Simple Steps************/

Answer: Singleton class in C++ is the class that is designed to provide 
only one unique instance across the system. So, whenever we create c++ 
singleton instance, it will return the same instance created earlier if any.

Singleton class requires below methods and variables.

1.Private singleton constructor and copy Constructor : 
  Singleton class should not allow users to create singleton instances 
  but they should request class to return an instance.Hence, make the 
  constructor and copy constructor of singleton class private to prevent object instantiation.
 
2.A public static function:
  As, it has blocked users to create objects, there should be
  a static function that returns object to the users using class name.
 
3.A private static pointer: 
  We need a static class pointer in singleton class to allocate object that will 
  be returned to users. Why static pointer, as static function accepts only 
  static variables as a parameter.
  
  
#include <iostream>
using namespace std;

class Singleton {
   static Singleton *instance;
   int data;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }

   public:
   static Singleton* getInstance() {
      if (!instance) instance = new Singleton;

	  return instance;
   }

   int getData() {
      return this->data;
   }

   void setData(int data) {
      this->data = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance

Singleton* Singleton::instance = 0;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}



#include <iostream>
using namespace std;

//singlton design 
class logger{
    logger(){} // So we can avoid define instance of class
    static logger* instance;
    public:
        static logger* getInstance(){
            if(instance == nullptr) instance = new logger();
            return instance;
        }
        
        void printLogs(){
            cout<<"Prints logs \n";
        }
};

logger* logger::instance = nullptr;
int main()
{
    logger* obj = logger::getInstance();
    obj->printLogs();
    std::cout<<"Hello World";

    return 0;
}