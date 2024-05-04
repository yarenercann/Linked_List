#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//Listedeki düðüm sayýsýný bulunuz.

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

void Dugum()
{
	Node *gecici=ilk;
	int sayac=0;
	while(gecici!=NULL)
	{
		sayac++;
		gecici=gecici->sonraki;
	}	
	
	printf("Listenin dugum sayisi: %d",sayac);
}

void Listele()
{
    printf("Liste: ");
    Node* gecici=ilk;
	while(gecici!=NULL)
	{
	    printf("%d -> ",gecici->data);
		gecici=gecici->sonraki;	
	}	
	printf("\n");
}


int main()
{
	int veri;
	printf("Liste elemanlarini giriniz:\n");
	for(int i=1;i<=10;i++)
	{
	    scanf("%d",&veri);
        Ekle(veri);
	}
	
	Listele();
	Dugum();
	return 0;
}

