/*
 * interfaces.h
 *
 *  Created on: 5 abr. 2022
 *      Author: migue
 */

#ifndef MI_BIBLIOTECA_INTERFACES_H_
#define MI_BIBLIOTECA_INTERFACES_H_
void menuInicio(char* mensaje1, char* mensaje2, float valor1, float valor2, int update);
void subMenu();
void informe(
            char* mensaje,
            float precio,
            float precioDescuento, 
            float precioRecargo, 
            float precioBitCoin, 
            float precioUnitario);

#endif /* MI_BIBLIOTECA_INTERFACES_H_ */
