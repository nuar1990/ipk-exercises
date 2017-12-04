/*
 * Parse_String.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Frank Streicher(nuar)
 */
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>

int parse_int(std::string number);
std::pair<int, int> find_Int(std::string number);
double parse_double(std::string number);
int main(){
	while(1){
		std::string s="47218";
		std::cout<<"Enter a number as string:";
		std::getline(std::cin,s);

		/*
		//(e)
		std::pair<int,int> k=find_Int(s);
		std::cout<<"Eingelesene Zahl:"<<k.first<<" Index of first character that wasn't read: "<<k.second<<std::endl;
		//a-d
		int number=parse_int(s);
		std::cout<<number;
		 */
		double value= parse_double(s);
		std::cout<<"Output: "<<value<<std::endl;
	}
	return 0;
}

std::pair<int, int> find_Int(std::string number){
	int num=0;
	int size= number.size();
	//variable used for determining the value on a certain position depending on it base:
	//e.g. decimal 12_10 = 2*10^0+1*10^1
	int depth=0;
	bool signatureFlag=false;
	bool firstNumberFound=false;
	int lastNumber=0;
	int firstNumber=0;
	bool isNumber=true;

	for (int i=0;i<=size-1;i++){
		if(number[i]>=48 && number[i]<=57){
			firstNumberFound=true;
			lastNumber=i;
		}
		if(firstNumberFound&& (!(number[i]>=48 && number[i]<=57))){
			break;
		}
		if(!firstNumberFound  && number[i]!=32 && number[i]!=43 && number[i]!=45){
			throw std::invalid_argument("String doesn't contain a valid number.");
		}
	}

	for(int i=lastNumber;i>=0;i--){

		//ASCII Space
		if(number[i]==32&&!isNumber){
			isNumber=false;
		}
		if(number[i]==32&&isNumber){
			isNumber=false;
		}
		//ASCII +
		if(number[i]==43&&!isNumber){

			throw std::invalid_argument("String doesn't contain a valid number.");
		}
		if(number[i]==43&&isNumber){
			isNumber=false;
			signatureFlag=false;
			firstNumber=i;
		}
		//ASCII -
		if(number[i]==45&&!isNumber){
			throw std::invalid_argument("String doesn't contain a valid number.");
		}
		if(number[i]==45&&isNumber){
			isNumber=false;
			signatureFlag=true;
			firstNumber=i;
		}
		//ASCII 0-9
		if(number[i]>=48 && number[i]<=57){
			num+=(number[i]-'0')*(pow(10,depth));
			isNumber=true;
			firstNumber=i;
			depth++;
		}
	}
	if(signatureFlag){
		num*=(-1);
	}

	std::pair<int, int> k =std::make_pair(num,lastNumber+1);
	return k;
}

int parse_int(std::string number){
	int num=0;
	int size= number.size();
	//variable depth used for determining the value on a certain position depending on it base:
	//e.g. decimal 12_10 = 2*10^0+1*10^1
	int depth=0;
	bool signatureFlag=false;
	bool firstNumberFound=false;
	int lastNumber=0;
	int firstNumber=0;
	bool isNumber=true;

	for (int i=0;i<=size-1;i++){
		if(number[i]>=48 && number[i]<=57){
			firstNumberFound=true;
			lastNumber=i;
		}
		if(firstNumberFound&& (!(number[i]>=48 && number[i]<=57))){
			break;
		}
		if(!firstNumberFound  && number[i]!=32 && number[i]!=43 && number[i]!=45){
			throw std::invalid_argument("String doesn't contain a valid number.");
		}
	}

	for(int i=lastNumber;i>=0;i--){

		//ASCII Space
		if(number[i]==32&&!isNumber){
			isNumber=false;
		}
		if(number[i]==32&&isNumber){
			isNumber=false;
		}
		//ASCII +
		if(number[i]==43&&!isNumber){

			throw std::invalid_argument("String doesn't contain a valid number.");
		}
		if(number[i]==43&&isNumber){
			isNumber=false;
			signatureFlag=false;
			firstNumber=i;
		}
		//ASCII -
		if(number[i]==45&&!isNumber){
			throw std::invalid_argument("String doesn't contain a valid number.");
		}
		if(number[i]==45&&isNumber){
			isNumber=false;
			signatureFlag=true;
			firstNumber=i;
		}
		//ASCII 0-9
		if(number[i]>=48 && number[i]<=57){
			num+=(number[i]-'0')*(pow(10,depth));
			isNumber=true;
			firstNumber=i;
			depth++;
		}
	}
	if(signatureFlag){
		num*=(-1);
	}

	return num;
}

double parse_double(std::string number){
	double num=0;
	int size= number.size();
	//variable depth used for determining the value on a certain position depending on it base:
	//e.g. decimal 12_10 = 2*10^0+1*10^1
	int depth=0;
	bool signatureFlag=false;
	bool firstNumberFound=false;
	bool decimal=false;
	bool exponent=true;

	int lastNumber=0;
	int decimalPoint=0;
	int expoPoint=0;

	bool isNumber=true;

	for (int i=0;i<=size-1;i++){
		if(number[i]>=48 && number[i]<=57){
			firstNumberFound=true;
			lastNumber=i;
		}
		if(firstNumberFound&& decimal && (!(number[i]>=48 && number[i]<=57))){
			break;
		}
		if(firstNumberFound&&!decimal &&(!(number[i]>=48 && number[i]<=57))&& number[i]!=46){

			break;
		}
		if(!firstNumberFound && number[i]!=32 && number[i]!=43 && number[i]!=45 && number[i]!=46){
			throw std::invalid_argument("String doesn't contain a valid number.");
		}
		if(number[i]==46){
			decimal=true;
			decimalPoint=i;
		}
	}
	//check for exponent
	if(size>lastNumber){
		if(number[lastNumber+1]==101||number[lastNumber+1]==69){
			if(size>lastNumber+1){
				if((number[lastNumber+2]>=48 && number[lastNumber+2]<=57)|| number[lastNumber+2]!=43 || number[lastNumber+2]!=45){
					expoPoint=2;
					exponent=true;
					if(size>lastNumber+2){
						if(number[lastNumber+3]>=48 && number[lastNumber+3]<=57){
							expoPoint=3;
							if(size>lastNumber+3){
								if(number[lastNumber+4]>=48 && number[lastNumber+4]<=57){
									expoPoint=4;
								}
							}
						}
					}
				}
			}
		}
	}

	for(int i=lastNumber;i>=0;i--){

		//ASCII Space
		if(number[i]==32&&!isNumber){
			isNumber=false;
		}
		if(number[i]==32&&isNumber){
			isNumber=false;
		}
		//ASCII +
		if(number[i]==43&&!isNumber){

			throw std::invalid_argument("String doesn't contain a valid number.");
		}
		if(number[i]==43&&isNumber){
			isNumber=false;
			signatureFlag=false;

		}
		//ASCII -
		if(number[i]==45&&!isNumber){
			throw std::invalid_argument("String doesn't contain a valid number.");
		}
		if(number[i]==45&&isNumber){
			isNumber=false;
			signatureFlag=true;
		}
		//ASCII 0-9
		if(number[i]>=48 && number[i]<=57){
			if(decimal){
				if(i>=decimalPoint){
					num+=(number[i]-'0')*(pow(10,-(i-decimalPoint)));
				}
				else{
					num+=(number[i]-'0')*(pow(10,depth));
					depth++;
				}
			}
			else{
				num+=(number[i]-'0')*(pow(10,depth));
				depth++;
			}
			isNumber=true;
		}
	}
	if(signatureFlag){
		num*=(-1);
	}
	if (exponent){
		if(number[lastNumber+2]==45){
			if(expoPoint==3){
				num=num*(pow(10,-number[lastNumber+3]-'0'));
			}
			if(expoPoint==4){
				num=num*(pow(10,(-(number[lastNumber+3]-'0')*10)-(number[lastNumber+4]-'0')));
			}
		}
		if(number[lastNumber+2]==43){
			if(expoPoint==3){
				num=num*(pow(10,number[lastNumber+3]-'0'));
			}
			if(expoPoint==4){
				num=num*(pow(10,(number[lastNumber+3]-'0')*10));
				num=num*(pow(10,(number[lastNumber+4]-'0')));
			}
		}
		if(number[lastNumber+2]!=43&& number[lastNumber+2]!=45){
			if(expoPoint==2){
				num=num*(pow(10,number[lastNumber+2]-'0'));
			}
			if(expoPoint==3){
				num=num*(pow(10,(number[lastNumber+2]-'0')*10));
				num=num*(pow(10,(number[lastNumber+3]-'0')));
			}
		}
	}

	return num;
}
