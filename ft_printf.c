/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppedrosa <ppedrosa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:52:15 by ppedrosa          #+#    #+#             */
/*   Updated: 2022/09/15 19:52:15 by ppedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"libft.h"
#include<stdio.h>

void    ft_putChar(char c){
    write(1, &c, 1);
}

void    ft_putString(char *str){
    while(*str){
        int i = *str;
        write(1, &i, 1);
        *str++;
    }
}

void ft_putNumber(int number){
    ft_putString(ft_itoa(number));
}

void ft_printv(char *format, va_list ap){

    char *p;
    int intValue;
    double doubleValue;

    for(p = format; *p; p++){
        if(*p != '%'){
            ft_putChar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ft_putNumber(va_arg(ap, int));                
                break;
            case 'f':
                doubleValue = va_arg(ap, double);
                printf("%f", doubleValue);
                break;
            case 's':
                ft_putString(va_arg(ap, char *));
                break;
            case 'c':
                ft_putChar(va_arg(ap, int));
                break;
            default:
                ft_putChar(*p);
                break;
        }
    }
}

void ft_printf(char *format, ...){
    va_list ap;
    va_start(ap, format);
    ft_printv(format, ap);
    va_end(ap);
}

int main(){

  //  void *pointer_to_main = (void *) main;

    ft_printf("Imprimir un caracter: %c. Done!\n", 'H');
    ft_printf("Imprimir un String: %s. Done!\n", "Hola mundo");
    ft_printf("Imprimir un entero negativo: %d. Done!\n", -2147483647);
    ft_printf("Imprimir un cero entero: %d. Done!\n", 0);
    ft_printf("Imprimir un entero positivo: %d. Done!\n", 2147483647);
/*  ft_printf("Imprimir un hexadecimal: %x. Done!\n", -10);
    ft_printf("Imprimir un cero hexadecimal: %x. Done!\n", -10);
    ft_printf("Imprimir un puntero: %p. Done!\n", pointer_to_main);
*/
return (0);
}
