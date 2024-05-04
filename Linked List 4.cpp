#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Kullan�c�dan al�nan bir say�n�n listede ka��nc� s�rada oldu�unu bulunuz.(�rne�in; 4, 7, 2, 5 olan bir listede say�:2 girilmi�se s�ra:3 olur)

struct Node{
	int data;
	struct Node *sonraki;
};

Node *ilk =NULL;

void Ekle(int veri)
{
	struct Node *yeni=(struct Node *)malloc(sizeof(Node));
	
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

void Liste()
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



void Konum(int aranan)
{
	Node *gecici=ilk;
	int sayac=0;
	while(gecici!=NULL)
	{
		sayac++;
		if(gecici->data==aranan)
		{
			printf("%d sayisinin konumu: %d\n",aranan,sayac);
		}
		gecici=gecici->sonraki;
	}
}


int main()
{
	int n,veri,aranan;
	printf("Kac elemanli liste olusturacaksiniz? --> ");
	scanf("%d",&n);
	printf("Listenin elemanlarini giriniz:\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&veri);
		Ekle(veri);
	}
	Liste();
	printf("Listede konumunu ogrenmek istediginiz sayiyi giriniz: ");
	scanf("%d",&aranan);

    Konum(aranan);
	return 0;
}
