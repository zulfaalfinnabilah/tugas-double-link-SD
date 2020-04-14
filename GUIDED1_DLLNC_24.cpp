#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef struct Tnode
{
	int data;
	Tnode *prev;
	Tnode *next;
};
Tnode *head;

void init()
{
	head = NULL;
}

int isEmpty()
{
	if(head == NULL)
		return 1;
	else
		return 0;
}

void tambah()
{
	int value;
	Tnode *baru, *bantu;
	baru = new Tnode;
	
	baru->data = value;
	baru->next = NULL;
	baru->prev = NULL;
	
	if(isEmpty()==1)
	{
		head = baru;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		bantu = head;
		while(bantu->next != NULL)
		{
			bantu = bantu->next;
		}
	baru->next = baru;
	head->prev = bantu;
	}
	printf("Data Masuk\n");
}

void hapus()
{
	Tnode *hapus;
	
	if(isEmpty == 0)
	{
		if(head->next !=NULL)
		{
			hapus = head;
			head = head->next;
			head->prev = NULL;
			delete hapus;
		}
		else
		{
			head = NULL;
		}
	printf("Data terhapus\n");
	}
	else
	{
		head = NULL;
	}
	printf("DATA KOSONG\n");
}


void cetak()
{
	Tnode *bantu;
	bantu = head;
	
	if(isEmpty()== 0)
	{
		while(bantu != NULL)
		{
			printf("%d", bantu->data);
			bantu = bantu->next;
		}
		printf("%n");
	}
	else 
		printf("data kosong");
}

int main()
{
	int pil, a;
	char b;
	
	cout <<"Menu Double Linked List Non Circular" << endl;
	cout << "1. Menambahkan data" << endl;
	cout << "2. Menghapus data" << endl;
	cout << "3. Mengecek data kosong" << endl;
	cout << "4. Mencetak data" << endl;
	cout << "Masukkan pilihan anda" << endl;
	cin >> pil;
	if(pil==1)
	{
		system("CLS");
		cout << "Menambahkan data" << endl;
		cout << "Masukkan data" << endl;
		cin >> a;
		tambah();		
	}
	else if(pil==2)
	{
		system("CLS");
		cout << "Menghapus data" << endl;
		hapus();
	}
	else if(pil==3)
	{
		system("CLS");
		cout << "Mengecek data kosong" << endl;
		isEmpty();
	}
	else if(pil==4)
	{
		system("CLS");
		cout << "Mencetak data" << endl;
		cetak();
	}
	else
	{
		cout<< "Masukkan ulang pilihan anda" << endl;
	}
	cout << endl << "Keluar dari program? (y/n)";
	cin >> b;
	if (b=='n')
	{
		system("CLS");
		main();
	}
	else
	{
		system("PAUSE");
	}
}

