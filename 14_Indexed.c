#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 
int used[32];                                   // 0 = free, 1 = allocated 
struct File { string name; int size; } 
files[] = {{"Alice_OS.pdf", 4}, {"Bob_DBMS.docx", 6},     {"Carol_CN.zip", 3}, {"Dave_AI.pdf", 5}, {"Eve_Thesis.pdf", 8}};  
int nextFree() { for (int i = 0; i < 32; i++) if (!used[i]) return i; return -1; } 
int main() {     
for (int b : {0, 1, 4, 5, 9, 10, 14}) used[b] = 1;   // blocks already taken, so free space is scattered     
cout << "SUBMISSION       INDEX_BLK  DATA_BLOCKS (listed inside the index block)\n";     
for (auto &f : files) {         
int freeCnt = 0; for (int u : used) freeCnt += !u;         
if (f.size + 1 > freeCnt) { cout << f.name << "  REJECTED (need " << f.size + 1 << " blocks, only " << freeCnt << " free)\n"; continue; }         
int idx = nextFree(); used[idx] = 1;               // 1 block holds the index table         
vector<int> blocks;         
for (int i = 0; i < f.size; i++) { 
int b = nextFree(); used[b] = 1; blocks.push_back(b); }         
cout << f.name << "  " << idx << "  ->  ";         
for (int b : blocks) cout << b << " ";         
cout << "\n";     } } 
