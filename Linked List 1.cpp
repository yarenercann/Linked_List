#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//Tam sayýlardan oluþan tek yönlü bir baðlý liste oluþturup kullanýcýdan alýnan sayýlarý listeye ekleyiniz. -1 girildiðinde 
//ise iþlemi sonlandýrýp listeyi yazdýrýnýz

struct Node{
   int data;
   struct Node*sonraki;	
};

Node* ilk=NULL;

void VeriEkle(int veri)
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
		Node *gecici=ilk;
		while( gecici->sonraki != NULL)
		{
			gecici=gecici->sonraki;
		}
		gecici->sonraki=yeni;
		//printf("%d eklendi\n",veri);
	}
}


void Listele()
{
	printf("Liste: ");
	Node *gecici=ilk;
	while(gecici != NULL)
	{
		printf("%d -> ",gecici->data);
		gecici=gecici->sonraki;
	}
	printf("\n");
}


int main()
{
	int veri;
	printf("Listenin elemanlarini giriniz:\n");
	do
	{
	    scanf("%d",&veri);
	    VeriEkle(veri);	
	}while(veri != -1);
	printf("Sayilar bagli listeye eklenmistir.\n");
	Listele();
	
	return 0;
}



