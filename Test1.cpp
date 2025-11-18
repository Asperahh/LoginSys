#include <iostream>

using namespace std;

const int N = 21;

int AccountNo = 0;


struct Account{
    char Name[N];
    char password[N];
    int Id;
    bool Log = false;

    Account(const char* n, const char* p, int id) {
        strncpy(Name, n, 21);
        Name[20] = '\0'; 
        strncpy(password, p, 21);
        password[20] = '\0';
        Id = id;
    
    }
};

struct AccountNode{
    Account* data;
    AccountNode* next;
    AccountNode* prev;

    AccountNode(Account* ac, AccountNode* nxt = nullptr, AccountNode* prv = nullptr)
        : data(ac), next(nxt), prev(prv) {}
};



void RHelp(AccountNode* temp);

AccountNode* head = nullptr;
Account* Session = nullptr;

void print(int k){
    switch(k){
        case 1:
            cout<<R"(          _____                    _____                _____                   _______         
         /\    \                  /\    \              /\    \                 /::\    \        
        /::\____\                /::\    \            /::\    \               /::::\    \       
       /::::|   |               /::::\    \           \:::\    \             /::::::\    \      
      /:::::|   |              /::::::\    \           \:::\    \           /::::::::\    \     
     /::::::|   |             /:::/\:::\    \           \:::\    \         /:::/~~\:::\    \    
    /:::/|::|   |            /:::/__\:::\    \           \:::\    \       /:::/    \:::\    \   
   /:::/ |::|   |           /::::\   \:::\    \          /::::\    \     /:::/    / \:::\    \  
  /:::/  |::|   | _____    /::::::\   \:::\    \        /::::::\    \   /:::/____/   \:::\____\ 
 /:::/   |::|   |/\    \  /:::/\:::\   \:::\    \      /:::/\:::\    \ |:::|    |     |:::|    |
/:: /    |::|   /::\____\/:::/  \:::\   \:::\____\    /:::/  \:::\____\|:::|____|     |:::|    |
\::/    /|::|  /:::/    /\::/    \:::\  /:::/    /   /:::/    \::/    / \:::\    \   /:::/    / 
 \/____/ |::| /:::/    /  \/____/ \:::\/:::/    /   /:::/    / \/____/   \:::\    \ /:::/    /  
         |::|/:::/    /            \::::::/    /   /:::/    /             \:::\    /:::/    /   
         |::::::/    /              \::::/    /   /:::/    /               \:::\__/:::/    /    
         |:::::/    /               /:::/    /    \::/    /                 \::::::::/    /     
         |::::/    /               /:::/    /      \/____/                   \::::::/    /      
         /:::/    /               /:::/    /                                  \::::/    /       
        /:::/    /               /:::/    /                                    \::/____/        
        \::/    /                \::/    /                                      ~~              
         \/____/                  \/____/                                                       
                                                                                                )"<<endl;
    break;



    }



}


bool CStringCompare(const char C1[N],const char C2[N]){
    int i = 0;
    while(C1[i]!='\0'&&C2[i]!='\0'){
        if(C1[i]!=C2[i]){
            return false;
        }
        i++;
    }
    return (C1[i]=='\0'&&C2[i]=='\0');
}



Account* AccountSearch(const char Name[N],AccountNode* head){
    if(head==nullptr)
        return nullptr;
    
    while(head!=nullptr){
        if(CStringCompare(Name,head->data->Name)){
            return head->data;
        }
        head = head->next;
    }
    return nullptr;
}

Account* AccountSearch(const int Id,AccountNode* head){
    if(head==nullptr)
        return nullptr;
    while(head!=nullptr){
        if(head->data->Id == Id){
            return head->data;
        }
        head = head->next;
    }
    return nullptr;
}

AccountNode* SearchNode(AccountNode* head,char Name[N]){
    while(head!=nullptr){
        if(CStringCompare(head->data->Name,Name)){
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

bool Validation(char pass[N]){
    return true;
}

bool Removal(int i){
    switch(i){
        case 1:
                if(Session==nullptr){
                    return false;
                }
                AccountNode* temp; 
                temp = SearchNode(head,Session->Name);
                if(temp == head){
                    head = temp->next;
                }
                if(temp->next){
                    temp->next->prev = temp->prev;
                }
                if(temp->prev){
                    temp->prev->next = temp->next;
                }
                delete temp->data;
                delete temp;
            return true;
            break;
        case 2:     //Delete all List
            RHelp(head);
            head = nullptr;
            Session = nullptr;
            return true;
            break;

        default:
            return false;
    }
    return false;
}

void RHelp(AccountNode* temp){
    if(temp==nullptr)
        return;
    RHelp(temp->next);
    delete temp->data;
    delete temp;
}



void Storage(int p){
    switch(p){
        case 1:

            break;


    }
}

void Acc(int i){
    switch(i){
        case 1:
            bool flag = false;
            char temp[N];
            char pass[N];

            cout<<"Creating Your First Account!"<<endl;
            cout<<"Please Type Your Desired Name!"<<endl;
            //Check if it shares the same name using another function, just make a searching algo,done
            cin.getline(temp,N);
            while (AccountSearch(temp, head) != nullptr) {
                cout << "Account Name has been used! Please try again!" << endl;
                cin.getline(temp, N);
            }
            cout<<"Please Type Your Desired Password!"<<endl;
            cin.getline(pass,N);
            while(!Validation(pass)){
                cout<<"Invalid PassWord Input,Please try again!"<<endl;
                cin.getline(pass,N);
            }

            AccountNode* current = head;
            if(current == nullptr){
                Account* nwAc = new Account(temp,pass,++AccountNo);
                AccountNode* nwNode = new AccountNode(nwAc,nullptr,nullptr);
                head = nwNode;
            }else{
                while(current->next!=nullptr){
                    current = current->next;
                }
                Account* nwAc = new Account(temp,pass,++AccountNo);
                AccountNode* nwNode = new AccountNode(nwAc,nullptr,current);
                current->next = nwNode;
            }
            break;

    }
}

void Login(){
    char temp[N];
    char pass[N];
    int x = -1;

    cout<<"Welcome to the Login System"<<endl;
    cout<<"1.Login\n2.ResetMyPassword"<<endl;
    cin>>x;
    while(x!=1&&x!=2){
        cout<<"Invalid Input,Please Retry"<<endl;
        cin>>x;
    }
    if(x==1){
        int count = 0;
        cout<<"Enter Your Login Name"<<endl;
        cin.ignore();
        cin.getline(temp,N);
        Account* check = AccountSearch(temp,head);
        while(count<3&&check==nullptr){
            cout<<"Invalid Name Please Retry"<<endl;
            cin.getline(temp,N);
            check = AccountSearch(temp,head);
            ++count;
            if(count==3){
                cout<<"Please Try again later"<<endl;
                return;
            }
        }
        if(check!=nullptr){
            count = 0;
            cout<<"Please Enter your Password! "<<temp<<endl;
            cin.getline(pass,N);
            while(!CStringCompare(pass,check->password)&&count<3){
                cout<<"Wrong Entry!"<<endl;
                cin.getline(pass,N);
                ++count;
                if(count==3){
                    cout<<"Please Try again later"<<endl;
                    return;
                }
            }
            cout<<"Welcome Back! "<<temp<<endl;
            Session = check;
        }                           //defensive only
    }else if (x==2){
        return;


    }
}





void menu(){
    int choice = -1;
    while(choice!=4){
        cin>>choice;
        while(choice<=0||choice>4){
        cout<<"Invalid Input"<<endl;
        cin>>choice;
        }
        cin.ignore();
        if(Session!=nullptr){
            switch(choice){
                case 1:
                case 2:
                    cout<<"Delete"<<endl;//temp shouldnt place here
                    Removal(2);
                    break;
                case 3:
                    cout<<"Signing out!"<<endl;
                    Session = nullptr;
                    break;
                case 4:
                    cout<<"Good Bye!"<<endl;
                    Removal(1);
                    break;
            }
        }else if(Session == nullptr){
            switch(choice){
                case 1:
                    Acc(1);
                case 2:
                    Login();
                case 3:
                    break;
                case 4:
                    cout<<"Good Bye!"<<endl;
                    Removal(1);
                    break;
            }
        }

    }


}


int main(){
    menu();
    return  0;
}