
class node{
public:
    int data = 0;
    node *next;
    node() = default;
    node(int Udata = 0) : data(Udata), next(nullptr){} 
};

class linklist{
    node *hp = nullptr;
    public:
        void add_end(int udata){
            node *ptr = new node(udata);
            node *temp = this->hp;
            
            if(hp == nullptr)/*hp is nullptr*/{ 
                hp = ptr;
            }
            else{
                int i =0;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = ptr;
            }
        }
        
        void add_begin(int udata){
            node *ptr = new node(udata);
            node *temp = this->hp;
            
            if(hp == nullptr)/*hp is nullptr*/{ 
                hp = ptr;
                return;
            }
            else{
                ptr->next = hp;
                hp = ptr;
            }
        }
        
        void deleteNode(int pos){
            node *temp = hp;
            if(pos == 0){
                hp = hp->next;
                delete temp;
            } else{
                for(int i =0;i < pos-1 && temp !=nullptr ;i++) temp = temp->next;
                
                if(temp->next == nullptr){ 
                    cout<<"Given pos is out of range"<<endl; 
                    return;}
                
                node* toBeDel = temp->next;
                temp->next = temp->next->next;
                delete toBeDel;
            }
        }
        void print(){
            node *temp = hp;
            while(temp != nullptr){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<endl;
        }
};
int main()
{
    linklist LS;
    LS.add_end(10);
    LS.add_end(20);
    LS.add_end(30);
    LS.add_begin(40);
    LS.add_begin(50);
    
    
    LS.print();
    
    LS.deleteNode(5);
    LS.print();
    

    return 0;
}