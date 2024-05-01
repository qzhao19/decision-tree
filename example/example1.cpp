#include <iostream>
#include "../decision_tree/decision_tree.hpp"

int main() {
    std::vector<std::vector<std::string>> class_labels = {{"setosa", "versicolor", "virginica"}};
    std::vector<std::string> feature_names = {"sepal length (cm)", "sepal width (cm)", "petal length (cm)", "petal width (cm)"};

    std::vector<double> X_train = {5.1, 3.5, 1.4, 0.2,
                            4.9, 3. , 1.4, 0.2,
                            4.7, 3.2, 1.3, 0.2,
                            4.6, 3.1, 1.5, 0.2,
                            5. , 3.6, 1.4, 0.2,
                            5.4, 3.9, 1.7, 0.4,
                            4.6, 3.4, 1.4, 0.3,
                            5. , 3.4, 1.5, 0.2,
                            4.4, 2.9, 1.4, 0.2,
                            4.9, 3.1, 1.5, 0.1,
                            5.4, 3.7, 1.5, 0.2,
                            4.8, 3.4, 1.6, 0.2,
                            4.8, 3. , 1.4, 0.1,
                            4.3, 3. , 1.1, 0.1,
                            5.8, 4. , 1.2, 0.2,
                            5.7, 4.4, 1.5, 0.4,
                            5.4, 3.9, 1.3, 0.4,
                            5.1, 3.5, 1.4, 0.3,
                            5.7, 3.8, 1.7, 0.3,
                            5.1, 3.8, 1.5, 0.3,
                            5.4, 3.4, 1.7, 0.2,
                            5.1, 3.7, 1.5, 0.4,
                            4.6, 3.6, 1. , 0.2,
                            5.1, 3.3, 1.7, 0.5,
                            4.8, 3.4, 1.9, 0.2,
                            5. , 3. , 1.6, 0.2,
                            5. , 3.4, 1.6, 0.4,
                            5.2, 3.5, 1.5, 0.2,
                            5.2, 3.4, 1.4, 0.2,
                            4.7, 3.2, 1.6, 0.2,
                            4.8, 3.1, 1.6, 0.2,
                            5.4, 3.4, 1.5, 0.4,
                            5.2, 4.1, 1.5, 0.1,
                            5.5, 4.2, 1.4, 0.2,
                            4.9, 3.1, 1.5, 0.2,
                            5. , 3.2, 1.2, 0.2,
                            5.5, 3.5, 1.3, 0.2,
                            4.9, 3.6, 1.4, 0.1,
                            4.4, 3. , 1.3, 0.2,
                            5.1, 3.4, 1.5, 0.2,
                            5. , 3.5, 1.3, 0.3,
                            4.5, 2.3, 1.3, 0.3,
                            4.4, 3.2, 1.3, 0.2,
                            5. , 3.5, 1.6, 0.6,
                            5.1, 3.8, 1.9, 0.4,
                            4.8, 3. , 1.4, 0.3,
                            5.1, 3.8, 1.6, 0.2,
                            4.6, 3.2, 1.4, 0.2,
                            5.3, 3.7, 1.5, 0.2,
                            5. , 3.3, 1.4, 0.2,
                            7. , 3.2, 4.7, 1.4,
                            6.4, 3.2, 4.5, 1.5,
                            6.9, 3.1, 4.9, 1.5,
                            5.5, 2.3, 4. , 1.3,
                            6.5, 2.8, 4.6, 1.5,
                            5.7, 2.8, 4.5, 1.3,
                            6.3, 3.3, 4.7, 1.6,
                            4.9, 2.4, 3.3, 1. ,
                            6.6, 2.9, 4.6, 1.3,
                            5.2, 2.7, 3.9, 1.4,
                            5. , 2. , 3.5, 1. ,
                            5.9, 3. , 4.2, 1.5,
                            6. , 2.2, 4. , 1. ,
                            6.1, 2.9, 4.7, 1.4,
                            5.6, 2.9, 3.6, 1.3,
                            6.7, 3.1, 4.4, 1.4,
                            5.6, 3. , 4.5, 1.5,
                            5.8, 2.7, 4.1, 1. ,
                            6.2, 2.2, 4.5, 1.5,
                            5.6, 2.5, 3.9, 1.1,
                            5.9, 3.2, 4.8, 1.8,
                            6.1, 2.8, 4. , 1.3,
                            6.3, 2.5, 4.9, 1.5,
                            6.1, 2.8, 4.7, 1.2,
                            6.4, 2.9, 4.3, 1.3,
                            6.6, 3. , 4.4, 1.4,
                            6.8, 2.8, 4.8, 1.4,
                            6.7, 3. , 5. , 1.7,
                            6. , 2.9, 4.5, 1.5,
                            5.7, 2.6, 3.5, 1. ,
                            5.5, 2.4, 3.8, 1.1,
                            5.5, 2.4, 3.7, 1. ,
                            5.8, 2.7, 3.9, 1.2,
                            6. , 2.7, 5.1, 1.6,
                            5.4, 3. , 4.5, 1.5,
                            6. , 3.4, 4.5, 1.6,
                            6.7, 3.1, 4.7, 1.5,
                            6.3, 2.3, 4.4, 1.3,
                            5.6, 3. , 4.1, 1.3,
                            5.5, 2.5, 4. , 1.3,
                            5.5, 2.6, 4.4, 1.2,
                            6.1, 3. , 4.6, 1.4,
                            5.8, 2.6, 4. , 1.2,
                            5. , 2.3, 3.3, 1. ,
                            5.6, 2.7, 4.2, 1.3,
                            5.7, 3. , 4.2, 1.2,
                            5.7, 2.9, 4.2, 1.3,
                            6.2, 2.9, 4.3, 1.3,
                            5.1, 2.5, 3. , 1.1,
                            5.7, 2.8, 4.1, 1.3,
                            6.3, 3.3, 6. , 2.5,
                            5.8, 2.7, 5.1, 1.9,
                            7.1, 3. , 5.9, 2.1,
                            6.3, 2.9, 5.6, 1.8,
                            6.5, 3. , 5.8, 2.2,
                            7.6, 3. , 6.6, 2.1,
                            4.9, 2.5, 4.5, 1.7,
                            7.3, 2.9, 6.3, 1.8,
                            6.7, 2.5, 5.8, 1.8,
                            7.2, 3.6, 6.1, 2.5,
                            6.5, 3.2, 5.1, 2. ,
                            6.4, 2.7, 5.3, 1.9,
                            6.8, 3. , 5.5, 2.1,
                            5.7, 2.5, 5. , 2. ,
                            5.8, 2.8, 5.1, 2.4,
                            6.4, 3.2, 5.3, 2.3,
                            6.5, 3. , 5.5, 1.8,
                            7.7, 3.8, 6.7, 2.2,
                            7.7, 2.6, 6.9, 2.3,
                            6. , 2.2, 5. , 1.5,
                            6.9, 3.2, 5.7, 2.3,
                            5.6, 2.8, 4.9, 2. ,
                            7.7, 2.8, 6.7, 2. ,
                            6.3, 2.7, 4.9, 1.8,
                            6.7, 3.3, 5.7, 2.1,
                            7.2, 3.2, 6. , 1.8,
                            6.2, 2.8, 4.8, 1.8,
                            6.1, 3. , 4.9, 1.8,
                            6.4, 2.8, 5.6, 2.1,
                            7.2, 3. , 5.8, 1.6,
                            7.4, 2.8, 6.1, 1.9,
                            7.9, 3.8, 6.4, 2. ,
                            6.4, 2.8, 5.6, 2.2,
                            6.3, 2.8, 5.1, 1.5,
                            6.1, 2.6, 5.6, 1.4,
                            7.7, 3. , 6.1, 2.3,
                            6.3, 3.4, 5.6, 2.4,
                            6.4, 3.1, 5.5, 1.8,
                            6. , 3. , 4.8, 1.8,
                            6.9, 3.1, 5.4, 2.1,
                            6.7, 3.1, 5.6, 2.4,
                            6.9, 3.1, 5.1, 2.3,
                            5.8, 2.7, 5.1, 1.9,
                            6.8, 3.2, 5.9, 2.3,
                            6.7, 3.3, 5.7, 2.5,
                            6.7, 3. , 5.2, 2.3,
                            6.3, 2.5, 5. , 1.9,
                            6.5, 3. , 5.2, 2. ,
                            6.2, 3.4, 5.4, 2.3,
                            5.9, 3. , 5.1, 1.8};
    std::vector<long> y_train = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    std::vector<double> X_test = {5.2, 3.3, 1.2, 0.3,
                                4.8, 3.1 , 1.6, 0.2,
                                4.75, 3.1, 1.32, 0.1,
                                5.9, 2.6, 4.1 , 1.2,
                                5.1 , 2.2, 3.3, 1.1,
                                5.2, 2.7, 4.1, 1.3,
                                6.6, 3.1 , 5.25, 2.2,
                                6.3, 2.5, 5.1 , 2.,
                                6.5, 3.1 , 5.2, 2.1};
    std::vector<long> y_test = {0, 0, 0, 1, 1, 1, 2, 2, 2};

    // Hyperparameters
    std::string class_balance  = "balanced";
    int max_depth = 4;
    int max_features = 0;
    int max_thresholds = 0;
    int random_state = 0;

    decisiontree::DecisionTreeClassifier clf(feature_names, class_labels);

    clf.fit(X_train, y_train);

    std::cout << "Predict proda" << std::endl;
    std::vector<double> proba = clf.predict_proba(X_test);

    std::size_t num_classes = class_labels[0].size();
    std::size_t num_samples = y_test.size();
    for (std::size_t i = 0; i < num_samples; ++i) {
        for (std::size_t j = 0; j < num_classes; ++j) {
            std::cout << proba[i * num_classes + j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Predict y" << std::endl;
    std::vector<long> y_pred = clf.predict(X_test);
    for (auto& p : y_pred) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    std::vector<double> f_importances;
    f_importances = clf.compute_feature_importance();
    for (auto& importance : f_importances) {
        std::cout << "importance = " << importance << " ";
    }
    std::cout << std::endl;

    clf.print_node_info();

};
