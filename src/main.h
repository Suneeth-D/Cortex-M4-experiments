/*
 * main.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Lenovo
 */

#ifndef MAIN_H_
#define MAIN_H_
//User-defined Macros
#define SRAM_START 0x20000000U
#define SRAM_SIZE ((128) * (1024))
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define TASK_STACK_SIZE 1024U

#define T1_STACK_START SRAM_END
#define T2_STACK_START ((SRAM_END) - (1 * TASK_STACK_SIZE))
#define T3_STACK_START ((SRAM_END) - (2 * TASK_STACK_SIZE))
#define T4_STACK_START ((SRAM_END) - (3 * TASK_STACK_SIZE))
#define IDLE_STACK_START ((SRAM_END) - (4 * TASK_STACK_SIZE))
#define SCHDLR_STACK_START ((SRAM_END) - (5 * TASK_STACK_SIZE))

#define CLOCK_FREQ 16000000
#define TICK_FREQ 1000

#define MAX_TASKS 5

#define LR_VAL 0xFFFFFFFD
#define DUMMY_XPSR 0x01000000

#define TASK_READY 0x00
#define TASK_BLOCKED 0xFF

#define INTRPT_DISABLE() do{__asm volatile("MOV R0,#0x1"); asm volatile("MSR PRIMASK, R0");}while(0)
#define INTRPT_ENABLE() do{__asm volatile("MOV R0,#0x0"); asm volatile("MSR PRIMASK, R0");}while(0)
//User-defined function declaration

extern void initialise_monitor_handles(void);
void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);
void systick_init(uint32_t tick_freq);
void SysTick_Handler(void);
__attribute__ ((naked))void PendSV_Handler(void);
__attribute__((naked)) void sched_stack_init(uint32_t schdlr_stack_start);
void task_stack_init(void);
__attribute__((naked)) void switch_sp_to_psp(void);
void enable_processor_faults(void);
void BusFault_Handler(void);
void MemManage_Handler(void);
void HardFault_Handler(void);
void UsageFault_Handler(void);
uint32_t get_psp_val(void);
void save_psp(uint32_t current_psp_val);
void update_next_task(void);
void task_delay(uint32_t tick_count);
void idle_handler(void);
void update_g_tick_count(void);
void unblock_tasks(void);
void schedule(void);

//Global Variables
//uint32_t *pSTK_CTRL = (uint32_t *)0xE000E010;
//uint32_t *pSTK_RLOAD = (uint32_t *)0xE000E014;
//uint32_t task_handler_addr[MAX_TASKS] = {task1_handler, task2_handler, task3_handler, task4_handler};
//uint32_t psp_tasks[MAX_TASK];



#endif /* MAIN_H_ */
