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

int isEmpty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

void tambah()
{
	int databaru;
	
	Tnode *baru, *bantu;
	baru = new Tnode;
	baru->data = databaru;
	baru->next = baru;
	baru->prev = baru;
	
	if(isEmpty()==1)
	{
		head = baru;
		head->next=head;
		head->prev=head;
	}
	else
	{
		bantu=head->prev;
		bantu->next=baru;
		baru->prev=bantu;
		baru->next = head;
		head->prev=baru;
	}
	cout <<"Data masuk!";
}

void hapus()
{
	Tnode *hapus, *bantu;
	int d;
	if(isEmpty()==0)
	{
		if(head->next!=head)
		{
			hapus = head;
			d = hapus->data;
			bantu = head->prev;
			head= head->next;
			bantu->next = head;
			head->prev = bantu;
			delete hapus;
		}
		else
		{
			d =head-> data;
			head = NULL;
		}
		printf("Data terhapus!",d);
	}
	else 
	printf("Masih kosong\n");
}

void tampil()
{
	Tnode *bantu;
	bantu = head;
	if(isEmpty()==0)
	{
		do
		{
			cout << bantu->data;
			bantu = bantu->next;
		}
		while(bantu!=head);
		printf("\n");
	}
	else
	cout<<"Masih kosong\n";
}

int main()
{
	int pil, a;
	char b;
	
	cout <<"Menu Double Linked List Circular" << endl;
	cout << "1. Menambahkan data" << endl;
	cout << "2. Menghapus data" << endl;
	cout << "3. Menampilkan data" << endl;
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
		cout << "Menampilkan data" << endl;
		tampil();
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
