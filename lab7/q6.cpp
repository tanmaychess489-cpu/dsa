#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int maxTasks(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int n = tasks.size();
    int m = workers.size();
    int low = 0, high = min(n, m), best = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        multiset<int> ws(workers.begin(), workers.end());
        int pillsLeft = pills;
        bool ok = true;

        for (int i = mid - 1; i >= 0; i--) {
            int need = tasks[i];
            auto it = ws.lower_bound(need);
            if (it != ws.end()) {
                ws.erase(it);
            } else {
                if (pillsLeft == 0) {
                    ok = false;
                    break;
                }
                auto it2 = ws.lower_bound(need - strength);
                if (it2 == ws.end()) {
                    ok = false;
                    break;
                }
                ws.erase(it2);
                pillsLeft--;
            }
        }

        if (ok) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return best;
}

int main() {
    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    cout << maxTasks(tasks, workers, 1, 1) << endl;
    return 0;
}
