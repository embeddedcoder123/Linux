# FreeRTOS scheduling (single-core, AMP and SMP)
## 1. Default RTOS Scheduling (Single-Core)

FreeRTOS normally uses:

**✅ Fixed-priority preemptive with time slicing**

Let’s break that down:

- Fixed-priority: Each task has a set priority. The RTOS doesn’t change it (unless temporarily for special cases like priority inheritance).

- Preemptive: The RTOS always runs the highest priority task that’s ready. If a higher priority task becomes ready, it interrupts the currently running task.

- Round-robin (with time slicing): If two or more tasks have the same priority, they take turns running — each for a short time called a time slice.

- Time slice: This is the time between RTOS tick interrupts (like a regular clock tick). The scheduler uses it to switch between equal-priority tasks.

### Summary in terms of scheduling flow:

- Find the highest priority ready task(s).

- If only one task at highest priority, run it until it blocks, completes, or preempted.

- If multiple tasks share that priority, run them in a round-robin fashion using time slices.

- If a higher priority task becomes ready, preempt immediately, regardless of round-robin state.
- 
### ⚠️ Task Starvation

If a high-priority task is always running and never waits, lower priority tasks never get to run.

To avoid this, high-priority tasks should wait for events (go into Blocked state), rather than running in a loop.

When a task waits (Blocked), other lower-priority tasks get a chance to run.

### ⚙️  Configuration Options in FreeRTOSConfig.h
🔧 configUSE_PREEMPTION

- 1 (on): Preemption is enabled (default) – higher priority tasks can interrupt.

- 0 (off): Preemption is disabled – tasks run until they block, yield, or an interrupt forces a switch.

### 🔧 configUSE_TIME_SLICING

- 1 (on): Equal priority tasks take turns (round-robin).

- 0 (off): First task runs until it blocks or finishes — no automatic switching between equal-priority tasks.

## 💻 AMP – Asymmetric Multiprocessing

- Each core runs its own separate FreeRTOS instance.

- Cores do not need to be identical (they can have different CPUs).

- To communicate between cores, use shared memory (like message buffers or stream buffers).

- The scheduler on each core behaves just like single-core FreeRTOS.

## What is FreeRTOS SMP?

SMP (Symmetric Multiprocessing) means FreeRTOS runs on multiple CPU cores at the same time.

- There is only one FreeRTOS system running that controls all the cores.

- All cores use the same type of processor and share the same memory.

### How does SMP scheduling work?

- The FreeRTOS scheduler picks which task runs on each core.

- Unlike single-core systems where only one task runs at a time, with SMP, one task runs on each core simultaneously.

- For example, on a 2-core CPU with:

    - 1 high priority task

    - 2 medium priority tasks

- The scheduler will:

    - Run the high priority task on core 1.

    - Run one of the medium priority tasks on core 2.

So, a lower priority task can run at the same time as a higher priority task but on a different core.

### Why does this matter?

Some existing programs assume:

-  Only one task runs at a time, or

- A low priority task only runs if no higher priority task can run.

- With SMP, these assumptions are no longer true, because tasks of different priorities can run at the same time on different cores.

### How to adjust your system?

- Option 1: configRUN_MULTIPLE_PRIORITIES

If you set this to 0, FreeRTOS will only run multiple tasks simultaneously if they have the same priority.

This helps keep old programs working correctly but limits SMP’s full power.

- Option 2: configUSE_CORE_AFFINITY

If set to 1, you can assign specific tasks to run only on certain cores using vTaskCoreAffinitySet().

This helps prevent tasks that need to run in order from running at the same time on different cores.

### In short:

SMP allows multiple tasks to run at the same time on multiple cores.

Lower priority tasks can run alongside higher priority tasks on different cores.

Use settings to make sure your program works correctly if it expects only one task to run at a time or that low priority tasks only run after higher priority ones finish.



## RTOS Inter-Task Data Transfer Mechanisms

This document explains the different mechanisms available in RTOS (especially FreeRTOS) for inter-task data transfer. Each mechanism is described with its features, use cases, and comparison table.

---

 ✅ Mechanisms Overview

### 1. Queue
- Transfers fixed-size data between tasks using a FIFO structure.
- Supports multiple buffered messages.
- Can be used from both tasks and ISRs.
- Automatically manages memory and thread safety.

**Use Cases:**
- Sending sensor data from a producer task to a consumer task.
- Passing commands between controller and actuator tasks.
- Queuing messages from ISR to task (e.g., button press data).

---

### 2. Message Buffer
- Transfers variable-length messages.
- Each message includes a header indicating its length.
- More efficient than queues when message sizes vary.
- Not ISR-safe (cannot be used from interrupt context).

**Use Cases:**
- Sending log messages of varying sizes.
- Transmitting formatted data packets (e.g., network messages).
- Inter-task communication with structured but variable-length data.

---

### 3. Stream Buffer
- Transfers a stream of bytes without message boundaries.
- No headers — just raw byte flow.
- Suitable for real-time streaming or byte-by-byte data flow.
- Not ISR-safe.

**Use Cases:**
- Sending UART receive/transmit buffers.
- Streaming audio or video data between tasks.
- Continuous byte stream communication (like pipes).

---

### 4. Task Notification with Data
- Each task has a single 32-bit notification value.
- Can be used to send a signal or small piece of data.
- Very fast and lightweight — lowest overhead.
- Can be used from both tasks and ISRs.

**Use Cases:**
- Signaling a task from ISR (e.g., "data ready").
- Sending small counters, flags, or event IDs.
- One-to-one task signaling with minimal latency.

---

### 5. Shared Global Variable with Mutex
- Tasks share data using global variables.
- Access is protected using a Mutex or Critical Section.
- No copying or buffering — direct memory access.
- Must be carefully synchronized to avoid race conditions.

**Use Cases:**
- Sharing system status/configuration between tasks.
- Monitoring counters, flags, or real-time values.
- When data doesn't need queuing, just mutual access.

---

### 🔑 Key Differences

| Mechanism                 | Data Type     | Variable Length | ISR Safe | Buffered | Speed         | Best Use Case                            |
|--------------------------|---------------|-----------------|----------|----------|---------------|------------------------------------------|
| **Queue**                | Fixed-size     | ❌              | ✅       | ✅       | Medium         | General data passing (e.g., structs)     |
| **Message Buffer**       | Byte array     | ✅              | ❌       | ✅       | Fast           | Logs, packets, variable-length messages  |
| **Stream Buffer**        | Byte stream    | ✅              | ❌       | ✅       | Fast           | Streaming UART/audio                     |
| **Task Notification**    | 32-bit integer | ❌              | ✅       | ❌       | 🚀 Very Fast    | Signaling small data or flags            |
| **Global Variable + Mutex** | Any        | ✅              | ❌       | ❌       | Fast (manual)  | Shared state or flags                    |

---

### 📘 Summary: When to Use What

| Requirement                                 | Recommended Mechanism         | Example Use Case                                                  |
|--------------------------------------------|-------------------------------|-------------------------------------------------------------------|
| Need to send structured data items          | **Queue**                     | Sensor task sends readings to processing or logging task         |
| Need to send messages of different sizes    | **Message Buffer**            | Logging task sends logs of variable size to storage task         |
| Need to stream raw data continuously        | **Stream Buffer**             | UART receive task streams serial data to parser task             |
| Need to send quick flags or small data      | **Task Notification**         | ISR signals task that new data is available                      |
| Need to share common state/config between tasks | **Global Variable + Mutex** | Multiple tasks read/write shared system status/config flags      |

---

### 📌 Notes

- **Queues** are versatile but slightly heavier due to memory and copying.
- **Message Buffers** are ideal for flexible message sizes.
- **Stream Buffers** are best for raw, high-speed, continuous data.
- **Task Notifications** are fastest but limited to 32-bit value per task.
- **Global Variables with Mutex** give full control, but you manage safety.

---

