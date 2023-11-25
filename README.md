# Neural_Network
Neural network (FCNN)

## Project
The project is a C++ implementation of FCNN.

The goal is to implement vector operations and FCNN networks using only C++ without external modules.


## Getting Start
### Clone Project
```
git clone https://github.com/neolgu/Neural_Network/
```

### Run main.cpp
1. Enter FCNN network parameters

Enter the input layer, output layer, hidden layer, and learning rate of the network.
```
NeuralNetwork Setup
Enter input) Number of input, Number of output, Number of hidden layer, learning rate
ex) 3 1 1 0.001 (input, output, hidden, lr)
```


2. Data

Enter the data to be used for learning. By default it uses input.txt.

The format of input.txt consists of Num of input and Num of output, and each data is separated by a space bar.

```
// This is sample input.txt (Num of input 3, Num of output 1)
-1.3	-0.2	0	0
-1.5	-0.7	-0.1	1
0.3	-0.7	-0.1	0
-0.1	-0.6	-0.1	0
...
```

3. Train FCNN

The data is successfully entered, network training begins.

```
Studying...
complete
```

4. Test FCNN

The learning is complete, you can test by entering values.

The format is the same as that of input.txt.
```
Enter the input value ) // -0.5 0.7 0.1
```


## Header file
### Arr1D

- A class for basic one-dimensional arrays to be used for input, output, and matrix and vector operations.
- It is responsible for allocating, freeing, and initializing memory and has simple operators overloaded.
  
### Matrix

- Extend Arr1D to a two-dimensional matrix.

### VectorND

- This is a basic data type for use in neural networks.
- All operations on vectors are overloaded.

### NeuralNetwork

- It contains the basic functions of FCNN.
- Activation functions use sigmoid, Relu, and LRelu.
- Forward propagation, backpropagation, and weight update are implemented.
