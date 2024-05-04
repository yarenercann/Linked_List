#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Baðlý listedeki tüm düðümleri siliniz.

struct Node {
	int data;
	struct Node *sonraki;
};

Node *ilk=NULL;

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


void Listele()
{
	if(ilk==NULL)
	{
		printf("Liste Bos!");
	}
	else
	{
		printf("Liste:\n");
		Node *gecici=ilk;
		while(gecici!=NULL)
		{
			printf("%d -> ",gecici->data);
			gecici=gecici->sonraki;
		}
	}
	printf("\n\n");
}



void Sil()
{
	struct Node *silinecek;
	while(ilk!=NULL)
	{
		silinecek=ilk;
		ilk=ilk->sonraki;
		printf("%d silindi.\n",silinecek->data);
		free(silinecek);
	}
	printf("\n");
	printf("Tum elemanlar silindi.\n");
}


int main()
{
	int n,veri;
	printf("Kac elemanli liste olusturacaksiniz? --> ");
	scanf("%d",&n);
	printf("Listenin elemanlarini giriniz:\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&veri);
		Ekle(veri);
	}
	Listele();
	Sil();
	Listele();
	
	return 0;
}

