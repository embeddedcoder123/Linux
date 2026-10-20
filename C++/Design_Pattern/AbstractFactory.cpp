#include <iostream>
using namespace std;
#define TATA


class Company {
    public:
   	 Company() {
     		 id_ = total_++;
   	  }
    virtual void companyName() = 0;
    protected:
      int id_;
      static int total_;
};
int Company::total_ = 0;


//Product A1
class TataMotor: public Company {
  	public:
    void companyName() {
      cout << "TataMotor " << id_ << ": companyName" << endl;
    }
};

//Product A2
class TataPower : public Company {
  public:
    void companyName() {
      cout << "TataPower " << id_ << ": companyName" << endl;
    }
};


//Product B1
class AdaniMotor : public Company {
  public:
    void companyName() {
      cout << "AdaniMotor " << id_ << ": companyName" << endl;
    }
};

//Product B2
class AdaniPower : public Company {
  public:
    void companyName() {
      cout << "AdaniPower " << id_ << ": companyName" << endl;
    }
};

class Factory {
  public:
    virtual Company* powerCompanyInstance() = 0;
    virtual Company* motorCompanyInstance() = 0;
};

// Concrete factory1
class TataFactory : public Factory {
  public:
    Company* motorCompanyInstance() {
      return new TataMotor;
    }
    Company* powerCompanyInstance() {
      return new TataPower;
    }
};

// Concrete factory2
class AdaniFactory : public Factory {
  public:
    Company* motorCompanyInstance() {
      return new AdaniMotor;
    }
    Company* powerCompanyInstance() {
      return new AdaniPower;
    }
};

int main() {
#ifdef TATA
  Factory* factory = new TataFactory;
#elifdef ADANI
  Factory* factory = new AdaniFactory;
#endif
  Company* Companys[3];

  Companys[0] = factory->motorCompanyInstance(); 
  Companys[1] = factory->powerCompanyInstance(); 
  Companys[2] = factory->motorCompanyInstance();

  for (int i=0; i < 3; i++) {
    Companys[i]->companyName();
  }
  return 0;
}

/*
TataMotor 0: companyName
TataPower 1: companyName
TataMotor 2: companyName
*/
