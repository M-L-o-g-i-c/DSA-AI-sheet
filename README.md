# DSA-AI-sheet

AI-generated DSA snippet library: difficulty-tiered C++ templates, each pinned to a standard problem and cited to its canonical source.

## How to use this guide

1. **Pick your level** in the [Layout](#layout) table below. Directory names sort in difficulty order: `easy` → `medium` → `tough` → `unhinged`.
2. **Open a topic directory.** Each topic starts with a `*_basic.cpp` ("how it works"), then the topic's standard variants — own implementation vs `*_stl` (stdlib), recursive vs iterative, fixed vs variable window, and so on.
3. **Read the header block first.** Every file starts with:
   - `// <file>: <what the code does>`
   - `// topic: <tier>/<topic> — <variant>`
   - `// problem:` the standard problem the snippet solves (LeetCode id, or `demo — …`)
   - `// links:` problem URL(s) — LeetCode files list **both** leetcode.com and leetcode.cn
   - `// reference:` MLA-style citation of the canonical source the implementation follows
4. **Compile and run** any snippet standalone:
   ```bash
   g++ -std=c++17 -O2 -Wall -Wextra path/to/file.cpp -o app
   ./app            # input format is commented inside main()
   ```
   `main()` is input/output plumbing only. The algorithm lives in `class Solution::solve`, LeetCode style — to use it on LeetCode, rename `solve` to the real method name and delete `main()`.

**Naming convention:** `<topic>_<variant>.cpp`. The `*_basic.cpp` file is always the annotated "how it works" version; `*_stl.cpp` files use the C++ standard library; the rest are the classic problem variants.

## Layout

| Tier | Meaning | Topics |
| --- | --- | --- |
| `easy/` | Basic topics | `arrays`, `binary-search`, `linked-lists`, `prefix-sums`, `queue`, `stack`, `strings`, `two-pointers` |
| `medium/` | Harder topics | `sliding-window`, `monotonic-stack`, `monotonic-queue`, `bit-manipulation`, `trees`, `undirected-graphs`, `directed-graphs`, `grids`, `greedy` |
| `tough/` | Hard topics | `backtracking`, `dynamic-programming`, `divide-and-conquer`, `union-find`, `topological-sort`, `string-hashing` |
| `unhinged/` | Competitive programming: segtrees & hard math | `segment-trees`, `number-theory`, `combinatorics`, `geometry` |
| `misc/` | Unclassified | — |

The tier names `easy → medium → tough → unhinged` are synonyms for easy / medium / hard / insane, chosen so alphabetical order equals difficulty order.

**Classification rules:** basic single-concept topics go in `easy`; harder topics in `medium`, harder still in `tough`; segment trees and hard-math algorithms in `unhinged`. Composite topics (e.g. `string-hashing` = strings + hashing) are automatically excluded from `easy`.

## Code index

### easy — 40 files

#### `easy/arrays` (6)

| File | What it does | Problem |
| --- | --- | --- |
| `arrays_basic.cpp` | read an array, traverse once, compute min, max and sum | demo |
| `arrays_max_subarray.cpp` | maximum sum of a contiguous subarray (Kadane) | [LC 53](https://leetcode.com/problems/maximum-subarray/) · [CN](https://leetcode.cn/problems/maximum-subarray/) |
| `arrays_remove_duplicates.cpp` | remove duplicates in place from a sorted array | [LC 26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) · [CN](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) |
| `arrays_reverse.cpp` | in-place array reversal with two pointers | demo |
| `arrays_rotate.cpp` | rotate the array to the right by k steps | [LC 189](https://leetcode.com/problems/rotate-array/) · [CN](https://leetcode.cn/problems/rotate-array/) |
| `arrays_two_sum.cpp` | find two indices whose values add up to target (hash map) | [LC 1](https://leetcode.com/problems/two-sum/) · [CN](https://leetcode.cn/problems/two-sum/) |

#### `easy/binary-search` (6)

| File | What it does | Problem |
| --- | --- | --- |
| `binary_search.cpp` | how it works — lo/hi invariant, first-true template | demo |
| `binary_search_array.cpp` | classic binary search on a sorted array | [LC 704](https://leetcode.com/problems/binary-search/) · [CN](https://leetcode.cn/problems/binary-search/) |
| `binary_search_lower_bound.cpp` | own implementation of `std::lower_bound` | demo |
| `binary_search_lower_bound_stl.cpp` | `std::lower_bound` usage | [LC 35](https://leetcode.com/problems/search-insert-position/) · [CN](https://leetcode.cn/problems/search-insert-position/) |
| `binary_search_upper_bound.cpp` | own implementation of `std::upper_bound` | demo |
| `binary_search_upper_bound_stl.cpp` | `std::upper_bound` usage | demo |

#### `easy/linked-lists` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `linked_list_basic.cpp` | ListNode struct, build a list from input, print it | demo |
| `linked_list_cycle.cpp` | detect a cycle with Floyd's tortoise and hare | [LC 141](https://leetcode.com/problems/linked-list-cycle/) · [CN](https://leetcode.cn/problems/linked-list-cycle/) |
| `linked_list_merge_sorted.cpp` | merge two sorted linked lists | [LC 21](https://leetcode.com/problems/merge-two-sorted-lists/) · [CN](https://leetcode.cn/problems/merge-two-sorted-lists/) |
| `linked_list_middle.cpp` | find the middle node with slow/fast pointers | [LC 876](https://leetcode.com/problems/middle-of-the-linked-list/) · [CN](https://leetcode.cn/problems/middle-of-the-linked-list/) |
| `linked_list_reverse.cpp` | reverse a singly linked list iteratively | [LC 206](https://leetcode.com/problems/reverse-linked-list/) · [CN](https://leetcode.cn/problems/reverse-linked-list/) |

#### `easy/prefix-sums` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `prefix_sum_basic.cpp` | build a 1D prefix array and answer range sums in O(1) | demo |
| `prefix_sum_2d.cpp` | 2D prefix sums for O(1) rectangle range sums | [LC 304](https://leetcode.com/problems/range-sum-query-2d-immutable/) · [CN](https://leetcode.cn/problems/range-sum-query-2d-immutable/) |
| `prefix_sum_range_query.cpp` | O(1) range-sum queries over an immutable prefix array | [LC 303](https://leetcode.com/problems/range-sum-query-immutable/) · [CN](https://leetcode.cn/problems/range-sum-query-immutable/) |
| `prefix_sum_subarray_sum_k.cpp` | count subarrays with sum k via prefix sums + hash map | [LC 560](https://leetcode.com/problems/subarray-sum-equals-k/) · [CN](https://leetcode.cn/problems/subarray-sum-equals-k/) |

#### `easy/queue` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `queue_basic.cpp` | hand-rolled circular queue over a fixed array (push, pop, front) | demo |
| `queue_circular.cpp` | fixed-size circular queue design | [LC 622](https://leetcode.com/problems/design-circular-queue/) · [CN](https://leetcode.cn/problems/design-circular-queue/) |
| `queue_implement_stack.cpp` | LIFO stack built from a queue | [LC 225](https://leetcode.com/problems/implement-stack-using-queues/) · [CN](https://leetcode.cn/problems/implement-stack-using-queues/) |
| `queue_stl.cpp` | `std::queue` and `std::deque` usage | demo |

#### `easy/stack` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `stack_basic.cpp` | hand-rolled stack over a fixed array (push, pop, top) | demo |
| `stack_implement_queue.cpp` | FIFO queue built from two stacks | [LC 232](https://leetcode.com/problems/implement-queue-using-stacks/) · [CN](https://leetcode.cn/problems/implement-queue-using-stacks/) |
| `stack_min_stack.cpp` | stack that reports its minimum in O(1) | [LC 155](https://leetcode.com/problems/min-stack/) · [CN](https://leetcode.cn/problems/min-stack/) |
| `stack_stl.cpp` | `std::stack` usage | demo |
| `stack_valid_parentheses.cpp` | bracket matching with a stack | [LC 20](https://leetcode.com/problems/valid-parentheses/) · [CN](https://leetcode.cn/problems/valid-parentheses/) |

#### `easy/strings` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `string_basic.cpp` | `std::string` iterate/index basics | demo |
| `string_anagram.cpp` | anagram check by letter counts | [LC 242](https://leetcode.com/problems/valid-anagram/) · [CN](https://leetcode.cn/problems/valid-anagram/) |
| `string_palindrome.cpp` | palindrome check skipping non-alphanumerics | [LC 125](https://leetcode.com/problems/valid-palindrome/) · [CN](https://leetcode.cn/problems/valid-palindrome/) |
| `string_reverse.cpp` | in-place reversal with two pointers | [LC 344](https://leetcode.com/problems/reverse-string/) · [CN](https://leetcode.cn/problems/reverse-string/) |
| `string_stl.cpp` | `std::string` find, substr, append, compare | demo |

#### `easy/two-pointers` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `two_pointers_basic.cpp` | how it works — same-direction and opposite-direction pointers | demo |
| `two_pointers_container_water.cpp` | greedy opposite-direction search for max area | [LC 11](https://leetcode.com/problems/container-with-most-water/) · [CN](https://leetcode.cn/problems/container-with-most-water/) |
| `two_pointers_remove_element.cpp` | in-place compaction with slow/fast pointers | [LC 27](https://leetcode.com/problems/remove-element/) · [CN](https://leetcode.cn/problems/remove-element/) |
| `two_pointers_three_sum.cpp` | sort, fix one index, two-sum the rest | [LC 15](https://leetcode.com/problems/3sum/) · [CN](https://leetcode.cn/problems/3sum/) |
| `two_pointers_two_sum_sorted.cpp` | opposite-direction pair search on sorted input | [LC 167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) · [CN](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) |

### medium — 40 files

#### `medium/bit-manipulation` (6)

| File | What it does | Problem |
| --- | --- | --- |
| `bit_basic.cpp` | the six bitwise operators and get/set/clear bit | demo |
| `bit_counting_bits.cpp` | count 1-bits of every i in 0..n with DP | [LC 338](https://leetcode.com/problems/counting-bits/) · [CN](https://leetcode.cn/problems/counting-bits/) |
| `bit_missing_number.cpp` | find the missing number in 0..n using XOR | [LC 268](https://leetcode.com/problems/missing-number/) · [CN](https://leetcode.cn/problems/missing-number/) |
| `bit_power_of_two.cpp` | check n is a power of two via `n & (n - 1)` | [LC 231](https://leetcode.com/problems/power-of-two/) · [CN](https://leetcode.cn/problems/power-of-two/) |
| `bit_single_number.cpp` | find the element that appears once using XOR | [LC 136](https://leetcode.com/problems/single-number/) · [CN](https://leetcode.cn/problems/single-number/) |
| `bit_subsets_mask.cpp` | enumerate all subsets with bitmask loops | [LC 78](https://leetcode.com/problems/subsets/) · [CN](https://leetcode.cn/problems/subsets/) |

#### `medium/directed-graphs` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `directed_graph_basic.cpp` | how it works — adjacency list build + print | demo |
| `directed_graph_bfs.cpp` | BFS shortest distances on an unweighted digraph | demo |
| `directed_graph_cycle.cpp` | directed cycle detection with DFS colors | demo |
| `directed_graph_dfs.cpp` | DFS preorder traversal from a source on a digraph | demo |

#### `medium/greedy` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `greedy_basic.cpp` | activity selection by earliest finish time | demo |
| `greedy_gas_station.cpp` | greedy circuit-start scan | [LC 134](https://leetcode.com/problems/gas-station/) · [CN](https://leetcode.cn/problems/gas-station/) |
| `greedy_jump_game.cpp` | greedy farthest-reach scan | [LC 55](https://leetcode.com/problems/jump-game/) · [CN](https://leetcode.cn/problems/jump-game/) |
| `greedy_non_overlapping.cpp` | earliest-finish greedy for intervals | [LC 435](https://leetcode.com/problems/non-overlapping-intervals/) · [CN](https://leetcode.cn/problems/non-overlapping-intervals/) |

#### `medium/grids` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `grid_basic.cpp` | grid input, 4-direction moves, BFS flood fill | demo |
| `grid_bfs_rotting.cpp` | BFS multi-source rotting oranges | [LC 994](https://leetcode.com/problems/rotting-oranges/) · [CN](https://leetcode.cn/problems/rotting-oranges/) |
| `grid_dfs_islands.cpp` | DFS island counting | [LC 200](https://leetcode.com/problems/number-of-islands/) · [CN](https://leetcode.cn/problems/number-of-islands/) |
| `grid_flood_fill.cpp` | DFS flood fill | [LC 733](https://leetcode.com/problems/flood-fill/) · [CN](https://leetcode.cn/problems/flood-fill/) |

#### `medium/monotonic-queue` (3)

| File | What it does | Problem |
| --- | --- | --- |
| `monotonic_queue_basic.cpp` | window maximum and minimum with a deque | demo |
| `monotonic_queue_max_value_equation.cpp` | maximize yi + yj + abs(xi - xj) | [LC 1499](https://leetcode.com/problems/max-value-of-equation/) · [CN](https://leetcode.cn/problems/max-value-of-equation/) |
| `monotonic_queue_sliding_window_max.cpp` | max value of every window of size k | [LC 239](https://leetcode.com/problems/sliding-window-maximum/) · [CN](https://leetcode.cn/problems/sliding-window-maximum/) |

#### `medium/monotonic-stack` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `monotonic_stack_basic.cpp` | next greater and previous smaller with stacks | demo |
| `monotonic_stack_daily_temperatures.cpp` | days until a warmer temperature | [LC 739](https://leetcode.com/problems/daily-temperatures/) · [CN](https://leetcode.cn/problems/daily-temperatures/) |
| `monotonic_stack_largest_rectangle.cpp` | largest rectangle area in a histogram | [LC 84](https://leetcode.com/problems/largest-rectangle-in-histogram/) · [CN](https://leetcode.cn/problems/largest-rectangle-in-histogram/) |
| `monotonic_stack_next_greater.cpp` | next greater element for each query value | [LC 496](https://leetcode.com/problems/next-greater-element-i/) · [CN](https://leetcode.cn/problems/next-greater-element-i/) |

#### `medium/sliding-window` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `sliding_window_basic.cpp` | fixed and variable window in one pass | demo |
| `sliding_window_longest_unique.cpp` | longest substring with all unique characters | [LC 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) · [CN](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) |
| `sliding_window_max_average.cpp` | maximum average of any length-k subarray | [LC 643](https://leetcode.com/problems/maximum-average-subarray-i/) · [CN](https://leetcode.cn/problems/maximum-average-subarray-i/) |
| `sliding_window_min_size_sum.cpp` | shortest subarray with sum >= target | [LC 209](https://leetcode.com/problems/minimum-size-subarray-sum/) · [CN](https://leetcode.cn/problems/minimum-size-subarray-sum/) |
| `sliding_window_min_window.cpp` | smallest substring covering all characters of t | [LC 76](https://leetcode.com/problems/minimum-window-substring/) · [CN](https://leetcode.cn/problems/minimum-window-substring/) |

#### `medium/trees` (6)

| File | What it does | Problem |
| --- | --- | --- |
| `tree_basic.cpp` | TreeNode struct, level-order build and print | demo |
| `tree_lca.cpp` | recursive lowest common ancestor | [LC 236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) · [CN](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/) |
| `tree_level_order.cpp` | BFS level-order traversal by levels | [LC 102](https://leetcode.com/problems/binary-tree-level-order-traversal/) · [CN](https://leetcode.cn/problems/binary-tree-level-order-traversal/) |
| `tree_max_depth.cpp` | recursive maximum depth | [LC 104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) · [CN](https://leetcode.cn/problems/maximum-depth-of-binary-tree/) |
| `tree_traversals.cpp` | pre/in/post-order traversals, recursive and iterative | [LC 94](https://leetcode.com/problems/binary-tree-inorder-traversal/) · [CN](https://leetcode.cn/problems/binary-tree-inorder-traversal/) |
| `tree_validate_bst.cpp` | range-bounds validation of a BST | [LC 98](https://leetcode.com/problems/validate-binary-search-tree/) · [CN](https://leetcode.cn/problems/validate-binary-search-tree/) |

#### `medium/undirected-graphs` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `undirected_graph_basic.cpp` | how it works — adjacency list + DFS/BFS orders | demo |
| `undirected_graph_components.cpp` | count connected components with DFS | demo |
| `undirected_graph_cycle.cpp` | undirected cycle detection with DFS parent tracking | demo |
| `undirected_graph_path_exists.cpp` | BFS reachability between two nodes | [LC 1971](https://leetcode.com/problems/find-if-path-exists-in-graph/) · [CN](https://leetcode.cn/problems/find-if-path-exists-in-graph/) |

### tough — 27 files

#### `tough/backtracking` (6)

| File | What it does | Problem |
| --- | --- | --- |
| `backtracking_basic.cpp` | choose/explore/unchoose template | demo |
| `backtracking_combinations.cpp` | choose k of 1..n by exploring increasing starts | [LC 77](https://leetcode.com/problems/combinations/) · [CN](https://leetcode.cn/problems/combinations/) |
| `backtracking_n_queens.cpp` | place queens row by row with column/diagonal guards | [LC 51](https://leetcode.com/problems/n-queens/) · [CN](https://leetcode.cn/problems/n-queens/) |
| `backtracking_permutations.cpp` | build permutations one position at a time | [LC 46](https://leetcode.com/problems/permutations/) · [CN](https://leetcode.cn/problems/permutations/) |
| `backtracking_subsets.cpp` | generate all subsets via choose/explore/unchoose | [LC 78](https://leetcode.com/problems/subsets/) · [CN](https://leetcode.cn/problems/subsets/) |
| `backtracking_word_search.cpp` | DFS from each cell, marking visited cells | [LC 79](https://leetcode.com/problems/word-search/) · [CN](https://leetcode.cn/problems/word-search/) |

#### `tough/divide-and-conquer` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `divide_conquer_basic.cpp` | divide, solve halves, combine by merging | demo |
| `divide_conquer_fast_pow.cpp` | x^n by squaring the half power (binary exponentiation) | [LC 50](https://leetcode.com/problems/powx-n/) · [CN](https://leetcode.cn/problems/powx-n/) |
| `divide_conquer_max_subarray.cpp` | max subarray sum via left/right/crossing recursion | [LC 53](https://leetcode.com/problems/maximum-subarray/) · [CN](https://leetcode.cn/problems/maximum-subarray/) |
| `divide_conquer_merge_sort.cpp` | top-down merge sort (sort halves, merge) | [LC 912](https://leetcode.com/problems/sort-an-array/) · [CN](https://leetcode.cn/problems/sort-an-array/) |
| `divide_conquer_quickselect.cpp` | partition around a pivot, recurse into one side | [LC 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) · [CN](https://leetcode.cn/problems/kth-largest-element-in-an-array/) |

#### `tough/dynamic-programming` (6)

| File | What it does | Problem |
| --- | --- | --- |
| `dp_basic.cpp` | fibonacci by memoization vs tabulation | demo |
| `dp_01_knapsack.cpp` | max value within capacity, each item used at most once | demo |
| `dp_climb_stairs.cpp` | count ways to reach step n (1 or 2 steps at a time) | [LC 70](https://leetcode.com/problems/climbing-stairs/) · [CN](https://leetcode.cn/problems/climbing-stairs/) |
| `dp_coin_change.cpp` | fewest coins summing to amount (unbounded knapsack) | [LC 322](https://leetcode.com/problems/coin-change/) · [CN](https://leetcode.cn/problems/coin-change/) |
| `dp_edit_distance.cpp` | min insert/delete/replace ops turning word1 into word2 | [LC 72](https://leetcode.com/problems/edit-distance/) · [CN](https://leetcode.cn/problems/edit-distance/) |
| `dp_lis.cpp` | longest increasing subsequence via patience tails array | [LC 300](https://leetcode.com/problems/longest-increasing-subsequence/) · [CN](https://leetcode.cn/problems/longest-increasing-subsequence/) |

#### `tough/string-hashing` (3)

| File | What it does | Problem |
| --- | --- | --- |
| `string_hash_basic.cpp` | polynomial rolling hash of a string or substring | demo |
| `string_hash_compare.cpp` | O(1) substring equality via prefix hashes | [LC 187](https://leetcode.com/problems/repeated-dna-sequences/) · [CN](https://leetcode.cn/problems/repeated-dna-sequences/) |
| `string_hash_rabin_karp.cpp` | Rabin-Karp pattern search | [LC 28](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) · [CN](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/) |

#### `tough/topological-sort` (3)

| File | What it does | Problem |
| --- | --- | --- |
| `topological_sort_basic.cpp` | how it works — Kahn's algorithm vs DFS reverse postorder | demo |
| `topological_sort_dfs.cpp` | DFS cycle detection for course scheduling | [LC 207](https://leetcode.com/problems/course-schedule/) · [CN](https://leetcode.cn/problems/course-schedule/) |
| `topological_sort_kahn.cpp` | Kahn's BFS topological sort of courses | [LC 210](https://leetcode.com/problems/course-schedule-ii/) · [CN](https://leetcode.cn/problems/course-schedule-ii/) |

#### `tough/union-find` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `union_find_basic.cpp` | how it works — find/union, path compression, union by size | demo |
| `union_find_dsu.cpp` | full DSU class (find/connected/unite) reused in problems | demo |
| `union_find_provinces.cpp` | count provinces with DSU | [LC 547](https://leetcode.com/problems/number-of-provinces/) · [CN](https://leetcode.cn/problems/number-of-provinces/) |
| `union_find_redundant_connection.cpp` | find the redundant edge with DSU | [LC 684](https://leetcode.com/problems/redundant-connection/) · [CN](https://leetcode.cn/problems/redundant-connection/) |

### unhinged — 18 files (competitive programming)

#### `unhinged/combinatorics` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `combinatorics_basic.cpp` | factorial + binomial coefficient nCr | demo |
| `combinatorics_catalan.cpp` | Catalan numbers via C(2n,n)/(n+1) | demo |
| `combinatorics_inclusion_exclusion.cpp` | inclusion-exclusion over divisibility | demo |
| `combinatorics_ncr_mod.cpp` | nCr mod p via factorials + modular inverse | demo |

#### `unhinged/geometry` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `geometry_basic.cpp` | points/vectors with dot + cross product | demo |
| `geometry_convex_hull.cpp` | Andrew's monotone chain convex hull | demo |
| `geometry_orientation.cpp` | orientation test (left/right/collinear) | demo |
| `geometry_polygon_area.cpp` | shoelace formula polygon area | demo |
| `geometry_segment_intersection.cpp` | segment intersection test | demo |

#### `unhinged/number-theory` (5)

| File | What it does | Problem |
| --- | --- | --- |
| `number_theory_basic.cpp` | Euclidean gcd and lcm of two integers | demo |
| `number_theory_factorization.cpp` | prime factorization by trial division | demo |
| `number_theory_mod_inverse.cpp` | modular inverse via Fermat and extended Euclid | demo |
| `number_theory_modpow.cpp` | fast modular exponentiation (binary exponentiation) | demo |
| `number_theory_sieve.cpp` | Sieve of Eratosthenes | [LC 204](https://leetcode.com/problems/count-primes/) · [CN](https://leetcode.cn/problems/count-primes/) |

#### `unhinged/segment-trees` (4)

| File | What it does | Problem |
| --- | --- | --- |
| `segment_tree_basic.cpp` | segment tree with build / query / point-update (annotated) | demo |
| `segment_tree_lazy.cpp` | lazy propagation with range add and range sum query | demo |
| `segment_tree_min.cpp` | range minimum query with point update | demo |
| `segment_tree_sum.cpp` | range sum query with point update | demo |

## Conventions

- **Language:** C++17, compiled with `g++ -std=c++17 -O2 -Wall -Wextra`. Snippets use `#include <bits/stdc++.h>`.
- **Structure:** every file = header comment block → `class Solution { solve(...) }` (algorithm only) → `main()` (input/output only). Design-type problems (e.g. LC 155/225/232/622) additionally keep the canonical design class and drive it through `solve`.
- **References:** every file cites the canonical source its implementation follows (CP-Algorithms, cppreference, or the official LeetCode solution) in an MLA-style block; pure demos say `reference: none (original demo)`. See the in-file `// reference:` blocks — this index links the problems, the files carry the citations.
- **Placeholders:** `.gitkeep` marks intentionally empty dirs (e.g. `misc/`); safe to delete once real files land.
