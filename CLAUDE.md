# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 项目概述

基于 Qt 6 Widgets 的桌面应用。项目名为 `opencv_invoke`，但代码中并未引入 OpenCV——相机枚举走 Qt Multimedia（`QMediaDevices` / `QCameraDevice`）。功能为「账号登录/注册 → 相机控制台」：无边框主窗口内用 `setCentralWidget()` 在登录、注册、找回密码、控制台四个页面间切换；控制台用 `QMdiArea` 管理多相机预览子窗口。

## 构建与运行

- 环境：Qt 6.9.2 + MinGW 64-bit，构建系统 CMake + Ninja（由 Qt Creator 生成，非手写）。
- 现有构建目录：`build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug`。
- 命令行增量构建：`cmake --build build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug`
- 无自动化测试、无 lint 配置；UI 行为靠运行程序手动确认。

## 架构

### 页面切换（核心导航机制）

`MainWindow`（QMainWindow）是唯一导航中枢。不用 QStackedWidget，而是 `setCentralWidget()` + `deleteLater()` 在以下页面间切换，每切一次就 new 新实例、销毁旧实例（见 `mainwindow.cpp` 的 `SlotSwitch*` 槽）：

- `Loding` 登录页 → 发出 `switchReg` / `switchGet` / `switchCtr`
- `RegFrom` 注册页 → `switchLog`
- `ForgetFrom` 找回密码页 → `switchLog`
- `CtrForm` 控制台 → `SwitchAcount`（目前为空槽）

页面之间完全靠 Qt signal/slot 解耦。

### 相机控制台

- `CtrForm` 用 `QMediaDevices::videoInputs()` 枚举摄像头，填入自定义控件 `MultiSelectComboBox`。
- 勾选摄像头触发 `invokeMdi(QString, bool)` → `CtrForm::createMdi`，在 `QMdiArea` 内按相机名创建/删除 `Form` 子窗口，用 `QMap<QString, QMdiSubWindow*>` 记录映射。
- `Form` 目前是相机预览占位 widget，尚未接入真实视频流。

### 自定义控件

- `MultiSelectComboBox`：基于 QComboBox + QListWidget(QCheckBox) 的多选下拉框，带搜索过滤。`QCheckBox::toggled` 被转成 `invokeMdi` 信号。
- `CheckableCombox`：空壳（仅构造函数），未使用。

### 基础设施

- `Singleton<T>`（CRTP，`Singleton.h`）：`static T& getInstance()` 局部静态实现。
- `ThreadPoll`：基于 `std::packaged_task` / `std::queue` / `condition_variable` 的模板线程池单例，`post(f, args...)` 返回 `std::future`。
- `HttpServer`：`QObject` + `Singleton` 单例，当前为空壳，预留给登录/注册 HTTP 请求（`loding.cpp`、`regfrom.cpp` 中的 `//http请求` 注释处尚未实现）。
- `account`：空壳类。

## 注意事项 / 坑

- **硬编码绝对路径**：`main.cpp`（logo.png）、`titelicon.cpp`（title.png）、`loding.cpp`（壁纸.jpg）写死了 `E:\...` 路径，换机器即失效。
- **.ui 是 UI 主定义**：布局与控件在 `.ui` 文件；槽函数沿用 Qt 自动连接命名 `on_<objectName>_<signal>`。
- **CMakeLists 有冗余**：`find_package(Qt6 ... Core)` 与 `target_link_libraries(... Qt6::Core)` 各重复 3 次，属历史遗留，可清理。
- **build/ 被 git 追踪**：`build/` 下大量生成文件已提交，`.gitignore` 的 `/build*/` 对已追踪文件不生效。
- 国际化：翻译文件 `opencv_invoke_en_AS.ts` 由 `qt_add_translations` 生成，`main.cpp` 运行时按系统语言加载。
