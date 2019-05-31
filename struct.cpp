#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Ana Program Baslangıcı */
#define BOYUT 5
struct yigin{
        int top;
        int veri[BOYUT];
       };  
/*** Prototip Tanımlaması Baslangıcı **/      
 
struct yigin  yiginOlustur(struct yigin Yigin);  
struct yigin push(struct yigin Yigin, int eklenecekVeri);  
int isfull(struct yigin Yigin);
struct yigin pop(struct yigin Yigin);
int isEmpty(struct yigin Yigin);
struct yigin yiginKopyala(struct yigin Yigin);
void tumunuGoster(struct yigin Yigin);
void yigitiTersle(struct yigin Yigin);
int yiginElemanAra(struct yigin Yigin, int aranan);
int yiginEnKucuk(struct yigin Yigin);
int yiginEnBuyuk(struct yigin Yigin);
 
 
/*** An program baslangici **/    
int main(void)
{  
 struct yigin s1;
 struct yigin s2;
 int eklenecekSayi;
 s1 = yiginOlustur(s1);
 s2 = yiginOlustur(s2);
 srand(time(NULL));
 while(s1.top<BOYUT-1)
   {
      eklenecekSayi = 1+ rand()%1000;  
      s1=push(s1,eklenecekSayi);          
   }                  
   printf("Yigittaki Butun  elamanları listeleyelim..\n");
   tumunuGoster(s1);
   printf("Kopyaladigimiz Yigittaki  Butun  elamanlari listeleyelim..\n");
   //s2=yiginKopyala(s1);
   //tumunuGoster(s2);
   /**yigitiTersle(s1);
   printf("Simdi Yeni Olustudugumuz  Yigittan  bir eleman cikartalim\n Ve Yigiti Yeniden listeleyelim\n");
   s2=pop(s2);
    tumunuGoster(s2);
    **/
   int enkElaman = yiginEnKucuk(s1);
   int enbElaman = yiginEnBuyuk(s1);
   printf("Yigitta ki en kucuk eleman---> %d \n",enkElaman);
   printf("Yigitta ki en buyuk eleman---> %d \n",enbElaman);
   return 0;
 }
/*** Yeni Bir Yigin Olusturan Fonksiyon **/  
struct yigin  yiginOlustur(struct yigin Yigin){
      Yigin.top=0;
      return Yigin;
     }
/*** Yigin'a Eleman Ekleyecen  Fonksiyon **/        
struct yigin push(struct yigin Yigin, int eklenecekVeri){
       if(isfull(Yigin)==1)
            {
               printf("Yigit Doludur\n");    
               //exit(1);    
            }
       Yigin.top=Yigin.top+1;
       Yigin.veri[Yigin.top]=eklenecekVeri;
       return Yigin;
     }
     
     /*** Yiginda Eleman Cıkartan Fonksiyon **/        
struct yigin pop(struct yigin Yigin){
       if(isEmpty(Yigin)==1)
            {
               printf("Yigit Bos\n");    
               exit(1);    
            }
       Yigin.top=Yigin.top-1;
       return Yigin;
     }
/*** Yigitin Dolu olup olmadığını kontrol eden fonksiyon **/        
int isfull(struct yigin Yigin){
      if(Yigin.top==BOYUT-1)
         return 1;
         else return 0;  
}
 
/*** Yigitin bos olup olmadığını kontrol eden fonksiyon **/
int isEmpty(struct yigin Yigin){
      if(Yigin.top==0)
         return 1;
         else return 0;  
}
 
/*** Bir Yigin'i basşka bir yığına kopyalayan fonksiyon. **/
struct yigin yiginKopyala(struct yigin Yigin){
        struct yigin YeniYigin;
        YeniYigin=yiginOlustur(YeniYigin);
         if(isEmpty(Yigin)==1)
         {
                   printf("Yigin Bos Kopyalama Yapılamaz !");
                   }
        while(Yigin.top>0){
             
             YeniYigin.top+=1;  // Yeni Yiginimiza veri eklicemiz için  gosterdiği değeri arttırdık.
             // Bu deger  yigit bosken sıfırdır.
             YeniYigin.veri[Yigin.top]=Yigin.veri[Yigin.top]; // Diger yigittaki elemani, yeni yigita kopyaladık.
             Yigin.top=Yigin.top-1;     // Eleman ekledikten sonra
           
             // referans olarak gondeerilen yigitin gosterdiği   yeri azalttık.    
         }  
         return YeniYigin;
       }
       
/*** Bir yigitin bütün elemanlarını gösteren fonksiyon **/        
void tumunuGoster(struct yigin Yigin)
{
      if(Yigin.top==0)
          printf("Bos Yigin Listelenemez..");
      while(Yigin.top>0)
       {
           printf("%d. elaman---> %d \n",Yigin.top,Yigin.veri[Yigin.top] );  
            Yigin.top+=-1;          
                        }      
 }
 
/*** Bir Yigiti tersten  listeleyen fonksiyon **/
void yigitiTersle(struct yigin Yigin){
       // Bu fonksiyon yigiti tersten yazdirir.
       int sayac =1;
       while(sayac<=Yigin.top){
            printf("Yigitin Tersten  %d. elemani --> %d \n",sayac,Yigin.veri[sayac]);
            sayac++;          
           }
     }
 /*** Bir fonksiyon yiginda eleman arar varsa o elamnin  yigitta kacinci sirada oldugunu gosterir.
 Eleman yoksa -1 donderir. **/    
int yiginElemanAra(struct yigin Yigin, int aranan){
       int arananSira=-1;
        while(Yigin.top>0)
            {  
                                   
                if(Yigin.veri[Yigin.top]==aranan)
                       {  
                          arananSira=Yigin.top;
                        }
             Yigin.top= Yigin.top-1; // -1 azalttık.  
             }
  return arananSira;  
  }
   
 /*** Yigittaki En Kucuk Elemaninı dondurur. **/      
int yiginEnKucuk(struct yigin Yigin){
    int enKucuk =Yigin.veri[Yigin.top];  
      while(Yigin.top>0)
      {
               if(Yigin.veri[Yigin.top]<enKucuk)
                  {  
                   enKucuk=Yigin.veri[Yigin.top];
                  }
                Yigin.top+=-1;
      }  
    return enKucuk;  
  }
   /*** Yigittaki En büyük Elemaninı dondurur. **/
int yiginEnBuyuk(struct yigin Yigin){
    int enbuyuk =Yigin.veri[Yigin.top];  
      while(Yigin.top>0)
      {
               if(Yigin.veri[Yigin.top]>enbuyuk)
                  {  
                   enbuyuk=Yigin.veri[Yigin.top];
                  }
                Yigin.top+=-1;
      }  
    return enbuyuk;  
  }
