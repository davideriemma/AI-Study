'''
definition of the neural network class
'''

from secrets import randbits
import math

def sigmoid(x):
  return 1 / (1 + math.exp(-x))

class FFNN_neuron:
    def __init__(self, previous_layer_size):
        self.__weights__ = [[0, 0]] * previous_layer_size  # create the list full of zeroes
        # initializes the bias and the weights
        for element in self.__weights__:
            element[0] = float(randbits(32))  # initializes the weights
            element[1] = int(randbits(32))  # initializes the bias

    def print_data(self):
        print("Printing Input Weights and Biases for the current Layer Status\n")
        for element in self.__weights__:
            print(f"[weight: {element[0]}, bias: {element[1]}]")

    def __call__(self, list_of_value: list):
        # compute the weighted sum and calculate the relu function
        activation_value = 0

        i = 0
        sum = 0
        while i < len(list_of_value):  # len(list_of_value) == len(list_of_bias_and_weights)
            #computes w0*a0 + b0 per ogni elemento della lista
            sum += self.__weights__[i][0] * list_of_value[i] + self.__weights__[i][1]
            i += 1

        return sigmoid(activation_value)

#TODO: aggiungere un metodo per salvare i dati della rete neurale

class FFNN_Layer:
    def __init__(self, type_of_layer, number_of_neurons, previous_layer_size):
        """Initializes the weights and the number"""
        self.__number_of_neurons__ = number_of_neurons
        self.__neurons__ = [FFNN_neuron(previous_layer_size)] * number_of_neurons

    def number_of_neurons(self):
        return self.__number_of_neurons__

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
