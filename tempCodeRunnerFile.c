#include <stdio.h>

static int sum[19999];

int main(void) {
    long long last[10] = {0}, digits[10] = {0};
    for (int a = 0; a <= 9999; ++a)
        for (int b = 0; b <= 9999; ++b) {
            int s = a + b;
            sum[s]++;
            last[s % 10]++;
            do { digits[s % 10]++; s /= 10; } while (s > 0);
        }

    int best = 0;
    for (int s = 0; s <= 19998; ++s) if (sum[s] > sum[best]) best = s;
    printf("Most common sum: %d (%d times)\n", best, sum[best]);
    printf("Sum 5: %d times, sum 19998: %d times\n\n", sum[5], sum[19998]);

    printf("Last digit of the sum:\n");
    for (int d = 0; d <= 9; ++d) printf("%d: %lld\n", d, last[d]);

    printf("\nAll digits appearing in the sums:\n");
    for (int d = 0; d <= 9; ++d) printf("%d: %lld\n", d, digits[d]);
    return 0;
}