#include <iostream>
#include <cstdlib>

using namespace std;

struct list
{
    int nilai;
    list *next;
};

list *top ;
list *tmp;

void menu();
void banner();
void push(int bil);
int pop();
void display();
int kosong();
void keluar();


int main()
{
    menu();
    return 0;
}

void menu()
{
    char key;
    int bil;
    top = NULL;

    do
    {
        banner();
        cout<<endl;
        cout<<"\tInputkan Pilihan : ";
        cin>>key;

        switch(key)
        {
            case '1' :  system("clear");
                        cout<<"\tMenu Input Nilai List Stack"<<endl<<endl;
                        cout<<"\tInput Bilangan : ";
                        cin>>bil;
                        push(bil);
                        system("clear");
                        break;
            case '2' :  system("clear");
                        cout<<"\tMenu POP / Hapus Nilai "<<endl<<endl;
                        if (kosong() == 1)
                        {
                            cout<<"\tList Stack kosong !"<<endl<<"\tTidak ada nilai yang Dihapus !"<<endl;
                        }
                        else
                        {
                            cout<<"\tNilai ( "<<pop()<<" ) Dihapus !";
                        }
                        cin.ignore().get();
                        system("clear");
                        break;
            case '3' :  system("clear");
                        cout<<"\tMenu Menampilkan Isi List Stack"<<endl<<endl;
                        if (kosong() == 1)
                        {
                            cout<<"\tList Stack Kosong !"<<endl<<"\tSilahkan Isikan nilai terlebih dahulu "<<endl;
                        }
                        else
                        {
                            display();
                        }
                        cin.ignore().get();
                        system("clear");
                        break;
            case '4' :  system("clear");
                        keluar();
                        cin.ignore().get();
                        system("clear");
                        break;
            default  :  system("clear");
                        cout<<"\t ____________________________________________"<<endl;
                        cout<<"\t|_Yang_anda_masukkan_tidak_ada_dalam_pilihan_|"<<endl;

        }
    }
    while(key != '4');
}

void banner()
{
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|NO|___Nim_____|____Nama________|___Kelas____|"<<endl;
cout<<"\t|01| 120401029 | Eko Subakti    | TI REG BII |"<<endl;
cout<<"\t|02| 120401060 | Gandhi Wibowo  | TI REG BII |"<<endl;
cout<<"\t|03| 120401143 | Marison Ervan  | TI REG BII |"<<endl;
cout<<"\t|__|___________|________________|____________|"<<endl;
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|______STACK_LINK_LIST_WITH_FUNCTION_________|"<<endl;
cout<<"\t|___Code:Blocks_12.11__||___Linux_Ubuntu_____|"<<endl;
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|               M  E  N  U                   |"<<endl;
cout<<"\t| 1. Push [ Isi ke dalam list ]              |"<<endl;
cout<<"\t| 2. Pop  [ Hapus ]                          |"<<endl;
cout<<"\t| 3. Tampilkan Data dari List Stack          |"<<endl;
cout<<"\t| 4. Keluar                                  |"<<endl;
cout<<"\t|_____________Input_Pilihan_1-4______________|"<<endl;
}

void push (int bil)
{
    tmp = new list;
    tmp->nilai = bil;
    tmp->next = top;
    top = tmp;
}

int pop()
{
    tmp = top;
    top = top->next;
    return tmp->nilai;
    delete tmp;
}

void display()
{
    tmp = top;
    cout<<"\tLast input :";
    while (tmp != NULL)
    {
        cout<<"<--( "<<tmp->nilai<<" )";
        tmp = tmp->next;
    }
    cout<<endl;
}

int kosong()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void keluar()
{
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|_______STACK_LINK_LIST_WITH_FUNCTION________|"<<endl;
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|         T E R I M A    K A S I H           |"<<endl;
cout<<"\t|_______UNTUK_KELUAR_TEKAN_[_ENTER_]_________|"<<endl;
}


