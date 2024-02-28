#include "number_operations.h"
#include <algorithm>
#include <string>

#ifdef _WIN32
#include <cstdlib> // Para system("cls") no Windows
#else
#include <unistd.h> // Para system("clear") em sistemas Unix
#endif




void limparTela() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}


int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


vector<int> divisors(int n){
	vector<int> divs;
	for(int i = 2;i*i<n;i++){
		if(n%i!=0){
			divs.push_back(i);
			if(n/i != i) 
				divs.push_back(n/i);
		}
	}
	return divs;
}
int chosseE(int tot){
    
    vector<int> result = divisors(tot);

   sort(result.begin(), result.end());

    for (int i = 0; i <= result.size(); i++){
        if(gcd(result[i], tot) == 1){
            return result[i]; 
        }

    }
    
    return tot;
}
int calculeD(int e, int tot){
        for (int i = 1; i <= tot; i++){
            if((i * e ) % tot == 1)
                return i;
        }
        
    return e;
}

string decode_word(vector<int> encoded_numbers) {
  string word;
  for (int number : encoded_numbers) {
    char character = static_cast<char>(number);
    word += character;
  }
  return word;
}

vector<int> stringToInt(string message){
    vector<int> form;
    // calling the encrypting function in encoding function
    for (auto& letter : message)
        form.push_back(static_cast<int>(letter));

    return form;
}

