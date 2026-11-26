# DSA-AI-sheet
AI generated DSA snippets

## 目录结构

仓库按"难度层级 → 细分概念"两级结构组织 LeetCode / 竞赛考点，顶层为 4 个难度层级，具体考点下沉到子目录。

层级命名 `easy → medium → tough → unhinged` 即 easy / medium / hard / insane 的同义词，特意选得让目录按名称排序时恰好是难度升序。

| 难度层级 | 说明 | 子目录 |
| --- | --- | --- |
| `easy` | 基础考点 | `arrays`、`strings`、`linked-lists`、`stack`、`queue`、`two-pointers`、`prefix-sums`、`binary-search` |
| `medium` | 进阶考点 | `sliding-window`、`monotonic-stack`、`monotonic-queue`、`bit-manipulation`、`trees`、`undirected-graphs`、`directed-graphs`、`grids`、`greedy` |
| `tough` | 困难考点（hard） | `backtracking`、`dynamic-programming`、`divide-and-conquer`、`union-find`、`topological-sort`、`string-hashing` |
| `unhinged` | 竞赛级（insane / competitive programming）：线段树与硬核数学 | `segment-trees`、`number-theory`、`combinatorics`、`geometry` |
| `misc` | 其他/未分类 | — |

## 分类规则

- 基础单一考点进 `easy`
- 更难的考点依次进 `medium`、`tough`
- 线段树、硬核数学算法（数论、组合、几何）进 `unhinged`
- 组合了多个基础考点的算法（如 `string-hashing` = 字符串 + 哈希）自动排除出 `easy`

## 约定

- 代码片段使用 **C++**，以 `.cpp` 文件放入对应的细分概念子目录
- `.gitkeep` 仅为空目录占位，目录内添加代码文件后可删除
