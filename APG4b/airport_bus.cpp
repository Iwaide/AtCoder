#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> times(N);
  rep(i, N) cin >> times.at(i);
  sort(times.begin(), times.end());
  int passenger = 1;
  int last_time = times.at(0);
  int interval = 0;
  int counter = 0;
  rep2(i, 1, N) {
    if (last_time != 0) {
      interval += times.at(i) - last_time;
      last_time = times.at(i);
    }
    if (interval > K) {
      passenger = 0;
      counter++;
      interval = 0;
      last_time = 0;
    } 
    passenger++;
    last_time = times.at(i);
    if (passenger >= C) {
      passenger = 0;
      counter++;
      interval = 0;
      last_time = 0;
    }
  }
  if (passenger > 0) counter++;
  cout << counter << endl;
}

// まずバスに乗せ、その後乗せられるだけ乗せる
int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> times(N);
  rep(i, N) cin >> times.at(i);
  sort(times.begin(), times.end());
  int counter = 0;
  int i = 0;
  while(i < N) {
    // バスを用意
    counter++;
    int first_arrival = times.at(i);
    int bus_departure = first_arrival + K;
    int passenger = 0;
    while(passenger < C && times[i] <= bus_departure) {
      passenger++;
      i++;
    }
  }
  cout << counter << endl;
}
