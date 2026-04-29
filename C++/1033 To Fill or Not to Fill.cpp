#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Station {
    double price, dist;
};

double Cmax, D, Davg;
int N;
vector<Station> sta;
double max_run;

bool cmp_dist(const Station &a, const Station &b) {
    return a.dist < b.dist;
}

bool cmp_price(const Station &a, const Station &b) {
    return a.price < b.price;
}

int main() {
    cin >> Cmax >> D >> Davg >> N;
    for (int i = 0; i < N; i++) {
        double p, d;
        cin >> p >> d;
        sta.push_back({p, d});
    }
    sta.push_back({0.0, D});
    sort(sta.begin(), sta.end(), cmp_dist);
    max_run = Cmax * Davg;
    if (sta[0].dist > 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    for (int i = 0; i < sta.size() - 1; i++) {
        double gap = sta[i+1].dist - sta[i].dist;
        if (gap > max_run) {
            printf("The maximum travel distance = %.2f\n", sta[i].dist + max_run);
            return 0;
        }
    }

    sort(sta.begin(), sta.end(), cmp_price);

    vector<double> cost(D + 1, 0);
    vector<bool> cover(D + 1, false);

    for (auto &s : sta) {
        double p = s.price;
        double pos = s.dist;
        int L = (int)pos;
        int R = (int)min(pos + max_run, (double)D);

        // 覆盖这段没被覆盖的路
        for (int i = L; i < R; i++) {
            if (!cover[i]) {
                cover[i] = true;
                cost[i] = p;
            }
        }
    }

    // 计算总花费
    double total = 0;
    for (int i = 0; i < D; i++) {
        total += cost[i] / Davg;
    }

    printf("%.2f\n", total);
    return 0;
}