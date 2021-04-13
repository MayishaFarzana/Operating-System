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

    int mx = INT_MIN;
    int mi = -1;
    for (int p = 0; p < N; p++){
      if (part[p] > mx){
        mx = part[p];
        mi = p;
      }
    }
    // sobcheye boro partition ache amr kache
    if (part[mi] >= req[r]){
      part[mi] -= req[r];
      for (int i = 0; i < N; i++){
        cout << part[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "Can't serve\n";
      int sum = 0;
      for (int i = 0; i < N; i++){
        sum += part[i];
      }
      cout << "External Fragmentation: " << sum << "\n";
      break;
    }
  }

  return 0;
}
