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