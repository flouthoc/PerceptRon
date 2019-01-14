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

	/*
	Personality Classifier
	parameter1: height;
	parameter2: wieghts;
	target: bad (0)
			good(1)

	*/


	vector<pair<vector<double>, bool>> trainingset{
		make_pair(vector<double> {6.3,80}, true),
		make_pair(vector<double> {5.4,60}, true),
		make_pair(vector<double> {4.1,60}, false),
		make_pair(vector<double> {6,120}, false),
		make_pair(vector<double> {6,70}, true),
		make_pair(vector<double> {5,70}, true),
		make_pair(vector<double> {3,50}, false),
	};
	per.traintilllearn(trainingset);
	per.printWeights();
	cout<<per.predict(vector<double> {5.5,65})<<endl;
	cout<<per.predict(vector<double> {3.4,90})<<endl;

	
	return 0;
}