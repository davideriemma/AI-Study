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