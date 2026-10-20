
class LegacyClass { // 
public:
    void specificRequest() {
        // Do something specific
    }
};


// Target interface
class TargetInterface {
public:
    virtual void request() = 0;
};



// Adapter class
class Adapter : public TargetInterface {
private:
    LegacyClass* m_legacy;
	


public:
    Adapter(LegacyClass* legacy) : m_legacy(legacy) {}

    void request() override {
        m_legacy->specificRequest();
    }
};






// Client code
int main() {
	
    LegacyClass legacy;
    Adapter adapter(&legacy);


    // Client code expects a TargetInterface
    TargetInterface* target = &adapter;
    target->request();
    return 0;
}