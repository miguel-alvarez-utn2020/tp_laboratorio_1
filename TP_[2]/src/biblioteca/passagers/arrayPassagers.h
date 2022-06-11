/*
 * arrayPassagers.h
 *
 *  Created on: 23 abr. 2022
 *      Author: migue
 */

#ifndef BIBLIOTECA_PASSAGERS_ARRAYPASSAGERS_H_
#define BIBLIOTECA_PASSAGERS_ARRAYPASSAGERS_H_

typedef struct
{
    int id;
    char name[50];
    char lastName[50];
    float price;
    char flyCode[15];
    int typePassager;
    int statusFlight;
    int isEmpty;
} Passager;

int initPassagers(Passager listPasaggers[], int sizeListPassager);
int chargePassagerAuto(Passager passagersList[], int amountPassagerCharge);
int findPositionFree(Passager passagersList[], int sizePassagerList);
void viewToPassager(Passager passager);
//////////////////////////////////////////////////////////////////////////
Passager addPassager(
    Passager newPassager,
    char nameMsj[],
    char lastNameMsj[],
    char flyCodeMsj[],
    char priceMsj[],
    char statusFlightMsj[],
    char typePassagerMsj[],
    char errorRangeMsj[],
    char errorNoValidoMsj[]);
///////////////////////////////
Passager editPassager(
    Passager passager,
    char nameMsj[],
    char lastNameMsj[],
    char flyCodeMsj[],
    char priceMsj[],
    char typePassagerMsj[],
    char errorRangeMsj[],
    char errorNoValidoMsj[]);
///////////////////////////////
void viewPassagers(Passager passagersList[], int sizePassagerList);
///////////////////////////////
//////////////////////////////////
Passager findPassagerById(Passager passagerList[], int sizePassagerList, int passagerId);
int sortPassagerByName(Passager passagerList[], int sizePassagerList, int orderMode);
int sortPassengersByCode(Passager passagerList[], int sizePassagerList, int orderMode);
int findPositionPassagerById(Passager passagerList[], int sizePassagerList, int idPassager);
void menuOption();
void menuOptionInfo();
int totalAndAvaragePrices(Passager passagerList[], int passagerSize, int *amontPassagers, float *totalPrice, float *avarage);
int highPriceAvarage(Passager passagerList[], int sizeList, float avarage, int *passagerAmount);
#endif /* BIBLIOTECA_PASSAGERS_ARRAYPASSAGERS_H_ */
