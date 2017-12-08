#include <iostream>
#include "NeuralNetwork.h"

void main() {
	VectorND<double> x(2);
	x[0] = x[1] = 0.0;

	VectorND<double> yTarget(1);
	yTarget[0] = 0.3f;

	VectorND<double> yTemp(1);

	NeuralNetwork nn;

	nn.initialize(2, 1, 3);
	nn.alpha = 0.1;
	printf("Aaaa");
	for (int i = 0; i < 300; i++) {
		nn.setInputVector(x);
		
		nn.propForward();

		nn.copyOutputVector(yTemp);

		std::cout << yTemp << std::endl;

		nn.propBackward(yTarget);
	}
	getchar();
}