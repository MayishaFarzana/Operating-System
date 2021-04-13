#include<bits/stdc++.h>

using namespace std;
int number_of_process, number_of_resources;
int max_need[100][100], allocation[100][100], need[100][100];
int available[100];
int total_resource[100];

bool visited[100];
int cnt = 0;
vector<int>safe_seq;
bool run_process(){
  int curr = -1;
  for (int i = 1; i <= number_of_process; i++){
    bool all = true;
    if (visited[i] == true){
      continue;
    }
    for (int j = 1; j <= number_of_resources; j++){
      if (need[i][j] > available[j]){
        all = false;
      }
    }
    if (all){
      curr = i;
      visited[i] = true;
      safe_seq.push_back(i);
      for (int r = 1; r <= number_of_resources; r++){
        available[r] += allocation[curr][r];
      }
      return true;
    }
  }
  return false;
}

int main(){
  cout << "Enter the number of process: ";
  cin >> number_of_process;
  cout << "Enter the number of resources: ";
  cin >> number_of_resources;

  for (int i = 1; i <= number_of_process; i++){
    cout << "Process " << i << "\n";
    for (int j = 1; j <= number_of_resources; j++){
      cout << "Maximum value for resource " << j << ": ";
      // take input
      cin >> max_need[i][j];
    }
    for (int j = 1; j <= number_of_resources; j++){
      cout << "Allocated from resource " << j << ": ";
      // take input
      cin >> allocation[i][j];
    }
  }
  for (int i = 1; i <= number_of_resources; i++){
    cout << "Enter total value of resource " << i << ": ";
    // take input
    cin >> total_resource[i];
  }
  for (int i = 1; i <= number_of_resources; i++){
    int sum = 0;
    for (int j = 1; j <= number_of_process; j++){
      sum += allocation[j][i];
    }
    available[i] = total_resource[i] - sum;
  }
  for (int i = 1; i <= number_of_process; i++){
    for (int j = 1; j <= number_of_resources; j++){
      need[i][j] = max_need[i][j] - allocation[i][j];
    }
  }
  while (cnt < number_of_process){
    if (run_process()){
      cnt++;
    }
    else {
      cout << "The system is not it safe state\n";
      return 0;
    }
  }
  cout << "The system is in safe sate\n";
  for (int i = 0; i < safe_seq.size(); i++){
    cout << "P" << safe_seq[i] << " ";
  }
  cout << "is the safe sequence\n";
  return 0;
}
