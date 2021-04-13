#include<bits/stdc++.h>

using namespace std;

int n;
int m;
int req[1000];

list<int>st;

void serve_req(int value){
  list<int> :: iterator it = find(st.begin(), st.end(), value);
  if (it != st.end()){
    st.erase(it);
    st.push_front(value);
  } else {
    if (st.size() >= m){
      st.pop_back();
    } 
    st.push_front(value);
  }
  for (it = st.begin(); it != st.end(); it++){
    cout << *it << " ";
  }
  cout << "\n";
}

int main(){
  cout << "Enter the number of req:\n";
  cin >> n;
  cout << "Enter the req:\n";
  for (int i = 0; i < n; i++){
    cin >> req[i];
  }
  cout << "Enter the number of frame:\n";
  cin >> m;
  for (int i = 0; i < n; i++){
    serve_req(req[i]);
  }    
  return 0;
}