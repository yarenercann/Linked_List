#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//Listedeki sayýlarýn toplamýný ve ortalamasýný bulunuz.

struct Node{
	int data;
	struct Node *sonraki;
};

Node *ilk=NULL;

void Ekle(int veri)
{
	struct Node *yeni=(struct Node*)malloc(sizeof(struct Node));
	yeni->data=veri;
	yeni->sonraki=NULL;
	
	if(ilk==NULL)
	{
		ilk=yeni;
	}
	
	else{
	    Node *gecici=ilk;
		
		while(gecici->sonraki != NULL)
		{
			gecici=gecici->sonraki;
		}
		gecici->sonraki=yeni;
	}
	
}


int Toplam()
{
	struct Node *gecici=ilk;
	int toplam=0;
	float ortalama;
	while(gecici!=NULL)
	{
		toplam+=gecici->data;
		gecici=gecici->sonraki;
	}	
	return toplam;
}

void Ortalama()
{
	struct Node *gecici=ilk;
	int sayac=0;
	float ortalama=0;
	while(gecici!=NULL)
	{
		sayac++;
		ortalama+=gecici->data;
		gecici=gecici->sonraki;
	}
	ortalama/=sayac;
	printf("Listenin ortalamasi: %.2f",ortalama);
}

void Listele()
{
	Node *gecici=ilk;
	printf("Liste: ");
	while(gecici!=NULL)
	{
		printf("%d -> ",gecici->data);
		gecici=gecici->sonraki;
	}
    printf("\n");
}


int main()
{
	int n,veri;
	printf("Listeye kac eleman gireceksiniz: ");
	scanf("%d",&n);
	printf("Listenin elemanlarini giriniz:\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&veri);
		Ekle(veri);
	}
	Listele();
	printf("Listenin toplami: %d\n",Toplam());
	Ortalama();
	return 0;
}

