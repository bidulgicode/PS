#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
size_t partition(vector<T>& data, size_t start, size_t end) {
  const auto& pivot = data[end];
  vector<T> partitioned_data(end - start + 1);

  size_t left = 0;
  size_t right = end - start;
  for (size_t i = start; i <= end; i++) {
    if (data[i] <= pivot) {
      partitioned_data[left++] = data[i];
    } else {
      partitioned_data[right--] = data[i];
    }
  }
  for (size_t i = 0; i <= end - start; i++) {
    data[i + start] = partitioned_data[i];
  }
  return right;
}

template <typename T>
size_t partition2(vector<T>& data, size_t start, size_t end) {
  const auto& pivot = data[end];
  size_t current_small_loc = start;  // 검은색 지시자

  // i 가 빨간색 지시자 역할을 한다.
  for (size_t i = start; i <= end; i++) {
    if (data[i] <= pivot) {
      swap(data[current_small_loc++], data[i]);
    }
  }
  return current_small_loc - 1;
}

int main() {
  vector<int> data = {3, 10, 8, 5, 1, 4, 9, 2, 6, 7};
  cout << "pivot position : " << partition2(data, 0, data.size() - 1) << endl;
  cout << "after partition ---" << endl;
  for (int num : data) {
    cout << num << " ";
  }
}