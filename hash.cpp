#include "hash.h"
#include <iostream>
#include <string>

using namespace std;

HashMap::HashMap(int k) {
  size = k;
  // array of pointers
  map = new Node *[size];
  for (int i = 0; i < size; ++i) {
    map[i] = nullptr;
  }
}

HashMap::~HashMap() {
  for (int i = 0; i < size; ++i) {
    Node *current = map[i];
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }
  delete[] map;
}

int HashMap::hash_function(string text, int current, int ideal) {
  // Implement your own hash function here
  // cout << (int)tolower(text[0]) << " " << offset << endl;
  // return ((int)tolower(text[0]) - offset) % k;
  return current / ideal;
}

void HashMap::insert(string text, int current, int ideal) {
  int index = hash_function(text, current, ideal);
  Node *newNode = new Node(text, nullptr);

  if (map[index] == nullptr) {
    map[index] = newNode;
  } else {
    Node *current = map[index];
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void HashMap::printFirst5Slots() {
  for (int i = 0; i < min(size, 5); ++i) {
    cout << "Slot " << i << ": ";
    Node *current = map[i];
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
}

void HashMap::printSlotLengths() {
  for (int i = 0; i < size; ++i) {
    cout << "Slot " << i << ": " << (map[i] ? getSlotLength(map[i]) : 0)
         << endl;
  }
}

int HashMap::getSlotLength(Node *node) {
  if (node == nullptr) {
    return 0;
  }
  return 1 + getSlotLength(node->next);
}

float HashMap::calculateStandardDeviation() {
  int sum = 0;
  int count = 0;

  // Calculate the sum of slot lengths
  for (int i = 0; i < size; ++i) {
    sum += map[i] ? getSlotLength(map[i]) : 0;
    count++;
  }

  // Calculate the mean
  float mean = static_cast<float>(sum) / count;

  // Calculate the sum of squared differences from the mean
  float squaredDifferences = 0;
  for (int i = 0; i < size; ++i) {
    squaredDifferences += pow(getSlotLength(map[i]) - mean, 2);
  }

  // Calculate standard deviation
  float standardDeviation = sqrt(squaredDifferences / count);
  return standardDeviation;
}
