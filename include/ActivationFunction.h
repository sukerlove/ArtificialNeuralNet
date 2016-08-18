#pragma once
#include <math.h>

namespace ann
{
	//List of activation function types
	enum FunctionType
	{
		BinaryF,
		BipolarF,
		LinearF,
		SigmoidF,
		Invalid
	};

	//Virtual base class
	class ActivationFunction
	{
	public:
		virtual float calculate(float input) = 0;
	};

	//Factory class
	class FunctionFactory
	{
	public:
		static ActivationFunction * getActivationFunction(FunctionType type);
	};

	//Implement classes
	class Binary : public ActivationFunction
	{
		float calculate(float input);
	};

	class Bipolar : public ActivationFunction
	{
		float calculate(float input);
	};

	class Linear : public ActivationFunction
	{
		float calculate(float input);
	};

	class Sigmoid : public ActivationFunction
	{
		float calculate(float input);
	};
}