#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
namespace sort {
    struct stats {
        size_t comparison_count = 0;
        size_t copy_count = 0;
    public:
        void operator+=(const stats& right) {
            this->comparison_count += right.comparison_count;
            this->copy_count += right.copy_count;
        }
        void operator/=(const int& value) {
            this->comparison_count /= value;
            this->copy_count /= value;
        }
    };
    template<class Iterator>
    stats Quicksort(Iterator begin, Iterator end) {

    }
    stats QuickSort(vector<int>& arr, int begin, int end) {
        stats stat;
        if (begin < end) {
            int pivot = arr[(begin + end) / 2];
            int i = begin;
            int j = end;
            while (i <= j) {
                stat.comparison_count++;
                while (arr[i] < pivot) {
                    stat.comparison_count++;
                    i++;
                }
                while (arr[j] > pivot) {
                    stat.comparison_count++;
                    j--;
                }
                if (i <= j) {
                    stat.comparison_count++;
                    std::swap(arr[i], arr[j]);
                    stat.copy_count++;
                    i++;
                    j--;
                }   
            }
            QuickSort(arr, begin, j);
            QuickSort(arr, i, end);
        }
        return stat;
    }
    stats selectionSort(vector<int>& arr) {
        stats stat;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            stat.comparison_count++;
            int min_index = i;
            for (int j = i + 1; j < n; ++j) {
                stat.comparison_count++;
                if (arr[j] < arr[min_index]) {
                    stat.comparison_count++;
                    min_index = j;
                    std::swap(arr[i], arr[min_index]);
                    stat.copy_count++;
                }
            }
        }
        return stat;
    }
    stats merge(vector<int>& arr, int left, int mid, int right) {
        stats stat;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> Leftarr(n1);
        vector<int> Rightarr(n2);

        for (int i = 0; i < n1; i++) {
            stat.comparison_count++;
            Leftarr[i] = arr[left + i];
            stat.copy_count++;
        }
        for (int j = 0; j < n2; j++) {
            stat.comparison_count++;
            Rightarr[j] = arr[mid + 1 + j];
            stat.copy_count++;
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            stat.comparison_count++;
            if (Leftarr[i] <= Rightarr[j]) {
                arr[k] = Leftarr[i];
                i++;
                stat.copy_count++;
            }
            else { 
                arr[k] = Rightarr[j];
                j++;
                stat.copy_count++;
            }
            k++;
            stat.comparison_count++;
        }
        while (i < n1) {
            arr[k] = Leftarr[i];
            i++;
            k++;
            stat.copy_count++;
            stat.comparison_count++;
        }
        while (j < n2) {
            arr[k] = Rightarr[j];
            j++;
            k++;
            stat.copy_count++;
            stat.comparison_count++;
        }
        return stat;
    }

    stats mergeSort(std::vector<int>& arr, int left, int right) {
        stats stat;
        if (left < right) {
            int mid = left + (right - left) / 2;
            stat += mergeSort(arr, left, mid);
            stat +=mergeSort(arr, mid + 1, right);
            stat += merge(arr, left, mid, right);
        }
        return stat;
    }
    void generator_arr(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rand();
        }
    }
    void sort_generator_arr(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = i;
        }
    }
}






