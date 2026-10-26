#include <stdio.h> 
#include <string.h> 
struct { char dname[20], fname[10][20]; int fcnt; } 
dir[10]; 
int dcnt = 0; 
int fd(char *d){for (int i = 0; i < dcnt; i++) if (!strcmp(dir[i].dname, d)) return i; return -1; } 
int ff(int i, char *f) { for (int k = 0; k < dir[i].fcnt; k++) if (!strcmp(dir[i].fname[k], f)) return k; return -1; } 
void create(char *d, char *f) { 
int i = fd(d); 
if (i < 0) printf("Create %s/%s -> FAILED (department not found)\n", d, f); 
else if (ff(i, f) >= 0) printf("Create %s/%s -> FAILED (already exists)\n", d, f); 
else { strcpy(dir[i].fname[dir[i].fcnt++], f); printf("Create %s/%s -> created\n", d, f); } } 
void search(char *d, char *f) { 
int i = fd(d); 
printf("Search %s/%s -> %s\n", d, f, i < 0 ? "department not found" : ff(i, f) >= 0 ? "found" : "file not found"); } 
int main() { 
strcpy(dir[dcnt++].dname, "Cardiology"); 
strcpy(dir[dcnt++].dname, "Neurology"); 
create("Cardiology", "report.pdf"); 
create("Neurology", "report.pdf");   // same name, different dept: OK 
create("Cardiology", "ecg.pdf");    
create("Neurology", "mri.pdf"); 
create("Cardiology", "report.pdf"); 
create("Oncology", "scan.pdf"); 
search("Cardiology", "ecg.pdf");    
search("Neurology", "ecg.pdf"); 
int i = fd("Cardiology"), k = ff(i, "report.pdf"); 
strcpy(dir[i].fname[k], dir[i].fname[--dir[i].fcnt]); 
printf("Delete Cardiology/report.pdf -> deleted\nDisplay:\n"); 
for (i = 0; i < dcnt; i++) { 
printf("%-12s", dir[i].dname); 
for (k = 0; k < dir[i].fcnt; k++) printf(" %s", dir[i].fname[k]); printf("\n"); } } 
