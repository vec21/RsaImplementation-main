#ifndef NUMBER_OPERATIONS_H
#define NUMBER_OPERATIONS_H

#include <vector>
#include <string>

using namespace std;

void limparTela();
int gcd(int a,int b);
vector<int> divisors(int n);
int chosseE(int tot);
int calculeD(int e, int tot);
string decode_word(vector<int> encoded_numbers);
vector<int> stringToInt(string message);

#endif  // NUMBER_OPERATIONS_H
