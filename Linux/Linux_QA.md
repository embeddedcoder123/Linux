- [Linux](#linux)
  - [1. Process Scheduling](#1-process-scheduling)
    - [1. How Does the Linux Kernel Handle Process Scheduling?](#1-how-does-the-linux-kernel-handle-process-scheduling)
    - [2. Completely Fair Scheduler (CFS)](#2-completely-fair-scheduler-cfs)
    - [3. How Are Scheduling Classes Prioritized?](#3-how-are-scheduling-classes-prioritized)
    - [4. What are Runqueues and How Are They Managed?](#4-what-are-runqueues-and-how-are-they-managed)
      - [5. How Does Kernel Handle Real-Time Scheduling?](#5-how-does-kernel-handle-real-time-scheduling)
  - [2. 📚 Memory Management](#2--memory-management)
    - [Physical vs. Virtual Memory](#physical-vs-virtual-memory)
    - [Page](#page)
    - [📐 **Memory Layout**](#-memory-layout)
    - [Kernel Address Space](#kernel-address-space)
    - [🔍 Paging and Address Translation](#-paging-and-address-translation)
    - [🧩 Memory Zones](#-memory-zones)
    - [🧠 Memory Allocators](#-memory-allocators)
      - [kmalloc vs vmalloc](#kmalloc-vs-vmalloc)
    - [🧹 Memory Reclaim](#-memory-reclaim)
      - [Page Types](#page-types)
    - [💾 Swapping and OOM Handling](#-swapping-and-oom-handling)
      - [🧠 Advanced Concepts](#-advanced-concepts)
    - [🧰 Debugging \& Monitoring Tools](#-debugging--monitoring-tools)
    - [🧪 Interview Questions – Linux Memory Management](#-interview-questions--linux-memory-management)
    - [🧠 Summary](#-summary)
- [Device Driver](#device-driver)
  - [1. Explain the difference between a character device and a block device in Linux.](#1-explain-the-difference-between-a-character-device-and-a-block-device-in-linux)
  - [2. What happens during insmod of a kernel module?](#2-what-happens-during-insmod-of-a-kernel-module)
  - [3. What are major and minor numbers in device drivers?](#3-what-are-major-and-minor-numbers-in-device-drivers)
  - [4. How do you handle concurrency in device drivers?](#4-how-do-you-handle-concurrency-in-device-drivers)
  - [5. What is the role of ioctl() in device drivers?](#5-what-is-the-role-of-ioctl-in-device-drivers)
  - [6. What is the difference between kmalloc() and vmalloc()?](#6-what-is-the-difference-between-kmalloc-and-vmalloc)
  - [7. How do you handle hardware interrupts in Linux kernel drivers?](#7-how-do-you-handle-hardware-interrupts-in-linux-kernel-drivers)
  - [8. What is the purpose of probe() and remove() in platform drivers?](#8-what-is-the-purpose-of-probe-and-remove-in-platform-drivers)
  - [9. What are the key considerations for writing a DMA-capable device driver?](#9-what-are-the-key-considerations-for-writing-a-dma-capable-device-driver)
  - [10. How would you debug a kernel driver crash (e.g., kernel panic)?](#10-how-would-you-debug-a-kernel-driver-crash-eg-kernel-panic)
  - [11. How to Make Your Kernel Module Load Automatically on Boot — Simplified Explanation](#11-how-to-make-your-kernel-module-load-automatically-on-boot--simplified-explanation)
    - [Step 1: Copy your .ko file into the right folder](#step-1-copy-your-ko-file-into-the-right-folder)
    - [Step 2: Run depmod -a](#step-2-run-depmod--a)
    - [Step 3: Add your module name to /etc/modules](#step-3-add-your-module-name-to-etcmodules)
    - [Step 4: Reboot your Raspberry Pi](#step-4-reboot-your-raspberry-pi)
  - [You reboot your system.](#you-reboot-your-system)
- [YOCTO](#yocto)

# Linux
## 1. Process Scheduling
### 1. How Does the Linux Kernel Handle Process Scheduling?
Process scheduling in Linux is the mechanism that decides which process runs on the CPU at any given time. The Linux kernel scheduler manages CPU time among multiple runnable processes to ensure fairness, efficiency, and responsiveness.

Key goals of the scheduler:
- Maximize CPU utilization.
- Provide fairness to all processes.
- Meet real-time requirements for time-critical tasks.
- Provide responsiveness for interactive tasks.

Linux uses a preemptive multitasking approach, where the scheduler interrupts running tasks to allocate CPU time to others, based on scheduling policies.

### 2. Completely Fair Scheduler (CFS)
**Overview**

The Completely Fair Scheduler (CFS) is the default scheduler for normal (non-real-time) processes in Linux since kernel 2.6.23 (around 2007).

Its main idea is to allocate CPU time fairly among all runnable processes, proportional to their priority, in a way that mimics an ideal, precise multitasking CPU sharing system.

**Design Principles of CFS**
  - **Fairness by Virtual Runtime (vruntime):**
  > CFS keeps track of how much CPU time each process has gotten, represented as virtual runtime (vruntime). Processes that have used less CPU time get higher priority to run next.

  - **Red-Black Tree Data Structure:**
  > All runnable tasks are stored in a balanced binary tree (a red-black tree) sorted by vruntime. The leftmost node in this tree is the process with the smallest vruntime and is chosen to run next.

  - **No Fixed Time Slices:**
  > Instead of fixed time slices, each process runs until its vruntime becomes greater than the vruntime of the next task in the tree. This makes the scheduler "completely fair," as every task gets CPU proportional to its weight (priority).

  - **Weight-Based Fairness:**
  > Process priority is translated into a weight (nice value affects weight). Higher priority processes get a larger share of CPU time.

  **Preemption and Load Balancing:**
  > The scheduler can preempt tasks to ensure fairness and also migrates tasks across CPUs for balanced workload.

**How CFS Works Step-by-Step**
- **Tracking vruntime:**
> Every process’s vruntime increases as it consumes CPU, weighted by priority.

**Selecting next task:**
> The scheduler picks the task with the smallest vruntime from the runqueue tree.

**Running the task:**
> The selected task runs until its vruntime surpasses another task’s vruntime, then the scheduler picks a new task.

**Inserting and removing tasks:**
> When a task becomes runnable, it’s inserted into the red-black tree at the correct position based on vruntime.

**Why CFS is “Completely Fair”**
> The vruntime ensures each task gets a fair proportion of CPU over time, with no fixed time slices that might cause unfairness or starvation.

### 3. How Are Scheduling Classes Prioritized?

The Linux kernel organizes processes into scheduling classes, which define different scheduling policies and priorities. The kernel always selects tasks from the highest-priority scheduling class that has runnable tasks.

The main scheduling classes, in priority order, are:
| Scheduling Class          | Description                                      | Priority (Higher to Lower) |
| ------------------------- | ------------------------------------------------ | -------------------------- |
| **Real-time (RT) class**  | For real-time tasks using FIFO or RR policy      | Highest priority           |
| **Fair Scheduling (CFS)** | Normal processes using Completely Fair Scheduler | Medium priority            |
| **Idle class**            | Runs only when no other task is runnable         | Lowest priority            |

- The Real-time class always preempts normal tasks.
- The CFS class is the default for normal processes.
- The Idle class runs when nothing else can run.

Within each class, scheduling decisions are made according to that class’s algorithm.

### 4. What are Runqueues and How Are They Managed?
**Runqueue Definition**

A `runqueue` is a data structure representing the set of runnable processes on a CPU. Since Linux supports `SMP` (Symmetric MultiProcessing), each CPU has its own runqueue to reduce contention and improve performance.

**Runqueue Structure**
- **Per-CPU runqueues:**
Each CPU maintains its own runqueue with all runnable tasks assigned to that CPU.

- **Runqueue Contents:**
Contains task lists or trees for different scheduling classes. For example, for the CFS class, the runqueue includes the red-black tree of runnable processes.

- **Load Information:**
Runqueue tracks load metrics, like the number of tasks, cumulative CPU load, etc., which help with load balancing.

**Runqueue Management**
- **Task Insertion:**
When a process becomes runnable, it is inserted into the runqueue’s data structure (e.g., red-black tree for CFS).

- **Task Selection:**
The scheduler picks the next task to run from the runqueue by applying scheduling class priorities and picking the task with the minimum vruntime (for CFS).

- **Load Balancing:**
Periodically, tasks may be migrated between CPUs’ runqueues to balance load.

#### 5. How Does Kernel Handle Real-Time Scheduling?
**Real-Time Scheduling Classes**
Linux supports two real-time scheduling policies:

- **SCHED_FIFO (First-In, First-Out)**:
Real-time tasks run until they block, voluntarily yield, or are preempted by a higher priority real-time task. No time slicing.

- **SCHED_RR (Round-Robin)**:
Like FIFO but with fixed time slices. Tasks of the same priority time-slice in a round-robin manner.

**Priority and Preemption**
- Real-time tasks have static priorities (usually 1 to 99, higher number = higher priority).
- Real-time tasks always have higher priority than normal (CFS) tasks.
- Scheduler preempts normal tasks immediately if a real-time task becomes runnable.
- Among real-time tasks, highest priority runs first; if multiple at the same priority in RR policy, time slices rotate.

**Real-Time Scheduling Implementation**
- Real-time tasks are stored in their own runqueue list inside the runqueue.
- Scheduler picks the highest-priority real-time task before normal tasks.
- Real-time tasks can cause priority inversion problems; kernel uses mechanisms like priority inheritance in mutexes to mitigate this.

**Real-Time Constraints**
- Designed to guarantee CPU access for critical tasks.
- Used in embedded systems, multimedia, or control applications where timing is crucial.
---
**Summary**
| Aspect                          | Description                                                                                    |
| ------------------------------- | ---------------------------------------------------------------------------------------------- |
| **Linux Process Scheduling**    | Decides which process runs on CPU to maximize utilization, fairness, responsiveness, real-time |
| **Completely Fair Scheduler**   | Uses vruntime and red-black tree to allocate CPU fairly, proportional to task priority         |
| **Scheduling Classes Priority** | Real-time (highest), CFS (normal), Idle (lowest)                                               |
| **Runqueues**                   | Per-CPU data structure with runnable tasks, managed by scheduling class priority               |
| **Real-Time Scheduling**        | SCHED\_FIFO and SCHED\_RR policies with strict priorities, preempt normal tasks                |

---
## 2. 📚 Memory Management

###  Physical vs. Virtual Memory

- **Physical memory** is actual RAM installed on the system.
- **Virtual memory** is an abstraction: each process thinks it has access to a large, private address space.
- The kernel uses **page tables** to map virtual addresses to physical memory.

### Page

- **Page** = Smallest unit of memory management (usually 4KB).
- Every page has metadata stored in a `struct page`.
- Linux uses multi-level page tables to manage virtual memory efficiently.

---

### 📐 **Memory Layout**

Process Address Space

For a user process:
```
High Address
    ↓
+-------------------------+  <-- VDSO / VVAR  
|  VDSO/VVAR: Kernel-     |  
|  provided shared areas  |  
|  for fast syscalls &    |  
|  kernel info            |  
+-------------------------+  
|  Stack: Function calls, |  
|  local variables,       |  
|  grows downward         |  
+-------------------------+  
|  mmap Area: Memory-     |  
|  mapped files &         |  
|  libraries              |  
+-------------------------+  
|  Heap: Dynamic memory   |  
|  allocation (malloc),   |  
|  grows upward           |  
+-------------------------+  
|  BSS: Uninitialized     |  
|  global/static vars,    |  
|  zero-initialized       |  
+-------------------------+  
|  Data: Initialized      |  
|  global/static vars     |  
+-------------------------+  
|  Text: Program code     |  
+-------------------------+  
    ↑
Low Address
```
###  Kernel Address Space

- The kernel space is shared among all processes but protected.
- Layout differs between **32-bit** and **64-bit** architectures.

---

### 🔍 Paging and Address Translation

Multi-Level Page Tables (x86_64)

- 4-level hierarchy:
  - **PGD** → **P4D** → **PUD** → **PMD** → **PTE**
- Each level is a table of 512 entries (9 bits per level).

3.2 TLB (Translation Lookaside Buffer)

- A cache for page table lookups.
- Kernel uses **TLB shootdowns** in SMP systems to update TLBs coherently across CPUs.

---

### 🧩 Memory Zones

Linux divides physical memory into **zones** to manage hardware constraints:

| Zone    | Purpose                                                     |
|---------|-------------------------------------------------------------|
| `ZONE_DMA`     | Legacy devices needing <16MB physical memory         |
| `ZONE_DMA32`   | 32-bit DMA-capable devices on 64-bit systems         |
| `ZONE_NORMAL`  | Regular RAM accessible by kernel                     |
| `ZONE_HIGHMEM` | Only on 32-bit systems for memory >896MB             |
| `ZONE_MOVABLE` | For memory that can be reclaimed or moved            |

> Each zone has its own free page lists, watermarks, and statistics.

---

### 🧠 Memory Allocators

Buddy Allocator

- Handles **page-level** allocations (order 0–10).
- Works by splitting or merging blocks of power-of-two pages.

Slab Allocator (Slab / SLUB / SLOB)

- Manages **object-level** memory.
- Caches frequently used kernel objects (e.g., inodes, dentries).
- Reduces fragmentation and improves cache locality.

#### kmalloc vs vmalloc

| Allocator | Contiguity | Usage                           |
|-----------|------------|----------------------------------|
| kmalloc   | Physically contiguous | Fast; preferred for drivers |
| vmalloc   | Virtually contiguous | Slower; used for large memory needs |

---

### 🧹 Memory Reclaim

Page Reclaim Mechanisms

- **kswapd**: Background daemon that reclaims memory when below watermarks.
- **Direct reclaim**: Called by processes when allocations fail.
- **Shrinkers**: Subsystem-specific memory cleanup (e.g., inode cache).
- **Compaction**: Moves pages to create contiguous free memory blocks.

#### Page Types

| Type            | Reclaimable | Notes |
|------------------|-------------|-------|
| File Cache       | ✅          | Clean pages can be dropped immediately |
| Anonymous Memory | ⚠️          | Swappable if not active                |
| Dirty Pages      | ❌ (until writeback) | Must be written to disk first     |

---

### 💾 Swapping and OOM Handling

Swap Space

- Used for inactive anonymous pages.
- Controlled by `swappiness` (default: 60).
- Pages moved to swap can be paged back in when accessed.

OOM Killer

- Triggered when reclaim fails and memory is exhausted.
- Kills the "least useful" process based on `oom_score`.

---

#### 🧠 Advanced Concepts

NUMA (Non-Uniform Memory Access)

- Memory is divided into **nodes**, one per CPU socket.
- Accessing local memory is faster than remote.
- Kernel tries to allocate memory near the accessing CPU.

Transparent Huge Pages (THP)

- Uses 2MB pages to reduce TLB misses.
- Enabled by default on most systems, but may cause latency spikes.

Memory Cgroups

- Used in containers for memory accounting and limits.
- Supports soft/hard limits, reclaim strategies, and OOM control.

---

### 🧰 Debugging & Monitoring Tools

| Tool           | Usage                                      |
|----------------|--------------------------------------------|
| `free`         | Shows RAM and swap usage                   |
| `top`, `htop`  | Real-time process and memory stats         |
| `vmstat`       | Paging, reclaim, I/O stats                 |
| `slabtop`      | Kernel object cache usage                  |
| `cat /proc/meminfo` | Detailed memory state                |
| `perf`, `ftrace`, `ebpf` | In-depth performance analysis     |

---

### 🧪 Interview Questions – Linux Memory Management

**Basics**

1. **What is the difference between physical and virtual memory?**
2. **How does the kernel map virtual to physical addresses?**
3. **What are memory zones and why do they exist?**

**🔬 Intermediate**

4. **Explain the role of the slab allocator.**
5. **What’s the difference between `kmalloc` and `vmalloc`?**
6. **How does demand paging work in Linux?**
7. **What happens during a page fault?**

**🧠 Advanced**

8. **How does the OOM killer choose a process to kill?**
9. **Explain TLB shootdowns and their role in multiprocessor systems.**
10. **How does the kernel reclaim memory under pressure?**
11. **What is memory compaction, and when is it used?**
12. **How do Transparent Huge Pages improve performance, and when can they hurt it?**
13. **How does NUMA-aware memory allocation work in Linux?**

---

### 🧠 Summary

- Linux uses paging, demand allocation, and reclamation to efficiently manage memory.
- It handles physical limitations (zones), performance (slabs, hugepages), and safety (COW, OOM killer).
- Understanding these mechanisms is crucial for kernel development, performance tuning, and system troubleshooting.

---


# Device Driver
## 1. Explain the difference between a character device and a block device in Linux.
**Answer:**
- A character device is accessed as a stream of bytes (like `/dev/tty` or `/dev/null`). It supports sequential access and uses file_operations like `read()`, `write()`, and `ioctl()`.
- A block device, like `/dev/sda`, allows random access to fixed-size blocks, supports buffering and caching via the page cache, and uses interfaces like request_queue and bio.

- Character devices are registered using `cdev`, while block devices require setting up a `gendisk` and `request queue`.

## 2. What happens during insmod of a kernel module?
**Answer:**
When insmod is executed:
- The kernel allocates memory and loads the module binary into kernel space.
- It resolves symbol dependencies with the kernel or other loaded modules.
- The module’s init_module() or __init function (usually module_init()) is called to initialize resources (register device, allocate memory, etc.).
- If initialization fails, cleanup is done and the module is not inserted.
- The kernel logs this process via dmesg.

## 3. What are major and minor numbers in device drivers?
**Answer:**
- Major number identifies the driver associated with the device.
- Minor number identifies a specific device (or subdevice) handled by the same driver.

- In the register_chrdev_region() or alloc_chrdev_region() functions, you define these numbers. The kernel uses them to map a device node (e.g., /dev/mydev) to the correct driver.

## 4. How do you handle concurrency in device drivers?
**Answer:**

Concurrency is crucial since multiple processes or CPUs might access the device or shared data.

Synchronization techniques:

- `Spinlocks` – for short atomic sections (IRQs disabled).
- `Mutexes/Semaphores` – for longer operations, but not in interrupt context.
- `Atomic variables` – for simple counters or flags.
- `RCU` (Read-Copy-Update) – for read-mostly data structures.
- `wait_queues` – for sleeping until a condition is met.
- Correct use depends on execution context (`process`, `softirq`, `hardirq`).

## 5. What is the role of ioctl() in device drivers?
Answer:
ioctl() is used for custom control commands not covered by read()/write(). It provides a flexible way to:

Configure device parameters (e.g., baud rate).

Send non-standard data.

Query device state.

You implement file_operations->unlocked_ioctl() or compat_ioctl() in the driver.

Care must be taken to handle user-space pointer access using copy_to_user() / copy_from_user().

## 6. What is the difference between kmalloc() and vmalloc()?
Answer:

- `kmalloc()` allocates physically contiguous memory, suitable for DMA.

- `vmalloc()` allocates virtually contiguous memory (not physically), useful for large allocations.

- `kmalloc()` is faster and preferred for small buffers. But for larger memory or non-DMA-safe memory, `vmalloc()` is safer.

## 7. How do you handle hardware interrupts in Linux kernel drivers?
Answer:
You use request_irq() to register an interrupt handler. The handler should:

Be fast.

Not sleep or block.

Acknowledge/clear the interrupt.

If heavy processing is needed, use:

Bottom halves like tasklets or workqueues for deferred processing.

Always `free_irq()` on driver removal.

## 8. What is the purpose of probe() and remove() in platform drivers?
Answer:

`probe()` is called when a matching device (e.g., from Device Tree or ACPI) is found. It initializes hardware and resources.

remove() is called when the device is removed or driver is unloaded. It cleans up (e.g., `iounmap()`, `free_irq()`).

They are part of the platform_driver structure and work with platform_device.

## 9. What are the key considerations for writing a DMA-capable device driver?
Answer:

Use `dma_alloc_coherent()` or `dma_map_single()` for buffer allocation.

Ensure memory is suitable for DMA (aligned, cache-coherent).

Properly map/unmap DMA addresses for the device.

Handle synchronization between CPU and device.

Consider DMA direction (DMA_TO_DEVICE, DMA_FROM_DEVICE).

Ensure memory barriers where necessary.

## 10. How would you debug a kernel driver crash (e.g., kernel panic)?
Answer:
Steps:

Enable `kptr_restrict` and review `dmesg` or `journalctl` -k for oops messages.

Use `kgdb` or `kdb` for step-debugging.

Add `printk()` or `pr_debug()` for tracing.

Use `ftrace` or `dynamic debug`.

Analyze crash dumps via `kexec/kdump.`

Use objdump or gdb with vmlinux to inspect code.

## 11. How to Make Your Kernel Module Load Automatically on Boot — Simplified Explanation

### Step 1: Copy your .ko file into the right folder

What you do:

You copy your compiled driver file (something like hello_driver.ko) into this folder:

```bash
/lib/modules/$(uname -r)/kernel/drivers/
```

What happens inside the system:

- The kernel and related tools expect all device drivers (modules) to live inside /lib/modules/ organized by kernel version.

- Putting your .ko there lets the system find and use it when needed.

### Step 2: Run depmod -a

What you do:

You run this command:

```bash
sudo depmod -a
```
`sudo depmod -a` is a Linux command used to rebuild module dependency lists for the kernel.



- depmod scans all modules in `/lib/modules/$(uname -r)/` and builds a map of dependencies between modules.
  
- You typically run this after:

  - Installing or updating kernel modules manually
  - Installing a new kernel
  - Fixing missing module dependency issues
  - Adding drivers outside your package manager

### Step 3: Add your module name to /etc/modules

What you do:

You add the name of your module (without .ko) to a text file:

```bash
echo hello_driver | sudo tee -a /etc/modules
```

What happens inside the system:

- `/etc/modules` is a simple list of module names to load every time the system boots.

- When the system starts, it reads this file and tries to load each module listed there.

- It uses the information depmod created to load the modules properly and in the right order.

### Step 4: Reboot your Raspberry Pi
What you do:
```bash
sudo reboot
```
You reboot your system.
-------------------------------------------------

# YOCTO

| Situation               | Command                             |
| ----------------------- | ----------------------------------- |
| Build application       | `bitbake sysmon`                    |
| Build complete firmware | `bitbake my-image`                  |
| See recipe variables    | `bitbake -e sysmon`                 |
| Find work directory     | `bitbake -e sysmon \| grep WORKDIR` |
| Clean build             | `bitbake -c clean sysmon`           |
| Full rebuild            | `bitbake -c cleansstate sysmon`     |
| Run only compile        | `bitbake -c compile sysmon`         |
| Force rebuild           | `bitbake -f sysmon`                 |
| See tasks               | `bitbake -c listtasks sysmon`       |
| Show all recipes        | `bitbake -s`                        |
| Debug dependency        | `bitbake -g sysmon`                 |

