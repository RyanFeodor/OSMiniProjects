#include <stdio.h>
struct Sample { char id[6]; char test[20]; int arrival, duration, done; };
int main() {
    struct Sample s[4] = {
        {"S101","Culture Panel",0,45,0},
        {"S102","Glucose Test",1,2,0},
        {"S103","CBC Panel",2,5,0},
        {"S104","Lipid Panel",3,10,0}
    };
    int t = 0, count = 0;
    printf("SJF Lab Queue\n");
    printf("Sample | Test           | Arrival | Duration | Start | End | Waiting\n");
    while (count < 4) {
        int pick = -1;
        for (int i = 0; i < 4; i++)
            if (!s[i].done && s[i].arrival <= t && (pick == -1 || s[i].duration < s[pick].duration))
                pick = i;
        if (pick == -1) { t++; continue; }
        int start = t, end = start + s[pick].duration;
        printf("%-6s | %-14s | %7d | %8d | %5d | %3d | %7d\n",
               s[pick].id, s[pick].test, s[pick].arrival, s[pick].duration, start, end, start - s[pick].arrival);
        t = end; s[pick].done = 1; count++;
    }
    return 0;
}
