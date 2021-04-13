#include<bits/stdc++.h>

using namespace std;

int N, R;
int part[1000];
int req[1000];
int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> part[i];
  }
  cin >> R;
  for (int i = 0; i < R; i++){
    cin >> req[i];
  }
  cout << "Step by step memory allocation situation\n";
  for (int i = 0; i < N; i++){
    cout << part[i] << " ";
  }
  cout << "\n";
  for (int r = 0; r < R; r++){
    // best fit konta?
    int mn = INT_MAX;
    int mi = -1;
    for (int p = 0; p < N; p++){
      if (part[p] >= req[r] && (part[p] - req[r] <= mn)){
        mn = part[p] - req[r];
        mi = p;
      }
    }
    // konta best seta jani (mi te ache);

    if (mi == -1){
      cout << "can't serve\n";
      int sum = 0;
      for (int i = 0; i < N; i++){
        sum += part[i];
      }
      cout << "External Fragmentation: " << sum << '\n';
      break;
    }
    else {
      part[mi] -= req[r];
      for (int i = 0; i < N; i++){
        cout << part[i] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
