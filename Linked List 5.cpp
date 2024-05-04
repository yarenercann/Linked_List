#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Kullanýcýnýn girdiði sýrada(konumda) bulunan sayýyý ekrana yazdýrýnýz.(Örneðin; 4, 7, 2, 5 olan bir listede sýra:2 girilmiþse sayý:7 olur)

struct Node{
	int data;
	struct Node *sonraki;
};

Node* ilk=NULL;

void Ekle(int veri)
{
	struct Node *yeni=(struct Node*)malloc(sizeof(Node));
	
	yeni->data=veri;
	yeni->sonraki=NULL;
	
	if(ilk==NULL)
	{
		ilk=yeni;
	}
	else
	{
		Node *gecici=ilk;
		while(gecici->sonraki!=NULL)
		{
			gecici=gecici->sonraki;
		}
		gecici->sonraki=yeni;
	}
}

void Konum(int konum)
{
	struct Node *gecici=ilk;
    int sayac=0;
	while(gecici!=NULL)
	{
		sayac++;
		if(sayac==konum)
		{
			printf("Aranan konum: %d  Konumda bulunan sayi: %d",konum,gecici->data);
			return ;
		}
		gecici=gecici->sonraki;
	}	
	printf("Aradiginiz %d. konum listede bulunmamaktadir.",konum);
}


void Listele()
{
	if(ilk==NULL)
	{
		printf("Liste Bos!");
	}
	else
	{
		printf("Liste:\n");
	    Node* gecici=ilk;
		while(gecici!=NULL)
		{
			printf("%d -> ",gecici->data);
			gecici=gecici->sonraki;
		}
		printf("\n");
	}
}


int main()
{
	int konum,veri,n;
	printf("Kac elemanli liste olusturacaksiniz? -->  ");
	scanf("%d",&n);
	printf("Listenin elemanlarini giriniz:\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&veri);
		Ekle(veri);
	}
	Listele();
	
	printf("Aradiginiz konumu belirtiniz: ");
	scanf("%d",&konum);
	Konum(konum);
	
	return 0;
}
