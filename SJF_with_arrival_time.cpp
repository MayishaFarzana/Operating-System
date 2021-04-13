

#include<bits/stdc++.h>

using namespace std;

struct process {
  int id;
  int arrival_time;
  int cpu_time;
  int waiting_time;
  int turnarround_time;
  bool operator < (process A)const {
    return A.cpu_time < cpu_time;
  }
};
int n; // Number of process
process ar[100];
priority_queue<process> q;
bool queued[100];  // store the information of a process that is already in ready queue
bool visited[100];  // store the information about a process that is ended
int finished_cnt = 0;  // count of process that are ended
int t = 0;   // times
void check_arrival_time(){
  for (int i = 0; i < n; i++){
    if (queued[ar[i].id] == false && ar[i].arrival_time <= t){
      queued[ar[i].id] = true;
      q.push(ar[i]);
    }
  }
}
vector<int>time_seq;
vector<int>process_seq;
void run_process(){
  if (q.empty()){
    return ;
  }
  process current_process = q.top();  // top process should be executed
  q.pop();
  t += current_process.cpu_time;
  time_seq.push_back(t);
  process_seq.push_back(current_process.id);
  for (int i = 0; i < n; i++){
    if (ar[i].id != current_process.id && visited[ar[i].id] == false){
      ar[i].waiting_time += current_process.cpu_time;
    }
  }
  finished_cnt++;
  visited[current_process.id] = true;
  ar[current_process.id - 1].turnarround_time = t - ar[current_process.id - 1].arrival_time;
}
int main(){
  cout << "Enter the number of process: ";
  cin >> n;
  cout << "Enter the CPU times: ";
  for (int i = 0; i < n; i++){
    cin >> ar[i].cpu_time;
  }
  cout << "Enter the arrival times: ";
  for (int i = 0; i < n; i++){
    cin >> ar[i].arrival_time;
    ar[i].id = i + 1;
  }
  /*
  for (int i = 0; i < n; i++){
    cout << ar[i].id << " " << ar[i].arrival_time << " " << ar[i].cpu_time << "\n";
  }
  */
  time_seq.push_back(0);
  while (finished_cnt < n){
    check_arrival_time();
    run_process();
  }
  cout << "Gantt chart:\n";
  cout << " | ";
  for (int i = 0; i < n; i++){
    cout << "-----p" << process_seq[i] << "----- | ";
  }
  cout << "\n";
  for (int i = 0; i < time_seq.size(); i++){
    printf("%.3d            ", time_seq[i]);
  }
  cout << "\n";
  cout << "\t\tWaiting Time\tTurnarround Time\n";
  for (int i = 0; i < n; i++){
    cout << "Process " << ar[i].id << ":\t" << ar[i].waiting_time - ar[i].arrival_time << "\t\t";
    cout << ar[i].turnarround_time << "\n";
  }
  return 0;
}


