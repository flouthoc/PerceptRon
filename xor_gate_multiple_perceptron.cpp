/*
	Author: flouthoc (flouthoc@gmail.com)
	Contributors: 
*/


#include <iostream>
#include <vector>
#include "perceptron.h"

using namespace std;

int main(){

	Perceptron per_xor_final(2);
	Perceptron per_or(2);
	Perceptron per_not_and(2);
	//per.printWeights();


	//traning set for per_xor_final;

	vector<pair<vector<double>, bool>> trainingset_and{
		make_pair(vector<double> {0,0}, false),
		make_pair(vector<double> {1,0}, false),
		make_pair(vector<double> {0,1}, false),
		make_pair(vector<double> {1,1}, true)
	};


	//traning set for per_or
	vector<pair<vector<double>, bool>> trainingset_or{
		make_pair(vector<double> {0,0}, false),
		make_pair(vector<double> {1,0}, true),
		make_pair(vector<double> {0,1}, true),
		make_pair(vector<double> {1,1}, true)
	};


	//traning set for per_or
	vector<pair<vector<double>, bool>> trainingset_not_and{
		make_pair(vector<double> {0,0}, true),
		make_pair(vector<double> {1,0}, true),
		make_pair(vector<double> {0,1}, true),
		make_pair(vector<double> {1,1}, false)
	};



	per_xor_final.traintilllearn(trainingset_and);
	per_or.traintilllearn(trainingset_or);
	per_not_and.traintilllearn(trainingset_not_and);
	
	cout<<"Inputs 1 & 1  --->";
	cout<<per_xor_final.predict(vector<double>{per_or.predict(vector<double> {1,1}),
	 per_not_and.predict(vector<double> {1,1})})<<endl;


	cout<<"Inputs 1 & 0  --->";
	cout<<per_xor_final.predict(vector<double>{per_or.predict(vector<double> {1,0}),
	 per_not_and.predict(vector<double> {1,0})})<<endl;

	cout<<"Inputs 0 & 1  --->";
	cout<<per_xor_final.predict(vector<double>{per_or.predict(vector<double> {0,1}),
	 per_not_and.predict(vector<double> {0,1})})<<endl;

	cout<<"Inputs 0 & 0  --->";
	cout<<per_xor_final.predict(vector<double>{per_or.predict(vector<double> {0,0}),
	 per_not_and.predict(vector<double> {0,0})})<<endl;
	
	return 0;
}