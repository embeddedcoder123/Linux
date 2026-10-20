- [C and C++](#c-and-c)
  - [MISRA C:2012 – 100 Coding Rules with Examples](#misra-c2012--100-coding-rules-with-examples)
    - [1-20](#1-20)
    - [21-40](#21-40)
    - [41-60](#41-60)
    - [61-80](#61-80)
    - [81-100](#81-100)
  - [Pointer declaration](#pointer-declaration)
  - [Pointer post-prefix increment](#pointer-post-prefix-increment)
  - [Decimal to hex conversion](#decimal-to-hex-conversion)
  - [Virtaul function and pure virtual function difference.](#virtaul-function-and-pure-virtual-function-difference)
  - [Diamond problem in C++](#diamond-problem-in-c)
  - [Other use case of virtual keyword](#other-use-case-of-virtual-keyword)
    - [1. Runtime Polymorphism](#1-runtime-polymorphism)
    - [2. Virtual Destructor](#2-virtual-destructor)
    - [3. Virtual Inheritance](#3-virtual-inheritance)
    - [4. Pure Virtual Functions (Abstract Classes)](#4-pure-virtual-functions-abstract-classes)
- [Kernel programming](#kernel-programming)
  - [`restrict` Keyword in C99 — Notes with Examples](#restrict-keyword-in-c99--notes-with-examples)
    - [What is `restrict`?](#what-is-restrict)
    - [🧠 Key Points](#-key-points)
    - [🧪 Example Code](#-example-code)
      - [✅ Correct Usage](#-correct-usage)
      - [❌ Incorrect Usage — Undefined Behavior](#-incorrect-usage--undefined-behavior)
  - [Strict Aliasing Rule](#strict-aliasing-rule)
    - [❌ Bad Example (Undefined behavior):](#-bad-example-undefined-behavior)
    - [✅ Safe workaround:](#-safe-workaround)
  - [`volatile`](#volatile)
    - [🔧 Use Cases:](#-use-cases)
    - [Example Recap (non-volatile flag):](#example-recap-non-volatile-flag)
      - [Step 1: Understanding the compiler’s assumptions](#step-1-understanding-the-compilers-assumptions)
      - [Step 2: Optimization performed — Register caching](#step-2-optimization-performed--register-caching)
      - [Step 3: Why this optimization makes sense](#step-3-why-this-optimization-makes-sense)
      - [Step 4: When this breaks — external changes](#step-4-when-this-breaks--external-changes)
      - [Step 5: How volatile fixes this](#step-5-how-volatile-fixes-this)
      - [Step 6: How the generated code differs](#step-6-how-the-generated-code-differs)
      - [Step 7: Real Assembly Example (simplified)](#step-7-real-assembly-example-simplified)
  - [`const volatile`](#const-volatile)
  - [`_Atomic`](#_atomic)
    - [Why do you need it?](#why-do-you-need-it)
  - [What are Memory Barriers? Why Are They Important?](#what-are-memory-barriers-why-are-they-important)
    - [why Memory barriers happened?](#why-memory-barriers-happened)
      - [Why is this allowed?](#why-is-this-allowed)
    - [❌ Example Without Memory Barrier (Possible Bug)](#-example-without-memory-barrier-possible-bug)
      - [❓What You Expect](#what-you-expect)
      - [⚠️ What Can Go Wrong:](#️-what-can-go-wrong)
    - [✅ Example WITH Memory Barrier (Correct)](#-example-with-memory-barrier-correct)
      - [✅ Now Guaranteed](#-now-guaranteed)
    - [barriar type](#barriar-type)
    - [Are \_\_sync\_synchronize(); and mb() the same?](#are-__sync_synchronize-and-mb-the-same)
  - [What is the difference between `static`, `extern`, and `static inline` functions in the kernel?](#what-is-the-difference-between-static-extern-and-static-inline-functions-in-the-kernel)
  - [How is `inline` Used in Kernel Code? What's the Role of `__always_inline`?](#how-is-inline-used-in-kernel-code-whats-the-role-of-__always_inline)
  - [What is the Role of `container_of()` Macro?](#what-is-the-role-of-container_of-macro)
  - [Use of typeof() and Its Role in Kernel Macros](#use-of-typeof-and-its-role-in-kernel-macros)
  - [What are `__init` and` __exit` in Kernel Modules?](#what-are-__init-and-__exit-in-kernel-modules)
    - [✅ ==\_\_init — Marks the Initialization Function](#-__init--marks-the-initialization-function)
    - [❌ \_\_exit — Marks the Cleanup Function](#-__exit--marks-the-cleanup-function)
    - [🧾 Simple Example](#-simple-example)
      - [What happens here?](#what-happens-here)
  - [What is Pointer Alignment?](#what-is-pointer-alignment)
    - [✅ Simple Example](#-simple-example-1)
      - [❌ What if it’s misaligned?](#-what-if-its-misaligned)
    - [🔧 In Kernel Code](#-in-kernel-code)
    - [🛠 How to Ensure Proper Alignment?](#-how-to-ensure-proper-alignment)
    - [Kernel memory](#kernel-memory)
    - [DMA Alignment](#dma-alignment)
  - [How are bitfields used in hardware registers?](#how-are-bitfields-used-in-hardware-registers)
    - [Step 1: Define a bitfield in C](#step-1-define-a-bitfield-in-c)
    - [Step 2: Access the bits](#step-2-access-the-bits)
  - [Difference Between `kmalloc()` and `vmalloc()`](#difference-between-kmalloc-and-vmalloc)
  - [What is Unaligned Memory Access?](#what-is-unaligned-memory-access)
    - [Unaligned Memory Access](#unaligned-memory-access)
    - [✅ Aligned Example](#-aligned-example)
    - [❌ Unaligned Example](#-unaligned-example)
    - [All possible way to handle unaligned memory access](#all-possible-way-to-handle-unaligned-memory-access)
  - [Difference Between `memcpy()` and `memmove()` in Kernel Space](#difference-between-memcpy-and-memmove-in-kernel-space)
  - [Unions in Hardware Register Definitions — Explained with Example](#unions-in-hardware-register-definitions--explained-with-example)
    - [Why use unions?](#why-use-unions)
  - [How to Prevent Structure Padding in C (for Memory-Mapped I/O)](#how-to-prevent-structure-padding-in-c-for-memory-mapped-io)
    - [1. Using __attribute__((packed)) in GCC](#1-using-attributepacked-in-gcc)
    - [2. Using #pragma pack (MSVC or GCC)](#2-using-pragma-pack-msvc-or-gcc)
    - [3. Memory-Mapped I/O Register Structure](#3-memory-mapped-io-register-structure)
  - [How do `copy_from_user()` and `copy_to_user()` work?](#how-do-copy_from_user-and-copy_to_user-work)
  - [Why can't you directly dereference user-space pointers in kernel?](#why-cant-you-directly-dereference-user-space-pointers-in-kernel)
  - [Difference between `get_user()` and `copy_from_user()`?](#difference-between-get_user-and-copy_from_user)
  - [Risks of using  `memcpy()` with user-space pointers?](#risks-of-using--memcpy-with-user-space-pointers)
  - [How do you perform DMA mapping in kernel?](#how-do-you-perform-dma-mapping-in-kernel)
    - [1️⃣ What is DMA?](#1️⃣-what-is-dma)
      - [What DMA Mapping Is (in simple words)](#what-dma-mapping-is-in-simple-words)
    - [2️⃣ How DMA Mapping Works](#2️⃣-how-dma-mapping-works)
  - [Explain page faults in kernel mode and how to avoid them.](#explain-page-faults-in-kernel-mode-and-how-to-avoid-them)
    - [What is a page fault in kernel mode?](#what-is-a-page-fault-in-kernel-mode)
    - [Why are page faults tricky in the kernel?](#why-are-page-faults-tricky-in-the-kernel)
    - [How to avoid page faults in kernel mode?](#how-to-avoid-page-faults-in-kernel-mode)
  - [What happens if a kernel module dereferences a null pointer?](#what-happens-if-a-kernel-module-dereferences-a-null-pointer)
  - [How is memory protection handled between user and kernel space?](#how-is-memory-protection-handled-between-user-and-kernel-space)
  - [What is the slab allocator? How does it differ from the buddy allocator?](#what-is-the-slab-allocator-how-does-it-differ-from-the-buddy-allocator)
  - [How does `kmem_cache_create()` help performance?](#how-does-kmem_cache_create-help-performance)
  - [How do you debug kernel memory leaks?](#how-do-you-debug-kernel-memory-leaks)
    - [✅ 1. Use `kmemleak` (Kernel Memory Leak Detector)](#-1-use-kmemleak-kernel-memory-leak-detector)
      - [1.Enable it in the kernel config](#1enable-it-in-the-kernel-config)
    - [2. Use slabtop](#2-use-slabtop)
  - [What does "*sleeping*" mean in memory allocation?](#what-does-sleeping-mean-in-memory-allocation)
  - [What are GFP Flags?](#what-are-gfp-flags)
    - [Common GFP Flags and Their Use](#common-gfp-flags-and-their-use)
  - [| `GFP_DMA`      | Memory below 16MB (DMA-capable)        | ✅ Yes      | Legacy devices needing DMA |](#-gfp_dma-------memory-below-16mb-dma-capable----------yes-------legacy-devices-needing-dma-)
  - [What is the `highmem zone` and how do you access it?](#what-is-the-highmem-zone-and-how-do-you-access-it)
    - [What is **HighMem**?](#what-is-highmem)
    - [Memory Zones in Linux Kernel](#memory-zones-in-linux-kernel)
    - [How to Access HighMem](#how-to-access-highmem)
    - [Why HighMem Is Mostly 32-bit Only](#why-highmem-is-mostly-32-bit-only)
  - [How do you prevent stack overflows in kernel code?](#how-do-you-prevent-stack-overflows-in-kernel-code)
    - [✅ Tips to Prevent Stack Overflows:](#-tips-to-prevent-stack-overflows)
      - [Avoid large local variables](#avoid-large-local-variables)
    - [Keep functions simple](#keep-functions-simple)
      - [Use static analysis tools](#use-static-analysis-tools)
    - [Use compiler stack checks](#use-compiler-stack-checks)
  - [When do you use mutext and shemphore](#when-do-you-use-mutext-and-shemphore)
    - [Mutex](#mutex)
      - [Mutex deadloack](#mutex-deadloack)
    - [Why we should use Mutex not global variable](#why-we-should-use-mutex-not-global-variable)
    - [How kernel handle mutext](#how-kernel-handle-mutext)
    - [Shemaphore](#shemaphore)
  - [Spinlocks vs Mutexes in Kernel](#spinlocks-vs-mutexes-in-kernel)
    - [Spinlock:](#spinlock)
    - [Mutex:](#mutex-1)
    - [🛠️ Example](#️-example)
  - [What is an Interrupt Context and Can It Sleep?](#what-is-an-interrupt-context-and-can-it-sleep)
  - [Bottom Halves, Tasklets, and Workqueues](#bottom-halves-tasklets-and-workqueues)
    - [What happens when an interrupt occurs?](#what-happens-when-an-interrupt-occurs)
    - [Handling an interrupt has two parts:](#handling-an-interrupt-has-two-parts)
      - [✅ Top Half (Fast Handler)](#-top-half-fast-handler)
      - [🔻 Bottom Half (Deferred Work)](#-bottom-half-deferred-work)
      - [1. 🧩 Tasklets (can not sleep and not intruptted by others)](#1--tasklets-can-not-sleep-and-not-intruptted-by-others)
      - [2. 🧵 Workqueues (can sleep)](#2--workqueues-can-sleep)
      - [Summary](#summary)
    - [Example](#example)
  - [Purpose of `atomic_t` and `atomic64_t`](#purpose-of-atomic_t-and-atomic64_t)
    - [Why?](#why)
  - [35. Can You Use Mutexes in Interrupt Handlers?](#35-can-you-use-mutexes-in-interrupt-handlers)
  - [RCU (Read-Copy-Update) and Seqlocks – What and When?](#rcu-read-copy-update-and-seqlocks--what-and-when)
  - [7. How Do You Avoid Deadlocks in Kernel Code?](#7-how-do-you-avoid-deadlocks-in-kernel-code)
    - [✅ Avoid deadlocks by:](#-avoid-deadlocks-by)
    - [Lockdep for Kernel and C++](#lockdep-for-kernel-and-c)
  - [What is Preemption? How to Disable/Enable It?](#what-is-preemption-how-to-disableenable-it)
  - [How Do You Implement a Lock-Free Queue in the Kernel?](#how-do-you-implement-a-lock-free-queue-in-the-kernel)
  - [Priority Inversion – Simple Explanation](#priority-inversion--simple-explanation)
    - [🔧 Problem (What is it?)](#-problem-what-is-it)
    - [Why is it bad?](#why-is-it-bad)
    - [🛠️ Solution – Priority Inheritance](#️-solution--priority-inheritance)
    - [In One Line:](#in-one-line)
  - [How do you map hardware registers to virtual memory in kernel?](#how-do-you-map-hardware-registers-to-virtual-memory-in-kernel)
    - [1. What are hardware registers?](#1-what-are-hardware-registers)
    - [2. Why map them to virtual memory?](#2-why-map-them-to-virtual-memory)
    - [3. How does the kernel map them?](#3-how-does-the-kernel-map-them)
    - [4. Now the kernel can use the mapped address](#4-now-the-kernel-can-use-the-mapped-address)
    - [5. Cleanup when done](#5-cleanup-when-done)
  - [What is a device file? How is it connected to a driver?](#what-is-a-device-file-how-is-it-connected-to-a-driver)
    - [How is it Connected to a Driver?](#how-is-it-connected-to-a-driver)
    - [Steps in Linux](#steps-in-linux)
- [Embedded System](#embedded-system)
  - [Define array of function pointer and use it in interrupt handling](#define-array-of-function-pointer-and-use-it-in-interrupt-handling)
    - [Use case of array of function pointer in ISR](#use-case-of-array-of-function-pointer-in-isr)
  - [How to access GPIO pin and update ?](#how-to-access-gpio-pin-and-update-)
  - [What is different between pull up and pull down register](#what-is-different-between-pull-up-and-pull-down-register)
  - [What happened in case of strong pull up and weak pull up?](#what-happened-in-case-of-strong-pull-up-and-weak-pull-up)
  - [When GPIO triggered from hardware or software and interupt triggered what exactly happened?](#when-gpio-triggered-from-hardware-or-software-and-interupt-triggered-what-exactly-happened)
    - [Hardware-Triggered GPIO Interrupt](#hardware-triggered-gpio-interrupt)
    - [Software-Triggered GPIO Interrupt](#software-triggered-gpio-interrupt)
    - [What Changes in the CPU During Interrupt?](#what-changes-in-the-cpu-during-interrupt)
  - [How can we solved post-processing delay issue in interrupt?](#how-can-we-solved-post-processing-delay-issue-in-interrupt)
    - [Bare metal progamming](#bare-metal-progamming)
      - [Ring buffer](#ring-buffer)
    - [OS based or freeRTOS](#os-based-or-freertos)
      - [FreeRTOS example using vTaskNotifyGiveFromISR()](#freertos-example-using-vtasknotifygivefromisr)
      - [in freeRTOS xQueueSendFromISR](#in-freertos-xqueuesendfromisr)
- [Linux](#linux)
  - [1. Explain linux directory structure](#1-explain-linux-directory-structure)
  - [Linux Boot Process Diagram](#linux-boot-process-diagram)
  - [Explain Linux boot process](#explain-linux-boot-process)
    - [0. CPU wakes up](#0-cpu-wakes-up)
    - [1. BIOS / UEFI Initialization](#1-bios--uefi-initialization)
    - [2. Bootloader (GRUB, LILO, systemd-boot, etc.)](#2-bootloader-grub-lilo-systemd-boot-etc)
    - [3. Linux Kernel Initialization](#3-linux-kernel-initialization)
    - [4. init System Starts (PID 1)](#4-init-system-starts-pid-1)
    - [5. Login Prompt / GUI](#5-login-prompt--gui)
  - [2. What is ABI](#2-what-is-abi)
    - [Example 1 Function Call (Most Common ABI Example)](#example-1-function-call-most-common-abi-example)
    - [2. Example 2: 32-bit vs 64-bit Program](#2-example-2-32-bit-vs-64-bit-program)
    - [Example 3: System Call (Kernel ABI)](#example-3-system-call-kernel-abi)
    - [Normal Function ABI vs Linux System Call ABI](#normal-function-abi-vs-linux-system-call-abi)
      - [Argument Registers](#argument-registers)
      - [Key Point](#key-point)
  - [3. How system call execute explain in detail.](#3-how-system-call-execute-explain-in-detail)
    - [What is a System Call?](#what-is-a-system-call)
    - [1. User Program Calls `write()`](#1-user-program-calls-write)
    - [2. `glibc` Prepares the System Call](#2-glibc-prepares-the-system-call)
    - [3. CPU Executes `syscall` Instruction](#3-cpu-executes-syscall-instruction)
    - [4. Kernel Handles the System Call](#4-kernel-handles-the-system-call)
    - [5. Kernel Returns Result](#5-kernel-returns-result)
    - [Complete Flow](#complete-flow)
  - [4. Define your own system  call and in kernel](#4-define-your-own-system--call-and-in-kernel)
    - [Step 1: Write the kernel function](#step-1-write-the-kernel-function)
    - [Step 2: Add the source file to the build](#step-2-add-the-source-file-to-the-build)
    - [Step 3: Register the system call](#step-3-register-the-system-call)
    - [Step 4: Rebuild the Kernel](#step-4-rebuild-the-kernel)
    - [Step 5: Call Your System Call from User Space](#step-5-call-your-system-call-from-user-space)
  - [5. Popular system call](#5-popular-system-call)
    - [Process Control System Calls](#process-control-system-calls)
    - [File Management System Calls](#file-management-system-calls)
    - [Device Management System Calls](#device-management-system-calls)
    - [Memory Management System Calls](#memory-management-system-calls)
    - [Information Maintenance System Calls](#information-maintenance-system-calls)
    - [Communication (IPC) System Calls](#communication-ipc-system-calls)
    - [Network System Calls](#network-system-calls)
  - [6. How context switch happens when open function is called from user space?](#6-how-context-switch-happens-when-open-function-is-called-from-user-space)
    - [1. User-Space Call](#1-user-space-call)
    - [2. Mode Switch (User → Kernel)](#2-mode-switch-user--kernel)
    - [3. Kernel Handles open()](#3-kernel-handles-open)
    - [4. When Does a Context Switch Happen?](#4-when-does-a-context-switch-happen)
  - [7. What is GNU](#7-what-is-gnu)
  - [8. Static and dynamic linking](#8-static-and-dynamic-linking)
    - [Static and Dynamic Linking in Linux](#static-and-dynamic-linking-in-linux)
      - [1. Introduction](#1-introduction)
      - [2. From Source Code to Executable](#2-from-source-code-to-executable)
      - [3. Important File Types](#3-important-file-types)
    - [Part I: Static Linking](#part-i-static-linking)
      - [4. What Is Static Linking?](#4-what-is-static-linking)
      - [5. Building a Static Library](#5-building-a-static-library)
        - [`mathutil.h`](#mathutilh)
        - [`mathutil.c`](#mathutilc)
        - [`main.c`](#mainc)
      - [6. Static Linking at Runtime](#6-static-linking-at-runtime)
      - [7. Advantages of Static Linking](#7-advantages-of-static-linking)
      - [8. Disadvantages of Static Linking](#8-disadvantages-of-static-linking)
    - [Part II: Dynamic Linking](#part-ii-dynamic-linking)
      - [9. What Is Dynamic Linking?](#9-what-is-dynamic-linking)
      - [10. Building a Shared Library](#10-building-a-shared-library)
      - [11. Why `-fPIC` Is Used](#11-why--fpic-is-used)
      - [12. What Happens When a Dynamic Program Starts?](#12-what-happens-when-a-dynamic-program-starts)
      - [13. Library Search Locations](#13-library-search-locations)
      - [14. Immediate and Lazy Symbol Binding](#14-immediate-and-lazy-symbol-binding)
      - [15. Advantages of Dynamic Linking](#15-advantages-of-dynamic-linking)
      - [16. Disadvantages of Dynamic Linking](#16-disadvantages-of-dynamic-linking)
    - [Part III: Detailed Comparison](#part-iii-detailed-comparison)
      - [17. Static vs Dynamic Linking](#17-static-vs-dynamic-linking)
      - [18. Visual Comparison](#18-visual-comparison)
        - [Static linking](#static-linking)
        - [Dynamic linking](#dynamic-linking)
    - [Part IV: Runtime Dynamic Loading](#part-iv-runtime-dynamic-loading)
      - [19. Link-Time Dynamic Linking vs `dlopen()`](#19-link-time-dynamic-linking-vs-dlopen)
        - [Normal shared-library dependency](#normal-shared-library-dependency)
        - [Explicit runtime loading](#explicit-runtime-loading)
    - [Part V: Names, Versions, and Compatibility](#part-v-names-versions-and-compatibility)
      - [20. Library Naming](#20-library-naming)
      - [21. SONAME](#21-soname)
      - [22. API vs ABI](#22-api-vs-abi)
    - [Part VI: Linker Behavior and Common Problems](#part-vi-linker-behavior-and-common-problems)
      - [23. Link Order Matters](#23-link-order-matters)
      - [24. Common Link-Time Errors](#24-common-link-time-errors)
        - [Undefined reference](#undefined-reference)
        - [Cannot find library](#cannot-find-library)
      - [25. Common Runtime Errors](#25-common-runtime-errors)
        - [Shared library not found](#shared-library-not-found)
        - [Symbol lookup error](#symbol-lookup-error)
    - [Part VII: Diagnostic Commands](#part-vii-diagnostic-commands)
      - [26. Useful Linux Commands](#26-useful-linux-commands)
        - [Determine file type](#determine-file-type)
        - [Display shared-library dependencies](#display-shared-library-dependencies)
        - [Show required libraries](#show-required-libraries)
        - [Show ELF interpreter](#show-elf-interpreter)
        - [Show symbols](#show-symbols)
        - [Show library search activity](#show-library-search-activity)
        - [Show loader and symbol activity](#show-loader-and-symbol-activity)
        - [Compare sizes](#compare-sizes)
        - [Trace opened library files](#trace-opened-library-files)
    - [Part VIII: Embedded Linux Considerations](#part-viii-embedded-linux-considerations)
      - [27. Choosing a Linking Model for Embedded Linux](#27-choosing-a-linking-model-for-embedded-linux)
        - [Static linking may be appropriate when](#static-linking-may-be-appropriate-when)
        - [Dynamic linking may be appropriate when](#dynamic-linking-may-be-appropriate-when)
        - [Practical BSP and cross-compilation concerns](#practical-bsp-and-cross-compilation-concerns)
      - [28. Security and Maintenance Considerations](#28-security-and-maintenance-considerations)
        - [Static binaries](#static-binaries)
        - [Dynamic binaries](#dynamic-binaries)
    - [Part IX: Worked Demonstration](#part-ix-worked-demonstration)
      - [29. Compare Dynamic and Static Builds](#29-compare-dynamic-and-static-builds)
    - [Part X: Interview Summary](#part-x-interview-summary)
      - [30. Short Interview Answer](#30-short-interview-answer)
      - [31. Key Differences to Remember](#31-key-differences-to-remember)
      - [32. Common Follow-Up Interview Questions](#32-common-follow-up-interview-questions)
    - [Final Takeaway](#final-takeaway)
  - [9. Execute script at boot time](#9-execute-script-at-boot-time)
    - [Create a systemd Service](#create-a-systemd-service)
      - [Create a service file](#create-a-service-file)
  - [10. Different b/w shemphore, mutex and spinlock](#10-different-bw-shemphore-mutex-and-spinlock)
    - [Shemaphore](#shemaphore-1)
    - [Mutex](#mutex-2)
    - [Spinlock](#spinlock-1)
  - [11. Different b/w character, block and network device driver](#11-different-bw-character-block-and-network-device-driver)
    - [One-line takeaway (easy to remember)](#one-line-takeaway-easy-to-remember)
  - [12. Can we send strucure using `IOCTL`?](#12-can-we-send-strucure-using-ioctl)
  - [13. Explain any linux subsystem in details?](#13-explain-any-linux-subsystem-in-details)
  - [14. Add any system call in linux?](#14-add-any-system-call-in-linux)
  - [15. use of `perf` tool for linux?](#15-use-of-perf-tool-for-linux)
  - [16. Changes required to add CAN driver in BSP](#16-changes-required-to-add-can-driver-in-bsp)
    - [1. Enable CAN Peripheral in Hardware Configuration](#1-enable-can-peripheral-in-hardware-configuration)
      - [1. Kernel driver](#1-kernel-driver)
      - [2. Kernel configuration](#2-kernel-configuration)
      - [3. Yocto integration](#3-yocto-integration)
      - [4. Device Tree](#4-device-tree)
    - [2. Update BSP Device Tree / Hardware Definition](#2-update-bsp-device-tree--hardware-definition)
    - [3. Add CAN Driver Source Files](#3-add-can-driver-source-files)
    - [4. Integrate with OS / HAL](#4-integrate-with-os--hal)
    - [5. Update BSP Initialization Code](#5-update-bsp-initialization-code)
    - [6. Add Device Registration (Optional)](#6-add-device-registration-optional)
  - [17. How so you debug crash occuring after 1 month of kernel without logs?](#17-how-so-you-debug-crash-occuring-after-1-month-of-kernel-without-logs)
    - [1. Capture Crash Info](#1-capture-crash-info)
    - [2. Check for Common Long-Uptime Issues](#2-check-for-common-long-uptime-issues)
    - [3. Monitor System](#3-monitor-system)
  - [18. How to serial communication using commandline](#18-how-to-serial-communication-using-commandline)
  - [| -echo   | Do not echo received data |](#--echo----do-not-echo-received-data-)
  - [19. How to debug i2c device driver if not shown in /dev.](#19-how-to-debug-i2c-device-driver-if-not-shown-in-dev)
    - [Step 1: Check Kernel Detection](#step-1-check-kernel-detection)
    - [Step 2: Check Device Tree / Platform Data](#step-2-check-device-tree--platform-data)
    - [Step 3: Check if the Driver is Loaded](#step-3-check-if-the-driver-is-loaded)
    - [Step 4: Verify Driver Binding](#step-4-verify-driver-binding)
    - [Step 5: Check /dev Creation](#step-5-check-dev-creation)
    - [Step 6: Enable Debug Prints](#step-6-enable-debug-prints)
    - [Step 7: Test with i2c-tools](#step-7-test-with-i2c-tools)
  - [20. Kernel Debugging and Tracing methods](#20-kernel-debugging-and-tracing-methods)
    - [1. `ftrace` Function Tracer](#1-ftrace-function-tracer)
      - [🎯 When to use](#-when-to-use)
      - [Example](#example-1)
      - [How to do it](#how-to-do-it)
    - [2. `perf` Performance Analysis Tool](#2-perf-performance-analysis-tool)
      - [When to use](#when-to-use)
      - [Example](#example-2)
    - [3. `kprobes`](#3-kprobes)
      - [When to use](#when-to-use-1)
- [Kernel interview Questions](#kernel-interview-questions)
  - [1. Can you explain what a kernel is and its main functions?](#1-can-you-explain-what-a-kernel-is-and-its-main-functions)
    - [Main Functions of a Kernel](#main-functions-of-a-kernel)
      - [1. Process Management](#1-process-management)
      - [2. Memory Management](#2-memory-management)
      - [3. Device Management (I/O Control)](#3-device-management-io-control)
      - [4. File System Management](#4-file-system-management)
      - [5. System Calls Interface](#5-system-calls-interface)
      - [6. Security \& Access Control](#6-security--access-control)
  - [2. What are the different types of kernels, and how do they differ?](#2-what-are-the-different-types-of-kernels-and-how-do-they-differ)
  - [3. How does process scheduling work in the kernel?](#3-how-does-process-scheduling-work-in-the-kernel)
  - [4. What is the role of system calls in the kernel?](#4-what-is-the-role-of-system-calls-in-the-kernel)
    - [Interface Between User and Kernel](#interface-between-user-and-kernel)
    - [Access to Hardware \& Resources](#access-to-hardware--resources)
    - [Process Management](#process-management)
    - [Memory Management](#memory-management)
    - [Communication](#communication)
    - [Security \& Stability](#security--stability)
  - [5. Can you explain the difference between user space and kernel space?](#5-can-you-explain-the-difference-between-user-space-and-kernel-space)
  - [6. How does memory management work in the kernel?](#6-how-does-memory-management-work-in-the-kernel)
  - [7. What are interrupts, and how are they handled by the kernel?](#7-what-are-interrupts-and-how-are-they-handled-by-the-kernel)
    - [How the Kernel Handles Interrupts](#how-the-kernel-handles-interrupts)
  - [8. Can you describe what a context switch is and when it occurs?](#8-can-you-describe-what-a-context-switch-is-and-when-it-occurs)
    - [Save State of Current Process](#save-state-of-current-process)
    - [When Context Switch Occurs](#when-context-switch-occurs)
  - [9. What is a device driver, and how does it interact with the kernel?](#9-what-is-a-device-driver-and-how-does-it-interact-with-the-kernel)
  - [10. How does the kernel handle synchronization between processes?](#10-how-does-the-kernel-handle-synchronization-between-processes)
  - [11. What is the difference between a monolithic kernel and a microkernel?](#11-what-is-the-difference-between-a-monolithic-kernel-and-a-microkernel)
  - [12. How do you debug kernel issues?](#12-how-do-you-debug-kernel-issues)
  - [13. What is a kernel panic, and how do you troubleshoot it?](#13-what-is-a-kernel-panic-and-how-do-you-troubleshoot-it)
- [RTOS](#rtos)
  - [1. How many stacks does an RTOS typically have](#1-how-many-stacks-does-an-rtos-typically-have)
  - [2. Who actually runs the scheduler in an RTOS?](#2-who-actually-runs-the-scheduler-in-an-rtos)
  - [3. Where is the initial value stored for global/static variables?](#3-where-is-the-initial-value-stored-for-globalstatic-variables)
  - [4. Why do we need both .bss and .data sections in memory layout?](#4-why-do-we-need-both-bss-and-data-sections-in-memory-layout)
  - [5. Does an 8-bit microcontroller support structure padding?](#5-does-an-8-bit-microcontroller-support-structure-padding)
  - [6. What is the purpose of padding in structures or memory alignment?](#6-what-is-the-purpose-of-padding-in-structures-or-memory-alignment)
  - [7. What typically triggers a context switch in an RTOS?](#7-what-typically-triggers-a-context-switch-in-an-rtos)
  - [8. How does the RTOS differentiate between ISR and task context?](#8-how-does-the-rtos-differentiate-between-isr-and-task-context)
  - [9. Why is dynamic memory allocation discouraged in safety-critical systems?](#9-why-is-dynamic-memory-allocation-discouraged-in-safety-critical-systems)
  - [10. How does the linker script influence stack and heap placement?](#10-how-does-the-linker-script-influence-stack-and-heap-placement)
  - [11. What function runs before main() in an embedded system?](#11-what-function-runs-before-main-in-an-embedded-system)

# C and C++
## MISRA C:2012 – 100 Coding Rules with Examples

### 1-20

| Rule No | Rule Description                                   | ❌ Non-Compliant               | ✅ Compliant                               |
| ------- | -------------------------------------------------- | ----------------------------- | ----------------------------------------- |
| 1.1     | No undefined behavior                              | `int x = 1/0;`                | `if(y != 0) x = 1/y;`                     |
| 2.2     | No dead code                                       | `if(0){x=5;}`                 | Remove unreachable code                   |
| 5.1     | Identifiers must be unique                         | `int a; int A;`               | Use distinct names                        |
| 5.2     | No reserved identifiers                            | `int _main;`                  | `int my_main;`                            |
| 8.7     | Internal linkage objects should be static          | `int counter;`                | `static int counter;`                     |
| 8.13    | Functions must be declared before use              | `foo(); int foo(){return 0;}` | `int foo(); foo();`                       |
| 9.1     | Variables must be initialized before use           | `int x; printf("%d", x);`     | `int x = 0;`                              |
| 10.1    | No implicit signed/unsigned conversion             | `unsigned int a=-1;`          | `unsigned int a=1U;`                      |
| 10.3    | No narrowing conversions                           | `uint8_t x=300;`              | `uint8_t x=(uint8_t)300;`                 |
| 11.3    | No cast between incompatible pointer types         | `float *p = (float*)&i;`      | Avoid unsafe casts                        |
| 12.1    | Operands of arithmetic operators must be safe      | `x=y/z;`                      | `if(z!=0) x=y/z;`                         |
| 12.2    | Right-hand operand of shift operator must be valid | `x=y<<40;`                    | `x=y<<3;`                                 |
| 13.2    | Expressions shall not have side effects            | `if(i++<10)`                  | `i++; if(i<10)`                           |
| 14.4    | Controlling expressions must be Boolean            | `if(x)`                       | `if(x!=0)`                                |
| 15.3    | Switch statements must have a default case         | `switch(a){case 1: break;}`   | Add `default:`                            |
| 15.5    | Functions should have a single exit point          | Multiple `return`s            | One `return` at end                       |
| 17.7    | Return value of non-void function must be used     | `printf("Hi");`               | `int ret=printf("Hi");`                   |
| 18.1    | Pointer arithmetic only within array bounds        | `*(ptr+10)`                   | Access valid index only                   |
| 19.7    | Function-like macros should not be used            | `#define SQR(x) x*x`          | `inline int square(int x){ return x*x; }` |
| 21.3    | Dynamic memory allocation shall not be used        | `malloc(10);`                 | Use static memory                         |

### 21-40

| Rule No | Rule Description                             | ❌ Non-Compliant        | ✅ Compliant                     |
| ------- | -------------------------------------------- | ---------------------- | ------------------------------- |
| 21.6    | Unsafe standard library functions prohibited | `gets(str);`           | `fgets(str,sizeof(str),stdin);` |
| 8.12    | No multiple definitions of objects/functions | `int x; int x;`        | Single definition               |
| 9.2     | Variables shall not be declared but unused   | `int x;`               | Remove or use variable          |
| 10.5    | Use only essential types                     | `int + float`          | Cast explicitly                 |
| 11.2    | Pointer must point to valid memory           | `int *p; *p=5;`        | `int x; int *p=&x;`             |
| 11.4    | Avoid pointer arithmetic on void*            | `void* p; p++;`        | `char* p; p++;`                 |
| 12.3    | No mixed operators without parentheses       | `a+b*c`                | `a+(b*c)`                       |
| 12.4    | Avoid complex expressions                    | `a=b+c*d-e/f;`         | Split into multiple statements  |
| 13.3    | Assignments shall be simple                  | `a=(b=c)+d;`           | `b=c; a=b+d;`                   |
| 14.1    | Loops must have well-defined exit            | `while(1){}`           | `while(cond){}`                 |
| 14.2    | No infinite loops without comment            | `for(;;)`              | `for(;;) { /* intentional */ }` |
| 14.3    | Avoid confusing nested if                    | `if(a) if(b) x=1;`     | Use braces                      |
| 15.1    | Avoid goto statements                        | `goto label;`          | Use structured flow             |
| 15.2    | Switch labels must be distinct               | `case 1:` duplicated   | Use unique case labels          |
| 15.4    | Break required in case                       | Missing `break;`       | Add break                       |
| 16.1    | Function parameters properly declared        | `void f(x)`            | `void f(int x)`                 |
| 16.2    | Functions must not have excessive parameters | `f(a,b,c,d,e,f,g,h,i)` | Reduce parameter count          |
| 16.3    | Use const for parameters if possible         | `void f(int x)`        | `void f(const int x)`           |
| 17.1    | Pointers must be aligned                     | `int* p=(int*)ptr;`    | Properly aligned pointer        |
| 17.2    | Arrays accessed within bounds                | `arr[10]` when size 5  | `arr[4]`                        |


### 41-60

| Rule No | Rule Description                         | ❌ Non-Compliant                 | ✅ Compliant                     |
| ------- | ---------------------------------------- | ------------------------------- | ------------------------------- |
| 17.3    | Do not return pointer to local variable  | `int* f(){int x; return &x;}`   | Return pointer to static/global |
| 17.4    | Do not modify string literals            | `char *s="hello"; s[0]='H';`    | `char s[]="hello"; s[0]='H';`   |
| 17.5    | Avoid multiple pointer dereference       | `**pp` without check            | Validate each pointer           |
| 18.2    | Union members accessed correctly         | Wrong type access               | Access correct member           |
| 18.3    | Avoid type punning                       | `int i; float *f=(float*)&i;`   | Use memcpy                      |
| 19.1    | Macros must be simple                    | Complex macro                   | Inline function                 |
| 19.2    | No macro side effects                    | `#define INC(x) x++`            | `inline void inc(int &x){x++;}` |
| 19.3    | Macro names unique                       | `#define MAX 10` multiple times | Unique name                     |
| 19.4    | No macro redefinition                    | `#define X 1 #define X 2`       | Avoid redefinition              |
| 19.5    | Avoid recursive macros                   | `#define A B #define B A`       | Avoid recursion                 |
| 19.6    | Conditional compilation limited          | Complex `#if`                   | Simplify logic                  |
| 20.1    | Standard library functions used safely   | `strcpy(dest, src);`            | `strncpy(dest, src, size);`     |
| 20.2    | No unsafe float comparison               | `if(f==0.1)`                    | `if(fabs(f-0.1)<0.001)`         |
| 20.3    | Avoid floating in critical code          | Float in ISR                    | Use integer                     |
| 20.4    | File operations checked                  | `fopen("x","r");`               | `FILE* f=fopen("x","r"); if(f)` |
| 20.5    | Error handling required                  | Ignore errors                   | Check return values             |
| 21.1    | No dynamic allocation in critical system | `malloc()`                      | Use static array                |
| 21.2    | Free only allocated memory               | `free(x)` if not allocated      | Valid free                      |
| 21.4    | Memory leaks prohibited                  | Missing free                    | Free after use                  |
| 21.5    | Global variable access controlled        | Unrestricted global             | Encapsulate in functions        |

### 61-80

| Rule No | Rule Description                               | ❌ Non-Compliant                                | ✅ Compliant                   |     |                         |
| ------- | ---------------------------------------------- | ---------------------------------------------- | ----------------------------- | --- | ----------------------- |
| 22.1    | Avoid pointer to different object types        | `int* p; float* f = (float*)p;`                | Keep pointers typed correctly |     |                         |
| 22.2    | Pointer arithmetic only on array               | `p+10` on single var                           | Only array pointer arithmetic |     |                         |
| 23.1    | No recursion                                   | `f(){ f(); }`                                  | Use iteration                 |     |                         |
| 23.2    | Functions shall not call themselves indirectly | Indirect recursion                             | Remove recursion              |     |                         |
| 24.1    | Loop counters well-defined                     | `for(i=0;i<n;i++){...}` without initialization | Initialize counters properly  |     |                         |
| 24.2    | Avoid infinite loops without comment           | `while(1){}`                                   | Add comment if intentional    |     |                         |
| 25.1    | Use boolean expressions explicitly             | `if(x)`                                        | `if(x!=0)`                    |     |                         |
| 25.2    | Avoid side effects in controlling expr         | `if(i++)`                                      | `i++; if(i<10)`               |     |                         |
| 26.1    | Avoid deep nesting                             | 6+ nested if                                   | Refactor logic                |     |                         |
| 26.2    | Avoid complex conditions                       | `if(a&&b                                       |                               | c)` | Split into multiple ifs |
| 27.1    | Switch-case labels must be constants           | `case x:` variable                             | Use constant values           |     |                         |
| 27.2    | Each case ends properly                        | Missing break                                  | Add bre                       |     |                         |


### 81-100

| Rule No | Rule Description                              | ❌ Non-Compliant                 | ✅ Compliant                  |
| ------- | --------------------------------------------- | ------------------------------- | ---------------------------- |
| 32.1    | No dynamic stack allocation                   | `alloca(10)`                    | Use fixed array              |
| 32.2    | Avoid variable-length arrays                  | `int arr[n];`                   | Use fixed size               |
| 33.1    | No hard-coded strings modification            | `char* s="abc"; s[0]='A';`      | Use array `char s[]="abc";`  |
| 33.2    | Pointer to string literals is read-only       | `char* s="abc";`                | Use `const char* s="abc";`   |
| 34.1    | Avoid undefined behavior with signed overflow | `int x=INT_MAX+1;`              | Use unsigned or check limits |
| 34.2    | Avoid undefined shift                         | `1 << 32`                       | Ensure shift < width         |
| 35.1    | No aliasing issues                            | `int* p; short* q = (short*)p;` | Avoid incompatible pointers  |
| 35.2    | Avoid pointer cast between types              | `(float*)&i`                    | Use memcpy or typed access   |
| 36.1    | Avoid unions for type punning                 | Access wrong member             | Use safe copy                |
| 36.2    | Ensure union member accessed correctly        | Wrong member                    | Access last written member   |
| 37.1    | Array indexing in bounds                      | `arr[10]` size 5                | `arr[4]`                     |
| 37.2    | Loop index within bounds                      | `for(i<=size)`                  | `for(i<size)`                |
| 38.1    | No unsafe function                            | `gets()`                        | `fgets()`                    |
| 38.2    | Use safe string functions                     | `strcpy()`                      | `strncpy()`                  |
| 39.1    | Library functions checked for errors          | Ignore return of `fopen()`      | Check `if(f!=NULL)`          |
| 39.2    | File operation return values used             | `fwrite()` ignored              | Check result                 |
| 40.1    | No direct hardware access without abstraction | `*(volatile int*)0x4000=1;`     | Use macro or driver          |
| 40.2    | Critical code no floating                     | Float in ISR                    | Use integer math             |
| 40.3    | Thread-safe code                              | Shared global without mutex     | Use mutex/atomic             |
| 40.4    | Document deviation                            | Break rule without record       | Add deviation comment        |

## Pointer declaration
1. int *p[5]
   - Array of 5 pointers to `int`
  
2. int (*p)[5]
   - Pointer to an array of 5 `integers`
  
3. int **p 
   - Pointer is points to integer pointer.

4. int (*p)(int, int) 
   - P is the function pointer which points to function that takes 2 int args and return int.

5.  int (*p[5])(int, int)
  - Array of 5 function pointers, where each function:
        - takes two `ints`
        - returns an `int`

6. int *(*p)(int, int);
  - p is a pointer to a function that takes two integers and returns a int pointer.
7. int (*(*p)[5])(int);
   - p is points to array of 5 function pointer which takes `int` and returns `int`.
  
```
p
 ↓
array[5]
 ↓
+-------+-------+-------+-------+-------+
|  *    |  *    |  *    |  *    |  *    |
+-------+-------+-------+-------+-------+
   ↓       ↓       ↓       ↓       ↓
 func    func    func    func    func
   ↓
 takes int
   ↓
 returns int

```
8.  char *(*p)[10];
   - Pointer is points to array of 10 `char*` 
```
p
 ↓
array[10]
 ↓
+----+----+----+----+----+
| *  | *  | *  | *  | *  | ... 10
+----+----+----+----+----+
  ↓
 char

```
9. char *(*p)[10];
- p is a pointer to an array of 10 pointers to pointers to char.
```
p
 ↓
array[10]
 ↓
+------+------+------+------+
| **   | **   | **   | **   | ... 10
+------+------+------+------+
  ↓
 pointer
  ↓
 char
```
```c
#include <stdio.h>

typedef int* (*handler_t) (int,int); 
static int result = 0;

int* add (int a, int b) { printf("add called...\n"); }
int* sub (int a, int b) { printf("sub called...\n");}
int* mul (int a, int b) { printf("mul called...\n"); }
int* div (int a, int b) { printf("div called...\n");}


handler_t afp[4] = {add, sub, mul, div}; // array of funciton pointer

int* (*array_fp[4]) (int,int) = {add, sub, mul, div}; // array of function pointer

int* (*(*p)[4]) (int,int) = &array_fp; // pointer pointing to array of function 

handler_t (*p1)[4] = &array_fp; // / pointer pointing to array of function 


int main () {

    for (int i = 0; i < 4 ; i++) {
        afp[i](50,5);
        array_fp[i](10,2);
        (*p)[i](10,2);
        (*p1)[i](10,2);
    }
    return 0;
}
```
## Pointer post-prefix increment

| Expression | Meaning | What changes? |
|---|---|---|
| `*p++` | `*(p++)` | Pointer address `p` changes |
| `*++p` | `*(++p)` | Pointer address `p` changes |
| `++*p` | `++(*p)` | Value `*p` changes |
| `(*p)++` | `(*p)++` | Value `*p` changes |
| `++(*p)` | `++(*p)` | Value `*p` changes |


## Decimal to hex conversion

```c
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
void dec_to_hex(int dec,char *hex,int *size){
    int idx = 0;
    for(int temp = 0;dec != 0;dec = dec / 16){
        temp = dec % 16;
        if(temp < 10){
            hex[idx++] = temp + '0';
        } else {
             hex[idx++] = temp + 'A';
        }
    }
    *size = idx -1;
}

int main() {
    int dec = 'Y';
    char ptr[8];
    memset(ptr,0,sizeof(ptr));
    
    int size;
    dec_to_hex(dec,ptr,&size);
    
    int idx = 7;
    while(size >= 0){
        printf("%c",ptr[size--]);
    }
    return 0;
}
```

## Virtaul function and pure virtual function difference.
## Diamond problem in C++
## Other use case of virtual keyword
### 1. Runtime Polymorphism

- Allows a derived class to **override base class methods.**

- Ensures **correct method is called** via base class pointer/reference.

### 2. Virtual Destructor

- Declaring `virtual ~Base()` ensures **derived class destructors run** when deleting through a base pointer.
  
- Prevents **resource leaks.**

### 3. Virtual Inheritance

- Solves** diamond problem** in multiple inheritance.

- Ensures **only one copy of the base class** exists.

### 4. Pure Virtual Functions (Abstract Classes)

- `virtual void func() = 0;`

- Makes class **abstract** → cannot instantiate.

- Forces derived classes to implement the function.

-----------------------------------------------------------------

# Kernel programming
## `restrict` Keyword in C99 — Notes with Examples

The `restrict` keyword was introduced in C99 to help the compiler optimize code by eliminating the possibility of pointer aliasing.

---

### What is `restrict`?

**These pointers are not sharing the same data**

- `restrict` is a **type qualifier** that applies only to **pointers**.
- It tells the compiler that the pointer is the **only reference** to the memory it points to.
- The compiler can assume **no other pointer** accesses the same memory during the pointer's lifetime.

---

### 🧠 Key Points

| Key Aspect       | Description |
|------------------|-------------|
| **Introduced in** | C99 |
| **Used with**     | Pointers only |
| **Purpose**       | Avoid pointer aliasing |
| **Benefit**       | Allows better compiler optimizations (e.g., vectorization) |
| **Risk**          | If violated, results in **undefined behavior** |
| **Works only if** | You **guarantee** no overlapping memory between pointers |

---

### 🧪 Example Code

#### ✅ Correct Usage

```c
#include <stdio.h>

void add_arrays(int *restrict a, int *restrict b, int *restrict result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
}
```

#### ❌ Incorrect Usage — Undefined Behavior

```c
#include <stdio.h>

void test(int *restrict a, int *restrict b) {
    *a = 10;
    *b = 20;
}

int main() {
    int x = 5;
    test(&x, &x);  // ❌ Violates restrict contract
    printf("%d\n", x);
    return 0;
}
```

## Strict Aliasing Rule

**Don't use different-type pointers to access the same data.**

The strict aliasing rule allows the compiler to assume that pointers to different types don’t point to the same memory.

**Same type → safe. Character type → safe for bytes. Unrelated type → don't do it**
### ❌ Bad Example (Undefined behavior):

```c
int i = 42;
float *f = (float*)&i;   // Violates strict aliasing
```

### ✅ Safe workaround:

```c
memcpy(&f, &i, sizeof(i));  // No aliasing violations
```

Violating this rule can cause the compiler to optimize in unsafe ways, leading to bugs.



## `volatile`
The volatile keyword tells the compiler:

> This variable can change at any time, outside the control of this code. Don’t optimize accesses to it.”

### 🔧 Use Cases:

- Hardware access (memory-mapped I/O)

- Shared variables in signal handlers

- Flags modified in setjmp/longjmp

- Multithreaded code (⚠️ but not safe for actual synchronization!)
  

### Example Recap (non-volatile flag):

```c
int flag = 0;

void wait_flag() {
    while (flag == 0) {
        // busy wait
    }
}
```

#### Step 1: Understanding the compiler’s assumptions

The compiler sees that:

- flag is a normal global variable.

- The only write to flag in the current translation unit (program) is outside of wait_flag() (or maybe no writes at all).

- In wait_flag(), flag is only read in the while condition.

- Since the compiler doesn't see any modification to flag inside wait_flag(), it assumes:

    > "The value of flag cannot change during the loop execution because there’s no code in this function modifying it."

#### Step 2: Optimization performed — Register caching

- The compiler loads the value of flag into a CPU register before entering the loop.

- It uses that cached value in the loop condition instead of reloading from memory every iteration.

- This is called register caching or value caching.

Intermediate code (conceptual):

```c
int temp = flag;  // load from memory once  flag = 0
while (temp == 0) {
    // loop infinitely because temp never changes
}
```

#### Step 3: Why this optimization makes sense

- This optimization is safe under the compiler’s assumptions:

- If no other code modifies flag concurrently (say, in a single-threaded program), reloading the variable each iteration wastes CPU cycles.

- So the compiler makes your program faster by avoiding unnecessary memory access.

#### Step 4: When this breaks — external changes

If flag is changed outside of this function, say by:

- Another thread,

- An interrupt,

- Hardware,

- then the cached temp will become stale.

- The compiler-generated code never sees the new value, so the loop becomes an infinite loop.

#### Step 5: How volatile fixes this

When flag is declared as volatile:

```c
volatile int flag = 0;
```

the compiler is told:

> "This variable may change at any time, even if the program doesn’t write to it directly."

So it:

- Disables register caching for flag.

- Forces the CPU to reload the value from memory every time the variable is accessed.

- This ensures changes made outside the function (e.g., another thread or interrupt) are seen.

#### Step 6: How the generated code differs

| Non-volatile (optimized)                | Volatile (no caching)                         |
| --------------------------------------- | --------------------------------------------- |
| `load flag` once                        | `load flag` every loop iteration              |
| Loop condition uses cached value        | Loop condition uses fresh memory value        |
| Infinite loop if external change occurs | Loop exits as soon as external change is seen |

#### Step 7: Real Assembly Example (simplified)

Suppose the compiler generates code like:

Non-volatile:

```asm
    mov eax, [flag]   ; Load flag into eax once
loop_start:
    cmp eax, 0        ; Compare eax with 0
    je loop_start     ; Jump back if zero
    ; exit loop
```

Volatile:

```asm
loop_start:
    mov eax, [flag]   ; Load flag from memory each iteration
    cmp eax, 0        ; Compare with 0
    je loop_start     ; Loop again if zero
    ; exit loop
```

Notice in the non-volatile version, the load happens once outside the loop, but in volatile, it happens every iteration.

## `const volatile`

Tells the compiler:

const = code can't write to it

volatile = value can still change, e.g., by hardware

Used for read-only hardware registers that change automatically


✅ Example:

| Version                                                                | Correct? | Why                   |
| ---------------------------------------------------------------------- | -------- | --------------------- |
| `const volatile uint32_t STATUS_REG = *(uint32_t*)0x40000000;`         | ❌ No     | Copies value once     |
| `#define STATUS_REG (*(const volatile uint32_t*)0x40000000)`           | ✅ Yes    | Always reads hardware |
| `const volatile uint32_t *ptr = (const volatile uint32_t*)0x40000000;` | ✅ Yes    | Pointer to hardware   |


```c
const volatile uint32_t STATUS_REG = *(uint32_t*)0x40000000;   // read only read once ❌ No 
/******
1. CPU reads the value at 0x40000000 once
2. Stores it into STATUS_REG
3. After that, STATUS_REG is just a normal variable

👉 So if the hardware register changes later, your variable does NOT update
*******/


#define STATUS_REG (*(const volatile uint32_t*)0x40000000u) // Always read hardware 

const volatile uint32_t *ptr = (const volatile uint32_t*)0x40000000 // Always read hardware 


```

| Declaration                    | Meaning                                                       | Can change value? | Can change pointer? | When value changes                                            | Simple Example Use                                            |
| ------------------------------ | ------------------------------------------------------------- | ----------------- | ------------------- | ------------------------------------------------------------- | ------------------------------------------------------------- |
| `int *p`                       | Normal pointer                                                | ✅ Yes             | ✅ Yes               | Only if program writes to it                                  | Normal variable array you can modify                          |
| `const int *p`                 | Pointer to read-only value                                    | ❌ No              | ✅ Yes               | Never (program cannot write)                                  | Read-only lookup table or config data                         |
| `volatile int *p`              | Pointer to value that can change outside program              | ✅ Yes             | ✅ Yes               | Can change anytime externally (hardware, ISR, another thread) | Writable hardware register (GPIO, UART)                       |
| `const volatile int *p`        | Pointer to read-only value that may change outside            | ❌ No              | ✅ Yes               | Can change anytime externally, program cannot write           | Read-only hardware status register or sensor                  |
| `int * const p`                | Pointer itself cannot change, value can                       | ✅ Yes             | ❌ No                | Only if program writes to it                                  | Fixed array pointer, buffer pointer you cannot move           |
| `const int * const p`          | Pointer cannot change, value cannot change                    | ❌ No              | ❌ No                | Never                                                         | Read-only pointer to ROM data or string literal               |
| `volatile int * const p`       | Pointer cannot change, value can change outside               | ✅ Yes             | ❌ No                | Can change anytime externally                                 | Fixed hardware register you can write to (GPIO output)        |
| `const volatile int * const p` | Pointer cannot change, value read-only but can change outside | ❌ No              | ❌ No                | Can change anytime externally, program cannot write           | Fixed hardware register you only read (status or ID register) |



## `_Atomic`

- _Atomic tells the compiler:
  > “This variable will be shared between threads and must be accessed safely without data races.”

- It makes sure operations on the variable happen all at once (atomically).

### Why do you need it?


- In programming, if two threads try to update the same variable without atomicity, you get wrong results.

```c
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

_Atomic int atomic_counter = 0;
int non_atomic_counter = 0;

void* do_work(void* arg) {
    for (int i = 0; i < 100000; i++) {
        atomic_fetch_add(&atomic_counter, 1); // Safe increment
        non_atomic_counter++;                   // Unsafe increment
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, do_work, NULL);
    pthread_create(&t2, NULL, do_work, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Atomic counter: %d\n", atomic_counter);       // Expected: 200000
    printf("Non-atomic counter: %d\n", non_atomic_counter); // Likely less than 200000

    return 0;
}
```

## What are Memory Barriers? Why Are They Important?

### why Memory barriers happened?

- **modern CPUs and compilers optimize execution for speed**, they may execute or arrange memory operations in a different order than the order written in your source code.

#### Why is this allowed?
There are several reasons:

  - **CPU pipelines:** The CPU has many instructions in flight simultaneously.

  - **Out-of-order execution:** The CPU can execute an instruction whose inputs are ready before an earlier instruction that is waiting.

  - **Store buffers:** Writes may temporarily sit in a buffer before becoming visible to other CPU cores.

  - **Caches:** Different cores may have different cached views of memory temporarily.

  - **Compiler optimizations:** The compiler can reorder instructions as long as the resulting behavior is valid under the language's memory rules.



Memory barriers (also called fences) prevent the CPU or compiler from reordering memory operations.

- Used to enforce correct ordering of reads/writes in multicore systems or with hardware.

- Crucial in synchronization, interrupts, and driver-hardware communication.


- **Without barrier**: CPU may reorder operations → bugs in multithreading.

- **With barrier:** Operations happen in the intended order → threads see consistent data.

- Memory barriers are often **built into locks and atomic operations**, so you don’t always need them manually.

### ❌ Example Without Memory Barrier (Possible Bug)

```c
// Thread 1
X = 1;       // Step 1
Y = 1;       // Step 2

// Thread 2
if (Y == 1) {
    printf("%d\n", X);
}

```

#### ❓What You Expect

> If Y == 1, then X should be 1, right?

#### ⚠️ What Can Go Wrong:

Modern CPUs may reorder instructions like this in Thread 1:

```c
Y = 1;       // Reordered first
X = 1;       // Reordered second
```

### ✅ Example WITH Memory Barrier (Correct)

Let’s now use a memory barrier to force the correct order:

```c
//🔧 Thread 1 (Writer):


X = 1;
__sync_synchronize();   // Full memory barrier
Y = 1;


// Thread 2 (Reader):

if (Y == 1) {
    __sync_synchronize();  // Full memory barrier
    printf("%d\n", X);
}

```

#### ✅ Now Guaranteed

- If Thread 2 sees Y == 1, then X == 1 is guaranteed

- Because the memory barrier forces the CPU to:

- Store X = 1 before Y = 1

- And read X after confirming Y == 1


### barriar type

| Barrier | Orders           | Use When                          |
| ------- | ---------------- | --------------------------------- |
| `wmb()` | Writes only      | You need to order writes for sync |
| `rmb()` | Reads only       | You need to order reads           |
| `mb()`  | Reads and Writes | You need total ordering of memory |


### Are __sync_synchronize(); and mb() the same?

| Aspect              | `__sync_synchronize();`                                          | `mb()`                                                       |
| ------------------- | ---------------------------------------------------------------- | ------------------------------------------------------------ |
| **What is it?**     | GCC/Clang compiler built-in                                      | Macro/function usually in Linux kernel                       |
| **Type of barrier** | Full memory barrier (read + write)                               | Full memory barrier (read + write)                           |
| **Scope**           | Compiler + CPU barrier                                           | CPU barrier (often also prevents compiler reordering)        |
| **Usage context**   | Used in user-space and kernel code                               | Mostly used in Linux kernel and low-level code               |
| **Guarantees**      | Prevents CPU + compiler from reordering any memory ops across it | Same: prevents reordering of any memory ops across it        |
| **Portability**     | Works where GCC/Clang supports                                   | Depends on architecture and platform (Linux kernel specific) |



| **Barrier** | **Orders**           | **Use When**                                                                                                                             |
| ----------- | -------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| `wmb()`     | **Writes only**      | You want **all writes before this point** to happen before **writes after it**. Useful for **synchronizing data being written**.         |
| `rmb()`     | **Reads only**       | You want **all reads before this point** to happen before **reads after it**. Useful when a thread must **see data in correct order**.   |
| `mb()`      | **Reads and Writes** | You want **total ordering** of memory: all reads and writes **before the barrier** happen before any reads/writes **after the barrier**. |


```c
int x = 0, y = 0;

// Thread 1: Writing data
x = 1;       
wmb();      // Ensure x is written before y
y = 2;

// Thread 2: Reading data
rmb();      // Ensure we read y first, then x
if (y == 2) {
    printf("x = %d\n", x); // Always prints 1
}
```
## What is the difference between `static`, `extern`, and `static inline` functions in the kernel?
| Feature                  | `static`                 | `extern`              | `static inline`                              |
| ------------------------ | ------------------------ | --------------------- | -------------------------------------------- |
| Visibility               | Current file only        | Across files          | Current file only                            |
| Function symbol          | Yes (normal function)    | Yes (from other file) | Often **no symbol** if inlined               |
| Compiler inlining        | Optional                 | Optional              | Suggested (may force with `__always_inline`) |
| Use case in kernel       | Private helper functions | Cross-file functions  | Hot-path / header helper functions           |
| Generated in object file | Yes                      | Yes                   | Only if not inlined                          |



## How is `inline` Used in Kernel Code? What's the Role of `__always_inline`?

- `inline` : Suggests the compiler to inline the function (replace call with code).

- `__always_inline`: Forces the compiler to always inline the function.

| Feature                          | `inline`                                      | `__always_inline`                              |
| -------------------------------- | --------------------------------------------- | ---------------------------------------------- |
| Compiler behavior                | Suggestion, may ignore                        | Mandatory (forces inline)                      |
| Function call overhead           | Might exist if not inlined                    | Never, always replaced with code               |
| Typical use                      | Small utility functions, optional performance | Critical hot paths, low-level kernel functions |
| Compiler optimization dependence | Yes, depends on optimization level            | No, inlined even without -O optimizations      |



## What is the Role of `container_of()` Macro?

Used to get the parent structure from a pointer to one of its members.

```c
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

```

Example 

```c
#include <stdio.h>
#include <stddef.h>  // for offsetof

struct Person {
    int age;
    char name[20];
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

int main() {
    struct Person p = { 30, "Bob" };

    int *age_ptr = &p.age;  // pointer to member

    // Get pointer to struct Person from pointer to age
    struct Person *p_ptr = container_of(age_ptr, struct Person, age);

    printf("Name: %s, Age: %d\n", p_ptr->name, p_ptr->age);

    return 0;
}

// Name: Bob, Age: 30
```
## Use of typeof() and Its Role in Kernel Macros

`typeof(x)` gets the type of x at compile time.

Used in macros to write type-safe, generic code.

## What are `__init` and` __exit` in Kernel Modules?

Every kernel module needs:

- A function to run when the module is loaded (like setup/init)

- A function to run when the module is removed (like cleanup)

### ✅ ==__init — Marks the Initialization Function

Used before the function that runs when the module is loaded

Tells the kernel:

- "After the module is loaded, this function’s memory can be freed."

- ✔️ This saves memory — because that function is not needed anymore after loading.

### ❌ __exit — Marks the Cleanup Function

Used before the function that runs when the module is removed

Tells the kernel:

- "This function is only needed if the module can be removed."

- 🚫 If the kernel is compiled without module unloading, this function will be ignored and not included in the final kernel image.

### 🧾 Simple Example

```c
#include <linux/module.h>
#include <linux/init.h>

static int __init my_module_init(void) {
    printk(KERN_INFO "My Module Loaded!\n");
    return 0;
}

static void __exit my_module_exit(void) {
    printk(KERN_INFO "My Module Removed!\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
```

#### What happens here?

- my_module_init() is marked with __init → called when the module is loaded

- my_module_exit() is marked with __exit → called when the module is removed

## What is Pointer Alignment?

Pointer alignment means that data (like `int`, `char`, `struct`, etc.) is stored in memory at addresses that are multiples of their size.

For example:

A 4-byte int is best aligned at an address like 0x1000, 0x1004, 0x1008... (i.e., multiples of 4)

An 8-byte pointer on a 64-bit system should be at addresses like 0x2000, 0x2008, 0x2010...


But in the kernel, correct alignment is critical.


### ✅ Simple Example

Aligned struct:
```c
struct Aligned {
    int a;       // 4 bytes
    char b;      // 1 byte
    // Padding: 3 bytes (to make the next int aligned)
    int c;       // 4 bytes
};

```
Memory layout:

| Offset | Data    |
| ------ | ------- |
| 0      | int a   |
| 4      | char b  |
| 5-7    | padding |
| 8      | int c   |


This is aligned properly, so it’s fast and safe.

#### ❌ What if it’s misaligned?

```c
char buffer[100];
int *p = (int *)(buffer + 1); // Not aligned!
*p = 123; // 🚫 Bad!
```

- buffer + 1 might be at address like 0x1001 → not a multiple of 4

- On x86, this might work but be slow

- On ARM or RISC-V, this might cause a kernel crash (alignment fault)

### 🔧 In Kernel Code

- Linux kernel enforces proper alignment for `structs`, `pointers`, `DMA buffers`, etc.

- Often uses macros like `ALIGN()`, `__aligned(x)`, or packed structs carefully.

### 🛠 How to Ensure Proper Alignment?

| Macro                         | Purpose                             |
| ----------------------------- | ----------------------------------- |
| `__aligned(n)`                | Align variable/struct to `n` bytes  |
| `__attribute__((aligned(n)))` | GCC syntax for alignment            |
| `PTR_ALIGN(ptr, n)`           | Round pointer up to multiple of `n` |
| `IS_ALIGNED(ptr, n)`          | Check if pointer is aligned         |


### Kernel memory 

```c
#include <linux/slab.h>
#include <linux/kernel.h>

void *buf;
buf = kmalloc(1024, GFP_KERNEL);         // may not be aligned for DMA
buf = PTR_ALIGN(buf, 64);                // align pointer to 64 bytes
```

### DMA Alignment
```c
dma_addr_t dma_addr;
void *buf = dma_alloc_coherent(dev, 1024, &dma_addr, GFP_KERNEL);

// `dma_alloc_coherent` guarantees buffer is aligned for device
```

## How are bitfields used in hardware registers?

### Step 1: Define a bitfield in C
```c
typedef struct {
    uint8_t STATUS : 1;  // bit 0
    uint8_t ENABLE : 1;  // bit 1
    uint8_t MODE   : 2;  // bits 2-3
    uint8_t UNUSED : 4;  // bits 4-7
} Reg;
```

### Step 2: Access the bits

```c
volatile Reg *reg = (volatile Reg *)0x4000; // address of register

reg->ENABLE = 1;  // turn ON
reg->MODE = 3;    // set mode = 3
if(reg->STATUS) {
    // do something if status bit is set
}
```




## Difference Between `kmalloc()` and `vmalloc()`

- **kmalloc()**:

    - Allocates physically contiguous memory and virtual contiguos memory.

    - Fast, suitable for hardware access (DMA).

- **vmalloc()**:

    - Allocates virtually contiguous memory (may not be physically contiguous).

    - Used for larger buffers that don’t need to be DMA-able.



## What is Unaligned Memory Access?

### Unaligned Memory Access

- When your computer reads or writes data (like an int or struct), it expects the data to start at certain memory addresses — these are called aligned addresses.

- If the data starts at a "weird" address, that's not what the CPU expects — this is called unaligned access.

### ✅ Aligned Example

- You store a u32 at address 0x1000 → this is divisible by 4.

- The CPU is happy. Fast and safe.

### ❌ Unaligned Example

- You store a u32 at address 0x1001 → not divisible by 4.

- The CPU is confused or slower.

  - Some CPUs will crash.

  - Others will handle it more slowly.

### All possible way to handle unaligned memory access
```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/unaligned/access_ok.h>  // get_unaligned / put_unaligned
#include <linux/string.h>               // memcpy
#include <linux/io.h>                   // readl / writel

static int __init unaligned_example_init(void)
{
    u8 buffer[16];
    u32 val1, val2, val3, val4, val5;

    printk(KERN_INFO "Unaligned access demo start\n");

    // ---------------------------------------------------------
    // Method 1: get_unaligned() / put_unaligned()
    // ---------------------------------------------------------
    put_unaligned(0xDEADBEEF, (u32 *)(buffer + 1));
    val1 = get_unaligned((u32 *)(buffer + 1));
    printk(KERN_INFO "Method 1 (get/put_unaligned): 0x%x\n", val1);

    // ---------------------------------------------------------
    // Method 2: memcpy()
    // ---------------------------------------------------------
    u32 write_val = 0xCAFEBABE;
    memcpy(buffer + 2, &write_val, sizeof(u32));
    memcpy(&val2, buffer + 2, sizeof(u32));
    printk(KERN_INFO "Method 2 (memcpy): 0x%x\n", val2);

    // ---------------------------------------------------------
    // Method 3: Byte-wise access
    // ---------------------------------------------------------
    buffer[4] = 0x78;
    buffer[5] = 0x56;
    buffer[6] = 0x34;
    buffer[7] = 0x12;

    val3 = buffer[4] |
          (buffer[5] << 8) |
          (buffer[6] << 16) |
          (buffer[7] << 24);

    printk(KERN_INFO "Method 3 (byte-wise): 0x%x\n", val3);

    // ---------------------------------------------------------
    // Method 4: Direct unaligned access (CPU dependent)
    // WARNING: May crash on some architectures!
    // ---------------------------------------------------------
    *(u32 *)(buffer + 3) = 0xAABBCCDD;
    val4 = *(u32 *)(buffer + 3);
    printk(KERN_INFO "Method 4 (direct access - unsafe): 0x%x\n", val4);

    // ---------------------------------------------------------
    // Method 5: Packed struct + get_unaligned()
    // ---------------------------------------------------------
    struct __attribute__((__packed__)) my_struct {
        u16 a;
        u32 b;
    };

    struct my_struct *p = (struct my_struct *)(buffer + 5);
    put_unaligned(0x11223344, &p->b);
    val5 = get_unaligned(&p->b);

    printk(KERN_INFO "Method 5 (packed struct): 0x%x\n", val5);

    // ---------------------------------------------------------
    // Method 6: Aligned access (for comparison)
    // ---------------------------------------------------------
    u32 *aligned_ptr = (u32 *)(buffer + 8); // likely aligned
    *aligned_ptr = 0x55667788;
    printk(KERN_INFO "Method 6 (aligned access): 0x%x\n", *aligned_ptr);

    // ---------------------------------------------------------
    // Method 7: I/O accessors (for MMIO, example only)
    // NOTE: This is just illustrative; not usable on normal buffer
    // ---------------------------------------------------------
    /*
    void __iomem *reg = ioremap(0x1000, 4);
    writel(0x12345678, reg);
    printk(KERN_INFO "Method 7 (IO accessors): 0x%x\n", readl(reg));
    iounmap(reg);
    */

    return 0;
}

static void __exit unaligned_example_exit(void)
{
    printk(KERN_INFO "Unaligned access demo end\n");
}

module_init(unaligned_example_init);
module_exit(unaligned_example_exit);

MODULE_LICENSE("GPL");
```
- Best (kernel): `get_unaligned()`
- Best (portable C): `memcpy()`
- Always safe: `byte-wise`
- Fastest: `aligned access`
- Risky: `direct access`
- Special case: `I/O accessors` for hardware

## Difference Between `memcpy()` and `memmove()` in Kernel Space

| Feature            | `memcpy()`                  | `memmove()`               |
| ------------------ | --------------------------- | ------------------------- |
| Overlapping memory | ❌ **Not safe**              | ✅ **Safe**                |
| Performance        | 🚀 Faster                   | 🐢 Slightly slower        |
| Use case           | Non-overlapping buffers     | Overlapping buffers       |
| Behavior           | Undefined if overlap occurs | Handles overlap correctly |


```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>  // memcpy, memmove

static int __init mem_example_init(void)
{
    char buf1[10] = "ABCDE";
    char buf2[10] = "ABCDE";

    printk(KERN_INFO "Original buf1: %s\n", buf1); // ABCDE
    printk(KERN_INFO "Original buf2: %s\n", buf2); // ABCDE

    // ---------------------------------------------------------
    // memcpy() with overlapping memory (UNSAFE)
    // ---------------------------------------------------------
    /*
     * Layout before:
     * buf1 = [A][B][C][D][E][\0]
     *         0  1  2  3  4
     *
     * Operation:
     * memcpy(buf1 + 1, buf1, 4);
     * Copy 4 bytes from index 0 → index 1
     *
     * Problem:
     * Source and destination overlap!
     * memcpy does forward copy without handling overlap.
     */

    memcpy(buf1 + 1, buf1, 4);

    /*
     * Possible step-by-step corruption:
     * Step 1: copy A → position 1 → [A][A][C][D][E]
     * Step 2: copy (overwritten A) → position 2 → [A][A][A][D][E]
     * Step 3: copy (overwritten A) → position 3 → [A][A][A][A][E]
     * Step 4: copy (overwritten A) → position 4 → [A][A][A][A][A]
     *
     * Final result (undefined behavior):
     * buf1 = "AAAAA"  (or other corrupted result depending on CPU)
     */

    printk(KERN_INFO "After memcpy (overlap): %s\n", buf1);


    // ---------------------------------------------------------
    // memmove() with overlapping memory (SAFE)
    // ---------------------------------------------------------
    /*
     * Layout before:
     * buf2 = [A][B][C][D][E][\0]
     *
     * Operation:
     * memmove(buf2 + 1, buf2, 4);
     *
     * memmove detects overlap and copies BACKWARD:
     */

    memmove(buf2 + 1, buf2, 4);

    /*
     * Safe step-by-step (backward copy):
     * Step 1: copy D → position 4 → [A][B][C][D][D]
     * Step 2: copy C → position 3 → [A][B][C][C][D]
     * Step 3: copy B → position 2 → [A][B][B][C][D]
     * Step 4: copy A → position 1 → [A][A][B][C][D]
     *
     * Final result:
     * buf2 = "AABCD"
     */

    printk(KERN_INFO "After memmove (overlap): %s\n", buf2);

    return 0;
}

static void __exit mem_example_exit(void)
{
    printk(KERN_INFO "Memcpy vs Memmove module unloaded\n");
}

module_init(mem_example_init);
module_exit(mem_example_exit);

MODULE_LICENSE("GPL");
```

## Unions in Hardware Register Definitions — Explained with Example

### Why use unions?

- Hardware registers are fixed-size memory locations (often 32-bit).

- Sometimes, you want to:

    - Access the whole register value at once.

    - Access individual bits or bit fields for control flags.

    - A union lets you access the same memory area in different ways (as a full integer or as individual bits).
  
```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>

/*
 * Define a union representing a 32-bit hardware register
 * It provides:
 * 1. Full register access using 'value'
 * 2. Bit-level access using 'bits'
 */
typedef union {
    uint32_t value;   // Full 32-bit register access

    struct {
        uint32_t ENABLE : 1;   // bit 0
        uint32_t MODE   : 3;   // bits 1-3
        uint32_t READY  : 1;   // bit 4
        uint32_t UNUSED : 27;  // bits 5-31
    } bits;

} my_reg_t;

static int __init union_reg_init(void)
{
    /*
     * Simulating a hardware register using a variable
     * In real drivers, this would be a memory-mapped address:
     * volatile my_reg_t *reg = (volatile my_reg_t *)0x40000000;
     */
    volatile my_reg_t reg;

    printk(KERN_INFO "Union Register Demo Start\n");

    // ---------------------------------------------------------
    // Method 1: Write full register
    // ---------------------------------------------------------
    reg.value = 0x00000000;  
    /*
     * All bits are cleared:
     * ENABLE = 0
     * MODE   = 0
     * READY  = 0
     */
    printk(KERN_INFO "Initial value: 0x%x\n", reg.value);

    // ---------------------------------------------------------
    // Method 2: Set individual bit fields
    // ---------------------------------------------------------
    reg.bits.ENABLE = 1;   // Set bit 0
    reg.bits.MODE   = 5;   // Set bits 1-3 (binary 101)
    /*
     * Now register looks like:
     * bit0 (ENABLE) = 1
     * bits1-3 (MODE) = 101
     *
     * Binary: 0000 0000 0000 0000 0000 0000 0000 1011
     * Hex   : 0x0000000B
     */
    printk(KERN_INFO "After setting fields: 0x%x\n", reg.value);

    // ---------------------------------------------------------
    // Method 3: Read individual field
    // ---------------------------------------------------------
    if (reg.bits.ENABLE) {
        printk(KERN_INFO "ENABLE bit is set\n");
    }

    printk(KERN_INFO "MODE value: %u\n", reg.bits.MODE);

    // ---------------------------------------------------------
    // Method 4: Modify full register
    // ---------------------------------------------------------
    reg.value = 0x00000010;  
    /*
     * Only bit 4 is set (READY)
     * Binary: 0001 0000
     */
    printk(KERN_INFO "After writing full value: 0x%x\n", reg.value);

    // ---------------------------------------------------------
    // Method 5: Check READY bit
    // ---------------------------------------------------------
    if (reg.bits.READY) {
        printk(KERN_INFO "READY bit is set\n");
    } else {
        printk(KERN_INFO "READY bit is NOT set\n");
    }

    /*
     * Key Concept:
     * - 'value' and 'bits' share same memory (union)
     * - Changing one automatically reflects in the other
     */

    return 0;
}

static void __exit union_reg_exit(void)
{
    printk(KERN_INFO "Union Register Demo End\n");
}

module_init(union_reg_init);
module_exit(union_reg_exit);

MODULE_LICENSE("GPL");
```

## How to Prevent Structure Padding in C (for Memory-Mapped I/O)

### 1. Using __attribute__((packed)) in GCC
```c
struct __attribute__((packed)) mmio_regs {
    u8  reg1;   // 1 byte
    u16 reg2;   // 2 bytes
    u32 reg3;   // 4 bytes
};
```
- packed tells the compiler: **do not insert padding.**

- Now the struct matches the **exact hardware layout.**

### 2. Using #pragma pack (MSVC or GCC)
```c
#pragma pack(push, 1)   // align on 1-byte boundary
struct mmio_regs {
    u8  reg1;
    u16 reg2;
    u32 reg3;
};
#pragma pack(pop)
```

### 3. Memory-Mapped I/O Register Structure
```c
struct __attribute__((packed)) device_regs {
    u8  control;   // offset 0x00
    u8  status;    // offset 0x01
    u16 data;      // offset 0x02
    u32 addr;      // offset 0x04
};
```
- Each member is at the **exact offset** expected by the hardware.

- You can now safely cast a memory-mapped address to this struct:

```c
volatile struct device_regs *regs = (volatile struct device_regs *)0xF0000000;
regs->control = 0x1;  // safe write
u32 value = regs->addr; // safe read
```

## How do `copy_from_user()` and `copy_to_user()` work?

- These are helper functions in the Linux kernel to safely copy data between `user space` and `kernel space`.

- `copy_from_user(void *to, const void __user *from, unsigned long n)` copies `n` bytes from user space address  `from` to kernel space address `to`.

- `copy_to_user(void __user *to, const void *from, unsigned long n)` copies `n` bytes from kernel space address `from` to user space address `to`.

- They check memory access validity and handle faults if the user pointer is invalid or inaccessible.

Example:

```c
char kernel_buffer[100];
char __user *user_buffer = ...;

if (copy_from_user(kernel_buffer, user_buffer, 100)) {
    printk(KERN_ERR "Failed to copy from user\n");
    return -EFAULT;
}
```

## Why can't you directly dereference user-space pointers in kernel?

Because user-space pointers are virtual addresses valid only in user context. Kernel operates in a different address space context, so direct dereferencing:

- Can cause page faults or kernel crashes if the pointer is invalid.

- Breaks security by allowing kernel to accidentally access or corrupt user memory.

The kernel uses safe functions like `copy_from_user()` to validate and safely access user memory.


## Difference between `get_user()` and `copy_from_user()`?

- `get_user()` copies a single simple value (like an int, char) from user space.

- `copy_from_user()` copies a block of memory (multiple bytes).

```c

// Reading value from user space 
int val;
if (get_user(val, (int __user *)user_ptr)) {
    return -EFAULT;
}

// reading block of memory

char buffer[20];
if (copy_from_user(buffer, user_ptr, 20)) {
    return -EFAULT;
}

```

## Risks of using  `memcpy()` with user-space pointers?

`memcpy()` assumes both source and destination pointers are valid kernel addresses. Using `memcpy()` on user-space pointers:

  - May cause kernel crashes or page faults if user pointer is invalid.

  - Does no access checks or fault handling.

  - Opens security risks (kernel could read/write invalid or malicious memory).

## How do you perform DMA mapping in kernel?

### 1️⃣ What is DMA?

**DMA (Direct Memory Access)** lets a device (like a network card, disk, or sound card) **read or write memory directly** without bothering the CPU.

#### What DMA Mapping Is (in simple words)

- **CPU memory** = the memory your computer’s brain (CPU) uses.

- **Device** = something like a network card, hard drive, or GPU that needs to read/write data.

- **Problem**: Devices can’t always understand CPU memory directly—they need it in a “language” or form they can access.


**DMA mapping** is like giving the device a map to find the memory it needs.

1. You have data in CPU memory.

2. DMA mapping **tells the device where in memory the data is and how to reach it safely**.

3. The device can then **read or write data directly without bothering the CPU** for every single piece of data.






### 2️⃣ How DMA Mapping Works
When you “map” memory for DMA:

1. **Allocate memory in the CPU space** (kernel or user memory).

2. **Translate the addresses** into a form the device can understand (often a physical address or I/O virtual address).

3. **Pass the mapped address** to the device so it can read/write data directly.

4. After the device is done, **unmap** the memory to clean up and maintain cache coherency.

This often involves:

- **Bounce buffers:** Temporary memory areas for devices that can’t access all physical memory.

- **IOMMU** (Input-Output Memory Management Unit): Hardware that automatically translates addresses for the device.

In modern systems, there are complications:

- Devices can’t always access all physical memory (especially on high-memory systems or IOMMUs).

- CPU virtual addresses (like `kmalloc`) may not be contiguous physically.

**So we map CPU memory into a form the device can access. This is called DMA mapping.**

```c
#include <linux/dma-mapping.h>
#include <linux/slab.h>   // for kmalloc

#define BUF_SIZE 2048

void example_dma_receive(struct device *dev)
{
    void *cpu_buffer;        // Virtual address used by CPU
    dma_addr_t dma_addr;     // DMA address used by device

    /* ---------------------------------------------------- */
    /* STEP 1: CREATE MEMORY (CPU SIDE)                     */
    /* ---------------------------------------------------- */

    /*
     * kmalloc() allocates memory in RAM.
     * This returns a VIRTUAL address that ONLY the CPU understands.
     *
     * At this point:
     *   CPU can use cpu_buffer
     *   Device CANNOT use it yet
     */
    cpu_buffer = kmalloc(BUF_SIZE, GFP_KERNEL);

    if (!cpu_buffer)
        return;

    /* ---------------------------------------------------- */
    /* STEP 2: MAP MEMORY FOR DMA (DEVICE SIDE)             */
    /* ---------------------------------------------------- */

    /*
     * dma_map_single() converts the CPU virtual address
     * into a DMA address that the DEVICE understands.
     *
     * Internally this may:
     *   - Convert virtual -> physical address
     *   - Setup IOMMU mapping (if system has one)
     *   - Handle cache synchronization
     *
     * After this:
     *   cpu_buffer  -> used by CPU
     *   dma_addr    -> given to device hardware
     */
    dma_addr = dma_map_single(dev,
                              cpu_buffer,
                              BUF_SIZE,
                              DMA_FROM_DEVICE);

    if (dma_mapping_error(dev, dma_addr)) {
        printk("DMA mapping failed\n");
        kfree(cpu_buffer);
        return;
    }

    /* ---------------------------------------------------- */
    /* STEP 3: DEVICE USES DMA ADDRESS                      */
    /* ---------------------------------------------------- */

    /*
     * You now program the hardware (for example,
     * a network card register) with dma_addr.
     *
     * The device will:
     *   Write received data directly into RAM
     *   at the memory location represented by dma_addr
     *
     * CPU is NOT involved in copying data.
     */


    /* ---------------------------------------------------- */
    /* STEP 4: UNMAP AFTER DEVICE FINISHES                  */
    /* ---------------------------------------------------- */

    /*
     * dma_unmap_single() tells the kernel:
     *   "Device is done using this memory"
     *
     * This ensures:
     *   - Cache is synchronized
     *   - Mapping is removed if IOMMU is used
     */
    dma_unmap_single(dev,
                     dma_addr,
                     BUF_SIZE,
                     DMA_FROM_DEVICE);

    /*
     * Now CPU can safely read data from cpu_buffer.
     */

    kfree(cpu_buffer);  // Free memory when done
}
```

## Explain page faults in kernel mode and how to avoid them.

### What is a page fault in kernel mode?

- Happens when the kernel tries to access memory that is not currently available or not mapped.

- For example, if the memory is swapped out or invalid.

### Why are page faults tricky in the kernel?

- Kernel often runs in atomic context (interrupts disabled or holding locks).

- In atomic context, the kernel cannot wait or sleep to handle page faults.

- If a page fault occurs here, it can crash or hang the system.

### How to avoid page faults in kernel mode?

- Don’t directly access user memory pointers in the kernel.

- Use safe APIs like:

```c
copy_from_user()
copy_to_user()
get_user() / put_user()
```

These functions check and handle faults safely.

Avoid accessing memory that can be swapped out or unmapped during atomic operations.


## What happens if a kernel module dereferences a null pointer?

- Kernel will crash with a NULL pointer dereference, leading to kernel panic or oops.

- This halts the system or crashes the module.

- A **kernel panic** is basically a fatal error in the Linux kernel where the kernel reaches a state it **cannot safely recover from**.
  
- **Always check pointers before dereferencing.**

## How is memory protection handled between user and kernel space?

- CPU hardware uses different privilege levels (rings).

- Memory management unit (MMU) separates user and kernel virtual memory.

- User mode processes cannot access kernel memory directly.

- Kernel runs in privileged mode and can access both user and kernel space.

## What is the slab allocator? How does it differ from the buddy allocator?

- Slab allocator manages caches of frequently used objects (like struct task_struct), optimized for small allocations and reuses memory objects efficiently.

- Buddy allocator handles larger, contiguous physical memory pages.

- Slab allocates fixed-size objects; buddy allocates pages.

## How does `kmem_cache_create()` help performance?

- It creates a cache of pre-allocated objects to reduce allocation overhead.

- Speeds up allocation/deallocation of frequently used kernel objects.

- Minimizes fragmentation and initialization cost.

## How do you debug kernel memory leaks?

### ✅ 1. Use `kmemleak` (Kernel Memory Leak Detector)

A built-in tool in the Linux kernel for tracking memory leaks.

Works like a garbage collector: scans memory and reports unreferenced allocations.

📌 Steps:

#### 1.Enable it in the kernel config

```ini
CONFIG_DEBUG_KMEMLEAK=y
```
| Step | Command | Purpose |
|---:|---|---|
| 1 | `cd linux` | Enter kernel source |
| 2 | `make menuconfig` | Configure kernel options |
| 3 | Enable `CONFIG_DEBUG_KMEMLEAK` | Enable kmemleak |
| 4 | `grep CONFIG_DEBUG_KMEMLEAK .config` | Verify configuration |
| 5 | `make -j$(nproc)` | Build the kernel |
| 6 | `sudo make modules_install` | Install kernel modules |
| 7 | `sudo make install` | Install kernel |
| 8 | Reboot | Boot the new kernel |
| 9 | `uname -r` | Verify running kernel |
| 10 | `sudo mount -t debugfs none /sys/kernel/debug` | Mount debugfs if needed |
| 11 | `echo scan | sudo tee /sys/kernel/debug/kmemleak` | Run kmemleak scan |
| 12 | `sudo cat /sys/kernel/debug/kmemleak` | View suspected leaks |


- This is a **kernel configuration option**
- It **enables the kmemleak feature at compile time**

- You must **recompile the kernel** after enabling this
- It **cannot be enabled at runtime**



### 2. Use slabtop


| Step | Command | Purpose |
|---|---|---|
| 1 | `sudo slabtop` | Check memory |
| 2 | Run test | Allocate memory |
| 3 | `slabtop` | Check again |
| 4 | Repeat | Find growth |
| 5 | `kmemleak` | Confirm leak |


## What does "*sleeping*" mean in memory allocation?

When you allocate memory in the Linux kernel (e.g., using `kmalloc()` with `GFP_KERNEL`), and no free memory is immediately available, the kernel might:

Put the current process to sleep (i.e., `wait/block`),

While it tries to:

- **Reclaim memory** → Free memory that is no longer actively needed, such as caches.

- **Swap out pages** → Move less-used memory pages from RAM to swap space on disk.

- **Wait for memory to become available** → Pause the requesting process until other memory can be freed.

⚠️ This **sleep is only allowed in process context, not in atomic/interrupt context**.

## What are GFP Flags?

- GFP = Get Free Pages

- GFP flags tell the kernel how to allocate memory.

- They control:

    - Whether allocation can sleep (wait)

    - Whether memory comes from low or high memory

    - Special needs (e.g., DMA-safe memory)


### Common GFP Flags and Their Use

| Flag           | Meaning                                | Can Sleep? | Used in...                 |
| -------------- | -------------------------------------- | ---------- | -------------------------- |
| `GFP_KERNEL`   | Normal allocation (can block/sleep)    | ✅ Yes      | Most kernel code           |
| `GFP_ATOMIC`   | Fast, non-blocking (can't sleep)       | ❌ No       | Interrupts, atomic context |
| `GFP_HIGHUSER` | From high memory (not directly mapped) | ✅ Yes      | User-space buffers         |
| `GFP_DMA`      | Memory below 16MB (DMA-capable)        | ✅ Yes      | Legacy devices needing DMA |
----------------------
## What is the `highmem zone` and how do you access it?

### What is **HighMem**?

- In **32-bit Linux**, the CPU can address **4GB of memory**.

- This **4GB virtual address space is divided into**:

  - **User space (~3GB)** → for applications

  - **Kernel space (~1GB)** → for the OS

- **Problem**: Some systems **have more than 1GB of RAM**.

  - Kernel cannot map all physical memory directly in its 1GB virtual space.

  - The **extra memory becomes High Memory** (HighMem).


### Memory Zones in Linux Kernel
Linux divides physical memory into zones:

| Zone             | Purpose                                                             |
| ---------------- | ------------------------------------------------------------------- |
| **ZONE_DMA**     | For devices that can only do DMA on low addresses (old hardware)    |
| **ZONE_NORMAL**  | Directly mapped memory kernel can always access                     |
| **ZONE_HIGHMEM** | Memory not permanently mapped, must be temporarily mapped to access |

- **ZONE_NORMAL** → Kernel can directly dereference pointers

- **ZONE_HIGHMEM** → Kernel cannot directly dereference, must map first

### How to Access HighMem

- **HighMem access is required mainly when kernel code needs to access a physical page that is not permanently mapped into the kernel's virtual address space.**

- This is mostly relevant to `32-bit Linux `systems with lots of RAM.
Since kernel cannot access HighMem directly:


| API | Purpose |
|---|---|
| `kmap_local_page()` | Temporarily map a HighMem page |
| `kunmap_local()` | Unmap it |
| `kmap()` | Map a page into kernel address space |
| `kunmap()` | Remove the mapping |
| `kmap_atomic()` | Older API for atomic mappings |


1. `Use kmap()`
```c
struct page *page = ...;   // HighMem page
void *vaddr = kmap(page);  // Temporarily map
// Access memory using vaddr
kunmap(page);              // Unmap when done
```
- **Can sleep**, slower
2. Use `kmap_atomic()`
```c
void *vaddr = kmap_atomic(page);  // Fast, no sleep
// Access memory
kunmap_atomic(vaddr);             // Unmap
```
- Used in **interrupts** or **critical sections**

### Why HighMem Is Mostly 32-bit Only

- **32-bit kernel** has limited **virtual address space (~1GB)** for kernel

- **HighMem** handles RAM beyond that limit

- 64-bit kernel has virtually unlimited address space, so HighMem is unnecessary

## How do you prevent stack overflows in kernel code?

The kernel stack is very small — usually 8KB per thread.
Stack overflows can crash the system, so it's important to use it carefully.

### ✅ Tips to Prevent Stack Overflows:

#### Avoid large local variables

- ❌ Bad: `char big_buffer[4096]`; → uses too much stack

- ✅ Use `kmalloc()` to allocate large memory on the heap

### Keep functions simple

- Don’t write deeply **nested** or **recursive** functions

- **Split large functions** into smaller ones

#### Use static analysis tools

- Tools like `smatch`, `clang-analyzer`, or `sparse` can detect risky stack use

### Use compiler stack checks

Enable `CONFIG_DEBUG_STACKOVERFLOW` in the kernel config to detect overflows at runtime


## When do you use mutext and shemphore

### Mutex
> I use a mutex to protect a shared resource so that only one task accesses it at a time."
> This is ownership mechanism, its takes ownership until mutex is released.


```c
#include <stdio.h>
#include <pthread.h>

int counter = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg)
{
    pthread_mutex_lock(&lock);

    /* Critical section */
    counter++;
    printf("Counter = %d\n", counter);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_function, NULL);
    pthread_create(&t2, NULL, thread_function, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}

```
```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;

/* Mutex protects the shared counter */
std::mutex mtx;

void increment()
{
    for (int i = 0; i < 100000; i++)
    {
        /*
         * Lock the mutex.
         * Only one thread can enter this section
         * at a time.
         */
        mtx.lock();

        counter++;

        /*
         * Release the mutex.
         */
        mtx.unlock();
    }
}

int main()
{
    std::thread t1(increment);
    std::thread t2(increment);

    /* Wait for both threads to finish */
    t1.join();
    t2.join();

    std::cout << "Counter = " << counter << std::endl;

    return 0;
}
```
#### Mutex deadloack
```c
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex m1;
std::mutex m2;

void thread1()
{
    m1.lock();
    std::cout << "T1 locked m1\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    m2.lock();   // waits for T2
    std::cout << "T1 locked m2\n";

    m2.unlock();
    m1.unlock();
}

void thread2()
{
    m2.lock();
    std::cout << "T2 locked m2\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    m1.lock();   // waits for T1
    std::cout << "T2 locked m1\n";

    m1.unlock();
    m2.unlock();
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();
}

```

### Why we should use Mutex not global variable

> A global variable only stores a value. A mutex provides synchronized ownership of a critical section. 
> A normal global bool cannot safely perform the atomic "check-and-lock" operation, so multiple threads can enter at the same time.

### How kernel handle mutext

1. Mutex state
      ↓
   FREE / LOCKED

2. Owner / waiting information
      ↓
   Who has it?
   Who is waiting?

3. Scheduler
      ↓
   Put waiting thread to sleep
   Wake it when mutex becomes available

### Shemaphore

> shemaphore is use to notify task-task or isr-task, something is happened and resource is available , This is signaling mechanism , one task is waiting till another gives signl
```c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

/* Thread 1 */
void *producer(void *arg)
{
    printf("Producer: doing some work...\n");

    sleep(2);

    printf("Producer: work completed!\n");

    /* Tell Thread 2 that work is completed */
    sem_post(&sem);

    return NULL;
}


/* Thread 2 */
void *consumer(void *arg)
{
    printf("Consumer: waiting...\n");

    /* Wait until producer signals */
    sem_wait(&sem);

    printf("Consumer: received signal!\n");

    return NULL;
}


int main(void)
{
    pthread_t t1, t2;

    /*
     * Initialize semaphore.
     *
     * 0 = initially no signal available.
     */
    sem_init(&sem, 0, 0);

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;
}
```

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;

/* Mutex protects the shared counter */
std::mutex mtx;

void increment()
{
    for (int i = 0; i < 100000; i++)
    {
        /*
         * Lock the mutex.
         * Only one thread can enter this section
         * at a time.
         */
        mtx.lock();

        counter++;

        /*
         * Release the mutex.
         */
        mtx.unlock();
    }
}

int main()
{
    std::thread t1(increment);
    std::thread t2(increment);

    /* Wait for both threads to finish */
    t1.join();
    t2.join();

    std::cout << "Counter = " << counter << std::endl;

    return 0;
}
```
> I use a semaphore to synchronize or signal an event between an ISR and a task, or between tasks.


## Spinlocks vs Mutexes in Kernel

### Spinlock:

- Busy-waits (spins) in a loop until the lock becomes available.

Does not sleep.

- Used in atomic context (e.g., interrupt handlers, where sleeping is not allowed).

### Mutex:

- If the lock is not available, it sleeps until it becomes available.

- Used in process context where sleeping is allowed.

### 🛠️ Example

```c
// Spinlock usage
spinlock_t lock;
spin_lock(&lock);
// critical section
spin_unlock(&lock);

// Mutex usage
struct mutex my_mutex;
mutex_lock(&my_mutex);
// critical section
mutex_unlock(&my_mutex);
```

## What is an Interrupt Context and Can It Sleep?

- Interrupt context: Code executed as a result of an interrupt (e.g., ISR).

    - It cannot sleep because it's running in a time-critical environment.

    - Functions like kmalloc(GFP_KERNEL) or mutex_lock() will crash if used here.

- ✅ Use GFP_ATOMIC allocations.
- ✅ Use spinlocks, not mutexes.

## Bottom Halves, Tasklets, and Workqueues

### What happens when an interrupt occurs?

When a device (like a keyboard or network card) needs attention, it sends an interrupt to the CPU. The CPU stops what it's doing to handle it.

-----------

### Handling an interrupt has two parts:

#### ✅ Top Half (Fast Handler)

- Runs immediately when interrupt happens.

- Does the urgent, quick work (like acknowledging the device).

- Defers long tasks to "bottom half" to keep things fast.

#### 🔻 Bottom Half (Deferred Work)

This part runs later, after the urgent work is done.

There are two main types of bottom halves:
- 1. Tasklets
- 2. Workqueues


#### 1. 🧩 Tasklets (can not sleep and not intruptted by others)

- Very lightweight.

- Run in a special context called `softirq`.

- **Cannot sleep** (can’t use things that wait, like `msleep()` or `mutex_lock()`).

- Run quickly and are non-preemptible (they can’t be interrupted by other tasklets).

- Use tasklets for short, fast work that doesn’t need to wait for anything.

#### 2. 🧵 Workqueues (can sleep)

- Run in process context (like a regular program).

- **Can sleep** — so they can use `msleep()`, `mutex_lock()`, etc.

- A little heavier, but more flexible.

- Use workqueues when you need to do something that might block or take longer.

#### Summary

| Part      | Runs When?         | Can Sleep? | Use For                        |
| --------- | ------------------ | ---------- | ------------------------------ |
| Top Half  | Immediately on IRQ | ❌ No       | Urgent, quick actions          |
| Tasklet   | After top half     | ❌ No       | Quick, non-blocking work       |
| Workqueue | After top half     | ✅ Yes      | Longer, possibly blocking work |

### Example

```c
#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>     // For tasklets and interrupt handling
#include <linux/workqueue.h>     // For workqueues
#include <linux/timer.h>         // For timer to simulate interrupts
#include <linux/delay.h>         // For msleep()
#include <linux/jiffies.h>       // For jiffies

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ChatGPT");
MODULE_DESCRIPTION("Example of Top Half, Tasklet, and Workqueue");
MODULE_VERSION("1.0");

// ------------------------------
// Simulated "Interrupt" via Timer
// ------------------------------
static struct timer_list my_timer;

// ------------------------------
// Tasklet
// ------------------------------
void my_tasklet_func(unsigned long data);
DECLARE_TASKLET(my_tasklet, my_tasklet_func, 0);

// ------------------------------
// Workqueue
// ------------------------------
static void my_work_func(struct work_struct *work);
static DECLARE_WORK(my_work, my_work_func);

// ------------------------------
// Simulated Top Half (ISR simulation)
// ------------------------------
void simulated_top_half(struct timer_list *t)
{
    printk(KERN_INFO "Top half: Simulated interrupt triggered\n");

    // Schedule tasklet (bottom half - lightweight)
    tasklet_schedule(&my_tasklet);

    // Schedule workqueue (bottom half - heavy)
    schedule_work(&my_work);

    // Restart the timer for continuous simulation
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));
}

// ------------------------------
// Tasklet Function
// ------------------------------
void my_tasklet_func(unsigned long data)
{
    printk(KERN_INFO "Tasklet: Running deferred quick work (non-blocking)\n");
}

// ------------------------------
// Workqueue Function
// ------------------------------
static void my_work_func(struct work_struct *work)
{
    printk(KERN_INFO "Workqueue: Running deferred heavy work (can sleep)\n");

    // Simulate longer processing
    msleep(500);

    printk(KERN_INFO "Workqueue: Finished sleeping\n");
}

// ------------------------------
// Module Init
// ------------------------------
static int __init my_module_init(void)
{
    printk(KERN_INFO "Module loaded: Bottom Half Example\n");

    // Setup and start the timer (simulated interrupt every 2 sec)
    timer_setup(&my_timer, simulated_top_half, 0);
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));

    return 0;
}

// ------------------------------
// Module Exit
// ------------------------------
static void __exit my_module_exit(void)
{
    // Cleanup
    del_timer_sync(&my_timer);
    tasklet_kill(&my_tasklet);
    cancel_work_sync(&my_work);

    printk(KERN_INFO "Module unloaded: Cleaned up\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
```

```makefile
obj-m += bottom_half_example.o

all:
  make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
  make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

```bash
make

sudo insmod bottom_half_example.ko
dmesg -w (you will se logs )
sudo rmmod bottom_half_example

```

## Purpose of `atomic_t` and `atomic64_t`

- They are used for lockless synchronization of shared variables between threads or CPUs.
  
### Why? 

- To prevent race conditions without using locks.

🛠️ Example:

```c
atomic_t counter = ATOMIC_INIT(0);
atomic_inc(&counter);    // Increment atomically
int val = atomic_read(&counter);
```

## 35. Can You Use Mutexes in Interrupt Handlers?

❌ NO. You cannot use mutexes in interrupt context.

- Mutexes may sleep if the lock is held.

- Sleeping in interrupt context causes a kernel panic.

✅ Use spinlocks or atomic operations instead.

## RCU (Read-Copy-Update) and Seqlocks – What and When?

| **Aspect**      | **RCU**                                     | **Seqlock**                            |
| --------------- | ------------------------------------------- | -------------------------------------- |
| **Use Case**    | Many readers, few writers                   | Few writers, retryable readers         |
| **Readers**     | Non-blocking, always consistent             | Non-blocking, **may retry**            |
| **Writers**     | Copy → update → swap pointer                | Lock → update data                     |
| **Read API**    | `rcu_read_lock()`, `rcu_dereference()`      | `read_seqbegin()`, `read_seqretry()`   |
| **Write API**   | `rcu_assign_pointer()`, `synchronize_rcu()` | `write_seqlock()`, `write_sequnlock()` |
| **Can Sleep?**  | Readers: ✅ Yes<br>Writers: ❌ No             | ❌ No (neither readers nor writers)     |
| **Data Type**   | Pointer-based                               | Small structs                          |
| **Consistency** | Always (old or new, never partial)          | Retry ensures consistency              |

## 7. How Do You Avoid Deadlocks in Kernel Code?

**Deadlock:** Two or more threads wait on each other forever.

### ✅ Avoid deadlocks by:

- Always acquire multiple locks in a fixed order.

- Don't sleep while holding a spinlock.

- Timeouts or detection for circular wait.

- Use `lockdep` (kernel debug feature) to detect locking issues.

### Lockdep for Kernel and C++

| Step | Type | Action |
|---|---|---|
| 1 | Kernel | Check: `grep CONFIG_LOCKDEP /boot/config-$(uname -r)` |
| 2 | Kernel | Enable `CONFIG_LOCKDEP=y` |
| 3 | Kernel | Enable `CONFIG_PROVE_LOCKING=y` |
| 4 | Kernel | Enable `CONFIG_DEBUG_LOCK_ALLOC=y` |
| 5 | Kernel | Rebuild and boot the new kernel |
| 6 | Kernel | Monitor: `sudo dmesg -w` |
| 7 | Kernel C++ | Use kernel locks such as `mutex`, `spinlock`, and `rwlock` |
| 8 | Kernel C++ | Lockdep automatically tracks supported kernel locks |
| 9 | User-space C++ | `std::mutex` is **not** tracked by kernel lockdep |
| 10 | User-space C++ | Use **ThreadSanitizer** instead |
| 11 | User-space C++ | Build: `g++ -g -O1 -fsanitize=thread -fno-omit-frame-pointer main.cpp -o app` |
| 12 | User-space C++ | Run: `./app` |
| 13 | Both | Fix inconsistent lock ordering reported by the tool |


## What is Preemption? How to Disable/Enable It?

**Preemption:** The scheduler can interrupt a task to run another (e.g., higher-priority one).

To prevent preemption in critical sections:
```c
preempt_disable();
// critical section
preempt_enable();
```

## How Do You Implement a Lock-Free Queue in the Kernel?

- Use atomic operations and memory barriers.
  
- The kernel provides lock-free queues:
    - kfifo (simple circular buffer)
    - llist (lockless list)
    - RCU-based queues  
  
```c
    DEFINE_KFIFO(my_fifo, int, 128);
    kfifo_in(&my_fifo, &data, 1);
    kfifo_out(&my_fifo, &data, 1);
```

## Priority Inversion – Simple Explanation

### 🔧 Problem (What is it?)

Imagine this:

- Low-priority task locks a resource (e.g., a mutex).

- High-priority task wants the same resource → has to wait.

- Meanwhile, medium-priority tasks keep running (they don’t need the lock).

- So, the low-priority task never gets CPU time to release the lock.

- Result: High-priority task is stuck — this is called priority inversion.
---------
### Why is it bad?

- High-priority tasks (like real-time tasks) are supposed to run immediately.

- Priority inversion breaks real-time guarantees.

### 🛠️ Solution – Priority Inheritance

- The kernel boosts the priority of the low-priority task (which holds the lock) to match the high-priority one.

- That task runs sooner, releases the lock, and lets the high-priority task continue.

✅ In Linux, this is supported via rt_mutex (real-time mutex).

### In One Line:

- `Priority Inversion` = High-priority task waits because a low-priority task holds a lock.

- `Priority Inheritance` = Kernel temporarily raises the low-priority task’s priority so it can finish quickly.

## How do you map hardware registers to virtual memory in kernel?

### 1. What are hardware registers?

- Hardware devices (like network cards, GPUs, or disk controllers) have registers — special memory locations used to control the device or read its status.

- These registers live at specific physical memory addresses.

### 2. Why map them to virtual memory?

- The CPU in modern systems doesn't access physical memory directly.

- It uses virtual memory, and the kernel is responsible for translating virtual addresses to physical addresses.

- So, to let the CPU talk to the hardware, the kernel maps those special physical addresses (registers) into its virtual address space.

### 3. How does the kernel map them?

The kernel uses a function like:

```c
#include <linux/io.h>  // for ioremap() and iounmap()

// ioremap - Input/Output re-mappaing
void __iomem *ioremap(phys_addr_t phys_addr, size_t size);
```

- phys_addr → The physical address of the hardware register.

- size → How much space to map (usually a few KB).

- It returns a virtual address pointer that the kernel can use to access the hardware.

### 4. Now the kernel can use the mapped address

Once mapped, the kernel can read/write to the registers using special functions:

```c
readl(virtual_addr);     // Read 32-bit value
writel(value, virtual_addr); // Write 32-bit value
```

### 5. Cleanup when done

When the device is removed or driver is unloaded, the kernel unmaps the registers:

```c
iounmap(virtual_addr);
```


## What is a device file? How is it connected to a driver?

- A **device file** (also called a special file) is a file in `/dev` that represents a **hardware device** or **virtual device**.
- It acts as a bridge between user space and kernel space.
- User programs don’t talk directly to hardware; they read/write the device file, and the kernel passes these operations to the appropriate driver.

| Type                 | Description                                    | Example                            |
| -------------------- | ---------------------------------------------- | ---------------------------------- |
| **Character device** | Accessed **byte by byte**                      | `/dev/ttyS0` (serial port)         |
| **Block device**     | Accessed **in blocks**                         | `/dev/sda` (disk), `/dev/ramdisk0` |
| **Network device**   | Special virtual files, mostly `/sys/class/net` | `/dev/net/tun`                     |

### How is it Connected to a Driver?

A **device file is linked to a driver through its major and minor numbers:**

**Major number** → identifies the driver type

**Minor number** → identifies the specific device managed by that driver

### Steps in Linux

- **Driver registers itself** with `register_chrdev()` (for character devices) or `register_blkdev()` (for block devices)

The kernel assigns a **major number** to the driver.

Device file is created using `mknod` or `udev`, e.g.:

```bash
sudo mknod /dev/ramdisk0 b 240 0
```
- b → block device

- 240 → major number (driver ID)

- 0 → minor number (specific device)

- File operations in driver (`read`, `write`, `ioctl`) are called whenever the user program interacts with the device file.



-----------------------------------------------------------------
# Embedded System
## Define array of function pointer and use it in interrupt handling

- This declares a function-pointer type in C:
```c
typedef void (*ISR_Handler)(void);  // Function pointer

void (*handler[n]) (void); // This is array of function pointer
```
So ISR_Handler means:

- **“pointer to a function that takes no arguments and returns void.”**

```c
void timer_ISR(void)
{
    // Handle timer interrupt
}

ISR_Handler handler = timer_ISR;

handler();  // Calls timer_ISR
```
### Use case of array of function pointer in ISR

```c
#include <stdint.h>
#include <stdio.h>

/* Function-pointer type for an ISR */
typedef void (*ISR_Handler)(void);


void timer_isr(void)
{
    printf("Timer interrupt occurred\n");

    /* Clear timer interrupt flag */
    // TIMER->STATUS = 0;
}

void uart_isr(void)
{
    printf("UART interrupt occurred\n");

    /* Read UART data */
    // uint8_t data = UART->DATA;

    /* Clear UART interrupt flag */
    // UART->STATUS = 0;
}

void gpio_isr(void)
{
    printf("GPIO interrupt occurred\n");

    /* Clear GPIO interrupt flag */
    // GPIO->INT_STATUS = 0;
}


/* ---------------------------------------------------
 * Interrupt handler table
 * --------------------------------------------------- */

#define NUM_INTERRUPTS 3

ISR_Handler interrupt_table[NUM_INTERRUPTS] =
{
    timer_isr,     // IRQ 0
    uart_isr,      // IRQ 1
    gpio_isr       // IRQ 2
};


/* ---------------------------------------------------
 * Common interrupt dispatcher
 * --------------------------------------------------- */

void CPU_IRQHandler(void)
{
    uint32_t irq;

    /* Read interrupt number from interrupt controller */
    irq = INTERRUPT_CONTROLLER->IRQ_NUMBER;

    /* Dispatch to appropriate ISR */
    if (irq < NUM_INTERRUPTS)
    {
        interrupt_table[irq]();
    }
}
```
## How to access GPIO pin and update ? 

```c
#include <stdint.h>

/*
 * ---------------------------------------------------------
 * GPIO REGISTER DEFINITIONS
 * ---------------------------------------------------------
 *
 * Assume GPIO peripheral starts at address 0x40020000.
 *
 * These addresses are only examples.
 * A real MCU will have its own GPIO register addresses.
 */

#define GPIO_BASE       0x40020000UL

#define GPIO_DIR        (*(volatile uint32_t *)(GPIO_BASE + 0x00))
#define GPIO_OUT        (*(volatile uint32_t *)(GPIO_BASE + 0x04))
#define GPIO_IN         (*(volatile uint32_t *)(GPIO_BASE + 0x08))


/*
 * We want to control GPIO pin 5.
 *
 * 1U << 5 produces:
 *
 *     0000 0000 0010 0000
 *                  ^
 *                  |
 *                bit 5
 */
#define GPIO5           (1U << 5)


/*
 * ---------------------------------------------------------
 * Small delay function
 * ---------------------------------------------------------
 *
 * This is only for demonstration.
 * In a real application, use a hardware timer or
 * RTOS delay instead of a software loop.
 */
static void delay(void)
{
    volatile uint32_t count;

    for (count = 0; count < 100000; count++)
    {
        /* Do nothing */
    }
}


/*
 * ---------------------------------------------------------
 * GPIO INITIALIZATION
 * ---------------------------------------------------------
 */
static void gpio_init(void)
{
    GPIO_DIR |= GPIO5;
}


/*
 * ---------------------------------------------------------
 * SET GPIO HIGH
 * ---------------------------------------------------------
 */
static void gpio_set(void)
{
  
    GPIO_OUT |= GPIO5;
}


/*
 * ---------------------------------------------------------
 * SET GPIO LOW
 * ---------------------------------------------------------
 */
static void gpio_clear(void)
{
    GPIO_OUT &= ~GPIO5;
}


/*
 * ---------------------------------------------------------
 * TOGGLE GPIO
 * ---------------------------------------------------------
 */
static void gpio_toggle(void)
{
    GPIO_OUT ^= GPIO5;
}


/*
 * ---------------------------------------------------------
 * READ GPIO INPUT
 * ---------------------------------------------------------
 */
static uint8_t gpio_read(void)
{
 
    /*
     * Clear bit 5.
     *
     * This configures GPIO5 as INPUT.
     */
    GPIO_DIR &= ~GPIO5;
    /*
     * Read GPIO5 input.
     *
     * If bit 5 is 1 -> pin is HIGH
     * If bit 5 is 0 -> pin is LOW
     */
    if (GPIO_IN & GPIO5)
    {
        return 1;
    }

    return 0;
}


/*
 * ---------------------------------------------------------
 * MAIN FUNCTION
 * ---------------------------------------------------------
 */
int main(void)
{
    /*
     * Configure GPIO5 as output.
     */
    gpio_init();

    while (1)
    {
        /*
         * Turn LED ON.
         */
        gpio_set();

        delay();

        /*
         * Turn LED OFF.
         */
        gpio_clear();

        delay();

        /*
         * Alternatively, we could simply use:
         *
         * gpio_toggle();
         *
         * instead of gpio_set() and gpio_clear().
         */
    }

    return 0;
}
```

## What is different between pull up and pull down register

Pull-up resistor

- Default state = **HIGH**

- Pressing the button connects to GND

- Signal reads **LOW when pressed**

Pull-down resistor

- Default state = **LOW**

- Pressing the button connects to **VCC**

- Signal reads **HIGH when pressed**


**Pull-up → Active LOW**

**Pull-down → Active HIGH**

## What happened in case of strong pull up and weak pull up?

The difference between a strong pull-up and a weak pull-up is mainly the **resistance value** and **how much current it can source**


| Situation            | Weak Pull-Up | Strong Pull-Up | Good For                                                          |
| -------------------- | ------------ | -------------- | ----------------------------------------------------------------- |
| Rise Time            | Slow         | Fast           | Strong pull-up → Fast digital signals (e.g., communication buses) |
| Power                | Low          | Higher         | Weak pull-up → Low-power designs, battery devices                 |
| Noise Resistance     | Lower        | Higher         | Strong pull-up → Noisy environments, long wires                   |
| Stress on LOW driver | Minimal      | Higher         | Weak pull-up → Microcontroller inputs, small transistors          |

## When GPIO triggered from hardware or software and interupt triggered what exactly happened?

### Hardware-Triggered GPIO Interrupt

**What happens internally:**

1. External signal changes GPIO state (LOW → HIGH or HIGH → LOW).

2. The GPIO edge/level detection logic detects the configured condition (rising edge, falling edge, or both).

3. An interrupt flag is set.

4. The interrupt controller checks:

    - Is this interrupt enabled?

    - Is its priority high enough?

5. CPU finishes the current instruction.

6. CPU jumps to the Interrupt Service Routine (ISR).

7. ISR executes.

8. Interrupt flag is cleared.

9. CPU returns to the main program.

### Software-Triggered GPIO Interrupt

**This happens when:**

- Software manually sets the interrupt flag

- Software writes to a GPIO register that causes a change

- Some MCUs allow forcing an interrupt via a register bit

**What happens:**

- Software sets interrupt pending bit.

- Interrupt controller treats it exactly like hardware trigger.

- CPU jumps to ISR.

- ISR runs.

- Return to main program.

### What Changes in the CPU During Interrupt?

**When interrupt occurs:**

- Current Program Counter (PC) is saved

- CPU status register is saved

- Global interrupts may be temporarily disabled

- ISR address is loaded

- ISR runs

- RETI (return from interrupt) restores context

```text
GPIO change → Flag set → CPU jumps to ISR → ISR runs → Return
```


## How can we solved post-processing delay issue in interrupt?

### Bare metal progamming
- I keep the ISR as short as possible. 
- The ISR captures the minimum required data, acknowledges or clears the interrupt source, and then communicates the event to the main loop using a flag, counter, or buffer. 
- For continuous data such as UART, I use a ring buffer. 
- For high-speed data such as ADC or SPI, I prefer DMA with a buffer or double-buffering. 
- The time-consuming processing such as filtering, calculations, logging, and storage is performed outside the ISR. This reduces ISR execution time and interrupt latency and prevents other interrupts from being unnecessarily delayed.


####  Ring buffer

```c 
#define BUFFER_SIZE 256

volatile uint8_t rx_buffer[BUFFER_SIZE];

volatile uint16_t head = 0;
volatile uint16_t tail = 0;

void UART_IRQHandler(void)
{
    uint8_t data;

    data = UART_READ_BYTE();

    rx_buffer[head] = data;

    head++;

    if (head >= BUFFER_SIZE)
        head = 0;

    UART_CLEAR_INTERRUPT();
}

while (1)
{
    if (head != tail)
    {
        uint8_t data;

        data = rx_buffer[tail];

        tail++;

        if (tail >= BUFFER_SIZE)
            tail = 0;

        process_data(data);
    }
}
```
### OS based or freeRTOS 

| Method | How It Works | Latency / Benefit | Best Use Case | Important Considerations | Recommendation |
|---|---|---|---|---|---|
| **Keep ISR Short** | ISR clears the interrupt, captures minimum required data, and signals a task | Very low latency | All interrupt-driven applications | Avoid loops, heavy calculations, logging, and blocking operations inside ISR | **Essential** |
| **Task Notification** | ISR uses `vTaskNotifyGiveFromISR()` or `xTaskNotifyFromISR()` to wake a specific task | Very low overhead and latency | One ISR needs to notify one task | Faster and lighter than semaphore/queue for simple events | **Highly Recommended** |
| **`portYIELD_FROM_ISR()`** | Requests an immediate context switch when the ISR wakes a higher-priority task | Very low scheduling latency | Time-critical interrupt processing | Use with `xHigherPriorityTaskWoken` returned by the FromISR API | **Highly Recommended** |
| **Increase Task Priority** | Gives the interrupt-processing task a higher FreeRTOS priority | Reduces task scheduling delay | Processing task is delayed by other tasks | Do not blindly assign the highest priority; consider system scheduling | **Recommended** |
| **Binary Semaphore** | ISR gives a semaphore and the waiting task takes it | Low latency | Simple ISR-to-task synchronization | More overhead than task notification | **Recommended** |
| **Queue** | ISR sends event/data to a FreeRTOS queue and the task receives it | Low to medium latency | ISR needs to transfer data to a task | Queue length and item size affect memory and performance | **Recommended for Data Transfer** |
| **Event Group** | ISR sets event bits and a task waits for one or more events | Medium latency | Multiple interrupt/event sources | Useful for multiple event conditions but not the lowest-latency option | **Use When Required** |
| **Reduce Critical Sections** | Minimizes time spent with interrupts or scheduling disabled | Can significantly reduce interrupt latency | System contains long critical sections | Avoid lengthy `taskENTER_CRITICAL()` / `taskEXIT_CRITICAL()` sections | **Essential** |
| **Avoid `printf()` in ISR** | Removes slow UART/logging operations from interrupt context | Significantly reduces ISR execution time | Debug-heavy firmware | Store diagnostic information and print it from a task instead | **Strongly Recommended** |
| **Avoid Blocking Operations in ISR** | Prevents delays caused by blocking APIs | Very low latency | All ISR implementations | Do not use normal blocking FreeRTOS APIs from an ISR | **Essential** |
| **DMA + ISR** | DMA handles data movement while ISR handles completion notification | Very low CPU overhead | High-speed ADC/UART/SPI/I2C interfaces | ISR only handles DMA completion and signals processing task | **Highly Recommended for High-Speed Data** |
| **Double Buffering** | One buffer is filled while another buffer is processed | Prevents processing from blocking data acquisition | Continuous/high-rate data | Requires proper buffer ownership and synchronization | **Recommended for Streaming Data** |
| **Ring Buffer** | ISR/DMA writes data into a circular buffer while a task consumes it | Good throughput and low latency | Continuous UART/network/sensor data | Handle overflow and producer/consumer synchronization correctly | **Recommended for Streaming Data** |
| **Interrupt Priority Optimization** | Assigns appropriate hardware interrupt priorities | Reduces delay from competing interrupts | Systems with multiple interrupts | On Cortex-M, ensure priorities follow FreeRTOS interrupt-priority rules | **Recommended** |
| **Measure ISR Latency** | Measures time from interrupt occurrence to ISR execution | Helps identify actual bottleneck | Debugging latency problems | Use GPIO, hardware timer, or DWT cycle counter instead of `printf()` | **Highly Recommended** |
| **Measure Task Response Latency** | Measures time from ISR notification to task execution | Identifies RTOS scheduling delay | Debugging post-ISR processing delay | Helps separate ISR delay from task scheduling delay | **Highly Recommended** |


####  FreeRTOS example using vTaskNotifyGiveFromISR()
```c
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*
 * Select one method:
 *
 * 1 = Task Notification
 * 0 = Binary Semaphore
 */
#define USE_TASK_NOTIFICATION    1


/*----------------------------------------------------------
 * Global objects
 *----------------------------------------------------------*/

#if USE_TASK_NOTIFICATION

TaskHandle_t processingTaskHandle = NULL;

#else

SemaphoreHandle_t binarySemaphore = NULL;

#endif


/*----------------------------------------------------------
 * Processing Task
 *----------------------------------------------------------*/

void ProcessingTask(void *pvParameters)
{
    while (1)
    {

#if USE_TASK_NOTIFICATION

        /* Wait for ISR notification */
        ulTaskNotifyTake(
            pdTRUE,
            portMAX_DELAY
        );

#else

        /* Wait for binary semaphore */
        xSemaphoreTake(
            binarySemaphore,
            portMAX_DELAY
        );

#endif

        /* Common post-processing */
        ProcessData();
    }
}


/*----------------------------------------------------------
 * Interrupt Handler
 *----------------------------------------------------------*/

void My_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* Clear hardware interrupt */
    ClearInterrupt();


#if USE_TASK_NOTIFICATION

    /* Notify processing task */
    vTaskNotifyGiveFromISR(
        processingTaskHandle,
        &xHigherPriorityTaskWoken
    );

#else

    /* Give binary semaphore */
    xSemaphoreGiveFromISR(
        binarySemaphore,
        &xHigherPriorityTaskWoken
    );

#endif


    /* Request immediate context switch */
    portYIELD_FROM_ISR(
        xHigherPriorityTaskWoken
    );
}


/*----------------------------------------------------------
 * Main
 *----------------------------------------------------------*/

int main(void)
{
    /* Hardware initialization */
    Hardware_Init();


#if USE_TASK_NOTIFICATION

    /*
     * Task Notification:
     * No separate notification object is required.
     */
    xTaskCreate(
        ProcessingTask,
        "Process",
        256,
        NULL,
        5,
        &processingTaskHandle
    );


#else

    /*
     * Create Binary Semaphore.
     */
    binarySemaphore = xSemaphoreCreateBinary();

    xTaskCreate(
        ProcessingTask,
        "Process",
        256,
        NULL,
        5,
        NULL
    );

#endif


    /* Start FreeRTOS scheduler */
    vTaskStartScheduler();


    /* Should never reach here */
    while (1)
    {
    }
}
```

#### in freeRTOS xQueueSendFromISR
```c
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Queue handle */
QueueHandle_t myQueue;

/* Data sent from ISR to task */
uint32_t data;


/*--------------------------------------------------
 * Processing Task
 *--------------------------------------------------*/
void ProcessingTask(void *arg)
{
    uint32_t receivedData;

    while (1)
    {
        /* Wait for data from ISR */
        if (xQueueReceive(myQueue,
                          &receivedData,
                          portMAX_DELAY) == pdPASS)
        {
            /*
             * ISR is finished.
             *
             * Do post-processing here.
             */
            PostProcess(receivedData);
        }
    }
}


/*--------------------------------------------------
 * ISR
 *--------------------------------------------------*/
void MyISR(void)
{
    BaseType_t higherPriorityTaskWoken = pdFALSE;

    /* Get data quickly */
    data = READ_DATA();

    /* Clear hardware interrupt */
    CLEAR_INTERRUPT();

    /*
     * Send data to queue from ISR.
     */
    xQueueSendFromISR(
        myQueue,
        &data,
        &higherPriorityTaskWoken
    );

    /*
     * If ProcessingTask has higher priority,
     * run it immediately after ISR.
     */
    portYIELD_FROM_ISR(
        higherPriorityTaskWoken
    );
}


/*--------------------------------------------------
 * Initialization
 *--------------------------------------------------*/
void AppInit(void)
{
    /*
     * Create queue:
     *
     * 10 = maximum 10 messages
     * sizeof(uint32_t) = size of each message
     */
    myQueue = xQueueCreate(
        10,
        sizeof(uint32_t)
    );

    if (myQueue == NULL)
    {
        /* Queue creation failed */
        Error_Handler();
    }

    /*
     * Create processing task.
     */
    xTaskCreate(
        ProcessingTask,
        "Processing",
        512,
        NULL,
        5,              /* Task priority */
        NULL
    );
}

```
----------------------------------------------------------------------------------
# Linux
## 1. Explain linux directory structure
| Directory | Purpose                 | Example / Usage                | Why Important                                           |
| --------- | ----------------------- | ------------------------------ | ------------------------------------------------------- |
| `/`       | Root directory          | All directories start here     | Fundamental starting point of filesystem                |
| `/bin`    | Essential user commands | `ls`, `cp`, `mv`, `cat`        | Needed for system boot & minimal operations             |
| `/sbin`   | System admin commands   | `mount`, `reboot`, `fsck`      | Shows separation of **admin vs user privileges**        |
| `/boot`   | Boot files              | `vmlinuz`, `grub/`             | Crucial for system startup and kernel loading           |
| `/dev`    | Device files            | `/dev/sda`, `/dev/null`        | Teaches **device abstraction** in Linux                 |
| `/etc`    | Configuration files     | `passwd`, `fstab`, `hostname`  | Central for system configuration & administration       |
| `/home`   | User directories        | `/home/alice`                  | Demonstrates **user space vs system space**             |
| `/root`   | Root user home          | `/root/.bashrc`                | Highlights **superuser privileges**                     |
| `/lib`    | Essential libraries     | `libc.so.6`                    | Shows **dynamic linking and dependency of binaries**    |
| `/usr`    | User applications       | `/usr/bin`, `/usr/lib`         | Separates system-essential tools from optional programs |
| `/var`    | Variable data           | `/var/log`, `/var/cache`       | Explains **logs, runtime data, and system monitoring**  |
| `/tmp`    | Temporary files         | `/tmp/file.txt`                | Demonstrates **volatile storage and caching**           |
| `/proc`   | Virtual filesystem      | `/proc/cpuinfo`, `/proc/[pid]` | Teaches **process and kernel info**                     |
| `/sys`    | Kernel device info      | `/sys/class/net/eth0`          | Shows **kernel & hardware interaction**                 |
| `/mnt`    | Temporary mounts        | `/mnt/usb`                     | Helps understand **filesystem mounting**                |
| `/media`  | Removable media         | `/media/cdrom`, `/media/usb`   | Demonstrates **auto-mounted devices**                   |
| `/opt`    | Optional software       | `/opt/google`                  | Separates vendor or third-party software                |




Linux Directory Structure – Simplified Table

## Linux Boot Process Diagram
```text
+----------------------------+
| 0. Power On                |
|----------------------------|
| - Power button pressed     |
| - PSU supplies power       |
| - CPU reset signal         |
| - CPU jumps to reset vector|
|   (e.g. 0xFFFFFFF0)        |
+------------+---------------+
             |
             v
+----------------------------+
| 1. BIOS / UEFI             |
|----------------------------|
| - Stored in flash          |
| (motherboard)              |
| - Initializes hardware     |
| - Runs POST                |
| - Checks Secure Boot       |
| - Loads bootloader         |
+------------+---------------+
             |
             v
+----------------------------+
| 2. Bootloader (GRUB)       |
|----------------------------|
| - Located in EFI partition |
| - Shows boot menu          |
| - Loads kernel             |
| - Loads initramfs          |
+------------+---------------+
             |
             v
+----------------------------+
| 3. Kernel                  |
|----------------------------|
| - Decompresses itself      |
| - Mounts initramfs         |
| - Loads drivers            |
| - Finds real root fs       |
| - Starts init (PID 1)      |
+------------+---------------+
             |
             v
+----------------------------+
| 4. init / systemd          |
|----------------------------|
| - Starts services          |
| - Mounts file systems      |
| - Prepares system          |
+------------+---------------+
             |
             v
+----------------------------+
| 5. Login / GUI             |
|----------------------------|
| - TTY login or GUI         |
| - User logs in             |
| - System is ready          |
+----------------------------+
```
## Explain Linux boot process

### 0. CPU wakes up

- CPU wakes up when power button is pressed.
- Reset vector is a fixed address inside the CPU register.
- CPU goes to that address automatically.
- That address points to firmware flash memory on the motherboard.
- The first instruction there is a small jump to the main firmware code.
- CPU follows the jump and starts UEFI.
- UEFI then initializes hardware and loads the operating system.

### 1. BIOS / UEFI Initialization

BIOS (Basic Input/Output System) or UEFI (Unified Extensible Firmware Interface) is the firmware built into the ROM and ROM is in the Motherboard.

BIOS present in ROM, Manufacturer burns one program into the ROM is called BIOS.

It:
- Initializes hardware components (CPU, RAM, disk, keyboard, etc.).
- Performs the POST (Power-On Self-Test).
- Looks for a bootable device (HDD, SSD, USB, CD/DVD).
- Loads the bootloader from the bootable device's Master Boot Record (MBR) or EFI partition.
- The MBR and EFI System Partition are stored on your storage drive (SSD or HDD)
- MBR First 512 bytes of harddisk
- EFI System Partition A disk partition
  
| Feature         | **BIOS (Basic Input/Output System)** | **UEFI (Unified Extensible Firmware Interface)** |
| --------------- | ------------------------------------ | ------------------------------------------------ |
| Year Introduced | 1975–1980s                           | Mid-2000s                                        |
| Bit Support     | 16-bit                               | 32-bit or 64-bit                                 |
| Interface       | Text-based                           | Graphical interface with mouse support           |
| Storage Support | MBR (Max 2 TB drives)                | GPT (Supports drives >2 TB)                      |
| Boot Time       | Slower                               | Faster                                           |
| Compatibility   | Legacy systems                       | Modern systems                                   |


### 2. Bootloader (GRUB, LILO, systemd-boot, etc.)
The bootloader’s job is to load the Linux kernel into memory.

**Hard disk contains the bootloader files**

| System Type  | Windows Bootloader Location                               | Linux Bootloader Location                                                                       |
| ------------ | --------------------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| **UEFI**     | EFI System Partition → `/EFI/Microsoft/Boot/bootmgfw.efi` | EFI System Partition → `/EFI/BOOT/grubx64.efi` (or distro-specific `/EFI/<distro>/grubx64.efi`) |
| **BIOS/MBR** | Root of active partition → `C:\bootmgr`                   | MBR of disk → GRUB Stage 1 → `/boot/grub` (Stage 2, configs, modules)                           |

``` text
SSD/HDD
│
├── EFI System Partition (FAT32)
│    ├── EFI/
│    │    ├── Microsoft/
│    │    │    └── bootmgfw.efi
│    │    └── ubuntu/
│    │         └── grubx64.efi
│
├── /boot
│    ├── vmlinuz-6.x.x          (Linux Kernel)
│    ├── initrd.img-6.x.x       (Initramfs)
│    ├── System.map
│    └── grub/
│         └── grub.cfg
│
└── Root Filesystem (/)
```
Common Linux bootloaders:
- GRUB (GRUB2) – the most widely used.

Tasks performed:
- Displays the boot menu (if multiple OSes or kernels are available).
- Loads the selected kernel and initramfs `initial RAM filesystem`/initrd (initial RAM disk).
- A typical initramfs contains:
    - Basic Linux binaries: /bin/sh, busybox, etc.
    - Kernel modules: /lib/modules/...
    - Initialization scripts: usually /init
    - Device nodes: /dev/
    - Configuration files
- Passes control to the kernel.


### 3. Linux Kernel Initialization
The kernel:

- Decompresses itself and mounts the initial temporary root filesystem from initramfs/initrd.
- Initializes all hardware via drivers (discovered or specified).
- Mounts the real root filesystem (from disk).
- Its load all services
- Starts the init process (PID 1).

### 4. init System Starts (PID 1)
- This is the first user-space program.
- Depending on the distro, this could be:
    * systemd (most modern distros)
    * SysVinit
    * Upstart (deprecated)
- init is responsible for:
    * Starting all other services (via units, runlevels, or targets).
    * Setting up networking, user logins, daemons, etc.

### 5. Login Prompt / GUI
Finally, the system:
- Presents a login prompt (TTY or graphical).
- For GUI systems, a display manager like GDM, LightDM, or SDDM is started.
- Users can log in and begin using the system.
---


## 2. What is ABI
- ABI stands for **Application Binary Interface**.
  
- ABI (**Application Binary Interface**) is like a set of rules that tells **compiled code** how to:

    - Pass arguments to functions

    - Return values from functions

    - Use CPU registers and stack

    - Talk to the operating system or libraries

If your code follows these rules, it can work with other programs, libraries, and the OS, even if they were compiled with a different compiler.

### Example 1 Function Call (Most Common ABI Example)
Suppose we have a simple C function:
```c
int add(int a, int b) {
    return a + b;
}
```
If you compile this function on `x86_64` Linux, the ABI (System V AMD64) specifies:

| Rule                  | What Happens                                        |
| --------------------- | --------------------------------------------------- |
| First argument (`a`)  | Goes into **RDI register**                          |
| Second argument (`b`) | Goes into **RSI register**                          |
| Return value          | Goes into **RAX register**                          |
| Stack alignment       | Must be **16-byte aligned**                         |
| Calling function      | Must preserve certain registers (`RBX`, `RBP`, `R12–R15`) |


**How it works in practice**

```asm
; x86_64 Linux assembly example
mov rdi, 5      ; first argument a = 5
mov rsi, 10     ; second argument b = 10
call add        ; call C function
; result is now in RAX register (15)
```
Even if:

- One file is compiled with `GCC`

- Another file is compiled with `Clang`

It works because both follow the same ABI rules.

### 2. Example 2: 32-bit vs 64-bit Program
If you try to run:

- 64-bit program
with

- 32-bit shared library

It fails ❌

Because:

- Pointer sizes are different

- Register usage is different

- Stack layout is different

That’s an **ABI mismatch**.

### Example 3: System Call (Kernel ABI)
```c
write(1, "Hello", 5);
```

The ABI defines:

- Which register holds the system call number

- Which registers hold arguments

- How the kernel returns the result


### Normal Function ABI vs Linux System Call ABI

| Feature | Normal Function ABI | Linux x86-64 Syscall ABI |
|---|---|---|
| Called by | User-space function | User space → Linux kernel |
| Instruction | `call` | `syscall` |
| Syscall number | Not required | `RAX` |
| 1st argument | `RDI` | `RDI` |
| 2nd argument | `RSI` | `RSI` |
| 3rd argument | `RDX` | `RDX` |
| 4th argument | `RCX` | `R10` ⚠️ |
| 5th argument | `R8` | `R8` |
| 6th argument | `R9` | `R9` |
| Return value | `RAX` | `RAX` |
| Stack alignment | 16-byte alignment | Different syscall ABI; arguments are passed in registers |
| Main difference | Uses `RCX` for 4th argument | Uses `R10` for 4th argument |

#### Argument Registers

| Argument | Normal Function | Linux Syscall |
|---|---|---|
| 1st | `RDI` | `RDI` |
| 2nd | `RSI` | `RSI` |
| 3rd | `RDX` | `RDX` |
| 4th | `RCX` | `R10` ⚠️ |
| 5th | `R8` | `R8` |
| 6th | `R9` | `R9` |

#### Key Point

Normal function:

`RDI → RSI → RDX → RCX → R8 → R9`

Linux syscall:

`RDI → RSI → RDX → R10 → R8 → R9`

**Why `R10` instead of `RCX`?**

The `syscall` CPU instruction uses `RCX` internally, so Linux uses `R10` for the 4th syscall argument.


## 3. How system call execute explain in detail.

### What is a System Call?

A **system call** is how a **user program requests a service from the kernel**.

Example in C:
```c
write(1, "Hello", 5);
```
This asks the kernel to write data to the screen.

Step-by-Step: How a System Call Executes

### 1. User Program Calls `write()`

```c
write(1, "Hello", 5);
```
- This is not directly the kernel.

- It calls a **glibc wrapper function** first.
- `glibc` -> **GNU C Library**

| glibc Function | Wraps Kernel Syscall |
| -------------- | -------------------- |
| `open()`       | `sys_open`           |
| `read()`       | `sys_read`           |
| `write()`      | `sys_write`          |
| `fork()`       | `sys_fork`           |
| `execve()`     | `sys_execve`         |


### 2. `glibc` Prepares the System Call

- C library prepares registers according to the **ABI rules**

On **x86_64** Linux, the system call ABI says:
| Register | Purpose            |
| -------- | ------------------ |
| `RAX`      | System call number |
| `RDI`      | 1st argument       |
| `RSI`      | 2nd argument       |
| `RDX`      | 3rd argument       |
| `R10`      | 4th argument       |
| `R8`       | 5th argument       |
| `R9`       | 6th argument       |


For `write(fd, buf, count)`:

```ini
RAX = 1        (sys_write number)
RDI = 1        (file descriptor)
RSI = address of "Hello"
RDX = 5        (length)
```

### 3. CPU Executes `syscall` Instruction

The wrapper executes:
```perl
syscall
```
This is a **special CPU instruction.**

What happens instantly:

- CPU switches from **User Mode → Kernel Mode**

- CPU jumps to a **predefined kernel entry point** `linux/arch/x86/entry/entry_64.S`

- Stack switches to kernel stack

- Privilege level changes (**Ring 3 → Ring 0**)

### 4. Kernel Handles the System Call

Inside the kernel:
- Kernel checks system call number (from `RAX`)

- Looks up the `system call table`

- Finds corresponding `kernel function`:
    ```scss
    sys_write()
    ```
- Executes kernel code:

### 5. Kernel Returns Result

- Return value is placed in `RAX`

- CPU executes special return mechanism (`sysret`)

- Switches from **Kernel Mode → User Mode**

- Returns control to user program

```ini
# if successfull
RAX = number of bytes written (5)
# if error
RAX = negative error code
```

### Complete Flow

```sql
User Program
     ↓
glibc wrapper
     ↓
Registers prepared (ABI rules)
     ↓
syscall instruction
     ↓
CPU switches to Kernel mode
     ↓
Kernel executes sys_write()
     ↓
Return value placed in RAX
     ↓
Back to User Mode
```

## 4. Define your own system  call and in kernel
We will create:
```scss
sys_hello()
```
That prints a message in kernel log.

### Step 1: Write the kernel function
Go to:
```bash
sudo nano kernel/hello.c
```
Add:
```c
#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(hello)
{
    printk(KERN_INFO "Hello from custom system call!\n");
    return 0;
}
```
- `SYSCALL_DEFINE0` → system call with `0` arguments

- `printk()` → kernel print

### Step 2: Add the source file to the build

File: `kernel/Makefile`

Add:
```makefile
obj-y += hello.o
```

- This instructs the kernel build system to compile hello.c and include the resulting object in the kernel.

### Step 3: Register the system call

File: `linux/arch/x86/entry/syscalls/syscall_64.tbl`

- Add an entry using a number that is unused in your particular kernel version:

```text
451    common    hello    sys_hello
```

### Step 4: Rebuild the Kernel
```go
make menuconfig
make -j4
make modules_install
make install
reboot
```

### Step 5: Call Your System Call from User Space
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

#define SYS_hello 451

int main() {
    syscall(SYS_hello);
    return 0;
}
```
Compile and run:
```bash
gcc test.c -o test
./test
```
Check kernel log:
```bash
dmesg
# you will see
Hello from custom system call!
```
```
[Write syscall function]
          ↓
[Register in syscall table]
          ↓
[Rebuild kernel]
          ↓
[Call via syscall(number)]
          ↓
[Kernel executes your function]
```

## 5. Popular system call

### Process Control System Calls

| System Call | Arguments                                | Example                          | Purpose (Detailed)                                                                                                                |
| ----------- | ---------------------------------------- | -------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| `fork()`    | —                                        | `pid = fork();`                  | Creates a new process by duplicating the parent process. The child gets its own process ID and runs concurrently with the parent. |
| `execve()`  | `char *path, char *argv[], char *envp[]` | `execve("/bin/ls", argv, envp);` | Replaces the current process memory with a new program. Used to run a new executable inside an existing process.                  |
| `exit()`    | `int status`                             | `exit(0);`                       | Terminates the calling process and releases all resources such as memory and open files.                                          |
| `wait()`    | `int *status`                            | `wait(&status);`                 | Makes the parent process wait until a child process finishes execution and collects its exit status.                              |
| `getpid()`  | —                                        | `pid = getpid();`                | Returns the unique process ID used by the OS to manage processes.                                                                 |
| `kill()`    | `pid_t pid, int sig`                     | `kill(pid, SIGKILL);`            | Sends a signal to a process to control its behavior, such as stopping or terminating it.                                          |


### File Management System Calls

| System Call | Arguments                            | Example                    | Purpose (Detailed)                                                                   |
| ----------- | ------------------------------------ | -------------------------- | ------------------------------------------------------------------------------------ |
| `open()`    | `char *path, int flags, mode_t mode` | `open("a.txt", O_RDONLY);` | Opens a file and returns a file descriptor that is used for further file operations. |
| `close()`   | `int fd`                             | `close(fd);`               | Closes an open file and frees kernel resources associated with it.                   |
| `read()`    | `int fd, void *buf, size_t n`        | `read(fd, buf, 100);`      | Reads data from a file into a buffer so the process can use it.                      |
| `write()`   | `int fd, void *buf, size_t n`        | `write(fd, buf, 100);`     | Writes data from a buffer into a file or output device.                              |
| `lseek()`   | `int fd, off_t off, int whence`      | `lseek(fd, 0, SEEK_SET);`  | Changes the current position of the file pointer to allow random access.             |
| `stat()`    | `char *path, struct stat *buf`       | `stat("a.txt", &st);`      | Retrieves file metadata such as size, permissions, and timestamps.                   |


### Device Management System Calls

| System Call | Arguments                     | Example                     | Purpose (Detailed)                                                                 |
| ----------- | ----------------------------- | --------------------------- | ---------------------------------------------------------------------------------- |
| `open()`    | `char *device, int flags`     | `open("/dev/tty", O_RDWR);` | Opens a device file and establishes communication with the hardware device.        |
| `close()`   | `int fd`                      | `close(fd);`                | Closes the device and releases it for other processes.                             |
| `read()`    | `int fd, void *buf, size_t n` | `read(fd, buf, 20);`        | Reads input or data from a hardware device.                                        |
| `write()`   | `int fd, void *buf, size_t n` | `write(fd, buf, 20);`       | Sends data or commands to a hardware device.                                       |
| `ioctl()`   | `int fd, int cmd, void *arg`  | `ioctl(fd, CMD, &v);`       | Performs device-specific control operations that are not possible with read/write. |

### Memory Management System Calls

| System Call  | Arguments                                                        | Example                                            | Purpose (Detailed)                                                     |
| ------------ | ---------------------------------------------------------------- | -------------------------------------------------- | ---------------------------------------------------------------------- |
| `brk()`      | `void *addr`                                                     | `brk(addr);`                                       | Adjusts the end of the data segment to control heap memory allocation. |
| `sbrk()`     | `int inc`                                                        | `sbrk(4096);`                                      | Dynamically increases or decreases the process heap size.              |
| `mmap()`     | `void *addr, size_t len, int prot, int flags, int fd, off_t off` | `mmap(NULL, 4096, PROT_READ, MAP_PRIVATE, fd, 0);` | Maps files or memory into a process’s virtual address space.           |
| `munmap()`   | `void *addr, size_t len`                                         | `munmap(addr, 4096);`                              | Unmaps a previously mapped memory region, freeing virtual memory.      |
| `mprotect()` | `void *addr, size_t len, int prot`                               | `mprotect(addr, 4096, PROT_READ);`                 | Changes access permissions of a memory region to enforce protection.   |


### Information Maintenance System Calls

| System Call      | Arguments                                 | Example                         | Purpose (Detailed)                                                  |
| ---------------- | ----------------------------------------- | ------------------------------- | ------------------------------------------------------------------- |
| `getuid()`       | —                                         | `uid = getuid();`               | Returns the user ID of the calling process for permission checking. |
| `setuid()`       | `uid_t uid`                               | `setuid(1000);`                 | Changes the user identity of a process to control privileges.       |
| `gettimeofday()` | `struct timeval *tv, struct timezone *tz` | `gettimeofday(&tv, NULL);`      | Gets the current system time for scheduling and logging.            |
| `uname()`        | `struct utsname *buf`                     | `uname(&u);`                    | Retrieves system information such as OS name and version.           |
| `getrlimit()`    | `int res, struct rlimit *r`               | `getrlimit(RLIMIT_NOFILE, &r);` | Gets resource usage limits for a process.                           |


### Communication (IPC) System Calls

| System Call | Arguments                                | Example                  | Purpose (Detailed)                                         |
| ----------- | ---------------------------------------- | ------------------------ | ---------------------------------------------------------- |
| `pipe()`    | `int fd[2]`                              | `pipe(fd);`              | Creates a communication channel between related processes. |
| `shmget()`  | `key_t key, size_t size, int flag`       | `shmget(k, 1024, 0666);` | Allocates shared memory for multiple processes.            |
| `shmat()`   | `int id, void *addr, int flag`           | `shmat(id, NULL, 0);`    | Attaches shared memory to a process’s address space.       |
| `msgget()`  | `key_t key, int flag`                    | `msgget(k, 0666);`       | Creates or accesses a message queue.                       |
| `msgsnd()`  | `int id, void *msg, size_t sz, int flag` | `msgsnd(id, &m, sz, 0);` | Sends a message to another process using a message queue.  |


### Network System Calls

| System Call | Arguments                                  | Example                             | Purpose (Detailed)                                |
| ----------- | ------------------------------------------ | ----------------------------------- | ------------------------------------------------- |
| `socket()`  | `int domain, int type, int proto`          | `socket(AF_INET, SOCK_STREAM, 0);`  | Creates an endpoint for network communication.    |
| `bind()`    | `int fd, struct sockaddr *a, socklen_t l`  | `bind(fd, &addr, sizeof(addr));`    | Assigns a local address to a socket.              |
| `listen()`  | `int fd, int b`                            | `listen(fd, 5);`                    | Prepares a socket to accept incoming connections. |
| `accept()`  | `int fd, struct sockaddr *a, socklen_t *l` | `accept(fd, &a, &l);`               | Accepts a connection request from a client.       |
| `connect()` | `int fd, struct sockaddr *a, socklen_t l`  | `connect(fd, &addr, sizeof(addr));` | Connects a process to a remote server.            |
| `send()`    | `int fd, void *buf, size_t n, int f`       | `send(fd, buf, n, 0);`              | Sends data over a network connection.             |
| `recv()`    | `int fd, void *buf, size_t n, int f`       | `recv(fd, buf, n, 0);`              | Receives data from a network connection.          |

---------------
## 6. How context switch happens when open function is called from user space?

### 1. User-Space Call
```c
int fd = open("file.txt", O_RDONLY);
```
- `open()` is a **glibc** wrapper.

- It prepares arguments as per **ABI** rule.

- It executes the `syscall` instruction.

### 2. Mode Switch (User → Kernel)
When syscall runs:
CPU switches from user mode (Ring 3) to kernel mode (Ring 0).

- CPU saves:

    - User instruction pointer (RIP)

    - Flags

- CPU jumps to kernel system call handler.

⚠️ This is only a **mode switch**, **not a process context switch.**

### 3. Kernel Handles open()

Kernel:

- Validates filename
- Resolves path (VFS)
- Checks permissions
- Allocates file descriptor
- Returns file descriptor number
  
Still running in **same process context**.

### 4. When Does a Context Switch Happen?

**Case 1: No Blocking (Fast) cache available**

- File metadata is already in memory.

- Kernel finishes quickly.

- Returns to user mode using sysret.

✅ Only **mode switch**
❌ No context switch


**Case 2: Disk I/O Needed (Blocking)**

If disk access is required:

1. Kernel marks the process as sleeping (blocked).

2. Scheduler selects another runnable process.

3. CPU performs a full context switch:

    - Save current process registers

    - Save stack pointer

    - Update process control block (PCB)

    - Load next process state

4. Another process runs.

When I/O completes:

1. Original process becomes runnable.

2. Scheduler eventually selects it.

3. Its context is restored.

4. Execution resumes inside the kernel.

5. Kernel returns to user space.


-----------------
## 7. What is GNU
**GNU = "GNU's Not Unix"** 

1. **Unix-like**
   - Designed to work like Unix.
   - Compatible with Unix software.

2. **Free Software Philosophy**
   - Users can **run, study, modify, and share** software.
   - Part of the **Free Software Foundation (FSF)** movement.

3. **Components**
   - **Compilers:** GCC (GNU Compiler Collection)  
   - **Libraries:** GNU C Library (glibc)  
   - **Shell:** Bash (Bourne Again SHell)  
   - **Utilities:** Coreutils, find, grep, sed, awk  

4. **Kernel**
   - GNU originally aimed to create its own kernel called **Hurd**, but it’s not widely used.
   - Most “GNU/Linux” systems use **Linux kernel + GNU utilities**.
Summary
- **GNU = Free software + Unix-like tools**
- Linux distributions are often called **GNU/Linux** because they combine GNU software with the Linux kernel.

## 8. Static and dynamic linking
### Static and Dynamic Linking in Linux

#### 1. Introduction

When a C or C++ program uses functions such as `printf()`, `malloc()`, `pthread_create()`, or functions from a custom library, the source file usually does not contain the implementation of those functions. The implementation is supplied by a library.

**Linking** is the process of combining program object files with the required library code or library references to produce an executable or another library.

Linux supports two main linking models:

1. **Static linking**: required library code is copied into the executable at link time.
2. **Dynamic linking**: the executable keeps references to shared libraries, which are loaded and resolved when the program starts or while it is running.

---

#### 2. From Source Code to Executable

A typical build passes through four conceptual stages:


| Stage | Input | Output | Main Job |
|---|---|---|---|
| Preprocessing | `.c` | `.i` | Expands macros and header files, removes comments, and processes conditional compilation directives. |
| Compilation | `.i` | `.s` | Checks syntax and types, performs optimization, and translates C code into target-specific assembly code. |
| Assembly | `.s` | `.o` | Converts assembly instructions into machine code and creates a relocatable object file. |
| Linking | `.o` files and libraries | Executable | Combines object files and libraries, resolves external symbols, performs relocation, and creates the final executable binary. |


```c
#include <stdio.h>

int main(void)
{
    printf("Hello, Linux!\n");
    return 0;
}
```

Build it normally:

```bash
gcc hello.c -o hello
```

GCC performs the required compilation and linking steps. On most Linux systems, this produces a dynamically linked executable.

To see the individual stages:

```bash
### Preprocess
gcc -E hello.c -o hello.i

### Compile to assembly
gcc -S hello.i -o hello.s

### Assemble into an object file
gcc -c hello.s -o hello.o

### Link the object file
gcc hello.o -o hello
```

The object file may still contain unresolved symbols. For example, `hello.o` refers to `printf`, but its implementation is provided by the C library.

Inspect unresolved symbols:

```bash
nm hello.o


#                   U printf
#  0000000000000000 T main
```

A symbol marked with `U` is undefined in that object file and must be resolved during linking or program loading.

---

#### 3. Important File Types

| File type | Meaning | Typical example |
|---|---|---|
| `.c` | C source file | `main.c` |
| `.o` | Relocatable object file | `main.o` |
| `.a` | Static library archive | `libmathutil.a` |
| `.so` | Shared object or dynamic library | `libmathutil.so` |
| Executable | Final ELF program | `myapp` |

Linux executables, object files, and shared libraries commonly use the **ELF**, or Executable and Linkable Format.

---

### Part I: Static Linking

#### 4. What Is Static Linking?

In static linking, the linker copies the required object code from static libraries into the final executable.

```text
main.o + libexample.a
          |
          v
A self-contained executable containing the selected library code
```

A static library is normally an archive of object files. It uses the `.a` extension.

Examples:

```text
libc.a
libm.a
libcustom.a
```

The linker normally copies only the archive members needed to resolve referenced symbols, not necessarily the entire library.

#### 5. Building a Static Library

Create a simple library.

##### `mathutil.h`

```c
#ifndef MATHUTIL_H
#define MATHUTIL_H

int add(int a, int b);

#endif
```

##### `mathutil.c`

```c
#include "mathutil.h"

int add(int a, int b)
{
    return a + b;
}
```

##### `main.c`

```c
#include <stdio.h>
#include "mathutil.h"

int main(void)
{
    printf("Result = %d\n", add(10, 20));
    return 0;
}
```

Compile the library source into an object file:

```bash
gcc -Wall -Wextra -c mathutil.c -o mathutil.o
```

> creates a static library named libmathutil.a from the object file mathutil.o.


```bash
ar rcs libmathutil.a mathutil.o
```
- `ar` → Archive tool (creates static libraries)
- `r` → Replace/add object file into library
- `c` → Create library if it doesn't exist
- `s` → Create symbol index for linker
- `libmathutil.a` → Static library name
- `mathutil.o` → Object file to add

```bash
gcc -Wall -Wextra main.c -L. -lmathutil -o app
```

| Option / Argument | Description |
|---|---|
| `gcc` | GNU C compiler driver |
| `-Wall` | Enables a broad set of common compiler warnings |
| `-Wextra` | Enables additional compiler warnings |
| `main.c` | Source file containing the `main()` function |
| `-L.` | Searches the current directory (`.`) for libraries |
| `-lmathutil` | Links against the `libmathutil` library, such as `libmathutil.a` |
| `-o app` | Names the output executable `app` |

- To request a fully static executable:

```bash
gcc main.c -static -L. -lmathutil -o app_static
```


- To explicitly select the static version of one library while allowing other dependencies to remain dynamic:

```bash
gcc main.c -L. -Wl,-Bstatic -lmathutil -Wl,-Bdynamic -o app
```

| Option | Purpose |
|---|---|
| `gcc main.c` | Compiles the main C source file |
| `-L.` | Searches the current directory for libraries |
| `-Wl,-Bstatic` | Tells the linker to prefer static libraries for subsequent library searches |
| `-lmathutil` | Links the `mathutil` library, typically `libmathutil.a` in static mode |
| `-Wl,-Bdynamic` | Restores the preference for dynamic libraries for subsequent library searches |
| `-o app` | Creates an executable named `app` |
[]
A fully static build succeeds only if static versions of all required libraries are installed and support static use.

#### 6. Static Linking at Runtime

After the executable is created, the selected library machine code is already part of the executable. The program does not need the corresponding `.a` file at runtime.

```text
Build machine                         Target machine
-------------                         --------------
main.o                                app_static
libmathutil.a       link ---------->  contains add()
```

Deleting `libmathutil.a` from the target does not affect an already linked static executable.

#### 7. Advantages of Static Linking

- **Simple deployment**: fewer runtime library files must be installed.
- **Controlled dependency version**: the executable contains the library implementation selected during the build.
- **Useful for recovery environments**: a utility can operate even when the normal shared-library filesystem is unavailable.
- **Predictable runtime dependencies**: custom statically linked code does not depend on finding the matching `.so` file.

#### 8. Disadvantages of Static Linking

- **Larger executables**: library code is included in each executable that uses it.
- **Repeated code across programs**: multiple executables may each contain their own copy of the same library routines.
- **Updates require relinking**: fixing a statically linked library does not change existing executables. They must be rebuilt or relinked and redeployed.
- **Licensing must be reviewed**: some libraries impose conditions that differ for static and dynamic distribution.
- **Not always completely independent**: some runtime behavior, such as name resolution, locale handling, plugins, or dynamically loaded modules, may still depend on target-system data or components.

---

### Part II: Dynamic Linking

#### 9. What Is Dynamic Linking?

In dynamic linking, the application contains references to shared libraries rather than copies of all required library code.

```text
Executable
    |
    +--> libc.so.6
    +--> libmathutil.so

Dynamic loader maps libraries and resolves symbols
```

Shared libraries normally use the `.so` extension. Versioned names are common:

```text
libexample.so
libexample.so.1
libexample.so.1.2.0
```

#### 10. Building a Shared Library

Compile position-independent code:

```bash
gcc -Wall -Wextra -fPIC -c mathutil.c -o mathutil.o
```

Create the shared library:

```bash
gcc -shared -Wl,-soname,libmathutil.so.1 \
    -o libmathutil.so.1.0.0 mathutil.o
```

Create symbolic links:

```bash
ln -s libmathutil.so.1.0.0 libmathutil.so.1
ln -s libmathutil.so.1 libmathutil.so
```

Link the application:

```bash
gcc -Wall -Wextra main.c -L. -lmathutil -o app_dynamic
```

For a local test without installing the library system-wide:

```bash
LD_LIBRARY_PATH=. ./app_dynamic
```

For production builds, prefer a controlled installation path, an appropriate runtime search path, or the platform's package-management approach instead of depending globally on `LD_LIBRARY_PATH`.

#### 11. Why `-fPIC` Is Used

`-fPIC` means **Position-Independent Code**. It generates code that can operate correctly when the shared library is mapped at different virtual addresses.

This is important because:

- different processes can map a library at different addresses;
- address-space layout randomization may change load addresses;
- position-independent code makes shared text pages easier to share between processes.

#### 12. What Happens When a Dynamic Program Starts?

A simplified flow is:

1. The shell requests execution of the ELF program.
2. The Linux kernel reads the executable's ELF metadata.
3. The kernel starts the ELF interpreter named in the executable, such as the system's dynamic loader.
4. The loader locates the required shared libraries.
5. It maps those libraries into the process address space.
6. It performs necessary relocations and symbol resolution.
7. Control eventually reaches the program's startup code and then `main()`.

The exact loader path depends on the architecture and Linux distribution.

Inspect the ELF interpreter:

```bash
readelf -l app_dynamic | grep 'interpreter'
```

Inspect required shared libraries:

```bash
readelf -d app_dynamic | grep NEEDED
```

Or:

```bash
objdump -p app_dynamic | grep NEEDED
```

#### 13. Library Search Locations

The dynamic loader may use information from several places, including:

- runtime search paths recorded in the executable;
- environment settings such as `LD_LIBRARY_PATH`;
- the loader cache;
- configured system library directories.

Inspect the loader cache:

```bash
ldconfig -p
```

After installing a shared library into a configured system library directory, administrators commonly refresh the loader cache with:

```bash
sudo ldconfig
```

#### 14. Immediate and Lazy Symbol Binding

Dynamic symbols can be resolved using strategies such as:

- **Immediate binding**: resolve required symbols during startup.
- **Lazy binding**: defer resolution of some function symbols until their first use.

For diagnostic testing, immediate binding can be requested with:

```bash
LD_BIND_NOW=1 ./app_dynamic
```

Immediate binding may reveal missing symbol problems at startup rather than later during execution.

#### 15. Advantages of Dynamic Linking

- **Smaller application binaries**: library implementations remain in separate `.so` files.
- **Shared physical memory**: read-only library code pages can be shared by multiple processes.
- **Centralized library updates**: compatible applications may use an updated shared library without being relinked.
- **Modular architecture**: applications can support plugins or optional components through runtime loading.
- **Reduced filesystem duplication**: multiple programs can use the same installed library file.

#### 16. Disadvantages of Dynamic Linking

- **Runtime dependencies**: required libraries and compatible symbols must be available.
- **Deployment complexity**: the target needs correct library versions and search paths.
- **Compatibility failures**: an incompatible ABI change can prevent loading or cause incorrect behavior.
- **Startup work**: the loader must locate, map, relocate, and resolve libraries.
- **Environment-related risk**: incorrectly configured search paths can load the wrong library.

---

### Part III: Detailed Comparison

#### 17. Static vs Dynamic Linking

| Aspect | Static linking | Dynamic linking |
|---|---|---|
| Library format | `.a` | `.so` |
| When core resolution occurs | Build/link time | Build records dependencies; loader completes runtime loading and resolution |
| Library code in executable | Selected code is copied into the executable | Executable mainly contains references and relocation information |
| Executable size | Usually larger | Usually smaller |
| Runtime library required | Not for the statically included library | Yes |
| Deployment | Easier for a single self-contained program | Requires compatible shared libraries |
| Library update | Rebuild and redeploy executable | Compatible library may be updated separately |
| Disk duplication | More across multiple executables | Less when programs share one installed library |
| Memory sharing | Separate executables contain separate linked copies | Read-only library pages can be shared across processes |
| Startup | No shared-library lookup for statically included code | Dynamic loader performs runtime work |
| Version control | Library version fixed at application build | Version controlled through SONAME, packaging, and ABI compatibility |
| Plugin support | Not the natural model | Well suited to runtime-loaded modules |
| Typical use | Recovery tools, restricted targets, standalone utilities | General Linux applications and systems with many programs |

#### 18. Visual Comparison

##### Static linking

```text
              Build time

main.o ----\
            +----> app_static
libA.a ----/       [main + selected libA code]

At runtime:
app_static runs without loading libA.a
```

##### Dynamic linking

```text
              Build time

main.o --------------------> app_dynamic
libA.so ---- symbol info --> dependency on libA.so

              Runtime

app_dynamic ----> dynamic loader ----> libA.so
```

---

### Part IV: Runtime Dynamic Loading

#### 19. Link-Time Dynamic Linking vs `dlopen()`

Dynamic libraries can be used in two ways.

##### Normal shared-library dependency

The library is specified when building the executable:

```bash
gcc main.c -lmathutil -o app
```

The ELF file contains a required-library entry, and the dynamic loader loads it when the program starts.

##### Explicit runtime loading

A program can load a shared object using the dynamic loading API:

```c
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*add_fn)(int, int);

int main(void)
{
    void *handle = dlopen("./libmathutil.so", RTLD_NOW);
    if (handle == NULL) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    dlerror();
    add_fn add = (add_fn)dlsym(handle, "add");

    const char *error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "dlsym failed: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    printf("Result = %d\n", add(10, 20));

    if (dlclose(handle) != 0) {
        fprintf(stderr, "dlclose failed: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```

Build it:

```bash
gcc -Wall -Wextra plugin_app.c -ldl -o plugin_app
```

This approach is useful for plugins, optional backends, and hardware-specific modules selected at runtime.

---

### Part V: Names, Versions, and Compatibility

#### 20. Library Naming

For a library named `mathutil`:

```text
libmathutil.a       Static archive
libmathutil.so      Linker name, often a symbolic link
libmathutil.so.1    SONAME-compatible runtime name
libmathutil.so.1.0  Specific implementation version
```

The `-lmathutil` option removes the `lib` prefix and file extension from the name.

```bash
gcc main.o -lmathutil -o app
```

#### 21. SONAME

A shared library's **SONAME** identifies its runtime ABI compatibility name.

Inspect it:

```bash
readelf -d libmathutil.so.1.0.0 | grep SONAME
```

An application may be linked against `libmathutil.so`, but record a dependency on `libmathutil.so.1`. A backward-incompatible ABI change should normally use a new major SONAME.

#### 22. API vs ABI

- **API**, or Application Programming Interface, describes source-level interfaces such as function names, parameters, structures, and header files.
- **ABI**, or Application Binary Interface, describes binary-level compatibility, including symbol names, calling conventions, data layout, and object-file expectations.

A program can compile successfully against an API but still fail at runtime if the available shared library has an incompatible ABI.

---

### Part VI: Linker Behavior and Common Problems

#### 23. Link Order Matters

With static archives, libraries should normally appear after the object files that reference them:

```bash
### Usually correct
gcc main.o -L. -lmathutil -o app

### May fail depending on symbols and linker behavior
gcc -L. -lmathutil main.o -o app
```

The linker generally processes inputs from left to right. When it examines an archive, it extracts members needed to resolve symbols currently known to be undefined.

Circular dependencies between static libraries may require grouping:

```bash
gcc main.o \
    -Wl,--start-group -lalpha -lbeta -Wl,--end-group \
    -o app
```

#### 24. Common Link-Time Errors

##### Undefined reference

```text
undefined reference to `add'
```

Possible causes:

- required library was not specified;
- library appears in the wrong order;
- function declaration and definition do not match;
- C and C++ symbol naming differ;
- the symbol is not exported by the library;
- the wrong library version or architecture is being used.

##### Cannot find library

```text
cannot find -lmathutil
```

Possible causes:

- no matching `libmathutil.so` or `libmathutil.a` exists;
- the linker search path is missing;
- the file name does not follow the expected naming convention.

Use:

```bash
gcc main.c -L/path/to/library -lmathutil -o app
```

#### 25. Common Runtime Errors

##### Shared library not found

```text
error while loading shared libraries:
libmathutil.so.1: cannot open shared object file
```

Useful checks:

```bash
ldd ./app_dynamic
readelf -d ./app_dynamic
ldconfig -p | grep mathutil
```

Possible corrections include installing the library in the intended target location, updating the loader configuration, rebuilding with an appropriate runtime path, or correcting the package deployment.

##### Symbol lookup error

```text
symbol lookup error: undefined symbol: some_function
```

This often indicates an incompatible shared-library version or a missing exported symbol.

Inspect symbols:

```bash
nm -D libmathutil.so
readelf -Ws libmathutil.so
```

---

### Part VII: Diagnostic Commands

#### 26. Useful Linux Commands

##### Determine file type

```bash
file app
```

##### Display shared-library dependencies

```bash
ldd app
```

For untrusted executables, prefer inspecting ELF metadata rather than executing or loading the program in an unsafe environment.

##### Show required libraries

```bash
readelf -d app | grep NEEDED
```

##### Show ELF interpreter

```bash
readelf -l app | grep interpreter
```

##### Show symbols

```bash
nm app
nm -D libexample.so
readelf -Ws libexample.so
```

##### Show library search activity

```bash
LD_DEBUG=libs ./app
```

##### Show loader and symbol activity

```bash
LD_DEBUG=libs,bindings ./app
```

##### Compare sizes

```bash
ls -lh app_dynamic app_static
size app_dynamic app_static
```

##### Trace opened library files

```bash
strace -e trace=openat ./app_dynamic
```

---

### Part VIII: Embedded Linux Considerations

#### 27. Choosing a Linking Model for Embedded Linux

The right choice depends on the complete system, not only one executable.

##### Static linking may be appropriate when

- the utility must run in a recovery or early-boot environment;
- the target root filesystem is extremely limited;
- deployment must use a single executable;
- library versions on the target cannot be guaranteed;
- the application is isolated and does not share many libraries with other programs.

##### Dynamic linking may be appropriate when

- many applications use the same libraries;
- storage and memory sharing across processes matter;
- the platform has a package or image-management strategy;
- security and bug fixes need centralized library updates;
- plugins or optional modules are required.

##### Practical BSP and cross-compilation concerns

When cross-compiling, use libraries built for the target architecture and target ABI, not host libraries.

Typical cross-compilation example:

```bash
aarch64-linux-gnu-gcc main.c \
    --sysroot=/path/to/target-sysroot \
    -L/path/to/target-sysroot/usr/lib \
    -lmathutil \
    -o app
```

Check the resulting architecture:

```bash
file app
readelf -h app
```

A frequent embedded deployment mistake is successfully linking on the build host but omitting the target `.so` file or deploying an incompatible build of it.

#### 28. Security and Maintenance Considerations

##### Static binaries

If a vulnerability is fixed in a static library, every executable containing that code must be identified, rebuilt, tested, and redeployed.

##### Dynamic binaries

A compatible shared-library update can fix multiple applications centrally. However, maintainers must preserve ABI compatibility and test all dependent applications.

For both models:

- use trusted library sources;
- control library search paths;
- avoid writable, untrusted library directories;
- track dependency versions in the build system;
- generate a software bill of materials when required;
- test on the actual target filesystem and architecture.

---

### Part IX: Worked Demonstration

#### 29. Compare Dynamic and Static Builds

Using `hello.c`:

```c
#include <stdio.h>

int main(void)
{
    puts("Hello, Linux!");
    return 0;
}
```

Build dynamically:

```bash
gcc -Wall -Wextra hello.c -o hello_dynamic
```

Build statically:

```bash
gcc -Wall -Wextra -static hello.c -o hello_static
```

Inspect both:

```bash
file hello_dynamic hello_static
ldd hello_dynamic
ldd hello_static
readelf -d hello_dynamic | grep NEEDED
ls -lh hello_dynamic hello_static
```

Expected conceptual result:

```text
hello_dynamic:
  depends on shared libraries
  normally has a smaller file size

hello_static:
  does not require the statically included libraries at runtime
  normally has a larger file size
```

Exact sizes and dependency names vary by architecture, compiler, C library, build options, and Linux distribution.

---

### Part X: Interview Summary

#### 30. Short Interview Answer

**Static linking** copies the required code from `.a` libraries into the executable at link time. It produces a more self-contained but usually larger binary. Updating the library requires rebuilding and redeploying the application.

**Dynamic linking** records dependencies on `.so` libraries. The Linux dynamic loader maps those libraries and resolves required symbols at runtime. It usually produces smaller executables, allows shared code pages across processes, and supports centralized compatible library updates, but it requires the correct libraries to be available on the target.

#### 31. Key Differences to Remember

```text
Static:  .a -> code becomes part of executable
Dynamic: .so -> library is loaded at runtime

Static:  larger executable, fewer runtime library dependencies
Dynamic: smaller executable, requires compatible target libraries

Static update: rebuild every affected executable
Dynamic update: replace a compatible shared library and test dependents
```

#### 32. Common Follow-Up Interview Questions

1. What is the difference between `.a` and `.so`?
2. Why is `-fPIC` required for shared libraries?
3. What does `ldd` show?
4. What is the ELF interpreter?
5. What is an SONAME?
6. What is the difference between an API and an ABI?
7. Why does static-library link order matter?
8. What is the purpose of `LD_LIBRARY_PATH`?
9. What is the difference between `RPATH` and `RUNPATH`?
10. How do `dlopen()` and `dlsym()` work?
11. How do you diagnose a missing shared library?
12. Why might a fully static glibc application still have operational limitations?
13. How do you package shared libraries in an Embedded Linux root filesystem?
14. How do you verify that a library matches the target architecture?

---

### Final Takeaway

There is no universally best linking method.

- Choose **static linking** when standalone deployment, recovery operation, or strict dependency control is the primary requirement.
- Choose **dynamic linking** when several programs share libraries, centralized updates are valuable, or runtime modularity is required.
- In production Embedded Linux, make the decision at the complete image level by considering flash usage, RAM sharing, boot behavior, ABI management, security updates, licensing, cross-compilation, and deployment strategy.


## 9. Execute script at boot time

### Create a systemd Service

#### Create a service file
```bash
sudo nano /etc/systemd/system/myscript.service
```

```ini
###########################################################
# [Unit]
#
# Contains metadata and dependency information.
# Systemd reads this section first to determine:
#   - What the service is
#   - When it should start
#   - Which services it depends on
###########################################################
[Unit]

# Human-readable description of the service
Description=My Startup Script

# Start this service only after otherscript.service starts
After=otherscript.service

# Hard dependency:
# If otherscript.service is not running,
# this service will not start.
Requires=otherscript.service


###########################################################
# [Service]
#
# Defines HOW the service should be executed.
# This section contains:
#   - Command to run
#   - User permissions
#   - Restart policy
#   - Working directory
###########################################################
[Service]

# Simple service:
# Systemd assumes the process started by ExecStart
# is the main process and keeps running.
Type=simple

# Full path of script/program to execute
ExecStart=/path/to/script.sh

# User account under which the script will run
User=yourusername

# Current working directory before script execution
WorkingDirectory=/path/to/

# Restart service automatically if it crashes
Restart=on-failure

# Wait 5 seconds before restart attempt
RestartSec=5


###########################################################
# [Install]
#
# Defines WHEN the service should be enabled.
# This section is used by:
#
#   systemctl enable myscript.service
#
# It creates symbolic links so the service
# starts automatically during boot.
###########################################################
[Install]

# Start the service when the system reaches
# normal multi-user mode (equivalent to runlevel 3)
WantedBy=multi-user.target
```

------------------------------------------------------
## 10. Different b/w shemphore, mutex and spinlock

| Feature                | Semaphore                                                                                                                  | Mutex                                                                                                                                                   | Spinlock                                                                                                                                     |
| ---------------------- | -------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| **Definition**         | A counter used to control access to shared resources; can allow multiple threads if count > 1                              | Binary lock that allows **only one thread** to access a resource                                                                                        | Simple lock where thread **spins (busy-waits)** until resource is free                                                                       |
| **Type**               | Can be **counting** (value > 1) or **binary** (value = 0/1)                                                                | Binary (locked/unlocked)                                                                                                                                | Binary (locked/unlocked)                                                                                                                     |
| **Ownership**          | No owner; any thread can signal (V) or wait (P)                                                                            | Has owner; only the thread that locks can unlock                                                                                                        | No ownership; any thread can release (dangerous if misused)                                                                                  |
| **Blocking behavior**  | **Can block** the thread if resource not available; scheduler switches context                                             | **Can block** the thread if resource not available; scheduler switches context                                                                          | **Does not block**; thread keeps CPU busy until lock is free                                                                                 |
| **Kernel/User Mode**   | Can be **used in user or kernel space**                                                                                    | Can be **used in user or kernel space**                                                                                                                 | Usually **used in kernel space**                                                                                                             |
| **Performance**        | Slower than spinlock; may involve context switch                                                                           | Slower than spinlock; may involve context switch                                                                                                        | Fast for short critical sections; avoids context switch                                                                                      |
| **Use Case**           | Controlling access to **multiple resources** or implementing producer-consumer                                             | Protecting a **single shared resource**                                                                                                                 | Protecting **short critical sections in kernel** where blocking is not allowed                                                               |
| **Deadlock potential** | Possible if not used carefully                                                                                             | Possible if not released                                                                                                                                | High if held too long, but low if critical section is short                                                                                  |
| **Example in Linux**   | <pre><code>#include <semaphore.h> sem_t sem; sem_init(&sem, 0, 2);  sem_wait(&sem); /* critical section */ sem_post(&sem);</pre></code> | <pre><code>#include <pthread.h> pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; pthread_mutex_lock(&m); /* critical section */ pthread_mutex_unlock(&m);</pre></code> | <pre><code> #include <linux/spinlock.h> spinlock_t lock; spin_lock_init(&lock); spin_lock(&lock); /* critical section */ spin_unlock(&lock); </pre></code> |



### Shemaphore

```c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_RESOURCES 3

// Semaphore controlling access to multiple resources
sem_t resource_sem;

void* thread_func(void* arg) {
    int id = *(int*)arg; // arg is void*; cast to int* to get thread ID

    printf("Thread %d: Waiting for a resource...\n", id);

    // sem_wait() blocks until the semaphore can be decremented
    // Arguments: sem_t *sem → pointer to semaphore
    // Return type: int → 0 on success, -1 on error
    sem_wait(&resource_sem); 
    printf("Thread %d: Acquired a resource! Working...\n", id);

    sleep(2); // Simulate work (seconds); argument: unsigned int seconds
               // Return type: unsigned int (seconds remaining if interrupted)

    printf("Thread %d: Releasing the resource.\n", id);

    // sem_post() increments the semaphore, possibly waking blocked threads
    // Arguments: sem_t *sem → pointer to semaphore
    // Return type: int → 0 on success, -1 on error
    sem_post(&resource_sem); 

    return NULL; // pthread functions must return void*
}

int main() {
    pthread_t threads[NUM_THREADS]; // thread handles
    int thread_ids[NUM_THREADS];    // IDs to pass to threads

    // sem_init() initializes the semaphore
    // Arguments: sem_t *sem → pointer to semaphore
    //            int pshared → 0 (shared between threads of process), 1 for inter-process
    //            unsigned int value → initial semaphore count
    // Return type: int → 0 on success, -1 on error
    sem_init(&resource_sem, 0, NUM_RESOURCES);

    /*
 * pthread_create() creates a new thread.
 *
 * Prototype:
 * int pthread_create(pthread_t *thread,
 *                    const pthread_attr_t *attr,
 *                    void *(*start_routine)(void *),
 *                    void *arg);
 *
 * Parameters:
 * thread
 *    - Pointer to thread identifier.
 *    - Used later with pthread_join(), pthread_cancel(), etc.
 *
 * attr
 *    - Thread attributes.
 *    - Pass NULL to use default attributes.
 *    - Can be used to configure stack size, detach state, priority, etc.
 *
 * start_routine
 *    - Function executed by the new thread.
 *    - Must have the signature:
 *        void *function_name(void *arg);
 *
 * arg
 *    - Argument passed to the thread function.
 *    - Can pass a structure, integer, or pointer.
 *
 * Return Value:
 *    - Returns 0 on success.
 *    - Returns an error number on failure.
 *
 * Notes:
 *    - The new thread starts executing immediately after creation.
 *    - Multiple threads run concurrently within the same process.
 *    - Threads share process resources:
 *         * Global variables
 *         * Heap memory
 *         * Open file descriptors
 *    - Each thread has its own:
 *         * Stack
 *         * Registers
 *         * Program counter
 *
 * Commonly used with:
 *    pthread_join()    -> Wait for thread completion.
 *    pthread_exit()    -> Terminate a thread.
 *    pthread_detach()  -> Release thread resources automatically.
 */
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    // pthread_join() waits for a thread to finish
    // Arguments: pthread_t thread → thread handle
    //            void **retval → pointer to store return value of thread (can be NULL)
    // Return type: int → 0 on success, error number on failure
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // sem_destroy() destroys the semaphore
    // Arguments: sem_t *sem → pointer to semaphore
    // Return type: int → 0 on success, -1 on error
    sem_destroy(&resource_sem);

    printf("All threads finished.\n");
    return 0;
}

```
```bash
Thread 1 waiting for printer...
Thread 2 waiting for printer...
Thread 3 waiting for printer...
Thread 1 got a printer!
Thread 2 got a printer!
Thread 3 got a printer!
Thread 4 waiting for printer...
Thread 5 waiting for printer...
Thread 1 released the printer.
Thread 4 got a printer!
Thread 2 released the printer.
Thread 5 got a printer!
...
```

### Mutex

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

pthread_mutex_t mutex;   // Mutex variable (used to protect shared resource)
int counter = 0;         // Shared variable

// Thread function
// Argument: void* arg → pointer to thread ID
// Return type: void* → must return void* (NULL here)
void* increment(void* arg) {
    int id = *(int*)arg;  // Convert void* to int*

    printf("Thread %d trying to lock mutex...\n", id);

    // pthread_mutex_lock()
    // Argument: pthread_mutex_t* → pointer to mutex
    // Return type: int → 0 on success, error number on failure
    pthread_mutex_lock(&mutex);

    printf("Thread %d inside critical section\n", id);

    // Critical section (only one thread executes this at a time)
    int temp = counter;

    // sleep()
    // Argument: unsigned int seconds
    // Return type: unsigned int → remaining seconds if interrupted
    sleep(1);  // simulate work

    counter = temp + 1;

    printf("Thread %d updated counter to %d\n", id, counter);

    // pthread_mutex_unlock()
    // Argument: pthread_mutex_t* → pointer to mutex
    // Return type: int → 0 on success, error number on failure
    pthread_mutex_unlock(&mutex);

    printf("Thread %d released mutex\n", id);

    return NULL;  // Thread returns void*
}

int main() {
    pthread_t threads[NUM_THREADS];  // Thread identifiers
    int ids[NUM_THREADS];            // Thread IDs passed as argument

    // pthread_mutex_init()
    // Arguments:
    // pthread_mutex_t* → pointer to mutex
    // const pthread_mutexattr_t* → attributes (NULL = default)
    // Return type: int → 0 on success, error number on failure
    pthread_mutex_init(&mutex, NULL);

    // pthread_create()
    // Arguments:
    // pthread_t* → address to store thread ID
    // const pthread_attr_t* → thread attributes (NULL = default)
    // void* (*start_routine)(void*) → function executed by thread
    // void* arg → argument passed to thread function
    // Return type: int → 0 on success, error number on failure
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, increment, &ids[i]);
    }

    // pthread_join()
    // Arguments:
    // pthread_t → thread ID to wait for
    // void** → pointer to store thread return value (NULL if not needed)
    // Return type: int → 0 on success, error number on failure
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // pthread_mutex_destroy()
    // Argument: pthread_mutex_t* → pointer to mutex
    // Return type: int → 0 on success, error number on failure
    pthread_mutex_destroy(&mutex);

    printf("Final counter value: %d\n", counter);

    return 0;  // main returns int → exit status (0 = success)
}
```
```bash
Thread 1 trying to lock mutex...
Thread 1 inside critical section
Thread 2 trying to lock mutex...
Thread 3 trying to lock mutex...
Thread 1 updated counter to 1
Thread 1 released mutex
Thread 2 inside critical section
Thread 2 updated counter to 2
Thread 2 released mutex
Thread 3 inside critical section
Thread 3 updated counter to 3
Thread 3 released mutex
Final counter value: 3
```

### Spinlock

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

pthread_spinlock_t spinlock;  // Spinlock variable
int counter = 0;              // Shared variable

// Thread function
// Argument: void* arg → pointer to thread ID
// Return type: void* → must return void*
void* increment(void* arg) {
    int id = *(int*)arg;

    printf("Thread %d trying to acquire spinlock...\n", id);

    // pthread_spin_lock()
    // Argument: pthread_spinlock_t* → pointer to spinlock
    // Return type: int → 0 on success
    // If lock is busy, thread keeps spinning (busy-wait)
    pthread_spin_lock(&spinlock);

    printf("Thread %d inside critical section\n", id);

    // Critical section
    int temp = counter;
    sleep(1);  // simulate work (not ideal for spinlock, just for demo)
    counter = temp + 1;

    printf("Thread %d updated counter to %d\n", id, counter);

    // pthread_spin_unlock()
    // Argument: pthread_spinlock_t* → pointer to spinlock
    // Return type: int → 0 on success
    pthread_spin_unlock(&spinlock);

    printf("Thread %d released spinlock\n", id);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    // pthread_spin_init()
    // Arguments:
    // pthread_spinlock_t* → pointer to spinlock
    // int pshared → 0 (shared between threads of same process)
    // Return type: int → 0 on success
    pthread_spin_init(&spinlock, 0);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, increment, &ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // pthread_spin_destroy()
    // Argument: pthread_spinlock_t*
    // Return type: int → 0 on success
    pthread_spin_destroy(&spinlock);

    printf("Final counter value: %d\n", counter);

    return 0;
}
```
```bash
Thread 1 trying to acquire spinlock...
Thread 1 inside critical section
Thread 2 trying to acquire spinlock...
Thread 3 trying to acquire spinlock...
Thread 1 updated counter to 1
Thread 1 released spinlock
Thread 2 inside critical section
Thread 2 updated counter to 2
Thread 2 released spinlock
Thread 3 inside critical section
Thread 3 updated counter to 3
Thread 3 released spinlock
Final counter value: 3
```
## 11. Different b/w character, block and network device driver


| Aspect                    | Character Device Driver                       | Block Device Driver                       | Network Device Driver         |
| ------------------------- | --------------------------------------------- | ----------------------------------------- | ----------------------------- |
| **Data flow**             | Stream of bytes (one character at a time)     | Fixed-size blocks (e.g., 512 bytes, 4 KB) | Packets (frames)              |
| **Access type**           | Sequential (no random access)                 | Random access supported                   | Message-based                 |
| **Kernel buffering**      | No buffering or very minimal                  | Heavy buffering and caching by kernel     | Uses networking stack buffers |
| **Data organization**     | No blocks or sectors                          | Organized into blocks                     | Organized into packets        |
| **Read/Write model**      | `read()` / `write()` in order                 | Block I/O requests                        | Packet transmit/receive       |
| **Seek support**          | No `llseek()`                                 | Supports `llseek()`                       | No seek concept               |
| **Main kernel interface** | `file_operations`                             | `block_device_operations`                 | `net_device_ops`              |
| **Who controls I/O**      | User process                                  | Kernel                                    | Network stack                 |
| **Performance focus**     | Simplicity, responsiveness                    | Throughput, caching                       | Latency, throughput           |
| **Typical complexity**    | Low                                           | Medium                                    | High                          |
| **Common examples**       | Keyboard, Mouse, Serial ports, Audio, Sensors | HDD, SSD, USB, CD/DVD                     | Ethernet, Wi-Fi, Virtual NICs |
| **Mental model**          | Live conversation                             | Book                                      | Sending letters               |

### One-line takeaway (easy to remember)
> **Character drivers handle byte streams, block drivers handle kernel-managed storage blocks, and network drivers handle packets via the > networking stack.**



## 12. Can we send strucure using `IOCTL`?
yes 

## 13. Explain any linux subsystem in details?

## 14. Add any system call in linux?

## 15. use of `perf` tool for linux?
- Performance analysis and monitoring tool
  
## 16. Changes required to add CAN driver in BSP

### 1. Enable CAN Peripheral in Hardware Configuration

#### 1. Kernel driver
   - Ensure the Linux kernel contains a compatible `MCP2517FD/MCP251xFD` driver.
   - For an older kernel such as Linux 5.5, driver backporting may be required.

#### 2. Kernel configuration
   - Enable the CAN/SocketCAN and SPI subsystems.
   - Typical configuration:
   - Enable the MCP251xFD driver symbol if supported by that kernel.
   This configuratoin is my layer  `/meta-mcp2517/recipes-kernel/linux/files/can.cfg`
  ```bash
  CONFIG_CAN=y
  CONFIG_CAN_RAW=y
  CONFIG_CAN_DEV=y
  CONFIG_SPI=y
  ```  
#### 3. Yocto integration
  1. Create your custom layer
  ```bash
   bitbake-layers create-layer ../meta-mcp2517
   bitbake-layers add-layer ../meta-mcp2517
   ```
  2. Create kernel recipe directory
   ```bash
   mkdir -p ../meta-mcp2517/recipes-kernel/linux/linux-raspberrypi
   ```
  3. Create CAN kernel configuration
  ```bash
    cat > ../meta-mcp2517/recipes-kernel/linux/linux-raspberrypi/can.cfg <<'EOF'
    CONFIG_CAN=y
    CONFIG_CAN_RAW=y
    CONFIG_CAN_DEV=y
    CONFIG_SPI=y
    EOF
  ```
  4. Create kernel .bbappend // add reciepe in kernel
 
```bash
    cat > ../meta-mcp2517/recipes-kernel/linux/linux-raspberrypi_%.bbappend <<'EOF'
    FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

    SRC_URI += "file://can.cfg"
    EOF
```


#### 4. Device Tree
Describe how MCP2517FD is connected:
```text
SPI controller
Chip Select
Interrupt GPIO
Oscillator/clock
```

----------------------------
- Configure `CAN pins` (TX, RX) in `MCU pinmux` or `GPIO` registers.

- Enable CAN clock in the MCU (usually via `RCC` or similar register). (**RCC -Reset and Clock Control.**)

- Configure CAN bit timing (baud rate, propagation, sample points).

- Optional: Enable interrupts for CAN events (RX, TX, error).

### 2. Update BSP Device Tree / Hardware Definition

- Add CAN controller node if your BSP uses a device tree (common in `RTOS` or `Linux`).

Specify:
- Base address of CAN peripheral
- Interrupt numbers
- Clock frequency
- Pin configuration

Example snippet (for Linux DT):

```dts
can1: can@40006400 {             // CAN1 peripheral node at memory address 0x40006400
    compatible = "vendor,can";   // Compatible string for driver selection
    reg = <0x40006400 0x400>;    // Base address = 0x40006400, size = 0x400 (1 KB)
    interrupts = <30>;           // Interrupt number assigned to this CAN peripheral
    clocks = <&can_clk>;         // Reference to the CAN clock node (RCC-controlled)
    status = "okay";             // Peripheral is enabled; "disabled" would ignore it
};
```
### 3. Add CAN Driver Source Files 

- BSP usually has a drivers folder. Add:

    - CAN driver source (e.g., `can.c`, `can.h`)

    - **Hardware abstraction layer (HAL)** or **low-level MCU** routines
- Driver should implement:
    - **Initialization**: CAN_Init()

    - **Send Frame**: CAN_Transmit()

    - **Receive Frame**: CAN_Receive()

    - **Interrupt handler**: CAN_IRQHandler()

### 4. Integrate with OS / HAL
- If using RTOS, integrate driver with:

    - Interrupt service routine (`ISR`) for `RX/TX` events

    - `Queues` or `semaphores` for sending/receiving messages
  
- If using `bare metal`, implement polling or callback mechanism.

### 5. Update BSP Initialization Code

In the BSP’s board_init() or peripheral_init() function:
- Enable CAN clocks

- Configure GPIO pins

- Initialize CAN peripheral using the driver

- Enable CAN interrupts

### 6. Add Device Registration (Optional)

- If OS supports device files (`Linux/RTOS`):

- Register CAN device so applications can use standard API (`read()`, `write()`, `ioctl()`).

## 17. How so you debug crash occuring after 1 month of kernel without logs?

### 1. Capture Crash Info

  - Use **kernel crash dump (kdump)** to save memory when it crashes.

  - Use** serial console or netconsole** to catch messages before crash

### 2. Check for Common Long-Uptime Issues
  - **Memory leaks** → kernel or module slowly uses all memory.

  - **Resource leaks** → too many `files`, `sockets`, or `threads` open.

  - `Counters` / `timers` overflow → e.g., `jiffies` wraparound.

  - **Rare race conditions** → happen only after a long time.
  
### 3. Monitor System
-  Watch memory (`/proc/meminfo`), `CPU`, open `files`, `network sockets`.

## 18. How to serial communication using commandline


```bash
# concigure UART
stty -F /dev/ttyUSB0 115200 cs8 -cstopb -parenb raw -echo

```

| Option  | Meaning                   |
| ------- | ------------------------- |
| 115200  | Baud rate                 |
| cs8     | 8 data bits               |
| -cstopb | 1 stop bit                |
| -parenb | No parity                 |
| raw     | Raw mode (no processing)  |
| -echo   | Do not echo received data |
---
**Send Data to UART**

```bash
echo "Hello" > /dev/ttyUSB0 # new line included "Hello\n"

echo -n "Hello" > /dev/ttyUSB0 # Send without new line

printf '\x01\x03\x00\x00\x00\x02\xC4\x0B' > /dev/ttyUSB0  # Send hex bytes

```
---------------------
**Receive Data from UART**

```bash
cat /dev/ttyUSB0 # Read continuously
cat /dev/ttyUSB0 | hexdump -C # read in hex formate

dd if=/dev/ttyUSB0 bs=1 count=8 2>/dev/null | hexdump -C # read only first 8 bytes

```
-----------------------------
## 19. How to debug i2c device driver if not shown in /dev.

### Step 1: Check Kernel Detection

**Why:** The kernel must first detect the I2C bus and the device. If the kernel doesn’t see the device, the driver cannot bind.


**How:**

```bash
i2cdetect -y 1           # Check connected devices -> 1 is bus number (here i2c-1)
i2cget -y 1 0x50 0x00    # Read register 0x00
i2cset -y 1 0x50 0x00 0xFF # Write 0xFF to register 0x00

```
- If commands work → hardware is fine → problem is driver or device tree

- If commands fail → check wiring, pull-ups, power, or device address
**Interpretation:**

>If the device is not listed, it could be a incorrect bus configuration, hardware issue, missing pull-ups.



### Step 2: Check Device Tree / Platform Data
**Why:** For most embedded systems, the kernel needs a device tree entry or platform data to know that a device exists on the I2C bus. Without this, the driver cannot bind.

**How:**

Check device tree (.dts) for the device node:

```dts
i2c1: i2c@40005400 {
    status = "okay";
    mydevice@50 {
        compatible = "vendor,mydevice";
        reg = <0x50>;
    };
};
```
- `compatible` must match the driver’s `of_match_table`.

`status = "okay"` enables the device; otherwise, the kernel ignores it.

### Step 3: Check if the Driver is Loaded
**Why:** If the module is not loaded, the driver cannot probe the device.

```bash
lsmod | grep my_driver      # Check if loaded
modprobe my_driver          # Load the module if missing
dmesg | tail -n 50          # Check for probe messages or errors
```
- **Errors in dmesg indicate problems in initialization or binding.**

### Step 4: Verify Driver Binding

**Why:** The driver only binds to devices with matching compatible strings or IDs. Mismatched entries will prevent /dev creation.


Check driver code for device table:
```c
static const struct of_device_id my_i2c_dt_ids[] = {
    { .compatible = "vendor,mydevice", },
    {},
};
MODULE_DEVICE_TABLE(of, my_i2c_dt_ids);
```

This is will create driver and device in 
```bash
ls /sys/bus/i2c/devices/
# you will see 1-0050  This is address

# Then check driver binding
ls /sys/bus/i2c/drivers/  
```

- If compatible does not match the device tree, the probe function never runs.

### Step 5: Check /dev Creation

**Why:** Even if the driver binds, /dev may not appear if the character device is not registered.

```c
alloc_chrdev_region(&dev, 0, 1, "mydevice");
cdev_init(&my_cdev, &fops);
cdev_add(&my_cdev, dev, 1);
device_create(my_class, NULL, dev, NULL, "mydevice");
```

### Step 6: Enable Debug Prints
Why: Debug prints in the probe function help verify whether the driver is actually being called.

```c
dev_info(&client->dev, "Device probed successfully\n");
```
```bash
dmesg | tail -n 50
```

### Step 7: Test with i2c-tools

```bash
i2cdetect -y 1           # Check device addresses
i2cget -y 1 0x50 0x00    # Read register 0x00
i2cset -y 1 0x50 0x00 0xFF # Write 0xFF to register 0x00
```

## 20. Kernel Debugging and Tracing methods


### 1. `ftrace` Function Tracer
- `ftrace` is a kernel tracing framework in the Linux kernel used to trace **function calls**, **scheduling events**, and **latency** in real time.


#### 🎯 When to use

- Debug **kernel execution flow**
  
- Analyze **scheduler behavior**

- Investigate **latency issues**


#### Example
> My system is lagging randomly. I want to see which kernel functions are taking time

#### How to do it

```bash
cd /sys/kernel/debug/tracing

# Enable function graph tracer (shows timing)
echo function_graph > current_tracer

# Start tracing
echo 1 > tracing_on

# View trace
cat trace
```
 
### 2. `perf` Performance Analysis Tool

- `perf` is a **performance profiling tool** in the Linux kernel that uses **hardware counters** (PMU) to find performance bottlenecks.

#### When to use
 
- ✅ Find CPU hotspots (functions consuming most CPU time)

- ✅ Analyze slow applications

- ✅ Measure CPU cycles

- ✅ Measure cache misses

- ✅ Profile user-space and kernel-space code

- ✅ Identify performance bottlenecks

#### Example

> 👉 “My application is using 100% CPU. I want to know which function is responsible.”

```bash
# Live CPU profiling
perf top

# Record performance data
perf record ./app

# CPU statistics
perf stat ./app

# Profile a running process
perf record -p <PID>

# View report
perf report

```



### 3. `kprobes`

- `kprobes` is a **dynamic kernel instrumentation tool** in the Linux kernel that lets you insert probes into running kernel code.

#### When to use
- Debug **specific kernel function**
- Add **custom tracing without recompiling kernel**
- Investigate **rare bugs in production**

```bash
cd /sys/kernel/debug/tracing

# Add probe on schedule()
echo 'p:sched schedule' > kprobe_events

# Start tracing
echo 1 > tracing_on

# View trace
cat trace
```
> `ftrace` is used for kernel **flow and latency tracing**, `perf` is used for performance profiling and CPU hotspot analysis, and `kprobes` is used for dynamically debugging specific kernel functions without rebuilding the kernel.

# Kernel interview Questions

## 1. Can you explain what a kernel is and its main functions?
- A **kernel** is the **core part of an operating system**—it acts as the **bridge between your software (apps) and the hardware (CPU, memory, devices)**. 
- Think of it as the system’s “manager” that makes sure everything runs smoothly and safely.

### Main Functions of a Kernel

#### 1. Process Management
- Handles running programs (**processes**)
- Decides which process gets CPU time (**scheduling**)
- Allows **multitasking**
👉 Example: Running a browser, music player, and editor at the same time

#### 2. Memory Management
- Allocates and deallocates RAM to processes
- Keeps processes isolated (so one app doesn’t overwrite another’s memory)

👉 Prevents crashes and improves stability

#### 3. Device Management (I/O Control)
- Communicates with hardware using drivers- [C and C++](#c-and-c)
  - [MISRA C:2012 – 100 Coding Rules with Examples](#misra-c2012--100-coding-rules-with-examples)
    - [1-20](#1-20)
    - [21-40](#21-40)
    - [41-60](#41-60)
    - [61-80](#61-80)
    - [81-100](#81-100)
  - [Pointer declaration](#pointer-declaration)
  - [Pointer post-prefix increment](#pointer-post-prefix-increment)
  - [Decimal to hex conversion](#decimal-to-hex-conversion)
  - [Virtaul function and pure virtual function difference.](#virtaul-function-and-pure-virtual-function-difference)
  - [Diamond problem in C++](#diamond-problem-in-c)
  - [Other use case of virtual keyword](#other-use-case-of-virtual-keyword)
    - [1. Runtime Polymorphism](#1-runtime-polymorphism)
    - [2. Virtual Destructor](#2-virtual-destructor)
    - [3. Virtual Inheritance](#3-virtual-inheritance)
    - [4. Pure Virtual Functions (Abstract Classes)](#4-pure-virtual-functions-abstract-classes)
- [Kernel programming](#kernel-programming)
  - [`restrict` Keyword in C99 — Notes with Examples](#restrict-keyword-in-c99--notes-with-examples)
    - [What is `restrict`?](#what-is-restrict)
    - [🧠 Key Points](#-key-points)
    - [🧪 Example Code](#-example-code)
      - [✅ Correct Usage](#-correct-usage)
      - [❌ Incorrect Usage — Undefined Behavior](#-incorrect-usage--undefined-behavior)
  - [Strict Aliasing Rule](#strict-aliasing-rule)
    - [❌ Bad Example (Undefined behavior):](#-bad-example-undefined-behavior)
    - [✅ Safe workaround:](#-safe-workaround)
  - [`volatile`](#volatile)
    - [🔧 Use Cases:](#-use-cases)
    - [Example Recap (non-volatile flag):](#example-recap-non-volatile-flag)
      - [Step 1: Understanding the compiler’s assumptions](#step-1-understanding-the-compilers-assumptions)
      - [Step 2: Optimization performed — Register caching](#step-2-optimization-performed--register-caching)
      - [Step 3: Why this optimization makes sense](#step-3-why-this-optimization-makes-sense)
      - [Step 4: When this breaks — external changes](#step-4-when-this-breaks--external-changes)
      - [Step 5: How volatile fixes this](#step-5-how-volatile-fixes-this)
      - [Step 6: How the generated code differs](#step-6-how-the-generated-code-differs)
      - [Step 7: Real Assembly Example (simplified)](#step-7-real-assembly-example-simplified)
  - [`const volatile`](#const-volatile)
  - [`_Atomic`](#_atomic)
    - [Why do you need it?](#why-do-you-need-it)
  - [What are Memory Barriers? Why Are They Important?](#what-are-memory-barriers-why-are-they-important)
    - [why Memory barriers happened?](#why-memory-barriers-happened)
      - [Why is this allowed?](#why-is-this-allowed)
    - [❌ Example Without Memory Barrier (Possible Bug)](#-example-without-memory-barrier-possible-bug)
      - [❓What You Expect](#what-you-expect)
      - [⚠️ What Can Go Wrong:](#️-what-can-go-wrong)
    - [✅ Example WITH Memory Barrier (Correct)](#-example-with-memory-barrier-correct)
      - [✅ Now Guaranteed](#-now-guaranteed)
    - [barriar type](#barriar-type)
    - [Are \_\_sync\_synchronize(); and mb() the same?](#are-__sync_synchronize-and-mb-the-same)
  - [What is the difference between `static`, `extern`, and `static inline` functions in the kernel?](#what-is-the-difference-between-static-extern-and-static-inline-functions-in-the-kernel)
  - [How is `inline` Used in Kernel Code? What's the Role of `__always_inline`?](#how-is-inline-used-in-kernel-code-whats-the-role-of-__always_inline)
  - [What is the Role of `container_of()` Macro?](#what-is-the-role-of-container_of-macro)
  - [Use of typeof() and Its Role in Kernel Macros](#use-of-typeof-and-its-role-in-kernel-macros)
  - [What are `__init` and` __exit` in Kernel Modules?](#what-are-__init-and-__exit-in-kernel-modules)
    - [✅ ==\_\_init — Marks the Initialization Function](#-__init--marks-the-initialization-function)
    - [❌ \_\_exit — Marks the Cleanup Function](#-__exit--marks-the-cleanup-function)
    - [🧾 Simple Example](#-simple-example)
      - [What happens here?](#what-happens-here)
  - [What is Pointer Alignment?](#what-is-pointer-alignment)
    - [✅ Simple Example](#-simple-example-1)
      - [❌ What if it’s misaligned?](#-what-if-its-misaligned)
    - [🔧 In Kernel Code](#-in-kernel-code)
    - [🛠 How to Ensure Proper Alignment?](#-how-to-ensure-proper-alignment)
    - [Kernel memory](#kernel-memory)
    - [DMA Alignment](#dma-alignment)
  - [How are bitfields used in hardware registers?](#how-are-bitfields-used-in-hardware-registers)
    - [Step 1: Define a bitfield in C](#step-1-define-a-bitfield-in-c)
    - [Step 2: Access the bits](#step-2-access-the-bits)
  - [Difference Between `kmalloc()` and `vmalloc()`](#difference-between-kmalloc-and-vmalloc)
  - [What is Unaligned Memory Access?](#what-is-unaligned-memory-access)
    - [Unaligned Memory Access](#unaligned-memory-access)
    - [✅ Aligned Example](#-aligned-example)
    - [❌ Unaligned Example](#-unaligned-example)
    - [All possible way to handle unaligned memory access](#all-possible-way-to-handle-unaligned-memory-access)
  - [Difference Between `memcpy()` and `memmove()` in Kernel Space](#difference-between-memcpy-and-memmove-in-kernel-space)
  - [Unions in Hardware Register Definitions — Explained with Example](#unions-in-hardware-register-definitions--explained-with-example)
    - [Why use unions?](#why-use-unions)
  - [How to Prevent Structure Padding in C (for Memory-Mapped I/O)](#how-to-prevent-structure-padding-in-c-for-memory-mapped-io)
    - [1. Using __attribute__((packed)) in GCC](#1-using-attributepacked-in-gcc)
    - [2. Using #pragma pack (MSVC or GCC)](#2-using-pragma-pack-msvc-or-gcc)
    - [3. Memory-Mapped I/O Register Structure](#3-memory-mapped-io-register-structure)
  - [How do `copy_from_user()` and `copy_to_user()` work?](#how-do-copy_from_user-and-copy_to_user-work)
  - [Why can't you directly dereference user-space pointers in kernel?](#why-cant-you-directly-dereference-user-space-pointers-in-kernel)
  - [Difference between `get_user()` and `copy_from_user()`?](#difference-between-get_user-and-copy_from_user)
  - [Risks of using  `memcpy()` with user-space pointers?](#risks-of-using--memcpy-with-user-space-pointers)
  - [How do you perform DMA mapping in kernel?](#how-do-you-perform-dma-mapping-in-kernel)
    - [1️⃣ What is DMA?](#1️⃣-what-is-dma)
      - [What DMA Mapping Is (in simple words)](#what-dma-mapping-is-in-simple-words)
    - [2️⃣ How DMA Mapping Works](#2️⃣-how-dma-mapping-works)
  - [Explain page faults in kernel mode and how to avoid them.](#explain-page-faults-in-kernel-mode-and-how-to-avoid-them)
    - [What is a page fault in kernel mode?](#what-is-a-page-fault-in-kernel-mode)
    - [Why are page faults tricky in the kernel?](#why-are-page-faults-tricky-in-the-kernel)
    - [How to avoid page faults in kernel mode?](#how-to-avoid-page-faults-in-kernel-mode)
  - [What happens if a kernel module dereferences a null pointer?](#what-happens-if-a-kernel-module-dereferences-a-null-pointer)
  - [How is memory protection handled between user and kernel space?](#how-is-memory-protection-handled-between-user-and-kernel-space)
  - [What is the slab allocator? How does it differ from the buddy allocator?](#what-is-the-slab-allocator-how-does-it-differ-from-the-buddy-allocator)
  - [How does `kmem_cache_create()` help performance?](#how-does-kmem_cache_create-help-performance)
  - [How do you debug kernel memory leaks?](#how-do-you-debug-kernel-memory-leaks)
    - [✅ 1. Use `kmemleak` (Kernel Memory Leak Detector)](#-1-use-kmemleak-kernel-memory-leak-detector)
      - [1.Enable it in the kernel config](#1enable-it-in-the-kernel-config)
    - [2. Use slabtop](#2-use-slabtop)
  - [What does "*sleeping*" mean in memory allocation?](#what-does-sleeping-mean-in-memory-allocation)
  - [What are GFP Flags?](#what-are-gfp-flags)
    - [Common GFP Flags and Their Use](#common-gfp-flags-and-their-use)
  - [| `GFP_DMA`      | Memory below 16MB (DMA-capable)        | ✅ Yes      | Legacy devices needing DMA |](#-gfp_dma-------memory-below-16mb-dma-capable----------yes-------legacy-devices-needing-dma-)
  - [What is the `highmem zone` and how do you access it?](#what-is-the-highmem-zone-and-how-do-you-access-it)
    - [What is **HighMem**?](#what-is-highmem)
    - [Memory Zones in Linux Kernel](#memory-zones-in-linux-kernel)
    - [How to Access HighMem](#how-to-access-highmem)
    - [Why HighMem Is Mostly 32-bit Only](#why-highmem-is-mostly-32-bit-only)
  - [How do you prevent stack overflows in kernel code?](#how-do-you-prevent-stack-overflows-in-kernel-code)
    - [✅ Tips to Prevent Stack Overflows:](#-tips-to-prevent-stack-overflows)
      - [Avoid large local variables](#avoid-large-local-variables)
    - [Keep functions simple](#keep-functions-simple)
      - [Use static analysis tools](#use-static-analysis-tools)
    - [Use compiler stack checks](#use-compiler-stack-checks)
  - [When do you use mutext and shemphore](#when-do-you-use-mutext-and-shemphore)
    - [Mutex](#mutex)
      - [Mutex deadloack](#mutex-deadloack)
    - [Why we should use Mutex not global variable](#why-we-should-use-mutex-not-global-variable)
    - [How kernel handle mutext](#how-kernel-handle-mutext)
    - [Shemaphore](#shemaphore)
  - [Spinlocks vs Mutexes in Kernel](#spinlocks-vs-mutexes-in-kernel)
    - [Spinlock:](#spinlock)
    - [Mutex:](#mutex-1)
    - [🛠️ Example](#️-example)
  - [What is an Interrupt Context and Can It Sleep?](#what-is-an-interrupt-context-and-can-it-sleep)
  - [Bottom Halves, Tasklets, and Workqueues](#bottom-halves-tasklets-and-workqueues)
    - [What happens when an interrupt occurs?](#what-happens-when-an-interrupt-occurs)
    - [Handling an interrupt has two parts:](#handling-an-interrupt-has-two-parts)
      - [✅ Top Half (Fast Handler)](#-top-half-fast-handler)
      - [🔻 Bottom Half (Deferred Work)](#-bottom-half-deferred-work)
      - [1. 🧩 Tasklets (can not sleep and not intruptted by others)](#1--tasklets-can-not-sleep-and-not-intruptted-by-others)
      - [2. 🧵 Workqueues (can sleep)](#2--workqueues-can-sleep)
      - [Summary](#summary)
    - [Example](#example)
  - [Purpose of `atomic_t` and `atomic64_t`](#purpose-of-atomic_t-and-atomic64_t)
    - [Why?](#why)
  - [35. Can You Use Mutexes in Interrupt Handlers?](#35-can-you-use-mutexes-in-interrupt-handlers)
  - [RCU (Read-Copy-Update) and Seqlocks – What and When?](#rcu-read-copy-update-and-seqlocks--what-and-when)
  - [7. How Do You Avoid Deadlocks in Kernel Code?](#7-how-do-you-avoid-deadlocks-in-kernel-code)
    - [✅ Avoid deadlocks by:](#-avoid-deadlocks-by)
    - [Lockdep for Kernel and C++](#lockdep-for-kernel-and-c)
  - [What is Preemption? How to Disable/Enable It?](#what-is-preemption-how-to-disableenable-it)
  - [How Do You Implement a Lock-Free Queue in the Kernel?](#how-do-you-implement-a-lock-free-queue-in-the-kernel)
  - [Priority Inversion – Simple Explanation](#priority-inversion--simple-explanation)
    - [🔧 Problem (What is it?)](#-problem-what-is-it)
    - [Why is it bad?](#why-is-it-bad)
    - [🛠️ Solution – Priority Inheritance](#️-solution--priority-inheritance)
    - [In One Line:](#in-one-line)
  - [How do you map hardware registers to virtual memory in kernel?](#how-do-you-map-hardware-registers-to-virtual-memory-in-kernel)
    - [1. What are hardware registers?](#1-what-are-hardware-registers)
    - [2. Why map them to virtual memory?](#2-why-map-them-to-virtual-memory)
    - [3. How does the kernel map them?](#3-how-does-the-kernel-map-them)
    - [4. Now the kernel can use the mapped address](#4-now-the-kernel-can-use-the-mapped-address)
    - [5. Cleanup when done](#5-cleanup-when-done)
  - [What is a device file? How is it connected to a driver?](#what-is-a-device-file-how-is-it-connected-to-a-driver)
    - [How is it Connected to a Driver?](#how-is-it-connected-to-a-driver)
    - [Steps in Linux](#steps-in-linux)
- [Embedded System](#embedded-system)
  - [Define array of function pointer and use it in interrupt handling](#define-array-of-function-pointer-and-use-it-in-interrupt-handling)
    - [Use case of array of function pointer in ISR](#use-case-of-array-of-function-pointer-in-isr)
  - [How to access GPIO pin and update ?](#how-to-access-gpio-pin-and-update-)
  - [What is different between pull up and pull down register](#what-is-different-between-pull-up-and-pull-down-register)
  - [What happened in case of strong pull up and weak pull up?](#what-happened-in-case-of-strong-pull-up-and-weak-pull-up)
  - [When GPIO triggered from hardware or software and interupt triggered what exactly happened?](#when-gpio-triggered-from-hardware-or-software-and-interupt-triggered-what-exactly-happened)
    - [Hardware-Triggered GPIO Interrupt](#hardware-triggered-gpio-interrupt)
    - [Software-Triggered GPIO Interrupt](#software-triggered-gpio-interrupt)
    - [What Changes in the CPU During Interrupt?](#what-changes-in-the-cpu-during-interrupt)
  - [How can we solved post-processing delay issue in interrupt?](#how-can-we-solved-post-processing-delay-issue-in-interrupt)
    - [Bare metal progamming](#bare-metal-progamming)
      - [Ring buffer](#ring-buffer)
    - [OS based or freeRTOS](#os-based-or-freertos)
      - [FreeRTOS example using vTaskNotifyGiveFromISR()](#freertos-example-using-vtasknotifygivefromisr)
      - [in freeRTOS xQueueSendFromISR](#in-freertos-xqueuesendfromisr)
- [Linux](#linux)
  - [1. Explain linux directory structure](#1-explain-linux-directory-structure)
  - [Linux Boot Process Diagram](#linux-boot-process-diagram)
  - [Explain Linux boot process](#explain-linux-boot-process)
    - [0. CPU wakes up](#0-cpu-wakes-up)
    - [1. BIOS / UEFI Initialization](#1-bios--uefi-initialization)
    - [2. Bootloader (GRUB, LILO, systemd-boot, etc.)](#2-bootloader-grub-lilo-systemd-boot-etc)
    - [3. Linux Kernel Initialization](#3-linux-kernel-initialization)
    - [4. init System Starts (PID 1)](#4-init-system-starts-pid-1)
    - [5. Login Prompt / GUI](#5-login-prompt--gui)
  - [2. What is ABI](#2-what-is-abi)
    - [Example 1 Function Call (Most Common ABI Example)](#example-1-function-call-most-common-abi-example)
    - [2. Example 2: 32-bit vs 64-bit Program](#2-example-2-32-bit-vs-64-bit-program)
    - [Example 3: System Call (Kernel ABI)](#example-3-system-call-kernel-abi)
    - [Normal Function ABI vs Linux System Call ABI](#normal-function-abi-vs-linux-system-call-abi)
      - [Argument Registers](#argument-registers)
      - [Key Point](#key-point)
  - [3. How system call execute explain in detail.](#3-how-system-call-execute-explain-in-detail)
    - [What is a System Call?](#what-is-a-system-call)
    - [1. User Program Calls `write()`](#1-user-program-calls-write)
    - [2. `glibc` Prepares the System Call](#2-glibc-prepares-the-system-call)
    - [3. CPU Executes `syscall` Instruction](#3-cpu-executes-syscall-instruction)
    - [4. Kernel Handles the System Call](#4-kernel-handles-the-system-call)
    - [5. Kernel Returns Result](#5-kernel-returns-result)
    - [Complete Flow](#complete-flow)
  - [4. Define your own system  call and in kernel](#4-define-your-own-system--call-and-in-kernel)
    - [Step 1: Write the kernel function](#step-1-write-the-kernel-function)
    - [Step 2: Add the source file to the build](#step-2-add-the-source-file-to-the-build)
    - [Step 3: Register the system call](#step-3-register-the-system-call)
    - [Step 4: Rebuild the Kernel](#step-4-rebuild-the-kernel)
    - [Step 5: Call Your System Call from User Space](#step-5-call-your-system-call-from-user-space)
  - [5. Popular system call](#5-popular-system-call)
    - [Process Control System Calls](#process-control-system-calls)
    - [File Management System Calls](#file-management-system-calls)
    - [Device Management System Calls](#device-management-system-calls)
    - [Memory Management System Calls](#memory-management-system-calls)
    - [Information Maintenance System Calls](#information-maintenance-system-calls)
    - [Communication (IPC) System Calls](#communication-ipc-system-calls)
    - [Network System Calls](#network-system-calls)
  - [6. How context switch happens when open function is called from user space?](#6-how-context-switch-happens-when-open-function-is-called-from-user-space)
    - [1. User-Space Call](#1-user-space-call)
    - [2. Mode Switch (User → Kernel)](#2-mode-switch-user--kernel)
    - [3. Kernel Handles open()](#3-kernel-handles-open)
    - [4. When Does a Context Switch Happen?](#4-when-does-a-context-switch-happen)
  - [7. What is GNU](#7-what-is-gnu)
  - [8. Static and dynamic linking](#8-static-and-dynamic-linking)
    - [Static and Dynamic Linking in Linux](#static-and-dynamic-linking-in-linux)
      - [1. Introduction](#1-introduction)
      - [2. From Source Code to Executable](#2-from-source-code-to-executable)
      - [3. Important File Types](#3-important-file-types)
    - [Part I: Static Linking](#part-i-static-linking)
      - [4. What Is Static Linking?](#4-what-is-static-linking)
      - [5. Building a Static Library](#5-building-a-static-library)
        - [`mathutil.h`](#mathutilh)
        - [`mathutil.c`](#mathutilc)
        - [`main.c`](#mainc)
      - [6. Static Linking at Runtime](#6-static-linking-at-runtime)
      - [7. Advantages of Static Linking](#7-advantages-of-static-linking)
      - [8. Disadvantages of Static Linking](#8-disadvantages-of-static-linking)
    - [Part II: Dynamic Linking](#part-ii-dynamic-linking)
      - [9. What Is Dynamic Linking?](#9-what-is-dynamic-linking)
      - [10. Building a Shared Library](#10-building-a-shared-library)
      - [11. Why `-fPIC` Is Used](#11-why--fpic-is-used)
      - [12. What Happens When a Dynamic Program Starts?](#12-what-happens-when-a-dynamic-program-starts)
      - [13. Library Search Locations](#13-library-search-locations)
      - [14. Immediate and Lazy Symbol Binding](#14-immediate-and-lazy-symbol-binding)
      - [15. Advantages of Dynamic Linking](#15-advantages-of-dynamic-linking)
      - [16. Disadvantages of Dynamic Linking](#16-disadvantages-of-dynamic-linking)
    - [Part III: Detailed Comparison](#part-iii-detailed-comparison)
      - [17. Static vs Dynamic Linking](#17-static-vs-dynamic-linking)
      - [18. Visual Comparison](#18-visual-comparison)
        - [Static linking](#static-linking)
        - [Dynamic linking](#dynamic-linking)
    - [Part IV: Runtime Dynamic Loading](#part-iv-runtime-dynamic-loading)
      - [19. Link-Time Dynamic Linking vs `dlopen()`](#19-link-time-dynamic-linking-vs-dlopen)
        - [Normal shared-library dependency](#normal-shared-library-dependency)
        - [Explicit runtime loading](#explicit-runtime-loading)
    - [Part V: Names, Versions, and Compatibility](#part-v-names-versions-and-compatibility)
      - [20. Library Naming](#20-library-naming)
      - [21. SONAME](#21-soname)
      - [22. API vs ABI](#22-api-vs-abi)
    - [Part VI: Linker Behavior and Common Problems](#part-vi-linker-behavior-and-common-problems)
      - [23. Link Order Matters](#23-link-order-matters)
      - [24. Common Link-Time Errors](#24-common-link-time-errors)
        - [Undefined reference](#undefined-reference)
        - [Cannot find library](#cannot-find-library)
      - [25. Common Runtime Errors](#25-common-runtime-errors)
        - [Shared library not found](#shared-library-not-found)
        - [Symbol lookup error](#symbol-lookup-error)
    - [Part VII: Diagnostic Commands](#part-vii-diagnostic-commands)
      - [26. Useful Linux Commands](#26-useful-linux-commands)
        - [Determine file type](#determine-file-type)
        - [Display shared-library dependencies](#display-shared-library-dependencies)
        - [Show required libraries](#show-required-libraries)
        - [Show ELF interpreter](#show-elf-interpreter)
        - [Show symbols](#show-symbols)
        - [Show library search activity](#show-library-search-activity)
        - [Show loader and symbol activity](#show-loader-and-symbol-activity)
        - [Compare sizes](#compare-sizes)
        - [Trace opened library files](#trace-opened-library-files)
    - [Part VIII: Embedded Linux Considerations](#part-viii-embedded-linux-considerations)
      - [27. Choosing a Linking Model for Embedded Linux](#27-choosing-a-linking-model-for-embedded-linux)
        - [Static linking may be appropriate when](#static-linking-may-be-appropriate-when)
        - [Dynamic linking may be appropriate when](#dynamic-linking-may-be-appropriate-when)
        - [Practical BSP and cross-compilation concerns](#practical-bsp-and-cross-compilation-concerns)
      - [28. Security and Maintenance Considerations](#28-security-and-maintenance-considerations)
        - [Static binaries](#static-binaries)
        - [Dynamic binaries](#dynamic-binaries)
    - [Part IX: Worked Demonstration](#part-ix-worked-demonstration)
      - [29. Compare Dynamic and Static Builds](#29-compare-dynamic-and-static-builds)
    - [Part X: Interview Summary](#part-x-interview-summary)
      - [30. Short Interview Answer](#30-short-interview-answer)
      - [31. Key Differences to Remember](#31-key-differences-to-remember)
      - [32. Common Follow-Up Interview Questions](#32-common-follow-up-interview-questions)
    - [Final Takeaway](#final-takeaway)
  - [9. Execute script at boot time](#9-execute-script-at-boot-time)
    - [Create a systemd Service](#create-a-systemd-service)
      - [Create a service file](#create-a-service-file)
  - [10. Different b/w shemphore, mutex and spinlock](#10-different-bw-shemphore-mutex-and-spinlock)
    - [Shemaphore](#shemaphore-1)
    - [Mutex](#mutex-2)
    - [Spinlock](#spinlock-1)
  - [11. Different b/w character, block and network device driver](#11-different-bw-character-block-and-network-device-driver)
    - [One-line takeaway (easy to remember)](#one-line-takeaway-easy-to-remember)
  - [12. Can we send strucure using `IOCTL`?](#12-can-we-send-strucure-using-ioctl)
  - [13. Explain any linux subsystem in details?](#13-explain-any-linux-subsystem-in-details)
  - [14. Add any system call in linux?](#14-add-any-system-call-in-linux)
  - [15. use of `perf` tool for linux?](#15-use-of-perf-tool-for-linux)
  - [16. Changes required to add CAN driver in BSP](#16-changes-required-to-add-can-driver-in-bsp)
    - [1. Enable CAN Peripheral in Hardware Configuration](#1-enable-can-peripheral-in-hardware-configuration)
      - [1. Kernel driver](#1-kernel-driver)
      - [2. Kernel configuration](#2-kernel-configuration)
      - [3. Yocto integration](#3-yocto-integration)
      - [4. Device Tree](#4-device-tree)
    - [2. Update BSP Device Tree / Hardware Definition](#2-update-bsp-device-tree--hardware-definition)
    - [3. Add CAN Driver Source Files](#3-add-can-driver-source-files)
    - [4. Integrate with OS / HAL](#4-integrate-with-os--hal)
    - [5. Update BSP Initialization Code](#5-update-bsp-initialization-code)
    - [6. Add Device Registration (Optional)](#6-add-device-registration-optional)
  - [17. How so you debug crash occuring after 1 month of kernel without logs?](#17-how-so-you-debug-crash-occuring-after-1-month-of-kernel-without-logs)
    - [1. Capture Crash Info](#1-capture-crash-info)
    - [2. Check for Common Long-Uptime Issues](#2-check-for-common-long-uptime-issues)
    - [3. Monitor System](#3-monitor-system)
  - [18. How to serial communication using commandline](#18-how-to-serial-communication-using-commandline)
  - [| -echo   | Do not echo received data |](#--echo----do-not-echo-received-data-)
  - [19. How to debug i2c device driver if not shown in /dev.](#19-how-to-debug-i2c-device-driver-if-not-shown-in-dev)
    - [Step 1: Check Kernel Detection](#step-1-check-kernel-detection)
    - [Step 2: Check Device Tree / Platform Data](#step-2-check-device-tree--platform-data)
    - [Step 3: Check if the Driver is Loaded](#step-3-check-if-the-driver-is-loaded)
    - [Step 4: Verify Driver Binding](#step-4-verify-driver-binding)
    - [Step 5: Check /dev Creation](#step-5-check-dev-creation)
    - [Step 6: Enable Debug Prints](#step-6-enable-debug-prints)
    - [Step 7: Test with i2c-tools](#step-7-test-with-i2c-tools)
  - [20. Kernel Debugging and Tracing methods](#20-kernel-debugging-and-tracing-methods)
    - [1. `ftrace` Function Tracer](#1-ftrace-function-tracer)
      - [🎯 When to use](#-when-to-use)
      - [Example](#example-1)
      - [How to do it](#how-to-do-it)
    - [2. `perf` Performance Analysis Tool](#2-perf-performance-analysis-tool)
      - [When to use](#when-to-use)
      - [Example](#example-2)
    - [3. `kprobes`](#3-kprobes)
      - [When to use](#when-to-use-1)
- [Kernel interview Questions](#kernel-interview-questions)
  - [1. Can you explain what a kernel is and its main functions?](#1-can-you-explain-what-a-kernel-is-and-its-main-functions)
    - [Main Functions of a Kernel](#main-functions-of-a-kernel)
      - [1. Process Management](#1-process-management)
      - [2. Memory Management](#2-memory-management)
      - [3. Device Management (I/O Control)](#3-device-management-io-control)
      - [4. File System Management](#4-file-system-management)
      - [5. System Calls Interface](#5-system-calls-interface)
      - [6. Security \& Access Control](#6-security--access-control)
  - [2. What are the different types of kernels, and how do they differ?](#2-what-are-the-different-types-of-kernels-and-how-do-they-differ)
  - [3. How does process scheduling work in the kernel?](#3-how-does-process-scheduling-work-in-the-kernel)
  - [4. What is the role of system calls in the kernel?](#4-what-is-the-role-of-system-calls-in-the-kernel)
    - [Interface Between User and Kernel](#interface-between-user-and-kernel)
    - [Access to Hardware \& Resources](#access-to-hardware--resources)
    - [Process Management](#process-management)
    - [Memory Management](#memory-management)
    - [Communication](#communication)
    - [Security \& Stability](#security--stability)
  - [5. Can you explain the difference between user space and kernel space?](#5-can-you-explain-the-difference-between-user-space-and-kernel-space)
  - [6. How does memory management work in the kernel?](#6-how-does-memory-management-work-in-the-kernel)
  - [7. What are interrupts, and how are they handled by the kernel?](#7-what-are-interrupts-and-how-are-they-handled-by-the-kernel)
    - [How the Kernel Handles Interrupts](#how-the-kernel-handles-interrupts)
  - [8. Can you describe what a context switch is and when it occurs?](#8-can-you-describe-what-a-context-switch-is-and-when-it-occurs)
    - [Save State of Current Process](#save-state-of-current-process)
    - [When Context Switch Occurs](#when-context-switch-occurs)
  - [9. What is a device driver, and how does it interact with the kernel?](#9-what-is-a-device-driver-and-how-does-it-interact-with-the-kernel)
  - [10. How does the kernel handle synchronization between processes?](#10-how-does-the-kernel-handle-synchronization-between-processes)
  - [11. What is the difference between a monolithic kernel and a microkernel?](#11-what-is-the-difference-between-a-monolithic-kernel-and-a-microkernel)
  - [12. How do you debug kernel issues?](#12-how-do-you-debug-kernel-issues)
  - [13. What is a kernel panic, and how do you troubleshoot it?](#13-what-is-a-kernel-panic-and-how-do-you-troubleshoot-it)
- [RTOS](#rtos)
  - [1. How many stacks does an RTOS typically have](#1-how-many-stacks-does-an-rtos-typically-have)
  - [2. Who actually runs the scheduler in an RTOS?](#2-who-actually-runs-the-scheduler-in-an-rtos)
  - [3. Where is the initial value stored for global/static variables?](#3-where-is-the-initial-value-stored-for-globalstatic-variables)
  - [4. Why do we need both .bss and .data sections in memory layout?](#4-why-do-we-need-both-bss-and-data-sections-in-memory-layout)
  - [5. Does an 8-bit microcontroller support structure padding?](#5-does-an-8-bit-microcontroller-support-structure-padding)
  - [6. What is the purpose of padding in structures or memory alignment?](#6-what-is-the-purpose-of-padding-in-structures-or-memory-alignment)
  - [7. What typically triggers a context switch in an RTOS?](#7-what-typically-triggers-a-context-switch-in-an-rtos)
  - [8. How does the RTOS differentiate between ISR and task context?](#8-how-does-the-rtos-differentiate-between-isr-and-task-context)
  - [9. Why is dynamic memory allocation discouraged in safety-critical systems?](#9-why-is-dynamic-memory-allocation-discouraged-in-safety-critical-systems)
  - [10. How does the linker script influence stack and heap placement?](#10-how-does-the-linker-script-influence-stack-and-heap-placement)
  - [11. What function runs before main() in an embedded system?](#11-what-function-runs-before-main-in-an-embedded-system)

- Manages input/output devices (keyboard, disk, printer, etc.)

👉 Apps don’t talk directly to hardware—the kernel handles it

#### 4. File System Management
- Organizes how data is stored and retrieved
- Handles file creation, deletion, reading, writing

👉 Ensures your files are safely stored and accessible

#### 5. System Calls Interface
- Provides a way for programs to request services from the kernel

👉 Example: When a program opens a file, it uses a system call

#### 6. Security & Access Control
- Controls permissions (who can access what)
- Protects system resources from unauthorized use
  
## 2. What are the different types of kernels, and how do they differ?

| Kernel Type | Main Idea                            | Key Difference                                  | Example OS             |
| ----------- | ------------------------------------ | ----------------------------------------------- | ---------------------- |
| Monolithic  | All services in kernel space         | Fast but less safe (everything tightly coupled) | Linux kernel, UNIX     |
| Microkernel | Minimal core, services in user space | More stable but slower (uses message passing)   | MINIX, QNX             |
| Hybrid      | Mix of both approaches               | Balances performance and modularity             | Windows NT kernel, XNU |
| Exokernel   | Minimal resource management only     | Gives maximum control to applications           | MIT Exokernel          |


## 3. How does process scheduling work in the kernel?
- Multiple processes are in memory (ready to run)
- The kernel keeps them in a ready queue
- A scheduler selects one process
- The CPU executes that process
- After some time, the kernel may switch to another process
  
## 4. What is the role of system calls in the kernel?

### Interface Between User and Kernel
- Allows user programs to request kernel services.
- Example: `open()` to access a file.
### Access to Hardware & Resources
- User programs cannot access hardware directly.
- Example: `read()` or `write()` for disk I/O.
### Process Management
- Create, terminate, or control processes.
- Example: `fork()`, `exec()`, `exit()`.
### Memory Management
- Allocate or release memory safely.
- Example: `mmap()`, `brk()`.
### Communication
- Enable inter-process communication.
- Example: `pipe()`, `socket()`.
### Security & Stability
- Ensures programs cannot corrupt system resources.
- Kernel checks requests before execution.
  
## 5. Can you explain the difference between user space and kernel space?
| Feature            | User Space                                          | Kernel Space                                      |
| ------------------ | --------------------------------------------------- | ------------------------------------------------- |
| **Definition**     | Memory area where **applications run**              | Memory area where the **OS kernel runs**          |
| **Access Level**   | Limited; cannot directly access hardware            | Full access to CPU, memory, and devices           |
| **Execution Mode** | User mode                                           | Kernel mode                                       |
| **Purpose**        | Run applications safely without crashing the system | Manage hardware, resources, and system services   |
| **Risk of Crash**  | Crashing here usually affects only the application  | Crashing can crash the entire OS                  |
| **Examples**       | Browsers, text editors, games                       | File system drivers, CPU scheduler, network stack |
| **Communication**  | Uses **system calls** to request kernel services    | Responds to system calls and manages resources    |


## 6. How does memory management work in the kernel?

- Process requests memory → kernel checks free memory.
- Kernel allocates virtual memory and maps to physical memory.
- CPU uses memory management unit (MMU) to translate virtual → physical addresses.
- When process terminates → kernel frees memory.

## 7. What are interrupts, and how are they handled by the kernel?

- An **interrupt** is a signal sent to the **CPU to immediately stop its current execution** and respond to an event.
- It can be **hardware-generated** (like keyboard input) or **software-generated** (like **exceptions** or **system calls**).


### How the Kernel Handles Interrupts
- **Interrupt Occurs** → CPU stops current execution.
- **Context Save** → Kernel saves the state of the current process (**registers**, **program counter**).
- **Interrupt Service Routine (ISR)** → Kernel executes a special handler for that interrupt.
- **Context Restore** → CPU resumes the interrupted process after handling the event.

## 8. Can you describe what a context switch is and when it occurs?

- loading and unloading of processes called context switches.
### Save State of Current Process

The kernel saves the current CPU state so Process A can resume later:

- **CPU registers** (general-purpose registers)
- **Program counter (PC)** – where the CPU left off
- **Stack pointer** – points to the process’s stack
- **Memory management info** (page tables, segment registers, if necessary)
- **Process control block (PCB)** is updated with this info

PCB = a data structure in the kernel that stores all info about a process


### When Context Switch Occurs
1. **Time-sharing / preemption**
- Process exceeds its CPU time slice → kernel switches to another process.
2. **I/O wait**
- Process waits for input/output → kernel switches to ready process.
3. **Interrupts**
- Hardware interrupt (e.g., keyboard, timer) may trigger switching.
4. **Priority-based scheduling**
- Higher priority process becomes ready → preempts current process. 

## 9. What is a device driver, and how does it interact with the kernel?

## 10. How does the kernel handle synchronization between processes?

| Mechanism | Use Case | Sleep Allowed? | Interrupt Context? |
|-----------|-----------|---------------|-------------------|
| Atomic Operations | Simple counters, flags, reference counters | No | Yes |
| Spinlock | Very short critical sections, ISR protection | No (Busy Wait) | Yes |
| Mutex | Long critical sections in process context | Yes | No |
| Semaphore | Resource management, limiting concurrent access | Yes | No |
| Read-Write Lock (RW Lock) | Many readers, few writers | Depends | Yes/No |
| RCU (Read-Copy Update) | Read-heavy data structures | No (for readers) | Yes |
| Completion | Waiting for an event/task to finish | Yes | No |

## 11. What is the difference between a monolithic kernel and a microkernel?


## 12. How do you debug kernel issues?
| Method                                 | Tools / Examples                                                  | Purpose / Use Case                                                 |
| -------------------------------------- | ----------------------------------------------------------------- | ------------------------------------------------------------------ |
| **Logging & Trace Statements**         | `printk()`, `dmesg` (Linux), `DbgPrint()`, Event Viewer (Windows) | Quick bug detection, trace function calls, monitor kernel behavior |
| **Kernel Debuggers**                   | KGDB, GDB (Linux), WinDbg, KD (Windows)                           | Step-by-step debugging, breakpoints, examine memory/registers      |
| **Crash Dumps / Post-Mortem Analysis** | `kdump`, `crash` (Linux), Windows memory dump + WinDbg            | Analyze kernel panic, BSOD, system crashes                         |
| **Tracing & Profiling Tools**          | `ftrace`, `perf`, SystemTap, eBPF (Linux), ETW (Windows)          | Real-time debugging, performance profiling, detect race conditions |
| **Virtual Machines / Emulators**       | QEMU, VMware, VirtualBox                                          | Safely reproduce kernel bugs without affecting host system         |
| **Static Analysis Tools**              | Coverity, Sparse, Clang Static Analyzer                           | Detect code-level issues like null pointers, race conditions       |
| **Dynamic Analysis Tools**             | KASAN, AddressSanitizer                                           | Detect memory corruption, buffer overflows during runtime          |
| **Driver & Hardware Debugging**        | debugfs, udevadm (Linux), Driver Verifier (Windows), JTAG         | Diagnose hardware/driver-related kernel issues                     |

## 13. What is a kernel panic, and how do you troubleshoot it?
- A **kernel panic** is a **critical error** that occurs when the Linux or Unix kernel encounters a situation from which it **cannot safely recover**. 
- It’s similar to the **Blue Screen of Death** (BSOD) in Windows.
-  When a kernel panic happens, the s**ystem usually halts or reboots**, and you might see a message like:
```bash
Kernel panic - not syncing: Fatal exception
```

| Step | Possible Cause                                  | Symptoms / Panic Message                     | Action / Troubleshooting                                                                                                                       |
| ---- | ----------------------------------------------- | -------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| 1    | Hardware issues (RAM, CPU, HDD, overheating)    | Random panics, memory dump, frequent reboots | - Run `memtest86+` to check RAM<br>- Use `smartctl -a /dev/sda` to check disk health<br>- Ensure proper cooling and reseat hardware            |
| 2    | Faulty or incompatible drivers / kernel modules | Panic shows module name or “Oops” messages   | - Boot into an **older kernel** via GRUB<br>- Blacklist problematic module: `modprobe.blacklist=<module>`<br>- Update drivers/kernel           |
| 3    | Corrupted filesystem or root disk               | “VFS: Unable to mount root fs” or I/O errors | - Boot from **Live USB/CD**<br>- Run `fsck /dev/sdaX` on root partition<br>- Repair or restore filesystems                                     |
| 4    | Corrupt kernel                                  | Panic at boot or immediately after           | - Reinstall or rollback kernel: `sudo apt-get install --reinstall linux-image-<version>`<br>- Boot an older working kernel                     |
| 5    | Misconfigured bootloader / kernel parameters    | Kernel can’t find root, fails to load        | - Check **GRUB config** (`/boot/grub/grub.cfg`)<br>- Adjust kernel parameters (e.g., `root=UUID=...`)<br>- Regenerate GRUB: `sudo update-grub` |
| 6    | Recent software updates / package issues        | Panic occurs after update, module errors     | - Boot older kernel or snapshot<br>- Undo recent updates or reinstall affected packages                                                        |
| 7    | System logs for diagnostics                     | Various, may contain call trace              | - View `dmesg` or `journalctl -xb` for detailed error logs<br>- Identify module, disk, or memory issue                                         |
| 8    | Persistent unknown panic                        | Unknown cause after above steps              | - Collect panic message, kernel version, and system info<br>- Search Linux forums or bug trackers for similar cases                            |


------------------------------------------------------------------------------

# RTOS
## 1. How many stacks does an RTOS typically have 
- An RTOS typically has one stack per task plus a system/ISR stack.

## 2. Who actually runs the scheduler in an RTOS?
- The scheduler is triggered by the timer interrupt (tick ISR) and executed by the RTOS kernel.

## 3. Where is the initial value stored for global/static variables?
- Initial values of global/static variables are stored in Flash (.data section) and copied to RAM at startup.

## 4. Why do we need both .bss and .data sections in memory layout?
- The .data section holds initialized global/static variables, while .bss holds zero-initialized ones to save Flash.

## 5. Does an 8-bit microcontroller support structure padding?
- Yes, even an 8-bit microcontroller supports structure padding depending on the compiler.

## 6. What is the purpose of padding in structures or memory alignment?
- Padding ensures proper memory alignment for faster access and fewer CPU cycles.

## 7. What typically triggers a context switch in an RTOS?
- A context switch occurs when a time slice ends, a higher-priority task becomes ready, or a blocked task is unblocked.

## 8. How does the RTOS differentiate between ISR and task context?
- The RTOS differentiates ISR and task context using separate stacks and interrupt return mechanisms.

## 9. Why is dynamic memory allocation discouraged in safety-critical systems?
- Dynamic memory allocation is discouraged in safety-critical systems due to fragmentation, memory leaks, and non-deterministic timing.

## 10. How does the linker script influence stack and heap placement?
- The linker script defines memory regions and controls the placement of stack and heap.

## 11. What function runs before main() in an embedded system?
- The Reset Handler/Startup Code runs before main(), setting up stack, copying .data, clearing .bss, calling SystemInit(), then jumping to main().