#include<bits/stdc++.h>
using namespace std;

struct Process {
    int p_id;  // process ID
    int at;    // arrival time
    int bt;    // burst time
    int ct;    // completion time
    int wt;    // waiting time
    int tat;   // turn around time
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];

    // Input process details
    for(int i = 0; i < n; i++) {
        cout << endl << "Enter process ID: ";
        cin >> p[i].p_id;
        cout << "Enter the burst time: ";
        cin >> p[i].bt;
        cout << "Enter the arrival time: ";
        cin >> p[i].at;
    }

    // Sorting processes based on arrival time
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (p[j].at > p[j+1].at) {
                swap(p[j], p[j+1]);
            }
        }
    }

    // Calculating completion time
    p[0].ct = p[0].bt + p[0].at;
    for (int i = 1; i < n; i++) {
        p[i].ct = p[i-1].ct + p[i].bt;
    }

    // Calculating waiting time
    p[0].wt = 0;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i].ct - p[i].bt - p[i].at;
    }

    // Calculating turn around time
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
    }

    // Display results
    cout << endl << "P_ID  AT  BT  CT  WT  TAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << p[i].p_id << "    " 
             << p[i].at << "   " 
             << p[i].bt << "   " 
             << p[i].ct << "   " 
             << p[i].wt << "   " 
             << p[i].tat << endl;
    }

    // Calculating average waiting time and turn around time
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_wt /= n;
    avg_tat /= n;

    cout << endl << "Average waiting time: " << avg_wt << endl;
    cout << "Average turn around time: " << avg_tat << endl;

    return 0;
}
