#ifndef HASH_H
#define HASH_H

#include <cmath>
#include <iostream>
#include <string>
// You are free to use additional libraries as long as it's not PROHIBITED per
// instruction.

using namespace std;

struct Node {
  string data;
  Node *next;

  // Constructor
  Node(string value, Node *nextNode) : data(value), next(nextNode) {}
};

class HashMap {
private:
  int size;
  Node **map;

public:
  HashMap(int k);
  ~HashMap();
  int hash_function(string text, int k);
  void insert(string text, int k);
  void printFirst5Slots();
  void printSlotLengths();
  float calculateStandardDeviation();
  int getSlotLength(Node *node);
};

#endif
