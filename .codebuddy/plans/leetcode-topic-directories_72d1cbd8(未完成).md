---
name: leetcode-topic-directories
overview: 在 DSA-AI-sheet 项目中创建 LeetCode 常考专题目录结构，采用 NeetCode/Blind 75 风格的分类体系，共 16 个带序号的目录，便于后续按专题组织算法代码片段。
todos:
  - id: create-topic-dirs
    content: 创建16个高频专题目录及misc目录，每目录放.gitkeep
    status: pending
  - id: update-readme
    content: 更新README.md，添加专题目录结构说明表格
    status: pending
    dependencies:
      - create-topic-dirs
---

## 产品概述
DSA-AI-sheet 是一个按 LeetCode 高频专题组织的算法代码片段仓库。本次任务为仓库搭建专题目录骨架，便于后续按考点归档 AI 生成的 DSA 代码片段。

## 核心功能
- 创建 LeetCode 常考专题目录，覆盖业界通行的高频考点分类（NeetCode/Blind 75 风格）
- 目录采用数字前缀 + kebab-case 命名，按推荐学习顺序排列
- 每个目录放置 .gitkeep 占位文件，确保空目录可被 git 追踪
- 同步更新 README.md，列出专题目录结构说明

## 技术方案
### 技术栈
- 纯目录/文件组织，无需编程语言依赖
- 版本管理：Git（通过 .gitkeep 占位空目录）

### 实现方案
在仓库根目录下创建 16 个专题目录，采用业界最流行的 LeetCode 高频考点划分（NeetCode 150 / Blind 75 体系），并附加一个 `misc` 目录收纳未分类题目。命名规则为两位数字前缀 + kebab-case（如 `01-arrays-hashing`），保证文件管理器与终端中按学习路径有序展示。

### 实现要点
- 仅创建目录与 .gitkeep 占位文件，不创建任何代码文件，保持本次变更范围最小
- README.md 追加目录结构表格（序号、目录名、中文专题名、说明），不覆盖原有标题
- 目录列表（16 + 1）：
  1. `01-arrays-hashing` — 数组与哈希
  2. `02-two-pointers` — 双指针
  3. `03-sliding-window` — 滑动窗口
  4. `04-stack` — 栈
  5. `05-binary-search` — 二分查找
  6. `06-linked-list` — 链表
  7. `07-trees` — 树
  8. `08-tries` — 字典树（Trie）
  9. `09-heap-priority-queue` — 堆与优先队列
  10. `10-backtracking` — 回溯
  11. `11-graphs` — 图
  12. `12-dynamic-programming` — 动态规划
  13. `13-greedy` — 贪心
  14. `14-intervals` — 区间问题
  15. `15-math-geometry` — 数学与几何
  16. `16-bit-manipulation` — 位运算
  17. `misc` — 其他/未分类

### 架构设计
无复杂组件关系，为单层目录骨架 + README 文档说明，无需架构图。

### 目录结构
```
DSA-AI-sheet/
├── README.md                    # [MODIFY] 追加专题目录结构说明表格
├── 01-arrays-hashing/
│   └── .gitkeep                 # [NEW] 空目录占位
├── 02-two-pointers/
│   └── .gitkeep                 # [NEW]
├── 03-sliding-window/
│   └── .gitkeep                 # [NEW]
├── 04-stack/
│   └── .gitkeep                 # [NEW]
├── 05-binary-search/
│   └── .gitkeep                 # [NEW]
├── 06-linked-list/
│   └── .gitkeep                 # [NEW]
├── 07-trees/
│   └── .gitkeep                 # [NEW]
├── 08-tries/
│   └── .gitkeep                 # [NEW]
├── 09-heap-priority-queue/
│   └── .gitkeep                 # [NEW]
├── 10-backtracking/
│   └── .gitkeep                 # [NEW]
├── 11-graphs/
│   └── .gitkeep                 # [NEW]
├── 12-dynamic-programming/
│   └── .gitkeep                 # [NEW]
├── 13-greedy/
│   └── .gitkeep                 # [NEW]
├── 14-intervals/
│   └── .gitkeep                 # [NEW]
├── 15-math-geometry/
│   └── .gitkeep                 # [NEW]
├── 16-bit-manipulation/
│   └── .gitkeep                 # [NEW]
└── misc/
    └── .gitkeep                 # [NEW] 未分类题目收纳
```
