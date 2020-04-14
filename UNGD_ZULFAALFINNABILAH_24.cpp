#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct node
{
	string password;
	node* next;
	node* prev;
}*list;

list head;
list tail;
int batas;

void initData()
{
	head = NULL;
	tail = NULL;
}

int cekHead()
{
	return (head == NULL) ? 1 : 0;
}

void tampilList()
{
	list bantu;
	bantu = head;
	if (cekHead() == 1)
	{
		cout << "Password Belum Diinputkan";
	}
	else
	{
		cout << endl;
		for (int x = 1; x <= batas; x++)
		{
			cout << "Karakter Ke-" << x << " : " << bantu->password << endl;
			bantu = bantu->next;
		}
	}
}

void tampilListBaru()
{
	list bantu;
	bantu = head;
	if (cekHead() == 1)
	{
		cout << "Password Belum Diinputkan";
	}
	else
	{
		for (int x = 1; x <= batas; x++)
		{
			cout << bantu->password;
			bantu = bantu->next;
		}
	}
}


void Enkripsi()
{
	list bantu, tempat;
	char random;
	bantu = head;
	for (int x = 1; x <= batas; x++)
	{
		if (x == batas - 2)
		{
			bantu->prev->next = NULL;
			bantu->prev = NULL;
			head = bantu;
		}
		else
		{
			bantu = bantu->next;
		}
	}

	bantu = head;
	do
	{
		bantu = bantu->next;
	} while (bantu->next != NULL);
	tail = bantu;
	head->prev = tail;
	tail->next = head;

	int jarak, a, b, hasil;
	jarak = 33 - 47;
	a = rand();
	b = a % jarak;
	hasil = b + 33;
	random = hasil;

	tempat = new node;
	tempat->password = random;
	bantu = head;
	for (int x = 1; x <= 3; x++)
	{
		bantu = bantu->next;
	}
	bantu->prev->next = tempat;
	tempat->prev = bantu->prev;
	tempat->next = bantu;
	bantu->prev = tempat;
	batas++;
}

void Deskripsi()
{
	list bantu, hapus;
	hapus = bantu = head;
	for (int x = 1; x <= 3; x++)
	{
		hapus = hapus->next;
	}
	hapus->prev->next = hapus->next;
	hapus->next->prev = hapus->prev;
	delete hapus;
	batas--;

	for (int x = 1; x <= 3; x++)
	{
		bantu = bantu->next;
	}
	bantu->prev->next = NULL;
	bantu->prev = NULL;
	head = bantu;

	bantu = head;
	do
	{
		bantu = bantu->next;
	} while (bantu->next != NULL);
	tail = bantu;
	head->prev = tail;
	tail->next = head;
}

void KeluarProgram()
{
	cout << endl;
	cout << "Anda keluar dari Program" << endl;
	system("PAUSE");
}

int main()
{
	initData();
	list n;
	list bantu;
    string data;
    int pilihan;
	bantu = new node;
	do
	{
		cout <<"=============================================="<< endl;
        cout << "Program Enkripsi dan Deskripsi Password" << endl;
        cout <<"=============================================="<< endl;
        cout << "1. Input Password\n";
        cout << "2. Tampilkan Password\n";
        cout << "3. Enkripsi Password Data\n";
        cout << "4. Deskripsi Password Data\n";
        cout << "5. Keluar dari Program\n";
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
            {
                cout << "Masukkan Panjang Password: ";
                cin >> batas;
                if(batas < 6)
                {
                cout << "Panjang Password Tidak Boleh Kurang Dari 6";
                cout << endl;
                break;
                }
                else
                {
                    for (int x = 1; x <= batas; x++)
                    {
                        if (x == 1)
                        {
                            cout << "Masukkan Karakter Ke-" << x << " : ";
                            cin >> data;
                            n = new node;
                            n->password = data;
                            n->prev = tail;
                            head = n;
                            bantu = n;
                        }
                        else if (x == batas)
                        {
                            cout << "Masukkan Karakter Ke-" << x << " : ";
                            cin >> data;
                            n = new node;
                            n->password = data;
                            bantu->next = n;
                            n->prev = bantu;
                            n->next = head;
                            tail = n;
                            head->prev = tail;
                            bantu = head;
                            cout << endl;
                            cout << "Password Tersimpan\n\n";
                        }
                        else
                        {
                            cout << "Masukkan Karakter Ke-" << x << " : ";
                            cin >> data;
                            n = new node;
                            n->password = data;
                            bantu->next = n;
                            n->prev = bantu;
                            bantu = bantu->next;
                        }
                    
                    }
                }break;
            }
            case 2:
                tampilList();
                cout << endl;
                break;
            case 3:
                {
                	cout << endl;
                    cout << "Password Asli: ";
                    tampilListBaru();
                    Enkripsi();
                    cout << "\nPassword Setelah Di Enkripsi: ";
                    tampilListBaru();
                    cout << endl << endl;
                    break;
                    }
            case 4:
            {
            		cout << endl;
                    cout << "Password Asli: ";
                    tampilListBaru();
                    Deskripsi();
                    cout << "\nPassword Setelah Di Deskripsi: ";
                    tampilListBaru();
                    cout << endl << endl;
                    break;
                    }
            case 5:
            	{
                KeluarProgram();
                break;
            	}
            default:
                cout<<"Input anda salah"<<endl;
                break;
        }
    }while(pilihan !=6);
    system("PAUSE");
     return 0;
}
