#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Tek yönlü bir baðlý listede kullanýcýnýn girdiði konumdaki(sýradaki) sayýyý kullanýcýdan alýnan sayý ile deðiþtiriniz.
//(Örneðin; 4, 7, 2, 5 olan bir listede sýra:2 yeni sayý:1 ise yeni liste:4, 1, 2, 5 olacaktýr)
struct Node{
	int data;
	struct Node *sonraki;
};

Node *ilk=NULL;

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


void Listele()
{
    
    printf("Liste:\n");
	Node *gecici=ilk;
	while(gecici!=NULL){
		printf("%d -> ",gecici->data);
		gecici=gecici->sonraki;
	}	
	printf("\n\n");
} 




void Konum(int konum,int sayi)
{
	Node *gecici=ilk;
	int sayac=0;
	while(gecici!=NULL)
	{
		sayac++;
		if(sayac==konum)
		{
			gecici->data=sayi;
			printf("%d. konumunda bulunan yeni sayi = %d\n",konum,gecici->data);
			return ;
		}
		gecici=gecici->sonraki;
	}
}


void YeniListe()
{
	printf("Yeni liste:\n");
	Node* gecici=ilk;
	
	while(gecici!=NULL)
	{
		printf("%d -> ",gecici->data);
		gecici=gecici->sonraki;
	}
	printf("\n\n");
}



int main()
{
	int konum,n,veri,sayi;
	printf("Kac elemanli liste olusturacaksiniz? -->  ");
	scanf("%d",&n);
	printf("\n");
	printf("Listenin elemanlarini giriniz:\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&veri);
		Ekle(veri);
	}
	printf("\n");
	Listele();
	printf("Aradiginiz konumu belirtiniz: ");
	scanf("%d",&konum);
	printf("\n");
	printf("Konuma eklemek istediginiz sayiyi belirtiniz: ");
	scanf("%d",&sayi);
	printf("\n");
	Konum(konum,sayi);
	printf("\n");
	YeniListe();
	
	return 0;
}
