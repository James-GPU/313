#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//James Ng CSCI 313 Question 8
template <class add>
class Sum {
public:
    void FindEveryCombination(vector<add> arr, vector<add> answer, vector<vector<add>>& answers, add sum, add addUp, int placement) {
        for (int i = placement; i < arr.size(); i++) {
            answer.push_back(arr[i]);//We add the answer to the vector
            addUp = addUp + arr[i];//Makes addUp add from array so we can see if anything adds up to the sum later on
            if (addUp == sum) {//If we found the combination we are looking for we add it to our vector
                answers.push_back(answer);//We put the correct combination into our vector
            }
            FindEveryCombination(arr, answer, answers, sum, addUp, i + 1);//Recursively repeats to find all combinations
            answer.pop_back();// Gets rid of the last element to prevent a loop
            addUp = addUp - arr[i];//Subtract the element that was removed from the sum.
        }
    }
    vector<vector<add>> StoreEveryCombination(vector<add> arr, add sum) {
        sort(arr.begin(), arr.end());//Sorts the whole array
        vector<add> answer;//This vector stores one out of all the answers 
        vector<vector<add>> answers;//This vector of a vector stores all possible answers from answer
        FindEveryCombination(arr, answer, answers, sum, 0, 0);//Calls private function to find the combination
        return answers;//Returns with all the answers
    }
};
int AskSize() {
    int size = 0;
    cout << "What is the size of the array?" << endl;//Prompts the user for size
    cin >> size;
    while (size == 0 || size < 0) {
        cout << "The input is invalid. Please input a valid size." << endl;//If the output is 0 or a negative, repeat until we get a valid size
        cin >> size;
    }
    return size;
}
int AskSum() {
    int sum = 0;
    cout << "What is the sum?" << endl;//Prompts the user for sum
    cin >> sum;
    return sum;
}
int main() {
    srand(time(nullptr));
    vector<int>arr;//We use vectors since we do not know how many answer we are going to get
    int size = AskSize();//Asks the size from the user
    int random = 0;//This is for random numbers
    for (int i = 0; i < size; i++) {//This loops until we get the size given
        random = (rand() % 100) + 1;//This makes the number between 1 to 100
        arr.push_back(random);//puts the number into the vector
        cout << random << " ";//Prints the numbers so we can confirm they actually exist
    }
    cout << endl;
    Sum<int>combos;//Calls the class so we can use functions and data
    int sum = AskSum();//Asks the user for sum
    vector<vector<int>> answers = combos.StoreEveryCombination(arr, sum);//creates a vector that has all the data so we can access it in main
    auto& TotalAnswer = answers;//Apparently auto& accepts any type of value
    if (answers.empty()) {//If there are no combinations, we end the program
        cout << "Unfortunately there are no possible solutions for " << sum << endl;
        return 0;
    }
    cout << "Here are your possible answers: " << endl;
    for (int i = 0; i < TotalAnswer.size(); i++) {
        vector<int> list = TotalAnswer[i];//We create a vector so we can list the answers
        cout << "{";
        for (int j = 0; j < list.size(); j++) {
            cout << list[j] << " ";
            if (j != (list.size() - 1)) cout << " + "; //This looks out for the end of the answer 
        }
        cout << "} = " <<sum;//I added brackets to make it look neater and it equal to the sum
        cout << endl;
    }
}

