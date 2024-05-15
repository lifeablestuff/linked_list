
#include <iostream>
using namespace std;

struct node{
	node(string s, node*);
	string st;
	node* next;
};

node::node(string s, node* np=0){ //:: scope resolution operator
	st = s;
	next = np;
}

//alternate node ctor with initialization list
//node::node(string s, node* np=0): st(s), next(np) {}



void walk(node* nd){
	cout<< nd->st <<" ";
	if (nd->next  !=0 )
		walk(nd->next);
}

int length(node* nd){
    int count = 0;
    if (nd->next !=0){
        walk(nd->next);
        count+= 1;
    }
    return count;
}

/*
node* NewNode(string s){
	node* np = new node;
	np->st = s;
	np->next = 0;
	return np;
}
*/

//Must pass nd by ref or seg fault. We must change root node address in main.
void pushfront(node* &nd, string s){ 
	nd = new node( s, nd); //wow this does it all since the ctor sets the next pointer 
    

}


void popfront(node* &nd){
    node* temp = nd->next;
    delete(nd);
    nd = temp;
    
}


/*can't pushback on root=0 since no node exists yet. So must check for it.
copy ctor called for nd pointer so root in main not changed. This is 
okay if one node already exists since we just add to the end of it.
But if no node exists yet (root=0) then we must change root addr so we
have to pass by ref also.*/

void pushback(node* &nd, string s){ 
    

}


void popback(node* &nd){
    
    node* temp;
    node* x = nd;
    
    while (x->next != nullptr){
        x = x->next;
        if (x->next==nullptr){
            temp = x->next;
            delete temp;
            x->next = nullptr;
        }
        
    }

}


/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, string s){
    node* x = nd;
    if (nd==nullptr){
        nd = new node(s,nullptr);
        return;
    }
    while(x->next != nullptr){
        if(x->st < s){
            if(x->next==nullptr){

                 x->next = new node(s,nullptr);
                 return;
        }
        else{
             x->next = new node(s,x->next);
             return;
        }
        x = x->next;
        break;
    }



}

	
void lfree(node* nd){
 if (nd == 0) return; //don't crash if nothing in linked list
     if (nd->next != 0)
        lfree(nd->next);
     delete nd;
     nd = 0; //sets all linked list pointers to zero (including the first one, root=0)   
	/*
	//alternate better solution 
	if (nd != 0){    // or simply if (nd)
		lfree(nd->next);
		delete nd;
		nd = 0;
	}
	*/
     /*
    //alternate not better solution:
    if (nd == 0) return;
    lfree(nd->next);
    delete nd;
    nd = 0;
    */     


}
	


int main(){
	
	const char* sarray[6] = {"b","d","a","e","f","c"};
	node* root=0;
	
	int x;
	for (x=0; x<6 ; x++)
	{
		//pushback(root, sarray[x]);
		//pushfront(root, sarray[x]);
		insert(root, sarray[x]);
		walk(root);
		cout<<endl;
	}
	for (x=0; x<3 ; x++)
	{
		cout<<"popfront"<<endl;
		popfront(root);
		walk(root);
		cout<<endl;
	}
	insert(root, "zoo");
	walk(root);
	cout<<endl;	
	for (x=0; x<3 ; x++)
	{
		cout<<"popback"<<endl;
		popback(root);
		walk(root);
		cout<<endl;
	}
	pushback(root, "zzz");
	walk(root);
	cout<<endl;
	
	lfree(root);
	return 0;
}

	
