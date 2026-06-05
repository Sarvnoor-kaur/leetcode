class Solution {
public:
    struct State {
        int prev, curr, tight, lead;
        long long cnt, sum;

        State(int p, int c, int t, int l, long long cntVal, long long sumVal)
            : prev(p), curr(c), tight(t), lead(l), cnt(cntVal), sum(sumVal) {}
    };

    long long solve(long long num) {
        if (num < 100) {
            return 0;
        }

        string str = to_string(num);
        int n = str.size();

        vector<State> currStates;
        currStates.emplace_back(10, 10, 1, 1, 1LL, 0LL);

        for (int pos = 0; pos < n; pos++) {
            int limit = str[pos] - '0';

            long long cnt[2][2][11][11] = {};
            long long sum[2][2][11][11] = {};

            for (auto &st : currStates) {
                int maxDigit = (st.tight == 1) ? limit : 9;

                for (int digit = 0; digit <= maxDigit; digit++) {
                    int newLead =
                        (st.lead == 1 && digit == 0) ? 1 : 0;

                    int newPrev = st.curr;
                    int newCurr = (newLead == 1) ? 10 : digit;

                    int newTight =
                        (st.tight == 1 && digit == maxDigit) ? 1 : 0;

                    long long add = 0;

                    if (newLead == 0 &&
                        st.prev != 10 &&
                        st.curr != 10) {

                        if ((st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sum[newTight][newLead][newPrev][newCurr] +=
                        st.sum + add;
                }
            }

            vector<State> nextStates;

            for (int tight = 0; tight < 2; tight++) {
                for (int lead = 0; lead < 2; lead++) {
                    for (int prev = 0; prev <= 10; prev++) {
                        for (int curr = 0; curr <= 10; curr++) {
                            long long c = cnt[tight][lead][prev][curr];
                            long long s = sum[tight][lead][prev][curr];

                            if (c != 0) {
                                nextStates.emplace_back(
                                    prev,
                                    curr,
                                    tight,
                                    lead,
                                    c,
                                    s
                                );
                            }
                        }
                    }
                }
            }

            currStates = move(nextStates);
        }

        long long ans = 0;
        for (auto &st : currStates) {
            ans += st.sum;
        }

        return ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};