#include <iostream>
#include<string>
#include<fstream>
using namespace std;
struct Contact{
string name;
string mobile;
};
struct node{
    Contact data;
    node* next;
};

struct List{
    node* start;
};

void init(List*L)
{
    L->start=NULL;
}
int isEmpty(List L){
    if(L.start==NULL)
        return 1;
    else
        return 0;
}

int insertFront(List *L,Contact c){
    node* p;
    p=new node;
    if(p==NULL)
        return 0;

    p->data.name=c.name;
    p->data.mobile=c.mobile;
    p->next=L->start;
    L->start=p;
    return 1;
}

void display(List L){
    if(isEmpty(L))
        cout<<"Empty List\n";
    else{
        node *p=L.start;
        cout<<"Name\tMobile\n";
        while(p!=NULL){
            cout<<p->data.name<<"\t"<<p->data.mobile<<endl;
          p=p->next;
        }
    }
}

List book[26];

void initilizePhoneBook(){
    for(int i=0;i<26;i++)
        init(&book[i]);
}

void PrintPhoneBook(){
    for(int i=0;i<26;i++)
    {
        cout<<"Contact Starting with "<<((char)('A'+i))<<endl;
       display(book[i]);
       cout<<"--------------------------------------\n";
    }

}

int hashFunction(string s){
   return (int)(s[0]-'A');
}

void insertInBook(Contact c){
    int i=hashFunction(c.name);
    insertFront(&book[i],c);
}

int main()
{
initilizePhoneBook();
fstream f;
f.open("contacts.txt",ios::in);
while(!f.eof()){
    Contact c;
    f>>c.name;
    f>>c.mobile;
    insertInBook(c);
}



PrintPhoneBook();






    return 0;
}
