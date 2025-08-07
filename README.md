### StormDrop

---

![StormDrop](https://repository-images.githubusercontent.com/1033775498/bb00ce3c-be32-4fcb-94ca-3fc6f1042ff2 "StormDrop")

---

StormDrop is a fast, huge-period, statistically-strong PRNG that outperforms MRG32k3a, Mersenne Twister, SFMT, TinyMT and WELL with enhanced statistical properties, faster generation speeds, flexible state sizes and larger periods.

The license is public domain. Anyone is free to use it for any purpose without restriction. It has no warranty.

---

`stormdrop64` is a PRNG function that generates a 64-bit, pseudorandom, unsigned integer from 64-bit state integers.

It accepts the following argument.

1. `s` is the `struct stormdrop64_s` pointer that contains the state. Each state integer must be seeded with any `uint64_t` value.

The return value data type is `uint64_t`.

It has an adjustable minimum period of 2²⁵⁶ to 2³²⁷⁶⁸ without broken cycles, confirmed by adequately-mixed, equally-distributed state assignments and rigorous black-box testing of various 2³² cycles from StormDrop8 for scaled-down computational feasibility. Furthermore, a full cycle generates at least 1 of each number from a range of 2⁶⁴ numbers and zeroland escapes quickly after 2 subsequent number generations.

Whenever the state size in `elements` is adjusted, the default `& 511` masks must be adjusted accordingly. `elements` must have a minimum of 4 elements and a maximum of 512 elements as the following table demonstrates.

```
Elements   Minimum     & Mask   PractRand
Count      2ⁿ Period            Results

4          256         3        Pending
8          512         7        Pending
16         1024        15       Pending
32         2048        31       Pending
64         4096        63       Pending
128        8192        127      Pending
256        16384       255      Pending
512        32768       511      Pending
```

Up to 2⁶⁴ parallel states each have a non-overlapping cycle of at least 2⁶⁴ numbers by seeding `a` with non-overlapping values, seeding `b` with `a + 1` and seeding `elements` with any combination of overlapping values. The first few generated numbers from each parallel cycle should be skipped to avoid correlations.

The default state with 512 elements passes `stdin64` PractRand tests further than 64-bit Mersenne Twister.

In conclusion, StormDrop64 provides enhanced distribution, flexibility, parallelism, period, speed and statistical test results as an ideal alternative to all 64-bit variants of Mersenne Twister and other huge-period PRNGs.

---

`stormdrop32` is a PRNG function that generates a 32-bit, pseudorandom, unsigned integer from 32-bit state integers.

It accepts the following argument.

1. `s` is the `struct stormdrop32_s` pointer that contains the state. Each state integer must be seeded with any `uint32_t` value.

The return value data type is `uint32_t`.

It has an adjustable minimum period of 2¹²⁸ to 2³²⁷⁶⁸ without broken cycles, confirmed by adequately-mixed, equally-distributed state assignments and rigorous black-box testing of various 2³² cycles from StormDrop8 for scaled-down computational feasibility. Furthermore, a full cycle generates at least 1 of each number from a range of 2³² numbers and zeroland escapes quickly after 2 subsequent number generations.

Whenever the state size in `elements` is adjusted, the default `& 1023` masks must be adjusted accordingly. `elements` must have a minimum of 4 elements and a maximum of 1024 elements as the following table demonstrates.

```
Elements   Minimum     & Mask   PractRand
Count      2ⁿ Period            Results

4          128         3        Pending
8          256         7        Pending
16         512         15       Pending
32         1024        31       Pending
64         2048        63       Pending
128        4096        127      Pending
256        8192        255      Pending
512        16384       511      Pending
1024       32768       1023     Pending
```

Up to 2³² parallel states each have a non-overlapping cycle of at least 2³² numbers by seeding `a` with non-overlapping values, seeding `b` with `a + 1` and seeding `elements` with any combination of overlapping values. The first few generated numbers from each parallel cycle should be skipped to avoid correlations.

The default state with 1024 elements passes `stdin32` PractRand tests further than 32-bit Mersenne Twister.

In conclusion, StormDrop32 provides enhanced distribution, flexibility, parallelism, period, speed and statistical test results as an ideal alternative to all 32-bit variants of Mersenne Twister and other huge-period PRNGs.

---

8-bit and 16-bit variants are coming soon.
