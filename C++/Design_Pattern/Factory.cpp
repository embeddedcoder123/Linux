// Factory Methods

#include<iostream>
#include<cstring>
using namespace std;
enum  enumVehicle{
    TwoWheel = 0,
    FourWheel =
};


// Abract Class
class vehicle{
    public:
    virtual void name() = 0;
};

// Product 1
class TwoWheeler : public vehicle{
    public:
    void name(){
            cout<<"TwoWheeler\n";
        }
};

// Product 2
class FourWheeler : public vehicle{
    public:
    void name(){
            cout<<"FourWheeler\n";
        }
};

class client{
    vehicle* ptr = nullptr;

    public:
    client(enumVehicle obj){
        if(obj == TwoWheel ){
            ptr = new TwoWheeler();
        }
        else if(obj == FourWheel){
            ptr = new FourWheeler();
        }
    }
	vehicle* getVehicle(){
			return ptr;
		}
		
	~client(){
			if(ptr) delete ptr;
	}
	   
};
int main()
{
    client TwoWheelObj(TwoWheel);
    vehicle * twoWheelerObj = TwoWheelObj.getVehicle();
    twoWheelerObj->name();
   
    client FourWheelObj(FourWheel);
    vehicle * FourWheelerObj = FourWheelObj.getVehicle();
    FourWheelerObj->name();
   return 0;
}

1. In the above example, we have totally decoupled the selection of types 
   for object creation from the Client. 
2. The factory class is now responsible for deciding which object type 
   to create based on the input provided by the client. 
3. The client just needs to make calls to the factory class’ build method and 
   pass the type it wants without worrying about the actual implementation of 
   the creation of objects.

