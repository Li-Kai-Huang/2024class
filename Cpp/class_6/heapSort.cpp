#include <bits/stdc++.h>
using namespace std;

// 函數用於堆化以節點 i 為根的子樹，i 是 arr[] 中的索引
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i; // 初始化最大值為根
    int left = 2 * i + 1; // 左子節點 = 2*i + 1
    int right = 2 * i + 2; // 右子節點 = 2*i + 2

    // 如果左子節點大於根
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    // 如果右子節點大於目前的最大值
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    // 如果最大值不是根
    if (largest != i)
    {
        swap(arr[i], arr[largest]); // 交換根與最大值
        heapify(arr, n, largest); // 遞迴堆化受影響的子樹
    }
}

// 主函數進行堆排序
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // 建立堆（重新排列數組）
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    //這邊主要用於由小排到大
    // 一個一個從堆中提取元素
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // 將當前根移到數組末尾
        heapify(arr, i, 0);   // 在縮小的堆上調用最大堆化
    }
}

int main()
{
    vector<int> arr = {26, 5, 77, 1, 61, 4}; // 初始化數組
    heapSort(arr); // 調用堆排序
    cout << "sort:\n"; // 打印排序後的數組
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}