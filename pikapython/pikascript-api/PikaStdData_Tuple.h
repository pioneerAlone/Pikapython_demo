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

#ifndef __PikaStdData_Tuple__H
#define __PikaStdData_Tuple__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_PikaStdData_Tuple(Args *args);

PikaObj* PikaStdData_Tuple___add__(PikaObj *self, PikaObj* others);
void PikaStdData_Tuple___del__(PikaObj *self);
int PikaStdData_Tuple___eq__(PikaObj *self, Arg* other);
Arg* PikaStdData_Tuple___getitem__(PikaObj *self, Arg* __key);
void PikaStdData_Tuple___init__(PikaObj *self);
Arg* PikaStdData_Tuple___iter__(PikaObj *self);
int PikaStdData_Tuple___len__(PikaObj *self);
PikaObj* PikaStdData_Tuple___mul__(PikaObj *self, int n);
Arg* PikaStdData_Tuple___next__(PikaObj *self);
char* PikaStdData_Tuple___str__(PikaObj *self);
Arg* PikaStdData_Tuple_get(PikaObj *self, int i);
int PikaStdData_Tuple_len(PikaObj *self);

#endif
