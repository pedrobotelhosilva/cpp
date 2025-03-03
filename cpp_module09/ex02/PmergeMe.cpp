#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other) {
        return (*this);
    }
    return (*this);
}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)(other); }

void PmergeMe::mergeInsertSortVector(std::vector<int>& container, int start, int end) {
    int newEnd;
    if (start < end) {
        if ((end - start) < 10)
            this->insertSortVector(container, start, end);
        else {
            newEnd = start + (end - start) / 2;
            this->mergeInsertSortVector(container, start, newEnd);
            this->mergeInsertSortVector(container, newEnd + 1, end);
            this->mergeSortVector(container, start, newEnd, end);
        }
    }
}

void PmergeMe::mergeSortVector(std::vector<int>& container, int start, int mid, int end) {
    int i, j, k;

    std::vector<int> left(mid - start + 1);
    std::vector<int> right(end - mid);

    for (i = 0; i < (mid - start + 1); ++i)
        left[i] = container[start + i];
    for (j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = start;
    while (i < (mid - start + 1) && j < (end - mid)) {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while (i < (mid - start + 1))
        container[k++] = left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
}

void PmergeMe::insertSortVector(std::vector<int>& container, int start, int end) {
    for (int index = start + 1; index <= end; index++) {
        int hold = container[index];
        int j = index - 1;
        for (; j >= start && container[j] > hold; --j)
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
}

void PmergeMe::runVector(std::vector<int>& container) {
    this->mergeInsertSortVector(container, 0, container.size() - 1);
}

void PmergeMe::runDeque(std::deque<int>& container) {
    this->mergeInsertSortDeque(container, 0, container.size() - 1);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& container, int start, int end) {
    int newEnd;
    if (start < end) {
        if ((end - start) < 10)
            this->insertSortDeque(container, start, end);
        else {
            newEnd = start + (end - start) / 2;
            this->mergeInsertSortDeque(container, start, newEnd);
            this->mergeInsertSortDeque(container, newEnd + 1, end);
            this->mergeSortDeque(container, start, newEnd, end);
        }
    }
}

void PmergeMe::mergeSortDeque(std::deque<int>& container, int start, int mid, int end) {
    int i, j, k;

    std::deque<int> left(mid - start + 1);
    std::deque<int> right(end - mid);

    for (i = 0; i < (mid - start + 1); ++i)
        left[i] = container[start + i];
    for (j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = start;
    while (i < (mid - start + 1) && j < (end - mid)) {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while (i < (mid - start + 1))
        container[k++] = left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
}

void PmergeMe::insertSortDeque(std::deque<int>& container, int start, int end) {
    for (int index = start + 1; index <= end; index++) {
        int hold = container[index];
        int j = index - 1;
        for (; j >= start && container[j] > hold; --j)
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
}

void calculateTime(std::vector<int>& Vcontainer, std::deque<int>& Dcontainer, double& vecTime, double& deqTime) {
    std::clock_t start = std::clock();
    PmergeMe::runVector(Vcontainer);
    std::clock_t end = std::clock();
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
    vecTime = elapsed;
    
    start = std::clock();
    PmergeMe::runDeque(Dcontainer);
    end = std::clock();
    elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
    deqTime = elapsed;
}

void print(std::vector<int>& Vec, std::deque<int>& Deq) {
    static int i = 0;

    if (!i)
        std::cout << "Vector before : ";
    else
        std::cout << "Vector after : ";

    for (auto Vit = Vec.begin(); Vit != Vec.end(); ++Vit)
        std::cout << *Vit << " ";
    std::cout << std::endl;

    if (!i)
        std::cout << "Deque before : ";
    else
        std::cout << "Deque after : ";

    for (auto Dit = Deq.begin(); Dit != Deq.end(); ++Dit)
        std::cout << *Dit << " ";
    std::cout << std::endl;

    i++;
}

int midPoint(int start, int end) {
    return (start + (end - start) / 2);
}
