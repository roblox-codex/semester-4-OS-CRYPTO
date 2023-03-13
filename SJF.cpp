#include <iostream>

using namespace std;

int main()
{
    int n, i, j, k, temp, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
    float avgwt = 0, avgtat = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], p[n], wt[n], tat[n], ct[n], at[n], pr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter the arrival time of process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> bt[i];
        cout << "Enter the priority of process " << i + 1 << ": ";
        cin >> pr[i];
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
                temp3 = pr[i];
                pr[i] = pr[j];
                pr[j] = temp3;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
                temp3 = pr[i];
                pr[i] = pr[j];
                pr[j] = temp3;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            if (at[i] > ct[i - 1])
            {
                ct[i] = at[i] + bt[i];
            }
            else
            {
                ct[i] = ct[i - 1] + bt[i];
            }
        }
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    cout << "Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurn Around Time\tWaiting Time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << p[i] << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << pr[i] << "\t\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }
    cout << "Average waiting time: " << avgwt / n << endl;
    cout << "Average turn around time: " << avgtat / n << endl;
    return 0;
}
