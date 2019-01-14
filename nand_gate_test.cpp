/*
	Author: flouthoc (flouthoc@gmail.com)
	Contributors: 
*/


#include <iostream>
#include <vector>
#include "perceptron.h"

using namespace std;

int main(){

	Perceptron per(2);
	per.printWeights();

	vector<pair<vector<double>, bool>> trainingset{
		make_pair(vector<double> {0,0}, true),
		make_pair(vector<double> {1,0}, true),
		make_pair(vector<double> {0,1}, true),
		make_pair(vector<double> {1,1}, false)
	};
	per.traintilllearn(trainingset);
	per.printWeights();
	cout<<per.predict(vector<double> {1,1})<<endl;
	cout<<per.predict(vector<double> {1,0})<<endl;
	cout<<per.predict(vector<double> {0,1})<<endl;
	cout<<per.predict(vector<double> {0,0})<<endl;
	
	return 0;
}