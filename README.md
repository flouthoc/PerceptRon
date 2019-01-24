# Neural Network01: PerceptRon


Implementation of simplest neuron i.e Rosenblatt Perceptron Model. Following codebase will demonstrate a perceptron of learning basic <strong>logic gates e.g AND , OR, NAND and a simple personality classifier on the bases of height and weight.</strong>

### Please read any of the examples and then dig into perceptron.h.

## Usage
```
g++ -std=c++11 -o <name-of-test> <name-of-test-file>.cpp
./<name-of-test>
```

## Docs
#### Simple example for Boolean OR gate
```c++
#include <iostream>
#include <vector>
#include "perceptron.h"

using namespace std;

int main(){

	Perceptron per(2);
	cout<<"---- Weights before training ----"<<endl;
	per.printWeights();

	vector<pair<vector<double>, bool>> trainingset{
		make_pair(vector<double> {1,0}, true),
		make_pair(vector<double> {0,1}, true),
		make_pair(vector<double> {0,0}, false)
	};
	per.traintilllearn(trainingset);
	cout<<"---- Weights after training ----"<<endl;
	per.printWeights();
	cout<<"----Predicted Outputs----"<<endl;
	cout<<per.predict(vector<double> {1,1})<<endl;
	cout<<per.predict(vector<double> {1,0})<<endl;
	cout<<per.predict(vector<double> {0,1})<<endl;
	cout<<per.predict(vector<double> {0,0})<<endl;
	
	return 0;
}
```

## Theory
### What is a perceptron
Read from here
* https://en.wikipedia.org/wiki/Perceptron
* https://www.cs.toronto.edu/~jlucas/teaching/csc411/lectures/tut5_handout.pdf