
# MBBench

MBBench is a worst-case execution time (WCET) benchmark suite. Its main aim is to help WCET research. It is a collection of programs which can be used to compare real-time platforms, WCET tools and techniques. It is spesifically focused on the benchmarking of measurement-based WCET analysis tools and techiques. All programs in the benchmark suite is open source.

## Citing MBBench

The paper of MBBench titled "MBBench: A WCET Benchmark Suite" can be accessed through the link below.

http://saucis.sakarya.edu.tr/en/pub/issue/54022/705777

If you use MBBench in your research, please consider citing.

M. Kuzhan and V. H. Şahin, “MBBench: A WCET Benchmark Suite,” Sakarya University Journal of Computer and Information Sciences, vol. 3, no. 1, pp. 39–49, Apr. 2020, doi: 10.35377/saucis.03.01.705777

```bibtex
@article{MBBench_2020,
	title = {{MBBench}: {A} {WCET} {Benchmark} {Suite}},
	volume = {3},
	issn = {2636-8129},
	shorttitle = {{MBBench}},
	url = {https://dergipark.org.tr/tr/doi/10.35377/saucis.03.01.705777},
	doi = {10.35377/saucis.03.01.705777},
	language = {en},
	number = {1},
	urldate = {2020-05-26},
	journal = {Sakarya University Journal of Computer and Information Sciences},
	author = {Kuzhan, Metin and Şahin, Veysel Harun},
	month = apr,
	year = {2020},
	pages = {39--49},
}
```

## Feature Matrix

### Abbreviations

Single Threaded (ST)  
Multi Threaded (MT)  
External Routine (ER)       
Single Path (SP)  
Multi Path (MP)  
Dynamic Memory Allocation (DMA)  
Loop (L)  
Nested Loop (NL)  
Recursion (R)  
Decision (D)  
Array (A)  
Bit Level Operation (BLO)  
Floating Point Operation (FPO)  
Integer Operation (IO)  
Input Vector (IVEC)  
Input Value (IVAL)  
Input File (IF) 

Table 1. MBBench 1.0 Programs feature matrix for Linux

Program Name | ST | MT|  ER | SP | MP | DMA| L | NL |R | D | A | BLO |  FPO | IO | IVEC | IVAL | IF |
:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
booth_algorithm |+| - |  + | - | + | - | + | - |- | + | + | + |  - | + | + | - | - |
bucket_sort_algorithm |+| - |  + | - | + | - | + | + | - |  + | + | - |- | + | + | - | - |
cesar_algorithm |+| - |  + | - | + | - | + | - | - |+ | + | - |  - | + | + | - | - |
counting_sort_algorithm |+| - | + | - | + | - | + | + |- | + | + | - |  - | + | + | - | - |
gcd |+| - | + | - | + | + | - | + | - | + | - | - | - | + | + | - | - |
huffman_coding_algorithm |+| - |  + | - | + | - | + | + | - | + | + | - | + | + | + | - | - |
0-1_knapsack_algorithm |+| - |  + | - | + | - | + | + |- | + | + | - |  - | + | + | - | - |
merge_sort_algorithm |+| - |  + | - | + | - | + | - | + | + | + | - | - | + | + | - | - |
miller_rabin_primality_test |+| - | + | - | + | - | + | - |- | + | - | - |  - | + | - | + | - |
pollard_rho_algorithm |+| - |  + | - | + | - | + | - |- | - | - | - |  - | + | - | + | - |
quick_sort_algorithm |-| + |  + | - | + | + | + | - |+ | + | + | - |  - | + | - | + | - |
rabin_karp_algorithm |+| - |  + | - | + | - | + | + |- | + | + | - |  - | + | + | - | - |
radix |+| - |  + | - | + | + | + | + |- | + | + | - |  - | + | + | - | - |
rsa_key_generation |+| - |  + | - | + | - | + | - | - | + | - | - | + | + | + | - | - |
standard_deviation |+| - |  + | - | + | - | + | + |- | + | + | - |  - | + | - | - | + |


Table 2. MBBench 1.0 Programs feature matrix for RTEMS

Program Name | ST | MT|  ER | SP | MP | DMA| L | NL |R | D | A | BLO |  FPO | IO | IVEC | IVAL | IF |
:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
booth_algorithm |+| - |  + | + | - | - | + | - |- | + | + | + |  - | + | - | - | - |
bucket_sort_algorithm |+| - |  + | + | - | - | + | + | - |  + | + | - |- | + | - | - | - |
cesar_algorithm |+| - |  + | + | - | - | + | - | - |+ | + | - |  - | + | - | - | - |
counting_sort_algorithm |+| - | + | + | - | - | + | + |- | + | + | - |  - | + | - | - | - |
gcd |+| - | + | + | - | + | - | + | - | + | - | - | - | + | - | - | - |
huffman_coding_algorithm |+| - |  + | + | - | - | + | + | - | + | + | - | + | + | - | - | - |
0-1_knapsack_algorithm |+| - |  + | + | - | - | + | + |- | + | + | - |  - | + | - | - | - |
merge_sort_algorithm |+| - |  + | + | - | - | + | - | + | + | + | - | - | + | - | - | - |
miller_rabin_primality_test |+| - | + | + | - | - | + | - |- | + | - | - |  - | + | - | - | - |
pollard_rho_algorithm |+| - |  + | + | - | - | + | - |- | - | - | - |  - | + | - | - | - |
quick_sort_algorithm |-| + |  + | + | - | + | + | - |+ | + | + | - |  - | + | - | - | - |
rabin_karp_algorithm |+| - |  + | + | - | - | + | + |- | + | + | - |  - | + | - | - | - |
radix |+| - |  + | + | - | + | + | + |- | + | + | - |  - | + | - | - | - |
rsa_key_generation |+| - |  + | +| - | - | + | - | - | + | - | - | + | + | - | - | - |
standard_deviation |+| - |  + | + | - | - | + | + |- | + | + | - |  - | + | - | - | - |



