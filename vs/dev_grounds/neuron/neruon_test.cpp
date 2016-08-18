#include <Neuron.h>
#include <iostream>

using namespace std;
using namespace ann;

int main()
{
	float num;
	cout << "Enter a number: ";
	cin >> num;
	
	Neuron n1(SigmoidF);
	n1.setOutput(num);
	
	cout << "Enter another number: ";
	cin >> num;

	Neuron n2;
	n2.setOutput(num);

	vector<Neuron *> n_vec(2);
	n_vec[0] = &n1;
	n_vec[1] = &n2;

	Neuron n3(SigmoidF, n_vec, 0.75f);

	n3.update();

	cout << "Neuron 3 has an output of " << n3.getOutput() << endl;

	n3.setWeights(vector<float>(2, 1.0f));
	n3.update();

	cout << "The new output with weights of 1: " << n3.getOutput() << endl;

	system("pause");

	return 0;
}
	
