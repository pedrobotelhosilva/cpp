#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>

#define START(x) (x + 1)

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    
    static void mergeInsertSortVector(std::vector<int>& container, int start, int end);
    static void mergeSortVector(std::vector<int>& container, int start, int mid, int end);
    static void insertSortVector(std::vector<int>& container, int start, int end);
    static void mergeInsertSortDeque(std::deque<int>& container, int start, int end);
    static void mergeSortDeque(std::deque<int>& container, int start, int mid, int end);
    static void insertSortDeque(std::deque<int>& container, int start, int end);
    static void runVector(std::vector<int>& container);
    static void runDeque(std::deque<int>& container);
    
    ~PmergeMe();
};

void print(std::vector<int>&, std::deque<int>&);
void calculateTime(std::vector<int>&, std::deque<int>&, double&, double&);
int midPoint(int start, int end);
