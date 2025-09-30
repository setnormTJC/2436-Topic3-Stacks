// Playing with a few standard library containers (data structures)
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// display all tasks
void displayTasks(const deque<string>& tasks) {
    cout << "   ";
    for (const auto& task : tasks) {
        cout << "[" << task << "] ";
    }
    cout << endl << endl;
}

// display all students in map
void displayGrades(const map<string, double>& grades) {
    if (grades.empty()) {
        cout << "   [Empty]" << endl;
    }
    else {
        for (const auto& pair : grades) {
            cout << "   " << setw(15) << left << pair.first
                << " : " << fixed << setprecision(1) << pair.second << endl;
        }
    }
    cout << endl;
}

// display all numbers in set
void displayNumbers(const set<int>& numbers) {
    cout << "   Current numbers in set: ";
    if (numbers.empty()) {
        cout << "[Empty]";
    }
    else {
        cout << "{";
        bool first = true;
        for (const auto& num : numbers) {
            if (!first) cout << ", ";
            cout << num;
            first = false;
        }
        cout << "}";
    }
    cout << " (Size: " << numbers.size() << ")" << endl << endl;
}

int main() {
    //===== DEQUE OPERATIONS =====//
    cout << "===== DEQUE OPERATIONS =====" << endl;

    std::deque<string> taskList;

    // 1. push_back() - add regular tasks at the end
    cout << "1. Adding regular tasks at the end:" << endl;
    taskList.push_back("Regular Task 1");
    cout << "   Added: \"Regular Task 1\" at back" << endl;

    taskList.push_back("Regular Task 2");
    cout << "   Added: \"Regular Task 2\" at back" << endl;

    taskList.push_back("Regular Task 3");
    cout << "   Added: \"Regular Task 3\" at back" << endl;

    displayTasks(taskList);

    // 2. push_front() - add urgent tasks at the front
    cout << "2. Adding urgent tasks at the front:" << endl;
    taskList.push_front("Urgent Task 1");
    cout << "   Added: \"Urgent Task 1\" at front" << endl;

    taskList.push_front("Urgent Task 2");
    cout << "   Added: \"Urgent Task 2\" at front" << endl;

    displayTasks(taskList);

    // 3. pop_front() - complete the first task
    cout << "3. Completing the first task (Urgent Task2):" << endl;
    taskList.pop_front();

    displayTasks(taskList);

    // 4. size() or at() or empty() or clear()
    cout << "4. Checking task count:" << endl;
    cout << "   Total tasks: " << taskList.size() << endl;

    //===== MAP OPERATIONS =====//
    cout << endl << "===== MAP OPERATIONS =====" << endl;

    std::map<string, double> studentGrades;

    // 1. insert() - add student-grade pairs
    cout << "1. Added 4 students to gradebook:" << endl;
    studentGrades.insert({ "Bob", 92.5 });
    studentGrades.insert({ "Tomas", 88.0 });
    studentGrades.insert({ "Katy", 95.3 });
    studentGrades.insert({ "Jonny", 79.8 });
    displayGrades(studentGrades);

    std::vector<int> nums = { 1, 2, 3, 4 };



    // 2. find()
    cout << "2. Finding a student (Tomas):" << endl;
    string searchName = "Tomas";
    auto searchResult = studentGrades.find(searchName);
    if (searchResult != studentGrades.end()) {
        cout << "   Found: " << searchName << " has grade "
            << searchResult->second << endl << endl;
    }
    else {
        cout << "   " << searchName << " not found" << endl << endl;
    }

    // 3. erase()
    cout << "3. Removing a student (Bob):" << endl;
    studentGrades.erase("Bob");
    displayGrades(studentGrades);

    // 4. size()
    cout << "4. Checking gradebook size:" << endl;
    cout << "   Total students: " << studentGrades.size() << endl;

    //===== SET OPERATIONS =====//
    cout << endl << "===== SET OPERATIONS =====" << endl;

    std::set<int> lotteryNumbers;

    // 1. insert() with duplicate
    cout << "1. Insert numbers:" << endl;
    cout << "   Insert 1, 2, 3, 4, 5" << endl;
    lotteryNumbers.insert(1);
    lotteryNumbers.insert(2);
    lotteryNumbers.insert(3);
    lotteryNumbers.insert(4);
    lotteryNumbers.insert(5);

    displayNumbers(lotteryNumbers);

    cout << "   Insert 3 and 5 (duplicate)" << endl;
    lotteryNumbers.insert(3);
    lotteryNumbers.insert(5);

    displayNumbers(lotteryNumbers); // insertion ignored because number 3 and 5 already exists

    // 2. find()
    cout << "2. Finding a number:" << endl;
    int checkNum = 2;
    if (lotteryNumbers.find(checkNum) != lotteryNumbers.end()) {
        cout << "   Number " << checkNum << " EXISTS in the set" << endl;
    }
    else {
        cout << "   Number " << checkNum << " NOT FOUND in the set" << endl;
    }

    checkNum = 10;
    if (lotteryNumbers.find(checkNum) != lotteryNumbers.end()) {
        cout << "   Number " << checkNum << " EXISTS in the set" << endl;
    }
    else {
        cout << "   Number " << checkNum << " NOT FOUND in the set" << endl;
    }
    cout << endl;

    // 3. lower_bound() and upper_bound()
    cout << "3. Range queries:" << endl;
    auto lower = lotteryNumbers.lower_bound(2);
    auto upper = lotteryNumbers.upper_bound(6);
    cout << "   Numbers between 2 and 6: ";
    if (lower != upper) {
        for (auto it = lower; it != upper; ++it) {
            cout << *it << " ";
        }
    }
    else {
        cout << "None";
    }
    cout << endl;

    return 0;
}