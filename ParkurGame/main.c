#include <stdio.h>
#include <stdlib.h>
int Asalmi(int sayi1,int sayi2){
	int i,adet=0;
	for(i=1;i<sayi1;i++){
		if((sayi1%i==0)&&(sayi2%i==0)){
			adet++;
		}
	}
	if(adet>1)return 0;
	else return 1;
}

void MetreAta(int EngelSayisi,int *CikacagiMetre,int parkurUzunlugu){
	int i;
	for(i=0;i<EngelSayisi;i++){
		CikacagiMetre[i]=rand()%parkurUzunlugu-5;
		CikacagiMetre[i]+=5;
	}
}
int main(int argc, char *argv[]) {
	srand(time(0));
	
	int parkurUzunlugu;
	parkurUzunlugu=rand()%50;
	parkurUzunlugu+=50;
	int YasamPuani=100;
	int EngelSayisi=rand()%4;
	EngelSayisi+=2;
	int *CikacagiMetre = malloc(sizeof(int*)*EngelSayisi);
	FILE* logtxt = fopen("log.txt","w");
	MetreAta(EngelSayisi,CikacagiMetre,parkurUzunlugu);
	int kosucu,engel;
	fprintf(logtxt,"Yarisma Basladi!\n");
	for(kosucu=0;kosucu<parkurUzunlugu;kosucu++){
		if(YasamPuani<=0){
			break;
		}
		for(engel=0;engel<EngelSayisi;engel++){
			
			if(kosucu==CikacagiMetre[engel]){
				fprintf(logtxt,"Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",kosucu);
					fprintf(logtxt,"%d. Metrede bir engel var.\n",kosucu);
				if(Asalmi(YasamPuani,kosucu)==1){
					YasamPuani= YasamPuani-kosucu;
					fprintf(logtxt,"%d Ve %d sayilari aralarinda asal.\n",YasamPuani,kosucu);
				}
				else{
					fprintf(logtxt,"%d Ve %d sayilari aralarinda asal degil.\n",YasamPuani,kosucu);
				}
				fprintf(logtxt,"Yarismaci Yasam Puani: %d\n",YasamPuani);
			}
		}
	}
	if(YasamPuani>0){
		fprintf(logtxt,"Yarismaci yarismayi basariyla tamamladi! Kalan HP: %d\n",YasamPuani);
	}
	else{
		fprintf(logtxt,"Yarismaci yarismayi basaramadi.");
	}
	fclose(logtxt);
	
	return 0;
}
