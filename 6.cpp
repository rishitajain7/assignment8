#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    void push(int x){
        heap.push_back(x);
        int i = heap.size() - 1;

        while(i != 0 && heap[i] > heap[(i-1)/2]){
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }}
    void pop(){
        if(heap.empty()){
          return;}

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        while(true){
            int l = 2*i+1, r = 2*i+2, largest = i;

            if(l < heap.size() && heap[l] > heap[largest]) largest = l;
            if(r < heap.size() && heap[r] > heap[largest]) largest = r;

            if(largest != i){
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    int top(){
        return heap.empty() ? -1 : heap[0];
    }
};

int main(){
    MaxHeap pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
 cout<< "Max element: " << pq.top() << endl;
    pq.pop();
   cout << "After pop: " << pq.top();

    return 0;
}
