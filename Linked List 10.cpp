#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Baðlý listeyi özyinelemeli(recursive) olarak tersten(sondan baþa) yazdýrýnýz.
struct Node {
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
	else
	{
		Node* gecici=ilk;
		while(gecici->sonraki!=NULL)
		{
			gecici=gecici->sonraki;
		}
		gecici->sonraki=yeni;
	}
}


void Listele(struct Node *gecici)
{
	if(ilk==NULL)
	{
		printf("Liste Bos!");
	}
	if(gecici==NULL) 
	{
		return;
	}
	Listele(gecici->sonraki);
	printf("%d -> ",gecici->data);
	
}


int main()
{
	int n,veri;
	printf("Listeniz kac elemanli olacak? -->  ");
	scanf("%d",&n);
	printf("\n");
	printf("Listenin elemanlarini giriniz:\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&veri);
		Ekle(veri);
	}
	printf("\n");
	printf("Listenin ters cevrilmis hali:\n");
	Listele(ilk);
	return 0;
}
