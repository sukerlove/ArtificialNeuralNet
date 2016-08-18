#pragma once
#include <vector>
#include "..\include\ActivationFunction.h"

namespace ann
{
	class Neuron
	{
	private:
		ActivationFunction * af;
		std::vector<Neuron *> input_neuron;
		std::vector<float> weight;
		FunctionType af_type;
		float output;

	public:
		Neuron();		//default constructor
		Neuron(FunctionType type, std::vector<Neuron *> & neuron_list, float initW = 0.5f);			//constructor 1
		Neuron(FunctionType type);		//constructor 2
		Neuron(FunctionType type, std::vector<Neuron *> & neuron_list, std::vector<float> weights);
		Neuron(const Neuron & obj);		//copy constructor	
		Neuron operator=(const Neuron & obj);		//assignment overload
		~Neuron();		//destructor

		void addInputNeuron(Neuron * in_neuron, float initW = 0.05f);
		float getOutput();
		void setAfType(FunctionType new_type);
		void update();
		void setOutput(float val);
		FunctionType getAfType();
		std::vector<float> getWeights();
		float getWeightAt(unsigned int index);
		void setWeights(std::vector<float> new_weights);
		void setWeightAt(unsigned int index, float new_weight);
		unsigned int numInput();
	};
}