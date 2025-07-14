# Embedded Systems Career Development Journal

## 简介

**写在前面**

本仓库用来记录作者在嵌入式领域中工作和学习所积累的笔记，来用于系统化梳理自己在工作过程中的学习积累，形成可复用的技术资产。

嵌入式的学习并非易事，其属于交叉性应用工程，即使是一个小的项目所涉及的学科知识也十分庞杂，这就导致了学习曲线的陡峭。但嵌入式既然属于工程范畴，从业至今我认为最好的学习方式：

1.采用自顶向下的学习方式，先经手一个难度适中的小项目然后不断优化，向下逐渐拆解，直至达到自我认可的边界。

2.不要有畏难情绪，不要回避用最难的方式去学习知识。平心而论



## 笔记

### 基础课程

1.C语言

2.数据结构

3.计算机组成原理

4.计算机网络

5.



### 基础工具链



### 硬件平台

1.[ESP32&ESP8266](./ESP32&ESP8266/ESP-IDF笔记.md)
2.[ESP-IDF环境搭建方式](./ESP32&ESP8266/ESP-IDF环境搭建)

3.[嵌入式C语言学习笔记](./Linux-C语言/嵌入式C语言笔记.md)

1.[ESP32&ESP8266](./ESP32&ESP8266/ESP学习笔记.md)

1.[ESP32&ESP8266](./ESP32&ESP8266/ESP学习笔记.md)



下面是一个较为完整的 **Git 协作开发流程**（以 Gitflow 为例），帮助你从“当作自动保存工具”迈向真正的团队协作：

------

## 1. 初始化仓库 & 主分支约定

- 创建远程仓库（GitHub/CodeHub）

- 本地执行：

  ```bash
  git clone <repo_url>
  cd repo
  git checkout -b develop
  git push -u origin develop
  ```

- 两个主干分支：

  - `main`：用于生产发布，始终保持可部署状态
  - `develop`：用于集成开发，所有 feature 分支来自此，稳定后合入

------

## 2. 功能开发：Feature 分支（feature/…）✨

1. 从 `develop` 分支拉出 feature 分支：

   ```bash
   git checkout develop
   git pull
   git checkout -b feature/我的功能描述
   ```

2. 在该分支完成开发，多次提交：

   ```bash
   git add .
   git commit -m "feat: 实现 XYZ 功能"
   ```

3. 推送并与团队协作审核：

   ```bash
   git push -u origin feature/我的功能描述
   ```

4. 发起 Pull Request → 同伴 Code Review → 合入 `develop` 分支

------

## 3. 发布准备：Release 分支（release/x.y.z）

当 `develop` 中功能达到发布标准：

1. 创建 release 分支：

   ```bash
   git checkout develop
   git pull
   git checkout -b release/1.2.0
   ```

2. 在该分支进行最后调试、bug 修复、版本号更新等

3. 测试通过后：

   ```bash
   git checkout main
   git merge release/1.2.0
   git tag -a v1.2.0 -m "Release 1.2.0"
   git checkout develop
   git merge release/1.2.0
   git branch -d release/1.2.0
   git push origin main develop --tags
   ```

------

## 4. 紧急修复：Hotfix 分支（hotfix/…）

在 `main` 分支发现严重 bug 时：

1. 创建 hotfix 分支：

   ```bash
   git checkout main
   git pull
   git checkout -b hotfix/1.2.1
   ```

2. 快速打补丁并提交，确保修复有效

3. 合并修复：

   ```bash
   git checkout main
   git merge hotfix/1.2.1
   git tag -a v1.2.1 -m "Hotfix 1.2.1"
   git checkout develop
   git merge hotfix/1.2.1
   git branch -d hotfix/1.2.1
   git push origin main develop --tags
   ```

------

## 5. 常用命令总结

| 操作               | Git 命令                                                     |
| ------------------ | ------------------------------------------------------------ |
| 创建 feature 分支  | `git checkout -b feature/xxx develop`                        |
| 提交 & 推送        | `git add . && git commit -m "msg"``git push -u origin feature/xxx` |
| 完成 feature，合并 | PR → review → merge → 删除分支                               |
| 发布版本           | 同 release 分支操作（见上）                                  |
| 紧急修复           | 同 hotfix 分支操作（见上）                                   |

------

## 6. 为什么选择 Gitflow？

- 清晰分支职责：把新功能、版本发布、紧急修复彻底分离 ([atlassian.com](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow?utm_source=chatgpt.com), [nulab.com](https://nulab.com/learn/software-development/git-tutorial/git-collaboration/branching-workflows/gitflow-workflow/?utm_source=chatgpt.com), [en.wikipedia.org](https://en.wikipedia.org/wiki/Git?utm_source=chatgpt.com))
- 避免多人在同一分支产生冲突
- 便于追踪、回滚与持续集成

------

## 7. 效率使用建议

1. 每次开发前先 `git pull develop`，保持本地最新
2. Feature 完成及时合 PR，减少分支生命周期
3. Release 分支只做调试/版本号/小修，避免引入新功能
4. 合并时优选 `--no-ff` 或 PR，这样保留分支历史

------

## ✅ 总结：从“自动保存”到“协作开发”

- **每个功能独立分支**，多人不会相互干扰
- **发布前预备分支**可做调试、版本号更新
- **紧急修复可快速响应生产问题**
- **合并回主线后删除无用分支，保持干净仓库**

------

如果你需要，我可以帮你生成一套 Bash 脚本模板，或写一个 GitHub Actions CI 示例，让开发、发布、打 tag 更自动、更规范。需要吗？

你第一个版本可以根据项目性质、完成度、是否面向用户等来命名。下面给你几种常见但实用的命名方式建议：

------

## 🚀 情况一：**正式稳定可用版本**

如果你已经开发了一个可用的、功能完整的版本（即使只是 MVP）：

👉 推荐命名为：

```bash
v1.0.0
```

含义：

- `1`：表示**第一个正式版本**
- `0`：尚未做新增功能扩展
- `0`：没有 bug 修复历史

📌 可以加备注或标签名如：

```bash
git tag -a v1.0.0 -m "Initial stable release"
git push origin v1.0.0
```

------

## 🧪 情况二：**内部测试 / 原型验证阶段**

如果当前只是内部原型或预发布版本，不建议直接叫 `v1.0.0`，可用：

```bash
v0.1.0
```

或

```bash
v0.1.0-alpha.1
```

含义：

- `0`：代表还在开发期（不稳定）
- `.1.0`：表示第一个原型或初版
- `-alpha.1`：开发中试验版（可选）

------

## 🎯 常用首发版本命名对比

| 场景                  | 推荐版本号           | 说明               |
| --------------------- | -------------------- | ------------------ |
| 正式可用，用户可使用  | `v1.0.0`             | 第一稳定版         |
| 内测功能完整但未发布  | `v0.9.0`             | 候选版本（未上线） |
| 仅供验证逻辑/功能测试 | `v0.1.0-alpha`       | 初始验证，开发阶段 |
| 私人/学习项目         | `v0.1.0` 或 `v0.0.1` | 第一次提交做个标记 |

------

## 💡 建议流程

1. 在 Git 仓库中打 tag：

   ```bash
   git tag -a v1.0.0 -m "First stable version: 保温灯核心功能上线"
   git push origin v1.0.0
   ```

2. 在版本说明文档（如 `CHANGELOG.md`）中写上版本变更内容

------

## ✍️ 示例：智能保温灯 v1.0.0

```markdown
## [v1.0.0] - 2025-07-13
- 实现温度传感器数据读取（SHTC3）
- 基础 PWM 控制保温灯
- 加入 WiFi 配网（WiFiManager）
- 自动记忆温度设置
- OTA 升级框架准备
```

------

如果你告诉我现在功能有哪些，我可以帮你准确命名版本号 + 写一段标准版本发布说明。要不要我帮你写一段？





这是非常关键的问题，意味着你已经不仅仅在“写代码”，而是在考虑**工程管理和版本控制体系**，这是迈向专业嵌入式/软件工程师的重要一步。

------

## ✅ 第一部分：**你的下一个版本怎么开发？**

比如你已经发布了 `v1.0.0`，那你接下来的开发通常分为两类：

### 🧩 **1. 增加新功能**（比如：新增定时功能、调光功能）

- 建议创建功能分支（从 `main` 或 `develop`）：

  ```bash
  git checkout -b feature/auto-brightness
  ```

- 编写代码，多次提交：

  ```bash
  git add .
  git commit -m "feat: 自动亮度调节功能初步完成"
  ```

- 推送并合并：

  ```bash
  git push -u origin feature/auto-brightness
  ```

- 合入开发主线：

  ```bash
  git checkout main
  git merge feature/auto-brightness
  git branch -d feature/auto-brightness
  ```

- 发新版本：

  ```bash
  git tag -a v1.1.0 -m "添加自动亮度调节功能"
  git push origin v1.1.0
  ```

🔢 **版本号更新策略**：

| 情况       | 升级方式 |
| ---------- | -------- |
| 新功能     | `v1.1.0` |
| 修 bug     | `v1.0.1` |
| 不兼容改动 | `v2.0.0` |

------

## ✅ 第二部分：**新项目如何制定合理框架？**

一个嵌入式项目建议有以下 5 个基础结构模块：

### 📁 推荐项目目录结构：

```
smart-heating-lamp/
├── src/                   # 源码
│   ├── main.cpp
│   ├── lamp_control.cpp
│   └── wifi_setup.cpp
├── include/               # 头文件
│   └── lamp_control.h
├── lib/                   # 第三方库
│   └── SHTC3/
├── data/                  # SPIFFS 文件系统（用于网页）
├── scripts/               # 构建脚本、打包、烧录等
├── platformio.ini / .ino  # 项目配置
├── changelog.md           # 版本变更日志
├── README.md              # 项目说明
└── .git/                  # Git 仓库
```

------

### 🔧 工程初始化流程（以 PlatformIO 或 Arduino 为例）

1. 初始化项目文件夹和 Git 仓库：

```bash
mkdir smart-heating-lamp
cd smart-heating-lamp
git init
```

1. 创建分支结构（建议使用）：

```bash
git checkout -b develop
```

1. 添加 `.gitignore` 文件：

```bash
*.bin
*.elf
data/upload/*
.pio/
build/
.vscode/
```

1. 第一次提交：

```bash
git add .
git commit -m "chore: 初始化项目框架"
git tag -a v0.1.0 -m "项目结构初始版本"
```

1. 开始开发第一个功能（如 PWM 控灯）：

```bash
git checkout -b feature/pwm-control
```

------

## ✅ 建议工具 / 技术

| 工具                 | 用途                            |
| -------------------- | ------------------------------- |
| Git + GitHub / Gitea | 版本管理 + 协作                 |
| PlatformIO           | 比 Arduino IDE 更适合模块化开发 |
| Typora + Markdown    | 文档、版本说明编写              |
| VSCode               | 编辑器，可集成 PlatformIO       |

------

## 🧠 总结一句话：

> **“每一个新功能，都开一个分支；每一个稳定点，都打一个 tag。”**

------

## ❓你接下来可以做什么？

- ✅ 建立 `develop` 分支
- ✅ 把代码结构模块化：控制 / 通信 / 感应 分离
- ✅ 写 `README.md` + `changelog.md`
- ✅ 开始第一个 feature 分支

------

如果你告诉我你现在项目代码目录结构，我可以帮你一起整理优化并画出结构图；或者我可以直接帮你生成一个嵌入式项目模板（比如 ESP8266 + 温控 + WiFiManager + OTA 支持），你需要吗？

太棒了，你已经深入到了 **Git 发布流程的核心概念**：`release` 和 `tag` 的区别。这两个在 Git 里是密切相关但不一样的东西。下面我会用清晰实用的方式带你全面搞懂：

------

## ✅ 一、Tag 和 Release 的基本定义

### 🏷️ **Tag（标签）**

- Git 的**原生概念**，用于**给某个提交打标记**
- 记录“这个提交就是某个版本”，比如 `v1.0.0`
- 两种类型：
  - 轻量标签（lightweight tag）：只是一个名字指向某次提交
  - 注解标签（annotated tag）：带有作者、时间、说明、签名信息

📌 **创建 tag 的命令：**

```bash
git tag -a v1.0.0 -m "Release version 1.0.0"
git push origin v1.0.0
```

------

### 📦 **Release（发布）**

- **GitHub/GitLab 等平台的概念**，基于 Tag
- 是对某个 Tag 的一个**“可视化描述 + 附件打包”**
- 通常会上传二进制文件（如 `.bin`、`.hex`）给用户下载
- 用于产品上线/内部版本管理/测试发布

📌 **创建 Release 的方式（GitHub 上）：**

1. 打开 GitHub 项目
2. 点右上角 “Releases”
3. 点击 “Draft a new release”
4. 选择已有 tag 或新建一个
5. 填写标题、说明，上传编译好的固件
6. 发布！

------

## 🧠 二者区别总结

| 对比维度 | **Tag**                            | **Release**                          |
| -------- | ---------------------------------- | ------------------------------------ |
| 属于     | Git 原生概念                       | 平台功能（GitHub、Gitea、GitLab）    |
| 内容     | 版本号 + 提交记录（可选说明）      | Tag + 文档说明 + 下载附件            |
| 作用     | 供开发者标记版本节点               | 给使用者/测试人员发正式构建包        |
| 是否必须 | 必须（创建 release 要有 tag）      | 可选（你可以只打 tag，不写 release） |
| 用途     | 版本对比、还原、分支分离、构建追踪 | 下载、OTA 推送、CI 发布、版本页展示  |

------

## 🎯 实战操作流程（你该怎么做）

### 第一次发布版本：

```bash
# 创建版本标签
git tag -a v1.0.0 -m "Initial release of smart heating lamp"
git push origin v1.0.0
```

### 然后去 GitHub 创建 Release：

1. 打开你的项目仓库 → 点“Releases”
2. “Draft a new release”
3. Tag：选择 `v1.0.0`
4. Title：`Smart Heating Lamp v1.0.0`
5. Description：写上功能变更、注意事项等
6. 上传 `.bin` 或 `.hex` 固件文件（如有）
7. 点击 “Publish release”

------

## 🔁 后续新版本流程

1. 在 `develop` 分支开发新功能

2. 合并到 `main`，创建 tag：

   ```bash
   git tag -a v1.1.0 -m "Add timer and brightness control"
   git push origin v1.1.0
   ```

3. 到 GitHub 发布新 release，上传新的固件文件

------

## ✅ 小技巧：快速查看所有 tag

```bash
git tag
```

查看某个 tag 指向哪次提交：

```bash
git show v1.0.0
```

------

## 💡 总结一张图

```plaintext
Git Tag         →      标记某一次提交为版本点
                    ↘
                     GitHub Release（含固件 + changelog + 文档）
```

------

### 你现在要做的：

-  在当前项目中创建 `v1.0.0` 的 tag
-  推送 tag 到远程仓库
-  去 GitHub / Gitea 上发布你的第一个 release（可以加固件）
-  把版本说明写入 `CHANGELOG.md`

------

如果你需要我帮你写一段标准的 `CHANGELOG` 结构，或者提供发布脚本（自动打 tag、生成 release note），我也可以继续帮你生成 🙌





你说得很对 —— 在 GitHub 上的 **Release 页面、Tag 页面** 或 `CHANGELOG.md` 文档中，经常能看到：

> 🔗 某个版本链接到了某一个 **commit 提交记录**，你点击可以跳转到那个版本对应的提交详情页。

这其实是通过 **Git 标签（tag）和 commit ID 的绑定关系**实现的。

------

## ✅ 核心原理：Tag 就是指向某个 commit 的标记

当你执行这条命令时：

```bash
git tag -a v1.0.0 -m "First stable release"
```

Git 会在当前的提交（HEAD）上创建一个叫 `v1.0.0` 的 tag，并把它**和该 commit 绑定**。

然后你 push 到远程：

```bash
git push origin v1.0.0
```

GitHub 或 Gitea 就能识别出这个 tag 是指向哪个提交的，并自动显示链接，例如：

```
v1.0.0  →  ab34cfe: feat: 添加定时功能
```

你在 GitHub 的 Releases 页面或 Tag 页面点击 `v1.0.0`，就能跳转到那个提交（即 `commit/ab34cfe...`）。

------

## 🧩 在 changelog 中加链接的方法（可选）

如果你想在 `CHANGELOG.md` 手动添加这个链接，也可以这样写：

```markdown
## [v1.0.0] - 2025-07-13
[查看提交](https://github.com/<你的用户名>/<项目名>/commit/提交哈希)

- 初始版本发布
- 实现 WiFiManager 配网
```

或者写版本 diff 对比链接：

```markdown
[Compare changes](https://github.com/你的仓库/compare/v0.9.0...v1.0.0)
```

------

## 🔍 如何查看 tag 对应 commit 的链接？

你可以在终端运行：

```bash
git show v1.0.0
```

输出中你会看到：

```bash
commit ab34cfe...
Author: you
Date: ...

    Release version 1.0.0
```

这个 `ab34cfe` 就是 commit ID，GitHub 上的链接就是：

```
https://github.com/<用户名>/<项目名>/commit/ab34cfe
```

------

## ✅ 总结一句话

> **Git tag 是一个对某个具体提交（commit）的指针；你打 tag 后，GitHub 自动把它和那个 commit 关联并生成跳转链接。**

------

如果你希望我帮你自动生成 `CHANGELOG.md` 带提交链接的格式（比如用脚本），我也可以立刻生成给你。需要吗？