#include<bits/stdc++.h>

using namespace std;

struct process{
  int id;
  int cpu_time;
  int waiting_time;
  int turnarround_time;
};

int n;   // n is number of process
process ar[100];   // Array of process
int main(){
  cout << "Enter the number of process: ";
  cin >> n;
  cout << "Enter CPU times: ";
  for (int i = 0; i < n; i++){
    cin >> ar[i].cpu_time;
    ar[i].id = i + 1;
  }
  vector<int>time_seq;
  int sum_time = 0;
  time_seq.push_back(sum_time);
  for (int i = 0; i < n; i++){
    sum_time += ar[i].cpu_time;
    time_seq.push_back(sum_time);
    for (int j = i + 1; j < n; j++){
      ar[j].waiting_time += ar[i].cpu_time;
    }
    ar[i].turnarround_time = sum_time;
  }
  cout << "Gantt chart:\n";
  cout << " | ";
  for (int i = 0; i < n; i++){
    cout << "-----p" << ar[i].id << "----- | ";
  }
  cout << "\n";
  for (int i = 0; i < time_seq.size(); i++){
    printf("%.3d            ", time_seq[i]);
  }
  cout << "\n";
  cout << "\t\tWaiting Time\tTurnarround Time\n";  for (int i = 0; i < n; i++){
    cout << "Process " << ar[i].id << ":\t" << ar[i].waiting_time << "\t\t";
    cout << ar[i].turnarround_time << "\n";
  }
  return 0;
}
