#include <stdio.h>
struct Sample { char id[6]; char test[20]; int arrival, duration; };
int main() {
    struct Sample s[4] = {
        {"S101","Culture Panel",0,45},
        {"S102","Glucose Test",1,2},
        {"S103","CBC Panel",2,5},
        {"S104","Lipid Panel",3,10}
    };
    int t = 0;
    printf("FCFS Lab Queue\n");
    printf("Sample | Test           | Arrival | Duration | Start | End | Waiting\n");
    for (int i = 0; i < 4; i++) {
        int start = (t > s[i].arrival) ? t : s[i].arrival;
        int end = start + s[i].duration;
        printf("%-6s | %-14s | %7d | %8d | %5d | %3d | %7d\n",
               s[i].id, s[i].test, s[i].arrival, s[i].duration, start, end, start - s[i].arrival);
        t = end;
    }
    return 0;
}
