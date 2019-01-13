#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>

using namespace std;

class Perceptron{


	public:

		int bias;
		double lr;
		vector<double> weights;
		vector<double> traningSet;
		vector<double> inputs;

		Perceptron(int bias, double lr,vector<double>&weights){

			this->bias = bias;
			this->lr = lr;
			this->weights.assign(weights.begin(), weights.end());
		}


		void init(vector<double> inputs){
			
			// First create an instance of an engine.
	    		random_device rnd_device;
			// Specify the engine and distribution.
			mt19937 mersenne_engine {rnd_device()};  // Generates random integers
			uniform_int_distribution<int> dist {1, 52};
			auto gen = [&dist, &mersenne_engine](){return dist(mersenne_engine);};
			
	
			vector<double> weights(inputs.size(), 0);
			generate(begin(weights), end(weights), gen);
			this->weights.assign(weights.begin(), weights.end());
			//this->weights = weights;


		}


		double dt(double actualval, bool target, double inputval, double lr){
			double err = target - actualval;
			return err * lr * inputval;
		}


		void adjustWeights(vector<double> inputs, bool target){

			bool actual = this->evalutate(inputs);
			if(actual == target) return;

				
			for(int i=0; i<this->weights.size(); i++){

				this->weights[i] += this->dt(actual, target, inputs[i], this->lr);
			}


		}

		double weightedSum(){

			double sum = 0;
			for(int i=0; i<this->inputs.size(); i++){
				sum += this->inputs[i]*this->weights[i];
			}
			return sum;


		}

		bool evalutate(vector<double> inputs){
			return this->activate(this->weightedSum());
		}

		bool activate(double value){
			return value >= 0 ? 1:0;
		}
		
};

#endif