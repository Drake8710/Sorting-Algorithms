// This is a implementation of 3 way partition QuickSort.
#include<bits/stdc++.h>
using namespace std;

pair<int,int> Partition(vector<int> &v1, int l, int r) {
  int i,j;
  if (r - l <= 1) {
     if (v1[r] < v1[l])
        swap(v1[r], v1[l]);
     i = l;
     j = r;
     return make_pair(i, j);
  }
  int mid = l;
  int pivot = v1[r];
  while (mid <= r) {
  if (v1[mid]<pivot)
     swap(v1[l++], v1[mid++]);
     else if (v1[mid]==pivot)
        mid++;
     else if (v1[mid] > pivot)
        swap(v1[mid], v1[r--]);
  }
  i = l-1;
  j = mid;

  return make_pair(i,j);
}

void randomized_quick_sort(vector<int> &v1, int l, int r) {

  if( r <= l)
    return ;
// random number between l and r
  int n = l + (rand() % (r - l));
  // swap with element at l so that our normal partion function works
  swap(v1[l], v1[n]);

  pair<int, int> p1 = Partition(v1, l, r);

  randomized_quick_sort(v1, l, p1.first);
  randomized_quick_sort(v1, p1.second, r);

}

int main() {

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  return 0;
}
