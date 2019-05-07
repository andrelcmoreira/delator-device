#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

int main()
{
    auto data_set = cv::ml::TrainData::loadFromCSV("train_data.csv", 1, 0, 1);

    data_set->setTrainTestSplitRatio(0.8); // 80 % of dataset for train purpose
    
    cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
    svm->setType(cv::ml::SVM::C_SVC);
    svm->setKernel(cv::ml::SVM::LINEAR);
    svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 100, 
                                          1e-6));
    
    // Setup train data
    cv::Mat train_samples = data_set->getTrainSamples();
    cv::Mat train_responses = data_set->getTrainResponses();
    
    train_responses.convertTo(train_responses, CV_32S);
    svm->train(train_samples, cv::ml::ROW_SAMPLE, train_responses);
    
    // Setup test data 
    cv::Mat test_samples = data_set->getTestSamples();
    cv::Mat test_responses = data_set->getTestResponses();
    cv::Mat results;
    
    svm->predict(test_samples, results);

    float correct = countNonZero(results == test_responses);
    float accuracy = correct / results.total();

    std::cout << "number of samples: " << data_set->getNSamples() << std::endl 
              << "number of train samples: " << data_set->getNTrainSamples()
              << std::endl << "number of test samples: " 
              << data_set->getNTestSamples() << std::endl;  
    
    std::cout << "correct answers: " << correct << "/" 
              << data_set->getNTestSamples() << " | accuracy: " 
              << (100 * accuracy) << " %" << std::endl;

    return 0;
}
