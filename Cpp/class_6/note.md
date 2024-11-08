# C++ 堆積

## 什麼是堆積？

堆積（Heap）是一種特殊的樹狀數據結構，滿足以下特性：
- 堆積是一棵完全二叉樹。
- 堆積中每個節點的值都大於或等於（最大堆）或小於或等於（最小堆）其子節點的值。

## 堆積的應用

堆積在計算機科學中有多種應用，包括但不限於：
- 優先隊列
- 堆排序
- 圖算法中的最短路徑算法（如Dijkstra算法）

## C++ 中的堆積實現

在C++中，可以使用標準模板庫（STL）中的`priority_queue`來實現堆積。以下是一些基本操作的示例：

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 創建一個最大堆
    std::priority_queue<int> maxHeap;

    // 插入元素
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);

    // 輸出並移除堆頂元素
    std::cout << "Max element: " << maxHeap.top() << std::endl;
    maxHeap.pop();

    // 創建一個最小堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 插入元素
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);

    // 輸出並移除堆頂元素
    std::cout << "Min element: " << minHeap.top() << std::endl;
    minHeap.pop();

    return 0;
}
```

## 堆積操作

### 插入操作

插入操作將新元素添加到堆的末尾，然後通過上浮操作將其移動到正確的位置。

### 刪除操作

刪除操作通常是刪除堆頂元素，然後將最後一個元素移到堆頂，通過下沉操作將其移動到正確的位置。

## 堆積排序

堆積排序是一種基於比較的排序算法，利用堆積的特性來實現排序。其基本思想是：
1. 將數組構建成一個堆。
2. 重複以下操作直到堆變空：
   - 將堆頂元素與堆的最後一個元素交換。
   - 移除堆的最後一個元素。
   - 調整堆以保持堆的性質。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void heapSort(std::vector<int>& arr) {
    // 將數組構建成一個堆
    std::make_heap(arr.begin(), arr.end());

    // 重複移除堆頂元素並調整堆
    for (auto it = arr.end(); it != arr.begin(); --it) {
        std::pop_heap(arr.begin(), it);
    }
}

int main() {
    std::vector<int> arr = {10, 20, 15, 30, 40};

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

以上代碼展示了如何使用C++中的STL函數來實現堆積排序。
