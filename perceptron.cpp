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

		Perceptron(int bias=1, double=0.1,vector<int>&weights){

			this.bias = bias;
			this.lr = lr;
			this.weights.assign(weights.begin(), weights.end());
		}


		void init(vector<double> inputs){
			
			// First create an instance of an engine.
	    		random_device rnd_device;
			// Specify the engine and distribution.
			mt19937 mersenne_engine {rnd_device()};  // Generates random integers
			uniform_int_distribution<int> dist {1, 52};
			auto gen = [&dist, &mersenne_engine](){return dist(mersenne_engine);};
			
	
			vector<int> weights(inputs.size(), 0);
			generate(begin(weights), end(weights), gen);
			this.weights = weights;


		}


		double dt(double actualval, double target, double intputval, double lr=this.lr){
			double err = target - actualval;
			return err * lr * inputval;
		}


		void adjustWeights(vector<double> inputs, vector<double> targets){



		}

		double weightedSum(){

			double sum = 0;
			for(int i=0; i<this.inputs.size(); i++){
				sum += this.inputs[i]*this.weights;
			}
			return sum;


		}

		bool evalutate(vector<double> inputs){
			return this.activate(this.weightedSum());
		}

		bool activate(double value){
			return value >= 0 ? 1:0;
		}
		
