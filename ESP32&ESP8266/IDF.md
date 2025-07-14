# 1.事件组

事件组（Event Groups）是 FreeRTOS 提供的一种非常有用的同步机制，特别适用于多个任务之间的事件通知和协调。它可以用来管理不同模块的状态，通知其他模块某个特定的事件发生了。

### 1. 事件组的基本概念

事件组本质上是一个位标志的集合，每个事件组中的标志位代表一个独立的事件或状态。你可以通过 **`xEventGroupSetBits()`** 设置某个或多个标志位，通过 **`xEventGroupWaitBits()`** 等待某个或多个标志位被设置。

### 2. 事件组的基本操作

#### a) **创建事件组**

首先，需要创建一个事件组，通常在 `app_main()` 或任务初始化时创建。

```c
EventGroupHandle_t event_group;   // 事件组句柄

event_group = xEventGroupCreate();  // 创建事件组
```

#### b) **设置事件组的标志位**

通过 **`xEventGroupSetBits()`** 设置事件组中的一个或多个标志位。这些标志位一般表示模块的运行状态。

```c
xEventGroupSetBits(event_group, BIT_0);  // 设置第 0 位标志位，表示某个模块完成初始化
xEventGroupSetBits(event_group, BIT_1 | BIT_3);  // 设置第 1 和第 3 位标志位
```

#### c) **等待事件组中的标志位**

通过 **`xEventGroupWaitBits()`** 等待一个或多个标志位被设置。当标志位满足条件时，任务就可以继续执行。这常常用于任务之间的同步。

```c
EventBits_t bits = xEventGroupWaitBits(event_group, BIT_0 | BIT_1, pdTRUE, pdFALSE, portMAX_DELAY);
if (bits & BIT_0) {
    // 如果第0位被设置，执行相关操作
}

if (bits & BIT_1) {
    // 如果第1位被设置，执行其他操作
}
```

#### d) **清除事件组的标志位**

通过 **`xEventGroupClearBits()`** 可以清除事件组中的一个或多个标志位，通常用于通知任务一个事件已经处理完。

```c
xEventGroupClearBits(event_group, BIT_0);  // 清除第 0 位标志
```

### 3. 事件组的用法举例

假设你有一个系统，包含多个模块（如 Wi-Fi 模块、MQTT 模块、传感器模块等）。你可以通过事件组来监听各个模块的状态，确保它们都已正常启动或工作。

#### 示例代码：多个模块状态监听

```c
// 事件组句柄
EventGroupHandle_t system_event_group;

// 定义事件标志位，表示不同模块的状态
#define WIFI_CONNECTED_BIT      (1 << 0)   // Wi-Fi 连接成功
#define MQTT_CONNECTED_BIT      (1 << 1)   // MQTT 连接成功
#define SENSOR_READY_BIT        (1 << 2)   // 传感器初始化完成

void wifi_event_handler(WIFI_EV_e ev) {
    if (ev == WIFI_CONNECTED) {
        // Wi-Fi 连接成功
        xEventGroupSetBits(system_event_group, WIFI_CONNECTED_BIT);
    }
}

void mqtt_event_handler(MQTT_EV_e ev) {
    if (ev == MQTT_CONNECTED) {
        // MQTT 连接成功
        xEventGroupSetBits(system_event_group, MQTT_CONNECTED_BIT);
    }
}

void sensor_event_handler(SENSOR_EV_e ev) {
    if (ev == SENSOR_READY) {
        // 传感器初始化完成
        xEventGroupSetBits(system_event_group, SENSOR_READY_BIT);
    }
}

void app_main(void) {
    // 创建事件组
    system_event_group = xEventGroupCreate();

    // 初始化 Wi-Fi 模块并设置事件回调
    wifi_sta_init(wifi_event_handler);

    // 初始化 MQTT 模块并设置事件回调
    mqtt_init(mqtt_event_handler);

    // 初始化传感器模块并设置事件回调
    sensor_init(sensor_event_handler);

    // 等待所有模块都已完成初始化
    EventBits_t ev = xEventGroupWaitBits(system_event_group,
                                          WIFI_CONNECTED_BIT | MQTT_CONNECTED_BIT | SENSOR_READY_BIT,
                                          pdTRUE,   // 清除已设置的位
                                          pdFALSE,  // 不等待所有标志位
                                          portMAX_DELAY);  // 无限等待

    if ((ev & (WIFI_CONNECTED_BIT | MQTT_CONNECTED_BIT | SENSOR_READY_BIT)) == (WIFI_CONNECTED_BIT | MQTT_CONNECTED_BIT | SENSOR_READY_BIT)) {
        // 所有模块都已初始化完成，系统可以开始执行应用层任务
        ESP_LOGI("System", "All modules are initialized and ready.");
    }

    // 执行应用层任务
    while (1) {
        // 执行其他操作
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
```

### 4. 事件组的详细解释

#### 事件组的工作流程：

1. **创建事件组**：调用 `xEventGroupCreate()` 创建一个事件组，返回一个事件组的句柄。
2. **设置事件标志位**：各个模块可以通过 `xEventGroupSetBits()` 设置自己的标志位，表示模块状态。
3. **等待事件**：主任务或其他任务可以通过 `xEventGroupWaitBits()` 等待一个或多个标志位的设置，确保在所有模块完成初始化后再开始执行后续任务。
4. **执行操作**：一旦所有模块都完成初始化，事件组中相应的标志位会被设置，主任务可以继续执行。

#### 使用 `xEventGroupWaitBits` 时需要注意：

- `pdTRUE`：表示等待时如果标志位已经被设置，则会自动清除该位。
- `pdFALSE`：表示等待时标志位不会被清除，适用于你希望标志位一直保持设置状态的情况。
- `portMAX_DELAY`：表示一直等待直到满足条件。

#### 为什么要使用事件组：

- 事件组提供了一种非常简洁且高效的方式来进行任务间同步。
- 当有多个任务依赖于不同模块的状态时，事件组可以帮助任务确保在所有必要条件满足之后再执行。
- 通过事件组，你可以避免任务过早地执行某些操作（例如启动 MQTT 客户端之前确保 Wi-Fi 已经连接），从而提高系统的稳定性。

### 5. 结论

通过事件组，ESP-IDF 可以非常高效地实现多个模块之间的事件通知与同步。你可以利用事件组来监听各个模块的状态（如 Wi-Fi 连接、MQTT 连接、传感器准备就绪等），然后在系统完全准备好之后开始执行应用层的任务。这样，不同模块之间的依赖关系和顺序执行问题就能得到很好的解决。

# 2.回调函数

好的，我会详细讲解在 **ESP-IDF** 中，如何使用 **回调函数** 来处理异步事件，并且在其中注册、触发、调用回调函数的完整流程。

### 什么是回调函数？

回调函数（Callback Function）是一种设计模式，通常是在某个事件发生时，由程序的另一个部分调用的函数。回调函数通常由开发者定义，并在特定的条件下通过某些机制自动执行。

在 **ESP-IDF** 中，回调函数常用于处理 **事件通知**，比如 Wi-Fi 连接状态变化、MQTT 消息接收、传感器数据读取等。

### 回调函数的流程概述

1. **回调函数的定义**：你首先定义一个回调函数，它将接收某些参数，并执行特定的操作。
2. **回调函数的注册**：你将回调函数注册到某个事件源（例如，Wi-Fi、MQTT、DS18B20 传感器等），这样当事件发生时，该回调函数会被调用。
3. **事件的触发**：当事件发生时，事件源会触发相应的回调函数。
4. **回调函数的调用**：事件源会根据事件的不同，传递不同的参数给回调函数，并由回调函数来处理这些事件数据。

### 举个例子：Wi-Fi 事件回调

ESP-IDF 中的 **Wi-Fi** 事件处理就是一个典型的回调机制。下面我们详细讲解每一步如何使用回调函数。

------

### 1. **回调函数的定义**

回调函数是由你来定义的，并且这个函数应该能够接受事件相关的参数。比如，Wi-Fi 事件的回调函数应该能够接受一个 Wi-Fi 事件信息结构体。

```c
// 定义回调函数类型
static void wifi_event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT) {
        switch (event_id) {
            case WIFI_EVENT_STA_START:
                ESP_LOGI(TAG, "Wi-Fi STA mode started");
                break;
            case WIFI_EVENT_STA_CONNECTED:
                ESP_LOGI(TAG, "Connected to Wi-Fi AP");
                break;
            case WIFI_EVENT_STA_DISCONNECTED:
                ESP_LOGI(TAG, "Disconnected from Wi-Fi AP");
                break;
            default:
                break;
        }
    }
}
```

- `event_base` 用来区分事件类别，这里是 `WIFI_EVENT`，表示 Wi-Fi 相关事件。
- `event_id` 是事件的具体类型，例如 `WIFI_EVENT_STA_START` 是 Wi-Fi STA 模式启动的事件。
- `event_data` 是事件的附加数据（有时是结构体或数据，可以通过它获取更多信息）。

### 2. **回调函数的注册**

回调函数定义好后，我们需要将它注册到 ESP-IDF 的事件系统中。这里我们用 `esp_event_handler_register` 来注册 Wi-Fi 事件回调函数。

```c
void app_main(void)
{
    // 初始化 NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    // 注册 Wi-Fi 事件回调函数
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL));

    // 初始化 Wi-Fi
    wifi_init_sta();
}
```

- `esp_event_handler_register` 的第一个参数是事件类别（在这里是 `WIFI_EVENT`）。
- 第二个参数是事件 ID（`ESP_EVENT_ANY_ID` 表示处理所有 Wi-Fi 事件，当然也可以指定具体事件）。
- 第三个参数是你定义的回调函数（这里是 `wifi_event_handler`）。
- 第四个参数是你可以传递给回调函数的用户数据（`NULL` 表示不传递任何数据）。

### 3. **事件的触发**

当 Wi-Fi 事件发生时（比如 Wi-Fi 启动、连接、断开等），ESP-IDF 会自动触发相应的回调函数。比如，Wi-Fi 连接成功时，Wi-Fi 模块会自动通知事件系统，系统会调用你之前注册的回调函数。

```c
// Wi-Fi 连接成功时，内部会触发 WIFI_EVENT_STA_CONNECTED 事件
esp_wifi_connect();
```

### 4. **回调函数的调用**

当事件触发时，事件系统会根据你注册的事件类型调用回调函数，并传递相关的事件数据。例如，当 Wi-Fi 连接成功时，回调函数会打印 `Connected to Wi-Fi AP`，当发生断开连接时，回调函数会打印 `Disconnected from Wi-Fi AP`。

------

### 回调机制扩展：模块化设计

你可以根据这种方式为其他模块（如传感器、MQTT、硬件中断等）设计回调函数，并通过事件通知机制来解耦不同模块之间的依赖。

### 示例：DS18B20 温度传感器的回调

假设你有一个温度传感器（如 DS18B20），它通过事件通知系统向外部报告温度更新。你可以这样定义回调和注册事件。

```c
// DS18B20 事件类别和事件 ID
#define DS18B20_EVENT_BASE "DS18B20_EVENT"
#define DS18B20_EVENT_TEMP_UPDATED 0x01

// 回调函数
typedef void (*ds18b20_event_cb)(int event_id, void* event_data);

// 回调函数实例
static ds18b20_event_cb ds18b20_cb = NULL;

/**
 * DS18B20 事件处理函数
 */
static void ds18b20_event_handler(int event_id, void* event_data)
{
    if (event_id == DS18B20_EVENT_TEMP_UPDATED) {
        float temperature = *((float*)event_data);
        ESP_LOGI(TAG, "Temperature updated: %.2f°C", temperature);
    }
}

/**
 * 初始化 DS18B20 并注册事件回调
 */
void ds18b20_init(ds18b20_event_cb callback)
{
    ds18b20_cb = callback;
    // 在此处进行 DS18B20 的硬件初始化
}

/**
 * 模拟温度更新事件触发
 */
void ds18b20_temperature_updated(float temperature)
{
    if (ds18b20_cb) {
        ds18b20_cb(DS18B20_EVENT_TEMP_UPDATED, &temperature);
    }
}

void app_main(void)
{
    // 初始化 DS18B20 并注册回调函数
    ds18b20_init(ds18b20_event_handler);

    // 模拟温度更新
    float new_temperature = 25.3;
    ds18b20_temperature_updated(new_temperature);
}
```

### 总结

1. **回调函数定义**：你定义回调函数时，需要考虑它的参数和返回类型，确保它能够正确处理事件数据。
2. **回调函数注册**：通过 `esp_event_handler_register` 等方式将回调函数注册到事件源（例如 Wi-Fi、MQTT 或自定义事件）。
3. **事件触发**：当事件发生时，事件源会自动调用已经注册的回调函数，并传递事件数据。
4. **回调函数执行**：回调函数会根据事件数据来执行特定的操作，例如打印日志、更新状态、处理错误等。

通过事件和回调机制，你可以将系统中的不同模块解耦，异步响应各种事件，大大提升系统的灵活性和可扩展性。





你写的 `Kconfig` 菜单配置看起来是正确的，但它**没有显示在 `menuconfig` 中**，可能是因为 **Kconfig 文件没有被 CMake 构建系统识别或关联**。下面是几种常见原因和解决方式：

### ✅ 1. `Kconfig` 文件要位于一个 **有效组件目录** 下

放在“根目录”是不够的，ESP-IDF 的构建系统只会自动加载以下路径下的 `Kconfig`：

- `main/Kconfig`
- `components/你的组件/Kconfig`

📌 **解决：**

- 把你的 `Kconfig` 文件放进某个有效组件目录，比如：

```
SmartLight-ESP32/
├── components/
│   └── Middlewares/
│       └── SNTP/
│           ├── Kconfig         ✅ 放这里
│           ├── CMakeLists.txt
│           └── sntp.c
```

------

### ✅ 2. 组件的 `CMakeLists.txt` 要包含：

```cmake
idf_component_register(SRCS "sntp.c"
                       INCLUDE_DIRS ".")
```

如果你的组件目录是自定义的（例如 `components/Middlewares/SNTP`），你还需要在项目的顶层 `CMakeLists.txt` 中添加：

```cmake
set(EXTRA_COMPONENT_DIRS components/Middlewares/SNTP)
```

或者更合理地添加：

```cmake
set(EXTRA_COMPONENT_DIRS components/Middlewares)
```

ESP-IDF 会自动递归进去找组件。

------

### ✅ 3. `Kconfig` 要通过 `Kconfig.projbuild` 引入到 `menuconfig`

在你组件目录下添加一个 `Kconfig.projbuild` 文件，并写入：

```kconfig
source "$COMPONENT_DIR/Kconfig"
```

这样它才会被 `menuconfig` 系统包含进来。

------

### ✅ 4. 文件命名要精确，不能写错

检查你是否用了错误的大小写或拼写，例如：

| 正确文件名          | 作用                               |
| ------------------- | ---------------------------------- |
| `Kconfig`           | 定义组件内的配置项                 |
| `Kconfig.projbuild` | 把组件的 `Kconfig` 引入 menuconfig |

------

## ✅ 最终结构参考（推荐做法）

```
SmartLight-ESP32/
├── main/
│   ├── main.c
│   └── CMakeLists.txt
├── components/
│   └── Middlewares/
│       └── SNTP/
│           ├── Kconfig
│           ├── Kconfig.projbuild
│           ├── sntp.c
│           └── CMakeLists.txt
├── CMakeLists.txt
└── sdkconfig
```

------

### 🧪 完成后运行：

```bash
idf.py menuconfig
```

然后你应该能看到：

```
Example Configuration  --->
  (pool.ntp.org) SNTP server name
  [*] update time immediately when received
```

------

如果你依然看不到，请贴出：

- `Kconfig` 的路径
- `Kconfig.projbuild` 内容
- 项目结构
   我可以帮你快速检查。