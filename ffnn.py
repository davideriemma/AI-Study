'''
definition of the neural network class
'''

from random import gauss #needed for the default random neuron wheights and biases initialization
import math #needed for the sigmoid function

'''global variables which rapresent the mu and sigma used for default random initialization of the neurons'''
MU = 1.5
SIGMA = 2.4

def sigmoid(x):
  return 1 / (1 + math.exp(-x))

class FFNN_neuron:
    def __init__(self, previous_layer_size):
        self.__weights_and_biases__ = [[0, 0]] * previous_layer_size  # create the list full of zeroes
        # initializes the bias and the weights
        if previous_layer_size != 0:
            for element in self.__weights_and_biases__:
                element[0] = float(gauss(MU, SIGMA))  # initializes the weights
                element[1] = int(gauss(MU, SIGMA))  # initializes the bias

    def print_weights_and_biases(self):
        print("Printing Input Weights and Biases for the current Neuron Status\n")
        i = 0
        for element in self.__weights_and_biases__:
            print(f"[link {i}][weight: {element[0]}, bias: {element[1]}]")
            i += 1

    def __call__(self, list_of_value: list):

        retval = 0 #return value

        if len(self.__weights_and_biases__) == 0: #if this is the first layer (no previous connections)
            retval = list_of_value #return the current list of values
        # compute the weighted sum and calculate the relu function
        else:
            activation_value = 0

            i = 0
            sum = 0
            while i < len(list_of_value):  # len(list_of_value) == len(list_of_bias_and_weights)
                #computes w0*a0 + b0 per ogni elemento della lista
                sum += self.__weights_and_biases__[i][0] * list_of_value[i] + self.__weights_and_biases__[i][1]
                i += 1
            retval = sigmoid(activation_value)

        return retval

class FFNN_Layer:
    def __init__(self, number_of_neurons, previous_layer_size):
        """Initializes the weights and the number"""
        self.__number_of_neurons__ = number_of_neurons
        self.__neurons__ = [FFNN_neuron(previous_layer_size)] * number_of_neurons

    def __int__(self, file_name: str):
        """initialized the neurons in the layer with a configuration from file_name"""
        self.load_layer_config(file_name)

    def get_number_of_neurons(self):
        """return the number of neurons in the network"""
        return self.__number_of_neurons__

    def store_layer_config(self, file_name: str):
        #todo: store the neuron configuration in an xml file
        pass

    def load_layer_config(self, file_name: str):
        #todo: load the neuron configuration in an xml file
        pass

    def __call__(self, input_from_previous_layer):
        """restituisce un array degli activation level di ogni neurone.
        per ogni neurone del livello corrente passa in input tutti i dati ricevuti e salva l'activation
        level ottenuto in un array"""
        activation_values = []  # lista dei valori di attivazione prodotti da quel layer
        i = 1 #neuron counter
        for neuron in self.__neurons__:
            print(f"Activating neuron {i}")
            i += 1
            activation_values.append(
                neuron(input_from_previous_layer))  # create the activation list for the current layer

        return activation_values
