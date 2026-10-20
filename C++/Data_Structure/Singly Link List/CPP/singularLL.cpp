#include<iostream>

class node
{
    public:
        int data;
        node * next = nullptr;
        node (int udata):data (udata){};
};

class SLinkedList
{
    node* hp = nullptr;
    public:
		
        SLinkedList() noexcept = default;
        
		void add_front (int udata){
           node *ptr = new node(udata);
            
			if (hp == nullptr){
            	hp = ptr;
            }
            else{
                ptr->next = hp;
                hp = ptr;
            }
        }

        void add_end (int udata){
            node *ptr = new node(udata);
            if(hp ==nullptr){
               hp = ptr;
            }
            else{
                node *temp = hp;
                while(temp->next != nullptr){ 
                    temp = temp->next;
                }
                temp->next = ptr; 
            }
        
        }
    
        void add_middle (int udata,int pos){
            if(pos == 0){
                node *ptr = new node(udata);
                ptr->next = hp;
                hp = ptr;
                return;
            }
            else{
                node *temp = hp;
                int cur_pos =0;
                while(cur_pos < (pos-1) && temp != nullptr){
                    temp = temp->next;
                    cur_pos++;
                }
                if(temp == nullptr){
                    std::cout<<"Requested position is out of range\n";
                    return;
                }
                else{
                    node* ptr = new node(udata);
                    ptr->next = temp->next;
                    temp->next = ptr;
                }
            }
        }
        
        void delete_node(int pos){
            node *temp = hp;
            int cnt =0;
            
            while(cnt <(pos -1) && temp != nullptr){
                temp = temp->next;
                cnt++;
            }
            if(temp == nullptr) {
                std::cout<<"requested position is out of range \n";
                return;
            }
            else{
                node *delete_node = temp->next;
                temp->next = temp->next->next;
                std::cout<<"node going to delete has data is:"<<delete_node->data<<std::endl;
                delete delete_node;
            }
        }
        void sort_list(){
            
            std::cout<<"sort_list is called..."<<std::endl;
            node *cur_ptr = hp;
            node *next_ptr = cur_ptr->next;
            while(cur_ptr != nullptr){
                next_ptr = cur_ptr->next;
                while(next_ptr != nullptr){
                    if(cur_ptr->data > next_ptr->data){
                        cur_ptr->data = (next_ptr->data + cur_ptr->data) - (next_ptr->data = cur_ptr->data); 
                    }
                    next_ptr = next_ptr->next;
                }
                cur_ptr = cur_ptr->next;
            }
        }
        void printList (){
        node *temp = hp;
            while(temp != nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
        std::cout<<std::endl;
        }
};

int main (){
  SLinkedList SL;
  SL.add_front(10);
  SL.add_front(20);
  SL.add_front(30);
  SL.add_end(40);
  SL.add_end(50);
  SL.add_middle(100,0);
  SL.printList();
  
  SL.sort_list();
  SL.printList();
  
  SL.delete_node(2);
  SL.printList();
  
  
  std::cout << "End of main..." << std::endl;
  return 0;
}


