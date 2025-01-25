#include <iostream>
using namespace std;

int parent[1000];
int size[1000];
int rank[1000];

void make_set(int v) {
  parent[v] = v;
  size[v] = 1;
  rank[v] = 0;
}

int find_set(int v) { // convert to loop
  if (v == parent[v])
    return v;
  return find_set(parent[v]);
}

void union_naive(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b)
    return;
  parent[a] = b;
}

void union_by_size(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b)
    return;
  if (size[a] > size[b]) {
    parent[b] = a;
    size[a] += size[b];
  } else {
    parent[a] = b;
    size[b] += size[a];
  }
}

void union_by_rank(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b)
    return;
  if (rank[a] > rank[b]) {
    parent[b] = a;
  } else if (rank[a] < rank[b]) {
    parent[a] = b;
  } else { // introduce union by size
    parent[b] = a;
    rank[a]++;
  }
}

int main() {

  for (int i = 0; i < 1000; i++)
    parent[i] = -1;

  for (int i = 1; i <= 10; i++) {
    make_set(i);
  }

  return 0;
}