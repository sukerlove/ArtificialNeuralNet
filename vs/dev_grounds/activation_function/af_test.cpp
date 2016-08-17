#include <iostream>
#include <ActivationFunction.h>

using namespace std;
using namespace ann;

int main()
{
	float input;
	cout << "Input: ";
	cin >> input;

	ActivationFunction * af = 0;
	af = FunctionFactory::getActivationFunction(BinaryF);
	cout << "Binary output = " << af->calculate(input) << endl;
	af = FunctionFactory::getActivationFunction(BipolarF);
	cout << "Bipolar output = " << af->calculate(input) << endl;
	af = FunctionFactory::getActivationFunction(LinearF);
	cout << "Linear output = " << af->calculate(input) << endl;
	af = FunctionFactory::getActivationFunction(SigmoidF);
	cout << "Sigmoid output = " << af->calculate(input) << endl;
	system("pause");
	return 0;
}