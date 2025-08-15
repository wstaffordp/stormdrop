### StormDrop

---

[![StormDrop](https://repository-images.githubusercontent.com/1038334939/bfbf2473-8fc6-431d-bb26-41131bea9cbc "StormDrop")](https://github.com/wstaffordp/stormdrop/tree/master/src)

---

StormDrop is a huge-period, statistically-strong PRNG that outperforms MRG32k3a, Mersenne Twister, SFMT, TinyMT and WELL. Anyone is free to use it without warranty.

---

#### StormDrop64

`stormdrop64` is a PRNG function that generates a 64-bit, pseudorandom, unsigned integer from 64-bit state integers.

It accepts the following argument.

1. `s` is the `struct stormdrop64_s` pointer that contains the state. Each state integer must be seeded with any `uint64_t` value.

The return value data type is `uint64_t`.

It has an adjustable minimum period of 2²⁵⁶ to 2³²⁷⁶⁸ without broken cycles. Furthermore, a full cycle generates at least 1 of each number from a range of 2⁶⁴ numbers and zeroland escapes quickly after 2 subsequent number generations.

Whenever the state size in `elements` is adjusted, the default `& 511` masks must be adjusted accordingly. `elements` must have a minimum of 4 elements and a maximum of 512 elements as the following table demonstrates. Statistical test result degradation varies as the minimum period decreases.

```
Elements   Minimum     & Mask
Count      2ⁿ Period

4          256         3
8          512         7
16         1024        15
32         2048        31
64         4096        63
128        8192        127
256        16384       255
512        32768       511
```

Up to 2⁶⁴ parallel states each have a non-overlapping cycle of at least 2⁶⁴ numbers by seeding `a` with non-overlapping values, seeding `b` with `a + 1` and seeding `elements` with any combination of overlapping values. The first few generated numbers from each parallel cycle should be skipped to avoid correlations.

In conclusion, StormDrop64 provides enhanced flexibility, parallelism, period, speed and statistical test results as an ideal alternative to all 64-bit variants of Mersenne Twister and other huge-period PRNGs.

---

#### StormDrop32

`stormdrop32` is a PRNG function that generates a 32-bit, pseudorandom, unsigned integer from 32-bit state integers.

It accepts the following argument.

1. `s` is the `struct stormdrop32_s` pointer that contains the state. Each state integer must be seeded with any `uint32_t` value.

The return value data type is `uint32_t`.

It has an adjustable minimum period of 2¹²⁸ to 2³²⁷⁶⁸ without broken cycles. Furthermore, a full cycle generates at least 1 of each number from a range of 2³² numbers and zeroland escapes quickly after 2 subsequent number generations.

Whenever the state size in `elements` is adjusted, the default `& 1023` masks must be adjusted accordingly. `elements` must have a minimum of 4 elements and a maximum of 1024 elements as the following table demonstrates. Statistical test result degradation varies as the minimum period decreases.

```
Elements   Minimum     & Mask
Count      2ⁿ Period

4          128         3
8          256         7
16         512         15
32         1024        31
64         2048        63
128        4096        127
256        8192        255
512        16384       511
1024       32768       1023
```

Up to 2³² parallel states each have a non-overlapping cycle of at least 2³² numbers by seeding `a` with non-overlapping values, seeding `b` with `a + 1` and seeding `elements` with any combination of overlapping values. The first few generated numbers from each parallel cycle should be skipped to avoid correlations.

In conclusion, StormDrop32 provides enhanced flexibility, parallelism, period, speed and statistical test results as an ideal alternative to all 32-bit variants of Mersenne Twister and other huge-period PRNGs.

---

Additional StormDrop variants are coming soon.
