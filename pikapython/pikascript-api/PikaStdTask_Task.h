/*
 * [Warning!] This file is auto-generated by pika compiler.
 * Do not edit it manually.
 * The source code is *.pyi file.
 * More details: 
 * English Doc:
 * https://pikadoc-en.readthedocs.io/en/latest/PikaScript%20%E6%A8%A1%E5%9D%97%E6%A6%82%E8%BF%B0.html
 * Chinese Doc:
 * http://pikapython.com/doc/PikaScript%20%E6%A8%A1%E5%9D%97%E6%A6%82%E8%BF%B0.html
 */

#ifndef __PikaStdTask_Task__H
#define __PikaStdTask_Task__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_PikaStdTask_Task(Args *args);

void PikaStdTask_Task___init__(PikaObj *self);
void PikaStdTask_Task_call_always(PikaObj *self, Arg* fun_todo);
void PikaStdTask_Task_call_period_ms(PikaObj *self, Arg* fun_todo, int period_ms);
void PikaStdTask_Task_call_when(PikaObj *self, Arg* fun_todo, Arg* fun_when);
void PikaStdTask_Task_platformGetTick(PikaObj *self);
void PikaStdTask_Task_run_forever(PikaObj *self);
void PikaStdTask_Task_run_once(PikaObj *self);
void PikaStdTask_Task_run_until_ms(PikaObj *self, int until_ms);

#endif
