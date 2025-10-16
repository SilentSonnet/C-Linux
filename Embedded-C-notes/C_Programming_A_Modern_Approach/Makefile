# ===== 路径 =====
SRCDIR := code
BINDIR := bin
OBJDIR := $(BINDIR)/obj

# ===== 编译器与参数（macOS M1 默认 clang）=====
CC     := clang
CSTD   := -std=c11
WARN   := -Wall -Wextra -Wpedantic
DEBUG  := -g
CFLAGS := $(CSTD) $(WARN) $(DEBUG)
# 如需数学库（多数 Linux 需要），取消下一行注释；macOS一般不需要
# LDLIBS := -lm

# ===== 自动发现源码并生成功能名 =====
SOURCES   := $(wildcard $(SRCDIR)/*.c)
BASENAMES := $(patsubst $(SRCDIR)/%.c,%,$(SOURCES))

# 默认目标：帮助
.DEFAULT_GOAL := help
.PHONY: help
help:
	@echo "用法："
	@echo "  make <名字>     编译 code/<名字>.c -> bin/<名字>"
	@echo "  make run-<名>   编译并运行（如：make run-hello）"
	@echo "  make list       列出可编译的名字"
	@echo "  make clean      清理 bin/"
	@echo
	@echo "已检测到的源码：$(if $(BASENAMES),$(BASENAMES),<空>)"

# ===== 确保目录存在（分别各一条规则，避免重复）=====
$(BINDIR):
	@mkdir -p $(BINDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# ===== .c -> .o =====
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ===== .o -> 可执行文件 =====
$(BINDIR)/%: $(OBJDIR)/%.o | $(BINDIR)
	$(CC) $< -o $@ $(LDLIBS)
	@echo "生成：$@"

# ===== 便捷：允许直接 make foo 得到 bin/foo =====
.PHONY: $(BASENAMES)
$(BASENAMES): %: $(BINDIR)/%

# ===== 运行 =====
.PHONY: run-%
run-%: %   # 先编译
	@echo "运行：./$(BINDIR)/$*"
	@./$(BINDIR)/$*

# ===== 列表 & 清理 =====
.PHONY: list
list:
	@printf "%s\n" $(BASENAMES)

.PHONY: clean
clean:
	@rm -rf $(BINDIR)
	@echo "已清理 bin/"

