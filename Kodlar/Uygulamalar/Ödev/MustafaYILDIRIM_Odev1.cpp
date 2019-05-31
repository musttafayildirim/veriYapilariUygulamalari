#include <cstdlib>
#include <iostream>
#include <string>
#include <bits/stdc++.h> 

/*
 * Created By MUSTAFA YILDIRIM
 * Date 26.04.2019
 * */

using namespace std;

class MyStack
{
      private :
              int ParantezSayaci,
              ToplamaSayici,
              CikarmaSayici,
              CarpmaSayici,
              BolmeSayici;
              
              int StackElemanSayaci;
              char *KarakterDizisi;
              
              //eleman çıkarma işlemi
              char MyStack_ElemanCikar(){
              StackElemanSayaci--;
              char Gecici=KarakterDizisi[StackElemanSayaci];
              KarakterDizisi[StackElemanSayaci]=' ';           
              return Gecici;
              }
              
      public :
              
              MyStack(int MAX){
              ParantezSayaci=0;
              ToplamaSayici=0;
              CikarmaSayici=0;
              CarpmaSayici=0;
              BolmeSayici=0;
              StackElemanSayaci=0;
              KarakterDizisi=new (nothrow) char[MAX];
              }
              
              //eleman Ekleme işlemi
              void MyStack_ElemanEkle(char GelenKarakter){
              KarakterDizisi[StackElemanSayaci]=GelenKarakter;
              StackElemanSayaci++;  
              }
              
              void OperatorSayisiBul(){
				  
				int MAX=StackElemanSayaci;
              
				for(int i=0; i<MAX; i++){
					char Gecici=MyStack_ElemanCikar();
					if(Gecici=='+'){
						ToplamaSayici++;				
					}
					else if(Gecici=='-'){
						CikarmaSayici++; 						
					}
					else if(Gecici=='*'){
						CarpmaSayici++; 						
					}
					else if(Gecici=='/'){
						BolmeSayici++; 						
					}				
				}
				cout << "Toplama Operatörü: " << ToplamaSayici << " adet. \n";  
				cout << "Çikarma Operatörü: " << CikarmaSayici << " adet. \n";
				cout << "Çarpma Operatörü: " << CarpmaSayici << " adet. \n";
				cout << "Bölme Operatörü: " << BolmeSayici << " adet. \n";
              }
              
              
              int ParantezKontrol(){
				int Bayrak=true;
				int MAX=StackElemanSayaci;
              
				for(int i=0; i<MAX; i++){
					char Gecici=MyStack_ElemanCikar();
					if(Gecici=='('){
						ParantezSayaci++;
					}
					else if(Gecici==')'){
						ParantezSayaci--; 
					}
					if(ParantezSayaci<0){
						Bayrak=false;
						break;
					}
				}  
              
				if(ParantezSayaci!=0){
					Bayrak=false;
				}
				return Bayrak;
              }             
};


             
              
int oncelik(char op){ 
	if(op == '+'||op == '-') 
	return 1; 
	if(op == '*'||op == '/') 
	return 2; 
	return 0; 
} 

int operatorIslem(int a, int b, char op){ 	
	switch(op){ 
		case '+': return a + b; 
		case '-': return a - b; 
		case '*': return a * b; 
		case '/': return a / b; 
	}			
} 
 
int IslemSonuc(string tokens){ 
	int i; 
	
	stack <int> values; 
	
	stack <char> ops; 
	
	for(i = 0; i < tokens.length(); i++){ 
		
		if(tokens[i] == ' ') 
			continue; 
		
		else if(tokens[i] == '('){ 
			ops.push(tokens[i]); 
		} 
		
		else if(isdigit(tokens[i])){ 
			int val = 0; 
			
			while(i < tokens.length() && 
						isdigit(tokens[i])) 
			{ 
				val = (val*10) + (tokens[i]-'0'); 
				i++; 
			} 
			
			values.push(val); 
		} 
		 
		else if(tokens[i] == ')') 
		{ 
			while(!ops.empty() && ops.top() != '(') 
			{ 
				int val2 = values.top(); 
				values.pop(); 
				
				int val1 = values.top(); 
				values.pop(); 
				
				char op = ops.top(); 
				ops.pop(); 
				
				values.push(operatorIslem(val1, val2, op)); 
			} 
			
			ops.pop(); 
		} 
		
		else
		{ 
			while(!ops.empty() && oncelik(ops.top()) 
								>= oncelik(tokens[i])){ 
				int val2 = values.top(); 
				values.pop(); 
				
				int val1 = values.top(); 
				values.pop(); 
				
				char op = ops.top(); 
				ops.pop(); 
				
				values.push(operatorIslem(val1, val2, op)); 
			} 
			
			ops.push(tokens[i]); 
		} 
	} 
	
	while(!ops.empty()){ 
		int val2 = values.top(); 
		values.pop(); 
				
		int val1 = values.top(); 
		values.pop(); 
				
		char op = ops.top(); 
		ops.pop(); 
				
		values.push(operatorIslem(val1, val2, op)); 
	} 
	
	return values.top(); 
} 

int main(int argc, char *argv[])
{
    string Ifade;
    string Ifade2;
    string Ifade3;
    
    cout<<"Her karakter arasında birer boşluk bırakarak bir işlem giriniz..\n";
    cout<< "Mesela ( 5 + 9 ) veya ( 1 - 2 ) + ( 5 * 5 )  gibi....\n";
    getline(cin, Ifade);
    
    Ifade2 = Ifade;
    Ifade3 = Ifade2;
    
    MyStack *YigitYapisi=new MyStack((int)Ifade.length());
    MyStack *YigitYapisi2=new MyStack((int)Ifade2.length());
    
    
    //Operator sayisi
    for(int i=Ifade.length()-1; i>-1; i--){
    
    char Gecici=(char)Ifade[i];

    YigitYapisi->MyStack_ElemanEkle(Gecici);
    
    }
    
    //parantez kontrolü
    for(int i=Ifade2.length()-1; i>-1; i--){
    
    char Gecici=(char)Ifade2[i];

    YigitYapisi2->MyStack_ElemanEkle(Gecici);
    
    }
    YigitYapisi2->OperatorSayisiBul();

	
    if(YigitYapisi->ParantezKontrol()==1){
	cout << IslemSonuc(Ifade3) << "\n"; 
    }
    else 
    {
    cout<<"Girilen matematiksel ifade yanlıştır.\n";
    }
   
    return EXIT_SUCCESS;
}
