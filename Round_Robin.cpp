#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int cpu_time;
    int arrival_time = 0;
    int cpu_time_left;
    int curr_running_time = 0;
    int waiting_time = 0;
    int turnarround_time = 0;
    bool done = false;
};
int Q;
// Time Quantum
// Variables
int number_of_process;
process ar[1002];
queue<process>q;
int finished = 0;
bool queued[1002];
vector<int>seq;
vector<int>tseq;
void check_without_arrival_time()
{
    for(int i=0; i<number_of_process; i++)
    {
        queued[i]=true;
        q.push(ar[i]);
    }

}
void run_process(int t)
{
    if (q.empty())
    {
        return ;
    }
    if (q.front().cpu_time_left <= 0)
    {
        seq.push_back(q.front().id);
        tseq.push_back(t);
        int temp_id=q.front().id-1;    //ar[0]=p1
        ar[temp_id].turnarround_time = t - q.front().arrival_time;
        ar[temp_id].done = true;
        q.pop();
        finished++;
    }
    if (q.empty())
    {
        return ;
    }
    if (q.front().curr_running_time >=Q)
    {
        seq.push_back(q.front().id);
        tseq.push_back(t);
        q.front().curr_running_time = 0;
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < number_of_process; i++)
    {
        if (ar[i].done == false && q.front().id != ar[i].id && queued[i]) //front id  jodi front e na thake mne process running
        {
            ar[i].waiting_time++;
        }//jodi ses na hy
        //jodi queue r suru te na thake
        //jodi queue te ese thke
    }
    q.front().curr_running_time++;
    q.front().cpu_time_left--;
}
int main()
{
    cout << "Enter the number of process: ";
    cin >> number_of_process;
    cout << "Enter the cpu times\n";
    for (int i = 0; i < number_of_process; i++)
    {
        cin >> ar[i].cpu_time;
        ar[i].cpu_time_left = ar[i].cpu_time;
        ar[i].id = i + 1;
    }
    cout << "Enter quantum time: ";
    cin >> Q;
    tseq.push_back(0);
    //0 theke process start hy
     check_without_arrival_time();
    for (int t = 0; finished < number_of_process; t++)
    {
       // check_arrival_time(t);
        run_process(t);
    }
    for (int i = 0; i < number_of_process; i++)
    {
        q.push(ar[i]);
    }

    cout << " |";
    for (int i = 0; i < (int) seq.size(); i++)
    {
        cout << " ----P" << seq[i] << "---- |";
    }
    cout << '\n';
    for (int i = 0; i < tseq.size(); i++)
    {
        printf("%.3d          ", tseq[i]);
    }
    cout << "\n\n";
    int sumwaiting = 0;
    int sumturnarround = 0;
    for (int i = 0; i < number_of_process; i++)
    {
        sumwaiting += ar[i].waiting_time;
        sumturnarround += ar[i].turnarround_time;
        cout << "Process " << ar[i].id << ": " << "Waiting Time: " << ar[i].waiting_time << " ";
        cout << "Turnaround Time: " << ar[i].turnarround_time << "\n";
    }
    cout << '\n';
    printf("Average Waiting time: %.2f\n", (double)sumwaiting /(double) number_of_process);
    printf("Average Turnaround time: %.2f\n", (double)sumturnarround /(double) number_of_process);
    return 0;
}
