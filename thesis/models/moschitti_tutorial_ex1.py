from sklearn.datasets import load_svmlight_file
from sklearn import lightsvm

with open('TREC.train', 'r') as f:
    training_data = loader.classification_from_lines(f)

with open('TREC.test', 'r') as f:
    test_data = f.readlines()
    test_data = loader.classification_from_lines(test_data)

# train a model based on the data
model = svmlight.learn(training_data, type='classification', verbosity=4)

# model data can be stored in the same format SVM-Light uses, for
# interoperability with the binaries.
svmlight.write_model(model, 'my_model.dat')

# classify the test data. this function returns a list of numbers, which
# represent the classifications.
predictions = svmlight.classify(model, test_data)
print(predictions)
