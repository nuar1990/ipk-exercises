/*
 * main.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: nuar
 */
#include <iostream>
#include <cmath>

void collatz(int zahl);
bool isPrime(int number);
void printPrimes(int upto);
int pow_iterative(int q, int n);
int pow_recursive(int q, int n);

int main(){
	int zahl=10;
	//std::cin>>zahl;
	collatz(zahl);
	std::cout<<"Ist Zahl Primzahl? (0=Nein) (1=Ja) : "<<isPrime(zahl)<<std::endl;
	std::cout<<"Primzahlen bis: "<<zahl<<"={";
	printPrimes(zahl);
	std::cout<<std::endl;
	int q=12;
	int n=10;
	std::cout<<q<<"^"<<n<<": ";
	std::cout<<pow_iterative(q,n);
	std::cout<<std::endl;
	std::cout<<q<<"^"<<n<<": ";
	std::cout<<pow_recursive(q,n);

	return 0;
}
void collatz(int zahl){
	std::cout<<"Zahl: "<<zahl<<std::endl;

	while(!(zahl==1)&&!(zahl==0)&&!(zahl==-1)&&!(zahl==-5)&&!(zahl==-17)){
		if(zahl% 2==0){
			zahl=zahl/2;
		}
		else{
			zahl=(zahl *3)+1;
		}
		std::cout<<"Zahl: "<<zahl<<std::endl;
	}
}
bool isPrime(int number){
	if(number<=1){
		return false;
	}

	for(int i=2;i<number;i++){
		if(number% i==0){
			return false;
		}
	}
	return true;
}
void printPrimes(int upto){
	if(upto<=1){
		std::cout<<"Keine Primzahlen in der Range"<<std::endl;
	}
	bool isBool=false;
	for(int i=2;i<upto;i++){
		isBool=isPrime(i);
		if(isBool){
			std::cout<<i<<" ";
		}
	}
	std::cout<<"}"<<std::endl;
}
int pow_iterative(int q, int n){
	int product=q;
	if(n%2==0){
		int m=n/2;
		while(m>1){
			product*=q;
			m--;
		}
		product*=product;
		return product;
	}
	while(n>1){
		product*=q;
		n--;
	}
	return product;
}
int pow_recursive(int q, int n){
	if(n==1){
		return q;
	}
	return pow_recursive(q,n-1)*q;
}

