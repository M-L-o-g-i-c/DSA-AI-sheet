---
name: leetcode-topic-directories
overview: 按"少量宽泛主专题 + 子目录细分概念"的两级结构组织 LeetCode 考点：6 个主专题（linear、stacks-queues、trees、graphs、math、techniques）下辖各细分概念子目录，后续 C++ 代码片段放入对应子目录。
todos:
  - id: create-main-dirs
    content: 创建 5 个主专题目录与 misc 目录骨架
    status: completed
  - id: create-subdirs
    content: 创建各主专题下概念子目录并放置 .gitkeep
    status: completed
    dependencies:
      - create-main-dirs
  - id: update-readme
    content: 更新 README.md 记录两级目录结构与 C++ 片段约定
    status: completed
    dependencies:
      - create-subdirs
---

## 产品概述
DSA-AI-sheet 是一个按 LeetCode 高频考点组织的算法代码片段仓库（后续使用 C++）。本次任务为仓库搭建两级专题目录骨架：少量宽泛的主专题目录，每个主专题下辖若干细分概念子目录，后续按考点归档代码片段。

## 核心功能
- 创建 5 个宽泛主专题目录（线性结构、栈与队列、图、数学、通用技法）+ 1 个 misc 目录，顶层分类少而宽泛
- 每个主专题下创建细分概念子目录（如 graphs 下 trees/directed-graphs/union-find，math 下 geometry 等）
- 每个叶子子目录放置 .gitkeep 占位文件，保证 git 可追踪空目录
- 更新 README.md，记录两级目录结构与后续 C++ (.cpp) 代码片段的放置约定

## 技术栈
- 纯目录/文件组织，无需编程语言依赖
- 版本管理：Git（.gitkeep 占位空目录）
- 后续代码语言：C++（.cpp 片段放入对应叶子子目录，本次不创建）

## 实现方案
在仓库根目录创建 5 个数字前缀主专题目录（kebab-case，按推荐学习顺序排列），每个主专题下创建 3-6 个概念子目录。顶层只保留宽泛概念家族，具体考点全部下沉到子目录，与用户"主专题少、子目录分支细化"的要求一致。

## 目录清单（5 主专题 + misc）
1. `01-linear/` — 线性结构与序列处理
   - `arrays/`、`strings/`、`linked-lists/`、`two-pointers/`、`sliding-window/`、`prefix-sums/`
2. `02-stacks-queues/` — 栈、队列与单调结构
   - `stack/`、`queue/`、`monotonic-stack/`、`monotonic-queue/`
3. `03-graphs/` — 图与树
   - `trees/`、`directed-graphs/`、`undirected-graphs/`、`grids/`、`union-find/`、`topological-sort/`
4. `04-math/` — 数学
   - `geometry/`、`number-theory/`、`bit-manipulation/`、`combinatorics/`
5. `05-techniques/` — 通用算法技法
   - `binary-search/`、`backtracking/`、`dynamic-programming/`、`greedy/`、`divide-and-conquer/`
6. `misc/` — 其他/未分类

## 实现要点
- 仅创建目录与 .gitkeep 占位文件，不创建任何代码文件，变更范围最小
- README.md 在原标题下追加目录结构说明（主专题、子目录、含义）及 C++ 片段放置约定，不覆盖原有内容
- 主专题目录数字前缀 + kebab-case；子目录纯 kebab-case

## 目录结构
```
DSA-AI-sheet/
├── README.md                       # [MODIFY] 追加两级目录结构与 C++ 约定说明
├── 01-linear/
│   ├── arrays/.gitkeep             # [NEW]
│   ├── strings/.gitkeep            # [NEW]
│   ├── linked-lists/.gitkeep       # [NEW]
│   ├── two-pointers/.gitkeep       # [NEW]
│   ├── sliding-window/.gitkeep     # [NEW]
│   └── prefix-sums/.gitkeep        # [NEW]
├── 02-stacks-queues/
│   ├── stack/.gitkeep              # [NEW]
│   ├── queue/.gitkeep              # [NEW]
│   ├── monotonic-stack/.gitkeep    # [NEW]
│   └── monotonic-queue/.gitkeep    # [NEW]
├── 03-graphs/
│   ├── trees/.gitkeep              # [NEW]
│   ├── directed-graphs/.gitkeep    # [NEW]
│   ├── undirected-graphs/.gitkeep  # [NEW]
│   ├── grids/.gitkeep              # [NEW]
│   ├── union-find/.gitkeep         # [NEW]
│   └── topological-sort/.gitkeep   # [NEW]
├── 04-math/
│   ├── geometry/.gitkeep           # [NEW]
│   ├── number-theory/.gitkeep      # [NEW]
│   ├── bit-manipulation/.gitkeep   # [NEW]
│   └── combinatorics/.gitkeep      # [NEW]
├── 05-techniques/
│   ├── binary-search/.gitkeep      # [NEW]
│   ├── backtracking/.gitkeep       # [NEW]
│   ├── dynamic-programming/.gitkeep# [NEW]
│   ├── greedy/.gitkeep             # [NEW]
│   └── divide-and-conquer/.gitkeep # [NEW]
└── misc/.gitkeep                   # [NEW] 未分类题目收纳
```
