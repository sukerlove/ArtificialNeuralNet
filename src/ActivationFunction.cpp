#include "..\include\ActivationFunction.h"

using namespace ann;

ActivationFunction * FunctionFactory::getActivationFunction(FunctionType type)
{
	switch (type)
	{
	case BinaryF:
		return new Binary;
	case BipolarF:
		return new Bipolar;
	case LinearF:
		return new Linear;
	case SigmoidF:
		return new Sigmoid;
	case Invalid:
		return 0;
	}
	return 0;
}

float Binary::calculate(float input)
{
	if (input >= 0.0f) return 1.0f;
	return 0.0f;
}

float Bipolar::calculate(float input)
{
	if (input >= 0) return 1.0f;
	return -1.0f;
}

float Linear::calculate(float input)
{
	if (input >= 1.0f)
		return 1.0f;
	else if (input <= -1.0f)
		return -1.0f;
	else
		return input;
}

float Sigmoid::calculate(float input)
{
	float denom = 1.0f + expf(-input);
	return 1.0f / denom;
}
