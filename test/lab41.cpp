#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void display_vec(const vector<T>& c){
  for (int i : c) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v;  
  for (size_t i=0; i<10; ++i){
    v.push_back(i);
  }
  std::cout<<"original vector\n";
  display_vec(v);
  v.push_back(10);
  std::cout<<"added element with .pushback(10)\n";
  display_vec(v);
  v.erase(v.begin()+3,v.begin()+8);
  std::cout<<"removed element 3-7\n";
  display_vec(v);
  v.pop_back();
  std::cout<<"poped last element\n";
  display_vec(v);
  v.insert(v.begin(),102);
  v.push_back(110011);
  std::cout<<"added 102 and 110011 to the vector\n";
  display_vec(v);

}
