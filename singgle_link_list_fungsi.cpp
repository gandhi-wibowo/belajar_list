#include <iostream>
#include <cstdlib>

using namespace std;

struct list
{
    int nilai;
    list *next;
};

    list *head, *tail;
    list *element;
    list *oldtmp, *tmp;

    void banner();
    void menu();
    void tampilkan_list();
    void isi_awal();
    void isi_tengah();
    void isi_akhir();
    void hapus_head(int bil);
    void hapus_tail(int bil);
    void hapus_tengah(int bil);
    void input(int bil);
    void hapus(int bil);
    void keluar();

int main()
{
    menu();
    return 0;
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
cout<<"\t|_____SINGGLE_LINK_LIST_WITH_FUNCTION________|"<<endl;
cout<<"\t|___Code:Blocks_12.11__||___Linux_Ubuntu_____|"<<endl;
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|               M  E  N  U                   |"<<endl;
cout<<"\t| 1. Input Element Ke dalam List             |"<<endl;
cout<<"\t| 2. Hapus Element dari dalam List           |"<<endl;
cout<<"\t| 3. Tampilkan Data dari dalam Element List  |"<<endl;
cout<<"\t| 4. Keluar                                  |"<<endl;
cout<<"\t|_____________Input_Pilihan_1-4______________|"<<endl;
}

void menu()
{
    char key;
    int bil;
    head = tail = NULL;

    do
    {
        banner();
        cout<<endl;
        cout<<"\tInputkan Pilihan : ";
        cin>>key;

        switch(key)
        {
            case '1' :  system("clear");
                        cout<<"\tMenu Input Nilai List"<<endl;
                        cout<<"\tInput Bilangan : ";
                        cin>>bil;
                        input(bil);
                        system("clear");
                        break;
            case '2' :  system("clear");
                        cout<<"\tMenu Hapus Nilai List"<<endl;
                        cout<<"\tBerapa Nilai yang akan di hapus : ";
                        cin>>bil;
                        hapus(bil);
                        system("clear");
                        break;
            case '3' :  system("clear");
                        cout<<"\tMenu Menampilkan Isi List"<<endl;

                        if(head == NULL)
                        {
                            cout<<"\tList Masih Kosong !"<<endl;
                            cout<<"\tSilahkan Diisi dahulu."<<endl;
                        }
                        else
                        {
                            tampilkan_list();
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

void input(int bil)
{
    element = new list;
    element->nilai = bil;
    element->next = NULL;

    if(head == NULL)
    {
        head = tail = element;
    }
    else if(head != NULL)
    {
        if(element->nilai <= head->nilai)
        {
            isi_awal();
        }
        else if(element->nilai >= tail->nilai)
        {
            isi_akhir();
        }
        else
        {
            isi_tengah();
        }
    }
}

void hapus(int bil)
{
    if(bil <= head->nilai)
    {
        hapus_head(bil);
    }
    else if(bil >= tail->nilai)
    {
        hapus_tail(bil);
    }
    else
    {
        hapus_tengah(bil);
    }
}

void isi_awal()
{
    element->next = head;
    head = element;
}

void isi_tengah()
{
    oldtmp = tmp = head;
    while(tmp->nilai <= element->nilai)
    {
        oldtmp = tmp;
        tmp = tmp->next;
    }
    element->next = tmp;
    oldtmp->next = element;
}

void isi_akhir()
{
    tail->next = element;
    tail = element;
}

void hapus_head(int bil)
{
    if(bil == head->nilai)
    {
        tmp = head;
        head = tmp->next;
        tmp->next = NULL;
        delete tmp;
    }
}

void hapus_tengah(int bil)
{
    oldtmp = tmp = head;
    while(tmp->nilai < bil)
    {
        oldtmp = tmp;
        tmp = tmp->next;
    }
    if(tmp->nilai == bil)
    {
        oldtmp->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
    }
}

void hapus_tail(int bil)
{
    if(bil == tail->nilai)
    {
        tmp = head;
        while(tmp->next != tail)
        {
            tmp = tmp->next;
        }
        tail = tmp;
        tmp = tmp->next;
        tail->next = NULL;
        delete tmp;
    }
}

void tampilkan_list()
{
    tmp = head;
    cout<<"\tIsi dari List adalah : ";
    while (tmp != NULL)
    {
        cout<<tmp->nilai<<" ";
        tmp = tmp->next;
    }
}

void keluar()
{
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|_____SINGGLE_LINK_LIST_WITH_FUNCTION________|"<<endl;
cout<<"\t ____________________________________________"<<endl;
cout<<"\t|         T E R I M A    K A S I H           |"<<endl;
cout<<"\t|_______UNTUK_KELUAR_TEKAN_[_ENTER_]_________|"<<endl;
}
