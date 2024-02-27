/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Achintya Jha, Ritwik Aggarwal
Your team alias: AR
*/

#include "hash.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {

  int k = 0;
  int n = 0;
  string texts[500];

  // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT
  // change this part!
  cin >> k;
  string line;
  getline(cin, line);

  while (getline(cin, line)) {
    texts[n] = line;
    n++;
  }

  // WARNING: End of the tokenizer, DO NOT change this part!

  // By this point, k is the # of slots, and n is the # of tokens to fit in
  // texts[] stores the input sequence of tokens/keys to be inserted into your
  // hash table

  // The template is able to be compiled by running
  //   make
  //   ./encoder < inputs/sample_input.txt
  // which puts out the placeholders only.

  // Your time to shine starts now

  // sorting so that all words are always in the same order.
  std::sort(std::begin(texts), std::end(texts));

  // for (int i = 0; i < sizeof(texts) / sizeof(texts[0]); i++) {
  //     if (texts[i]) {
  //   cout << texts[i] << endl;
  //     }
  // }

  // int offset = (int)tolower(texts[0][0]);

  // cout << offset << endl;
  //
  // cout << "++++++++" << endl;

  HashMap hashMap(k);

  int ideal = n / k;

  cout << "ideal: " << ideal << endl;

  // Insert tokens into the hash table
  for (int i = 0; i < n; ++i) {
    hashMap.insert(texts[i], i, ideal);
  }

  cout << "==== Printing the contents of the first 5 slots ====" << endl;
  hashMap.printFirst5Slots();

  cout << "==== Printing the slot lengths ====" << endl;
  hashMap.printSlotLengths();

  cout << "==== Printing the standard variance =====" << endl;
  float standardDeviation = hashMap.calculateStandardDeviation();
  cout << standardDeviation << endl;

  return 0;
}
