// FastFizzBuzz
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
void main(){
	for(int i=1;i<=100;i++){ //1 to 100
		std::string str = "";

		if(i%3==0){ str += "Fizz"; }

		if(i%5==0){ str += "Buzz"; }

		if (str == ""){ //if not applicatble
			cout << i << endl;
		}else{
			cout << str << endl;
		}
	}
	getchar();  //pause
}