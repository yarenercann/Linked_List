#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Kullanýcýdan alýnan 1.sayýyý baðlý listede bulup yine kullanýcýdan alýnan 2.sayý ile deðiþtiriniz.(birden fazla ayný sayýdan varsa tümünü 
//deðiþtirmelidir) (4,7,2,5,4 olan listede aranan:4 yeni sayý:1 ise yeni liste: 1,7,2,5,1)

struct Node{
	int data;
	struct Node *sonraki;
};

Node* ilk=NULL;

void Ekle(int veri)
{
	struct Node* yeni=(struct Node*)malloc(sizeof(Node));
	
	yeni->data=veri;
	yeni->sonraki=NULL;
	
	if(ilk==NULL)
	{
		ilk=yeni;
	}
	else{
		Node* gecici=ilk;
		while(gecici->sonraki!=NULL)
		{
			gecici=gecici->sonraki;
		}
		gecici->sonraki=yeni;
	}
}

void Liste()
{
	printf("Liste:\n");
	Node *gecici=ilk;
	while(gecici!=NULL)
	{
		printf("%d -> ",gecici->data);
	    gecici=gecici->sonraki;
	}
	printf("\n\n");
}


void Degistir(int aranan,int sayi)
{
	Node *gecici=ilk;
	int sayac=0;
	while(gecici!=NULL)
	{
		sayac++;
		if(gecici->data==aranan)
		{
			gecici->data=sayi;
		}
		gecici=gecici->sonraki;
	}
}


void ListeYeni()
{
	printf("Yeni liste:\n");
	Node *gecici=ilk;
	while(gecici!=NULL)
	{
		printf("%d -> ",gecici->data);
		gecici=gecici->sonraki;
	}
	printf("\n\n");
}

int main()
{
	int n,veri,sayi,aranan;
	printf("Listeye kac adet sayi gireceksiniz: ");
	scanf("%d",&n);
	printf("\n");
	printf("Listenin elemanlarini giriniz:\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&veri);
		Ekle(veri);
	}
	printf("\n");
	Liste();
	printf("Listede hangi sayiya erismek istiyorsunuz? --> ");
	scanf("%d",&aranan);
	printf("\n");
	printf("%d sayisi yerine koymak istediginiz sayiyi giriniz: ",aranan);
	scanf("%d",&sayi);
	printf("\n");
	Degistir(aranan,sayi);
	ListeYeni();
	
	return 0;
}

