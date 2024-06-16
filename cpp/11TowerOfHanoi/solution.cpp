#include <bits/stdc++.h>

using namespace std;

void moveDisc(string source, string destination, int discNum);
void moveDiscs(int noOfDiscs, string source, string destination, string broker);

void moveDisc(string source, string destination, int discNum) {
  cout << "Moving " << discNum << " disk from " << source << " tower to "
       << destination << " tower" << endl;
}

void moveDiscs(int noOfDiscs, string source, string destination,
               string broker) {
  if (noOfDiscs == 1) {
    moveDisc(source, destination, noOfDiscs);
    return;
  }
  moveDiscs(noOfDiscs - 1, source, broker, destination);
  moveDisc(source, destination, noOfDiscs);
  moveDiscs(noOfDiscs - 1, broker, destination, source);
}

int main() {
  moveDiscs(5, "source", "destination", "broker");
  return 0;
}
