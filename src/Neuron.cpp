#include "..\include\Neuron.h"

using namespace ann;

Neuron::Neuron()
{
	af = 0;
	af_type = Invalid;
	output = 0.0f;
}

Neuron::Neuron(FunctionType type, std::vector<Neuron *> & neuron_list, float initW)
{
	af = FunctionFactory::getActivationFunction(type);
	af_type = type;
	input_neuron = neuron_list;
	weight = std::vector<float>(neuron_list.size(), initW);
	output = 0.0f;
}

Neuron::Neuron(FunctionType type)
{
	af = FunctionFactory::getActivationFunction(type);
	af_type = type;
	output = 0.0f;
}

Neuron::Neuron(FunctionType type, std::vector<Neuron *> & neuron_list, std::vector<float> weights)
{
	af = FunctionFactory::getActivationFunction(type);
	af_type = type;
	if (neuron_list.size() == weights.size())
	{
		input_neuron = neuron_list;
		weight = weights;
	}
	output = 0.0f;
}

Neuron::Neuron(const Neuron & obj)
{
	af_type = obj.af_type;
	af = FunctionFactory::getActivationFunction(af_type);
	input_neuron = obj.input_neuron;
	weight = obj.weight;
	output = obj.output;
}

Neuron Neuron::operator=(const Neuron & obj)
{
	af_type = obj.af_type;
	af = FunctionFactory::getActivationFunction(af_type);
	input_neuron = obj.input_neuron;
	weight = obj.weight;
	output = obj.output;
	return *this;
}

Neuron::~Neuron()
{
	if (af)
		delete af;
}

void Neuron::addInputNeuron(Neuron * in_neuron, float initW)
{
	input_neuron.push_back(in_neuron);
	weight.push_back(initW);
}

float Neuron::getOutput()
{
	return output;
}

void Neuron::setAfType(FunctionType new_type)
{
	af_type = new_type;
	if (af)
		delete af;
	af = FunctionFactory::getActivationFunction(new_type);
}

void Neuron::update()
{
	float summed = 0.0f;
	for (unsigned int i = 0; i < input_neuron.size(); i++)
	{
		summed += (input_neuron[i]->output) * weight[i];
	}

	if (af)
		output = af->calculate(summed);
}

void Neuron::setOutput(float val)
{
	output = val;
}

FunctionType Neuron::getAfType()
{
	return af_type;
}

std::vector<float> Neuron::getWeights()
{
	return weight;
}

float Neuron::getWeightAt(unsigned int index)
{
	if (index >= weight.size())
		return 0.0f;
	return weight[index];
}

void Neuron::setWeights(std::vector<float> new_weights)
{
	if (new_weights.size() == input_neuron.size())
		weight = new_weights;
}

void Neuron::setWeightAt(unsigned int index, float new_weight)
{
	if (index >= weight.size())
		return;
	weight[index] = new_weight;
}

unsigned int Neuron::numInput()
{
	return input_neuron.size();
}