import ffnn as f
import secrets as s

#create test data
print("Creating test data..")

test_data = []

for i in range(100):
    test_data.append(f.sigmoid(s.randbits(32)))

print("Test data:")
print(test_data)

#create a neural network

layer1 = f.FFNN_Layer(0, 100, 100)
layer2 = f.FFNN_Layer(0, 20, layer1.number_of_neurons())
layer3 = f.FFNN_Layer(0, 2, layer2.number_of_neurons())

print("is there an tree?")
print(layer3(layer2(layer1(test_data)))) #determine if there is a tree

class FFNN_rec_trees:

    def __init__(self):
        self.__layer1__ = f.FFNN_Layer(720*720, 0) #input layer
        self.__layer2__ = f.FFNN_Layer(2000, self.__layer1__.get_number_of_neurons()) #riconosce i tratti elementari
                                                                                      #che compongono un albero (linee
                                                                                      #curve, linee dritte, etc..)
        self.__layer3__ = f.FFNN_Layer(10, self.__layer2__.get_number_of_neurons()) #riconosce la chioma, il tronco, le radici, etc..
        self.__layer4__ = f.FFNN_Layer(2, self.__layer3__.get_number_of_neurons()) #recognises wheather the image shown contains a tree or not