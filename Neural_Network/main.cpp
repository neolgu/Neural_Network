#include <iostream>
#include "NeuralNetwork.h"

void main() {
	//input vector
	VectorND<double> x(2);
	x[0] = x[1] = 0.0;

	//output (Desired outcome)
	VectorND<double> yTarget(1);
	yTarget[0] = 0.3f;

	//output vector
	VectorND<double> yTemp(1);

	NeuralNetwork nn;

	nn.initialize(2, 1, 3);//input num, outputnum, hidden layer num
	nn.alpha = 0.1;//Learning rate

	for (int i = 0; i < 100; i++) {
		nn.setInputVector(x);
		
		nn.forwardProp();

		nn.copyOutputVector(yTemp);

		std::cout << yTemp << std::endl;

		nn.backProp(yTarget);
	}
	//getchar();
}