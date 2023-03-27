#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struct to represent a process
struct Process
{
    int id;
    int arrival_time;
    int burst_time;
};

// Function to implement the LJF scheduling algorithm and print a Gantt chart
void ljf(vector<Process> &processes)
{
    // Sort processes by descending order of burst time
    sort(processes.begin(), processes.end(), [](const Process &p1, const Process &p2)
         { return p1.burst_time > p2.burst_time; });

    int n = processes.size();
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_completion_time = 0;

    // Print header for process details table
    cout << endl
         << "Process Details" << endl;
    cout << "+-----+--------------+------------+-----------------+-------------------+---------------------+" << endl;
    cout << "| PID | Arrival Time | Burst Time | Waiting Time (s) | Turnaround Time (s) | Completion Time (s) |" << endl;
    cout << "+-----+--------------+------------+-----------------+-------------------+---------------------+" << endl;

    for (int i = 0; i < n; i++)
    {
        Process &p = processes[i];
        int start_time = max(current_time, p.arrival_time);
        int end_time = start_time + p.burst_time;
        int waiting_time = max(0, start_time - p.arrival_time);
        int turnaround_time = end_time - p.arrival_time;
        int completion_time = end_time;
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;
        total_completion_time += completion_time;
        current_time = end_time;

        // Print process details row
        cout << "| " << setw(3) << p.id << " | " << setw(12) << p.arrival_time << " | " << setw(10) << p.burst_time << " | " << setw(15) << waiting_time << " | " << setw(17) << turnaround_time << " | " << setw(19) << completion_time << " |" << endl;
    }

    // Print footer for process details table
    cout << "+-----+--------------+------------+-----------------+-------------------+---------------------+" << endl;

    double avg_waiting_time = static_cast<double>(total_waiting_time) / n;
    double avg_turnaround_time = static_cast<double>(total_turnaround_time) / n;
    double avg_completion_time = static_cast<double>(total_completion_time) / n;

    // Print average waiting time, turnaround time, and completion time
    cout << "Average waiting time: " << fixed << setprecision(2) << avg_waiting_time << endl;
    cout << "Average turnaround time: " << fixed << setprecision(2) << avg_turnaround_time << endl;
    cout << "Average completion time: " << fixed << setprecision(2) << avg_completion_time << endl;
}


int main()
{
    // Input the number of processes
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    // Input the arrival time and burst time for each process
    vector<Process> processes(n);
    for (int i = 0; i < n; i++)
    {
        Process &p = processes[i];
        p.id = i + 1;
        cout << "Enter the arrival time and burst time for process " << p.id << ": ";
        cin >> p.arrival_time >> p.burst_time;
    }

    // Run the LJF scheduling algorithm and print the Gantt chart
    ljf(processes);

    return 0;
}
